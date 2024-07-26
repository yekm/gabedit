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

#ifndef __GABEDIT_BONDS_H__
#define __GABEDIT_BONDS_H__

typedef enum
{
  GABEDIT_BONDTYPE_SINGLE = 0,
  GABEDIT_BONDTYPE_DOUBLE,
  GABEDIT_BONDTYPE_TRIPLE,
  GABEDIT_BONDTYPE_HYDROGEN,
} GabEditBondType;
typedef struct _BondType BondType;
struct _BondType
{
	gint n1;
	gint n2;
	GabEditBondType bondType;
};
GList *BondsOrb;
void buildBondsOrb();
void buildMultipleBonds();
void buildHBonds();
void readBondsPDB(FILE* file);
void readBondsHIN(FILE* file);
#endif /* __GABEDIT_BONDS_H__ */

