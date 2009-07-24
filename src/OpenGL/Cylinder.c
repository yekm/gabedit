/* Cylinder.c */
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
#include "GlobalOrb.h"
#include "../Utils/Vector3d.h"
#include "../Utils/Transformation.h"
#include "../Utils/Constants.h"

#define Deg_Rad 180.0/PI

/************************************************************************/
void rotated_vector(V3d v)
{
	V3d vz={0.0,0.0,1.0};
	V3d	vert;
	gfloat angle;


	v3d_cross(vz,v,vert);
	angle = acos(v3d_dot(vz,v)/v3d_length(v))*Deg_Rad;
	  
	if(fabs(angle)<1e-6)
		return;
	if(fabs(angle-180)<1e-6)
		glRotated(angle, 1.0, 0.0, 0.0);
	else
	glRotated(angle, vert[0],vert[1],vert[2]);

}
/************************************************************************/
void Cylinder_Draw(GLfloat radius,V3d Base1Pos,V3d Base2Pos)
{
		V3d Direction;
		GLUquadricObj *obj;
		glPushMatrix();
		glTranslated(Base1Pos[0],Base1Pos[1],Base1Pos[2]);
		Direction[0] = Base2Pos[0]-Base1Pos[0];
		Direction[1] = Base2Pos[1]-Base1Pos[1];
		Direction[2] = Base2Pos[2]-Base1Pos[2];

		rotated_vector(Direction);
		obj = gluNewQuadric();
		gluQuadricNormals(obj, GL_SMOOTH);
		gluQuadricDrawStyle(obj, GLU_FILL);
		gluCylinder (obj,radius,radius,v3d_length(Direction),(GLint)openGLOptions.numberOfSubdivisionsCylindre,1);
		gluDeleteQuadric(obj);
		glPopMatrix(); 
}

/************************************************************************/
void Cylinder_Draw_Color(GLfloat radius,V3d Base1Pos,V3d Base2Pos,
			 V4d Specular,V4d Diffuse,V4d Ambiant)
{
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,50);
	Cylinder_Draw(radius,Base1Pos,Base2Pos);
}
/************************************************************************/
void Cylinder_Draw_Color_Two(GLfloat radius,V3d Base1Pos,V3d Base2Pos,
			 V4d Specular1,V4d Diffuse1,V4d Ambiant1,
			 V4d Specular2,V4d Diffuse2,V4d Ambiant2,
			GLfloat p1,GLfloat p2)
{
	V3d Center;
	GLfloat p = p1 + p2;
	Center[0] = (Base1Pos[0]*p2 + Base2Pos[0]*p1)/p;
	Center[1] = (Base1Pos[1]*p2 + Base2Pos[1]*p1)/p;
	Center[2] = (Base1Pos[2]*p2 + Base2Pos[2]*p1)/p;
	Cylinder_Draw_Color(radius,Base1Pos,Center,Specular1,Diffuse1,Ambiant1);
	Cylinder_Draw_Color(radius,Center,Base2Pos,Specular2,Diffuse2,Ambiant2);
}
/************************************************************************/
