/* Postscript.c */
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
#include <math.h>

#include "../Common/Global.h"
#include "../Utils/Constantes.h"
#include "../Utils/UtilsInterface.h"
#include "../Geometry/InterfaceGeom.h"
#include "../Utils/Utils.h"
#include "../Utils/AtomsProp.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/Mesure.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Common/Windows.h"

typedef struct _PColor
{
/* Red Green Blue GreyScale */
 gdouble Colors[4];
}PColor;

typedef struct _XYRC
{
/* X=C[0], Y=C[1], Radius=C[2] */
 gushort C[3];
/* Red Green Blue GreyScale */
 PColor P;
}XYRC;
/********************************************************************************/
void set_color_shad_post(PColor *color,guint i)
{
 guint k;
 gdouble Coef=1.0;
 if(fabs(coordmaxmin.Zmax-coordmaxmin.Zmin)>1.e-6)
 {
 	Coef = fabs(0.99-0.2*(coordmaxmin.Zmax-geometry[i].Z)/(coordmaxmin.Zmax-coordmaxmin.Zmin));
        if(Coef<1.0)
        	for(k=0;k<4;k++)
			color->Colors[k] *=  Coef;
 }
}
/********************************************************************************/
gchar *get_first()
{
     gchar *temp;
     temp = g_strdup("%!PS-Adobe-2.0 EPSF-2.0\n");
     temp = g_strdup_printf("%s%%%%Title: Gabedit\n",temp);
     temp = g_strdup_printf("%s%%%%For: Allouche\n",temp);
     temp = g_strdup_printf("%s%%%%Creator: Allouche AR\n",temp);
     temp = g_strdup_printf("%s%%%%DocumentFonts: Courier\n",temp);
     temp = g_strdup_printf("%s%%%%Pages (atend)\n",temp);
     temp = g_strdup_printf("%s%%%%BoundingBox: 0 0 612 792\n",temp);
     temp = g_strdup_printf("%s%% \n",temp);
     return temp;
}
/********************************************************************************/
gchar *get_preferences()
{
     gchar *temp;
     temp = g_strdup("%%###### Preferences ############\n");
     temp = g_strdup_printf("%s/size    {  0.24 } def\n",temp);
     temp = g_strdup_printf("%s/originx {  0.0 } def\n",temp);
     temp = g_strdup_printf("%s/originy {  792.0 } def\n",temp);
     temp = g_strdup_printf("%s/angle   {  -90.0 } def\n",temp);

     if(label_option() != LABELNO  || distances_draw_mode() || dipole_draw_mode())
     {
     temp = g_strdup_printf("%s/fontwidth {36} def\n",temp);
     temp = g_strdup_printf("%s/fontheight {47} def\n",temp);
     }
     temp = g_strdup_printf("%s%%###### END Preferences ############\n",temp);
     return temp;
}
/********************************************************************************/
gchar *get_doball()
{
     gchar *temp;
     temp = g_strdup("/doball\n");
     temp = g_strdup_printf("%s{\n",temp);
     temp = g_strdup_printf("%s\t stickwidth setlinewidth\n",temp);
     temp = g_strdup_printf("%s\t 1 setlinecap\n",temp);
     temp = g_strdup_printf("%s\t 2 setlinejoin\n",temp);
     temp = g_strdup_printf("%s\t colorred colorgreen colorblue setrgbcolor\n",temp);
     temp = g_strdup_printf("%s\t newpath\n",temp);
     temp = g_strdup_printf("%s\t x y r 0 360 arc\n",temp);
     temp = g_strdup_printf("%s\t fill\n",temp);
     temp = g_strdup_printf("%s\t stroke \n",temp);
     temp = g_strdup_printf("%s\t } def\n",temp);
     return temp;
}
/********************************************************************************/
gchar *get_dostick()
{
     gchar *temp;
     temp = g_strdup("/dostick\n");
     temp = g_strdup_printf("%s{\n",temp);
     temp = g_strdup_printf("%s\t stickwidth setlinewidth\n",temp);
     temp = g_strdup_printf("%s\t 1 setlinecap\n",temp);
     temp = g_strdup_printf("%s\t 2 setlinejoin\n",temp);
     temp = g_strdup_printf("%s\t colorred colorgreen colorblue setrgbcolor\n",temp);
     temp = g_strdup_printf("%s\t newpath\n",temp);
     temp = g_strdup_printf("%s\t x1 y1 moveto\n",temp);
     temp = g_strdup_printf("%s\t x2 y2 lineto\n",temp);
     temp = g_strdup_printf("%s\t stroke \n",temp);
     temp = g_strdup_printf("%s\t } def\n",temp);
     return temp;
}
/********************************************************************************/
gchar *get_dostick_hbond()
{
     gchar *temp;
     temp = g_strdup("/dostickhbond\n");
     temp = g_strdup_printf("%s{\n",temp);
     temp = g_strdup_printf("%s\t stickwidth setlinewidth\n",temp);
     temp = g_strdup_printf("%s\t 0 setlinecap [8 14] 0 setdash\n",temp);
     temp = g_strdup_printf("%s\t 2 setlinejoin\n",temp);
     temp = g_strdup_printf("%s\t colorred colorgreen colorblue setrgbcolor\n",temp);
     temp = g_strdup_printf("%s\t newpath\n",temp);
     temp = g_strdup_printf("%s\t x1 y1 moveto\n",temp);
     temp = g_strdup_printf("%s\t x2 y2 lineto\n",temp);
     temp = g_strdup_printf("%s\t stroke \n",temp);
     temp = g_strdup_printf("%s\t 0 setlinecap [] 0 setdash\n",temp);
     temp = g_strdup_printf("%s\t } def\n",temp);
     return temp;
}
/********************************************************************************/
gchar *get_doball_3d()
{
 		
 		

     gchar *temp;
     temp = g_strdup("/doball3d\n");
     temp = g_strdup_printf("%s{\n",temp);
     temp = g_strdup_printf("%s\t stickwidth setlinewidth\n",temp);
     temp = g_strdup_printf("%s\t 1 setlinecap\n",temp);
     temp = g_strdup_printf("%s\t 2 setlinejoin\n",temp);
     temp = g_strdup_printf("%s\t colorred colorgreen colorblue setrgbcolor\n",temp);
	 temp = g_strdup_printf("%s\t 90 -1 1\n",temp);
	 temp = g_strdup_printf("%s\t{ \n",temp);
	 temp = g_strdup_printf("%s\tdup \n",temp);
	 temp = g_strdup_printf("%s\tdup cos colorred mul exch  \n",temp);
	 temp = g_strdup_printf("%s\tdup cos colorgreen mul exch  \n",temp);
	 temp = g_strdup_printf("%s\tdup cos colorblue mul exch \n",temp);
	 temp = g_strdup_printf("%s\t pop \n",temp);
	 temp = g_strdup_printf("%s\t setrgbcolor\n",temp);
     temp = g_strdup_printf("%s\t newpath\n",temp);
     temp = g_strdup_printf("%s\t 	  	sin r mul x exch y exch 0 360 arc\n",temp);
     temp = g_strdup_printf("%s\tclosepath fill } for\n",temp); 
     temp = g_strdup_printf("%s\t } def\n",temp);
     return temp;
}

