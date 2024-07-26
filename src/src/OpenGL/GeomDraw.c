/* GeomDraw */
/**********************************************************************************************************
Copyright (c) 2002 Abdul-Rahman Allouche. All rights reserved

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
#include "../Utils/Vector3d.h"
#include "../Utils/Transformation.h"
#include "../Utils/Utils.h"
#include "../Utils/Constantes.h"
#include "../Utils/HydrogenBond.h"
#include "Sphere.h"
#include "Cylinder.h"

/************************************************************************/
gboolean draw_lines_yes_no_orb(gint i,gint j)
{
	GLfloat distance;
	V3d dif;
	gint k;
	
	for(k=0;k<3;k++)
		dif[k] = (GeomOrb[i].C[k] - GeomOrb[j].C[k]);

	distance = v3d_length(dif);

	if(distance<(GeomOrb[i].Prop.covalentRadii + GeomOrb[j].Prop.covalentRadii))
		return TRUE;
	else 
		return FALSE;
}
/************************************************************************/
gboolean draw_lines_hbond_yes_no_orb(gint i,gint j)
{
	gfloat minDistanceH;
	gfloat maxDistanceH;
	gfloat minDistanceH2;
	gfloat maxDistanceH2;
	gfloat minAngleH;
	gfloat maxAngleH;
	gfloat distance2;
	gfloat angle;
	gchar* strAngle;
	Point A;
	Point B;
	gdouble dx, dy, dz;

	gint k;
	gint kH;
	gint kO;

	if(strcmp(GeomOrb[i].Symb,"H") == 0 )
	{
		kH = i;
		kO = j;
		if(!atomCanDoHydrogenBond(GeomOrb[j].Symb)) return FALSE;
	}
	else
	{
		if(strcmp(GeomOrb[j].Symb,"H") == 0 )
		{
			kH = j;
			kO = i;
			if(!atomCanDoHydrogenBond(GeomOrb[i].Symb)) return FALSE;
		}
		else return FALSE;
	}
	minDistanceH = getMinDistanceHBonds();
	minDistanceH2 = minDistanceH*minDistanceH*ANG_TO_BOHR*ANG_TO_BOHR;

	maxDistanceH = getMaxDistanceHBonds();
	maxDistanceH2 = maxDistanceH*maxDistanceH*ANG_TO_BOHR*ANG_TO_BOHR;

	minAngleH = getMinAngleHBonds();
	maxAngleH = getMaxAngleHBonds();

	dx = GeomOrb[i].C[0] - GeomOrb[j].C[0];
	dy = GeomOrb[i].C[1] - GeomOrb[j].C[1];
	dz = GeomOrb[i].C[2] - GeomOrb[j].C[2];
	distance2 = (dx*dx+dy*dy+dz*dz);
	if(distance2<minDistanceH2 || distance2>maxDistanceH2) return FALSE;

	for(k=0;k<Ncenters;k++)
	{
		if(k==kH) continue;
		if(k==kO) continue;
		/* angle kO, kH, connection to kH */
		if(!draw_lines_yes_no_orb(kH,k)) continue;
		A.C[0]=GeomOrb[kO].C[0]-GeomOrb[kH].C[0];
		A.C[1]=GeomOrb[kO].C[1]-GeomOrb[kH].C[1];
		A.C[2]=GeomOrb[kO].C[2]-GeomOrb[kH].C[2];

		B.C[0]=GeomOrb[k].C[0]-GeomOrb[kH].C[0];
		B.C[1]=GeomOrb[k].C[1]-GeomOrb[kH].C[1];
		B.C[2]=GeomOrb[k].C[2]-GeomOrb[kH].C[2];
        
        	strAngle = get_angle_vectors(A,B);
		angle = atof(strAngle);
		if(strAngle) g_free(strAngle);
		if(angle>=minAngleH &&angle<=maxAngleH) return TRUE;
	}
	return FALSE;
}
/************************************************************************/
void draw_space(int i)
{
	int k;
	V4d Specular = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant  = {0.2f,0.2f,0.2f,1.0f};
	  
	Specular[0] = GeomOrb[i].Prop.color.red/(gfloat)65535;
	Specular[1] = GeomOrb[i].Prop.color.green/(gfloat)65535;
	Specular[2] = GeomOrb[i].Prop.color.blue/(gfloat)65535;
	for(k=0;k<3;k++) Diffuse[k] = Specular[k]*0.8;
	for(k=0;k<3;k++) Ambiant[k] = Specular[k]*0.8;
	for(k=0;k<3;k++) Specular[k] = 1.0;

	Sphere_Draw_Color_Precision(GeomOrb[i].Prop.vanDerWaalsRadii,GeomOrb[i].C,Specular,Diffuse,Ambiant, (GLint)openGLOptions.numberOfSubdivisionsSphere*2);

}
/************************************************************************/
void draw_ball(int i,GLfloat scal)
{
	int k;
	V4d Specular = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant  = {0.0f,0.0f,0.0f,1.0f};
	GLfloat g = scal*GeomOrb[i].Prop.radii;
	  
	Specular[0] = GeomOrb[i].Prop.color.red/(gfloat)65535;
	Specular[1] = GeomOrb[i].Prop.color.green/(gfloat)65535;
	Specular[2] = GeomOrb[i].Prop.color.blue/(gfloat)65535;
	for(k=0;k<3;k++) Diffuse[k] = Specular[k]*0.8;
	for(k=0;k<3;k++) Ambiant[k] = Specular[k]*0.5;

	Sphere_Draw_Color(g,GeomOrb[i].C,Specular,Diffuse,Ambiant);

}
/************************************************************************/
void draw_hbond(int i,int j,GLfloat scal)
{
	
	int k;
	GLfloat g;
	V4d Specular1 = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse1  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant1  = {0.0f,0.0f,0.0f,1.0f};
	V4d Specular2 = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse2  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant2  = {0.0f,0.0f,0.0f,1.0f};
	GLfloat aspect = scal;
	GLfloat p1;
	GLfloat p2;
     	gfloat A[3];
     	gfloat B[3];
     	gfloat K[3];
     	static gint n = 10;
	gint kbreak;
	
	if(GeomOrb[i].Prop.radii<GeomOrb[j].Prop.radii) g = GeomOrb[i].Prop.radii*aspect;
	else g = GeomOrb[j].Prop.radii*aspect;
	  
	Specular1[0] = GeomOrb[i].Prop.color.red/(gfloat)65535;
	Specular1[1] = GeomOrb[i].Prop.color.green/(gfloat)65535;
	Specular1[2] = GeomOrb[i].Prop.color.blue/(gfloat)65535;

	Specular2[0] = GeomOrb[j].Prop.color.red/(gfloat)65535;
	Specular2[1] = GeomOrb[j].Prop.color.green/(gfloat)65535;
	Specular2[2] = GeomOrb[j].Prop.color.blue/(gfloat)65535;

	for(k=0;k<3;k++)
	{
		Diffuse1[k] = Specular1[k]*0.8;
		Diffuse2[k] = Specular2[k]*0.8;
	}
	for(k=0;k<3;k++)
	{
		Ambiant1[k] = Specular1[k]*0.5;
		Ambiant2[k] = Specular2[k]*0.5;
	}

	p1 = GeomOrb[i].Prop.covalentRadii+GeomOrb[i].Prop.radii;
	p2 = GeomOrb[j].Prop.covalentRadii+GeomOrb[j].Prop.radii;

	kbreak = (gint)(p1*n/(p1+p2));

	for(k=0;k<3;k++) K[k] =(GeomOrb[j].C[k]-GeomOrb[i].C[k])/(n*5.0/4);
	for(k=0;k<3;k++) A[k] =GeomOrb[i].C[k];
	for(i=0;i<n;i++)
	{
     		for(k=0;k<3;k++) B[k] = A[k] + K[k];
		if(i<=kbreak) Cylinder_Draw_Color(g,A,B,Specular1,Diffuse1,Ambiant1);
		else Cylinder_Draw_Color(g,A,B,Specular2,Diffuse2,Ambiant2);
     		for(k=0;k<3;k++) A[k] = B[k]+K[k]/4;
     }
}
/************************************************************************/
void draw_wireframe(int i,int j, int line)
{
	
	int k;
	V4d Specular1 = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse1  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant1  = {0.0f,0.0f,0.0f,1.0f};
	V4d Specular2 = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse2  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant2  = {0.0f,0.0f,0.0f,1.0f};
	V3d Center;
	GLfloat p1;
	GLfloat p2;
	GLfloat p;
		  
	glLineWidth(line);
	Specular1[0] = GeomOrb[i].Prop.color.red/(gfloat)65535;
	Specular1[1] = GeomOrb[i].Prop.color.green/(gfloat)65535;
	Specular1[2] = GeomOrb[i].Prop.color.blue/(gfloat)65535;

	Specular2[0] = GeomOrb[j].Prop.color.red/(gfloat)65535;
	Specular2[1] = GeomOrb[j].Prop.color.green/(gfloat)65535;
	Specular2[2] = GeomOrb[j].Prop.color.blue/(gfloat)65535;

	for(k=0;k<3;k++)
	{
		Diffuse1[k] = Specular1[k]*0.99;
		Diffuse2[k] = Specular2[k]*0.99;
	}
	for(k=0;k<3;k++)
	{
		Ambiant1[k] = Specular1[k]*0.9;
		Ambiant2[k] = Specular2[k]*0.9;
	}
	p1 = GeomOrb[i].Prop.covalentRadii+GeomOrb[i].Prop.radii;
	p2 = GeomOrb[j].Prop.covalentRadii+GeomOrb[j].Prop.radii;
	p = p1 + p2;

	Center[0] = (GeomOrb[i].C[0]*p2 + GeomOrb[j].C[0]*p1)/p;
	Center[1] = (GeomOrb[i].C[1]*p2 + GeomOrb[j].C[1]*p1)/p;
	Center[2] = (GeomOrb[i].C[2]*p2 + GeomOrb[j].C[2]*p1)/p;


	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant1);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,50);
	
	glBegin(GL_LINES);
	glVertex3f(GeomOrb[i].C[0],GeomOrb[i].C[1],GeomOrb[i].C[2]);
	glVertex3f(Center[0],Center[1],Center[2]);
	glEnd();


	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular2);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse2);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant2);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,50);

	glBegin(GL_LINES);
	glVertex3f(Center[0],Center[1],Center[2]);
	glVertex3f(GeomOrb[j].C[0],GeomOrb[j].C[1],GeomOrb[j].C[2]);
	glEnd();
	glLineWidth(1);

}
/************************************************************************/
void draw_bond(int i,int j,GLfloat scal)
{
	
	int k;
	GLfloat g;
	V4d Specular1 = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse1  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant1  = {0.0f,0.0f,0.0f,1.0f};
	V4d Specular2 = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse2  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant2  = {0.0f,0.0f,0.0f,1.0f};
	GLfloat aspect = scal;
	GLfloat p1;
	GLfloat p2;
	
	if(GeomOrb[i].Prop.radii<GeomOrb[j].Prop.radii) g = GeomOrb[i].Prop.radii*aspect;
	else g = GeomOrb[j].Prop.radii*aspect;
	  
	Specular1[0] = GeomOrb[i].Prop.color.red/(gfloat)65535;
	Specular1[1] = GeomOrb[i].Prop.color.green/(gfloat)65535;
	Specular1[2] = GeomOrb[i].Prop.color.blue/(gfloat)65535;

	Specular2[0] = GeomOrb[j].Prop.color.red/(gfloat)65535;
	Specular2[1] = GeomOrb[j].Prop.color.green/(gfloat)65535;
	Specular2[2] = GeomOrb[j].Prop.color.blue/(gfloat)65535;

	for(k=0;k<3;k++)
	{
		Diffuse1[k] = Specular1[k]*0.8;
		Diffuse2[k] = Specular2[k]*0.8;
	}
	for(k=0;k<3;k++)
	{
		Ambiant1[k] = Specular1[k]*0.5;
		Ambiant2[k] = Specular2[k]*0.5;
	}
	p1 = GeomOrb[i].Prop.covalentRadii+GeomOrb[i].Prop.radii;
	p2 = GeomOrb[j].Prop.covalentRadii+GeomOrb[j].Prop.radii;

	Cylinder_Draw_Color_Two(g,GeomOrb[i].C,GeomOrb[j].C,
				Specular1,Diffuse1,Ambiant1,
				Specular2,Diffuse2,Ambiant2,
				p1,p2);

}
/************************************************************************/
gint GeomDrawBallStick()
{
	int i;
	int j;
	  for(i = 0;i<Ncenters;i++)
	  {
		draw_ball(i,1.0);

		for(j=i+1;j<Ncenters;j++)
			if(draw_lines_yes_no_orb(i,j))
				draw_bond(i,j,1.0/3.0);
		        else
			if(ShowHBondOrb && draw_lines_hbond_yes_no_orb(i,j)) draw_hbond(i,j,1.0/5.0);


	  }

  return TRUE;
}
/************************************************************************/
gint GeomDrawSpaceFill()
{
	int i;
	  for(i = 0;i<Ncenters;i++)
		draw_space(i);

  return TRUE;
}
/************************************************************************/
static void draw_ball_for_stick(int i, GLfloat g)
{
	int k;
	V4d Specular = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant  = {0.0f,0.0f,0.0f,1.0f};
	  
	Specular[0] = GeomOrb[i].Prop.color.red/(gfloat)65535;
	Specular[1] = GeomOrb[i].Prop.color.green/(gfloat)65535;
	Specular[2] = GeomOrb[i].Prop.color.blue/(gfloat)65535;
	for(k=0;k<3;k++) Diffuse[k] = Specular[k]*0.8;
	for(k=0;k<3;k++) Ambiant[k] = Specular[k]*0.5;

	Sphere_Draw_Color(g,GeomOrb[i].C,Specular,Diffuse,Ambiant);
	Sphere_Draw_Color_Precision(g,GeomOrb[i].C,Specular,Diffuse,Ambiant, (GLint)openGLOptions.numberOfSubdivisionsCylindre);

}
/************************************************************************/
void draw_bond_for_stick(int i,int j,GLfloat g)
{
	
	int k;
	V4d Specular1 = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse1  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant1  = {0.0f,0.0f,0.0f,1.0f};
	V4d Specular2 = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse2  = {0.0f,0.0f,0.0f,1.0f};
	V4d Ambiant2  = {0.0f,0.0f,0.0f,1.0f};
	GLfloat p1;
	GLfloat p2;
	
	  
	Specular1[0] = GeomOrb[i].Prop.color.red/(gfloat)65535;
	Specular1[1] = GeomOrb[i].Prop.color.green/(gfloat)65535;
	Specular1[2] = GeomOrb[i].Prop.color.blue/(gfloat)65535;

	Specular2[0] = GeomOrb[j].Prop.color.red/(gfloat)65535;
	Specular2[1] = GeomOrb[j].Prop.color.green/(gfloat)65535;
	Specular2[2] = GeomOrb[j].Prop.color.blue/(gfloat)65535;

	for(k=0;k<3;k++)
	{
		Diffuse1[k] = Specular1[k]*0.8;
		Diffuse2[k] = Specular2[k]*0.8;
	}
	for(k=0;k<3;k++)
	{
		Ambiant1[k] = Specular1[k]*0.5;
		Ambiant2[k] = Specular2[k]*0.5;
	}
	p1 = GeomOrb[i].Prop.covalentRadii+GeomOrb[i].Prop.radii;
	p2 = GeomOrb[j].Prop.covalentRadii+GeomOrb[j].Prop.radii;

	Cylinder_Draw_Color_Two(g,GeomOrb[i].C,GeomOrb[j].C,
				Specular1,Diffuse1,Ambiant1,
				Specular2,Diffuse2,Ambiant2,
				p1,p2);

}
/************************************************************************/
gint GeomDrawStick()
{
	int i;
	int j;
	gboolean* Ok = NULL;
	GLfloat g = 0.2;
	if(Ncenters>0) Ok = g_malloc(Ncenters*sizeof(gboolean));
	for(i = 0;i<Ncenters;i++)
		Ok[i] = FALSE;
	
	for(i = 0;i<Ncenters;i++)
	{

		draw_ball_for_stick(i, g);
		for(j=i+1;j<Ncenters;j++)
			if(draw_lines_yes_no_orb(i,j))
			{
				draw_bond_for_stick(i, j, g);
				Ok[i] = TRUE;
				Ok[j] = TRUE;
			}
		        else
			if(ShowHBondOrb && draw_lines_hbond_yes_no_orb(i,j)) draw_hbond(i,j,0.15);

		if(!Ok[i]) draw_ball(i,0.2);


	}
	if(Ok) g_free(Ok);

	return TRUE;
}
/************************************************************************/
gint GeomDrawWireFrame()
{
	int i;
	int j;
	gboolean* Ok = NULL;

	if(Ncenters>0) Ok = g_malloc(Ncenters*sizeof(gboolean));

	for(i = 0;i<Ncenters;i++)
		Ok[i] = FALSE;
	
	for(i = 0;i<Ncenters;i++)
	{
		for(j=i+1;j<Ncenters;j++)
			if(draw_lines_yes_no_orb(i,j))
			{
				draw_wireframe(i,j, 5);
				Ok[i] = TRUE;
				Ok[j] = TRUE;
			}
			else
			if(ShowHBondOrb && draw_lines_hbond_yes_no_orb(i,j)) draw_wireframe(i,j,1);

		if(!Ok[i]) draw_ball(i,0.2);


	}
	if(Ok) g_free(Ok);
	glLineWidth(1);

	return TRUE;
}
/************************************************************************/
gint GeomDraw()
{
	switch(TypeGeom)
	{
	case GABEDIT_TYPEGEOM_BALLSTICK : return GeomDrawBallStick();
	case GABEDIT_TYPEGEOM_STICK : return GeomDrawStick();
	case GABEDIT_TYPEGEOM_SPACE: return GeomDrawSpaceFill();
	case GABEDIT_TYPEGEOM_WIREFRAME : return GeomDrawWireFrame();
	default: return GeomDrawBallStick();
	}
  return FALSE;
}
/************************************************************************/
GLuint GeomGenList(GLuint geomlist)
{
	if(!GeomOrb) return 0;
	if (glIsList(geomlist) == GL_TRUE) glDeleteLists(geomlist,1);
	geomlist = glGenLists(1);
	glNewList(geomlist, GL_COMPILE);
	GeomDraw();
	glEndList();
	return geomlist;
}
/************************************************************************/
void GeomShowList(GLuint geomlist)
{
	if(TypeGeom==GABEDIT_TYPEGEOM_NO) return;
	if (glIsList(geomlist) == GL_TRUE) glCallList(geomlist);
}
/************************************************************************/


