/* UtilsGL.c */
/**********************************************************************************************************
Copyright (c) 2002-2007 Abdul-Rahman Allouche. All rights reserved

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the Gabedit), to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions
  of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
************************************************************************************************************/


#include "../../Config.h"
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <gtk/gtk.h>
#include <GL/gl.h>
#include <GL/glu.h>

#ifndef G_OS_WIN32
#include <GL/glx.h>
#include <pango/pangox.h>
#include <gdk/gdkx.h>
#else
#include <pango/pangowin32.h>
#endif


#include "../Common/Global.h"
#include "../Utils/Vector3d.h"
#include "../Utils/Transformation.h"
#include "UtilsGL.h"
/* transformation/projection matrices */
static GLint viewport[4];
static GLdouble mvmatrix[16];
static GLdouble projmatrix[16];
static gint glFontsize=10;
static gint fontOffset=-1;
#ifdef G_OS_WIN32
PangoFont *
gdk_gl_font_use_pango_font (const PangoFontDescription *font_desc,
                            int                         first,
                            int                         count,
                            int                         list_base)
{
  PangoFontMap *font_map;
  PangoFont *font = NULL;
  LOGFONT *logfont = NULL;
  PangoWin32FontCache *font_cache;
  HFONT hfont;
  HDC hdc;

  g_return_val_if_fail (font_desc != NULL, NULL);

  font_map = pango_win32_font_map_for_display ();

  font = pango_font_map_load_font (font_map, NULL, font_desc);
  if (font == NULL)
    {
      g_warning ("cannot load PangoFont");
      goto FAIL;
    }

  logfont = pango_win32_font_logfont (font);
  if (logfont == NULL)
    {
      g_warning ("cannot get LOGFONT struct");
      font = NULL;
      goto FAIL;
    }

  font_cache = pango_win32_font_map_get_font_cache (font_map);

  hfont = pango_win32_font_cache_load (font_cache, logfont);

  hdc = CreateCompatibleDC (NULL);
  if (hdc == NULL)
    {
      g_warning ("cannot create a memory DC");
      font = NULL;
      goto FAIL;
    }

  SelectObject (hdc, hfont);

  if (!wglUseFontBitmaps (hdc, first, count, list_base))
    {
      g_warning ("cannot create the font display lists");
      font = NULL;
      goto FAIL;
    }

  if (!DeleteDC (hdc))
    g_warning ("cannot delete the memory DC");

  pango_win32_font_cache_unload (font_cache, hfont);

 FAIL:

  if (logfont != NULL)
    g_free (logfont);

  return font;
}
#else
/*********************************************************************************************/
static char *
gdk_gl_font_charset_for_locale (void)
{
  static char *charset_map[][2] = {
    { "ANSI_X3.4-1968", "iso8859-1" },
    { "US-ASCII",   "iso8859-1" },
    { "ISO-8859-1", "iso8859-1" },
    { "ISO-8859-2", "iso8859-2" },
    { "ISO-8859-3", "iso8859-3" },
    { "ISO-8859-4", "iso8859-4" },
    { "ISO-8859-5", "iso8859-5" },
    { "ISO-8859-6", "iso8859-6" },
    { "ISO-8859-7", "iso8859-7" },
    { "ISO-8859-8", "iso8859-8" },
    { "ISO-8859-9", "iso8859-9" },
    { "UTF-8",      "iso8859-1" }
  };

  const char *codeset;
  char *result = NULL;
  gsize i;

  g_get_charset (&codeset);
  
  for (i = 0; i < G_N_ELEMENTS (charset_map); i++)
    if (strcmp (charset_map[i][0], codeset) == 0)
      {
	result = charset_map[i][1];
	break;
      }

  if (result != NULL)
    return g_strdup (result);
  else
    return g_strdup ("iso8859-1");
}
static PangoFont *
gdk_gl_font_use_pango_font_common (PangoFontMap               *font_map,
                                   const PangoFontDescription *font_desc,
                                   int                         first,
                                   int                         count,
                                   int                         list_base)
{
  PangoFont *font = NULL;
  gchar *charset = NULL;
  PangoXSubfont subfont_id;
  gchar *xlfd = NULL;
  PangoXFontCache *font_cache;
  XFontStruct *fs;


  font = pango_font_map_load_font (font_map, NULL, font_desc);
  if (font == NULL)
    {
      g_warning ("cannot load PangoFont");
      goto FAIL;
    }

  charset = gdk_gl_font_charset_for_locale ();
  if (!pango_x_find_first_subfont (font, &charset, 1, &subfont_id))
    {
      g_warning ("cannot find PangoXSubfont");
      font = NULL;
      goto FAIL;
    }

  xlfd = pango_x_font_subfont_xlfd (font, subfont_id);
  if (xlfd == NULL)
    {
      g_warning ("cannot get XLFD");
      font = NULL;
      goto FAIL;
    }

  font_cache = pango_x_font_map_get_font_cache (font_map);

  fs = pango_x_font_cache_load (font_cache, xlfd);

  glXUseXFont (fs->fid, first, count, list_base);

  pango_x_font_cache_unload (font_cache, fs);

 FAIL:

  if (charset != NULL)
    g_free (charset);

  if (xlfd != NULL)
    g_free (xlfd);

  return font;
}

