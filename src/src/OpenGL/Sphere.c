/* Sphere.c */
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

static GLfloat emission[] = { 0.0, 0.0, 0.0, 1.0 };
/************************************************************************************************************/
void Sphere_Draw_Precision(GLfloat radius,V3d position, GLint numberOfSubdivisions)
{
	GLUquadricObj *obj;
	
	glPushMatrix();
	glTranslated(position[0],position[1],position[2]);
    	obj = gluNewQuadric();
	gluQuadricNormals(obj, GL_SMOOTH);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluSphere(obj, radius, numberOfSubdivisions*2, numberOfSubdivisions);

	gluDeleteQuadric(obj);
	glTranslated(-position[0],-position[1],-position[2]);
	glPopMatrix(); 
}
/************************************************************************************************************/
void Sphere_Draw_Color_Precision(GLfloat radius,V3d position, V4d Specular,V4d Diffuse,V4d Ambiant, GLint numberOfSubdivisions)
{
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,100);
	Sphere_Draw_Precision(radius,position, numberOfSubdivisions);
}
/************************************************************************************************************/
void Sphere_Draw(GLfloat radius,V3d position)
{
	GLUquadricObj *obj;
	
	glPushMatrix();
	glTranslated(position[0],position[1],position[2]);
    	obj = gluNewQuadric();
	gluQuadricNormals(obj, GL_SMOOTH);
	gluQuadricDrawStyle(obj, GLU_FILL);
	gluSphere(obj, radius, (GLint)openGLOptions.numberOfSubdivisionsSphere, (GLint)openGLOptions.numberOfSubdivisionsSphere);

	gluDeleteQuadric(obj);
	glTranslated(-position[0],-position[1],-position[2]);
	glPopMatrix(); 
}
/************************************************************************************************************/
void Sphere_Draw_Color(GLfloat radius,V3d position, V4d Specular,V4d Diffuse,V4d Ambiant)
{
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Specular);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Ambiant);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,100);
	Sphere_Draw(radius,position);

}
/************************************************************************************************************/
GLuint Sphere_Get_List(int i,GLfloat radius,V4d Specular,V4d Diffuse,V4d Ambiant)
{
	
	GLuint sphere;
	V3d position={0,0,0};
	
	
    sphere = glGenLists(i);
	glNewList(sphere, GL_COMPILE);
	Sphere_Draw_Color(radius,position,Specular,Diffuse,Ambiant);
	glEndList();
	return sphere;
}
/************************************************************************************************************/
void Sphere_Draw_From_List(GLuint sphere,V3d position)
{
	glPushMatrix();
	glTranslated(position[0],position[1],position[2]);
	if (glIsList(sphere) == GL_TRUE) 
		glCallList(sphere);
	else
		printf("Erreur de list\n");

	
	glPopMatrix();
}

