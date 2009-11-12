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
#ifndef __GABEDIT_MOLECULESYMMETRY_H__
#define __GABEDIT_MOLECULESYMMETRY_H__

int computeSymmetry(
		gdouble principalAxisToterance, gboolean axz_3, gchar* pointGroupeSymbol,
		gint maximalOrder, gboolean redu,
	       	gint* numberOfAtoms, gchar** symbols, gdouble* X, gdouble* Y, gdouble* Z, gdouble* eps, gchar* message);
int computeAbelianGroup(
		gdouble principalAxisTolerance, gchar* pointGroupSymbol, gchar* abelianPointGroupSymbol,
		gint maximalOrder, gboolean redu,
	       	gint* numberOfAtoms, 
		gchar** symbols, gdouble* X, gdouble* Y, gdouble* Z, 
		gint* nGenerators,
		gchar** generators,
		gint* nMolcas,
		gchar** molcasGenerators,
		gint* nElements,
		gchar** elements,
		gdouble* precision, gchar* message);
int generateMoleculeUsingAbelianGroup(
		gchar* abelianPointGroupSymbol,
	       	gint* numberOfAtoms, 
		gchar*** symbols, gdouble** X, gdouble** Y, gdouble** Z
		);

#endif /* __GABEDIT_MOLECULESYMMETRY_H__ */

