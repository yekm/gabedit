/* ForceField.c */
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
#include "../../Config.h"
#include <stdlib.h>
#include <math.h>

#include "../Common/Global.h"
#include "../Utils/AtomsProp.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "Atom.h"
#include "Molecule.h"
#include "ForceField.h"
void create_GeomXYZ_from_draw_grometry();

/**********************************************************************/
ForceField newForceField()
{
	gint i;
	ForceField forceField;

	forceField.molecule = newMolecule();

	forceField.klass = g_malloc(sizeof(ForceFieldClass));
	forceField.klass->calculateGradient = NULL;
	forceField.klass->calculateEnergy = NULL;
	forceField.klass->calculateEnergyTmp = NULL;


	forceField.numberOfStretchTerms = 0;
	forceField.numberOfBendTerms = 0;
	forceField.numberOfDihedralTerms = 0;
	forceField.numberOfImproperTorsionTerms = 0;
	forceField.numberOfNonBonded = 0;
	forceField.numberOfHydrogenBonded = 0;

	for(i=0;i<STRETCHDIM;i++)
		forceField.bondStretchTerms[i] = NULL;
	for(i=0;i<BENDDIM;i++)
		forceField.angleBendTerms[i] = NULL;
	for(i=0;i<DIHEDRALDIM;i++)
		forceField.dihedralAngleTerms[i] = NULL;
	for(i=0;i<IMPROPERDIHEDRALDIM;i++)
		forceField.improperTorsionTerms[i] = NULL;
	for(i=0;i<NONBONDEDDIM;i++)
		forceField.nonBondedTerms[i] = NULL;
	for(i=0;i<HYDROGENBONDEDDIM;i++)
		forceField.hydrogenBondedTerms[i] = NULL;

	forceField.numberOfPairWise = 0;
	for(i=0;i<PAIRWISEDIM;i++)
		forceField.pairWiseTerms[i] = NULL;

	forceField.options.type = AMBER;
	forceField.options.coulomb = TRUE;
	forceField.options.hydrogenBonded = TRUE;
	forceField.options.improperTorsion = TRUE;
	forceField.options.vanderWals = TRUE;
	return forceField;

}
/**********************************************************************/
void freeForceField(ForceField* forceField)
{

	gint i;
	freeMolecule(&forceField->molecule);

	if(forceField->klass != NULL)
	{
		g_free(forceField->klass);
		forceField->klass = NULL;
	}
	for(i=0;i<STRETCHDIM;i++)
		if(forceField->bondStretchTerms[i] !=NULL)
		{
			g_free(forceField->bondStretchTerms[i]);
			forceField->bondStretchTerms[i] = NULL;
		}
	for(i=0;i<BENDDIM;i++)
		if(forceField->angleBendTerms[i] != NULL)
		{
			g_free(forceField->angleBendTerms[i]);
			forceField->angleBendTerms[i] = NULL;
		}
	for(i=0;i<DIHEDRALDIM;i++)
		if(forceField->dihedralAngleTerms[i] != NULL)
		{
			g_free(forceField->dihedralAngleTerms[i]);
			forceField->dihedralAngleTerms[i] = NULL;
		}
	for(i=0;i<IMPROPERDIHEDRALDIM;i++)
		if(forceField->improperTorsionTerms[i] != NULL)
		{
			g_free(forceField->improperTorsionTerms[i]);
			forceField->improperTorsionTerms[i] = NULL;
		}
	for(i=0;i<NONBONDEDDIM;i++)
		if(forceField->nonBondedTerms[i] != NULL)
		{
			g_free(forceField->nonBondedTerms[i]);
			forceField->nonBondedTerms[i] = NULL;
		}
	for(i=0;i<HYDROGENBONDEDDIM;i++)
		if(forceField->hydrogenBondedTerms[i] != NULL)
		{
			g_free(forceField->hydrogenBondedTerms[i]);
			forceField->hydrogenBondedTerms[i] = NULL;
		}

	forceField->numberOfStretchTerms = 0;
	forceField->numberOfBendTerms = 0;
	forceField->numberOfDihedralTerms = 0;
	forceField->numberOfImproperTorsionTerms = 0;
	forceField->numberOfNonBonded = 0;
	forceField->numberOfHydrogenBonded = 0;

	for(i=0;i<PAIRWISEDIM;i++)
		if(forceField->pairWiseTerms[i] != NULL)
		{
			g_free(forceField->pairWiseTerms[i]);
			forceField->pairWiseTerms[i] = NULL;
		}
	forceField->numberOfPairWise = 0;
}
/*****************************************************************************/
