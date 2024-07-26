/* PovrayGL.c */
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
#include "GlobalOrb.h"
#include "../Geometry/GeomGlobal.h"
#include "../Files/FileChooser.h"
#include "../Utils/Vector3d.h"
#include "../Utils/Transformation.h"
#include "../Utils/Utils.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Constantes.h"
#include "../Utils/HydrogenBond.h"
#include "../Utils/PovrayUtils.h"
#include "../OpenGL/GLArea.h"
#include "../OpenGL/GeomDraw.h"
#include "../OpenGL/TriangleDraw.h"
#include "../OpenGL/AxisGL.h"
#include "../OpenGL/PrincipalAxisGL.h"
#include "../OpenGL/ColorMap.h"
#include "../OpenGL/BondsOrb.h"
#include "../OpenGL/RingsOrb.h"

#include <unistd.h>

#define STICKSIZE 0.2
#define STICKSIZEBALL 0.7


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
static XYZRC get_prop_center(gint Num, gdouble scale)
{
        XYZRC PropCenter;
	gint i;

	for(i=0;i<3;i++) PropCenter.C[i]=GeomOrb[Num].C[i];
	if(TypeGeom==GABEDIT_TYPEGEOM_SPACE)
		PropCenter.C[3]=GeomOrb[Num].Prop.vanDerWaalsRadii*scale;
	else
		PropCenter.C[3]=GeomOrb[Num].Prop.radii*scale;

	PropCenter.P.Colors[0]=(gdouble)(GeomOrb[Num].Prop.color.red/65535.0);
	PropCenter.P.Colors[1]=(gdouble)(GeomOrb[Num].Prop.color.green/65535.0);
	PropCenter.P.Colors[2]=(gdouble)(GeomOrb[Num].Prop.color.blue/65535.0);

        return  PropCenter;
}
/********************************************************************************/
static XYZRC get_base_dipole()
{
        XYZRC PropCenter;
	gint i;

	for(i=0;i<3;i++) PropCenter.C[i]= 0.0;
	PropCenter.C[3] = Dipole.radius;
	for(i=0;i<3;i++) PropCenter.P.Colors[i]=Dipole.color[i]/65535.0;

        return  PropCenter;
}
/********************************************************************************/
static XYZRC get_tete_dipole()
{
        XYZRC PropCenter;
	gint i;
	static GLfloat f = 2;

	for(i=0;i<3;i++) PropCenter.C[i]= f*Dipole.Value[i];
	PropCenter.C[3] = Dipole.radius;
	for(i=0;i<3;i++) PropCenter.P.Colors[i]=Dipole.color[i]/65535.0;

        return  PropCenter;
}
/********************************************************************************/
static gfloat get_min(gint k)
{
     gfloat min;
     gint i=0;
     min = GeomOrb[0].C[k];
     for(i=1;i<(gint)Ncenters;i++)
		if(min>GeomOrb[i].C[k])
			min = GeomOrb[i].C[k];
     
     min -=20;
     return min;
}
/********************************************************************************/
static gint get_num_min_rayonIJ(gint i, gint j)
{
	if(GeomOrb[i].Prop.radii<GeomOrb[j].Prop.radii) return i;
	return j;
}
/********************************************************************************/
static gchar *get_pov_dipole()
{
     XYZRC C1 = get_base_dipole();
     XYZRC C2 = get_tete_dipole();
     gdouble ep = C1.C[3]/2;

     gchar* temp = g_strdup_printf(
		"// Dipole\n"
		"#declare CDipole1 = <%f, %f, %f>;\n"
		"#declare CDipole2 = <%f, %f, %f>;\n"
		"#declare ColDipole1 = <%f, %f, %f>;\n"
		"#declare ColDipole2 = <%f, %f, %f>;\n"
		"object\n"
		"{\n"
		"\tarrow (CDipole1, CDipole2, %f, ColDipole1, ColDipole2)\n"
		"}\n",
		C1.C[0],C1.C[1],C1.C[2],
		C2.C[0],C2.C[1],C2.C[2],
		C1.P.Colors[0],C1.P.Colors[1],C1.P.Colors[2],
		C2.P.Colors[0]/2,C2.P.Colors[1]/2,C2.P.Colors[2]/2,
		ep
		);
     return temp;
}
/********************************************************************************/
static gchar *get_pov_xyz_axes()
{
	gboolean show;
	gboolean negative;
	gfloat origin[3];
	gfloat originX[3];
	gfloat originY[3];
	gfloat originZ[3];
	gfloat radius;
	gfloat scale;
	gfloat xColor[3];
	gfloat yColor[3];
	gfloat zColor[3];
	gfloat vectorX[3]  = {1,0,0};
	gfloat vectorY[3]  = {0,1,0};
	gfloat vectorZ[3]  = {0,0,1};
	gint i;
	gchar* temp; 

	getAxisProperties(&show, &negative, origin, &radius, &scale,  xColor, yColor, zColor);
	if(!show) return NULL;

	for(i=0;i<3;i++) vectorX[i] *= scale;
	for(i=0;i<3;i++) vectorY[i] *= scale;
	for(i=0;i<3;i++) vectorZ[i] *= scale;

	for(i=0;i<3;i++) originX[i] = origin[i];
	for(i=0;i<3;i++) originY[i] = origin[i];
	for(i=0;i<3;i++) originZ[i] = origin[i];
	if(negative)
	{
		for(i=0;i<3;i++) originX[i] -=vectorX[i];
		for(i=0;i<3;i++) originY[i] -=vectorY[i];
		for(i=0;i<3;i++) originZ[i] -=vectorZ[i];
	}

	temp = g_strdup_printf(
		"// XYZ Axes\n"
		"#declare COriginAxes1 = <%f, %f, %f>;\n"
		"#declare COriginAxes2 = <%f, %f, %f>;\n"
		"#declare COriginAxes3 = <%f, %f, %f>;\n"
		"#declare CTeteAxes1 = <%f, %f, %f>;\n"
		"#declare CTeteAxes2 = <%f, %f, %f>;\n"
		"#declare CTeteAxes3 = <%f, %f, %f>;\n"
		"#declare ColorAxes1 = <%f, %f, %f>;\n"
		"#declare ColorConeAxes1 = <%f, %f, %f>;\n"
		"#declare ColorAxes2 = <%f, %f, %f>;\n"
		"#declare ColorConeAxes2 = <%f, %f, %f>;\n"
		"#declare ColorAxes3 = <%f, %f, %f>;\n"
		"#declare ColorConeAxes3 = <%f, %f, %f>;\n"
		"#declare AxesRadius = %f;\n"
		"object\n"
		"{\n"
		"\tarrow (COriginAxes1, CTeteAxes1, AxesRadius, ColorAxes1, ColorConeAxes1)\n"
		"}\n"
		"object\n"
		"{\n"
		"\tarrow (COriginAxes2, CTeteAxes2, AxesRadius, ColorAxes2, ColorConeAxes2)\n"
		"}\n"
		"object\n"
		"{\n"
		"\tarrow (COriginAxes3, CTeteAxes3, AxesRadius, ColorAxes3, ColorConeAxes3)\n"
		"}\n",
		originX[0],originX[1],originX[2],
		originY[0],originY[1],originY[2],
		originZ[0],originZ[1],originZ[2],
		vectorX[0],vectorX[1],vectorX[2],
		vectorY[0],vectorY[1],vectorY[2],
		vectorZ[0],vectorZ[1],vectorZ[2],
		xColor[0],xColor[1],xColor[2],
		xColor[0]/2,xColor[1]/2,xColor[2]/2,
		yColor[0],yColor[1],yColor[2],
		yColor[0]/2,yColor[1]/2,yColor[2]/2,
		zColor[0],zColor[1],zColor[2],
		zColor[0]/2,zColor[1]/2,zColor[2]/2,
		radius
		);
     return temp;
}
/********************************************************************************/
static gchar *get_pov_principal_axes()
{
	gboolean show;
	gboolean negative;
	gboolean def;
	gfloat origin[3];
	gfloat firstOrigin[3];
	gfloat secondOrigin[3];
	gfloat thirdOrigin[3];
	gfloat radius;
	gfloat scale;
	gfloat firstColor[3];
	gfloat secondColor[3];
	gfloat thirdColor[3];
	gfloat firstVector[3]  = {1,0,0};
	gfloat secondVector[3]  = {0,1,0};
	gfloat thirdVector[3]  = {0,0,1};
	gint i;
	gchar* temp = NULL;

	getPrincipalAxisProperties(&show,&negative, &def, origin, &radius, &scale,
		firstVector,secondVector,thirdVector,
		firstColor,secondColor, thirdColor);
	if(!def || !show) return NULL;

	for(i=0;i<3;i++) firstVector[i] *= scale;
	for(i=0;i<3;i++) secondVector[i] *= scale;
	for(i=0;i<3;i++) thirdVector[i] *= scale;

	for(i=0;i<3;i++) firstOrigin[i] = origin[i];
	for(i=0;i<3;i++) secondOrigin[i] = origin[i];
	for(i=0;i<3;i++) thirdOrigin[i] = origin[i];
	if(negative)
	{
		for(i=0;i<3;i++) firstOrigin[i] -=firstVector[i];
		for(i=0;i<3;i++) secondOrigin[i] -=secondVector[i];
		for(i=0;i<3;i++) thirdOrigin[i] -=thirdVector[i];
	}

	temp = g_strdup_printf(
		"// Principal Axes\n"
		"#declare COriginPrincipalAxe1 = <%f, %f, %f>;\n"
		"#declare COriginPrincipalAxe2 = <%f, %f, %f>;\n"
		"#declare COriginPrincipalAxe3 = <%f, %f, %f>;\n"
		"#declare CTetePrincipalAxe1 = <%f, %f, %f>;\n"
		"#declare CTetePrincipalAxe2 = <%f, %f, %f>;\n"
		"#declare CTetePrincipalAxe3 = <%f, %f, %f>;\n"
		"#declare ColorPrincipalAxe1 = <%f, %f, %f>;\n"
		"#declare ColorConePrincipalAxe1 = <%f, %f, %f>;\n"
		"#declare ColorPrincipalAxe2 = <%f, %f, %f>;\n"
		"#declare ColorConePrincipalAxe2 = <%f, %f, %f>;\n"
		"#declare ColorPrincipalAxe3 = <%f, %f, %f>;\n"
		"#declare ColorConePrincipalAxe3 = <%f, %f, %f>;\n"
		"#declare PrincipalAxeRadius = %f;\n"
		"object\n"
		"{\n"
		"\tarrow (COriginPrincipalAxe1, CTetePrincipalAxe1, PrincipalAxeRadius, ColorPrincipalAxe1, ColorConePrincipalAxe1)\n"
		"}\n"
		"object\n"
		"{\n"
		"\tarrow (COriginPrincipalAxe2, CTetePrincipalAxe2, PrincipalAxeRadius, ColorPrincipalAxe2, ColorConePrincipalAxe2)\n"
		"}\n"
		"object\n"
		"{\n"
		"\tarrow (COriginPrincipalAxe3, CTetePrincipalAxe3, PrincipalAxeRadius, ColorPrincipalAxe3, ColorConePrincipalAxe3)\n"
		"}\n",
		firstOrigin[0],firstOrigin[1],firstOrigin[2],
		secondOrigin[0],secondOrigin[1],secondOrigin[2],
		thirdOrigin[0],thirdOrigin[1],thirdOrigin[2],
		firstVector[0],firstVector[1],firstVector[2],
		secondVector[0],secondVector[1],secondVector[2],
		thirdVector[0],thirdVector[1],thirdVector[2],
		firstColor[0],firstColor[1],firstColor[2],
		firstColor[0]/2,firstColor[1]/2,firstColor[2]/2,
		secondColor[0],secondColor[1],secondColor[2],
		secondColor[0]/2,secondColor[1]/2,secondColor[2]/2,
		thirdColor[0],thirdColor[1],thirdColor[2],
		thirdColor[0]/2,thirdColor[1]/2,thirdColor[2]/2,
		radius/2
		);
     return temp;
}
/********************************************************************************/
static gchar *get_pov_ball(gint num, gfloat scale)
{
     gchar *temp;
     XYZRC Center = get_prop_center(num,1.0);
     temp = g_strdup_printf(
		"sphere\n"
		"{\n"
		"\t<%14.6f,%14.6f,%14.6f> %14.6f\n"
		"\ttexture\n"
		"\t{\n"
		"\t\tpigment { rgb<%14.6f,%14.6f,%14.6f> }\n"
		"\t\tfinish {ambient ambientCoef diffuse diffuseCoef specular specularCoef}\n"
		"\t}\n"
		"}\n"
		,
		Center.C[0],Center.C[1],Center.C[2],Center.C[3]*scale,
		Center.P.Colors[0], Center.P.Colors[1], Center.P.Colors[2]
		);
     return temp;
}
/********************************************************************************/
static gchar *get_pov_cylingre(gdouble C1[],gdouble C2[],gdouble Colors[],gdouble ep)
{
     gchar* temp = NULL;
     gint i;
     gfloat d = 0;

     for(i=0;i<3;i++) d += (C1[i]-C2[i])*(C1[i]-C2[i]);
     if(d<1e-8) return g_strdup("\n");

     temp = g_strdup_printf(
		"cylinder\n"
		"{\n"
		"\t<%14.6f,%14.6f,%14.6f>,\n"
		"\t<%14.6f,%14.6f,%14.6f> \n"
		"\t%14.6f\n"
		"\ttexture\n"
		"\t{\n"
		"\t\tpigment { rgb<%14.6f,%14.6f,%14.6f> }\n"
		"\t\tfinish {ambient ambientCoef diffuse diffuseCoef specular specularCoef}\n"
		"\t}\n"
		"}\n",
		C1[0],C1[1],C1[2],
		C2[0],C2[1],C2[2],
		ep,
		Colors[0],Colors[1],Colors[2]
		);
	return temp;

}
/********************************************************************************/
static gchar *get_pov_one_stick(gint i,gint j, GabEditBondType bondType)
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
     V3d CC1;
     V3d CC2;

     Center1 = get_prop_center(i, 1.0);
     Center2 = get_prop_center(j, 1.0);
     k =get_num_min_rayonIJ(i,j);
 
     /*
     if(k==i) ep = Center1.C[3];
     else ep = Center2.C[3];
     */
     ep =  STICKSIZEBALL;

     /* if(TypeGeom == GABEDIT_TYPEGEOM_STICK ) ep /=4;*/
     if(TypeGeom == GABEDIT_TYPEGEOM_STICK ) ep =STICKSIZE;
     else ep/=2;
     if(TypeGeom==GABEDIT_TYPEGEOM_WIREFRAME ) ep =STICKSIZE/2;

 
     poid1 = GeomOrb[i].Prop.covalentRadii+GeomOrb[i].Prop.radii;
     poid2 = GeomOrb[j].Prop.covalentRadii+GeomOrb[j].Prop.radii;
     poid = poid1 + poid2 ;
     for(l=0;l<3;l++) CC1[l] =Center1.C[l];
     for(l=0;l<3;l++) CC2[l] =Center2.C[l];
     if(bondType == GABEDIT_BONDTYPE_SINGLE)
     {
     	for(l=0;l<3;l++) C[l] =(Center1.C[l]*poid2+Center2.C[l]*poid1)/poid;
      	temp1 = get_pov_cylingre(Center1.C,C,Center1.P.Colors,ep);
      	temp2 = get_pov_cylingre(C,Center2.C,Center2.P.Colors,ep);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
     }
     else if(bondType == GABEDIT_BONDTYPE_DOUBLE && TypeGeom == GABEDIT_TYPEGEOM_STICK)
     {
	gchar* temp3;
  	V3d vScal = {ep*1.5,ep*1.5,ep*1.5};
	gdouble C1[3];
	gdouble C2[3];
	V3d cros;
	V3d sub;
	V3d CRing;
	gfloat C10[3];
	gfloat C20[3];
	getCentreRing(i,j, CRing);
	v3d_sub(CRing, CC1, C10);
	v3d_sub(CRing, CC2, C20);
	v3d_cross(C10, C20, cros);
	v3d_sub(CC1, CC2, sub);
	v3d_cross(cros, sub, vScal);
	if(v3d_dot(vScal,vScal)!=0)
	{
		v3d_normal(vScal);
		v3d_scale(vScal, ep*1.5);
	}
	for(l=0;l<3;l++) C1[l] = Center1.C[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_pov_cylingre(C1,C,Center1.P.Colors,ep);
      	temp2 = get_pov_cylingre(C,C2,Center2.P.Colors,ep);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
	for(l=0;l<3;l++) C1[l] = Center1.C[l]-vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]-vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_pov_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_pov_cylingre(C,C2,Center2.P.Colors,ep/3);
	temp3 = temp;
      	temp = g_strdup_printf("%s%s%s",temp3,temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
      	g_free(temp3);
     }
     else if(bondType == GABEDIT_BONDTYPE_TRIPLE  && TypeGeom == GABEDIT_TYPEGEOM_STICK)
     {
	gchar* temp3;
  	V3d vScal = {ep*1.5,ep*1.5,ep*1.5};
	gdouble C1[3];
	gdouble C2[3];
	V3d cros;
	V3d sub;
	V3d CRing;
	gfloat C10[3];
	gfloat C20[3];
	getCentreRing(i,j, CRing);
	v3d_sub(CRing, CC1, C10);
	v3d_sub(CRing, CC2, C20);
	v3d_cross(C10, C20, cros);
	v3d_sub(CC1, CC2, sub);
	v3d_cross(cros, sub, vScal);
	if(v3d_dot(vScal,vScal)!=0)
	{
		v3d_normal(vScal);
		v3d_scale(vScal, ep*1.5);
	}
	for(l=0;l<3;l++) C1[l] = Center1.C[l]-vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]-vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_pov_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_pov_cylingre(C,C2,Center2.P.Colors,ep/3);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
	for(l=0;l<3;l++) C1[l] = Center1.C[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_pov_cylingre(C1,C,Center1.P.Colors,ep);
      	temp2 = get_pov_cylingre(C,C2,Center2.P.Colors,ep);
	temp3 = temp;
      	temp = g_strdup_printf("%s%s%s",temp3,temp1,temp2);
      	g_free(temp3);
      	g_free(temp1);
      	g_free(temp2);
	for(l=0;l<3;l++) C1[l] = Center1.C[l]+vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]+vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_pov_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_pov_cylingre(C,C2,Center2.P.Colors,ep/3);
	temp3 = temp;
      	temp = g_strdup_printf("%s%s%s",temp3,temp1,temp2);
      	g_free(temp3);
      	g_free(temp1);
      	g_free(temp2);
     }
     else if(bondType == GABEDIT_BONDTYPE_DOUBLE)
     {
	gchar* temp3;
  	V3d vScal = {ep*0.5,ep*0.5,ep*0.5};
	gdouble C1[3];
	gdouble C2[3];
	V3d cros;
	V3d sub;
	V3d CRing;
	gfloat C10[3];
	gfloat C20[3];
	getCentreRing(i,j, CRing);
	v3d_sub(CRing, CC1, C10);
	v3d_sub(CRing, CC2, C20);
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
      	temp1 = get_pov_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_pov_cylingre(C,C2,Center2.P.Colors,ep/3);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
	for(l=0;l<3;l++) C1[l] = Center1.C[l]+vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]+vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_pov_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_pov_cylingre(C,C2,Center2.P.Colors,ep/3);
	temp3 = temp;
      	temp = g_strdup_printf("%s%s%s",temp3,temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
      	g_free(temp3);
     }
     else if(bondType == GABEDIT_BONDTYPE_TRIPLE)
     {
	gchar* temp3;
  	V3d vScal = {ep*0.5,ep*0.5,ep*0.5};
	gdouble C1[3];
	gdouble C2[3];
	V3d cros;
	V3d sub;
	V3d CRing;
	gfloat C10[3];
	gfloat C20[3];
	getCentreRing(i,j, CRing);
	v3d_sub(CRing, CC1, C10);
	v3d_sub(CRing, CC2, C20);
	v3d_cross(C10, C20, cros);
	v3d_sub(CC1, CC2, sub);
	v3d_cross(cros, sub, vScal);
	if(v3d_dot(vScal,vScal)!=0)
	{
		v3d_normal(vScal);
		v3d_scale(vScal, ep*0.5*2);
	}
	for(l=0;l<3;l++) C1[l] = Center1.C[l]-vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]-vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_pov_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_pov_cylingre(C,C2,Center2.P.Colors,ep/3);
      	temp = g_strdup_printf("%s%s",temp1,temp2);
      	g_free(temp1);
      	g_free(temp2);
	for(l=0;l<3;l++) C1[l] = Center1.C[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_pov_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_pov_cylingre(C,C2,Center2.P.Colors,ep/3);
	temp3 = temp;
      	temp = g_strdup_printf("%s%s%s",temp3,temp1,temp2);
      	g_free(temp3);
      	g_free(temp1);
      	g_free(temp2);
	for(l=0;l<3;l++) C1[l] = Center1.C[l]+vScal[l];
	for(l=0;l<3;l++) C2[l] = Center2.C[l]+vScal[l];
     	for(l=0;l<3;l++) C[l] =(C1[l]*poid2+C2[l]*poid1)/poid;
      	temp1 = get_pov_cylingre(C1,C,Center1.P.Colors,ep/3);
      	temp2 = get_pov_cylingre(C,C2,Center2.P.Colors,ep/3);
	temp3 = temp;
      	temp = g_strdup_printf("%s%s%s",temp3,temp1,temp2);
      	g_free(temp3);
      	g_free(temp1);
      	g_free(temp2);
     }
     else temp = g_strdup_printf(" ");
     return temp;
}
/********************************************************************************/
static gchar *get_pov_one_hbond(gint i,gint j)
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

     Center1 = get_prop_center(i, 1.0);
     Center2 = get_prop_center(j, 1.0);
     k =get_num_min_rayonIJ(i,j);
 
     if(k==i) ep = Center1.C[3];
     else ep = Center2.C[3];

     if(TypeGeom == GABEDIT_TYPEGEOM_STICK  ) ep /=4;
     else ep/=2;
     if(TypeGeom==GABEDIT_TYPEGEOM_WIREFRAME ) ep /=4;

 
     poid1 = GeomOrb[i].Prop.covalentRadii+GeomOrb[i].Prop.radii;
     poid2 = GeomOrb[j].Prop.covalentRadii+GeomOrb[j].Prop.radii;
     poid = poid1 + poid2 ;

     ibreak = (gint)(poid1*n/poid);

     for(l=0;l<3;l++) K[l] =(Center2.C[l]-Center1.C[l])/(n*5/4);
     for(l=0;l<3;l++) A[l] =Center1.C[l];
     temp = NULL;
     for(i=0;i<n;i++)
     {
     	for(l=0;l<3;l++) B[l] = A[l] + K[l];
	if(i<=ibreak)
		temp1 =  get_pov_cylingre(A,B,Center1.P.Colors,ep/2);
	else
		temp1 =  get_pov_cylingre(A,B,Center2.P.Colors,ep/2);
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
static gchar *get_pov_epilogue()
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
static gchar *get_pov_declare_finish_option()
{
	gchar* temp;

	temp = g_strdup_printf(
	 "// finish options\n"
	 "#declare ambientCoef = 0.2;\n"
	 "#declare diffuseCoef = 0.8;\n"
	 "#declare specularCoef = 0.8;\n"
	 "\n"
	);
	return temp;
}
/********************************************************************************/
static gchar *get_pov_declare_surface_options()
{
	gchar* temp;
	gint i;
	gdouble ep;
	/* compute the min radius of atoms*/
	ep = 10000;
	for(i=0;i<Ncenters;i++)
	{
		if(!strstr(GeomOrb[i].Prop.symbol,"X") && ep>GeomOrb[i].Prop.radii) ep = GeomOrb[i].Prop.radii;
	}
	ep /= 32;

	temp = g_strdup_printf(
	 "// transparency coeffition\n"
	 "#declare surfaceTransCoef = 0.6;\n"
	 "// wire frame radius of cylinder\n"
	 "#declare wireFrameCylinderRadius = %f;\n"
	 "\n\n",
	 ep
	);
	return temp;
}
/********************************************************************************/
static gchar *get_pov_matrix_transformation()
{
	gfloat q[4];
	gfloat m[4][4];
	gchar* temp;

	getQuat(q);
	build_rotmatrix(m,q);
	temp = g_strdup_printf(
	 "// Rotation matrix\n"
	 "#declare myTransforms = transform {\n"
	 "matrix <%f, %f ,%f, %f, %f, %f, %f, %f, %f, %f, %f ,%f>\n"
	 "}\n\n",
	 m[0][0],m[0][1],m[0][2],
	 m[1][0],m[1][1],m[1][2],
	 m[2][0],m[2][1],m[2][2],
	 m[3][0],m[3][1],m[3][2]
	);
	return temp;
}
/********************************************************************************/
static gchar *get_pov_declare_arrow()
{
     gchar *temp;
     temp = g_strdup(
	"// arrow\n"
	"#macro arrow (P1, P2, r, C1, C2) \n"
	"\tunion {\n"
	"\t\tcylinder\n"
	"\t\t{\n"
	"\t\t\tP1,P2-(P2-P1)*0.2,r\n"
	"\t\t\ttexture\n"
	"\t\t\t{\n"
	"\t\t\t\tpigment { rgb C1}\n"
	"\t\t\t\tfinish {ambient ambientCoef diffuse diffuseCoef specular specularCoef}\n"
	"\t\t\t}\n"
	"\t\t}\n"
	"\t\tcone\n"
	"\t\t{\n"
	"\t\t\tP2-(P2-P1)*0.2,r*2.0,P2,0\n"
	"\t\t\ttexture\n"
	"\t\t\t{\n"
	"\t\t\t\tpigment { rgb C2}\n"
	"\t\t\t\tfinish {ambient ambientCoef diffuse diffuseCoef specular specularCoef}\n"
	"\t\t\t}\n"
	"\t\t}\n"
	"\t\tno_shadow\n"
	"\t}\n"
	"#end\n"
	 "\n"
		    );
     return temp;
}
/********************************************************************************/
static gchar *get_pov_declare_threeCylinders_wireframe()
{
     gchar *temp;
     temp = g_strdup(
	"// TriangleCylinders\n"
	"#macro threeCylinders ( P1, P2, P3, r) \n"
	"\tunion {\n"
	"\t\t#if (vlength(P1-P2)>0)\n"
	"\t\t\tcylinder { P1 , P2, r}\n"
	"\t\t#end\n"
	"\t\t#if (vlength(P2-P3)>0)\n"
	"\t\t\tcylinder { P2 , P3, r}\n"
	"\t\t#end\n"
	"\t\t#if (vlength(P1-P3)>0)\n"
	"\t\t\tcylinder { P3 , P1, r}\n"
	"\t\t#end\n"
	"\t}\n"
	"#end\n"
	 "\n"
		    );
     return temp;
}
/********************************************************************************/
static gchar *get_pov_declare_threeCylinders_wireframe_color()
{
     gchar *temp;
     temp = g_strdup(
	"// TriangleCylindersColor\n"
	"#macro threeCylindersColor ( P1, P2, P3, C1, C2, C3, r) \n"
	"\tunion {\n"
	"\t\t#if (vlength(P1-P2)>0)\n"
	"\t\t\tcylinder { P1 , P2, r  texture {pigment { rgb C1}} finish {ambient ambientCoef diffuse diffuseCoef specular specularCoef} }\n"
	"\t\t#end\n"
	"\t\t#if (vlength(P2-P3)>0)\n"
	"\t\t\tcylinder { P2 , P3, r  texture {pigment { rgb C2}} finish {ambient ambientCoef diffuse diffuseCoef specular specularCoef} }\n"
	"\t\t#end\n"
	"\t\t#if (vlength(P1-P3)>0)\n"
	"\t\t\tcylinder { P3 , P1, r  texture {pigment { rgb C3}} finish {ambient ambientCoef diffuse diffuseCoef specular specularCoef} }\n"
	"\t\t#end\n"
	"\t}\n"
	"#end\n"
	 "\n"
		    );
     return temp;
}
/********************************************************************************/
static gchar *get_pov_camera()
{
	gchar *temp;
	gfloat f = 5;
	gfloat position = 10;
	gfloat zn, zf, zo;
	gboolean perspective;
	get_camera_values(&zn, &zf, &zo, &perspective);

	position = zf/2;
	f = position/2;

     
	temp = g_strdup_printf(
	 "// CAMERA\n"
	 "camera\n"
	 "{\n"
	 "\tright      < 0.000000, 1.000000, 0.000000 >\n"
	  "\tup        < 0.000000, 1.000000, 0.000000 >\n"
	  "\tdirection < 0.000000, 0.000000, 1.00000 >\n"
	  "\tlocation  < 0.000000, 0.00000, %14.8f >\n"
	  "\tlook_at   < 0.000000, 0.00000, %14.8f >\n"
	  "}\n\n",
	   position,f
	);
     return temp;
}
/********************************************************************************/
static gchar *get_pov_light_source(gchar* title,gchar* color,gfloat x,gfloat y, gfloat z)
{
	gchar *temp;
     	temp = g_strdup_printf("%s%s\t<%10.6f,%10.6f,%10.6f>\n\tcolor %s\n}\n",
				title,
         			"light_source\n"
         			"{\n\n",
				 x,y,z,color);
	return temp;           
}
/********************************************************************************/
static gchar *get_pov_light_sources()
{
     gchar *temp;
     gfloat Ymax;
     gchar* dump1;
     gchar* dump2;
     gint i=0;
/* calcul of Ymax*/

     Ymax = GeomOrb[0].C[1];
     for(i=1;i<(gint)Ncenters;i++)
		if(Ymax<GeomOrb[i].C[1])
			Ymax = GeomOrb[i].C[1];
     
      Ymax +=10;
      dump1 = get_pov_light_source("// LIGHT 1\n","0.6*White",Ymax,Ymax,Ymax);
      dump2 =  get_pov_light_source("// LIGHT 2\n","0.8*White",0,0,Ymax);;
      temp = g_strdup_printf("%s %s",dump1, dump2);
      g_free(dump1);
      g_free(dump2);

     return temp;
}
/********************************************************************************/
static gchar *get_pov_begin_molecule()
{
     gchar *temp;
     temp = g_strdup( "\n# declare molecule = union {\n");
     return temp;
}
/********************************************************************************/
static gchar *get_pov_end_molecule()
{
     gchar *temp;
     temp = g_strdup("transform { myTransforms }\n}\n\nobject {molecule}");
     return temp;
}
/********************************************************************************/
static gchar *get_pov_atoms()
{
     	gchar *temp=NULL;
     	gchar *tempold=NULL;
     	gchar *t=NULL;
     	gint i=0;
     	temp = g_strdup( "// ATOMS \n");
	for(i=0;i<(gint)Ncenters;i++)
	{
		if(!ShowHAtomOrb && strcmp("H",GeomOrb[i].Symb)==0) continue;
		tempold = temp;
		t =get_pov_ball(i,1.0);
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
static gchar *get_pov_ball_for_stick(gint num, gfloat radius)
{
     gchar *temp;
     XYZRC Center = get_prop_center(num,1.0);
     temp = g_strdup_printf(
		"sphere\n"
		"{\n"
		"\t<%14.6f,%14.6f,%14.6f> %14.6f\n"
		"\ttexture\n"
		"\t{\n"
		"\t\tpigment { rgb<%14.6f,%14.6f,%14.6f> }\n"
		"\t\tfinish {ambient ambientCoef diffuse diffuseCoef specular specularCoef}\n"
		"\t}\n"
		"}\n"
		,
		Center.C[0],Center.C[1],Center.C[2], radius,
		Center.P.Colors[0], Center.P.Colors[1], Center.P.Colors[2]
		);
     return temp;
}
/********************************************************************************/
static gchar *get_pov_atoms_for_stick()
{
     	gchar *temp=NULL;
     	gchar *tempold=NULL;
     	gchar *t=NULL;
     	gint i=0;
     	temp = g_strdup( "// ATOMS \n");
	for(i=0;i<(gint)Ncenters;i++)
	{
		if(!ShowHAtomOrb && strcmp("H",GeomOrb[i].Symb)==0) continue;
		tempold = temp;
		if(TypeGeom==GABEDIT_TYPEGEOM_WIREFRAME)
			t =get_pov_ball_for_stick(i,STICKSIZE/2);
		else
			t =get_pov_ball_for_stick(i,STICKSIZE);
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
static gchar *get_pov_bonds()
{
     gchar *temp = NULL;
     gint i,j;
     gchar* t;
     gchar* tempold;
     gboolean* Ok = NULL;
     GList* list = NULL;
     if(Ncenters>0) Ok = g_malloc(Ncenters*sizeof(gboolean));
     for(i=0;i<(gint)Ncenters;i++) Ok[i] = FALSE;

     temp = g_strdup( "// BONDS \n");
     for(list=BondsOrb;list!=NULL;list=list->next)
     {
	BondType* data=(BondType*)list->data;
	i = data->n1;
	j = data->n2;
	if(!ShowHAtomOrb && (strcmp("H",GeomOrb[i].Symb)==0 || strcmp("H",GeomOrb[j].Symb)==0)) continue;
	if(data->bondType == GABEDIT_BONDTYPE_HYDROGEN)
	{
		tempold = temp;
		t =get_pov_one_hbond(i,j);
		if(tempold)
               	{
               		temp = g_strdup_printf("%s%s",tempold,t);
                       	g_free(tempold);
                }
                else temp = g_strdup_printf("%s",t); 
	}
	else
	{
		Ok[i] = TRUE;
		Ok[j] = TRUE;
		tempold = temp;
		t =get_pov_one_stick(i,j,data->bondType);
		if(tempold)
               	{
                       	temp = g_strdup_printf("%s%s",tempold,t);
                       	g_free(tempold);
               	}
               	else temp = g_strdup_printf("%s",t); 
	}
     }

     for(i=0;i<(gint)Ncenters;i++)
     if(!Ok[i])
     {
		if(!ShowHAtomOrb && strcmp("H",GeomOrb[i].Symb)==0) continue;
		tempold = temp;
		t =get_pov_ball(i, 0.5);
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
     if(Ok) g_free(Ok);
     return temp;
}
/********************************************************************************/
static void save_pov_surfaces(FILE* file)
{
	gchar* fileName = g_strdup_printf("%s%stmp%spovraySurfaces.pov",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
	gchar* fileNameLast = g_strdup_printf("%s%stmp%spovrayLastSurface.pov",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
	FILE* fileSurfaces = fopen(fileName,"r");
	FILE* fileLastSurface = fopen(fileNameLast,"r");
	gchar* t = g_malloc(BSIZE*sizeof(gchar));

	g_free(fileName);
	g_free(fileNameLast);
	if(!fileSurfaces)
	{
		g_free(t);
		return;
	}
	while(!feof(fileSurfaces))
	{
		if(!fgets(t, BSIZE,fileSurfaces)) break;
		fprintf(file,"%s",t);
	}
	fclose(fileSurfaces);

	if(!fileLastSurface)
	{
		g_free(t);
		return;
	}
	while(!feof(fileLastSurface))
	{
		if(!fgets(t, BSIZE,fileLastSurface)) break;
		fprintf(file,"%s",t);
	}
	fclose(fileLastSurface);
	g_free(t);
}
/********************************************************************************/
static void save_pov_contours(FILE* file)
{
	gchar* fileName = g_strdup_printf("%s%stmp%spovrayContours.pov",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
	FILE* fileContours = fopen(fileName,"r");
	gchar* t = g_malloc(BSIZE*sizeof(gchar));

	g_free(fileName);
	if(!fileContours)
	{
		g_free(t);
		return;
	}
	while(!feof(fileContours))
	{
		if(!fgets(t, BSIZE,fileContours)) break;
		fprintf(file,"%s",t);
	}
	fclose(fileContours);
}
/********************************************************************************/
static void save_pov_planes_mapped(FILE* file)
{
	gchar* fileName = g_strdup_printf("%s%stmp%spovrayPlanesMapped.pov",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
	FILE* filePlanesMapped = fopen(fileName,"r");
	gchar* t = g_malloc(BSIZE*sizeof(gchar));

	g_free(fileName);
	if(!filePlanesMapped)
	{
		g_free(t);
		return;
	}
	while(!feof(filePlanesMapped))
	{
		if(!fgets(t, BSIZE,filePlanesMapped)) break;
		fprintf(file,"%s",t);
	}
	fclose(filePlanesMapped);
}
/********************************************************************************/
static void save_pov_rings(FILE* file)
{
	gchar* fileName = g_strdup_printf("%s%stmp%spovrayRings.pov",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
	FILE* fileRings = fopen(fileName,"r");
	gchar* t = g_malloc(BSIZE*sizeof(gchar));

	g_free(fileName);
	if(!fileRings)
	{
		g_free(t);
		return;
	}
	while(!feof(fileRings))
	{
		if(!fgets(t, BSIZE,fileRings)) break;
		fprintf(file,"%s",t);
	}
	fclose(fileRings);
}
/********************************************************************************/
static gchar* create_povray_file(gchar* fileName, gboolean saveCamera, gboolean newCamera)
{
	FILE* file;
	gchar* temp;
	static gchar message[1024];
	static gchar* camera = NULL;
	static gchar* background = NULL;
	static gchar* light = NULL;


	if(!GLArea)
	{
		sprintf(message,"Sorry\n OpenGl window is not open");
		return message;
	}
 	if ((!fileName) || (strcmp(fileName,"") == 0))
	{
		sprintf(message,"Sorry\n Problem with the name of file");
	       	return message;
	}

	file = FOpen(fileName, "w");
 	if (!file)
	{
		sprintf(message,"Sorry\n I can not open %s file ",fileName);
	       	return message;
	}
	
	temp =get_pov_epilogue();
	fprintf(file,"%s",temp);
	g_free(temp);
	temp = get_pov_matrix_transformation();
	fprintf(file,"%s",temp);
	g_free(temp);

	temp = get_pov_declare_finish_option();
	fprintf(file,"%s",temp);
	g_free(temp);

	temp = get_pov_declare_arrow();
	fprintf(file,"%s",temp);
	g_free(temp);

	if(newCamera)
	{
		temp =get_pov_camera();
		fprintf(file,"%s",temp);
		if(saveCamera)
		{
			if(camera) g_free(camera);
			camera = g_strdup(temp);
		}
		g_free(temp);
	}
	else
	{
		if(camera) fprintf(file,"%s",camera);
		else
		{
			printf("Erreur : No new camera et camera =NULL\n");
			temp =get_pov_camera();
			fprintf(file,"%s",temp);
			g_free(temp);
		}
	}

	if(newCamera)
	{
		temp = get_pov_light_sources();
		fprintf(file,"%s",temp);
		if(saveCamera)
		{
			if(light) g_free(light);
			light = g_strdup(temp);
		}
		g_free(temp);
	}
	else
	{
		if(light) fprintf(file,"%s",light);
		else
		{
			printf("Erreur : No new camera et camera =NULL\n");
			temp = get_pov_light_sources();
			fprintf(file,"%s",temp);
			g_free(temp);
		}
	}

	if(newCamera)
	{
		gfloat xmin = get_min(0);
		gfloat ymin = get_min(1);
		gfloat zmin = get_min(2);
 		temp = get_pov_background(xmin,ymin,zmin);
		fprintf(file,"%s",temp);
		if(saveCamera)
		{
			if(background) g_free(background);
			background = g_strdup(temp);
		}
		g_free(temp);
	}
	else
	{
		if(background) fprintf(file,"%s",background);
		else
		{
			gfloat xmin = get_min(0);
			gfloat ymin = get_min(1);
			gfloat zmin = get_min(2);
			printf("Erreur : No new camera and background =NULL\n");
 			temp = get_pov_background(xmin,ymin,zmin);
			fprintf(file,"%s",temp);
			g_free(temp);
		}
	}

     	if(Ncenters<1)
	{
		fclose(file);
		return NULL;
	}

	temp = get_pov_begin_molecule();
	fprintf(file,"%s",temp);
	g_free(temp);

	if(TypeGeom==GABEDIT_TYPEGEOM_BALLSTICK || TypeGeom==GABEDIT_TYPEGEOM_SPACE)
	{
		temp = get_pov_atoms(); 
		fprintf(file,"%s",temp);
		g_free(temp);
	}
	else if(TypeGeom==GABEDIT_TYPEGEOM_STICK || TypeGeom==GABEDIT_TYPEGEOM_WIREFRAME)
	{
		temp = get_pov_atoms_for_stick(); 
		fprintf(file,"%s",temp);
		g_free(temp);
	}
	if(TypeGeom==GABEDIT_TYPEGEOM_BALLSTICK || TypeGeom==GABEDIT_TYPEGEOM_STICK || TypeGeom==GABEDIT_TYPEGEOM_WIREFRAME)
	{
		temp = get_pov_bonds(); 
		fprintf(file,"%s",temp);
		g_free(temp);
	}
	if(Dipole.def && ShowDipoleOrb)
	{
			temp = get_pov_dipole();
			fprintf(file,"%s",temp);
			g_free(temp);
	}
	temp = get_pov_xyz_axes();
	if(temp)
	{
		fprintf(file,"%s",temp);
		g_free(temp);
	}
	temp = get_pov_principal_axes();
	if(temp)
	{
		fprintf(file,"%s",temp);
		g_free(temp);
	}
	temp = get_pov_end_molecule();
	fprintf(file,"%s",temp);
	g_free(temp);

	temp = get_pov_declare_surface_options();
	fprintf(file,"%s",temp);
	g_free(temp);

	temp = get_pov_declare_threeCylinders_wireframe();
	fprintf(file,"%s",temp);
	g_free(temp);

	temp = get_pov_declare_threeCylinders_wireframe_color();
	fprintf(file,"%s",temp);
	g_free(temp);

	save_pov_surfaces(file);
	save_pov_contours(file);
	save_pov_planes_mapped(file);
	save_pov_rings(file);
		
 	fclose(file);
	return NULL;
}
/********************************************************************************/
static void save_povray_file(GabeditFileChooser *w , gint response_id)
{
	gchar *fileName;
	gchar* message = NULL;
    	GtkWidget* m;

 	if(response_id != GTK_RESPONSE_OK) return;
	if(!GLArea) return;
 	fileName = gabedit_file_chooser_get_current_file(w);
	message = create_povray_file(fileName, FALSE, TRUE);
	if(message)
	{
    		m = Message(message,"Error",TRUE);
		gtk_window_set_modal (GTK_WINDOW (m), TRUE);
	}
}
/**************************************************************************/
gchar* new_pov(gchar* dirname, int i)
{
	gchar* fileName = g_strdup_printf("%s%sgab%d.pov",dirname,G_DIR_SEPARATOR_S,i);
	gchar* message;
	if(i==1)
	{
		gint j;
		for(j=0;j<100;j++)
		{
			gchar* filestoDelete = g_strdup_printf("%s%sgab%d.pov",dirname,G_DIR_SEPARATOR_S,j);
			unlink(filestoDelete);
			g_free(filestoDelete);

		}
		message = create_povray_file(fileName,TRUE,TRUE);
	}
	else
		message = create_povray_file(fileName,FALSE,FALSE);

	g_free(fileName);
	return message;
}
/********************************************************************************/
void create_save_povray_orb(GtkWidget* Win)
{
	gchar* title = g_strdup_printf("Create a povray file");
  	gchar* patternsfiles[] = {"*","*.pov",NULL};
	gchar* fileName = g_strdup_printf("gabedit.pov");
	gchar* filter = g_strdup_printf("*.pov");

	GtkWidget* win = choose_file_to_create(title, GTK_SIGNAL_FUNC(save_povray_file));
	gabedit_file_chooser_set_filters(GABEDIT_FILE_CHOOSER(win), patternsfiles);
	gabedit_file_chooser_set_filter(GABEDIT_FILE_CHOOSER(win),filter);
	gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(win),fileName);
	g_free(title);
	g_free(fileName);
	g_free(filter);
}
