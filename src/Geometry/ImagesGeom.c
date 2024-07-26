/* ImagesGeom.c */
/**********************************************************************************************************
Copyright (c) 2002-2009 Abdul-Rahman Allouche. All rights reserved

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
#include "../Common/Global.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Utils.h"

/**********************************************************************************************************************************/
static void save_geometry_image(GabeditFileChooser *SelecFile, gchar* type)
{       
 	gchar *fileName;

 	fileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!fileName) || (strcmp(fileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    		return ;
 	}

	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() ) gtk_main_iteration();
	Waiting(1.0);

	gtk_window_move(GTK_WINDOW(GeomDlg),0,0);
	rafresh_drawing();
	while( gtk_events_pending() ) gtk_main_iteration();
	gabedit_save_image(ZoneDessin, fileName, type);

}
/**************************************************************************
*       Get image in rgb format
**************************************************************************/
guchar *get_rgb_image()
{
 if(!ZoneDessin)
 {
   Message("Sorry I can not create image file \nbecause Geometry display windows is closed"," Error ",TRUE);
   return NULL;
 }
  {
	gdouble fac=255.0/65535.0;
  	GdkPixmap* pixmap = get_drawing_pixmap();
  	GdkColormap *colormap = get_drawing_colormap();
  	guint height = ZoneDessin->allocation.height;
  	guint width = ZoneDessin->allocation.width;
	guint32 pixel;
  	GdkImage* image = NULL;
	GdkVisual *v;
	guint8 component;
	guint k=0;
	gint x;
	gint y;
	gint i;
	guchar* rgbbuf=(guchar *) g_malloc(3*width*height*sizeof(guchar));

  	if(!pixmap || !colormap)
		 return NULL;
	if(!rgbbuf)
	{
            Message("Sorry: couldn't allocate memory\n","Error",TRUE);
	    return NULL;
	}
	/* Debug("End get colormap\n");*/
	image = gdk_drawable_get_image(ZoneDessin->window,0,0,width,height);
	/* Debug("End get Image\n");*/
	v = gdk_colormap_get_visual(colormap);
	/* Debug("End get visual\n");*/
	switch(v->type)
	{
		case GDK_VISUAL_STATIC_GRAY:
		case GDK_VISUAL_GRAYSCALE:
		case GDK_VISUAL_STATIC_COLOR:
		case GDK_VISUAL_PSEUDO_COLOR:
			for(y=height-1;y>=0;y--)
				for(x=0;x<(gint)width;x++)
			{
				pixel = gdk_image_get_pixel(image, x, y);
				rgbbuf[k] = (guchar)(colormap->colors[pixel].red*fac);
				rgbbuf[k+1] =(guchar) (colormap->colors[pixel].green*fac);
				rgbbuf[k+2] =(guchar) (colormap->colors[pixel].blue*fac);
				k+=3;
			}
			break;

	    case GDK_VISUAL_TRUE_COLOR:
		/* Debug("True color\n");*/
			for(y=height-1;y>=0;y--)
				for(x=0;x<(gint)width;x++)
			{
				pixel = gdk_image_get_pixel(image, x, y);
	      			component = 0;
	      			for (i = 24; i < 32; i += v->red_prec)
					component |= ((pixel & v->red_mask) << (32 - v->red_shift - v->red_prec)) >> i;
	      			rgbbuf[k] = (guchar)(component);
	      			
				component = 0;
	      			for (i = 24; i < 32; i += v->green_prec)
					component |= ((pixel & v->green_mask) << (32 - v->green_shift - v->green_prec)) >> i;
	      			rgbbuf[k+1] = (guchar)(component);
	      			component = 0;
	      			for (i = 24; i < 32; i += v->blue_prec)
					component |= ((pixel & v->blue_mask) << (32 - v->blue_shift - v->blue_prec)) >> i;
	      			rgbbuf[k+2] = (guchar)(component);
	      			k += 3;
			}
	      break;
	    case GDK_VISUAL_DIRECT_COLOR:
			for(y=height-1;y>=0;y--)
				for(x=0;x<(gint)width;x++)
			{
				pixel = gdk_image_get_pixel(image, x, y);
	      			component = colormap->colors[((pixel & v->red_mask) << (32 - v->red_shift - v->red_prec)) >> 24].red;
	      			rgbbuf[k] = (guchar)(component*fac);

	      			component = colormap->colors[((pixel & v->green_mask) << (32 - v->green_shift - v->green_prec)) >> 24].green;
	      			rgbbuf[k+1] = (guchar)(component*fac);
	      			component = colormap->colors[((pixel & v->blue_mask) << (32 - v->blue_shift - v->blue_prec)) >> 24].blue;
	      			rgbbuf[k+2] = (guchar)(component*fac);
	      			k += 3;
			}
	      break;
	    default : Message("Unknown visual\n","Error",TRUE);
		      g_free(rgbbuf);
		      return NULL;
	}
	return rgbbuf;
  }

}
/**************************************************************************
*       Save the Frame Buffer in a jpeg format file
**************************************************************************/
void save_geometry_jpeg_file(GabeditFileChooser *SelecFile, gint response_id)
{       
	if(response_id != GTK_RESPONSE_OK) return;
	save_geometry_image(SelecFile, "jpeg");
} 
/**************************************************************************
*       Save the Frame Buffer in a ppm format file
**************************************************************************/
void save_geometry_ppm_file(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *FileName;
	FILE *file;
	int i;
	int j;
	int k;
	int width;
	int height;
	guchar *rgbbuf;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    		return ;
 	}

	file = FOpen(FileName,"wb");

        if (!file) {
            Message("Sorry: can't open output file\n","Error",TRUE);
            return;
        }

	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() )
		gtk_main_iteration();
	Waiting(1.0);
	gtk_window_move(GTK_WINDOW(GeomDlg),0,0);
	rafresh_drawing();
	while( gtk_events_pending() )
		gtk_main_iteration();



	rgbbuf = get_rgb_image();
	if (!rgbbuf) {
            return;
	}
	width =  ZoneDessin->allocation.width;
	height = ZoneDessin->allocation.height;

        fprintf(file,"P6\n");
        fprintf(file,"#Image rendered with gabedit\n");
        fprintf(file,"%d\n%d\n255\n", width,height);

	for(i=height-1; i>= 0; i--){
	   for(j=0; j< width; j++){
		k = 3*(j + i*width);
		fwrite( &rgbbuf[k] ,sizeof(*rgbbuf), 1, file);
		fwrite( &rgbbuf[k+1] ,sizeof(*rgbbuf), 1, file);
		fwrite( &rgbbuf[k+2] ,sizeof(*rgbbuf), 1, file);
	   }
	}

	fclose(file);
	g_free(rgbbuf);
} 
/**************************************************************************
*       Save the Frame Buffer in a bmp format file
**************************************************************************/
static void WLSBL(int val,char* arr)
{
    arr[0] = (char) (val&0xff);
    arr[1] = (char) ((val>>8) &0xff);
    arr[2] = (char) ((val>>16)&0xff);
    arr[3] = (char) ((val>>24)&0xff);
}
void save_geometry_bmp_file(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *FileName;
	FILE *file;
	int i;
	int j;
	int width;
	int height;
  	guchar *rgbbuf;
  	guchar rgbtmp[3];
  	int pad;
	char bmp_header[]=
	{ 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0,
  	40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0, 0,0,0,0, 0,0,0,0,
  	0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 };

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    	return ;
 	}

	file = FOpen(FileName,"wb");

	if (!file) 
	{
		Message("Sorry: can't open output file\n","Error",TRUE);
		return;
	}
	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() )
		gtk_main_iteration();
	Waiting(1.0);

	gtk_window_move(GTK_WINDOW(GeomDlg),0,0);
	rafresh_drawing();
	while( gtk_events_pending() )
		gtk_main_iteration();

  

  	rgbbuf = get_rgb_image();
  	if (!rgbbuf)
	{
	    	fclose(file);
		return;
  	}
	width =  ZoneDessin->allocation.width;
	height = ZoneDessin->allocation.height;