/********************************************************************************/
gchar *get_dostick_3d()
{		 
     gchar *temp;
     temp = g_strdup("/dostick3d\n");
     temp = g_strdup_printf("%s{\n",temp);
     temp = g_strdup_printf("%s\t stickwidth setlinewidth\n",temp);
	 /*
     temp = g_strdup_printf("%s\t 1 setlinecap\n",temp);
     temp = g_strdup_printf("%s\t 2 setlinejoin\n",temp);
	 */
     temp = g_strdup_printf("%s\t colorred colorgreen colorblue setrgbcolor\n",temp);
	 temp = g_strdup_printf("%s\t 90 -5 1\n",temp);
	 temp = g_strdup_printf("%s\t {\n",temp);
	 temp = g_strdup_printf("%s\t dup\n",temp);
	 temp = g_strdup_printf("%s\t dup cos colorred mul exch \n",temp);
	 temp = g_strdup_printf("%s\t dup cos colorgreen mul exch \n",temp);
	 temp = g_strdup_printf("%s\tdup cos colorblue mul exch \n",temp);
	 temp = g_strdup_printf("%s\t pop\n",temp);
	 temp = g_strdup_printf("%s\t setrgbcolor\n",temp);
	 temp = g_strdup_printf("%s\t dup sin stickwidth mul setlinewidth\n",temp);
     temp = g_strdup_printf("%s\t newpath\n",temp);
     temp = g_strdup_printf("%s\t x1 y1 moveto\n",temp);
     temp = g_strdup_printf("%s\t x2 y2 lineto\n",temp);
	 temp = g_strdup_printf("%s\t closepath stroke\n",temp);
	 temp = g_strdup_printf("%s\t } for\n",temp);
     temp = g_strdup_printf("%s\t } def\n",temp);
     return temp;
}
/********************************************************************************/
gchar *get_epilogue()
{
     gchar *temp;
     temp = g_strdup("/stickwidth 10 def\n");
     temp = g_strdup_printf("%s \n",temp);
     if(label_option() != LABELNO  || distances_draw_mode() || dipole_draw_mode())
     	temp = g_strdup_printf("%s /Helvetica-Bold findfont [ fontwidth   0   0  fontheight   0   0] makefont setfont \n",temp);
     temp = g_strdup_printf("%s originx originy translate \n",temp);
     temp = g_strdup_printf("%s angle rotate \n",temp);
     temp = g_strdup_printf("%s 3 setlinewidth\n",temp);
     temp = g_strdup_printf("%s 2 setlinecap\n",temp);
     temp = g_strdup_printf("%s size size scale\n",temp);
     temp = g_strdup_printf("%s %%%%EndProlog\n",temp);
     temp = g_strdup_printf("%s %%%%Page: ? 1\n",temp);
     temp = g_strdup_printf("%s newpath\n",temp);
     return temp;
}
/********************************************************************************/
gchar *get_end()
{
     gchar *temp;
     temp = g_strdup("showpage\n");
     temp = g_strdup_printf("%s originx originy translate \n",temp);
     temp = g_strdup_printf("%s angle rotate \n",temp);
     temp = g_strdup_printf("%s 3 setlinewidth\n",temp);
     temp = g_strdup_printf("%s 2 setlinecap\n",temp);
     temp = g_strdup_printf("%s size size scale\n",temp);
     return temp;
}
/********************************************************************************/
XYRC get_prop_center(guint Num)
{
        guint i;
        XYRC PropCenter;
	gushort XMDrawing;
	gushort YMDrawing;
	gushort RMDrawing;

	gushort XMPost=2550;
	gushort YMPost=2550;

	XMDrawing=ZoneDessin->allocation.width;
	YMDrawing=ZoneDessin->allocation.height;
        RMDrawing =  XMDrawing;
        if(RMDrawing <  YMDrawing)
        	RMDrawing =  YMDrawing;

	PropCenter.C[0]=(gushort)(((gdouble)geometry[Num].Xi- XMDrawing/2)*(gdouble)XMPost/
				   (gdouble)RMDrawing+XMPost/2); 
	PropCenter.C[1]=(gushort)(((gdouble)geometry[Num].Yi- YMDrawing/2)*(gdouble)YMPost/
				   (gdouble)RMDrawing+YMPost/2);
	PropCenter.C[2]=(gushort)(geometry[Num].Rayon*(gdouble)XMPost/(gdouble)RMDrawing);

/*
        printf("%d %d %d\n",PropCenter.C[0],PropCenter.C[1],PropCenter.C[2]);
*/
	PropCenter.P.Colors[0]=(gdouble)(geometry[Num].Prop.color.red/65535.0);
	PropCenter.P.Colors[1]=(gdouble)(geometry[Num].Prop.color.green/65535.0);
	PropCenter.P.Colors[2]=(gdouble)(geometry[Num].Prop.color.blue/65535.0);

	PropCenter.P.Colors[3]=0.0;
        for(i=0;i<3;i++)
	  PropCenter.P.Colors[3]+=PropCenter.P.Colors[i];

	PropCenter.P.Colors[3]/=3.0;
        return  PropCenter;

}
/********************************************************************************/
gchar *get_draw_line(gint x1,gint y1,gint x2,gint y2,PColor color,gint epaisseur)
{
     gchar *temp;
     temp = g_strdup_printf("/x1 %d def\n",x1);
     temp = g_strdup_printf("%s/y1 %d def\n",temp,y1);
     temp = g_strdup_printf("%s/x2 %d def\n",temp,x2);
     temp = g_strdup_printf("%s/y2 %d def\n",temp,y2);
     temp=g_strdup_printf("%s/colorred %f def\n",temp,color.Colors[0]);
     temp=g_strdup_printf("%s/colorgreen %f def\n",temp,color.Colors[1]);
     temp=g_strdup_printf("%s/colorblue  %f def\n",temp,color.Colors[2]);
     temp = g_strdup_printf("%s /stickwidth %d def \n",temp,epaisseur);
     temp = g_strdup_printf("%s dostick \n",temp);
 return temp;

}
/********************************************************************************/
gchar *get_draw_line_hbond(gint x1,gint y1,gint x2,gint y2,PColor color,gint epaisseur)
{
     gchar *temp;
     temp = g_strdup_printf("/x1 %d def\n",x1);
     temp = g_strdup_printf("%s/y1 %d def\n",temp,y1);
     temp = g_strdup_printf("%s/x2 %d def\n",temp,x2);
     temp = g_strdup_printf("%s/y2 %d def\n",temp,y2);
     temp=g_strdup_printf("%s/colorred %f def\n",temp,color.Colors[0]);
     temp=g_strdup_printf("%s/colorgreen %f def\n",temp,color.Colors[1]);
     temp=g_strdup_printf("%s/colorblue  %f def\n",temp,color.Colors[2]);
     temp = g_strdup_printf("%s /stickwidth %d def \n",temp,epaisseur);
     temp = g_strdup_printf("%s dostickhbond \n",temp);
 return temp;

}
/********************************************************************************/
gchar *get_draw_line_3d(gint x1,gint y1,gint x2,gint y2,PColor color,gint epaisseur)
{
     gchar *temp;
     temp = g_strdup_printf("/x1 %d def\n",x1);
     temp = g_strdup_printf("%s/y1 %d def\n",temp,y1);
     temp = g_strdup_printf("%s/x2 %d def\n",temp,x2);
     temp = g_strdup_printf("%s/y2 %d def\n",temp,y2);
     temp=g_strdup_printf("%s/colorred %f def\n",temp,color.Colors[0]);
     temp=g_strdup_printf("%s/colorgreen %f def\n",temp,color.Colors[1]);
     temp=g_strdup_printf("%s/colorblue  %f def\n",temp,color.Colors[2]);
     temp = g_strdup_printf("%s /stickwidth %d def \n",temp,epaisseur);
     temp = g_strdup_printf("%s dostick3d \n",temp);
 return temp;

}
/********************************************************************************/
gchar *get_draw_distance(gint i,gint j,gint x0,gint y0)
{
        Point A;
        Point B;
        gchar *temp;

	A.C[0]=geometry[i].X;
	A.C[1]=geometry[i].Y;
	A.C[2]=geometry[i].Z;
        
	B.C[0]=geometry[j].X;
	B.C[1]=geometry[j].Y;
	B.C[2]=geometry[j].Z;
     temp = g_strdup_printf("%d %d moveto\t",x0,y0);
     temp = g_strdup_printf("%s\t 0 0 0 setrgbcolor\t",temp);
     temp = g_strdup_printf("%s(%s) show\n",temp,get_distance_points(A,B,TRUE));

        return temp;

}
/********************************************************************************/
gchar *get_draw_line2_hbond(gint epaisseur,guint i,guint j,gint x1,gint y1,gint x2,gint y2,PColor color1,PColor color2)
{
	gint x0;
	gint y0;

        gdouble poid1;
        gdouble poid2;
        gdouble poid;
        gchar *temp;
        gchar *t;
        
        poid1 = geometry[i].Prop.covalentRadii+geometry[i].Prop.radii;
        poid2 = geometry[j].Prop.covalentRadii+geometry[j].Prop.radii;
        poid = poid1 + poid2 ;
	x0=(gint)((x1*poid2+x2*poid1)/poid+0.5);
	y0=(gint)((y1*poid2+y2*poid1)/poid+0.5);
	temp=get_draw_line_hbond(x1,y1,x0,y0,color1,epaisseur);
	t=get_draw_line_hbond(x0,y0,x2,y2,color2,epaisseur);
	temp=g_strdup_printf("%s%s",temp,t);
        g_free(t);
	if(distances_draw_mode())
        {
           t=get_draw_distance(i,j,x0,y0); 
	   temp=g_strdup_printf("%s%s",temp,t);
           g_free(t);
        }
    return temp;
}
/********************************************************************************/
gchar *get_draw_line2(gint epaisseur,guint i,guint j,gint x1,gint y1,gint x2,gint y2,PColor color1,PColor color2,gboolean hideDistance)
{
	gint x0;
	gint y0;

        gdouble poid1;
        gdouble poid2;
        gdouble poid;
        gchar *temp;
        gchar *t;
        
        poid1 = geometry[i].Prop.covalentRadii+geometry[i].Prop.radii;
        poid2 = geometry[j].Prop.covalentRadii+geometry[j].Prop.radii;
        poid = poid1 + poid2 ;
	x0=(gint)((x1*poid2+x2*poid1)/poid+0.5);
	y0=(gint)((y1*poid2+y2*poid1)/poid+0.5);
	temp=get_draw_line(x1,y1,x0,y0,color1,epaisseur);
	t=get_draw_line(x0,y0,x2,y2,color2,epaisseur);
	temp=g_strdup_printf("%s%s",temp,t);
        g_free(t);
	if(!hideDistance && distances_draw_mode())
        {
           t=get_draw_distance(i,j,x0,y0); 
	   temp=g_strdup_printf("%s%s",temp,t);
           g_free(t);
        }
    return temp;
}
/********************************************************************************/
gchar *get_draw_line2_3d(gint epaisseur,guint i,guint j,gint x1,gint y1,gint x2,gint y2,PColor color1,PColor color2,gboolean hideDistance)
{
	gint x0;
	gint y0;
	gint xp;
	gint yp;
	gdouble k;
        gushort rayon;

	
	gdouble poid1;
	gdouble poid2;
	gdouble poid;
	gchar *temp;
	gchar *t;
	XYRC xyrc1;

	if( !stick_mode())
    	{
		xyrc1= get_prop_center(i);
                rayon =(gushort)(xyrc1.C[2]*factorball);
			if (pers_mode()) 
                	rayon =(gushort)(geometry[i].Coefpers*xyrc1.C[2]*factorball);
                k= ((gdouble)rayon*(gdouble)rayon-(gdouble)epaisseur*(gdouble)epaisseur/4.0);
		 if(get_connection_type(i,j)==2) k= ((gdouble)rayon*(gdouble)rayon-(gdouble)epaisseur*(gdouble)epaisseur*9.0/4);
		 if(get_connection_type(i,j)==3) k= ((gdouble)rayon*(gdouble)rayon-(gdouble)epaisseur*(gdouble)epaisseur*25.0/4);

		if(k>0 &&(( (gdouble)(x2-x1)*(gdouble)(x2-x1)+(gdouble)(y2-y1)*(gdouble)(y2-y1) )>1e-6))
                k = (sqrt(k))/(gdouble)(sqrt( (gdouble)(x2-x1)*(gdouble)(x2-x1)+(gdouble)(y2-y1)*(gdouble)(y2-y1) ) );     
                else
                 k=0.0;
		xp = x1 + (gint)(k *(x2-x1) +0.5);
		yp = y1 + (gint)(k *(y2-y1) +0.5);
    	}
     	else
     	{
		xp = x1;
		yp = y1;

     	}
        poid1 = geometry[i].Prop.covalentRadii+geometry[i].Prop.radii;
        poid2 = geometry[j].Prop.covalentRadii+geometry[j].Prop.radii;
        poid = poid1 + poid2 ;

	x0=(gint)((x1*poid2+x2*poid1)/poid +0.5);
	y0=(gint)((y1*poid2+y2*poid1)/poid +0.5);
	temp=get_draw_line_3d(xp,yp,x0,y0,color1,epaisseur);
	t=get_draw_line_3d(x0,y0,x2,y2,color2,epaisseur);

	if(!stick_mode())
		temp=g_strdup_printf("	 0 setlinecap\n 2 setlinejoin\n %s 0 setlinecap\n 0 setlinejoin\n %s",temp,t);
        else
		temp=g_strdup_printf("	 1 setlinecap\n 2 setlinejoin\n %s 1 setlinecap\n 2 setlinejoin\n %s",temp,t);
	
        g_free(t);
	if(!hideDistance && distances_draw_mode())
        {
           t=get_draw_distance(i,j,x0,y0); 
	   temp=g_strdup_printf("%s%s",temp,t);
           g_free(t);
        }
    return temp;
}
/********************************************************************************/
gchar *get_draw_cercle(gint x,gint y,gint rayon,PColor color)
{
     gchar *temp;
     temp = g_strdup_printf("/x %d def\n",x);
     temp = g_strdup_printf("%s/y %d def\n",temp,y);
     temp = g_strdup_printf("%s/r %d def\n",temp,rayon);
     temp=g_strdup_printf("%s/colorred %f def\n",temp,color.Colors[0]);
     temp=g_strdup_printf("%s/colorgreen %f def\n",temp,color.Colors[1]);
     temp=g_strdup_printf("%s/colorblue  %f def\n",temp,color.Colors[2]);
     temp = g_strdup_printf("%s doball \n",temp);
 return temp;

}
/********************************************************************************/
gchar *get_draw_cercle_3d(gint x,gint y,gint rayon,PColor color)
{
     gchar *temp;
     temp = g_strdup_printf("/x %d def\n",x);
     temp = g_strdup_printf("%s/y %d def\n",temp,y);
     temp = g_strdup_printf("%s/r %d def\n",temp,rayon);
     temp=g_strdup_printf("%s/colorred %f def\n",temp,color.Colors[0]);
     temp=g_strdup_printf("%s/colorgreen %f def\n",temp,color.Colors[1]);
     temp=g_strdup_printf("%s/colorblue  %f def\n",temp,color.Colors[2]);
     temp = g_strdup_printf("%s doball3d \n",temp);
 return temp;

}
/********************************************************************************/
gchar *get_draw_symb(guint epaisseur,guint i,gint x,gint y)
{
     gchar *temp;
     temp = g_strdup_printf("%d %d moveto\t",x,y);
     temp = g_strdup_printf("%s\t 0 0 0 setrgbcolor\t",temp);
     temp = g_strdup_printf("%s(%s) show\n",temp,geometry[i].Prop.symbol);
     return temp; 
}
/********************************************************************************/
gchar* get_draw_numb(guint epaisseur,guint i,gint x,gint y)
{
     gchar *temp;
     temp = g_strdup_printf("%d %d moveto\t",x,y);
     temp = g_strdup_printf("%s\t 0 0 0 setrgbcolor\t",temp);
     temp = g_strdup_printf("%s(%d) show\n",temp,geometry[i].N);
     return temp; 
}
/********************************************************************************/
gchar *get_draw_layer(guint epaisseur,guint i,gint x,gint y)
{
     gchar *temp;
     temp = g_strdup_printf("%d %d moveto\t",x,y);
     temp = g_strdup_printf("%s\t 0 0 0 setrgbcolor\t",temp);
     if(geometry[i].Layer==LOW_LAYER) temp = g_strdup_printf("%s(L) show\n",temp);
     else if(geometry[i].Layer==MEDIUM_LAYER) temp = g_strdup_printf("%s(M) show\n",temp);
     else temp = g_strdup_printf("%s( ) show\n",temp);
     return temp; 
}
/********************************************************************************/
gchar *get_draw_mmtyp(guint epaisseur,guint i,gint x,gint y)
{
     gchar *temp;
     temp = g_strdup_printf("%d %d moveto\t",x,y);
     temp = g_strdup_printf("%s\t 0 0 0 setrgbcolor\t",temp);
     temp = g_strdup_printf("%s(%s) show\n",temp,geometry[i].mmType);
     return temp; 
}
/********************************************************************************/
gchar *get_draw_pdbtyp(guint epaisseur,guint i,gint x,gint y)
{
     gchar *temp;
     temp = g_strdup_printf("%d %d moveto\t",x,y);
     temp = g_strdup_printf("%s\t 0 0 0 setrgbcolor\t",temp);
     temp = g_strdup_printf("%s(%s) show\n",temp,geometry[i].pdbType);
     return temp; 
}
/********************************************************************************/
gchar* get_draw_numb_symb(guint epaisseur,guint i,gint x,gint y)
{
     gchar *temp;
     temp = g_strdup_printf("%d %d moveto\t",x,y);
     temp = g_strdup_printf("%s\t 0 0 0 setrgbcolor\t",temp);
     temp = g_strdup_printf("%s(%s[%d]) show\n",temp,geometry[i].Prop.symbol,geometry[i].N);
     return temp; 
}
/********************************************************************************/
gchar *get_draw_label(guint epaisseur,guint i,gint x,gint y)
{
   gchar *temp=NULL;
   switch(label_option())
   {
   case LABELSYMB: temp=get_draw_symb(epaisseur,i,x,y);break;
   case LABELNUMB: temp=get_draw_numb(epaisseur,i,x,y);break;
   case LABELMMTYP: temp=get_draw_mmtyp(epaisseur,i,x,y);break;
   case LABELPDBTYP: temp=get_draw_pdbtyp(epaisseur,i,x,y);break;
   case LABELLAYER: temp=get_draw_layer(epaisseur,i,x,y);break;
   case LABELSYMBNUMB: temp=get_draw_numb_symb(epaisseur,i,x,y);break;
   }
     return temp; 
}
/********************************************************************************/
XYRC get_prop_dipole(gint Num)
{
        guint i;
        XYRC PropCenter;
	gushort XMDrawing;
	gushort YMDrawing;
	gushort RMDrawing;

	gushort XMPost=2550;
	gushort YMPost=2550;

	XMDrawing=ZoneDessin->allocation.width;
	YMDrawing=ZoneDessin->allocation.height;
        RMDrawing =  XMDrawing;
        if(RMDrawing <  YMDrawing)
        	RMDrawing =  YMDrawing;

	PropCenter.C[0]=(gushort)(((gdouble)DXi[Num]- XMDrawing/2)*(gdouble)XMPost/
				   (gdouble)RMDrawing+XMPost/2); 
	PropCenter.C[1]=(gushort)(((gdouble)DYi[Num]- YMDrawing/2)*(gdouble)YMPost/
				   (gdouble)RMDrawing+YMPost/2);
	PropCenter.C[2]=(gushort)(10*factorstick*geometry[0].Coefpers*(gdouble)XMPost/(gdouble)RMDrawing);

	if(Num<NDIVDIPOLE-1)
		PropCenter.P.Colors[0]=50000;
	else
		PropCenter.P.Colors[0]=60000;
	PropCenter.P.Colors[1]=0;
	PropCenter.P.Colors[2]=0;

	PropCenter.P.Colors[3]=0.0;
        for(i=0;i<3;i++)
	  PropCenter.P.Colors[3]+=PropCenter.P.Colors[i];

	PropCenter.P.Colors[3]/=3.0;
        return  PropCenter;
}
/********************************************************************************/
gchar *get_draw_dipole(gint x0,gint y0)
{
        gchar *temp;
	gchar *t;
	gint i;
	gdouble d = 0.0;

	for(i=0;i<3;i++)
		d += Dipole.Value[i]*Dipole.Value[i];


     	t = g_strdup_printf("%d %d moveto\t",x0,y0);
     	temp = g_strdup_printf("%s\t 0 0 0 setrgbcolor\t",t);
	g_free(t);
	t = g_strdup_printf("%0.3f D",sqrt(d)*AUTODEB);
     	temp = g_strdup_printf("%s(%s) show\n",temp,t);

        return temp;

}
/*****************************************************************************/
gchar* dessine_dipole_post(gint i)
{	
	gchar *t;
	XYRC c1,c2 ;

    	if(!Ddef)
		return NULL;

	c1 = get_prop_dipole(i);
	if(i<NDIVDIPOLE-1)
	{
		gchar* v;
		c2 = get_prop_dipole(i+1);
/*		if (light_mode()) */
		if (TRUE) 
		t = get_draw_line_3d(c1.C[0],c1.C[1],c2.C[0],c2.C[1],c1.P,c1.C[2]);
		else
		t = get_draw_line(c1.C[0],c1.C[1],c2.C[0],c2.C[1],c1.P,c1.C[2]);
		if(dipole_draw_mode() && i==NDIVDIPOLE/2)
		{
	 		v = get_draw_dipole(c1.C[0],c1.C[1]);
			t = g_strdup_printf("%s%s",t,v);
			g_free(v);
		}
	}
	else
	{
/*		if (light_mode()) */
		if (TRUE) 
		t = get_draw_cercle_3d(c1.C[0],c1.C[1],c1.C[2],c1.P);
		else
		t = get_draw_cercle(c1.C[0],c1.C[1],c1.C[2],c1.P);
	}
	return t;
}
/********************************************************************************/
gchar *dessine_ball_post()
{	
	guint i;
	guint j;
	guint k;
	gint epaisseur;
        gushort rayon;
	PColor color1;
	PColor color2;
	XYRC xyrc1;
	XYRC xyrc2;
        gchar *temp;
        gchar *t;
	gint split[2] = {0,0};
	gdouble ab[] = {0,0};
	gint x1, x2, y1,y2;

        temp=g_strdup("\n");

	for(i=0;i<Natoms-1;i++)
	{
		xyrc1= get_prop_center(i);
                rayon =(gushort)(xyrc1.C[2]*factorball);
				if (pers_mode()) 
                	rayon =(gushort)(geometry[i].Coefpers*xyrc1.C[2]*factorball);

		color1 = xyrc1.P;  
			if (shad_mode()) 
			 set_color_shad_post(&color1,i);

/*		if (light_mode()) */
		if (TRUE) 
		t=get_draw_cercle_3d(xyrc1.C[0],xyrc1.C[1],rayon,color1);
        	else
		t=get_draw_cercle(xyrc1.C[0],xyrc1.C[1],rayon,color1);
                temp=g_strdup_printf("%s%s",temp,t);
                g_free(t); 
		for(j=i+1;j<Natoms;j++)
                if( get_connection_type(i,j)>0)
		{
			gint nc = get_connection_type(i,j);
			xyrc2= get_prop_center(j);
			k =get_num_min_rayonIJ(i,j);

                	if(k==i) epaisseur = (gint) (xyrc1.C[2]*factorstick);
                	else epaisseur = (gint) (xyrc2.C[2]*factorstick);
                 
			if (pers_mode()) epaisseur =(gint)(geometry[k].Coefpers*epaisseur);

			color2 = xyrc2.P;  

			if (shad_mode()) set_color_shad_post(&color2,j);

			if(nc>1)
			{
				gdouble m = 0;
				ab[0] = xyrc2.C[1]-xyrc1.C[1];
				ab[1] = -xyrc2.C[0]+xyrc1.C[0];
				m = sqrt(ab[0]*ab[0]+ab[1]*ab[1]);
				if(m !=0)
				{
					ab[0] /= m;
					ab[1] /= m;
				}
			}

/*			if (light_mode()) */
			if (TRUE) 
			{
				if(nc==2)
				{
					split[0] = (gint)(ab[0]*epaisseur/3);
					split[1] = (gint)(ab[1]*epaisseur/3);

					x1 = (gint)xyrc1.C[0]-split[0];
					x2 = (gint)xyrc2.C[0]-split[0];
					y1 = (gint)xyrc1.C[1]-split[1];
					y2 = (gint)xyrc2.C[1]-split[1];
					t=get_draw_line2_3d(epaisseur/3,i,j, x1,y1, x2,y2, color1,color2,TRUE);
                 			temp=g_strdup_printf("%s%s",temp,t);
                 			g_free(t);

					x1 = (gint)xyrc1.C[0]+split[0];
					x2 = (gint)xyrc2.C[0]+split[0];
					y1 = (gint)xyrc1.C[1]+split[1];
					y2 = (gint)xyrc2.C[1]+split[1];
					t=get_draw_line2_3d(epaisseur/3,i,j, x1,y1, x2,y2, color1,color2,FALSE);
                 			temp=g_strdup_printf("%s%s",temp,t);
                 			g_free(t);
				}
				else
				if(nc==3)
				{
					split[0] = (gint)(ab[0]*epaisseur/5);
					split[1] = (gint)(ab[1]*epaisseur/5);

					x1 = (gint)xyrc1.C[0]-2*split[0];
					x2 = (gint)xyrc2.C[0]-2*split[0];
					y1 = (gint)xyrc1.C[1]-2*split[1];
					y2 = (gint)xyrc2.C[1]-2*split[1];
					t=get_draw_line2_3d(epaisseur/5,i,j, x1,y1, x2,y2, color1,color2,TRUE);
                 			temp=g_strdup_printf("%s%s",temp,t);
                 			g_free(t);

					x1 = (gint)xyrc1.C[0];
					x2 = (gint)xyrc2.C[0];
					y1 = (gint)xyrc1.C[1];
					y2 = (gint)xyrc2.C[1];
					t=get_draw_line2_3d(epaisseur/5,i,j, x1,y1, x2,y2, color1,color2,TRUE);
                 			temp=g_strdup_printf("%s%s",temp,t);
                 			g_free(t);

					x1 = (gint)xyrc1.C[0]+2*split[0];
					x2 = (gint)xyrc2.C[0]+2*split[0];
					y1 = (gint)xyrc1.C[1]+2*split[1];
					y2 = (gint)xyrc2.C[1]+2*split[1];
					t=get_draw_line2_3d(epaisseur/5,i,j, x1,y1, x2,y2, color1,color2,FALSE);
                 			temp=g_strdup_printf("%s%s",temp,t);
                 			g_free(t);
				}
				else
				{
					x1 = (gint)xyrc1.C[0];
					x2 = (gint)xyrc2.C[0];
					y1 = (gint)xyrc1.C[1];
					y2 = (gint)xyrc2.C[1];
					t=get_draw_line2_3d(epaisseur,i,j, x1,y1, x2,y2, color1,color2,FALSE);
                 			temp=g_strdup_printf("%s%s",temp,t);
                 			g_free(t);
				}
			}
                	else
			{
				t=get_draw_line2(epaisseur,i,j, (gint)xyrc1.C[0],(gint)xyrc1.C[1], (gint)xyrc2.C[0],(gint)xyrc2.C[1], color1,color2,FALSE);
                 		temp=g_strdup_printf("%s%s",temp,t);
                 		g_free(t);
			}
		}
		else
		{
			if(hbond_connections(i,j))
			{
				k =get_num_min_rayonIJ(i,j);
				xyrc2= get_prop_center(j);
                		if(k==i) epaisseur = (gint) (xyrc1.C[2]*factorstick);
                		else epaisseur = (gint) (xyrc2.C[2]*factorstick);
				if (pers_mode()) epaisseur =(gint)(geometry[k].Coefpers*epaisseur);

				color2 = xyrc2.P;  
				epaisseur /= 5;
				if(epaisseur<2) epaisseur = 2;
				t = get_draw_line2_hbond(epaisseur,i,j, (gint)xyrc1.C[0],(gint)xyrc1.C[1], (gint)xyrc2.C[0],(gint)xyrc2.C[1], color1,color2);
                 		temp=g_strdup_printf("%s%s",temp,t);
                 		g_free(t);
			}
		}
    	if (label_option() != LABELNO) 
        {
         	t=get_draw_label(5,i,(gint)xyrc1.C[0],(gint)xyrc1.C[1]);
                temp=g_strdup_printf("%s%s",temp,t);
                g_free(t);
        }
    	if(Ddef && dipole_mode())
		for(j = 0;j<NDIVDIPOLE;j++)
			if(Ndipole[j]==(gint)i)
			{
	 			t = dessine_dipole_post(j);
                		temp=g_strdup_printf("%s%s",temp,t);
                		g_free(t);
			}
	}
        i=Natoms-1;
	xyrc1= get_prop_center(i);
	color1 = xyrc1.P;  
		if (shad_mode()) 
		 set_color_shad_post(&color1,i);
        rayon =(gushort)(xyrc1.C[2]*factorball);
			if (pers_mode()) 
               	rayon =(gushort)(geometry[i].Coefpers*xyrc1.C[2]*factorball);
/*	if (light_mode()) */
	if (TRUE) 
	t=get_draw_cercle_3d(xyrc1.C[0],xyrc1.C[1],rayon,color1);
        else
	t=get_draw_cercle(xyrc1.C[0],xyrc1.C[1],rayon,color1);
        temp=g_strdup_printf("%s%s",temp,t);
        g_free(t);
   
	if (label_option() != LABELNO) 
        {
         	t=get_draw_label(5,i,(gint)xyrc1.C[0],(gint)xyrc1.C[1]);
                temp=g_strdup_printf("%s%s",temp,t);
                g_free(t);
        }
    	if(Ddef && dipole_mode())
		for(j = 0;j<NDIVDIPOLE;j++)
			if(Ndipole[j]==(gint)i)
			{
	 			t = dessine_dipole_post(j);
                		temp=g_strdup_printf("%s%s",temp,t);
                		g_free(t);
			}

	return temp;	
	
}
/********************************************************************************/
gchar *dessine_stick_post()
{	
	guint i;
	guint j;
	guint k;
	gint epaisseur;
        gushort rayon;
	PColor color1;
	PColor color2;
	XYRC xyrc1;
	XYRC xyrc2;
        gchar *temp;
        gchar *t;
	gint split[2] = {0,0};
	gdouble ab[] = {0,0};
	gint x1, x2, y1,y2;

        temp=g_strdup("\n");

	for(i=0;i<Natoms-1;i++)
	{
		xyrc1= get_prop_center(i);
                rayon =(gushort)(xyrc1.C[2]/4*factorball);
		if (pers_mode()) 
                	rayon =(gushort)(geometry[i].Coefpers*xyrc1.C[2]*factorball);

		color1 = xyrc1.P;  
		if (shad_mode()) 				
			 set_color_shad_post(&color1,i);
		for(j=i+1;j<Natoms;j++)
                if( get_connection_type(i,j)>0)
		{
			gint nc = get_connection_type(i,j);
			xyrc2= get_prop_center(j);
			k =get_num_min_rayonIJ(i,j);

                	if(k==i) epaisseur = (gint) (xyrc1.C[2]/4*factorstick);
                	else epaisseur = (gint) (xyrc2.C[2]/4*factorstick);
                 
			if (pers_mode()) 				
                	epaisseur =(gint)(geometry[k].Coefpers*epaisseur);

			color2 = xyrc2.P;  
			if (shad_mode()) set_color_shad_post(&color2,j);

			if(nc>1)
			{
				gdouble m = 0;
				ab[0] = xyrc2.C[1]-xyrc1.C[1];
				ab[1] = -xyrc2.C[0]+xyrc1.C[0];
				m = sqrt(ab[0]*ab[0]+ab[1]*ab[1]);
				if(m !=0)
				{
					ab[0] /= m;
					ab[1] /= m;
				}
			}

/*			if (light_mode()) */
			if (TRUE) 
			{
				t=get_draw_line2_3d(epaisseur,i,j, (gint)xyrc1.C[0],(gint)xyrc1.C[1], (gint)xyrc2.C[0],(gint)xyrc2.C[1], color1,color2,FALSE);
                 		temp=g_strdup_printf("%s%s",temp,t);
                 		g_free(t);
				if(nc==2)
				{
					split[0] = (gint)(ab[0]*epaisseur*1.5);
					split[1] = (gint)(ab[1]*epaisseur*1.5);

					x1 = (gint)xyrc1.C[0]-split[0]-split[1];
					y1 = (gint)xyrc1.C[1]-split[1]+split[0];
					x2 = (gint)xyrc2.C[0]-split[0]+split[1];
					y2 = (gint)xyrc2.C[1]-split[1]-split[0];

					t=get_draw_line2_3d(epaisseur/2,i,j, x1,y1,x2,y2, color1,color2,TRUE);
                 			temp=g_strdup_printf("%s%s",temp,t);
                 			g_free(t);
				}
				if(nc==3)
				{
					split[0] = (gint)(ab[0]*epaisseur*1.5);
					split[1] = (gint)(ab[1]*epaisseur*1.5);

					x1 = (gint)xyrc1.C[0]-split[0]-split[1];
					y1 = (gint)xyrc1.C[1]-split[1]+split[0];
					x2 = (gint)xyrc2.C[0]-split[0]+split[1];
					y2 = (gint)xyrc2.C[1]-split[1]-split[0];
					t=get_draw_line2_3d(epaisseur/2,i,j, x1,y1,x2,y2, color1,color2,TRUE);
                 			temp=g_strdup_printf("%s%s",temp,t);
                 			g_free(t);
					x1 = (gint)xyrc1.C[0]+split[0]-split[1];
					y1 = (gint)xyrc1.C[1]+split[1]+split[0];
					x2 = (gint)xyrc2.C[0]+split[0]+split[1];
					y2 = (gint)xyrc2.C[1]+split[1]-split[0];
					t=get_draw_line2_3d(epaisseur/2,i,j, x1,y1,x2,y2, color1,color2,TRUE);
                 			temp=g_strdup_printf("%s%s",temp,t);
                 			g_free(t);
				}
			}
                	else
			{
				t=get_draw_line2(epaisseur,i,j, (gint)xyrc1.C[0],(gint)xyrc1.C[1], (gint)xyrc2.C[0],(gint)xyrc2.C[1], color1,color2,FALSE);
                 		temp=g_strdup_printf("%s%s",temp,t);
                 		g_free(t);
			}
		}
		else
		{
			if(hbond_connections(i,j))
			{
				xyrc2= get_prop_center(j);
				k =get_num_min_rayonIJ(i,j);
                		if(k==i) epaisseur = (gint) (xyrc1.C[2]*factorstick);
                		else epaisseur = (gint) (xyrc2.C[2]*factorstick);
				if (pers_mode()) epaisseur =(gint)(geometry[k].Coefpers*epaisseur);

				color2 = xyrc2.P;  
				epaisseur /= 5;
				if(epaisseur<2) epaisseur = 2;
				t = get_draw_line2_hbond(epaisseur,i,j, (gint)xyrc1.C[0],(gint)xyrc1.C[1], (gint)xyrc2.C[0],(gint)xyrc2.C[1], color1,color2);
                 		temp=g_strdup_printf("%s%s",temp,t);
                 		g_free(t);
			}
		}

	if (label_option() != LABELNO) 
        {
         	t=get_draw_label(5,i,(gint)xyrc1.C[0],(gint)xyrc1.C[1]);
                temp=g_strdup_printf("%s%s",temp,t);
                g_free(t);
        }
    	if(Ddef && dipole_mode())
		for(j = 0;j<NDIVDIPOLE;j++)
			if(Ndipole[j]==(gint)i)
			{
	 			t = dessine_dipole_post(j);
                		temp=g_strdup_printf("%s%s",temp,t);
                		g_free(t);
			}
	}
        i=Natoms-1;
	xyrc1= get_prop_center(i);
    
	if (label_option() != LABELNO) 			
        {
         	t=get_draw_label(5,i,(gint)xyrc1.C[0],(gint)xyrc1.C[1]);
                temp=g_strdup_printf("%s%s",temp,t);
                g_free(t);
        }

	return temp;	
}
/********************************************************************************/
gchar *dessine_post()
{
     gchar *temp=" ";
     if(Natoms<1)
	return temp;
	if(stick_mode())
   		temp = dessine_stick_post();
         else 
   		temp = dessine_ball_post();
      return temp;
}
/********************************************************************************/
void save_postscript_file(GtkWidget *w,gpointer data)
{
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext;
  gchar *NomFichier;
  gchar *temp;
  FILE *fd=NULL;

 if(!ZoneDessin)
 {
   Message("Sorry I can not create postscript file \nbecause Geometry display windows is closed"," Error ",TRUE);
   return;
 }
 entryall=(GtkWidget **)data;
 entry=entryall[0];
 entrytext = gtk_entry_get_text(GTK_ENTRY(entry));

 NomFichier = g_strdup_printf("%s",entrytext);
 fd = FOpen(NomFichier, "w");
 if(fd!=NULL)
 {
  temp =get_first();
  fprintf(fd,"%s",temp);
  g_free(temp);
  temp=get_preferences();
  fprintf(fd,"%s",temp);
  g_free(temp);
/* if (light_mode()) */
  if (TRUE) 
  {
  	temp=get_doball_3d();
  	fprintf(fd,"%s",temp);
  	g_free(temp);
  	temp=get_dostick_3d();
  	fprintf(fd,"%s",temp);
  	g_free(temp);
  }
  else
  {
  	temp=get_doball();
  	fprintf(fd,"%s",temp);
  	g_free(temp);
  	temp=get_dostick();
  	fprintf(fd,"%s",temp);
  	g_free(temp);
  }
  /* hbond */
  if (TRUE) 
  {
  	temp=get_dostick_hbond();
  	fprintf(fd,"%s",temp);
  	g_free(temp);
  }
  temp=get_epilogue();
  fprintf(fd,"%s",temp);
  g_free(temp);
  temp=dessine_post();
  fprintf(fd,"%s",temp);
  g_free(temp);
  temp=get_end();
  fprintf(fd,"%s",temp);
  fclose(fd);
 }
}
/********************************************************************************/
void create_save_postscript(GtkWidget* Win)
{
  GtkWidget *fp;
  GtkWidget *frame;
  GtkWidget *vboxall;
  GtkWidget *vboxframe;
  GtkWidget *hbox;
  GtkWidget *button;
  GtkWidget **entry;
  gchar      *labelt = g_strdup(" File  : ");
  gchar      *liste;
  gchar      *titre=g_strdup("Save in postscript file");
  static gchar* patterns[] = {"*.ps *.eps","*.ps","*.eps","*",NULL};

  entry=g_malloc(2*sizeof(GtkWidget *));

  liste  = g_strdup_printf("%s%sgabedit.ps",get_last_directory(),G_DIR_SEPARATOR_S);
  /* Fenetre principale */
  fp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(fp),titre);
  gtk_window_set_position(GTK_WINDOW(fp),GTK_WIN_POS_CENTER);
  gtk_window_set_transient_for(GTK_WINDOW(fp),GTK_WINDOW(Fenetre));

  add_child(Win,fp,gtk_widget_destroy," Postscript ");

  g_signal_connect(G_OBJECT(fp),"delete_event",(GtkSignalFunc)delete_child,NULL);
  g_signal_connect(G_OBJECT(fp),"delete_event",(GtkSignalFunc)gtk_widget_destroy,NULL);

  gtk_container_set_border_width (GTK_CONTAINER (fp), 5);
  vboxall = create_vbox(fp);
  frame = gtk_frame_new ("Location&Name of file");
  g_object_ref (frame);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  gtk_container_add (GTK_CONTAINER (vboxall), frame);
  gtk_widget_show (frame);

  vboxframe = create_vbox(frame);

  hbox = create_hbox_browser(Win,vboxframe,labelt,liste,patterns);
  entry[0] = (GtkWidget*)(g_object_get_data(G_OBJECT(hbox),"Entry"));	

  /* buttons */
  hbox = create_hbox(vboxall);
  gtk_widget_realize(fp);

  button = create_button(fp,"Cancel");
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
  g_signal_connect_swapped(G_OBJECT(button),"clicked",(GtkSignalFunc)delete_child,GTK_OBJECT(fp));
  gtk_widget_show (button);

  button = create_button(fp,"OK");
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
  gtk_widget_show (button);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(save_postscript_file),(gpointer)entry);
 g_signal_connect_swapped(G_OBJECT(button),"clicked",(GtkSignalFunc)delete_child,GTK_OBJECT(fp));


  g_free(labelt);
  g_free(liste);
   
  gtk_widget_show_all(fp);
}
/********************************************************************************/
