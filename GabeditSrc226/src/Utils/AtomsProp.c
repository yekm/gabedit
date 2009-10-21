/* AtomsProp.c */
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
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../Common/Global.h"
#include "../Utils/Constants.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/UtilsInterface.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Utils/Utils.h"
#include "../Geometry/GeomGlobal.h"
#include "../OpenGL/GLArea.h"
#include "../Common/Windows.h"

#define NATOMS 111

enum 
{
	DISPLAY_RADII = 0,
	COVALENT_RADII,
	VANDERWALS_RADII,
	MAXIMUM_BOND_VALENCE,
	MASSE,
	ELECTRONEGATIVITY,
	NUMBER_OF_ENTRYS,
};
/******************************************************************/
typedef struct _SData
{
	gchar *Symb;
	GtkWidget *Window;
	GtkWidget *Button;
	GtkStyle *Style;
}SData;
/******************************************************************/
static SAtomsProp AtomsProp[NATOMS];
static GtkWidget *EntryProp[NUMBER_OF_ENTRYS];
GdkColor ColorTemp;
/********************************************************************************/
void save_atoms_prop()
{
 guint i;
 gchar *atomspropfile;
 FILE *fd;

 atomspropfile = g_strdup_printf("%s/atomsprop",gabedit_directory());
 fd = FOpen(atomspropfile, "w");

 if(fd==NULL)
   return;

 for(i=0;i<NATOMS;i++)
  fprintf(fd,"%s %s %d %f %f %f %f %d %f %f %d %d %d \n",
	AtomsProp[i].name,
	AtomsProp[i].symbol,
	AtomsProp[i].atomicNumber,
	AtomsProp[i].covalentRadii,
	AtomsProp[i].bondOrderRadii,
	AtomsProp[i].vanDerWaalsRadii,
	AtomsProp[i].radii,
	AtomsProp[i].maximumBondValence,
	AtomsProp[i].masse,
	AtomsProp[i].electronegativity,
	AtomsProp[i].color.red,
	AtomsProp[i].color.green,
	AtomsProp[i].color.blue);
  fclose(fd);
}
/********************************************************************************/
gboolean read_atoms_prop()
{
 
 gint i;
 gchar *t;
 guint taille=BSIZE;
 gboolean OK=TRUE;
 gchar *atomspropfile;
 FILE *fd;
 
 atomspropfile = g_strdup_printf("%s/atomsprop",gabedit_directory());
 fd = FOpen(atomspropfile, "r");  

 t=g_malloc(taille);

 i=-1;
 if(fd!=NULL)
 {
  while(!feof(fd) && (i<NATOMS-1))
  {
    i++;
    fgets(t,taille,fd);
    AtomsProp[i].name= g_malloc(30);
    AtomsProp[i].symbol= g_malloc(3);
    sscanf(t,"%s %s %d %lf %lf %lf %lf %d %lf %lf %hu %hu %hu",
	AtomsProp[i].name,
	AtomsProp[i].symbol,
	&AtomsProp[i].atomicNumber,
	&AtomsProp[i].covalentRadii,
	&AtomsProp[i].bondOrderRadii,
	&AtomsProp[i].vanDerWaalsRadii,
	&AtomsProp[i].radii,
	&AtomsProp[i].maximumBondValence,
	&AtomsProp[i].masse,
	&AtomsProp[i].electronegativity,
	&AtomsProp[i].color.red,
	&AtomsProp[i].color.green,
	&AtomsProp[i].color.blue
        );
  }
 }
 else
    OK  = FALSE;
 g_free(t);
 return OK;
}
/********************************************************************************/
gdouble get_masse_from_symbol(gchar* symbol)
{
	guint i;
	for(i=0;i<NATOMS;i++)
	{
		if (!strcmp(symbol,AtomsProp[i].symbol))
			return AtomsProp[i].masse;
	}
	return 1.0;
}
/******************************************************************/
gdouble get_atomic_number_from_symbol(gchar* symbol)
{
	guint i;
        static gchar symb[5];
	gint l;

	if(!symbol) return 0.0;
	l = strlen(symbol);
	symb[0] = toupper(symbol[0]);
	if(l>1) symb[1]=tolower(symbol[1]);
	if(l>2) symb[2]=tolower(symbol[1]);
	symb[l] = '\0';
	
	for(i=0;i<NATOMS;i++)
	{
		if (!strcmp(symb,AtomsProp[i].symbol))
		{
			return AtomsProp[i].atomicNumber;
		}
	}
	return -1.0;
}
/********************************************************************************/
gchar* get_symbol_using_z(gint z)
{
	guint i;
	
	for(i=0;i<NATOMS;i++)
	{
		if(z == (gint)AtomsProp[i].atomicNumber)
		{
			return g_strdup(AtomsProp[i].symbol);
		}
	}
	return g_strdup("X");
}
/********************************************************************************/
gboolean test_atom_define(gchar *Symb)
{
	guint i;
	
	for(i=0;i<NATOMS;i++)
	{
		if (!strcmp(Symb,AtomsProp[i].symbol))
 		{
			return TRUE;
		}

	}
	return FALSE;
}
/********************************************************************************/
SAtomsProp prop_atom_get(const gchar *Symb)
{
	guint i;
        SAtomsProp temp;
	
	for(i=0;i<NATOMS;i++)
	{
		if (!strcmp(Symb,AtomsProp[i].symbol))
 		{
			temp.name   = g_strdup(AtomsProp[i].name);
			temp.symbol   = g_strdup(AtomsProp[i].symbol);
			temp.atomicNumber      = AtomsProp[i].atomicNumber;
			temp.covalentRadii    = AtomsProp[i].covalentRadii;
			temp.bondOrderRadii    = AtomsProp[i].bondOrderRadii;
			temp.vanDerWaalsRadii   = AtomsProp[i].vanDerWaalsRadii;
			temp.radii = AtomsProp[i].radii;
			temp.maximumBondValence = AtomsProp[i].maximumBondValence;
			temp.masse    = AtomsProp[i].masse;
			temp.electronegativity    = AtomsProp[i].electronegativity;
			temp.color  = AtomsProp[i].color;
			return temp;
		}

	}
	printf("Warning : Sorry , Your atom %s is not defined\n",Symb);
        i=0;
	temp.name   = g_strdup(AtomsProp[i].name);
	temp.symbol   = g_strdup(AtomsProp[i].symbol);
	temp.atomicNumber      = AtomsProp[i].atomicNumber;
	temp.covalentRadii    = AtomsProp[i].covalentRadii;
	temp.bondOrderRadii    = AtomsProp[i].bondOrderRadii;
	temp.vanDerWaalsRadii   = AtomsProp[i].vanDerWaalsRadii;
	temp.maximumBondValence = AtomsProp[i].maximumBondValence;
	temp.radii = AtomsProp[i].radii;
	temp.masse = AtomsProp[i].masse;
	temp.electronegativity = AtomsProp[i].electronegativity;
	temp.color  = AtomsProp[i].color;
	return temp;
}
/******************************************************************/
gchar *symb_atom_get(guint Z)
{
	guint i;
        gchar *symb;
       
        symb = g_strdup("X");
	
	for(i=0;i<NATOMS;i++)
	{
		if (Z==AtomsProp[i].atomicNumber)
 		{
		symb =g_strdup(AtomsProp[i].symbol);
 		break;
		}

	}
	return symb;
}
/******************************************************************/
void set_color_atom(GdkColor color,gchar *Symb)
{
  guint i;
  for (i=0;i<NATOMS;i++)	  
  {
	if (!strcmp(Symb,AtomsProp[i].symbol))
	{
	 AtomsProp[i].color=color;
	 return;
	}
  }
}
/******************************************************************/
void setPropForOneAtom(gchar* name, gchar* symbol, gint atomicNumber, 
		gdouble covalentRadii, gdouble bondOrderRadii, gdouble vanDerWaalsRadii, 
		gint maximumBondValence, gdouble masse, gdouble electronegativity, gdouble red, gdouble green, gdouble blue)
{
	gint i = (gint)atomicNumber-1;
	if(strcmp(symbol,"Xx")==0) i = 109;
	if(strcmp(symbol,"X")==0) i = 110;

	AtomsProp[i].name = g_strdup(name);
	AtomsProp[i].symbol = g_strdup(symbol);
	AtomsProp[i].atomicNumber = atomicNumber;
	AtomsProp[i].covalentRadii = (covalentRadii+0.2)*ANG_TO_BOHR;
	AtomsProp[i].bondOrderRadii = bondOrderRadii*ANG_TO_BOHR;
	AtomsProp[i].vanDerWaalsRadii = vanDerWaalsRadii*ANG_TO_BOHR;
	/*AtomsProp[i].radii = covalentRadii/1.5*ANG_TO_BOHR;*/
	AtomsProp[i].radii = vanDerWaalsRadii*0.2*ANG_TO_BOHR;
	AtomsProp[i].maximumBondValence = maximumBondValence;
	AtomsProp[i].masse = masse;
	AtomsProp[i].electronegativity = electronegativity/27.21;
	AtomsProp[i].color.red = (gushort)(red*65535);
	AtomsProp[i].color.green = (gushort)(green*65535);
	AtomsProp[i].color.blue =  (gushort)(blue*65535);
}
/******************************************************************/
void define_default_atoms_prop()
{
	setPropForOneAtom("Hydrogen", "H", 1, 0.230000, 0.330000, 1.200000, 1, 1.007940, 2.100000, 1.000000, 1.000000, 1.000000);
	setPropForOneAtom("Helium", "He", 2, 0.930000, 0.700000, 1.400000, 0, 4.002602, 0.000000, 0.850000, 1.000000, 1.000000);
	setPropForOneAtom("Lithium", "Li", 3, 0.680000, 1.230000, 1.820000, 1, 6.941000, 0.980000, 0.800000, 0.500000, 1.000000);
	setPropForOneAtom("Beryllium", "Be", 4, 0.350000, 0.900000, 1.700000, 2, 9.012182, 1.570000, 0.760000, 1.000000, 0.000000);
	setPropForOneAtom("Boron", "B", 5, 0.830000, 0.820000, 2.080000, 3, 10.811000, 2.040000, 1.000000, 0.710000, 0.710000);
	setPropForOneAtom("Carbon", "C", 6, 0.680000, 0.770000, 1.950000, 4, 12.010700, 2.550000, 0.500000, 0.500000, 0.500000);
	setPropForOneAtom("Nitrogen", "N", 7, 0.680000, 0.700000, 1.850000, 3, 14.006700, 3.040000, 0.050000, 0.050000, 1.000000);
	setPropForOneAtom("Oxygen", "O", 8, 0.680000, 0.660000, 1.700000, 2, 15.999400, 3.440000, 1.000000, 0.050000, 0.050000);
	setPropForOneAtom("Fluorine", "F", 9, 0.640000, 0.611000, 1.730000, 1, 18.998404, 3.980000, 0.700000, 1.000000, 1.000000);
	setPropForOneAtom("Neon", "Ne", 10, 1.120000, 0.700000, 1.540000, 0, 20.179701, 0.000000, 0.700000, 0.890000, 0.960000);
	/*
	setPropForOneAtom("Sodium", "Na", 11, 0.970000, 1.540000, 2.270000, 1, 22.989771, 0.930000, 0.670000, 0.360000, 0.950000);
	*/
	setPropForOneAtom("Sodium", "Na", 11, 1.9, 3.06, 2.270000, 1, 22.989771, 0.930000, 0.670000, 0.360000, 0.950000);
	AtomsProp[10].radii /= 2;

	setPropForOneAtom("Magnesium", "Mg", 12, 1.100000, 1.360000, 1.730000, 2, 24.305000, 1.310000, 0.540000, 1.000000, 0.000000);
	setPropForOneAtom("Aluminium", "Al", 13, 1.350000, 1.180000, 2.050000, 6, 26.981539, 1.610000, 0.750000, 0.650000, 0.650000);
	setPropForOneAtom("Silicon", "Si", 14, 1.200000, 0.937000, 2.100000, 6, 28.085501, 1.900000, 0.500000, 0.600000, 0.600000);
	setPropForOneAtom("Phosphorus", "P", 15, 1.100000, 0.890000, 2.080000, 5, 30.973761, 2.190000, 1.000000, 0.500000, 0.000000);
	setPropForOneAtom("Sulphur", "S", 16, 1.020000, 1.040000, 2.000000, 6, 32.064999, 2.580000, 1.000000, 1.000000, 0.190000);
	setPropForOneAtom("Chlorine", "Cl", 17, 0.990000, 0.997000, 1.970000, 1, 35.452999, 3.160000, 0.120000, 0.940000, 0.120000);
	setPropForOneAtom("Argon", "Ar", 18, 1.570000, 1.740000, 1.880000, 0, 39.948002, 0.000000, 0.500000, 0.820000, 0.890000);
	setPropForOneAtom("Potassium", "K", 19, 1.330000, 2.030000, 2.750000, 1, 39.098301, 0.820000, 0.560000, 0.250000, 0.830000);
	setPropForOneAtom("Calcium", "Ca", 20, 0.990000, 1.740000, 1.973000, 2, 40.077999, 1.000000, 0.240000, 1.000000, 0.000000);
	setPropForOneAtom("Scandium", "Sc", 21, 1.440000, 1.440000, 1.700000, 6, 44.955910, 1.360000, 0.900000, 0.900000, 0.900000);
	setPropForOneAtom("Titanium", "Ti", 22, 1.470000, 1.320000, 1.700000, 6, 47.867001, 1.540000, 0.750000, 0.760000, 0.780000);
	setPropForOneAtom("Vanadium", "V", 23, 1.330000, 1.220000, 1.700000, 6, 50.941502, 1.630000, 0.650000, 0.650000, 0.670000);
	setPropForOneAtom("Chromium", "Cr", 24, 1.350000, 1.180000, 1.700000, 6, 51.996101, 1.660000, 0.540000, 0.600000, 0.780000);
	setPropForOneAtom("Manganese", "Mn", 25, 1.350000, 1.170000, 1.700000, 8, 54.938049, 1.550000, 0.610000, 0.480000, 0.780000);
	setPropForOneAtom("Iron", "Fe", 26, 1.340000, 1.170000, 1.700000, 6, 55.845001, 1.830000, 0.500000, 0.480000, 0.780000);
	setPropForOneAtom("Cobalt", "Co", 27, 1.330000, 1.160000, 1.700000, 6, 58.933201, 1.880000, 0.440000, 0.480000, 0.780000);
	setPropForOneAtom("Nickel", "Ni", 28, 1.500000, 1.150000, 1.630000, 6, 58.693401, 1.910000, 0.360000, 0.480000, 0.760000);
	setPropForOneAtom("Copper", "Cu", 29, 1.520000, 1.170000, 1.400000, 6, 63.546001, 1.900000, 1.000000, 0.480000, 0.380000);
	setPropForOneAtom("Zinc", "Zn", 30, 1.450000, 1.250000, 1.390000, 6, 65.408997, 1.650000, 0.490000, 0.500000, 0.690000);
	setPropForOneAtom("Gallium", "Ga", 31, 1.220000, 1.260000, 1.870000, 3, 69.723000, 1.810000, 0.760000, 0.560000, 0.560000);
	setPropForOneAtom("Germanium", "Ge", 32, 1.170000, 1.188000, 1.700000, 4, 72.639999, 2.010000, 0.400000, 0.560000, 0.560000);
	setPropForOneAtom("Arsenic", "As", 33, 1.210000, 1.200000, 1.850000, 3, 74.921600, 2.180000, 0.740000, 0.500000, 0.890000);
	setPropForOneAtom("Selenium", "Se", 34, 1.220000, 1.170000, 1.900000, 2, 78.959999, 2.550000, 1.000000, 0.630000, 0.000000);
	setPropForOneAtom("Bromine", "Br", 35, 1.210000, 1.167000, 2.100000, 1, 79.903999, 2.960000, 0.650000, 0.160000, 0.160000);
	setPropForOneAtom("Krypton", "Kr", 36, 1.910000, 1.910000, 2.020000, 0, 83.797997, 0.000000, 0.360000, 0.720000, 0.820000);
	setPropForOneAtom("Rubidium", "Rb", 37, 1.470000, 2.160000, 1.700000, 1, 85.467796, 0.820000, 0.440000, 0.180000, 0.690000);
	setPropForOneAtom("Strontium", "Sr", 38, 1.120000, 1.910000, 1.700000, 2, 87.620003, 0.950000, 0.000000, 1.000000, 0.000000);
	setPropForOneAtom("Yttrium", "Y", 39, 1.780000, 1.620000, 1.700000, 6, 88.905853, 1.220000, 0.580000, 1.000000, 1.000000);
	setPropForOneAtom("Zirconium", "Zr", 40, 1.560000, 1.450000, 1.700000, 6, 91.223999, 1.330000, 0.580000, 0.880000, 0.880000);
	setPropForOneAtom("Niobium", "Nb", 41, 1.480000, 1.340000, 1.700000, 6, 92.906380, 1.600000, 0.450000, 0.760000, 0.790000);
	setPropForOneAtom("Molybdenum", "Mo", 42, 1.470000, 1.300000, 1.700000, 6, 95.940002, 2.160000, 0.330000, 0.710000, 0.710000);
	setPropForOneAtom("Technetium", "Tc", 43, 1.350000, 1.270000, 1.700000, 6, 98.000000, 1.900000, 0.230000, 0.620000, 0.620000);
	setPropForOneAtom("Ruthenium", "Ru", 44, 1.400000, 1.250000, 1.700000, 6, 101.070000, 2.200000, 0.140000, 0.560000, 0.560000);
	setPropForOneAtom("Rhodium", "Rh", 45, 1.450000, 1.250000, 1.700000, 6, 102.905502, 2.280000, 0.040000, 0.490000, 0.550000);
	setPropForOneAtom("Palladium", "Pd", 46, 1.500000, 1.280000, 1.630000, 6, 106.419998, 2.200000, 0.000000, 0.410000, 0.520000);
	setPropForOneAtom("Silver", "Ag", 47, 1.590000, 1.340000, 1.720000, 6, 107.868202, 1.930000, 0.880000, 0.880000, 1.000000);
	setPropForOneAtom("Cadmium", "Cd", 48, 1.690000, 1.480000, 1.580000, 6, 112.411003, 1.690000, 1.000000, 0.850000, 0.560000);
	setPropForOneAtom("Indium", "In", 49, 1.630000, 1.440000, 1.930000, 3, 114.818001, 1.780000, 0.650000, 0.460000, 0.450000);
	setPropForOneAtom("Tin", "Sn", 50, 1.460000, 1.385000, 2.170000, 4, 118.709999, 1.960000, 0.400000, 0.500000, 0.500000);
	setPropForOneAtom("Antimony", "Sb", 51, 1.460000, 1.400000, 2.200000, 3, 121.760002, 2.050000, 0.620000, 0.390000, 0.710000);
	setPropForOneAtom("Tellurium", "Te", 52, 1.470000, 1.378000, 2.060000, 2, 127.599998, 2.100000, 0.830000, 0.480000, 0.000000);
	setPropForOneAtom("Iodine", "I", 53, 1.400000, 1.387000, 2.150000, 1, 126.904472, 2.660000, 0.580000, 0.000000, 0.580000);
	setPropForOneAtom("Xenon", "Xe", 54, 1.980000, 1.980000, 2.160000, 0, 131.292999, 2.600000, 0.260000, 0.620000, 0.690000);
	setPropForOneAtom("Cesium", "Cs", 55, 1.670000, 2.350000, 1.700000, 1, 132.905457, 0.790000, 0.340000, 0.090000, 0.560000);
	setPropForOneAtom("Barium", "Ba", 56, 1.340000, 1.980000, 1.700000, 2, 137.326996, 0.890000, 0.000000, 0.790000, 0.000000);
	setPropForOneAtom("Lanthanum", "La", 57, 1.870000, 1.690000, 1.700000, 12, 138.905502, 1.100000, 0.440000, 0.830000, 1.000000);
	setPropForOneAtom("Cerium", "Ce", 58, 1.830000, 1.830000, 1.700000, 6, 140.115997, 1.120000, 1.000000, 1.000000, 0.780000);
	setPropForOneAtom("Praseodymium", "Pr", 59, 1.820000, 1.820000, 1.700000, 6, 140.907654, 1.130000, 0.850000, 1.000000, 0.780000);
	setPropForOneAtom("Neodymium", "Nd", 60, 1.810000, 1.810000, 1.700000, 6, 144.240005, 1.140000, 0.780000, 1.000000, 0.780000);
	setPropForOneAtom("Promethium", "Pm", 61, 1.800000, 1.800000, 1.700000, 6, 145.000000, 1.130000, 0.640000, 1.000000, 0.780000);
	setPropForOneAtom("Samarium", "Sm", 62, 1.800000, 1.800000, 1.700000, 6, 150.360001, 1.170000, 0.560000, 1.000000, 0.780000);
	setPropForOneAtom("Europium", "Eu", 63, 1.990000, 1.990000, 1.700000, 6, 151.964005, 1.200000, 0.380000, 1.000000, 0.780000);
	setPropForOneAtom("Gadolinium", "Gd", 64, 1.790000, 1.790000, 1.700000, 6, 157.250000, 1.200000, 0.270000, 1.000000, 0.780000);
	setPropForOneAtom("Terbium", "Tb", 65, 1.760000, 1.760000, 1.700000, 6, 158.925339, 1.100000, 0.190000, 1.000000, 0.780000);
	setPropForOneAtom("Dysprosium", "Dy", 66, 1.750000, 1.750000, 1.700000, 6, 162.500000, 1.220000, 0.120000, 1.000000, 0.780000);
	setPropForOneAtom("Holmium", "Ho", 67, 1.740000, 1.740000, 1.700000, 6, 164.930313, 1.230000, 0.000000, 1.000000, 0.610000);
	setPropForOneAtom("Erbium", "Er", 68, 1.730000, 1.730000, 1.700000, 6, 167.259003, 1.240000, 0.000000, 0.900000, 0.460000);
	setPropForOneAtom("Thulium", "Tm", 69, 1.720000, 1.720000, 1.700000, 6, 168.934204, 1.250000, 0.000000, 0.830000, 0.320000);
	setPropForOneAtom("Ytterbium", "Yb", 70, 1.940000, 1.940000, 1.700000, 6, 173.039993, 1.100000, 0.000000, 0.750000, 0.220000);
	setPropForOneAtom("Lutetium", "Lu", 71, 1.720000, 1.720000, 1.700000, 6, 174.966995, 1.270000, 0.000000, 0.670000, 0.140000);
	setPropForOneAtom("Hafnium", "Hf", 72, 1.570000, 1.440000, 1.700000, 6, 178.490005, 1.300000, 0.300000, 0.760000, 1.000000);
	setPropForOneAtom("Tantalum", "Ta", 73, 1.430000, 1.340000, 1.700000, 6, 180.947906, 1.500000, 0.300000, 0.650000, 1.000000);
	setPropForOneAtom("Tungsten", "W", 74, 1.370000, 1.300000, 1.700000, 6, 183.839996, 2.360000, 0.130000, 0.580000, 0.840000);
	setPropForOneAtom("Rhenium", "Re", 75, 1.350000, 1.280000, 1.700000, 6, 186.207001, 1.900000, 0.150000, 0.490000, 0.670000);
	setPropForOneAtom("Osmium", "Os", 76, 1.370000, 1.260000, 1.700000, 6, 190.229996, 2.200000, 0.150000, 0.400000, 0.590000);
	setPropForOneAtom("Iridium", "Ir", 77, 1.320000, 1.270000, 1.700000, 6, 192.216995, 2.200000, 0.090000, 0.330000, 0.530000);
	setPropForOneAtom("Platinum", "Pt", 78, 1.500000, 1.300000, 1.720000, 6, 195.078003, 2.280000, 0.960000, 0.930000, 0.820000);
	setPropForOneAtom("Gold", "Au", 79, 1.500000, 1.340000, 1.660000, 6, 196.966553, 2.540000, 0.800000, 0.820000, 0.120000);
	setPropForOneAtom("Mercury", "Hg", 80, 1.700000, 1.490000, 1.550000, 6, 200.589996, 2.000000, 0.710000, 0.710000, 0.760000);
	setPropForOneAtom("Thallium", "Tl", 81, 1.550000, 1.480000, 1.960000, 3, 204.383301, 2.040000, 0.650000, 0.330000, 0.300000);
	setPropForOneAtom("Lead", "Pb", 82, 1.540000, 1.480000, 2.020000, 4, 207.199997, 2.330000, 0.340000, 0.350000, 0.380000);
	setPropForOneAtom("Bismuth", "Bi", 83, 1.540000, 1.450000, 1.700000, 3, 208.980377, 2.020000, 0.620000, 0.310000, 0.710000);
	setPropForOneAtom("Polonium", "Po", 84, 1.680000, 1.460000, 1.700000, 2, 209.000000, 2.000000, 0.670000, 0.360000, 0.000000);
	setPropForOneAtom("Astatine", "At", 85, 1.700000, 1.450000, 1.700000, 1, 210.000000, 2.200000, 0.460000, 0.310000, 0.270000);
	setPropForOneAtom("Radon", "Rn", 86, 2.400000, 2.400000, 1.700000, 0, 222.000000, 0.000000, 0.260000, 0.510000, 0.590000);
	setPropForOneAtom("Francium", "Fr", 87, 2.000000, 2.000000, 1.700000, 1, 223.000000, 0.700000, 0.260000, 0.000000, 0.400000);
	setPropForOneAtom(" radium", "Ra", 88, 1.900000, 1.900000, 1.700000, 2, 226.000000, 0.890000, 0.000000, 0.490000, 0.000000);
	setPropForOneAtom("Actinium", "Ac", 89, 1.880000, 1.880000, 1.700000, 6, 227.000000, 1.100000, 0.440000, 0.670000, 0.980000);
	setPropForOneAtom("Thorium", "Th", 90, 1.790000, 1.790000, 1.700000, 6, 232.038101, 1.300000, 0.000000, 0.730000, 1.000000);
	setPropForOneAtom("Protactinium", "Pa", 91, 1.610000, 1.610000, 1.700000, 6, 231.035873, 1.500000, 0.000000, 0.630000, 1.000000);
	setPropForOneAtom("Uranium", "U", 92, 1.580000, 1.580000, 1.860000, 6, 238.028915, 1.380000, 0.000000, 0.560000, 1.000000);
	setPropForOneAtom("Neptunium", "Np", 93, 1.550000, 1.550000, 1.700000, 6, 237.000000, 1.360000, 0.000000, 0.500000, 1.000000);
	setPropForOneAtom("Plutionium", "Pu", 94, 1.530000, 1.530000, 1.700000, 6, 244.000000, 1.280000, 0.000000, 0.420000, 1.000000);
	setPropForOneAtom("Americium", "Am", 95, 1.510000, 1.070000, 1.700000, 6, 243.000000, 1.300000, 0.330000, 0.360000, 0.950000);
	setPropForOneAtom("Curium", "Cm", 96, 1.500000, 0.000000, 1.700000, 6, 247.000000, 1.300000, 0.470000, 0.360000, 0.890000);
	setPropForOneAtom("Berkelium", "Bk", 97, 1.500000, 0.000000, 1.700000, 6, 247.000000, 1.300000, 0.540000, 0.310000, 0.890000);
	setPropForOneAtom("Californium", "Cf", 98, 1.500000, 0.000000, 1.700000, 6, 251.000000, 1.300000, 0.630000, 0.210000, 0.830000);
	setPropForOneAtom("Einsteinium", "Es", 99, 1.500000, 0.000000, 1.700000, 6, 252.000000, 1.300000, 0.700000, 0.120000, 0.830000);
	setPropForOneAtom("Fermium", "Fm", 100, 1.500000, 0.000000, 1.700000, 6, 257.000000, 1.300000, 0.700000, 0.120000, 0.730000);
	setPropForOneAtom("Mendelevium", "Md", 101, 1.500000, 0.000000, 1.700000, 6, 258.000000, 1.300000, 0.700000, 0.050000, 0.650000);
	setPropForOneAtom("Nobelium", "No", 102, 1.500000, 0.000000, 1.700000, 6, 259.000000, 1.300000, 0.740000, 0.050000, 0.530000);
	setPropForOneAtom("Lawrencium", "Lr", 103, 1.500000, 0.000000, 1.700000, 6, 262.000000, 1.300000, 0.780000, 0.000000, 0.400000);
	setPropForOneAtom("Rutherfordium", "Rf", 104, 1.600000, 0.000000, 1.700000, 6, 261.000000, 0.000000, 0.800000, 0.000000, 0.350000);
	setPropForOneAtom("Dubnium", "Db", 105, 1.600000, 0.000000, 1.700000, 6, 262.000000, 0.000000, 0.820000, 0.000000, 0.310000);
	setPropForOneAtom("Seaborgium", "Sg", 106, 1.600000, 0.000000, 1.700000, 6, 263.000000, 0.000000, 0.850000, 0.000000, 0.270000);
	setPropForOneAtom("Bohrium", "Bh", 107, 1.600000, 0.000000, 1.700000, 6, 264.000000, 0.000000, 0.880000, 0.000000, 0.220000);
	setPropForOneAtom("Hassium", "Hs", 108, 1.600000, 0.000000, 1.700000, 6, 265.000000, 0.000000, 0.900000, 0.000000, 0.180000);
	setPropForOneAtom("Meitnerium", "Mt", 109, 1.600000, 0.000000, 1.700000, 6, 268.000000, 0.000000, 0.920000, 0.000000, 0.150000);
	setPropForOneAtom("Dummy", "Xx", 0, 0.000000, 0.000000, 0.000000, 0, 0.000000, 0.000000, 0.070000, 0.500000, 0.700000);
	setPropForOneAtom("Dummy", "X", 0, 0.000000, 0.000000, 0.000000, 0, 0.000000, 0.000000, 0.070000, 0.500000, 0.700000);
}
/******************************************************************/
void set_atom_color(GtkColorSelection *Sel,gpointer *d)
{
	gtk_color_selection_get_current_color(Sel, &ColorTemp);
}
/******************************************************************/
void set_button_color(GtkObject *button,gpointer *data)
{
	  GtkStyle *style;
          SData *tdata=(SData*)data;
          style =  gtk_style_copy(tdata->Style); 
          style->bg[0].red= ColorTemp.red; 
          style->bg[0].green=ColorTemp.green;
          style->bg[0].blue=ColorTemp.blue;
          tdata->Style=style;
	  gtk_widget_set_style(tdata->Button, tdata->Style);
}
/******************************************************************/
static void open_color_dlg_atoms(GtkWidget *win,gpointer tdata)
{

	GtkColorSelectionDialog *ColorDlg;
        SData *data=(SData*)tdata;
	GtkStyle *style;
	gdouble v[3];

        style =  data->Style; 
	v[0] =style->bg[0].red/65535.0;
	v[1] =style->bg[0].green/65535.0;
	v[2] =style->bg[0].blue/65535.0;
	ColorDlg = (GtkColorSelectionDialog *)gtk_color_selection_dialog_new("Set Atom Color");
	gtk_color_selection_set_current_color (GTK_COLOR_SELECTION (ColorDlg->colorsel), &style->bg[0]);

	gtk_window_set_transient_for(GTK_WINDOW(ColorDlg),GTK_WINDOW(data->Window));
        gtk_window_set_position(GTK_WINDOW(ColorDlg),GTK_WIN_POS_CENTER);
	gtk_window_set_modal (GTK_WINDOW (ColorDlg), TRUE);
 	g_signal_connect(G_OBJECT(ColorDlg), "delete_event",(GCallback)destroy_button_windows,NULL);
  	g_signal_connect(G_OBJECT(ColorDlg), "delete_event",G_CALLBACK(gtk_widget_destroy),NULL);

  	gtk_widget_hide(ColorDlg->help_button);
	g_signal_connect_swapped(G_OBJECT(ColorDlg->ok_button),"clicked",
		(GCallback)set_atom_color,GTK_OBJECT(ColorDlg->colorsel));

	g_signal_connect(G_OBJECT(ColorDlg->ok_button),"clicked",
		(GCallback)set_button_color,tdata);

  	g_signal_connect_swapped(G_OBJECT(ColorDlg->ok_button), "clicked",
		(GCallback)destroy_button_windows,GTK_OBJECT(ColorDlg));
	g_signal_connect_swapped(G_OBJECT(ColorDlg->ok_button),"clicked",
		(GCallback)gtk_widget_destroy,GTK_OBJECT(ColorDlg));

  	g_signal_connect_swapped(G_OBJECT(ColorDlg->cancel_button), "clicked",
		(GCallback)destroy_button_windows,GTK_OBJECT(ColorDlg));
	g_signal_connect_swapped(G_OBJECT(ColorDlg->cancel_button),"clicked",
		(GCallback)gtk_widget_destroy,GTK_OBJECT(ColorDlg));

  	add_button_windows(" Set Color ",GTK_WIDGET(ColorDlg));
	gtk_widget_show(GTK_WIDGET(ColorDlg));

}
/******************************************************************/
static void set_atom_prop(GtkWidget *w,gpointer data)
{
  guint i;
  gchar *Symb;
  G_CONST_RETURN gchar *temp;
  gdouble radii;
  gdouble covalentRadii;
  gdouble vanDerWaalsRadii;
  gint maximumBondValence;
  gdouble masse;
  gdouble electronegativity;
  SData *sdata=(SData*)data;


  Symb = (gchar *)sdata->Symb;
  temp = gtk_entry_get_text(GTK_ENTRY(EntryProp[DISPLAY_RADII]));
  if(!test(temp))
  {
	Message("ERROR : the entry text is not a number","Warning",TRUE);
	return;
  }
  else radii = atof(temp)/BOHR_TO_ANG;

  temp = gtk_entry_get_text(GTK_ENTRY(EntryProp[COVALENT_RADII]));
  if(!test(temp))
  {
	Message("ERROR : the entry text is not a number","Warning",TRUE);
	return;
  }
  else covalentRadii = atof(temp)/BOHR_TO_ANG;

  temp = gtk_entry_get_text(GTK_ENTRY(EntryProp[VANDERWALS_RADII]));
  if(!test(temp))
  {
	Message("ERROR : the entry text is not a number","Warning",TRUE);
	return;
  }
  else vanDerWaalsRadii = atof(temp)/BOHR_TO_ANG;

  temp = gtk_entry_get_text(GTK_ENTRY(EntryProp[MAXIMUM_BOND_VALENCE]));
  if(!test(temp))
  {
	Message("ERROR : the entry text is not a number","Warning",TRUE);
	return;
  }
  else maximumBondValence = atoi(temp);

  temp = gtk_entry_get_text(GTK_ENTRY(EntryProp[MASSE]));
  if(!test(temp))
  {
	Message("ERROR : the entry text is not a number","Wrning",TRUE);
	return;
  }
  else masse = atof(temp);

  temp = gtk_entry_get_text(GTK_ENTRY(EntryProp[ELECTRONEGATIVITY]));
  if(!test(temp))
  {
	Message("ERROR : the entry text is not a number","Wrning",TRUE);
	return;
  }
  else electronegativity = atof(temp)/27.21;

/*  g_free(temp);*/
 
  for(i=0;i<NATOMS;i++)
  {
	if (!strcmp(Symb,AtomsProp[i].symbol))
 	{
	 	AtomsProp[i].radii = radii;
	 	AtomsProp[i].covalentRadii = covalentRadii;
	 	AtomsProp[i].vanDerWaalsRadii = vanDerWaalsRadii;
	 	AtomsProp[i].maximumBondValence = maximumBondValence;
	 	AtomsProp[i].masse = masse;
	 	AtomsProp[i].electronegativity = electronegativity;

		set_color_atom(ColorTemp,Symb);
		sdata->Style=set_button_style(sdata->Style,sdata->Button,Symb);

		if(ZoneDessin != NULL) rafresh_drawing();
		rafresh_window_orb();
		return; 
	}
  }
}
/********************************************************************************/
static GtkWidget *Add_Label_Table(GtkWidget *Table,gchar *label,gushort line,gushort colonne)
{
	GtkWidget *Label;
	GtkWidget *Hbox;
	
	Label = gtk_label_new (label);
   	gtk_label_set_justify(GTK_LABEL(Label),GTK_JUSTIFY_LEFT);
	Hbox = gtk_hbox_new (FALSE, 2);
	gtk_box_pack_start (GTK_BOX (Hbox), Label, FALSE, FALSE, 4);

	gtk_table_attach(GTK_TABLE(Table),Hbox,colonne,colonne+1,line,line+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	return Label;
}
/******************************************************************/
static void dialog_set_atom_prop(GtkWidget *w,gpointer data)
{
  GtkWidget *Dialogue;
  GtkWidget *Bouton;
  GtkWidget *frame;
  GtkWidget *vboxframe;
  GtkWidget *Table;
  SAtomsProp Prop;
  gchar *temp;
  gchar *tlabel[]={"Display radius", "Covalent radii", "Van der Waals radius", "Maximum bond valence", "Masse" , "Electronegativity"};
  SData *sdata ;
  SData *tdata ;
  GtkStyle *style;
  gint i;
  GtkWidget* comboMaxValence;
  
  
  sdata = (SData *)data;

  Prop = prop_atom_get(sdata->Symb);
  ColorTemp = Prop.color;
  
  Dialogue = gtk_dialog_new();
  temp = g_strdup_printf("Set properties of %s atom",sdata->Symb);
  gtk_window_set_title(GTK_WINDOW(Dialogue),temp);
  gtk_window_set_position(GTK_WINDOW(Dialogue),GTK_WIN_POS_CENTER);
  gtk_window_set_transient_for(GTK_WINDOW(Dialogue),GTK_WINDOW(sdata->Window));
  gtk_window_set_modal (GTK_WINDOW (Dialogue), TRUE);
  g_signal_connect(G_OBJECT(Dialogue), "delete_event",(GCallback)destroy_button_windows,NULL);
  g_signal_connect(G_OBJECT(Dialogue), "delete_event",G_CALLBACK(gtk_widget_destroy),NULL);

  frame = gtk_frame_new (sdata->Symb);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 10);
  gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Dialogue)->vbox), frame,TRUE,TRUE,0);

  gtk_widget_show (frame);

  vboxframe = create_vbox(frame);

  Table = gtk_table_new(7,4,FALSE);

  gtk_box_pack_start(GTK_BOX(vboxframe), Table,TRUE,TRUE,0);

  i = 0;
  Add_Label_Table(Table,"Name",i,0);
  Add_Label_Table(Table,":",i,1);
  Add_Label_Table(Table,Prop.name,i,2);

  i++;
  Add_Label_Table(Table,"Symbol",i,0);
  Add_Label_Table(Table,":",i,1);
  Add_Label_Table(Table,sdata->Symb,i,2);

  i++;
  Add_Label_Table(Table,"Atomic Number",i,0);
  Add_Label_Table(Table,":",i,1);
  temp = g_strdup_printf("%d",Prop.atomicNumber);
  Add_Label_Table(Table,temp,i,2);

  /* Display radius */
  i++;
  Add_Label_Table(Table,tlabel[DISPLAY_RADII],i,0);
  Add_Label_Table(Table,":",i,1);
  EntryProp[DISPLAY_RADII] = gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(EntryProp[DISPLAY_RADII]),80,-1);
  gtk_table_attach(GTK_TABLE(Table),EntryProp[DISPLAY_RADII],2,3,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 1,1);
  temp = g_strdup_printf("%f",Prop.radii*BOHR_TO_ANG);
  gtk_entry_set_text(GTK_ENTRY(EntryProp[DISPLAY_RADII]),temp);
  Add_Label_Table(Table,"Angstroms",i,3);

  /* Covalent radii */
  i++;
  Add_Label_Table(Table,tlabel[COVALENT_RADII],i,0);
  Add_Label_Table(Table,":",i,1);
  EntryProp[COVALENT_RADII] = gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(EntryProp[COVALENT_RADII]),80,-1);
  gtk_table_attach(GTK_TABLE(Table),EntryProp[COVALENT_RADII],2,3,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 1,1);
  temp = g_strdup_printf("%f",Prop.covalentRadii*BOHR_TO_ANG);
  gtk_entry_set_text(GTK_ENTRY(EntryProp[COVALENT_RADII]),temp);
  Add_Label_Table(Table,"Angstroms",i,3);

  /* Van der Waals radius */
  i++;
  Add_Label_Table(Table,tlabel[VANDERWALS_RADII],i,0);
  Add_Label_Table(Table,":",i,1);
  EntryProp[VANDERWALS_RADII] = gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(EntryProp[VANDERWALS_RADII]),80,-1);
  gtk_table_attach(GTK_TABLE(Table),EntryProp[VANDERWALS_RADII],2,3,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 1,1);
  temp = g_strdup_printf("%f",Prop.vanDerWaalsRadii*BOHR_TO_ANG);
  gtk_entry_set_text(GTK_ENTRY(EntryProp[VANDERWALS_RADII]),temp);
  Add_Label_Table(Table,"Angstroms",i,3);

  /* Maximum bond valence */
  i++;
  Add_Label_Table(Table,tlabel[MAXIMUM_BOND_VALENCE],i,0);
  Add_Label_Table(Table,":",i,1);
  {
	gint m = 30;
  	gchar **maxValence = g_malloc(30*sizeof(gchar*));
	gint k;

  	for(k=0; k<m; k++) maxValence[k] = g_strdup_printf("%d",k);
	comboMaxValence = create_combo_box_entry(maxValence, m, FALSE,-1,-1);
	EntryProp[MAXIMUM_BOND_VALENCE] = (GTK_BIN (comboMaxValence)->child);
  	for(k=0; k<m; k++) g_free(maxValence[k]);
	g_free(maxValence);
  }
  gtk_widget_set_size_request(GTK_WIDGET(EntryProp[MAXIMUM_BOND_VALENCE]),80,-1);
  /*
  gtk_table_attach(GTK_TABLE(Table),EntryProp[MAXIMUM_BOND_VALENCE],2,3,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 1,1);
  */
  gtk_table_attach(GTK_TABLE(Table),comboMaxValence,2,3,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 1,1);
  temp = g_strdup_printf("%d",Prop.maximumBondValence);
  gtk_entry_set_text(GTK_ENTRY(EntryProp[MAXIMUM_BOND_VALENCE]),temp);
  Add_Label_Table(Table," ",i,3);


  /* Masse */
  i++;
  Add_Label_Table(Table,tlabel[MASSE],i,0);
  Add_Label_Table(Table,":",i,1);
  EntryProp[MASSE] = gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(EntryProp[MASSE]),80,-1);
  gtk_table_attach(GTK_TABLE(Table),EntryProp[MASSE],2,3,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 1,1);
  temp = g_strdup_printf("%f",Prop.masse);
  gtk_entry_set_text(GTK_ENTRY(EntryProp[MASSE]),temp);
  Add_Label_Table(Table,"uam(12C)",i,3);

  /* "Electronegativity"*/
  i++;
  Add_Label_Table(Table,tlabel[ELECTRONEGATIVITY],i,0);
  Add_Label_Table(Table,":",i,1);
  EntryProp[ELECTRONEGATIVITY] = gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(EntryProp[ELECTRONEGATIVITY]),80,-1);
  gtk_table_attach(GTK_TABLE(Table),EntryProp[ELECTRONEGATIVITY],2,3,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 1,1);
  temp = g_strdup_printf("%f",Prop.electronegativity/27.21);
  gtk_entry_set_text(GTK_ENTRY(EntryProp[ELECTRONEGATIVITY]),temp);
  Add_Label_Table(Table,"eV",i,3);

  i++;
  Add_Label_Table(Table,"Atom Color",i,0);
  Add_Label_Table(Table,":",i,1);

  Bouton = gtk_button_new_with_label("Set Color");
  style=set_button_style(sdata->Style,Bouton,sdata->Symb);
  tdata=g_malloc(sizeof(SData));
  tdata->Window = Dialogue;
  tdata->Symb = g_strdup(sdata->Symb);
  tdata->Button =Bouton;
  tdata->Style =style;
  gtk_table_attach(GTK_TABLE(Table),Bouton,2,3,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 1,1);
  g_signal_connect(G_OBJECT(Bouton), "clicked", (GCallback)open_color_dlg_atoms, (gpointer)tdata);

  gtk_widget_realize(Dialogue);

  Bouton = create_button(Dialogue,"Cancel");
  gtk_box_pack_start( GTK_BOX(GTK_DIALOG(Dialogue)->action_area), Bouton,TRUE,TRUE,0);
  g_signal_connect_swapped(G_OBJECT(Bouton), "clicked",(GCallback)destroy_button_windows,GTK_OBJECT(Dialogue));
  g_signal_connect_swapped(G_OBJECT(Bouton), "clicked",(GCallback)gtk_widget_destroy,GTK_OBJECT(Dialogue));
  GTK_WIDGET_SET_FLAGS(Bouton, GTK_CAN_DEFAULT);

  Bouton = create_button(Dialogue,"OK");
  gtk_box_pack_start( GTK_BOX(GTK_DIALOG(Dialogue)->action_area), Bouton,TRUE,TRUE,0);
  g_signal_connect(G_OBJECT(Bouton), "clicked", (GCallback)set_atom_prop, sdata);
  g_signal_connect_swapped(G_OBJECT(Bouton), "clicked",(GCallback)destroy_button_windows,GTK_OBJECT(Dialogue));
  g_signal_connect_swapped(G_OBJECT(Bouton), "clicked",(GCallback)gtk_widget_destroy,GTK_OBJECT(Dialogue));
  GTK_WIDGET_SET_FLAGS(Bouton, GTK_CAN_DEFAULT);
  gtk_widget_grab_default(Bouton);
    
  add_button_windows(" Set properties ",Dialogue);
  gtk_widget_show_all(Dialogue);
  g_free(temp);
}
/******************************************************************/
GtkStyle *set_button_style( GtkStyle *button_style,GtkWidget *button,gchar *Symb)
{
          SAtomsProp Pro=prop_atom_get(Symb);
	  GtkStyle *style;
          style =  gtk_style_copy(button_style); 
          style->bg[0].red=Pro.color.red;
          style->bg[0].green=Pro.color.green;
          style->bg[0].blue=Pro.color.blue;
	  gtk_widget_set_style(button, style );
          return style;
}
/******************************************************************/
gchar*** get_periodic_table()
{
	static const gchar *table0[PERIODIC_TABLE_N_COLUMNS][PERIODIC_TABLE_N_ROWS]={
		{"H" ,"Li","Na","K" ,"Rb","Cs","Fr","00","00","00"},
		{"00","Be","Mg","Ca","Sr","Ba","Ra","00","X","00"},
		{"00","00","00","Sc","Y" ,"La","Ac","00","00","00"},
		{"00","00","00","Ti","Zr","Hf","Rf","00","00","00"},
		{"00","00","00","V" ,"Nb","Ta","Db","Ce","Th","00"},
		{"00","00","00","Cr","Mo","W" ,"Sg","Pr","Pa","00"},
		{"00","00","00","Mn","Tc","Re","Bh","Nd","U" ,"00"},
		{"00","00","00","Fe","Ru","Os","Hs","Pm","Np","00"},
		{"00","00","00","Co","Rh","Ir","Mt","Sm","Pu","00"},
		{"00","00","00","Ni","Pd","Pt","00","Eu","Am","00"},
		{"00","00","00","Cu","Ag","Au","00","Gd","Cm","00"},
		{"00","00","00","Zn","Cd","Hg","00","Tb","Bk","00"},
		{"00","B" ,"Al","Ga","In","Tl","00","Dy","Cf","00"},
		{"00","C" ,"Si","Ge","Sn","Pb","00","Ho","Es","00"},
		{"00","N" ,"P" ,"As","Sb","Bi","00","Er","Fm","00"},
		{"00","O" ,"S" ,"Se","Te","Po","00","Tm","Md","00"},
		{"00","F" ,"Cl","Br","I" ,"At","00","Yb","No","00"},
		{"He","Ne","Ar","Kr","Xe","Rn","00","Lu","Lr","00"},
		};
	static gchar*** table = NULL;
	if(table == NULL)
	{
		gint i;
		gint j;
		table = g_malloc(PERIODIC_TABLE_N_COLUMNS*sizeof(gchar**));
		for(i=0;i<PERIODIC_TABLE_N_COLUMNS;i++)
		{
			table[i] = g_malloc(PERIODIC_TABLE_N_ROWS*sizeof(gchar*));
			for(j=0;j<PERIODIC_TABLE_N_ROWS;j++)
				table[i][j] = g_strdup(table0[i][j]);
		}
	}
	return table;
}
/******************************************************************/
void create_table_prop_in_window(GtkWidget *WinTable, GtkWidget *frame)
{
	GtkWidget* Table;
	GtkWidget* button;
	guint i;
	guint j;

       GtkStyle *button_style = gtk_widget_get_style(WinTable); 
       GtkStyle *style;

	gchar*** Symb = get_periodic_table();
	SData *sdata[18][10];


	Table = gtk_table_new(PERIODIC_TABLE_N_ROWS-1,PERIODIC_TABLE_N_COLUMNS,TRUE);
	gtk_container_add(GTK_CONTAINER(frame),Table);
  
	for ( i = 0;i<PERIODIC_TABLE_N_ROWS-1;i++)
	for ( j = 0;j<PERIODIC_TABLE_N_COLUMNS;j++)
	{
		if(strcmp(Symb[j][i],"00"))
		{
			button = gtk_button_new_with_label(Symb[j][i]);
			style=set_button_style(button_style,button,Symb[j][i]);

			sdata[j][i]=g_malloc(sizeof(SData));
			sdata[j][i]->Window = WinTable;
			sdata[j][i]->Symb = g_strdup(Symb[j][i]);
			sdata[j][i]->Button =button;
			sdata[j][i]->Style =style;
			g_signal_connect(G_OBJECT(button), "clicked", (GCallback)dialog_set_atom_prop,(gpointer )sdata[j][i]);
			gtk_table_attach(GTK_TABLE(Table),button,j,j+1,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
		}
	}
}
/******************************************************************/
void create_table_prop()
{
   GtkWidget *WinTable;
   GtkWidget *frame;
   GtkWidget *vbox;
   GtkWidget *hbox;
   GtkWidget* button;

  WinTable = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(WinTable),"Select your atom");
  gtk_window_set_position(GTK_WINDOW(WinTable),GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW(WinTable),(gint)(ScreenWidth*0.5),(gint)(ScreenHeight*0.4));

  g_signal_connect(G_OBJECT(WinTable), "delete_event", (GCallback)destroy_button_windows, NULL);
  g_signal_connect(G_OBJECT(WinTable), "delete_event", (GCallback)gtk_widget_destroy, NULL);

  vbox = gtk_vbox_new (FALSE, 2);
  gtk_container_add(GTK_CONTAINER(WinTable),vbox);
  
  hbox = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);

  frame = gtk_frame_new (NULL);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 0);
  gtk_container_add(GTK_CONTAINER(hbox),frame);  
  gtk_widget_show (frame);

  create_table_prop_in_window(WinTable,frame);

  hbox = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 2);
  gtk_widget_realize(WinTable);
  button = create_button(WinTable,"CLOSE");
  gtk_box_pack_end (GTK_BOX (hbox), button, FALSE, FALSE, 2);
  g_signal_connect_swapped(G_OBJECT(button),"clicked", (GCallback)destroy_button_windows, GTK_OBJECT(WinTable));
  g_signal_connect_swapped(G_OBJECT(button), "clicked", (GCallback)gtk_widget_destroy, GTK_OBJECT(WinTable));
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_widget_grab_default(button);
  gtk_widget_show(button);
  
  add_button_windows(" Properties ",WinTable);

  gtk_widget_show_all(WinTable);
}
/********************************************************************************/
void create_table_prop_in_vbox(GtkWidget *WinTable,GtkWidget *Vbox)
{
   GtkWidget *frame;

  frame = gtk_frame_new (NULL);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 10);
  gtk_container_add(GTK_CONTAINER(Vbox),frame);  
  gtk_widget_show (frame);

  create_table_prop_in_window(WinTable,frame);

  gtk_widget_show_all(WinTable);
}
/******************************************************************/

