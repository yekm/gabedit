/* SemiEmpiricalModel.c */
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
#include <stdlib.h>
#include <math.h>

#include "../Common/Global.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/Utils.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "AtomSE.h"
#include "MoleculeSE.h"
#include "SemiEmpiricalModel.h"
void create_GeomXYZ_from_draw_grometry();

/**********************************************************************/
SemiEmpiricalModel newSemiEmpiricalModel(gchar* method, gchar* dirName)
{
	SemiEmpiricalModel seModel;

	seModel.molecule = newMoleculeSE();

	seModel.klass = g_malloc(sizeof(SemiEmpiricalModelClass));
	seModel.klass->calculateGradient = NULL;
	seModel.klass->calculateEnergy = NULL;


	seModel.method = NULL;
	if(method) seModel.method = g_strdup(method);
	if(dirName) seModel.workDir = g_strdup(dirName);
	else seModel.workDir = g_strdup_printf("%s%stmp",gabedit_directory(),G_DIR_SEPARATOR_S);
	return seModel;

}
/**********************************************************************/
void freeSemiEmpiricalModel(SemiEmpiricalModel* seModel)
{

	freeMoleculeSE(&seModel->molecule);

	if(seModel->klass != NULL)
	{
		g_free(seModel->klass);
		seModel->klass = NULL;
	}
	if(seModel->method != NULL)
	{
		g_free(seModel->method);
		seModel->method = NULL;
	}
	if(seModel->workDir != NULL)
	{
		g_free(seModel->workDir);
		seModel->workDir = NULL;
	}
}
/*****************************************************************************/
SemiEmpiricalModel copySemiEmpiricalModel(SemiEmpiricalModel* f)
{
	SemiEmpiricalModel seModel = newSemiEmpiricalModel(NULL,NULL);

	seModel.molecule = copyMoleculeSE(&f->molecule);
	seModel.method = NULL;
	if(f->method) seModel.method = g_strdup(f->method);
	seModel.workDir = NULL;
	if(f->workDir) seModel.workDir = g_strdup(f->workDir);

	seModel.klass->calculateGradient = f->klass->calculateGradient;
	seModel.klass->calculateEnergy = f->klass->calculateEnergy;

	return seModel;
}