/* The number of bytes on a screenline should be wholly devisible by 4 */

  	pad = (width*3)%4;
  	if (pad) pad = 4 - pad;

  	WLSBL((int) (3*width+pad)*height+54,bmp_header+2);
  	WLSBL((int) width,bmp_header+18);
  	WLSBL((int) height,bmp_header+22);
  	WLSBL((int) 3*width*height,bmp_header+34);

  	fwrite(bmp_header,1,54,file);

  	for (i=0;i<height;i++)
	{
    		for (j=0;j<width;j++)
		{
			rgbtmp[0] = rgbbuf[(j+width*i)*3+2];
			rgbtmp[1] = rgbbuf[(j+width*i)*3+1];
			rgbtmp[2] = rgbbuf[(j+width*i)*3+0];
			fwrite(rgbtmp,3,1,file);
    		}
    	rgbtmp[0] = (char) 0;
    	for (j=0;j<pad;j++) 
		fwrite(rgbtmp,1,1,file);
  	}

  	fclose(file);
  	g_free(rgbbuf);
}
/**************************************************************************
*       ps header file
**************************************************************************/
static void ps_header(FILE* file)
{
   fprintf(file,"%%true {\n");
   fprintf(file,"systemdict /colorimage known not {\n");
   fprintf(file,"%%\n");
   fprintf(file,"/colorImageDict 50 dict def\n");
   fprintf(file,"/colorimage {\n");
   fprintf(file,"    colorImageDict begin\n");
   fprintf(file,"    /Ncomp exch def\n");
   fprintf(file,"    {\n");
   fprintf(file,"        (Multi-source not implemented\\n) print flush\n");
   fprintf(file,"        limitcheck\n");
   fprintf(file,"    } {\n");
   fprintf(file,"        /Dsrc exch def\n");
   fprintf(file,"        /Matrix exch def\n");
   fprintf(file,"        /Bcomp exch def\n");
   fprintf(file,"        /Height exch def\n");
   fprintf(file,"        /Width exch def\n");
   fprintf(file,"        /Bycomp Bcomp 7 add 8 idiv def\n");
   fprintf(file,"        Bcomp 8 gt { (Only 8 bit per sample images \\n)\n");
   fprintf(file,"                     print flush limitcheck\n");
   fprintf(file,"                   } if\n");
   fprintf(file,"        Width Height Bcomp Matrix\n");
   fprintf(file,"        Ncomp 1 eq {\n");
   fprintf(file,"            { Dsrc exec }\n");
   fprintf(file,"        } if\n");
   fprintf(file,"        Ncomp 3 eq {\n");
   fprintf(file,"          /Gstr Bycomp Width mul string def\n");
   fprintf(file,"          { Dsrc exec\n");
   fprintf(file,"             /Cstr exch def\n");
   fprintf(file,"             0 1 Width 1 sub {\n");
   fprintf(file,"               /I exch def\n");
   fprintf(file,"               /X I 3 mul def\n");
   fprintf(file,"               Gstr I\n");
   fprintf(file,"                 Cstr X       get 0.3  mul\n");
   fprintf(file,"                 Cstr X 1 add get 0.59 mul\n");
   fprintf(file,"                 Cstr X 2 add get 0.11 mul\n");
   fprintf(file,"                 add add cvi\n");
   fprintf(file,"               put\n");
   fprintf(file,"              } for\n");
   fprintf(file,"             Gstr\n");
   fprintf(file,"          }\n");
   fprintf(file,"        } if\n");
   fprintf(file,"        Ncomp 4 eq {\n");
   fprintf(file,"          /Gstr Bycomp Width mul string def\n");
   fprintf(file,"          { Dsrc exec\n");
   fprintf(file,"             /Cstr exch def\n");
   fprintf(file,"             0 1 Width 1 sub {\n");
   fprintf(file,"               /I exch def\n");
   fprintf(file,"               /X I 4 mul def\n");
   fprintf(file,"               Gstr I\n");
   fprintf(file,"                 2 Bcomp exp 1 sub\n");
   fprintf(file,"                 Cstr X       get 0.3  mul\n");
   fprintf(file,"                 Cstr X 1 add get 0.59 mul\n");
   fprintf(file,"                 Cstr X 2 add get 0.11 mul\n");
   fprintf(file,"                 Cstr X 3 add get\n");
   fprintf(file,"                 add add add dup 2 index gt {pop dup} if\n");
   fprintf(file,"                 sub cvi\n");
   fprintf(file,"               put\n");
   fprintf(file,"              } for\n");
   fprintf(file,"             Gstr\n");
   fprintf(file,"          }\n");
   fprintf(file,"        } if\n");
   fprintf(file,"        image\n");
   fprintf(file,"    } ifelse\n");
   fprintf(file,"    end\n");
   fprintf(file,"} bind def\n");
   fprintf(file,"} if\n");
}
/**************************************************************************
*       Save the Frame Buffer in a ps format file
**************************************************************************/
void save_geometry_ps_file(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *FileName;
	FILE *file;
	int i;
	int j;
	int k;
	int width;
	int height;
	guchar *rgbbuf;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    	return ;
 	}

        file = FOpen(FileName,"w");

        if (!file) {
            Message("Sorry: can't open output file\n","Error",TRUE);
            return;
        }

	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() )
		gtk_main_iteration();
	Waiting(1.0);

	gtk_window_move(GTK_WINDOW(GeomDlg),0,0);
	rafresh_drawing();
	while( gtk_events_pending() )
		gtk_main_iteration();
  


	rgbbuf = get_rgb_image();
	if (!rgbbuf) {
            return;
	}
	width =  ZoneDessin->allocation.width;
	height = ZoneDessin->allocation.height;


        fprintf(file,"%%!PS-Adobe-2.0 EPSF-2.0\n");
        fprintf(file,"%%%%BoundingBox: 16 16 %d %d\n",width+16,height+16);
        fprintf(file,"%%%%Creator: gabedit\n");
        fprintf(file,"%%%%Title: gabedit output file\n");
        fprintf(file,"%%%%EndComments\n");

	ps_header(file);

	fprintf(file,"/picstr %d string def\n",height*3);

	fprintf(file,"16 16 translate\n");
        fprintf(file,"%d %d scale\n",width,height);
        fprintf(file,"%d %d 8 [ %d 0 0 %d 0 0] \n",width,height,width,height);
        fprintf(file,"{ currentfile picstr readhexstring  pop }\n");
        fprintf(file,"false 3 colorimage\n");

        j = k = 0;
	for (i=0;i<width*height+1;i++){

	   fprintf(file,"%02x%02x%02x",rgbbuf[j],rgbbuf[j+1],rgbbuf[j+2]);
	   j += 3;
           k += 6;

           if (k>70){ 
                fprintf(file,"\n");
                k=0;
           }
        }
        fprintf(file,"\nshowpage\n");   
        fprintf(file,"%%%%Trailer\n");
        fclose(file);
        g_free(rgbbuf);
}
/**********************************************************************************************************************************/
void save_geometry_png_file(GabeditFileChooser *SelecFile, gint response_id)
{       
	if(response_id != GTK_RESPONSE_OK) return;
	save_geometry_image(SelecFile, "png");
}
