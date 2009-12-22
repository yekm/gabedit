/* MoleculeSE.c */
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
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Geometry/Measure.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/GeomXYZ.h"
#include "../Utils/Constants.h"
#include "../Utils/Utils.h"
#include "AtomSE.h"
#include "MoleculeSE.h"
void dessine();
void create_GeomXYZ_from_draw_grometry();


#define BOHR_TO_ANG  0.52917726

/**********************************************************************/
MoleculeSE newMoleculeSE()
{
	gint i;
	MoleculeSE molecule;

	molecule.nAtoms = 0;
	molecule.totalCharge = 0;
	molecule.spinMultiplicity = 0;
	molecule.atoms = NULL;
	molecule.energy = 0;

	for(i=0;i<3;i++)
		molecule.gradient[i] = NULL;

	return molecule;

}
/**********************************************************************/
void freeMoleculeSE(MoleculeSE* molecule)
{

	gint i;
        if(molecule->nAtoms<=0)
		return;

	if(molecule->atoms != NULL)
	{
		for(i=0;i<molecule->nAtoms;i++)
		{
			if(molecule->atoms[i].prop.symbol != NULL)
				g_free(molecule->atoms[i].prop.symbol);
			if(molecule->atoms[i].mmType !=NULL )
				g_free(molecule->atoms[i].mmType);
			if(molecule->atoms[i].pdbType !=NULL )
				g_free(molecule->atoms[i].pdbType);
		}

		g_free(molecule->atoms);
		molecule->atoms = NULL;
	}
	molecule->nAtoms = 0;
	molecule->energy = 0;
	molecule->totalCharge = 0;
	molecule->spinMultiplicity = 0;

	for(i=0;i<3;i++)
		if(molecule->gradient[i] != NULL)
		{
			g_free(molecule->gradient[i]);
			molecule->gradient[i] = NULL;
		}
}
/*****************************************************************************/
MoleculeSE createMoleculeSE(GeomDef* geom,gint natoms, gint charge, gint spin)
{

	gint i;
	MoleculeSE molecule = newMoleculeSE();

	molecule.nAtoms = natoms;
	molecule.atoms = g_malloc(molecule.nAtoms*sizeof(AtomSE));
	for(i=0;i<molecule.nAtoms;i++)
	{
		molecule.atoms[i].prop = prop_atom_get(geom[i].Prop.symbol);
		molecule.atoms[i].coordinates[0] = geom[i].X*BOHR_TO_ANG;
		molecule.atoms[i].coordinates[1] = geom[i].Y*BOHR_TO_ANG;
		molecule.atoms[i].coordinates[2] = geom[i].Z*BOHR_TO_ANG;
		molecule.atoms[i].charge = geom[i].Charge;
		molecule.atoms[i].mmType = g_strdup(geom[i].mmType);
		molecule.atoms[i].pdbType = g_strdup(geom[i].pdbType);
		molecule.atoms[i].residueName = g_strdup(geom[i].Residue);
		molecule.atoms[i].residueNumber = geom[i].ResidueNumber;
		molecule.atoms[i].layer = geom[i].Layer;
		molecule.atoms[i].show = geom[i].show;
	}
	molecule.totalCharge = charge;
	molecule.spinMultiplicity = spin;

	for(i=0;i<3;i++) /* x, y and z derivatives */
		molecule.gradient[i] = g_malloc(molecule.nAtoms*sizeof(gdouble));

	return molecule;
}
/*****************************************************************************/
MoleculeSE createFromGeomXYZMoleculeSE(gint charge, gint spin)
{

	gdouble x,y,z;
	gint i;
	MoleculeSE molecule = newMoleculeSE();

	molecule.nAtoms = NcentersXYZ;
	molecule.atoms = g_malloc(molecule.nAtoms*sizeof(AtomSE));
	for(i=0;i<molecule.nAtoms;i++)
	{
		molecule.atoms[i].prop = prop_atom_get(GeomXYZ[i].Symb);
         	if(!test(GeomXYZ[i].X)) x = get_value_variableXYZ(GeomXYZ[i].X);
          	else x = atof(GeomXYZ[i].X);
         	if(!test(GeomXYZ[i].Y)) y = get_value_variableXYZ(GeomXYZ[i].Y);
          	else y = atof(GeomXYZ[i].Y);
         	if(!test(GeomXYZ[i].Z)) z = get_value_variableXYZ(GeomXYZ[i].Z);
          	else z = atof(GeomXYZ[i].Z);

		if(Units==0)
		{
			x *= BOHR_TO_ANG;
			y *= BOHR_TO_ANG;
			z *= BOHR_TO_ANG;
		}
		molecule.atoms[i].coordinates[0] = x;
		molecule.atoms[i].coordinates[1] = y;
		molecule.atoms[i].coordinates[2] = z;
		molecule.atoms[i].charge = atof(GeomXYZ[i].Charge);
		molecule.atoms[i].mmType = g_strdup(GeomXYZ[i].mmType);
		molecule.atoms[i].pdbType = g_strdup(GeomXYZ[i].pdbType);
		molecule.atoms[i].residueName = g_strdup(GeomXYZ[i].Residue);
		molecule.atoms[i].residueNumber = GeomXYZ[i].ResidueNumber;
		if(strstr(GeomXYZ[i].Layer,"Low")) molecule.atoms[i].layer = LOW_LAYER;
		if(strstr(GeomXYZ[i].Layer,"Medium")) molecule.atoms[i].layer = MEDIUM_LAYER;
		else molecule.atoms[i].layer = HIGH_LAYER;
		molecule.atoms[i].show = TRUE;
	}
	molecule.totalCharge = charge;
	molecule.spinMultiplicity = spin;

	for(i=0;i<3;i++) /* x, y and z derivatives */
		molecule.gradient[i] = g_malloc(molecule.nAtoms*sizeof(gdouble));

	return molecule;
}
/*****************************************************************************/
void redrawMoleculeSE(MoleculeSE* molecule,gchar* str)
{
	gint i;
	gdouble C[3] = {0.0,0.0,0.0};

	Free_One_Geom(geometry0,Natoms);
	Free_One_Geom(geometry ,Natoms);
	Natoms = 0;
	geometry0 = NULL;
	geometry  = NULL;

	Natoms = molecule->nAtoms;
	geometry0 = g_malloc((Natoms)*sizeof(GeomDef));
	geometry  = g_malloc((Natoms)*sizeof(GeomDef));

	for(i=0;i<(gint)Natoms;i++)
	{
		geometry0[i].X = molecule->atoms[i].coordinates[0];
		geometry0[i].Y = molecule->atoms[i].coordinates[1];
		geometry0[i].Z = molecule->atoms[i].coordinates[2];
		geometry0[i].Charge =  molecule->atoms[i].charge;
		geometry0[i].Prop = prop_atom_get(molecule->atoms[i].prop.symbol);
		geometry0[i].pdbType =  g_strdup(molecule->atoms[i].pdbType);
		geometry0[i].mmType =  g_strdup(molecule->atoms[i].mmType);
		geometry0[i].Residue =  g_strdup(molecule->atoms[i].residueName);
		geometry0[i].ResidueNumber =  molecule->atoms[i].residueNumber;
		geometry0[i].show =  molecule->atoms[i].show;
		geometry0[i].Layer =  molecule->atoms[i].layer;
		geometry0[i].Variable = FALSE;
		geometry0[i].N = i+1;

		geometry[i].X = molecule->atoms[i].coordinates[0];
		geometry[i].Y = molecule->atoms[i].coordinates[1];
		geometry[i].Z = molecule->atoms[i].coordinates[2];
		geometry[i].Charge =  molecule->atoms[i].charge;
		geometry[i].Prop = prop_atom_get(molecule->atoms[i].prop.symbol);
		geometry[i].pdbType =  g_strdup(molecule->atoms[i].pdbType);
		geometry[i].mmType =  g_strdup(molecule->atoms[i].mmType);
		geometry[i].Residue =  g_strdup(molecule->atoms[i].residueName);
		geometry[i].ResidueNumber =  molecule->atoms[i].residueNumber;
		geometry[i].show =  molecule->atoms[i].show;
		geometry[i].Layer =  molecule->atoms[i].layer;
		geometry[i].Variable = FALSE;
		geometry[i].N = i+1;

		C[0] +=  geometry0[i].X;
		C[1] +=  geometry0[i].Y;
		C[2] +=  geometry0[i].Z;


	}
	for(i=0;i<3;i++)
		C[i] /= Natoms;
	/* center */
	for(i=0;i<(gint)Natoms;i++)
	{
		geometry0[i].X -= C[0];
		geometry0[i].Y -= C[1];
		geometry0[i].Z -= C[2];

		geometry[i].X -= C[0];
		geometry[i].Y -= C[1];
		geometry[i].Z -= C[2];
	}
	
	for(i=0;i<(gint)Natoms;i++)
	{
		geometry0[i].X /=BOHR_TO_ANG;
		geometry0[i].Y /=BOHR_TO_ANG;
		geometry0[i].Z /=BOHR_TO_ANG;

		geometry[i].X /=BOHR_TO_ANG;
		geometry[i].Y /=BOHR_TO_ANG;
		geometry[i].Z /=BOHR_TO_ANG;
	}
	unselect_all_atoms();
	set_text_to_draw(str);
	set_statubar_operation_str(str);
	change_of_center(NULL,NULL);
	reset_all_connections();
	create_GeomXYZ_from_draw_grometry();
	dessine();

    	while( gtk_events_pending() )
        	gtk_main_iteration();

}
/********************************************************************************/
MoleculeSE copyMoleculeSE(MoleculeSE* m)
{

	gint i;
	gint j;
	MoleculeSE molecule = newMoleculeSE();

	molecule.energy = m->energy;
	molecule.nAtoms = m->nAtoms;
	molecule.totalCharge = m->totalCharge;
	molecule.spinMultiplicity = m->spinMultiplicity;
	if( molecule.nAtoms>0) molecule.atoms = g_malloc(molecule.nAtoms*sizeof(AtomSE));
	for(i=0;i<molecule.nAtoms;i++)
	{
		molecule.atoms[i].prop = prop_atom_get(m->atoms[i].prop.symbol);
		for(j=0;j<3;j++) molecule.atoms[i].coordinates[j] = m->atoms[i].coordinates[j];
		molecule.atoms[i].charge = m->atoms[i].charge;
		molecule.atoms[i].mmType = g_strdup(m->atoms[i].mmType);
		molecule.atoms[i].pdbType = g_strdup(m->atoms[i].pdbType);
		molecule.atoms[i].residueName = g_strdup(m->atoms[i].residueName);
		molecule.atoms[i].residueNumber = m->atoms[i].residueNumber;
		molecule.atoms[i].layer = m->atoms[i].layer;
		molecule.atoms[i].show = m->atoms[i].show;
	}


	if(molecule.nAtoms>0)
	for(j=0;j<3;j++) /* x, y and z derivatives */
	{
		molecule.gradient[j] = g_malloc(molecule.nAtoms*sizeof(gdouble));
		for(i=0;i<molecule.nAtoms;i++)
		molecule.gradient[j][i] = m->gradient[j][i];
	}

	return molecule;
}
