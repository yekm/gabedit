/**********************************************************************************************************
Copyright (c) 2002-2010 Abdul-Rahman Allouche. All rights reserved

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

#ifndef __GABEDIT_SPHERE_H__
#define __GABEDIT_SPHERE_H__


void Sphere_Draw_Precision(GLdouble radius,V3d position, GLint numberOfSubdivisions);
void Sphere_Draw_Color_Precision(GLdouble radius,V3d position, V4d Specular,V4d Diffuse,V4d Ambiant, GLint numberOfSubdivisions);

void Sphere_Draw(GLdouble radius,V3d position);
void Sphere_Draw_Color(GLdouble radius,V3d position, V4d Specular,V4d Diffuse,V4d Ambiant);

GLuint Sphere_Get_List(int i,GLdouble radius,V4d Specular,V4d Diffuse,V4d Ambiant);
void Sphere_Draw_From_List(GLuint sphere,V3d position);

#endif /* __GABEDIT_SPHERE_H__ */

