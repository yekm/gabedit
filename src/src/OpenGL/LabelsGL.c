/* GLArea.c */
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
#include "../Common/Global.h"
#include "GlobalOrb.h"
#include "../Utils/Vector3d.h"
#include "../Utils/Transformation.h"
#include "../Utils/UtilsGL.h"
#include "../Utils/Constantes.h"
#include "../Geometry/GeomGlobal.h"
#include "../OpenGL/AxisGL.h"
#include "../OpenGL/PrincipalAxisGL.h"

static gboolean showSymbols = FALSE;
static gboolean showNumbers = FALSE;
static gboolean showDistances = FALSE;
static gboolean showDipole = FALSE;
static gboolean showAxes = FALSE;
static gchar fontName[BSIZE] = "Sans 14";
static gboolean ortho = FALSE;

/*********************************************************************************************/
void init_labels_font()
{
	sprintf(fontName,"%s",FontsStyleLabel.fontname);
}
/*********************************************************************************************/
gboolean get_labels_ortho()
{
	return ortho;
}
/*********************************************************************************************/
void set_labels_ortho(gboolean o)
{
	ortho = o;
}
/*********************************************************************************************/
gboolean get_show_symbols()
{
	return showSymbols;
}
/*********************************************************************************************/
void set_show_symbols(gboolean ac)
{
	showSymbols=ac;
}
/*********************************************************************************************/
void showLabelSymbols()
{
	gint i;
	V4d Diffuse  = {0.8,0.8,0.8,0.8};
	V4d Specular = {0.8,0.8,0.8,0.8 };
	V4d Ambiant  = {0.8,0.8,0.8,0.8 };

	if(Ncenters<1) return;

	Ambiant[0] = FontsStyleLabel.TextColor.red/65535.0; 
	Ambiant[1] = FontsStyleLabel.TextColor.green/65535.0; 
	Ambiant[2] = FontsStyleLabel.TextColor.blue/65535.0; 
	for(i=0;i<3;i++)
	{
		Diffuse[i] = Ambiant[i];
		Specular[i] = Ambiant[i];
	}

	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant);
	if(strcmp(fontName,FontsStyleLabel.fontname)!=0)
	{
		init_labels_font();
		glInitFonts();
	}

	for(i=0;i<(gint)Ncenters;i++)
	{

		if(ortho)
			glPrintOrtho(GeomOrb[i].C[0], GeomOrb[i].C[1], GeomOrb[i].C[2], GeomOrb[i].Symb);
		else
		{
		/*	glPrint(GeomOrb[i].C[0], GeomOrb[i].C[1], GeomOrb[i].C[2], GeomOrb[i].Symb);*/
			glPrintScale(GeomOrb[i].C[0], GeomOrb[i].C[1], GeomOrb[i].C[2], 1.1*GeomOrb[i].Prop.radii,GeomOrb[i].Symb);
		}
	}
}
/*********************************************************************************************/
gboolean get_show_numbers()
{
	return showNumbers;
}
/*********************************************************************************************/
void set_show_numbers(gboolean ac)
{
	showNumbers=ac;
}
/*********************************************************************************************/
void showLabelNumbers()
{
	gint i;
	gchar buffer[BSIZE];
	V4d Diffuse  = {0.8,0.8,0.8,0.8};
	V4d Specular = {0.8,0.8,0.8,0.8 };
	V4d Ambiant  = {0.8,0.8,0.8,0.8 };

	if(Ncenters<1) return;

	Ambiant[0] = FontsStyleLabel.TextColor.red/65535.0; 
	Ambiant[1] = FontsStyleLabel.TextColor.green/65535.0; 
	Ambiant[2] = FontsStyleLabel.TextColor.blue/65535.0; 
	for(i=0;i<3;i++)
	{
		Diffuse[i] = Ambiant[i];
		Specular[i] = Ambiant[i];
	}

	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant);
	if(strcmp(fontName,FontsStyleLabel.fontname)!=0)
	{
		init_labels_font();
		glInitFonts();
	}

	for(i=0;i<(gint)Ncenters;i++)
	{

		sprintf(buffer,"%d",i+1);
		if(ortho)
			glPrintOrtho(GeomOrb[i].C[0], GeomOrb[i].C[1], GeomOrb[i].C[2], buffer);
		else
		{
			/*glPrint(GeomOrb[i].C[0], GeomOrb[i].C[1], GeomOrb[i].C[2], buffer);*/
			glPrintScale(GeomOrb[i].C[0], GeomOrb[i].C[1], GeomOrb[i].C[2], 1.1*GeomOrb[i].Prop.radii,buffer);
		}
	}
}
/*********************************************************************************************/
void showLabelSymbolsAndNumbers()
{
	gint i;
	gchar buffer[BSIZE];
	V4d Diffuse  = {0.8,0.8,0.8,0.8};
	V4d Specular = {0.8,0.8,0.8,0.8 };
	V4d Ambiant  = {0.8,0.8,0.8,0.8 };

	if(Ncenters<1) return;

	Ambiant[0] = FontsStyleLabel.TextColor.red/65535.0; 
	Ambiant[1] = FontsStyleLabel.TextColor.green/65535.0; 
	Ambiant[2] = FontsStyleLabel.TextColor.blue/65535.0; 
	for(i=0;i<3;i++)
	{
		Diffuse[i] = Ambiant[i];
		Specular[i] = Ambiant[i];
	}

	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant);
	if(strcmp(fontName,FontsStyleLabel.fontname)!=0)
	{
		init_labels_font();
		glInitFonts();
	}

	for(i=0;i<(gint)Ncenters;i++)
	{

		sprintf(buffer,"%s[%d]",GeomOrb[i].Symb,i+1);
		if(ortho)
			glPrintOrtho(GeomOrb[i].C[0], GeomOrb[i].C[1], GeomOrb[i].C[2], buffer);
		else
		{
			/* glPrint(GeomOrb[i].C[0], GeomOrb[i].C[1], GeomOrb[i].C[2], buffer);*/
			glPrintScale(GeomOrb[i].C[0], GeomOrb[i].C[1], GeomOrb[i].C[2], 1.1*GeomOrb[i].Prop.radii,buffer);
		}
	}
}
/*********************************************************************************************/
gboolean get_show_distances()
{
	return showDistances;
}
/*********************************************************************************************/
void set_show_distances(gboolean ac)
{
	showDistances=ac;
}
/*********************************************************************************************/
void showLabelDistances()
{
	gint i;
	gint k;
	gint j;
	gdouble distance;
	gfloat tmp[3];
	gchar buffer[BSIZE];
	V4d Diffuse  = {1.0,1.0,1.0,0.8};
	V4d Specular = {1.0,1.0,1.0,0.8 };
	V4d Ambiant  = {1.0,1.0,1.0,0.8 };

	if(Ncenters<1) return;
	Ambiant[0] = FontsStyleLabel.TextColor.red/65535.0; 
	Ambiant[1] = FontsStyleLabel.TextColor.green/65535.0; 
	Ambiant[2] = FontsStyleLabel.TextColor.blue/65535.0; 
	for(i=0;i<3;i++)
	{
		Diffuse[i] = Ambiant[i];
		Specular[i] = Ambiant[i];
	}


	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant);
	if(strcmp(fontName,FontsStyleLabel.fontname)!=0)
	{
		init_labels_font();
		glInitFonts();
	}

	for(i=0;i<(gint)Ncenters;i++)
	for(j=i+1;j<(gint)Ncenters;j++)
	{
		for(k=0;k<3;k++)
			tmp[k] = (GeomOrb[i].C[k] - GeomOrb[j].C[k]);
		distance = v3d_length(tmp);
		if(distance>=(GeomOrb[i].Prop.covalentRadii + GeomOrb[j].Prop.covalentRadii))
			continue;
		for(k=0;k<3;k++)
			tmp[k] = (GeomOrb[i].C[k] + GeomOrb[j].C[k])/2;
		sprintf(buffer, "%0.3f",distance);

		if(ortho)
			glPrintOrtho(tmp[0], tmp[1], tmp[2], buffer);
		else
		{
			/* glPrint(tmp[0], tmp[1], tmp[2], buffer);*/
			gdouble r = GeomOrb[i].Prop.radii;
			if(GeomOrb[j].Prop.radii>r)r = GeomOrb[j].Prop.radii; 
			glPrintScale(tmp[0], tmp[1], tmp[2], 1.1*r,buffer);
		}
	}
}
/*********************************************************************************************/
gboolean get_show_dipole()
{
	return showDipole;
}
/*********************************************************************************************/
void set_show_dipole(gboolean ac)
{
	showDipole=ac;
}
/*********************************************************************************************/
void showLabelDipole()
{
	gint i;
	V4d Diffuse  = {0.8,0.8,0.8,0.8};
	V4d Specular = {0.8,0.8,0.8,0.8 };
	V4d Ambiant  = {0.8,0.8,0.8,0.8 };
	V3d Base1Pos  = {0.0f,0.0f,0.0f};
	V3d Base2Pos  = {Dipole.Value[0],Dipole.Value[1],Dipole.Value[2]};
	GLfloat radius = Dipole.radius;
	V3d Center;
	GLfloat p1=90;
	GLfloat p2=10;
	GLfloat p = p1 + p2;
	GLfloat scal = 2;
	gdouble module;
	gchar buffer[BSIZE];

	if(Ncenters<1) return;
	if(!showDipole) return;
	if(!ShowDipoleOrb) return;

	Ambiant[0] = FontsStyleLabel.TextColor.red/65535.0; 
	Ambiant[1] = FontsStyleLabel.TextColor.green/65535.0; 
	Ambiant[2] = FontsStyleLabel.TextColor.blue/65535.0; 
	for(i=0;i<3;i++)
	{
		Diffuse[i] = Ambiant[i];
		Specular[i] = Ambiant[i];
	}

	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant);
	if(strcmp(fontName,FontsStyleLabel.fontname)!=0)
	{
		init_labels_font();
		glInitFonts();
	}

	if(radius<0.1) radius = 0.1;

	Base2Pos[0] *= scal;
	Base2Pos[1] *= scal;
	Base2Pos[2] *= scal;

	Center[0] = (Base1Pos[0]*p2 + Base2Pos[0]*p1)/p;
	Center[1] = (Base1Pos[1]*p2 + Base2Pos[1]*p1)/p;
	Center[2] = (Base1Pos[2]*p2 + Base2Pos[2]*p1)/p;

	module = 0;
	for(i=0;i<3;i++)
		module += Dipole.Value[i]*Dipole.Value[i];
	module = sqrt(module);
	module *= AUTODEB;
	sprintf(buffer,"%0.3f D",module);

	if(ortho)
		glPrintOrtho(Center[0], Center[1], Center[2], buffer);
	else
	{
	/*	glPrint(Center[0], Center[1], Center[2], buffer); */
		glPrintScale(Center[0], Center[1], Center[2], 1.1*radius,buffer);
	}
}
/*********************************************************************************************/
gboolean get_show_axes()
{
	return showAxes;
}
/*********************************************************************************************/
void set_show_axes(gboolean ac)
{
	showAxes=ac;
}
/*********************************************************************************************/
void showLabelAxes()
{
	gint i;
	V4d Diffuse  = {0.8,0.8,0.8,0.8};
	V4d Specular = {0.8,0.8,0.8,0.8 };
	V4d Ambiant  = {0.8,0.8,0.8,0.8 };
	gchar buffer[BSIZE];
	gboolean show;
	gboolean negative;
	gfloat origin[3];
	gfloat radius;
	gfloat scal;
	gfloat xColor[3];
	gfloat yColor[3];
	gfloat zColor[3];
	gfloat vectorX[]  = {1,0,0};
	gfloat vectorY[]  = {0,1,0};
	gfloat vectorZ[]  = {0,0,1};

	if(!showAxes) return;
	if(!testShowAxis()) return;

	getAxisProperties(&show, &negative, origin, &radius, &scal, xColor, yColor, zColor);

	for(i=0;i<3;i++)
	{
		vectorX[i] *= scal;
		vectorY[i] *= scal;
		vectorZ[i] *= scal;
	}
	for(i=0;i<3;i++)
	{
		vectorX[i] += origin[i];
		vectorY[i] += origin[i];
		vectorZ[i] += origin[i];
	}
	

	Ambiant[0] = FontsStyleLabel.TextColor.red/65535.0; 
	Ambiant[1] = FontsStyleLabel.TextColor.green/65535.0; 
	Ambiant[2] = FontsStyleLabel.TextColor.blue/65535.0; 
	for(i=0;i<3;i++)
	{
		Diffuse[i] = Ambiant[i];
		Specular[i] = Ambiant[i];
	}

	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant);
	if(strcmp(fontName,FontsStyleLabel.fontname)!=0)
	{
		init_labels_font();
		glInitFonts();
	}

	if(radius<0.1) radius = 0.1;


	if(ortho)
	{
		sprintf(buffer,"X");
		glPrintOrtho(vectorX[0], vectorX[1], vectorX[2], buffer);
		sprintf(buffer,"Y");
		glPrintOrtho(vectorY[0], vectorY[1], vectorY[2], buffer);
		sprintf(buffer,"Z");
		glPrintOrtho(vectorZ[0], vectorZ[1], vectorZ[2], buffer);
	}
	else
	{
		/*
		sprintf(buffer,"X");
		glPrint(vectorX[0], vectorX[1], vectorX[2], buffer);
		sprintf(buffer,"Y");
		glPrint(vectorY[0], vectorY[1], vectorY[2], buffer);
		sprintf(buffer,"Z");
		glPrint(vectorZ[0], vectorZ[1], vectorZ[2], buffer);
		*/
		sprintf(buffer,"X");
		glPrintScale(vectorX[0], vectorX[1], vectorX[2], 1.1*radius, buffer);
		sprintf(buffer,"Y");
		glPrintScale(vectorY[0], vectorY[1], vectorY[2], 1.1*radius, buffer);
		sprintf(buffer,"Z");
		glPrintScale(vectorZ[0], vectorZ[1], vectorZ[2], 1.1*radius, buffer);
	}
}
/*********************************************************************************************/
void showLabelPrincipalAxes()
{
	gint i;
	V4d Diffuse  = {0.8,0.8,0.8,0.8};
	V4d Specular = {0.8,0.8,0.8,0.8 };
	V4d Ambiant  = {0.8,0.8,0.8,0.8 };
	gchar buffer[BSIZE];
	gboolean show;
	gboolean negative;
	gboolean def;
	gfloat origin[3];
	gfloat radius;
	gfloat scal;
	gfloat c1[3];
	gfloat c2[3];
	gfloat c3[3];
	gfloat v1[]  = {1,0,0};
	gfloat v2[]  = {0,1,0};
	gfloat v3[]  = {0,0,1};
	gfloat I[]  = {1,1,1};

	if(!showAxes) return;
	if(!testShowPrincipalAxisGL()) return;

	getPrincipalAxisProperties(&show, &negative, &def, origin, &radius, &scal, v1,v2, v3, c1,c2, c3);
	if(!def) return;
	getPrincipalAxisInertias(I);

	for(i=0;i<3;i++)
	{
		v1[i] *= scal;
		v2[i] *= scal;
		v3[i] *= scal;
	}
	for(i=0;i<3;i++)
	{
		v1[i] += origin[i];
		v2[i] += origin[i];
		v3[i] += origin[i];
	}
	

	Ambiant[0] = FontsStyleLabel.TextColor.red/65535.0; 
	Ambiant[1] = FontsStyleLabel.TextColor.green/65535.0; 
	Ambiant[2] = FontsStyleLabel.TextColor.blue/65535.0; 
	for(i=0;i<3;i++)
	{
		Diffuse[i] = Ambiant[i];
		Specular[i] = Ambiant[i];
	}

	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant);
	if(strcmp(fontName,FontsStyleLabel.fontname)!=0)
	{
		init_labels_font();
		glInitFonts();
	}

	if(radius<0.1) radius = 0.1;


	if(ortho)
	{
		sprintf(buffer,"I=%0.3f",I[0]);
		glPrintOrtho(v1[0], v1[1], v1[2], buffer);
		sprintf(buffer,"I=%0.3f",I[1]);
		glPrintOrtho(v2[0], v2[1], v2[2], buffer);
		sprintf(buffer,"I=%0.3f",I[2]);
		glPrintOrtho(v3[0], v3[1], v3[2], buffer);
	}
	else
	{
		/*
		sprintf(buffer,"I=%0.3f",I[0]);
		glPrint(v1[0], v1[1], v1[2], buffer);
		sprintf(buffer,"I=%0.3f",I[1]);
		glPrint(v2[0], v2[1], v2[2], buffer);
		sprintf(buffer,"I=%0.3f",I[2]);
		glPrint(v3[0], v3[1], v3[2], buffer);
		*/
		sprintf(buffer,"I=%0.3f",I[0]);
		glPrintScale(v1[0], v1[1], v1[2], 1.1*radius, buffer);
		sprintf(buffer,"I=%0.3f",I[1]);
		glPrintScale(v2[0], v2[1], v2[2], 1.1*radius, buffer);
		sprintf(buffer,"I=%0.3f",I[2]);
		glPrintScale(v3[0], v3[1], v3[2], 1.1*radius, buffer);
	}
}
