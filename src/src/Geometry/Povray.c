/* Povray.c */
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
#include "../Utils/UtilsInterface.h"
#include "../Geometry/InterfaceGeom.h"
#include "../Utils/Utils.h"
#include "../Utils/PovrayUtils.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/Vector3d.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/Mesure.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Common/Windows.h"

#define STICKSIZE 0.2

typedef struct _RGB
{
	/* Red Green Blue */
 	gdouble Colors[3];
}RGB;

typedef struct _XYZRC
{
	/* X=C[0], Y=C[1], Z =C[2] Radius=C[3] */
 	gdouble C[4];
	/* RGB Colors */
	RGB P;
}XYZRC;

/********************************************************************************/
static XYZRC get_prop_center(gint Num)
{
        XYZRC PropCenter;

	PropCenter.C[0]=geometry[Num].X;
	PropCenter.C[1]=geometry[Num].Y;
	PropCenter.C[2]=geometry[Num].Z;
	PropCenter.C[3]=geometry[Num].Prop.radii;

	PropCenter.P.Colors[0]=(gdouble)(geometry[Num].Prop.color.red/65535.0);
	PropCenter.P.Colors[1]=(gdouble)(geometry[Num].Prop.color.green/65535.0);
	PropCenter.P.Colors[2]=(gdouble)(geometry[Num].Prop.color.blue/65535.0);

        return  PropCenter;
}
/********************************************************************************/
static XYZRC get_prop_dipole(gint i)
{
        XYZRC PropCenter;

	PropCenter.C[0]=dipole[i][0];
	PropCenter.C[1]=dipole[i][1];
	PropCenter.C[2]=dipole[i][2];
	PropCenter.C[3]=geometry[0].Prop.radii*factor/4*factorstick;

	if(i<NDIVDIPOLE-1)
	{
		PropCenter.P.Colors[0]=0;
		PropCenter.P.Colors[1]=0;
		PropCenter.P.Colors[2]=(gdouble)(50000.0/65535.0);
	}
	else
	{
		PropCenter.P.Colors[0]=(gdouble)(50000.0/65535.0);
		PropCenter.P.Colors[1]=0;
		PropCenter.P.Colors[2]=0;
	}

        return  PropCenter;
}
/********************************************************************************/
static gchar *get_cone_dipole()
{
     XYZRC C1 = get_prop_dipole(NDIVDIPOLE-NDIVDIPOLE/5);
     XYZRC C2 = get_prop_dipole(NDIVDIPOLE-1);
     gdouble ep = C1.C[3]*2;
     gchar* temp = g_strdup_printf(
		"cone\n"
		"{\n"
		"\t<%14.6f,%14.6f,%14.6f>,%14.6f\n"
		"\t<%14.6f,%14.6f,%14.6f>,0.0 \n"
		"\ttexture { finish { Dull } }\n"
		"\tpigment { rgb<%14.6f,%14.6f,%14.6f> }\n}\n",
		C1.C[0],C1.C[1],C1.C[2],ep,
		C2.C[0],C2.C[1],C2.C[2],
		C2.P.Colors[0],C2.P.Colors[1],C2.P.Colors[2]
		);
     return temp;
}
/********************************************************************************/
static gchar *get_ball(gint num, gfloat scale)
{
     gchar *temp;
     XYZRC Center = get_prop_center(num);
     temp = g_strdup_printf(
		"sphere\n"
		"{\n"
		"\t<%14.6f,%14.6f,%14.6f> %14.6f\n"
		"\ttexture { finish { Dull } }\n"
		"\tpigment { rgb<%14.6f,%14.6f,%14.6f> }\n}\n"
		,
		Center.C[0],Center.C[1],Center.C[2],Center.C[3]*factorball*scale,
		Center.P.Colors[0], Center.P.Colors[1], Center.P.Colors[2]
		);
     return temp;
}
/********************************************************************************/
static gchar *get_ball_for_stick(gint num, gfloat scale)
{
     gchar *temp;
     XYZRC Center = get_prop_center(num);
     temp = g_strdup_printf(
		"sphere\n"
		"{\n"
		"\t<%14.6f,%14.6f,%14.6f> %14.6f\n"
		"\ttexture { finish { Dull } }\n"
		"\tpigment { rgb<%14.6f,%14.6f,%14.6f> }\n}\n"
		,
		Center.C[0],Center.C[1],Center.C[2],STICKSIZE*scale,
		Center.P.Colors[0], Center.P.Colors[1], Center.P.Colors[2]
		);
     return temp;
}
/********************************************************************************/
static gfloat get_min(gint k)
{
     gfloat min;
     gint i=0;

     if(k==0)
     {
     	min = geometry[0].X;
     	for(i=1;i<(gint)Natoms;i++) if(min>geometry[i].X) min = geometry[i].X;
     }
     else
     {
     	if(k==1)
     	{
     		min = geometry[0].Y;
     		for(i=1;i<(gint)Natoms;i++) if(min>geometry[i].Y) min = geometry[i].Y;
     	}
     	else
     	{
     		min = geometry[0].Z;
     		for(i=1;i<(gint)Natoms;i++) if(min>geometry[i].Z) min = geometry[i].Z;
     	}
     }
     
     min -=10;
    return min;
}
/********************************************************************************/
static gchar *get_cylingre(gdouble C1[],gdouble C2[],gdouble Colors[],gdouble ep)
{
     gchar* temp = g_strdup_printf(
		"cylinder\n"
		"{\n"
		"\t<%14.6f,%14.6f,%14.6f>,\n"
		"\t<%14.6f,%14.6f,%14.6f> \n"
		"\t%14.6f\n"
		"\ttexture { finish { Dull } }\n"
		"\tpigment { rgb<%14.6f,%14.6f,%14.6f> }\n}\n",
		C1[0],C1[1],C1[2],
		C2[0],C2[1],C2[2],
		ep,
		Colors[0],Colors[1],Colors[2]
		);
	return temp;

}
/********************************************************************************/
static gchar *get_stick_dipole()
{
     gchar *temp;
     XYZRC Center1;
     XYZRC Center2;
     gdouble ep;

     Center1 = get_prop_dipole(0);
     Center2 = get_prop_dipole(NDIVDIPOLE-NDIVDIPOLE/5);
     ep = Center1.C[3];

 
      temp = get_cylingre(Center1.C,Center2.C,Center1.P.Colors,ep);
      return temp;
}
/********************************************************************************/
static gchar *get_one_stick_for_ball(gint i,gint j)
{
     gchar *temp;
     gchar *temp1;
     gchar *temp2;
     XYZRC Center1;
     XYZRC Center2;
     gint l;
     gint k;
     gdouble ep;
     gdouble poid1;
     gdouble poid2;
     gdouble poid;
     gdouble C[3];
     gint nc = get_connection_type(i,j);

     if(nc<1) return " ";

     Center1 = get_prop_center(i);
     Center2 = get_prop_center(j);
     k =get_num_min_rayonIJ(i,j);
 
     if(k==i) ep = Center1.C[3]*factorstick;
     else ep = Center2.C[3]*factorstick;

     if(stick_mode()) ep =STICKSIZE*factorstick;
     else ep/=2;

 
     poid1 = geometry[i].Prop.covalentRadii+geometry[i].Prop.radii;
     poid2 = geometry[j].Prop.covalentRadii+geometry[j].Prop.radii;
     poid = poid1 + poid2 ;

     if(nc==3)
     {
	gchar* t;
  	V3d vScal = {ep*0.5,ep*0.5,ep*0.5};
	gdouble C1[3];
	gdouble C2[3];
	V3d cros;
	V3d sub;
	V3d C0={0,0,0};
	gfloat C10[3];
	gfloat C20[3];
	gfloat CC1[3];
	gfloat CC2[3];
	for(l=0;l<3;l++) CC1[l] = Center1.C[l];
	for(l=0;l<3;l++) CC2[l] = Center2.C[l];
	v3d_sub(C0, CC1, C10);
	v3d_sub(C0, CC2, C20);
	v3d_cross(C10, C20, cros);
	v3d_sub(CC1, CC2, sub);
	v3d_cross(cros, sub, vScal);
	if(v3d_dot(vScal,vScal)!=0)
	{
		v3d_normal(vScal);
		v3d_scale(vScal, ep*0.5);
	}
	for(l=0;l<3;l++) C1[l] = Center1.C[l]-vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]-vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_cylingre(C,C2,Center2.P.Colors,ep/3);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);

	for(l=0;l<3;l++) C1[l] = Center1.C[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_cylingre(C,C2,Center2.P.Colors,ep/3);
	t = temp;
      	temp = g_strdup_printf("%s%s%s",t,temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
      	g_free(t);

	for(l=0;l<3;l++) C1[l] = Center1.C[l]+vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]+vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_cylingre(C,C2,Center2.P.Colors,ep/3);
	t = temp;
      	temp = g_strdup_printf("%s%s%s",t,temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
      	g_free(t);

     }
     else
     if(nc==2)
     {
	gchar* t;
  	V3d vScal = {ep*0.5,ep*0.5,ep*0.5};
	gdouble C1[3];
	gdouble C2[3];
	V3d cros;
	V3d sub;
	V3d C0={0,0,0};
	gfloat C10[3];
	gfloat C20[3];
	gfloat CC1[3];
	gfloat CC2[3];
	for(l=0;l<3;l++) CC1[l] = Center1.C[l];
	for(l=0;l<3;l++) CC2[l] = Center2.C[l];
	v3d_sub(C0, CC1, C10);
	v3d_sub(C0, CC2, C20);
	v3d_cross(C10, C20, cros);
	v3d_sub(CC1, CC2, sub);
	v3d_cross(cros, sub, vScal);
	if(v3d_dot(vScal,vScal)!=0)
	{
		v3d_normal(vScal);
		v3d_scale(vScal, ep*0.5);
	}
	for(l=0;l<3;l++) C1[l] = Center1.C[l]-vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]-vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_cylingre(C,C2,Center2.P.Colors,ep/3);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);

	for(l=0;l<3;l++) C1[l] = Center1.C[l]+vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]+vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_cylingre(C,C2,Center2.P.Colors,ep/3);
	t = temp;
      	temp = g_strdup_printf("%s%s%s",t,temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
      	g_free(t);

     }
     else
     {
     	for(l=0;l<3;l++) C[l] =(Center1.C[l]*poid2+Center2.C[l]*poid1)/poid;
      	temp1 = get_cylingre(Center1.C,C,Center1.P.Colors,ep);
      	temp2 = get_cylingre(C,Center2.C,Center2.P.Colors,ep);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
     }

      return temp;
}
/********************************************************************************/
static gchar *get_one_stick(gint i,gint j)
{
     gchar *temp;
     gchar *temp1;
     gchar *temp2;
     XYZRC Center1;
     XYZRC Center2;
     gint l;
     gint k;
     gdouble ep;
     gdouble poid1;
     gdouble poid2;
     gdouble poid;
     gdouble C[3];
     gint nc = get_connection_type(i,j);

     if(nc<1) return " ";

     Center1 = get_prop_center(i);
     Center2 = get_prop_center(j);
     k =get_num_min_rayonIJ(i,j);
 
     if(k==i) ep = Center1.C[3]*factorstick;
     else ep = Center2.C[3]*factorstick;

     if(stick_mode()) ep =STICKSIZE*factorstick;
     else ep/=2;

 
     poid1 = geometry[i].Prop.covalentRadii+geometry[i].Prop.radii;
     poid2 = geometry[j].Prop.covalentRadii+geometry[j].Prop.radii;
     poid = poid1 + poid2 ;

     if(nc==3)
     {
	gchar* t;
  	V3d vScal = {ep,ep,ep};
	gdouble C1[3];
	gdouble C2[3];
	gfloat C12[3];
	V3d cros;
	V3d sub;
	V3d C0={0,0,0};
	gfloat C10[3];
	gfloat C20[3];
	gfloat CC1[3];
	gfloat CC2[3];
	for(l=0;l<3;l++) CC1[l] = Center1.C[l];
	for(l=0;l<3;l++) CC2[l] = Center2.C[l];
	v3d_sub(C0, CC1, C10);
	v3d_sub(C0, CC2, C20);
	v3d_cross(C10, C20, cros);
	v3d_sub(CC1, CC2, sub);
	v3d_cross(cros, sub, vScal);
	if(v3d_dot(vScal,vScal)!=0)
	{
		v3d_normal(vScal);
		v3d_scale(vScal, ep*2);
	}
	for(l=0;l<3;l++) C1[l] = Center1.C[l]-vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]-vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;

	v3d_sub(CC1, CC2, C12);
	if(v3d_dot(C12,C12)!=0)
	{
		v3d_normal(C12);
	}
	for(l=0;l<3;l++) C1[l] -= C12[l]*ep;
	for(l=0;l<3;l++) C2[l] += C12[l]*ep;

      	temp1 = get_cylingre(C1,C,Center1.P.Colors,ep/2);
      	temp2 = get_cylingre(C,C2,Center2.P.Colors,ep/2);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);


	for(l=0;l<3;l++) C1[l] = Center1.C[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_cylingre(C1,C,Center1.P.Colors,ep);
      	temp2 = get_cylingre(C,C2,Center2.P.Colors,ep);
	t = temp;
      	temp = g_strdup_printf("%s%s%s",t,temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
      	g_free(t);

	for(l=0;l<3;l++) C1[l] = Center1.C[l]+vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]+vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;

	for(l=0;l<3;l++) C1[l] -= C12[l]*ep;
	for(l=0;l<3;l++) C2[l] += C12[l]*ep;

      	temp1 = get_cylingre(C1,C,Center1.P.Colors,ep/2);
      	temp2 = get_cylingre(C,C2,Center2.P.Colors,ep/2);
	t = temp;
      	temp = g_strdup_printf("%s%s%s",t,temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
      	g_free(t);

     }
     else
     if(nc==2)
     {
	gchar* t;
  	V3d vScal = {ep,ep,ep};
	gdouble C1[3];
	gdouble C2[3];
	V3d cros;
	V3d sub;
	V3d C0={0,0,0};
	gfloat C10[3];
	gfloat C20[3];
	gfloat CC1[3];
	gfloat CC2[3];
	gfloat C12[3];
	for(l=0;l<3;l++) CC1[l] = Center1.C[l];
	for(l=0;l<3;l++) CC2[l] = Center2.C[l];
	v3d_sub(C0, CC1, C10);
	v3d_sub(C0, CC2, C20);
	v3d_cross(C10, C20, cros);
	v3d_sub(CC1, CC2, sub);
	v3d_cross(cros, sub, vScal);
	if(v3d_dot(vScal,vScal)!=0)
	{
		v3d_normal(vScal);
		v3d_scale(vScal, ep*2);
	}
	for(l=0;l<3;l++) C1[l] = Center1.C[l]-vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]-vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;

	v3d_sub(CC1, CC2, C12);
	if(v3d_dot(C12,C12)!=0)
	{
		v3d_normal(C12);
	}
	for(l=0;l<3;l++) C1[l] -= C12[l]*ep;
	for(l=0;l<3;l++) C2[l] += C12[l]*ep;

      	temp1 = get_cylingre(C1,C,Center1.P.Colors,ep/2);
      	temp2 = get_cylingre(C,C2,Center2.P.Colors,ep/2);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);

	for(l=0;l<3;l++) C1[l] = Center1.C[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_cylingre(C1,C,Center1.P.Colors,ep);
      	temp2 = get_cylingre(C,C2,Center2.P.Colors,ep);
	t = temp;
      	temp = g_strdup_printf("%s%s%s",t,temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
      	g_free(t);

     }
     else
     {
     	for(l=0;l<3;l++) C[l] =(Center1.C[l]*poid2+Center2.C[l]*poid1)/poid;
      	temp1 = get_cylingre(Center1.C,C,Center1.P.Colors,ep);
      	temp2 = get_cylingre(C,Center2.C,Center2.P.Colors,ep);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
     }

      return temp;
}
/********************************************************************************/
static gchar *get_one_hbond(gint i,gint j)
{
     gchar *temp;
     XYZRC Center1;
     XYZRC Center2;
     gint l;
     gint k;
     gdouble ep;
     gdouble poid1;
     gdouble poid2;
     gdouble poid;
     gint n = 10;
     gdouble A[3];
     gdouble B[3];
     gdouble K[3];
     gchar *dump;
     gchar *temp1;
     gint ibreak;

     if( !hbond_connections(i,j)) return " ";

     Center1 = get_prop_center(i);
     Center2 = get_prop_center(j);
     k =get_num_min_rayonIJ(i,j);
 
     if(k==i) ep = Center1.C[3]*factorstick;
     else ep = Center2.C[3]*factorstick;
     if(stick_mode()) ep /=4;
     else ep /=2;

 
     poid1 = geometry[i].Prop.covalentRadii+geometry[i].Prop.radii;
     poid2 = geometry[j].Prop.covalentRadii+geometry[j].Prop.radii;
     poid = poid1 + poid2 ;

     ibreak = (gint)(poid1*n/poid);

     for(l=0;l<3;l++) K[l] =(Center2.C[l]-Center1.C[l])/(n*5/4);
     for(l=0;l<3;l++) A[l] =Center1.C[l];
     temp = NULL;
     for(i=0;i<n;i++)
     {
     	for(l=0;l<3;l++) B[l] = A[l] + K[l];
	if(i<=ibreak)
		temp1 =  get_cylingre(A,B,Center1.P.Colors,ep/2);
	else
		temp1 =  get_cylingre(A,B,Center2.P.Colors,ep/2);
	dump = temp;
	if(dump)
	{
     		temp = g_strdup_printf("%s%s",dump,temp1);
		g_free(dump);
	}
	else temp = g_strdup_printf("%s",temp1);
	g_free(temp1);
	temp1 = NULL;
     	for(l=0;l<3;l++) A[l] = B[l]+K[l]/4;
     }

     if(temp1) g_free(temp1);
     return temp;
}
/********************************************************************************/
static gchar *get_epilogue()
{
     gchar *temp;
     temp = g_strdup(
	 "// ****This file was generated by Gabedit ****\n\n"
	 "#include \"colors.inc\"\n"
	 "#include \"textures.inc\"\n"
	 "#include \"shapes.inc\"\n"
	 "#include \"stones1.inc\"\n\n"
	);
     return temp;
}
/********************************************************************************/
static gchar *get_camera()
{
	gchar *temp;
	gfloat max;
	gfloat min;
	gint i=0;
	gfloat f = 5;
	gfloat position = 10;

	max = geometry[0].Z;
	min = geometry[0].Z;
	for(i=1;i<(gint)Natoms;i++)
	{
		if(max<geometry[i].Z) max = geometry[i].Z;
		if(min>geometry[i].Z) min = geometry[i].Z;
		if(max<geometry[i].Y) max = geometry[i].Y;
		if(min>geometry[i].Y) min = geometry[i].Y;
		if(max<geometry[i].X) max = geometry[i].X;
		if(min>geometry[i].X) min = geometry[i].X;
	}
	if(fabs(max-min)>1.e-6)
	{
		position = 2*fabs(max-min);
		f = position/2;
	}
     
	temp = g_strdup_printf(
	 "// CAMERA\n\n"
	 "camera\n"
	 "{\n"
	 "\tright      < 0.000000, 1.000000, 0.000000 >\n"
	  "\tup        < 0.000000, 1.000000, 0.000000 >\n"
	  "\tdirection < 0.000000, 0.000000, 1.000000 >\n"
	  "\tlocation  < 0.000000, 0.00000, %14.8f >\n"
	  "\tlook_at   < 0.000000, 0.00000, %14.8f >\n"
	  "}\n",
	   position,f
	);
     return temp;
}
/********************************************************************************/
static gchar *get_light_source(gchar* title,gchar* color,gfloat x,gfloat y, gfloat z)
{
	gchar *temp;
     	temp = g_strdup_printf("%s%s\t<%10.6f,%10.6f,%10.6f>\n\tcolor %s\n}\n",
				title,
         			"light_source\n"
         			"{\n",
				 x,y,z,color);
	return temp;           
}
/********************************************************************************/
static gchar *get_light_sources()
{
     gchar *temp;
     gfloat Ymax;
     gint i=0;
/* calcul of Ymax*/

     Ymax = geometry[0].Y;
     for(i=1;i<(gint)Natoms;i++)
		if(Ymax<geometry[i].Y)
			Ymax = geometry[i].Y;
     
      Ymax +=10;
      temp = get_light_source("// LIGHT 1\n","0.6*White",Ymax,Ymax,Ymax);
     return temp;
}
/********************************************************************************/
static gchar *get_atoms(gdouble scal)
{
     	gchar *temp=NULL;
     	gchar *tempold=NULL;
     	gchar *t=NULL;
     	gint i=0;
     	temp = g_strdup( "// ATOMS \n");
	for(i=0;i<(gint)Natoms;i++)
	{
		tempold = temp;
		t =get_ball(i,scal);
		if(tempold)
		{
			temp = g_strdup_printf("%s%s",tempold,t);
			g_free(tempold);
		}
		else
			temp = g_strdup_printf("%s",t);
		if(t)
		  g_free(t);
	}

     return temp;
}
/********************************************************************************/
static gchar *get_atoms_for_stick(gdouble scal)
{
     	gchar *temp=NULL;
     	gchar *tempold=NULL;
     	gchar *t=NULL;
     	gint i=0;
     	temp = g_strdup( "// ATOMS \n");
	for(i=0;i<(gint)Natoms;i++)
	{
		tempold = temp;
		t =get_ball_for_stick(i,scal);
		if(tempold)
		{
			temp = g_strdup_printf("%s%s",tempold,t);
			g_free(tempold);
		}
		else
			temp = g_strdup_printf("%s",t);
		if(t)
		  g_free(t);
	}

     return temp;
}
/********************************************************************************/
static gchar *get_bonds(gboolean ballstick)
{
     gchar *temp = NULL;
     gint i,j;
     gchar* t;
     gchar* tempold;
     gboolean* Ok = NULL;
     if(Natoms>0) Ok = g_malloc(Natoms*sizeof(gboolean));
     for(i=0;i<(gint)Natoms;i++) Ok[i] = FALSE;

     temp = g_strdup( "// BONDS \n");
     for(i=0;i<(gint)(Natoms-1);i++)
     {
	for(j=i+1;j<(gint)Natoms;j++)
		if(get_connection_type(i,j)>0)
	 	{
			Ok[i] = TRUE;
			Ok[j] = TRUE;
			tempold = temp;
			if(ballstick) t =get_one_stick_for_ball(i,j);
			else t =get_one_stick(i,j);
			if(tempold)
                	{
                        	temp = g_strdup_printf("%s%s",tempold,t);
                        	g_free(tempold);
                	}
                	else temp = g_strdup_printf("%s",t); 
	 	}
     		else
		{
			if(hbond_connections(i,j))
			{
				tempold = temp;
				t =get_one_hbond(i,j);
				if(tempold)
                		{
                        		temp = g_strdup_printf("%s%s",tempold,t);
                        		g_free(tempold);
                		}
                		else temp = g_strdup_printf("%s",t); 
			}
		}
     }
     for(i=0;i<(gint)(Natoms-1);i++)
	if(!Ok[i])
	{
		tempold = temp;
		t =get_ball(i, 0.5);
		if(tempold)
		{
			temp = g_strdup_printf("%s%s",tempold,t);
			g_free(tempold);
		}
		else
			temp = g_strdup_printf("%s",t);
		if(t)
		  g_free(t);
	}
     return temp;
}
/********************************************************************************/
static gchar *get_dipole()
{
	gchar* t1;
	gchar* t2;
	gchar* t = NULL;

     	t = g_strdup( "// Dipole \n");
	t1 = t;
	t2 = get_stick_dipole();
	t = g_strdup_printf("%s%s",t1,t2);
	g_free(t1);
	g_free(t2);
	t1 = t;
	t2 = get_cone_dipole();
	t = g_strdup_printf("%s%s",t1,t2);
	g_free(t1);
	g_free(t2);
	return t;
}
	
