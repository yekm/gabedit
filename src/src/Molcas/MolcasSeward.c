/* MolcasSeward.c */
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
#include <ctype.h>

#include "../../Config.h"
#include "../Common/Global.h"
#include "../Molcas/MolcasTypes.h"
#include "../Molcas/MolcasGlobal.h"
#include "../Molcas/MolcasBasis.h"
#include "../Molcas/MolcasScf.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/GeomConversion.h"
#include "../Geometry/GeomXYZ.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Utils/Utils.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Constantes.h"
#include "../Geometry/InterfaceGeom.h"
#include "../Common/Windows.h"
#include "../Utils/Constantes.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/GabeditTextEdit.h"
#include "../Symmetry/MoleculeSymmetry.h"
#include "../Symmetry/MoleculeSymmetryInterface.h"

/************************************************************************************************************/
/* 0-> Witout symmetry ; 
 * 1-> with symmetry */
static gint typeOfSymmetry[] = { 0,1};

static gboolean symReduction = TRUE;

static GtkWidget* labelSymmetry = NULL;
static GtkWidget *buttonTolerance = NULL;
static GtkWidget *buttonView = NULL;
static GtkWidget *buttonBasis = NULL;
/************************************************************************************************************/
void initSewardButtons()
{
	labelSymmetry = NULL;
	buttonTolerance = NULL;
	buttonView = NULL;
}
/************************************************************************************************************/
void initMolcasMolecule()
{
	gint i;

	molcasMolecule.listOfAtoms = NULL;  
	molcasMolecule.totalNumberOfElectrons = 0;
	molcasMolecule.numberOfValenceElectrons = 0;
	molcasMolecule.numberOfAtoms = 0;
	molcasMolecule.numberOfDifferentKindsOfAtoms=0;
	molcasMolecule.symbol = NULL;
	molcasMolecule.groupSymbol = NULL;
	molcasMolecule.numberOfAtomsOfEachType = NULL;
	molcasMolecule.numberOfAtomsOfEachTypeForAllAtoms = NULL;
	molcasMolecule.numberOfMolcasGenerators = 0;
	for(i=0; i<3; i++)
		molcasMolecule.molcasGenerators[i] = NULL;
	molcasMolecule.basis = NULL;
}
/************************************************************************************************************/
void freeMolcasMolecule()
{
	gint i;
	static gboolean first = TRUE;

	if(first)
	{
		initMolcasMolecule();
		first = FALSE;
		return;
	}

	if(molcasMolecule.listOfAtoms) g_free(molcasMolecule.listOfAtoms);
	molcasMolecule.numberOfAtoms = 0;
	if(molcasMolecule.groupSymbol)
		g_free(molcasMolecule.groupSymbol);

	if(molcasMolecule.symbol)
	{
		for(i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms; i++)
			if(molcasMolecule.symbol[i]) g_free(molcasMolecule.symbol[i]);

		g_free(molcasMolecule.symbol);
	}
	if(molcasMolecule.numberOfAtomsOfEachType ) g_free(molcasMolecule.numberOfAtomsOfEachType);
	if(molcasMolecule.numberOfAtomsOfEachTypeForAllAtoms ) g_free(molcasMolecule.numberOfAtomsOfEachTypeForAllAtoms);
	for(i=0; i<3; i++)
		if(molcasMolecule.molcasGenerators[i]) g_free(molcasMolecule.molcasGenerators[i]);
	if(molcasMolecule.basis)
	{
		for(i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms; i++)
			if(molcasMolecule.basis[i]) g_free(molcasMolecule.basis[i]);

		g_free(molcasMolecule.basis);
	}
	initMolcasMolecule();
}
/************************************************************************************************************/
static gint setMolcasMoleculeDefaultBasis()
{
	gint i;

	if(molcasMolecule.numberOfDifferentKindsOfAtoms<1) return 0;
	molcasMolecule.basis = g_malloc(molcasMolecule.numberOfDifferentKindsOfAtoms*sizeof(gchar*));

      	for (i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms;i++)
	      	molcasMolecule.basis[i] = g_strdup_printf("%s.sto-3g....",molcasMolecule.symbol[i]);
	return 0;
}
/************************************************************************************************************/
static void removePointFromString(gchar* buffer, gchar* buffer2)
{
	gint len;
	gint k;
	gint i;

	len = strlen(buffer);
	k = 0;
	for(i=0; i<len; i++)
	{
		if(buffer[i]!='.')
		{
			buffer2[k] = buffer[i];
			k++;
		}
		else
		{
			if(i<len-1 && buffer[i+1]=='.')
			{
				buffer2[k] = ' ';
				k++;
				buffer2[k] = 'U';
				k++;
				buffer2[k] = 'N';
				k++;
				buffer2[k] = 'K';
				k++;
			}
			else
			{
				buffer2[k] = ' ';
				k++;
			}
		}
	}
	buffer2[k] = '\0';
}
/************************************************************************************************************/
gint resetNumberOfValenceElectrons()
{
	gint i;
	gint n;
	gchar symbol[BSIZE];
	gchar type[BSIZE];
	gchar pseudo[BSIZE];
	gchar* dump[3];
	gchar buffer[BSIZE];
	gchar buffer2[BSIZE];
	SAtomsProp prop;

      	for (i=0;i<3;i++)
		dump[i] = g_malloc(BSIZE*sizeof(gchar));

	if(molcasMolecule.basis)
	{
		molcasMolecule.numberOfValenceElectrons = molcasMolecule.totalNumberOfElectrons;
      		for (i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms;i++)
		{
			sprintf(buffer,"%s",molcasMolecule.basis[i]);
			removePointFromString(buffer,buffer2);
			n = sscanf(buffer2,"%s %s %s %s %s %s",symbol,type,dump[0],dump[1],dump[2],pseudo);
			if(n==6 && strcmp(type,"ECP")==0)
			{
				gint nElectrons = atoi(pseudo);
				prop = prop_atom_get(symbol);

				molcasMolecule.numberOfValenceElectrons += nElectrons*molcasMolecule.numberOfAtomsOfEachTypeForAllAtoms[i];
				molcasMolecule.numberOfValenceElectrons -= prop.atomicNumber*molcasMolecule.numberOfAtomsOfEachTypeForAllAtoms[i];
			}
		}
	}
	activateScfEntryType();
      	for (i=0;i<3;i++)
		g_free(dump[i]);
	return 0;
}
/************************************************************************************************************/
static gint setnumberOfAtomsOfEachTypeForAllAtomsFromGeomXYZ()
{
	gint i;
	gint n;

	molcasMolecule.numberOfAtomsOfEachTypeForAllAtoms = (gint*)g_malloc(sizeof(gint)*(molcasMolecule.numberOfAtoms));
	if(molcasMolecule.numberOfAtomsOfEachTypeForAllAtoms == NULL) return -1;

      	for (i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms;i++)
		molcasMolecule.numberOfAtomsOfEachTypeForAllAtoms[i] = 0;

	for(n=0; n<(gint)NcentersXYZ; n++)
	{
      		for (i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms;i++)
		{
	  		if ((strcmp(GeomXYZ[n].Symb,molcasMolecule.symbol[i]))==0)
	    		{
	      			molcasMolecule.numberOfAtomsOfEachTypeForAllAtoms[i]++;
	      			break;
	    		}
		}
	}

	return 0;
}
/************************************************************************************************************/
static gint setMolcasMoleculeFromSXYZ(gint nAtoms, gchar** symbols, gdouble* X, gdouble* Y, gdouble* Z)
{
	gint i;
	gint n;
	MolcasAtom* atomList = NULL;

	molcasMolecule.listOfAtoms = NULL;  
	molcasMolecule.numberOfAtoms = 0;
	molcasMolecule.numberOfDifferentKindsOfAtoms=0;
	molcasMolecule.symbol = NULL;
	molcasMolecule.numberOfAtomsOfEachType = NULL;

	molcasMolecule.listOfAtoms = (MolcasAtom*)g_malloc(sizeof(MolcasAtom)*(nAtoms));
	if(molcasMolecule.listOfAtoms==NULL) return -1;

	molcasMolecule.numberOfAtoms = nAtoms;

	molcasMolecule.symbol = (gchar**)g_malloc(sizeof(gchar*)*(molcasMolecule.numberOfAtoms));
	if( molcasMolecule.symbol == NULL) return -1;
	for(n=0; n<molcasMolecule.numberOfAtoms; n++) molcasMolecule.symbol[n] = NULL;

	molcasMolecule.numberOfAtomsOfEachType = (gint*)g_malloc(sizeof(gint)*(molcasMolecule.numberOfAtoms));
	if(molcasMolecule.numberOfAtomsOfEachType == NULL) return -1;

	atomList = molcasMolecule.listOfAtoms;
	for(n=0; n<molcasMolecule.numberOfAtoms; n++)
	{
		atomList->position[0]  = X[n];
		atomList->position[1]  = Y[n];
		atomList->position[2]  = Z[n];
		i = 0;
      		for (i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms;i++) /* search symbol */
		{
	  		if ((strcmp(symbols[n],molcasMolecule.symbol[i]))==0)
	    		{
	      			molcasMolecule.numberOfAtomsOfEachType[i]++;
	      			break;      
	    		}
		}
      		if (i==molcasMolecule.numberOfDifferentKindsOfAtoms)
		{
			molcasMolecule.symbol[i] = g_strdup(symbols[n]);
	  		molcasMolecule.numberOfAtomsOfEachType[i] = 1;
	  		molcasMolecule.numberOfDifferentKindsOfAtoms++;
		}
		atomList->type = i;
		atomList++;
	}
	/*
	atomList = molcasMolecule.listOfAtoms;
	for(n=0; n<molcasMolecule.numberOfAtoms; n++)
	{
		printf("TODEL %s %f %f %f\n",
			molcasMolecule.symbol[atomList->type],
			atomList->position[0], 
		       	atomList->position[1],  
			atomList->position[2]);
		atomList++;
	}
	*/

	return 0;
}
/************************************************************************************************************/
static void setXYZFromGeomXYZ(gint i, gdouble* x, gdouble* y, gdouble *z)
{
  	if(!test(GeomXYZ[i].X))
    		*x = get_value_variableXYZ(GeomXYZ[i].X);
  	else
    		*x = atof(GeomXYZ[i].X);
  	if(!test(GeomXYZ[i].Y))
    		*y = get_value_variableXYZ(GeomXYZ[i].Y);
  	else
    		*y = atof(GeomXYZ[i].Y);
  	if(!test(GeomXYZ[i].Z))
    		*z = get_value_variableXYZ(GeomXYZ[i].Z);
  	else
    		*z = atof(GeomXYZ[i].Z);

         if(Units==0)
         {
              *x *= BOHR_TO_ANG;
              *y *= BOHR_TO_ANG;
              *z *= BOHR_TO_ANG;
         }
}
/************************************************************************************************************/
static gboolean setMolcasMoleculeFromGeomXYZ()
{
	gint i;
	gchar** symbols = NULL;
	gdouble* X = NULL;
	gdouble* Y = NULL;
	gdouble* Z = NULL;
	gint numberOfAtoms = NcentersXYZ;
	gchar pointGroupSymbol[BSIZE];
	gchar abelianPointGroupSymbol[BSIZE];
	gchar message[BSIZE];
	gint maximalOrder = 20;
	gint nGenerators;
	gint nMolcas = 0;
	gint nElements;
	gchar* generators[3];
	gchar* molcasGenerators[3];
	gchar* elements[8];
	gdouble principalAxisTolerance = getTolerancePrincipalAxis();
	gdouble positionTolerance = getTolerancePosition();

	if(numberOfAtoms<1) return FALSE;

	for(i=0;i<3;i++)
	{
		generators[i] = g_malloc(100*sizeof(gchar));
		molcasGenerators[i] = g_malloc(100*sizeof(gchar));
	}
	for(i=0;i<8;i++)
		elements[i] = g_malloc(100*sizeof(gchar));

	symbols = (gchar**)g_malloc(sizeof(gchar*)*(numberOfAtoms));
	if(symbols == NULL) return FALSE;

	X = (gdouble*)g_malloc(sizeof(gdouble)*(numberOfAtoms));
	if(X == NULL) return FALSE;
	Y = (gdouble*)g_malloc(sizeof(gdouble)*(numberOfAtoms));
	if(Y == NULL) return FALSE;
	Z = (gdouble*)g_malloc(sizeof(gdouble)*(numberOfAtoms));
	if(Z == NULL) return FALSE;

	molcasMolecule.totalNumberOfElectrons = 0;
	for(i=0; i<numberOfAtoms; i++)
	{
		SAtomsProp prop = prop_atom_get(GeomXYZ[i].Symb);

		symbols[i] = g_strdup(GeomXYZ[i].Symb);
		setXYZFromGeomXYZ(i, &X[i] , &Y[i] , &Z[i]);
		molcasMolecule.totalNumberOfElectrons += prop.atomicNumber;
	}
	molcasMolecule.numberOfValenceElectrons = molcasMolecule.totalNumberOfElectrons;
	if(symReduction)
	computeAbelianGroup(principalAxisTolerance, pointGroupSymbol, abelianPointGroupSymbol, maximalOrder, symReduction,
	       	&numberOfAtoms, symbols, X, Y, Z, 
		&nGenerators, generators, &nMolcas, molcasGenerators, &nElements, elements, &positionTolerance, message);

	setMolcasMoleculeFromSXYZ(numberOfAtoms, symbols, X, Y, Z);

	if(symReduction)
		molcasMolecule.groupSymbol = g_strdup(abelianPointGroupSymbol);
	else
		molcasMolecule.groupSymbol = g_strdup("Sorry, No Symmetry");

	molcasMolecule.numberOfMolcasGenerators = nMolcas;
	for(i=0; i<nMolcas; i++)
	         molcasMolecule.molcasGenerators[i] = g_strdup(molcasGenerators[i]);

	for(i=0;i<3;i++)
	{
		g_free(generators[i]);
		g_free(molcasGenerators[i]);
	}
	for(i=0;i<8;i++)
		g_free(elements[i]);

	for (i=0;i<(gint)NcentersXYZ;i++) g_free( symbols[i]);
	g_free( symbols);
	g_free(X);
	g_free(Y);
	g_free(Z);
	setMolcasMoleculeDefaultBasis();
	setnumberOfAtomsOfEachTypeForAllAtomsFromGeomXYZ();
	return TRUE;
}
/************************************************************************************************************/
static gboolean setMolcasMoleculeFromGeomZMatrix()
{
	conversion_zmat_to_xyz();
	return setMolcasMoleculeFromGeomXYZ();
}
/************************************************************************************************************/
gboolean setMolcasMolecule()
{
	freeMolcasMolecule();
	if(setMolcasMoleculeFromGeomXYZ()) return TRUE;
	if(setMolcasMoleculeFromGeomZMatrix()) return TRUE;
	return FALSE;
}
/************************************************************************************************************/
static void setGeneratorsAndAbelianGroup(gchar* groupName,
		gint* nGenerators, gchar** generators, 
		gint* nMolcas, gchar** molcasGenerators, 
		gint* nElements, gchar** elements
		)
{

	int i;

	for (i=0;i<*nMolcas; i++) g_strup(molcasGenerators[i]);

	if(*nMolcas == 0)
	{
		sprintf(groupName,"C1");
		*nGenerators = 0;
		*nElements = 0;
		return;
	}
	if(*nMolcas == 3)
	{
		sprintf(groupName,"D2h");

		*nGenerators = 3;
		sprintf(generators[0],"C2z");
		sprintf(generators[1],"C2y");
		sprintf(generators[2],"i");
			
		*nElements = 8;
		sprintf(elements[0],"E");
		sprintf(elements[1],"C2z");
		sprintf(elements[2],"C2y");
		sprintf(elements[3],"C2x");
		sprintf(elements[4],"i");
		sprintf(elements[5],"Sigma xy");
		sprintf(elements[6],"Sigma xz");
		sprintf(elements[7],"Sigma yz");
		return;
	}
	if(*nMolcas == 1)
	{
		if(strstr(molcasGenerators[0],"XYZ"))
		{
			sprintf(groupName,"Ci");

			*nGenerators = 1;
			sprintf(generators[0],"i");

			*nElements = 2;
			sprintf(elements[0],"E");
			sprintf(elements[1],"i");
			return;
		}
		else
		if(strstr(molcasGenerators[0],"XY"))
		{
			sprintf(groupName,"C2");

			*nGenerators = 1;
			sprintf(generators[0],"C2z");

			*nElements = 2;
			sprintf(elements[0],"E");
			sprintf(elements[1],"C2");
			return;
		}
		else
		if(strstr(molcasGenerators[0],"X"))
		{
			sprintf(groupName,"Cs");
			*nGenerators = 1;
			sprintf(generators[0],"Sigma");

			*nElements = 2;
			sprintf(elements[0],"E");
			sprintf(elements[1],"Sigma");
			return;
		}
		else
		{
			sprintf(groupName,"C1");
			*nGenerators = 0;
			*nElements = 0;
			*nMolcas = 0;
		}
	}
	if(*nMolcas == 2)
	{
		if(strstr(molcasGenerators[0],"XY") && strstr(molcasGenerators[1],"XYZ"))
		{
			sprintf(groupName,"C2h");

			*nGenerators = 2;
			sprintf(generators[0],"C2z");
			sprintf(generators[1],"i");

			*nElements = 4;
			sprintf(elements[0],"E");
			sprintf(elements[1],"C2z");
			sprintf(elements[2],"i");
			sprintf(elements[3],"Sigma h");
			return;
		}
		else
		if(strstr(molcasGenerators[0],"XY") && strstr(molcasGenerators[1],"Y"))
		{
			sprintf(groupName,"C2v");

			*nGenerators = 2;
			sprintf(generators[0],"C2z");
			sprintf(generators[1],"Sigma v");

			*nElements = 4;
			sprintf(elements[0],"E");
			sprintf(elements[1],"C2z");
			sprintf(elements[2],"Sigma v");
			sprintf(elements[3],"Sigma' v");
			return;
		}
		else
		if(strstr(molcasGenerators[0],"XY") && strstr(molcasGenerators[1],"XZ"))
		{
			sprintf(groupName,"D2");

			*nGenerators = 2;
			sprintf(generators[0],"C2z");
			sprintf(generators[1],"C2y");

			*nElements = 4;
			sprintf(elements[0],"E");
			sprintf(elements[1],"C2z");
			sprintf(elements[2],"C2y");
			sprintf(elements[3],"C2z");
			return;
		}
		else
		if(*nMolcas == 0)
		{
			sprintf(groupName,"C1");
			*nGenerators = 0;
			*nElements = 0;
			*nMolcas = 0;
			return;
		}
	}
}
/************************************************************************************************************/
static gint setSymbolsXYZFromMolcasMolecule(gchar** symbols, gdouble* X, gdouble* Y, gdouble* Z)
{
	gchar symb[BSIZE];
	gint i;

	if(molcasMolecule.numberOfAtoms<1) return 0;

	for(i=0;i<molcasMolecule.numberOfAtoms;i++)
	{
		sprintf(symb,"%s",molcasMolecule.symbol[molcasMolecule.listOfAtoms[i].type]);
		symbols[i] = g_strdup(symb);
		X[i]=molcasMolecule.listOfAtoms[i].position[0];
		Y[i]=molcasMolecule.listOfAtoms[i].position[1];
		Z[i]=molcasMolecule.listOfAtoms[i].position[2];
	}
	return molcasMolecule.numberOfAtoms;
}
/************************************************************************************************************/
static gboolean setGeomXYZFromSXYZ(gint numberOfAtoms, gchar** symbols, gdouble* X, gdouble* Y, gdouble* Z)
{
	gint i;

	if(numberOfAtoms<1) return FALSE;

 	if(GeomXYZ) freeGeomXYZ();
 	if(VariablesXYZ) freeVariablesXYZ(VariablesXYZ);

	Dipole.def = FALSE;
	GeomXYZ=g_malloc(numberOfAtoms*sizeof(GeomXYZAtomDef));

	for(i=0;i<numberOfAtoms;i++)
	{
		GeomXYZ[i].Nentry=NUMBER_LIST_XYZ;
		GeomXYZ[i].Symb=g_strdup(symbols[i]);
		GeomXYZ[i].Type=g_strdup(symbols[i]);
		GeomXYZ[i].Residue=g_strdup(symbols[i]);
		GeomXYZ[i].ResidueNumber=0;
		if(Units==1)
		{
			GeomXYZ[i].X=g_strdup_printf("%f",X[i]);
			GeomXYZ[i].Y=g_strdup_printf("%f",Y[i]);
			GeomXYZ[i].Z=g_strdup_printf("%f",Z[i]);
		}
		else
		{
			GeomXYZ[i].X=g_strdup_printf("%f",X[i]*ANG_TO_BOHR);
			GeomXYZ[i].Y=g_strdup_printf("%f",Y[i]*ANG_TO_BOHR);
			GeomXYZ[i].Z=g_strdup_printf("%f",Z[i]*ANG_TO_BOHR);
		}
		GeomXYZ[i].Charge=g_strdup("0.0");
		GeomXYZ[i].Layer=g_strdup(" ");
	}
	NcentersXYZ = numberOfAtoms;
	MethodeGeom = GEOM_IS_XYZ;

	if(GeomIsOpen)
	{
		create_geomXYZ_interface (GABEDIT_TYPEFILEGEOM_UNKNOWN);
	}
	if(ZoneDessin != NULL)
		rafresh_drawing();

	return TRUE;
}
/************************************************************************************************************/
static gboolean setGeomXYZFromMolcasMolecule()
{
	gint i;
	gchar symb[BSIZE];

	if(molcasMolecule.numberOfAtoms<1) return FALSE;
	if(molcasMolecule.numberOfMolcasGenerators != 0) return FALSE;

 	if(GeomXYZ) freeGeomXYZ();
 	if(VariablesXYZ) freeVariablesXYZ(VariablesXYZ);
	Dipole.def = FALSE;
	GeomXYZ=g_malloc(molcasMolecule.numberOfAtoms*sizeof(GeomXYZAtomDef));
	for(i=0;i<molcasMolecule.numberOfAtoms;i++)
	{
		sprintf(symb,"%s",molcasMolecule.symbol[molcasMolecule.listOfAtoms[i].type]);
		GeomXYZ[i].Nentry=NUMBER_LIST_XYZ;
		GeomXYZ[i].Symb=g_strdup(symb);
		GeomXYZ[i].Type=g_strdup(symb);
		GeomXYZ[i].Residue=g_strdup(symb);
		GeomXYZ[i].ResidueNumber=0;
		if(Units==1)
		{
			GeomXYZ[i].X=g_strdup_printf("%f",molcasMolecule.listOfAtoms[i].position[0]);
			GeomXYZ[i].Y=g_strdup_printf("%f",molcasMolecule.listOfAtoms[i].position[1]);
			GeomXYZ[i].Z=g_strdup_printf("%f",molcasMolecule.listOfAtoms[i].position[2]);
		}
		else
		{
			GeomXYZ[i].X=g_strdup_printf("%f",molcasMolecule.listOfAtoms[i].position[0]*ANG_TO_BOHR);
			GeomXYZ[i].Y=g_strdup_printf("%f",molcasMolecule.listOfAtoms[i].position[1]*ANG_TO_BOHR);
			GeomXYZ[i].Z=g_strdup_printf("%f",molcasMolecule.listOfAtoms[i].position[2]*ANG_TO_BOHR);
		}
		GeomXYZ[i].Charge=g_strdup("0.0");
		GeomXYZ[i].Layer=g_strdup(" ");
	}
	NcentersXYZ = molcasMolecule.numberOfAtoms;
	MethodeGeom = GEOM_IS_XYZ;

	if(GeomIsOpen)
	{
		create_geomXYZ_interface (GABEDIT_TYPEFILEGEOM_UNKNOWN);
	}
	if(ZoneDessin != NULL)
		rafresh_drawing();

	return TRUE;
}
/************************************************************************************************************/
static gboolean testMolcasGeometryAvailableInInputFile(gchar* fileName)
{
	gchar t[BSIZE];
	FILE* file = NULL;
	gboolean Ok = FALSE;
	gboolean OkSewardKeyWord = FALSE;
	gboolean OkBasisKeyWord = FALSE;
	gboolean OkEndBasisKeyWord = FALSE;
	gboolean OkEndInputKeyWord = FALSE;

	file = FOpen(fileName, "r");
	if(!file) return FALSE;

	while(!feof(file))
	{
		if(!fgets(t, BSIZE, file)) break;
		g_strup(t);
		if( strstr(t, "&SEWARD") && strstr(t, "&END")) OkSewardKeyWord = TRUE;
		if(OkSewardKeyWord)
		{
			while(!feof(file))
			{
				if(!fgets(t, BSIZE, file)) break;
				g_strup(t);
				if( strstr(t, "BASIS") && strstr(t, "SET"))
				{
					OkBasisKeyWord = TRUE;
					OkEndBasisKeyWord = FALSE;
				}
				if( strstr(t, "END") && strstr(t, "OF") && strstr(t, "INPUT")) OkEndInputKeyWord = TRUE;
				if( strstr(t, "END") && strstr(t, "OF") && strstr(t, "BASIS"))
				{
					if(OkBasisKeyWord)
					{
						OkBasisKeyWord = FALSE;
				       		OkEndBasisKeyWord = TRUE;
					}
					else
						break;
				}
				if( strstr(t, "&END"))
				{
					Ok = FALSE;
					break;
				}
			}
			if(OkSewardKeyWord && OkEndBasisKeyWord && OkEndInputKeyWord) Ok = TRUE;
			break;
		}
	}
	fclose(file);
	return Ok;
}
/************************************************************************************************************/
static gchar** getMolcasGeometryListOfAtomsFromInputFile(gchar* fileName, 
		gint* numberOfAtoms, 
		gint**  basisNumber, 
		gint* numberOfBasis, 
		gchar*** listOfBasis, 
		gint* numberOfMolcasGenerators, gchar* molcasGenerators[])
{
	gchar t[BSIZE];
	FILE* file = NULL;
	gboolean Ok = FALSE;
	gboolean OkSewardKeyWord = FALSE;
	gint nAtoms = 0;
	gint nBas = 0;
	gchar** listOfAtoms = NULL;
	long sewardPos = 0;
	gint i;

	*numberOfBasis = 0;
	*listOfBasis = NULL;
	*numberOfAtoms = 0;
	*numberOfMolcasGenerators = 0;
	*basisNumber = NULL;

#ifdef G_OS_WIN32 
 	file = FOpen(fileName, "rb");
#else
	file = FOpen(fileName, "r");
#endif
	if(!file) return listOfAtoms;
	while(!feof(file))
	{
		if(!fgets(t, BSIZE, file)) { Ok = FALSE; break;}
		g_strup(t);
		if( strstr(t, "&SEWARD") && strstr(t, "&END"))
		{
			OkSewardKeyWord = TRUE;
			sewardPos = ftell(file);
		}
		if(OkSewardKeyWord)
		{
			Ok = TRUE;
			while(Ok && !feof(file) && ( ! (strstr(t,"END") && strstr(t,"OF") && strstr(t,"INPUT")) ) )
			{
				if(!fgets(t, BSIZE, file)){Ok = FALSE; break;}
				g_strup(t);
				if(strstr(t, "SYMMETRY"))
				{
					if(!fgets(t, BSIZE, file)){ Ok = FALSE; break;}
					*numberOfMolcasGenerators = sscanf(t,"%s %s %s",
							molcasGenerators[0], molcasGenerators[1],molcasGenerators[2]);
				}
				if( strstr(t, "BASIS") && strstr(t, "SET"))
				{
					if(!fgets(t, BSIZE, file)){ Ok = FALSE; break;} /* Basis Name */
					nBas++;
					*listOfBasis = g_realloc(*listOfBasis, nBas*sizeof(gchar*));
					str_delete_n(t);
					(*listOfBasis)[nBas-1] = g_strdup(t);

					while(!feof(file))
					{
						if(!fgets(t, BSIZE, file)){ Ok = FALSE; break;}
						g_strup(t);
						if(strstr(t,"END") && strstr(t,"OF") && strstr(t,"BASIS")) break;

						nAtoms++;
						listOfAtoms = g_realloc(listOfAtoms, nAtoms*sizeof(gchar*));
						str_delete_n(t);
						listOfAtoms[nAtoms-1]  = g_strdup(t);

						*basisNumber = g_realloc(*basisNumber, nAtoms*sizeof(gint));
						(*basisNumber)[nAtoms-1]  = nBas-1;
					}
				}
			}
			break;
		}
	}
	if(!Ok && nAtoms > 0)
	{
		if(listOfAtoms)
		{
			for(i=0 ; i<nAtoms; i++)
				if(listOfAtoms[i]) g_free(listOfAtoms[i]);
			g_free(listOfAtoms);
		}
		listOfAtoms = NULL;
		nAtoms = 0;
		if(*listOfBasis)
		{
			for(i=0 ; i<nBas; i++)
				if((*listOfBasis)[i]) g_free((*listOfBasis)[i]);
			g_free((*listOfBasis));
		}
		if(*basisNumber)
			g_free((*basisNumber));
		*basisNumber = NULL;
		nBas = 0;
		*numberOfMolcasGenerators = 0;
	}
	*numberOfAtoms = nAtoms;
	*numberOfBasis = nBas;
	fclose(file);
	return listOfAtoms;
}
/************************************************************************************************************/
static gint setMolcasMoleculeFromListOfAtoms(
		gint numberOfAtoms, gchar** listOfAtoms,gint* basisNumber,
	        gint numberOfBasis, gchar** listOfBasis,
		gint numberOfMolcasGenerators, gchar* molcasGenerators[])
{
	gint i;
	gint n;
	MolcasAtom* atomList = NULL;
	gchar symb[5];

	molcasMolecule.listOfAtoms = NULL;  
	molcasMolecule.numberOfAtoms = 0;
	molcasMolecule.numberOfDifferentKindsOfAtoms=0;
	molcasMolecule.symbol = NULL;
	molcasMolecule.numberOfAtomsOfEachType = NULL;

	molcasMolecule.listOfAtoms = (MolcasAtom*)g_malloc(sizeof(MolcasAtom)*(numberOfAtoms));
	if(molcasMolecule.listOfAtoms==NULL) return -1;

	molcasMolecule.numberOfAtoms = numberOfAtoms;

	molcasMolecule.symbol = (gchar**)g_malloc(sizeof(gchar*)*(molcasMolecule.numberOfAtoms));
	if( molcasMolecule.symbol == NULL) return -1;
	for(n=0; n<molcasMolecule.numberOfAtoms; n++) molcasMolecule.symbol[n] = NULL;

	molcasMolecule.numberOfAtomsOfEachType = (gint*)g_malloc(sizeof(gint)*(molcasMolecule.numberOfAtoms));
	if(molcasMolecule.numberOfAtomsOfEachType == NULL) return -1;

	molcasMolecule.numberOfDifferentKindsOfAtoms = numberOfBasis;


	atomList = molcasMolecule.listOfAtoms;
	for(n=0; n<molcasMolecule.numberOfAtoms; n++)
	{
		molcasMolecule.symbol[basisNumber[n]] = g_malloc(BSIZE*sizeof(gchar));
		sscanf(listOfAtoms[n],"%s %lf %lf %lf",
				symb,
				&(atomList->position[0]), 
				&(atomList->position[1]), 
				&(atomList->position[2]));
		if(!strstr(listOfAtoms[n],"/ANG"))
		{
				atomList->position[0] *= BOHR_TO_ANG;
				atomList->position[1] *= BOHR_TO_ANG; 
				atomList->position[2] *= BOHR_TO_ANG; 
		}

		atomList->type = basisNumber[n];
		atomList++;
		for(i=0;i<(gint)strlen(symb);i++)
			if(isdigit(symb[i])) symb[i] = ' ';

		delete_all_spaces(symb);
		for(i=1;i<(gint)strlen(symb);i++)
			symb[i] = tolower(symb[i]);

		molcasMolecule.symbol[basisNumber[n]] = g_strdup(symb);
	}
      	for (i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms;i++)
	{
	      	molcasMolecule.numberOfAtomsOfEachType[i] = 0;
		for(n=0;n<numberOfAtoms; n++)
		{
	 		if (i==basisNumber[n])
	      			molcasMolecule.numberOfAtomsOfEachType[i]++;
		}
	}
	if(molcasMolecule.numberOfDifferentKindsOfAtoms<1) return 0;

	molcasMolecule.basis = g_malloc(molcasMolecule.numberOfDifferentKindsOfAtoms*sizeof(gchar*));

      	for (i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms;i++)
	      	molcasMolecule.basis[i] = g_strdup(listOfBasis[i]);

	resetNumberOfValenceElectrons();

	 molcasMolecule.numberOfMolcasGenerators = numberOfMolcasGenerators;
	 for(i=0; i<molcasMolecule.numberOfMolcasGenerators; i++)
	 	molcasMolecule.molcasGenerators[i] = g_strdup(molcasGenerators[i]);
	
	 /*
	atomList = molcasMolecule.listOfAtoms;
	for(n=0; n<molcasMolecule.numberOfAtoms; n++)
	{
		printf("TODEL %s %f %f %f\n",
			molcasMolecule.symbol[atomList->type],
			atomList->position[0], 
		       	atomList->position[1],  
			atomList->position[2]);
		atomList++;
	}

	printf("TODEL SYMMETRY : ");
	for(n=0; n<molcasMolecule.numberOfMolcasGenerators; n++)
		printf("%s ",molcasMolecule.molcasGenerators[n]);
	printf("\n");
	*/

	return 0;
}
/************************************************************************************************************/
void setMolcasGeometryFromInputFile(gchar* fileName)
{
	gboolean available = testMolcasGeometryAvailableInInputFile(fileName);
	gchar** listOfAtoms = NULL;
	gint numberOfAtoms = 0;
	gint numberOfBasis = 0;
	gchar** listOfBasis = NULL;
	gint* basisNumber = NULL;

	gint numberOfMolcasGenerators = 0;
	gchar* molcasGenerators[3];

	gint numberOfGenerators = 0;
	gchar* generators[3];

	gint numberOfElements = 0;
	gchar* elements[8];

	gchar groupName[BSIZE];

	gint i;


	if(!available)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not read geometry from %s file",fileName);
		Message(buffer,"Warning",TRUE);
		return;
	}

	for(i=0;i<3;i++) molcasGenerators[i] = g_malloc(BSIZE*sizeof(gchar));
	for(i=0;i<3;i++) generators[i] = g_malloc(BSIZE*sizeof(gchar));
	for(i=0;i<8;i++) elements[i] = g_malloc(BSIZE*sizeof(gchar));

	listOfAtoms = getMolcasGeometryListOfAtomsFromInputFile(fileName, &numberOfAtoms,&basisNumber, 
			&numberOfBasis, &listOfBasis,
			&numberOfMolcasGenerators, molcasGenerators);

	/* print All  */
	/*
	printf("TODEL : nAtoms = %d nBas = %d\n",numberOfAtoms, numberOfBasis);
	printf("TODEL Basis List\n");
	for(i=0;i<numberOfBasis;i++)
		printf("TODEL : %s\n",listOfBasis[i]);
	printf("\nTODEL Atom List\n");
	for(i=0;i<numberOfAtoms;i++)
		printf("TODEL : %s Basis Number = %d \n",listOfAtoms[i], basisNumber[i]);
		*/

	if(numberOfAtoms>0)
	{
		freeMolcasMolecule();
		setMolcasMoleculeFromListOfAtoms(
				numberOfAtoms, listOfAtoms, basisNumber, 
				numberOfBasis,listOfBasis, 
				numberOfMolcasGenerators, molcasGenerators);
		/*
		printf("numberOfMolcasGenerators = %d\n",numberOfMolcasGenerators);
		for(i=0;i<numberOfMolcasGenerators;i++)
			printf("%s\n",molcasGenerators[i]);
			*/
	}

	setGeneratorsAndAbelianGroup(groupName,
		&numberOfGenerators, generators, 
		&numberOfMolcasGenerators, molcasGenerators, 
		&numberOfElements, elements);

	/*
	printf("groupName = %s\n",groupName);
	*/

	if(numberOfMolcasGenerators==0)
	{
		setGeomXYZFromMolcasMolecule();
	}
	else
	if(molcasMolecule.numberOfAtoms>0)
	{
		gchar** symbols = g_malloc(molcasMolecule.numberOfAtoms*sizeof(gchar*));
		gdouble* X = g_malloc(molcasMolecule.numberOfAtoms*sizeof(gdouble));
		gdouble* Y = g_malloc(molcasMolecule.numberOfAtoms*sizeof(gdouble));
		gdouble* Z = g_malloc(molcasMolecule.numberOfAtoms*sizeof(gdouble));
		gint numberOfAtoms = molcasMolecule.numberOfAtoms;

		setSymbolsXYZFromMolcasMolecule(symbols,X,Y, Z);

		generateMoleculeUsingAbelianGroup(groupName, &numberOfAtoms, &symbols, &X, &Y, &Z);

		/*
		printf("Molecule generate Using groupe Symmetry\n");
		for(i=0;i<numberOfAtoms;i++)
		{
			printf("%s %f %f %f\n",symbols[i], X[i], Y[i], Z[i]);
		}
		*/

		setGeomXYZFromSXYZ(numberOfAtoms, symbols, X, Y, Z);
		if(symbols)
		{
			for(i=0;i<numberOfAtoms; i++)
				if(symbols[i]) g_free(symbols[i]);
			g_free(symbols);
		}
		if(X) g_free(X);
		if(Y) g_free(Y);
		if(Z) g_free(Z);
	}
	setnumberOfAtomsOfEachTypeForAllAtomsFromGeomXYZ();

	/* free All local variable */
	for(i=0;i<3;i++) if( molcasGenerators[i]) g_free( molcasGenerators[i]);
	for(i=0;i<3;i++) if( generators[i]) g_free( generators[i]);
	for(i=0;i<8;i++) if( elements[i]) g_free( elements[i]);

	if(listOfAtoms)
	{
		for(i=0 ; i<numberOfAtoms; i++)
			if(listOfAtoms[i]) g_free(listOfAtoms[i]);
		g_free(listOfAtoms);
	}
	if(listOfBasis)
	{
		for(i=0 ; i<numberOfBasis; i++)
			if(listOfBasis[i]) g_free(listOfBasis[i]);
		g_free(listOfBasis);
	}
	if(basisNumber)
		g_free(basisNumber);

}
/**************************************************************************************************************************************/
static void activateRadioButton(GtkWidget *button, gpointer data)
{
	gint* type = NULL;
	GtkWidget* label = NULL;
	gchar buffer[BSIZE];
	 
	if(!GTK_IS_WIDGET(button)) return;

	type  = g_object_get_data(G_OBJECT (button), "Type");
	label = g_object_get_data(G_OBJECT (button), "Label");
	if(type)
	{
		if(*type == typeOfSymmetry[0]) symReduction = FALSE;
		if(*type == typeOfSymmetry[1]) symReduction = TRUE;
		setMolcasMolecule();

		if(label) gtk_label_set_text(GTK_LABEL(label)," ");
		if(buttonTolerance && symReduction ) gtk_widget_set_sensitive(buttonTolerance, TRUE);
		if(buttonTolerance && !symReduction ) gtk_widget_set_sensitive(buttonTolerance, FALSE);

		if(buttonView) gtk_widget_set_sensitive(buttonView, TRUE);
		/*
		if(buttonView && symReduction ) gtk_widget_set_sensitive(buttonView, TRUE);
		if(buttonView && !symReduction ) gtk_widget_set_sensitive(buttonView, FALSE);
		*/

		if(label && symReduction)
		{
			sprintf(buffer,"%s group",molcasMolecule.groupSymbol);
			gtk_label_set_text(GTK_LABEL(label),buffer);
		}

		/*
		if(label && symReduction)
		{
			if(molcasMolecule.numberOfMolcasGenerators<1)
				gtk_label_set_text(GTK_LABEL(label)," No Symmetry detected");
			else
			{
				gint i;
				gchar buffer1[BSIZE];
				gchar buffer2[BSIZE];
				sprintf(buffer,"Generators : ");
				for(i=0; i<molcasMolecule.numberOfMolcasGenerators; i++)
				{
					sprintf(buffer1,"%s", buffer);
					sprintf(buffer2,"%s", molcasMolecule.molcasGenerators[i]);
					g_strup(buffer2);
					if(i!=0)
						sprintf(buffer," %s, %s", buffer1, buffer2);
					else
						sprintf(buffer," %s %s", buffer1, buffer2);
						
				}
				printf("buff = %s\n",buffer);
				gtk_label_set_text(GTK_LABEL(label),buffer);
			}
		}
		*/

	}
}
/************************************************************************************************************/
static GtkWidget* addRadioButtonToATable(GtkWidget* table, GtkWidget* friendButton, gchar* label, gint i, gint j, gint k)
{
	GtkWidget *newButton;

	if(friendButton)
		newButton = gtk_radio_button_new_with_label( gtk_radio_button_get_group (GTK_RADIO_BUTTON (friendButton)), label);
	else
		newButton = gtk_radio_button_new_with_label( NULL, label);

	gtk_table_attach(GTK_TABLE(table),newButton,j,j+k,i,i+1,
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
                  3,3);

	g_object_set_data(G_OBJECT (newButton), "Label",NULL);
	g_object_set_data(G_OBJECT (newButton), "Type",NULL);
	return newButton;
}
/**************************************************************************************************************************************/
static void resetTolerance(GtkWidget *win)
{
	gchar buffer[BSIZE];

	setMolcasMolecule();
	if(labelSymmetry)
	{
		sprintf(buffer,"%s group",molcasMolecule.groupSymbol);
		gtk_label_set_text(GTK_LABEL(labelSymmetry),buffer);
	}
}
/**************************************************************************************************************************************/
static void activateToleranceButton(GtkWidget *button, gpointer data)
{
	if(!GTK_IS_WIDGET(button)) return;
	createToleranceWindow(molcasWin, resetTolerance);
}
/************************************************************************************************************/
static void putInfoInTextWidget(GtkWidget* textWid)
{
        gchar buffer[BSIZE];
	MolcasAtom* atomList = NULL;
	gint i;
	gint k;
	gint n;
	gdouble principalAxisTolerance = getTolerancePrincipalAxis();
	gdouble positionTolerance = getTolerancePosition();

	/* if(molcasMolecule.numberOfMolcasGenerators<1) return;*/
	if(molcasMolecule.numberOfAtoms<1) return;

	sprintf(buffer,"Group symbol = %s\n",molcasMolecule.groupSymbol);
        gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer, -1);

	sprintf(buffer,"Tolerance for principal axis classification : %0.5f\n",principalAxisTolerance);
 	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL,buffer,-1);   


	if(positionTolerance<0)
		sprintf(buffer,"Precision for atom position : Min distance between atoms\n\n");
	else
		sprintf(buffer,"Precision for atom position : %0.5f\n\n",positionTolerance);

 	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer,-1);   

	sprintf(buffer,"Total number of electrons : %d\n\n",molcasMolecule.totalNumberOfElectrons);
 	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL,buffer,-1);   

	sprintf(buffer,"================================================================\n");
        gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer,-1);

        gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, &molcasColorFore.program, NULL, "Generators : ",-1);
	if(molcasMolecule.numberOfMolcasGenerators==0)
        	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, "Notting", -1);
	
      	for (i=0;i<molcasMolecule.numberOfMolcasGenerators;i++)
	{
		sprintf(buffer,"%s ",molcasMolecule.molcasGenerators[i]);
		g_strup(buffer);
        	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer, -1);
	}
        gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, "\n",-1);

	sprintf(buffer,"================================================================\n");
        gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer,-1);

	atomList = molcasMolecule.listOfAtoms;
      	for (i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms;i++)
	{

		sprintf(buffer,"Type n %d\n",i+1);
        	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer, -1);
		sprintf(buffer,"Basis = %s\n",molcasMolecule.basis[i]);
        	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer, -1);

		sprintf(buffer,"Number of atoms (without reduction ) for %s = %d \n",
				molcasMolecule.symbol[i], 
				molcasMolecule.numberOfAtomsOfEachTypeForAllAtoms[i]);
        	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer, -1);
		sprintf(buffer,"Number of atoms (with reduction ) for %s = %d \n",
				molcasMolecule.symbol[i], 
				molcasMolecule.numberOfAtomsOfEachType[i]);
        	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer, -1);
        	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, "\n\n", -1);

		n = 1;
		for(k=0; k<molcasMolecule.numberOfAtoms; k++)
		{
			if(atomList[k].type == i)
			{
				
				sprintf(buffer,"%s%d %f %f %f /Angstrom\n",molcasMolecule.symbol[i], n, 
						atomList[k].position[0], atomList[k].position[1], atomList[k].position[2]);
			
        			gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer, -1);
				n++;
			}
		}
		sprintf(buffer,"----------------------------------------------------------------\n");
        	gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer,-1);
	}
	sprintf(buffer,"================================================================\n");
        gabedit_text_insert (GABEDIT_TEXT(textWid), NULL, NULL, NULL, buffer,-1);
}
/************************************************************************************************************/
static void createBasisWindow(GtkWidget* win, gpointer data)
{

	GtkWidget* winBasis = createMolcasBasisWindow();
	if(GTK_IS_WIDGET(win))
		gtk_window_set_transient_for(GTK_WINDOW(winBasis),GTK_WINDOW(win));
	gtk_window_set_modal (GTK_WINDOW (winBasis), TRUE);
	gtk_window_set_position(GTK_WINDOW(winBasis),GTK_WIN_POS_CENTER);
}
/************************************************************************************************************/
static void createViewInfoAbelianGroupWindow(GtkWidget* win, gpointer data)
{
	GtkWidget *Dialogue = NULL;
	GtkWidget *Bouton;
	GtkWidget *frame;
	GtkWidget *TextWid;
	gchar * title = NULL;
	 
	if(molcasMolecule.numberOfAtoms<1)
	{
		 Message("Sorry Number of atoms is not positive","Error",TRUE);
		 return;
	}
	Dialogue = gtk_dialog_new();
	gtk_widget_realize(GTK_WIDGET(Dialogue));
	title = g_strdup("Point group, abelian point group & Geometry with reduction (using abelian group)");
			
	gtk_window_set_title(GTK_WINDOW(Dialogue),title);

	gtk_window_set_modal (GTK_WINDOW (Dialogue), TRUE);
	gtk_window_set_position(GTK_WINDOW(Dialogue),GTK_WIN_POS_CENTER);

	g_signal_connect(G_OBJECT(Dialogue), "delete_event", (GtkSignalFunc)destroy_button_windows, NULL);
	g_signal_connect(G_OBJECT(Dialogue), "delete_event", (GtkSignalFunc)gtk_widget_destroy, NULL);

	TextWid = create_text_widget(GTK_WIDGET(GTK_DIALOG(Dialogue)->vbox),NULL,&frame);
	gabedit_text_set_editable(GABEDIT_TEXT(TextWid), TRUE);

	gtk_box_set_homogeneous (GTK_BOX( GTK_DIALOG(Dialogue)->action_area), FALSE);

	Bouton = create_button(Dialogue,"OK");
	gtk_box_pack_end (GTK_BOX( GTK_DIALOG(Dialogue)->action_area), Bouton, FALSE, TRUE, 5);	
	GTK_WIDGET_SET_FLAGS(Bouton, GTK_CAN_DEFAULT);
	gtk_widget_grab_default(Bouton);
	g_signal_connect_swapped(G_OBJECT(Bouton), "clicked", (GtkSignalFunc)destroy_button_windows, GTK_OBJECT(Dialogue));
	g_signal_connect_swapped(G_OBJECT(Bouton), "clicked", (GtkSignalFunc)gtk_widget_destroy, GTK_OBJECT(Dialogue));

	add_button_windows(title,Dialogue);

	putInfoInTextWidget(TextWid);

	gtk_window_set_default_size (GTK_WINDOW(Dialogue), ScreenWidth/2, ScreenHeight/2);
	gtk_widget_show_all(Dialogue);
	g_free(title);
	if(GTK_IS_WIDGET(win))
		gtk_window_set_transient_for(GTK_WINDOW(Dialogue),GTK_WINDOW(win));
}
/**************************************************************************************************************************************/
void createSymmetryFrame(GtkWidget *win, GtkWidget *box)
{
	GtkWidget* button;
	GtkWidget* frame;
	GtkWidget* vboxFrame;
	GtkWidget* label = gtk_label_new(" ");
	GtkWidget* label0 = gtk_label_new("C1   group");
	GtkWidget *table = gtk_table_new(3,3,FALSE);

	frame = gtk_frame_new ("Geometry& basis");
	gtk_widget_show (frame);
	gtk_box_pack_start (GTK_BOX (box), frame, TRUE, TRUE, 3);
	gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

	vboxFrame = gtk_vbox_new (FALSE, 3);
	gtk_widget_show (vboxFrame);
	gtk_container_add (GTK_CONTAINER (frame), vboxFrame);

	gtk_box_pack_start (GTK_BOX (vboxFrame), table, TRUE, TRUE, 0);

	button = addRadioButtonToATable(table, NULL, "Without symmetry", 0, 0,1);
	add_widget_table(table, label0, 0, 1);
	g_object_set_data(G_OBJECT (button), "Label",label);
	g_object_set_data(G_OBJECT (button), "Type",&typeOfSymmetry[0]);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button), FALSE);
	g_signal_connect(G_OBJECT(button),"clicked", GTK_SIGNAL_FUNC(activateRadioButton),NULL);

	button = addRadioButtonToATable(table, button, "With symmetry", 1, 0, 1);
	g_object_set_data(G_OBJECT (button), "Label",label);
	g_object_set_data(G_OBJECT (button), "Type",&typeOfSymmetry[1]);
	g_signal_connect(G_OBJECT(button),"clicked", GTK_SIGNAL_FUNC(activateRadioButton),NULL);
	add_widget_table(table, label, 1, 1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (button), TRUE);
	buttonTolerance = create_button(win," Tolerance ");
	add_widget_table(table, buttonTolerance, 1, 2);
	g_signal_connect(G_OBJECT(buttonTolerance),"clicked", GTK_SIGNAL_FUNC(activateToleranceButton),NULL);

	buttonView = create_button(win," Show result ");
	gtk_table_attach(GTK_TABLE(table),buttonView,1,1+2,2,2+1,
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
                  3,3);
	/* add_widget_table(table, buttonView, 2, 2);*/
	g_signal_connect_swapped(G_OBJECT(buttonView),"clicked", GTK_SIGNAL_FUNC(createViewInfoAbelianGroupWindow),GTK_OBJECT(win));

	buttonBasis = create_button(win," Set Basis ");
	add_widget_table(table, buttonBasis, 2, 0);
	g_signal_connect_swapped(G_OBJECT(buttonBasis),"clicked", GTK_SIGNAL_FUNC(createBasisWindow),GTK_OBJECT(win));

	labelSymmetry = label;
}
/************************************************************************************************************/
void putSymmetryInTextEditor()
{
        gchar buffer[BSIZE];
	gint i;

	if(molcasMolecule.numberOfMolcasGenerators<1) return;
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.program, NULL, "Symmetry\n",-1);
      	for (i=0;i<molcasMolecule.numberOfMolcasGenerators;i++)
	{
		sprintf(buffer,"%s ",molcasMolecule.molcasGenerators[i]);
		g_strup(buffer);
        	gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, buffer, -1);
	}
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, "\n",-1);
}
/************************************************************************************************************/
void putMoleculeInTextEditor()
{
        gchar buffer[BSIZE];
	MolcasAtom* atomList = NULL;
	gint i;
	gint k;
	gint n;

	if(molcasMolecule.numberOfAtoms<1) return;

	atomList = molcasMolecule.listOfAtoms;
      	for (i=0;i<molcasMolecule.numberOfDifferentKindsOfAtoms;i++)
	{
		sprintf(buffer,"*----------------------------------------------------------------\n");
        	gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, buffer,-1);
        	gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.basis, NULL, "Basis set\n",-1);
		sprintf(buffer,"%s\n",molcasMolecule.basis[i]);
        	gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, buffer, -1);
		n = 1;
		for(k=0; k<molcasMolecule.numberOfAtoms; k++)
		{
			if(atomList[k].type == i)
			{
				
				sprintf(buffer,"%s%d %f %f %f /Angstrom\n",molcasMolecule.symbol[i], n, 
						atomList[k].position[0], atomList[k].position[1], atomList[k].position[2]);
			
				/*
				sprintf(buffer,"%s %f %f %f /Angstrom\n",molcasMolecule.symbol[i],
						atomList[k].position[0], atomList[k].position[1], atomList[k].position[2]);
						*/
        			gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, buffer, -1);
				n++;
			}
		}
        	gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.basis, NULL, "End of basis\n",-1);
	}
}
/************************************************************************************************************/
static void putBeginSewardInTextEditor()
{
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.program, &molcasColorBack.program, "  &SEWARD &END\n",-1);
}
/************************************************************************************************************/
static void putTitleSewardInTextEditor()
{
        gchar buffer[BSIZE];

        gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.program, NULL, "Title\n",-1);

	sprintf(buffer,"Seward data By Gabedit\n");
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, buffer,-1);

	sprintf(buffer,"*----------------------------------------------------------------\n");
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, buffer,-1);
}
/************************************************************************************************************/
static void putEndSewardInTextEditor()
{
        gchar buffer[BSIZE];
	sprintf(buffer,"*----------------------------------------------------------------\n");
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, buffer,-1);
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, &molcasColorFore.program, &molcasColorBack.program, "End of input\n\n",-1);
}
/************************************************************************************************************/
void putSewardInfoInTextEditor()
{
	putBeginSewardInTextEditor();
	putTitleSewardInTextEditor();
	putSymmetryInTextEditor();
	putMoleculeInTextEditor();
	putEndSewardInTextEditor();
}
/************************************************************************************************************/
