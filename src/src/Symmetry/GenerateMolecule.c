/* GenerateMolecule.c */
/**********************************************************************************************************
Copyright (c) 2002-2011 Abdul-Rahman Allouche. All rights reserved

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
#include <glib.h>
#include "../Symmetry/MoleculeSymmetryType.h"
#include "../Symmetry/MoleculeSymmetry.h"
#include "../Symmetry/SymmetryOperators.h"
#include "../Symmetry/ReduceMolecule.h"
#include "../Symmetry/ReducePolyHedralMolecule.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SQU(x,y,z) ((x)*(x) + (y)*(y) + (z)*(z))

/************************************************************************************************************/
/*
static void printAMolecule(MolSymMolecule* mol)
{

	gint i;
	MolSymAtom *atomList;
	atomList = mol->listOfAtoms;

	for (i=0;i<mol->numberOfAtoms;i++)
	{
		printf("%d %f %f %f\n",
		atomList->type ,
		atomList->position[0],
		atomList->position[1],
		atomList->position[2]
		      );
		atomList++;;
	}
}
*/
/************************************************************************************************************/
static gint freeAMolecule(MolSymMolecule* mol)
{

	gint i;
	if(mol->numberOfAtoms>0 && mol->listOfAtoms) g_free(mol->listOfAtoms);
	mol->listOfAtoms = NULL;
	mol->numberOfAtoms = 0;
	if(mol->numberOfDifferentKindsOfAtoms>0 && mol->symbol)
	{
		for(i=0;i<mol->numberOfDifferentKindsOfAtoms;i++)
			if( mol->symbol[i]) g_free(mol->symbol[i]);
		g_free(mol->symbol);
	}
	mol->symbol = NULL;
	if(mol->numberOfDifferentKindsOfAtoms>0 && mol->numberOfAtomsOfEachType) g_free(mol->numberOfAtomsOfEachType);
	mol->numberOfAtomsOfEachType = 0;
	if(mol->numberOfDifferentKindsOfAtoms>0 && mol->masse) g_free(mol->masse);
	mol->masse = 0;
	mol->numberOfDifferentKindsOfAtoms = 0;
	return 0;
}
/************************************************************************************************************/
static void removeEquivAtoms(MolSymMolecule* mol)
{
	gdouble eps = 1e-3;
	gint i;
	gint j;
	gint numberOfAtoms = mol->numberOfAtoms;
	gint deleted = mol->numberOfDifferentKindsOfAtoms;     /* tag for deleted atom */
	gdouble rr = 0;
	gdouble xx = 0;
	gdouble yy = 0;
	gdouble zz = 0;

	for(i=1;i<mol->numberOfAtoms;i++)
	{
		for(j=0;j<i;j++)
		{
			if(mol->listOfAtoms[i].type != deleted && mol->listOfAtoms[j].type == mol->listOfAtoms[i].type)
			{
				xx = mol->listOfAtoms[i].position[0] -  mol->listOfAtoms[j].position[0];
				yy = mol->listOfAtoms[i].position[1] -  mol->listOfAtoms[j].position[1];
				zz = mol->listOfAtoms[i].position[2] -  mol->listOfAtoms[j].position[2];
				eps = fabs( mol->listOfAtoms[i].eps +  mol->listOfAtoms[j].eps)/2;
				rr = SQU(xx,yy,zz);
				if(rr<eps*eps)
				{
					mol->listOfAtoms[j].type = deleted;
					numberOfAtoms--;
				}
			}
		}
	}
	qsort(mol->listOfAtoms,mol->numberOfAtoms,sizeof(MolSymAtom),compare2atoms);
	mol->numberOfAtoms = numberOfAtoms;
}
/************************************************************************************************************/
static gint copyAMolecule(MolSymMolecule* mol, MolSymMolecule* mol2Copy)
{

	gint i;
	MolSymAtom *atomList;
	MolSymAtom *tmpAtomList;

	if(mol->numberOfAtoms>0 && mol->listOfAtoms) g_free(mol->listOfAtoms);
	mol->listOfAtoms = NULL;
	if(mol2Copy->numberOfAtoms<1) return -1;

	mol->numberOfDifferentKindsOfAtoms = mol2Copy->numberOfDifferentKindsOfAtoms;

	if(mol->numberOfDifferentKindsOfAtoms>0 && mol->symbol)
	{
		for(i=0;i<mol->numberOfDifferentKindsOfAtoms;i++)
			if( mol->symbol[i]) g_free(mol->symbol[i]);
		g_free(mol->symbol);
	}
	mol->symbol = (gchar**)g_malloc(mol->numberOfDifferentKindsOfAtoms*sizeof(gchar*));

	if(mol->numberOfDifferentKindsOfAtoms>0 && mol->numberOfAtomsOfEachType) g_free(mol->numberOfAtomsOfEachType);
	mol->numberOfAtomsOfEachType = (gint*)g_malloc(mol->numberOfDifferentKindsOfAtoms*sizeof(gint));

	if(mol->numberOfDifferentKindsOfAtoms>0 && mol->masse) g_free(mol->masse);
	mol->masse = (gdouble*)g_malloc(mol->numberOfDifferentKindsOfAtoms*sizeof(gdouble));

	mol->numberOfAtoms=mol2Copy->numberOfAtoms;
	mol->listOfAtoms = (MolSymAtom*)g_malloc(mol->numberOfAtoms*sizeof(MolSymAtom));

	atomList = mol->listOfAtoms;
	tmpAtomList = mol2Copy->listOfAtoms;

	for (i=0;i<mol->numberOfAtoms;i++)
	{
		atomList->position[0] =  tmpAtomList->position[0];
		atomList->position[1] =  tmpAtomList->position[1];
		atomList->position[2] =  tmpAtomList->position[2];
		atomList->type = tmpAtomList->type;
		atomList->eps = tmpAtomList->eps;

		atomList++;;
		tmpAtomList++;
	}
	for (i=0;i<mol->numberOfDifferentKindsOfAtoms;i++)
	{
		mol->numberOfAtomsOfEachType[i] = mol2Copy->numberOfAtomsOfEachType[i];
		mol->symbol[i] = g_strdup(mol2Copy->symbol[i]);
		mol->masse[i] = mol2Copy->masse[i];
	}

	return 0;
}
/************************************************************************************************************/
static gint AddHalfSpace(MolSymMolecule* mol, RotationReflectionOperator op)
{
	gdouble eps = 1e-3;
	gint n;
	gint i;
	MolSymAtom *atomList;
	MolSymAtom *tmpAtomList;
	MolSymMolecule tmpMol;
	gint numberOfAtoms = 0;
	gchar** symbols = NULL;
	gdouble* masses = NULL;
	gint originalNumberOfAtoms = mol->numberOfAtoms;

	if(mol->numberOfAtoms >0) eps = mol->listOfAtoms[0].eps;


	tmpMol.numberOfAtoms=2*mol->numberOfAtoms;
	tmpMol.listOfAtoms = (MolSymAtom*)g_malloc(tmpMol.numberOfAtoms*sizeof(MolSymAtom));
	tmpMol.symbol = (gchar**)g_malloc(tmpMol.numberOfAtoms*sizeof(gchar*));
	tmpMol.numberOfAtomsOfEachType = (gint*)g_malloc(tmpMol.numberOfAtoms*sizeof(gint));
	tmpMol.masse = (gdouble*)g_malloc(tmpMol.numberOfAtoms*sizeof(gdouble));

	symbols = (gchar**)g_malloc(tmpMol.numberOfAtoms*sizeof(gchar*));
	masses = (gdouble*)g_malloc(tmpMol.numberOfAtoms*sizeof(gdouble));

	if (tmpMol.listOfAtoms == NULL) return -1;

	atomList = mol->listOfAtoms;
	tmpAtomList = tmpMol.listOfAtoms;

	/* copy molecule */
	numberOfAtoms = 0;
	for (n=0;n<mol->numberOfAtoms;n++)
	{
		numberOfAtoms++;
		tmpAtomList->position[0] =  atomList->position[0];
		tmpAtomList->position[1] =  atomList->position[1];
		tmpAtomList->position[2] =  atomList->position[2];
		tmpAtomList->type = atomList->type;
		tmpAtomList->eps = atomList->eps;
		symbols[numberOfAtoms-1] = g_strdup(mol->symbol[atomList->type]); 
		masses[numberOfAtoms-1] = mol->masse[atomList->type]; 

		atomList++;;
		tmpAtomList++;
	}

	atomList = mol->listOfAtoms;
	for (n=0;n<mol->numberOfAtoms;n++)
	{
		switch(op)
		{
			case XY_PLANE:
			tmpAtomList->position[0] =  atomList->position[0];
			tmpAtomList->position[1] =  atomList->position[1];
			tmpAtomList->position[2] = -atomList->position[2];
			numberOfAtoms++;
			symbols[numberOfAtoms-1] = g_strdup(mol->symbol[atomList->type]); 
			masses[numberOfAtoms-1] = mol->masse[atomList->type]; 
			tmpAtomList->type = atomList->type;
			tmpAtomList->eps = atomList->eps;
			atomList++;;
			tmpAtomList++;
			break;

			case XZ_PLANE:
			tmpAtomList->position[0] =  atomList->position[0];
			tmpAtomList->position[1] = -atomList->position[1];
			tmpAtomList->position[2] =  atomList->position[2];
			numberOfAtoms++;
			symbols[numberOfAtoms-1] = g_strdup(mol->symbol[atomList->type]); 
			masses[numberOfAtoms-1] = mol->masse[atomList->type]; 
			tmpAtomList->type = atomList->type;
			tmpAtomList->eps = atomList->eps;
			atomList++;;
			tmpAtomList++;
			break;

			case YZ_PLANE:
			tmpAtomList->position[0] = -atomList->position[0];
			tmpAtomList->position[1] = atomList->position[1];
			tmpAtomList->position[2] = atomList->position[2];
			numberOfAtoms++;
			symbols[numberOfAtoms-1] = g_strdup(mol->symbol[atomList->type]); 
			masses[numberOfAtoms-1] = mol->masse[atomList->type]; 
			tmpAtomList->type = atomList->type;
			tmpAtomList->eps = atomList->eps;
			atomList++;;
			tmpAtomList++;
			break;

			case POINT_INV:
			tmpAtomList->position[0] = -atomList->position[0];
			tmpAtomList->position[1] = -atomList->position[1];
			tmpAtomList->position[2] = -atomList->position[2];
			numberOfAtoms++;
			symbols[numberOfAtoms-1] = g_strdup(mol->symbol[atomList->type]); 
			masses[numberOfAtoms-1] = mol->masse[atomList->type]; 
			tmpAtomList->type = atomList->type;
			tmpAtomList->eps = atomList->eps;
			atomList++;;
			tmpAtomList++;
			break;

			case ROT2X:
			tmpAtomList->position[0] =  atomList->position[0];
			tmpAtomList->position[1] = -atomList->position[1];
			tmpAtomList->position[2] = -atomList->position[2];
			numberOfAtoms++;
			symbols[numberOfAtoms-1] = g_strdup(mol->symbol[atomList->type]); 
			masses[numberOfAtoms-1] = mol->masse[atomList->type]; 
			tmpAtomList->type = atomList->type;
			tmpAtomList->eps = atomList->eps;
			atomList++;;
			tmpAtomList++;
			break;

			case ROT2Y:
			tmpAtomList->position[0] = -atomList->position[0];
			tmpAtomList->position[1] =  atomList->position[1];
			tmpAtomList->position[2] = -atomList->position[2];
			numberOfAtoms++;
			symbols[numberOfAtoms-1] = g_strdup(mol->symbol[atomList->type]); 
			masses[numberOfAtoms-1] = mol->masse[atomList->type]; 
			tmpAtomList->type = atomList->type;
			tmpAtomList->eps = atomList->eps;
			atomList++;;
			tmpAtomList++;
			break;

			case ROT2Z:
			tmpAtomList->position[0] = -atomList->position[0];
			tmpAtomList->position[1] = -atomList->position[1];
			tmpAtomList->position[2] =  atomList->position[2];
			numberOfAtoms++;
			symbols[numberOfAtoms-1] = g_strdup(mol->symbol[atomList->type]); 
			masses[numberOfAtoms-1] = mol->masse[atomList->type]; 
			tmpAtomList->type = atomList->type;
			tmpAtomList->eps = atomList->eps;
			atomList++;;
			tmpAtomList++;
		}
	 }
	tmpMol.numberOfAtoms = numberOfAtoms;
	tmpAtomList = tmpMol.listOfAtoms;
      	tmpMol.numberOfDifferentKindsOfAtoms = 0;
	for(n=0; n<tmpMol.numberOfAtoms; n++)
	{
		i = 0;
      		for (i=0;i<tmpMol.numberOfDifferentKindsOfAtoms;i++) /* search symbol */
		{
	  		if ((strcmp(symbols[n],tmpMol.symbol[i]))==0)
	    		{
	      			tmpMol.numberOfAtomsOfEachType[i]++;
	      			break;      
	    		}
		}
      		if (i==tmpMol.numberOfDifferentKindsOfAtoms)
		{
			tmpMol.symbol[i] = g_strdup(symbols[n]);
			tmpMol.masse[i] = masses[n];
	  		tmpMol.numberOfAtomsOfEachType[i] = 1;
	  		tmpMol.numberOfDifferentKindsOfAtoms++;
		}
		tmpAtomList->type = i;
		tmpAtomList++;
	}

	/* printf("Avant remove\n"); printAMolecule(&tmpMol);*/
	removeEquivAtoms(&tmpMol);
	/* printf("Apres remove\n"); printAMolecule(&tmpMol);*/
	copyAMolecule(mol, &tmpMol);
	freeAMolecule(&tmpMol);

	if(symbols)
	{
		for(i=0; i<originalNumberOfAtoms*2; i++)
			if(symbols[i]) g_free(symbols[i]);
	       	g_free(symbols);
	}
	if(masses) g_free(masses);
 
	return 0;
}
/************************************************************************************************************/
void generateMoleculeFromTheBasisSetOfAtoms(MolSymMolecule* mol, gint numberOfElements, gchar** elements)
{
	gint i;
	if(numberOfElements<2) return;
	for(i=1 ; i<numberOfElements ; i++)
	{
		if(!strcmp(elements[i],"C2z")) AddHalfSpace(mol, ROT2Z);
		if(!strcmp(elements[i],"C2y")) AddHalfSpace(mol, ROT2Y);
		if(!strcmp(elements[i],"C2x")) AddHalfSpace(mol, ROT2X);
		if(!strcmp(elements[i],"i")) AddHalfSpace(mol, POINT_INV);
		if(!strcmp(elements[i],"Sigma")) AddHalfSpace(mol, XY_PLANE);
		if(!strcmp(elements[i],"Sigma v")) AddHalfSpace(mol, XZ_PLANE);
		if(!strcmp(elements[i],"Sigma' v")) AddHalfSpace(mol, YZ_PLANE);
		if(!strcmp(elements[i],"Sigma h")) AddHalfSpace(mol, XY_PLANE);
		if(!strcmp(elements[i],"Sigma xy")) AddHalfSpace(mol, XY_PLANE);
		if(!strcmp(elements[i],"Sigma xz")) AddHalfSpace(mol, XZ_PLANE);
		if(!strcmp(elements[i],"Sigma yz")) AddHalfSpace(mol, YZ_PLANE);
	}
}
