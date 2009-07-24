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

#ifndef __GABEDIT_CYLINDER_H__
#define __GABEDIT_CYLINDER_H__

void Cylinder_Draw(GLfloat radius,V3d Base1Pos,V3d Base2Pos);
void Cylinder_Draw_Color(GLfloat radius,V3d Base1Pos,V3d Base2Pos,
						 V4d Specular,V4d Diffuse,V4d Ambiant);
void Cylinder_Draw_Color_Two(GLfloat radius,V3d Base1Pos,V3d Base2Pos,
			 V4d Specular1,V4d Diffuse1,V4d Ambiant1,
			 V4d Specular2,V4d Diffuse2,V4d Ambiant2,
			GLfloat p1, GLfloat p2);

#endif /* __GABEDIT_CYLINDER_H__ */