/**
 * gdk_gl_font_use_pango_font:
 * @font_desc: a #PangoFontDescription describing the font to use.
 * @first: the index of the first glyph to be taken.
 * @count: the number of glyphs to be taken.
 * @list_base: the index of the first display list to be generated.
 *
 * Creates bitmap display lists from a #PangoFont.
 *
 * Return value: the #PangoFont used, or NULL if no font matched.
 **/
static PangoFont *
gdk_gl_font_use_pango_font (const PangoFontDescription *font_desc,
                            int                         first,
                            int                         count,
                            int                         list_base)
{
  PangoFontMap *font_map;

  g_return_val_if_fail (font_desc != NULL, NULL);


  font_map = pango_x_font_map_for_display (gdk_x11_get_default_xdisplay ());

  return gdk_gl_font_use_pango_font_common (font_map, font_desc,
                                            first, count, list_base);
}
#endif

/*********************************************************************************************/
/* window to real space conversion primitive */
void glGetWorldCoords(gint x, gint y, gint height, gdouble *w)
{
	gint ry;
	gint i;
	GLdouble r[3];

	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);

	ry = height - y - 1;
	gluUnProject(x, ry, 0.1, mvmatrix, projmatrix, viewport, &r[0], &r[1], &r[2]);

	for(i=0;i<3;i++) w[i] = r[i];
}
/*********************************************************************************************/
/* real space to window conversion primitive */
void glGetWindowCoords(gdouble *w, gint height, gint *x)
{
	GLdouble r[3];

	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);

	gluProject(w[0], w[1], w[2], mvmatrix, projmatrix, viewport, &r[0], &r[1], &r[2]);

	x[0] = r[0];
	x[1] = height - r[1] - 1;
}
/*********************************************************************************************/
gint glTextWidth(gchar *str)
{
	return(strlen(str) * glFontsize);
}
/*********************************************************************************************/
/* print at a window position */
void glPrintWin(gint x, gint y, gint height, gchar *str)
{
	gdouble w[3];

	glGetWorldCoords(x, y, height, w);
	glRasterPos3f(w[0], w[1], w[2]); 

	glListBase(fontOffset);
	glCallLists(strlen(str), GL_UNSIGNED_BYTE, str);
}
/*********************************************************************************************/
/* print at a world position */
void glPrint(gdouble x, gdouble y, gdouble z, gchar *str)
{
	glRasterPos3f(x,y,z); 

	glListBase(fontOffset);
	glCallLists(strlen(str), GL_UNSIGNED_BYTE, str);
}
/*********************************************************************************************/
void glPrintOrtho(gdouble x, gdouble y, gdouble z, gchar *str)
{
	gdouble w[] = {x, y, z};
	gint xy[] = {0, 0};
	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetWindowCoords(w, viewport[3], xy);
	glPushMatrix();
	glLoadIdentity();
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); glLoadIdentity();
	gluOrtho2D(0, viewport[2], 0, viewport[3]);
	
	glPrintWin(xy[0], xy[1], viewport[3], str);
	
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	
	glPopMatrix();
}
/*********************************************************************************************/
/* pango fonts for OpenGL  */
void glInitFonts()
{
	/*if (fontOffset >=0) return;*/

	fontOffset = glGenLists(128);
	if (fontOffset)
	{ 
		PangoFontDescription *pfd;
		pfd = pango_font_description_from_string(FontsStyleLabel.fontname);
		if (gdk_gl_font_use_pango_font(pfd, 0, 128, fontOffset))
			glFontsize = pango_font_description_get_size(pfd) / PANGO_SCALE;
		pango_font_description_free(pfd); 
	}
}
/*********************************************************************************************/
/* get a World coordinates from scene coordinates */
void glGetWorldCoordsFromSceneCoords(gdouble VScene[], gdouble VWorld[])
{
	GLdouble mvMatrix[4][4];
	gfloat** trMatrix;
	gfloat** invMatrix;
	gint i;
	gint j;
	glGetDoublev(GL_MODELVIEW_MATRIX, &mvMatrix[0][0]);
	trMatrix = g_malloc(3*sizeof(gfloat*));
	for(i=0;i<3;i++) trMatrix[i] = g_malloc(3*sizeof(gfloat));

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			trMatrix[j][i] = mvMatrix[i][j];

	invMatrix = Inverse3(trMatrix);
	for(i=0;i<3;i++) g_free(trMatrix[i]);
	g_free(trMatrix);

	if(invMatrix != NULL)
	{
		for(i=0;i<3;i++)
		{
			VWorld[i] = 0;
			for(j=0;j<3;j++)
			{
				VWorld[i] += invMatrix[i][j]*VScene[j];
			}
		}
		for(i=0;i<3;i++) g_free(invMatrix[i]);
		g_free(invMatrix);
	}
	else
	{
		for(i=0;i<3;i++) VWorld[i] = 0;
		VWorld[2] = 1;
	}
}
/*********************************************************************************************/
/* get a normal vector to plan of window */
void getNormalPlanWindow(gdouble N[])
{
	gdouble VScene[3]={0,0,1};

	glGetWorldCoordsFromSceneCoords(VScene,N);

}
/*********************************************************************************************/
/* print at a world position  after scaling of scal in scene coordinates*/
void glPrintScale(gdouble x, gdouble y, gdouble z, gdouble scale, gchar *str)
{
	gdouble VScene[]={0,0,0};
	gdouble VWorld[]={x,y,z};
	GLdouble mvMatrix[4][4];
	gfloat** trMatrix;
	gfloat** invMatrix;
	gint i;
	gint j;
	glGetDoublev(GL_MODELVIEW_MATRIX, &mvMatrix[0][0]);
	trMatrix = g_malloc(3*sizeof(gfloat*));
	for(i=0;i<3;i++) trMatrix[i] = g_malloc(3*sizeof(gfloat));

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			trMatrix[j][i] = mvMatrix[i][j];

	for(i=0;i<3;i++)
	{
		VScene[i] = 0;
		for(j=0;j<3;j++)
		{
			VScene[i] += trMatrix[i][j]*VWorld[j];
		}
	}
	VScene[2] += scale;

	invMatrix = Inverse3(trMatrix);
	for(i=0;i<3;i++) g_free(trMatrix[i]);
	g_free(trMatrix);

	if(invMatrix != NULL)
	{
		for(i=0;i<3;i++)
		{
			VWorld[i] = 0;
			for(j=0;j<3;j++)
			{
				VWorld[i] += invMatrix[i][j]*VScene[j];
			}
		}
		for(i=0;i<3;i++) g_free(invMatrix[i]);
		g_free(invMatrix);
	}
	else
	{
		VWorld[0] = x;
		VWorld[1] = y;
		VWorld[2] = z;
	}
	glRasterPos3f(VWorld[0],VWorld[1],VWorld[2]); 
	glListBase(fontOffset);
	glCallLists(strlen(str), GL_UNSIGNED_BYTE, str);
}
