/* MolcasGridIT.c */
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

#include <stdlib.h>

#include "../../Config.h"
#include "../Common/Global.h"
#include "../Molcas/MolcasTypes.h"
#include "../Molcas/MolcasGlobal.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/GeomConversion.h"
#include "../Utils/Utils.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Constantes.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/GabeditTextEdit.h"
#include "../Symmetry/MoleculeSymmetry.h"
#include "../Symmetry/MoleculeSymmetryInterface.h"

static MolcasGridIT molcasGridITTmp;
/************************************************************************************************************/
static void initMolcasGridIT(MolcasGridIT* mGridIt)
{
	mGridIt->ascii = TRUE;
	mGridIt->all = TRUE;
}
/************************************************************************************************************/
static void initMolcasGridITTmp()
{
	initMolcasGridIT(&molcasGridITTmp);
}
/************************************************************************************************************/
static void copyGridITParameters(MolcasGridIT* newCopy, MolcasGridIT* toCopy)
{
	newCopy->ascii = toCopy->ascii; 
	newCopy->all = toCopy->all;
}
/************************************************************************************************************/
static void putBeginGridITInTextEditor()
{

        gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.program, &molcasColorBack.program, "  &GRID_IT &END\n",-1);
}
/************************************************************************************************************/
static void putAsciiInTextEditor()
{
	if(!molcasGridIT.ascii) return;
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.program, NULL, "ASCII\n",-1);
}
/************************************************************************************************************/
static void putAllInTextEditor()
{
	if(!molcasGridIT.all) return;
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.program, NULL, "ALL\n",-1);
}
/************************************************************************************************************/
static void putEndGridITInTextEditor()
{

        gchar buffer[BSIZE];
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.program, &molcasColorBack.program, "End of input\n\n",-1);

	sprintf(buffer,"! cp $Project.M2Msi   $MOLCAS_SUBMIT_PWD/$Project.M2Msi\n");
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.shellCommand, &molcasColorBack.shellCommand, buffer, -1);
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, "\n\n", -1);
}
/************************************************************************************************************/
void putGridITInfoInTextEditor()
{

	initMolcasGridITTmp();
	initMolcasGridIT(&molcasGridIT);
	copyGridITParameters(&molcasGridIT, &molcasGridITTmp);
	putBeginGridITInTextEditor();
	putAsciiInTextEditor();
	putAllInTextEditor();
	putEndGridITInTextEditor();
}
/************************************************************************************************************/
