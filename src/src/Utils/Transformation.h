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

#ifndef __GABEDIT_TRANSFORMATION_H__
#define __GABEDIT_TRANSFORMATION_H__

typedef gfloat V4d[4];
gfloat *v4d_pvect(V4d v1,V4d v2);
gfloat v4d_pscal(V4d v1,V4d v2);
gfloat* v4d_scal(V4d v1,gfloat scal);
gfloat v4d_length(V4d v);
void v4d_normal(V4d v);
void trackball(gfloat q[4],gfloat p1x,gfloat p1y,gfloat p2x,gfloat p2y);
void add_quats(gfloat q1[4],gfloat q2[4],gfloat dest[4]);
void build_rotmatrix(gfloat m[4][4],gfloat q[4]);
gfloat** Inverse(gfloat **mat,gint size,gfloat error);
gfloat** Inverse3(gfloat **mat);

#endif /* __GABEDIT_TRANSFORMATION_H__ */

