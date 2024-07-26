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

#ifndef __GABEDIT_GRID_H__
#define __GABEDIT_GRID_H__

typedef struct _Point5
{
	gfloat C[5];
}Point5;
typedef struct _GridLimits
{
	gfloat MinMax[2][4];
}GridLimits;

typedef struct _Grid
{
	gint N[3];
	Point5 ***point;
	GridLimits limits;
	gboolean mapped;
}Grid;
gdouble get_value_orbital(gfloat x,gfloat y,gfloat z,gint k);
gdouble get_value_electronic_density_on_atom(gfloat x,gfloat y,gfloat z,gint n);
gdouble get_value_electronic_density_atomic(gfloat x,gfloat y,gfloat z,gint dump);
gdouble get_value_electronic_density(gfloat x,gfloat y,gfloat z,gint dump);
gdouble get_value_electronic_density_bonds(gfloat x,gfloat y,gfloat z,gint dump);
gdouble get_value_spin_density(gfloat x,gfloat y,gfloat z,gint dump);
Grid* grid_point_alloc(gint N[],GridLimits limits);
Grid* define_grid(gint N[],GridLimits limits);
Grid* free_grid(Grid* grid);
GridLimits limits;
gint NumPoints[3];
gfloat firstDirection[3];
gfloat secondDirection[3];
gfloat thirdDirection[3];
gfloat originOfCube[3];
Grid* get_grid_laplacian(Grid* grid, gint nBoundary);
Grid* get_grid_norm_gradient(Grid* grid, gint nBoundary);

#endif /* __GABEDIT_GRID_H__ */