/********************************************************************************/
static void save_povray_file(GtkWidget *w,gpointer data)
{
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext;
  gchar *NomFichier;
  gchar *temp;
  gfloat xmin;
  gfloat ymin;
  gfloat zmin;
  FILE *fd=NULL;

 if(!ZoneDessin)
 {
   Message("Sorry I can not create pov-ray file \nbecause Geometry display windows is closed"," Error ",TRUE);
   return;
 }
 entryall=(GtkWidget **)data;
 entry=entryall[0];
 entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
 NomFichier = g_strdup_printf("%s.pov",get_suffix_name_file(entrytext));
 fd = FOpen(NomFichier, "w");
 if(fd)
 {
	temp =get_epilogue();
	fprintf(fd,"%s",temp);
	g_free(temp);
	temp =get_camera();
	fprintf(fd,"%s",temp);
	g_free(temp);
	temp = get_light_sources();
	fprintf(fd,"%s",temp);
	g_free(temp);

	xmin = get_min(0);
	ymin = get_min(1);
	zmin = get_min(2);
	temp = get_pov_background(xmin, ymin,zmin);
	fprintf(fd,"%s",temp);
	g_free(temp);

     	if(Natoms<1)
	{
		fclose(fd);
		return;
	}
	if( !stick_mode())
	{
		temp = get_atoms(1.0); 
		fprintf(fd,"%s",temp);
		g_free(temp);
	}
	else
	{
		temp = get_atoms_for_stick(1.0); 
		fprintf(fd,"%s",temp);
		g_free(temp);
	}
	temp = get_bonds( !stick_mode()); 
	fprintf(fd,"%s",temp);
	g_free(temp);
        if(Ddef && dipole_mode())
	{
		temp = get_dipole();
		fprintf(fd,"%s",temp);
		g_free(temp);
	}
	
 	fclose(fd);
 }
}
/********************************************************************************/
void create_save_povray(GtkWidget* Win)
{
  GtkWidget *fp;
  GtkWidget *frame;
  GtkWidget *vboxall;
  GtkWidget *vboxframe;
  GtkWidget *hbox;
  GtkWidget *button;
  GtkWidget **entry;
  gchar      *labelt = g_strdup(" File  : ");
  gchar      *liste=g_strdup("gabedit.pov");
  gchar      *titre=g_strdup("Create a pov-ray file");
  static gchar* patterns[] = {"*.pov","*",NULL};
  entry=g_malloc(2*sizeof(GtkWidget *));

  liste  = g_strdup_printf("%s%sgabedit.pov",get_last_directory(),G_DIR_SEPARATOR_S);
  /* Fenetre principale */
  fp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(fp),titre);
  gtk_window_set_position(GTK_WINDOW(fp),GTK_WIN_POS_CENTER);
  gtk_window_set_transient_for(GTK_WINDOW(fp),GTK_WINDOW(Fenetre));

  add_child(Win,fp,gtk_widget_destroy," Povray ");

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
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(save_povray_file),(gpointer)entry);
  g_signal_connect_swapped(G_OBJECT(button),"clicked",(GtkSignalFunc)delete_child,GTK_OBJECT(fp));


  g_free(labelt);
  g_free(liste);
   
  gtk_widget_show_all(fp);
}
