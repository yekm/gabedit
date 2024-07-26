/* FragmentsPPD.c */
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
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "../Geometry/Fragments.h"

#define ANG_TO_BOHR  1.0/0.52917726
/*****************************************************************/
static void SetResidue(Fragment* Frag,gchar* name)
{
	gint i;
	for(i=0;i<Frag->NAtoms;i++)
		Frag->Atoms[i].Residue = g_strdup(name);

}
/*****************************************************************/
static void SetAtom(Atom* A,gchar* symb,gfloat x,gfloat y,gfloat z,gfloat charge)
{
	A->Type = g_strdup(symb);
	A->Symb = g_strdup_printf("%c",toupper(symb[0]));

	A->Coord[0] = (gdouble)x*(gdouble)ANG_TO_BOHR;
	A->Coord[1] = (gdouble)y*(gdouble)ANG_TO_BOHR;
	A->Coord[2] = (gdouble)z*(gdouble)ANG_TO_BOHR;
	A->Charge = charge;
}

/*****************************************************************/
Fragment GetFragmentPPD(gchar* Name)
{
	Fragment F;
	gchar T[100]="UNK";
	gint i;

	F.NAtoms = 0;
	F.Atoms = NULL;
	F.atomToDelete = -1;
	F.atomToBondTo = -1;
	F.angleAtom    = -1;

	if ( !strcmp(Name, "Lace" ) ){
		F.NAtoms =  6 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "H1", 0.000f, 0.000f, 0.000f,0.000f );
                SetAtom(&F.Atoms[ 1 ], "CH3", 0.000f, 1.090f, 0.000f,0.000f );
                SetAtom(&F.Atoms[ 2 ], "H2", 1.028f, 1.453f, 0.000f,0.000f );
                SetAtom(&F.Atoms[ 3 ], "H3", -0.514f, 1.453f, -0.890f,0.000f );
                SetAtom(&F.Atoms[ 4 ], "C", -0.721f, 1.600f, 1.249f, 0.616f );
                SetAtom(&F.Atoms[ 5 ], "O", -0.839f, 2.806f, 1.453f, -0.504f );
	}
	else if ( !strcmp(Name, "Lala" ) ){
		F.NAtoms =  10 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
        	SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
                SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.580f, -1.780f, 1.205f, 0.036f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.077f, -0.816f, 1.241f, 0.036f );
				SetAtom(&F.Atoms[ 9 ], "HB3", 1.638f, -0.260f, 2.131f, 0.036f );
	}
	else if ( !strcmp(Name, "Larg" ) ){
		F.NAtoms = 24 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.080f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.077f, -0.816f, 1.241f, 0.056f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.638f, -0.260f, 2.131f, 0.056f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.418f, -2.182f, 1.194f, -0.103f );
                SetAtom(&F.Atoms[ 10 ], "HG1", 0.329f, -2.136f, 1.186f, 0.074f );
                SetAtom(&F.Atoms[ 11 ], "HG2", 1.767f, -2.692f, 0.296f, 0.074f );
                SetAtom(&F.Atoms[ 12 ], "CD", 1.884f, -2.951f, 2.427f, -0.228f );
                SetAtom(&F.Atoms[ 13 ], "HD1", 2.973f, -2.984f, 2.445f, 0.133f );
                SetAtom(&F.Atoms[ 14 ], "HD2", 1.511f, -2.438f, 3.314f, 0.133f );
                SetAtom(&F.Atoms[ 15 ], "NE", 1.349f, -4.332f, 2.424f, -0.324f );
                SetAtom(&F.Atoms[ 16 ], "HE", 0.761f, -4.619f, 1.655f, 0.269f );
                SetAtom(&F.Atoms[ 17 ], "CZ", 1.606f, -5.209f, 3.389f, 0.760f );
                SetAtom(&F.Atoms[ 18 ], "NH1", 2.372f, -4.905f, 4.434f, -0.624f );
                SetAtom(&F.Atoms[ 19 ], "HH11", 2.774f, -3.982f, 4.509f, 0.361f );
                SetAtom(&F.Atoms[ 20 ], "HH12", 2.546f, -5.597f, 5.148f, 0.361f );
                SetAtom(&F.Atoms[ 21 ], "NH2", 1.074f, -6.424f, 3.287f, -0.624f );
		SetAtom(&F.Atoms[ 22 ], "HH21", 0.494f, -6.653f, 2.493f, 0.361f );
                SetAtom(&F.Atoms[ 23 ], "HH22", 1.252f, -7.113f, 4.004f, 0.361f );
	}
	else if ( !strcmp(Name, "Lasn" ) ){
		F.NAtoms =  14 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.086f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.077f, -0.800f, 1.251f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.613f, -0.256f, 2.118f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.439f, -2.188f, 1.232f, 0.675f );
                SetAtom(&F.Atoms[ 10 ], "OD1", 0.720f, -2.579f, 0.315f, -0.470f );
                SetAtom(&F.Atoms[ 11 ], "ND2", 1.780f, -2.961f, 2.266f, -0.867f );
                SetAtom(&F.Atoms[ 12 ], "HD21", 2.374f, -2.591f, 2.995f, 0.344f );
                SetAtom(&F.Atoms[ 13 ], "HD22", 1.443f, -3.912f, 2.315f, 0.344f );
	}
	else if ( !strcmp(Name, "Lasp" ) ){
		F.NAtoms =  12 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.398f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.077f, -0.816f, 1.241f, 0.071f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.638f, -0.260f, 2.131f, 0.071f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.417f, -2.185f, 1.194f, 0.714f );
                SetAtom(&F.Atoms[ 10 ], "OD1", 2.107f, -3.069f, 0.620f, -0.721f );
                SetAtom(&F.Atoms[ 11 ], "OD2", 0.297f, -2.369f, 1.741f, -0.721f );
	}
	else if ( !strcmp(Name, "Lcys" ) ){
		F.NAtoms =  11 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.060f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.076f, -0.748f, 1.283f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.528f, -0.252f, 2.075f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "SG", 1.409f, -2.479f, 1.367f, -0.135f );
                SetAtom(&F.Atoms[ 10 ], "HG", 1.890f, -3.023f, 2.481f, 0.135f );
	}
	else if ( !strcmp(Name, "Lcyx" ) ){
		F.NAtoms =  10 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.076f, -0.748f, 1.283f, 0.0495f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.528f, -0.252f, 2.075f, 0.0495f );
                SetAtom(&F.Atoms[ 9 ], "SG", 1.409f, -2.479f, 1.367f, 0.015f );
	}
	else if ( !strcmp(Name, "Lgln" ) ){
		F.NAtoms =  17 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.077f, -0.816f, 1.241f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.638f, -0.260f, 2.131f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.418f, -2.182f, 1.194f, -0.102f );
                SetAtom(&F.Atoms[ 10 ], "HG1", 0.330f, -2.135f, 1.168f, 0.057f );
                SetAtom(&F.Atoms[ 11 ], "HG2", 1.792f, -2.681f, 0.300f, 0.057f );
                SetAtom(&F.Atoms[ 12 ], "CD", 1.861f, -2.984f, 2.410f, 0.675f );
                SetAtom(&F.Atoms[ 13 ], "OE1", 2.585f, -2.476f, 3.263f, -0.470f );
                SetAtom(&F.Atoms[ 14 ], "NE2", 1.422f, -4.243f, 2.489f, -0.867f );
                SetAtom(&F.Atoms[ 15 ], "HE21", 0.828f, -4.614f, 1.761f, 0.344f );
                SetAtom(&F.Atoms[ 16 ], "HE22", 1.687f, -4.819f, 3.275f, 0.344f );
	}
	else if ( !strcmp(Name, "Lglu" ) ){
		F.NAtoms =  15 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.184f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.077f, -0.816f, 1.241f, 0.092f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.638f, -0.260f, 2.131f, 0.092f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.423f, -2.168f, 1.195f, -0.398f );
                SetAtom(&F.Atoms[ 10 ], "HG1", 0.334f, -2.122f, 1.187f, 0.071f );
                SetAtom(&F.Atoms[ 11 ], "HG2", 1.772f, -2.678f, 0.296f, 0.071f );
                SetAtom(&F.Atoms[ 12 ], "CD", 1.890f, -2.939f, 2.429f, 0.714f );
                SetAtom(&F.Atoms[ 13 ], "OE1", 1.161f, -2.878f, 3.455f, -0.721f );
                SetAtom(&F.Atoms[ 14 ], "OE2", 2.971f, -3.578f, 2.334f, -0.721f );
	}
	else if ( !strcmp(Name, "Lgly" ) ){
		F.NAtoms =  7 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.027f, 1.358f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.697f, 1.839f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA1", 1.886f, -0.523f, -0.885f, 0.032f );
                SetAtom(&F.Atoms[ 4 ], "HA2", 1.874f, -0.506f, 0.899f, 0.032f);
		SetAtom(&F.Atoms[ 5 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
                SetAtom(&F.Atoms[ 6 ], "O", -0.624f, 1.058f, 0.000f, -0.504f );
	}
	else if ( !strcmp(Name, "Lhid" ) ){
		F.NAtoms =  17 ;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.076f, -0.759f, 1.276f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.547f, -0.251f, 2.084f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, 1.321f, -0.032f );
                SetAtom(&F.Atoms[ 10 ], "ND1", 1.829f, -3.024f, 2.383f, -0.146f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.411f, -2.777f, 3.169f, 0.228f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.698f, -2.921f, 0.493f, 0.195f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.306f, -2.473f, -0.421f, 0.018f );
                SetAtom(&F.Atoms[ 14 ], "CE1", 1.252f, -4.194f, 2.183f, 0.241f );
                SetAtom(&F.Atoms[ 15 ], "HE1", 1.387f, -5.000f, 2.905f, 0.036f );
                SetAtom(&F.Atoms[ 16 ], "NE2", 0.576f, -4.150f, 1.061f, -0.502f );
	}
	else if ( !strcmp(Name, "Lhie" ) ){
		F.NAtoms =  17;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.076f, -0.759f, 1.276f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.547f, -0.251f, 2.084f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, 1.321f, 0.251f );
                SetAtom(&F.Atoms[ 10 ], "ND1", 1.829f, -3.024f, 2.383f, -0.502f );
                SetAtom(&F.Atoms[ 11 ], "CD2", 0.698f, -2.921f, 0.493f, -0.184f );
                SetAtom(&F.Atoms[ 12 ], "HD2", 0.306f, -2.473f, -0.421f, 0.114f );
                SetAtom(&F.Atoms[ 13 ], "CE1", 1.252f, -4.194f, 2.183f, 0.241f );
                SetAtom(&F.Atoms[ 14 ], "HE1", 1.387f, -5.000f, 2.905f, 0.036f );
                SetAtom(&F.Atoms[ 15 ], "NE2", 0.576f, -4.150f, 1.061f, -0.146f );
                SetAtom(&F.Atoms[ 16 ], "HE2", 0.041f, -4.916f, 0.677f, 0.228f );
	}
	else if ( !strcmp(Name, "Lhip" ) ){
		F.NAtoms = 18;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.076f, -0.759f, 1.276f, 0.086f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.547f, -0.251f, 2.084f, 0.086f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, 1.321f, 0.058f );
                SetAtom(&F.Atoms[ 10 ], "ND1", 1.829f, -3.024f, 2.383f, -0.058f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.411f, -2.777f, 3.169f, 0.306f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.698f, -2.921f, 0.493f, -0.037f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.306f, -2.473f, -0.421f, 0.153f );
                SetAtom(&F.Atoms[ 14 ], "CE1", 1.252f, -4.194f, 2.183f, 0.114f );
                SetAtom(&F.Atoms[ 15 ], "HE1", 1.387f, -5.000f, 2.905f, 0.158f );
                SetAtom(&F.Atoms[ 16 ], "NE2", 0.576f, -4.150f, 1.061f, -0.058f );
                SetAtom(&F.Atoms[ 17 ], "HE2", 0.041f, -4.916f, 0.677f, 0.306f );
	}
	else if ( !strcmp(Name, "Lhis" ) ){
		F.NAtoms =  18;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.076f, -0.759f, 1.276f, 0.086f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.547f, -0.251f, 2.084f, 0.086f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, 1.321f, 0.058f );
                SetAtom(&F.Atoms[ 10 ], "ND1", 1.829f, -3.024f, 2.383f, -0.058f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.411f, -2.777f, 3.169f, 0.306f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.698f, -2.921f, 0.493f, -0.037f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.248f, -2.587f, -0.442f, 0.153f );
                SetAtom(&F.Atoms[ 14 ], "CE1", 1.252f, -4.194f, 2.183f, 0.114f );
                SetAtom(&F.Atoms[ 15 ], "HE1", 1.327f, -5.058f, 2.843f, 0.158f );
                SetAtom(&F.Atoms[ 16 ], "NE2", 0.576f, -4.150f, 1.061f, -0.058f );
                SetAtom(&F.Atoms[ 17 ], "HE2", 0.041f, -4.916f, 0.677f, 0.306f );
	}
	else if ( !strcmp(Name, "Lile" ) ){
		F.NAtoms =  19;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.875f, -0.500f, -0.902f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 2.009f, -0.733f, 1.245f, -0.012f );
                SetAtom(&F.Atoms[ 7 ], "HB", 3.098f, -0.765f, 1.245f, 0.022f );
                SetAtom(&F.Atoms[ 8 ], "CG1", 1.459f, -2.156f, 1.245f, -0.049f );
                SetAtom(&F.Atoms[ 9 ], "HG11", 0.370f, -2.124f, 1.245f, 0.027f );
                SetAtom(&F.Atoms[ 10 ], "HG12", 1.807f, -2.680f, 0.355f, 0.027f );
                SetAtom(&F.Atoms[ 11 ], "CG2", 1.522f, 0.000f, 2.491f, -0.085f );
                SetAtom(&F.Atoms[ 12 ], "HG21", 1.870f, -0.524f, 3.381f, 0.029f );
                SetAtom(&F.Atoms[ 13 ], "HG22", 1.914f, 1.017f, 2.490f, 0.029f );
                SetAtom(&F.Atoms[ 14 ], "HG23", 0.432f, 0.032f, 2.491f, 0.029f );
                SetAtom(&F.Atoms[ 15 ], "CD1", 1.947f, -2.889f, 2.491f, -0.085f );
                SetAtom(&F.Atoms[ 16 ], "HD11", 1.554f, -3.906f, 2.490f, 0.028f );
                SetAtom(&F.Atoms[ 17 ], "HD12", 3.036f, -2.921f, 2.491f, 0.028f);
                SetAtom(&F.Atoms[ 18 ], "HD13", 1.599f, -2.365f, 3.381f, 0.028f );
	}
	else if ( !strcmp(Name, "Lleu" ) ){
		F.NAtoms =  19;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.061f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.077f, -0.816f, 1.241f, 0.033f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.638f, -0.260f, 2.131f, 0.033f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.418f, -2.182f, 1.194f, -0.010f );
                SetAtom(&F.Atoms[ 10 ], "HG", 0.329f, -2.136f, 1.186f, 0.031f );
                SetAtom(&F.Atoms[ 11 ], "CD1", 1.906f, -2.894f, -0.063f, -0.107f );
                SetAtom(&F.Atoms[ 12 ], "HD11", 1.499f, -3.905f, -0.090f, 0.034f );
                SetAtom(&F.Atoms[ 13 ], "HD12", 1.573f, -2.345f, -0.943f, 0.034f );
                SetAtom(&F.Atoms[ 14 ], "HD13", 2.995f, -2.941f, -0.055f, 0.034f );
                SetAtom(&F.Atoms[ 15 ], "CD2", 1.884f, -2.951f, 2.427f, -0.107f );
                SetAtom(&F.Atoms[ 16 ], "HD21", 1.476f, -3.962f, 2.400f, 0.034f );
                SetAtom(&F.Atoms[ 17 ], "HD22", 2.973f, -2.998f, 2.436f, 0.034f );
                SetAtom(&F.Atoms[ 18 ], "HD23", 1.534f, -2.443f, 3.325f, 0.034f );
	}
	else if ( !strcmp(Name, "Llys" ) ){
		F.NAtoms =  22;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.077f, -0.816f, 1.241f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.638f, -0.260f, 2.131f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.418f, -2.182f, 1.194f, -0.160f );
                SetAtom(&F.Atoms[ 10 ], "HG1", 0.329f, -2.136f, 1.186f, 0.116f );
                SetAtom(&F.Atoms[ 11 ], "HG2", 1.767f, -2.692f, 0.296f, 0.116f );
                SetAtom(&F.Atoms[ 12 ], "CD", 1.884f, -2.951f, 2.427f, -0.180f );
                SetAtom(&F.Atoms[ 13 ], "HD1", 2.973f, -2.998f, 2.436f, 0.122f );
                SetAtom(&F.Atoms[ 14 ], "HD2", 1.534f, -2.443f, 3.325f, 0.122f );
                SetAtom(&F.Atoms[ 15 ], "CE", 1.314f, -4.366f, 2.389f, -0.038f );
                SetAtom(&F.Atoms[ 16 ], "HE1", 0.225f, -4.318f, 2.381f, 0.098f );
                SetAtom(&F.Atoms[ 17 ], "HE2", 1.663f, -4.874f, 1.491f, 0.098f );
                SetAtom(&F.Atoms[ 18 ], "NZ", 1.763f, -5.107f, 3.577f, -0.138f );
                SetAtom(&F.Atoms[ 19 ], "HZ1", 1.385f, -6.042f, 3.552f, 0.294f );
                SetAtom(&F.Atoms[ 20 ], "HZ2", 2.772f, -5.150f, 3.585f, 0.294f );
                SetAtom(&F.Atoms[ 21 ], "HZ3", 1.440f, -4.635f, 4.409f, 0.294f );
	}
	else if ( !strcmp(Name, "Lmet" ) ){
		F.NAtoms =  17;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.151f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.077f, -0.816f, 1.241f, 0.027f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.638f, -0.260f, 2.131f, 0.027f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.418f, -2.182f, 1.194f, -0.054f );
                SetAtom(&F.Atoms[ 10 ], "HG1", 0.329f, -2.135f, 1.179f, 0.0652f );
                SetAtom(&F.Atoms[ 11 ], "HG2", 1.775f, -2.688f, 0.297f, 0.0652f );
                SetAtom(&F.Atoms[ 12 ], "SD", 1.962f, -3.109f, 2.652f, -0.025f );
                SetAtom(&F.Atoms[ 13 ], "CE", 1.167f, -4.670f, 2.341f, -0.134f );
                SetAtom(&F.Atoms[ 14 ], "HE1", 1.399f, -5.364f, 3.149f, 0.0652f );
                SetAtom(&F.Atoms[ 15 ], "HE2", 0.088f, -4.523f, 2.287f, 0.0652f );
                SetAtom(&F.Atoms[ 16 ], "HE3", 1.525f, -5.079f, 1.396f, 0.0652f );
	}
	else if ( !strcmp(Name, "Lnme" ) ){
		F.NAtoms =  6;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", -1.227f, 0.728f, 2.125f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", -1.124f, -0.261f, 1.947f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", -1.918f, 1.159f, 3.323f, 0.03502f );
                SetAtom(&F.Atoms[ 3 ], "HA1", -1.939f, 2.249f, 3.358f, 0.0586f );
                SetAtom(&F.Atoms[ 4 ], "HA2", -2.939f, 0.777f, 3.311f, 0.0586f );
		SetAtom(&F.Atoms[ 5 ], "HA3", -1.398f, 0.777f, 4.201f, 0.0586f );
	}
	else if ( !strcmp(Name, "Lphe" ) ){
		F.NAtoms =  20;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.100f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.076f, -0.759f, 1.276f, 0.108f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.547f, -0.251f, 2.084f, 0.108f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, 1.321f, -0.100f );
                SetAtom(&F.Atoms[ 10 ], "CD1", 1.856f, -2.993f, 2.410f, -0.150f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.497f, -2.589f, 3.194f, 0.150f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.669f, -2.712f, 0.315f, -0.150f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.385f, -2.087f, -0.533f, 0.150f );
                SetAtom(&F.Atoms[ 14 ], "CE1", 1.398f, -4.313f, 2.492f, -0.150f );
                SetAtom(&F.Atoms[ 15 ], "HE1", 1.681f, -4.937f, 3.340f, 0.150f );
                SetAtom(&F.Atoms[ 16 ], "CE2", 0.210f, -4.031f, 0.397f, -0.150f );
                SetAtom(&F.Atoms[ 17 ], "HE2", -0.431f, -4.435f, -0.386f, 0.150f );
                SetAtom(&F.Atoms[ 18 ], "CZ", 0.575f, -4.833f, 1.486f, -0.150f );
                SetAtom(&F.Atoms[ 19 ], "HZ", 0.217f, -5.860f, 1.550f, 0.150f );
	}
	else if ( !strcmp(Name, "Lpro" ) ){
		F.NAtoms =  14;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.068f, 1.413f, 0.000f, -0.229f );
                SetAtom(&F.Atoms[ 1 ], "CA", 1.523f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 2 ], "HA", 2.373f, -0.566f, -0.381f, 0.048f );
                SetAtom(&F.Atoms[ 3 ], "C", 0.000f, 0.000f, 0.000f, 0.526f );
                SetAtom(&F.Atoms[ 4 ], "O", -0.623f, 1.059f, -0.001f, -0.500f );
		SetAtom(&F.Atoms[ 5 ], "CB", 0.361f, 0.011f, 0.950f, -0.115f );
                SetAtom(&F.Atoms[ 6 ], "HB1", -0.547f, -0.274f, 0.417f, 0.061f );
                SetAtom(&F.Atoms[ 7 ], "HB2", 0.547f, -0.695f, 1.758f, 0.061f );
                SetAtom(&F.Atoms[ 8 ], "CG", 0.192f, 1.398f, 1.523f, -0.121f );
                SetAtom(&F.Atoms[ 9 ], "HG1", -0.781f, 1.794f, 1.235f, 0.063f );
                SetAtom(&F.Atoms[ 10 ], "HG2", 0.257f, 1.396f, 2.611f, 0.063f );
                SetAtom(&F.Atoms[ 11 ], "CD", 1.274f, 2.235f, 0.905f, -0.0012f );
                SetAtom(&F.Atoms[ 12 ], "HD1", 1.916f, 2.636f, 1.689f, 0.060f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.824f, 3.057f, 0.349f, 0.060f );
	}
	else if ( !strcmp(Name, "Lser" ) ){
		F.NAtoms =  11;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, 0.018f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.077f, -0.816f, 1.241f, 0.119f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.638f, -0.260f, 2.131f, 0.119f );
                SetAtom(&F.Atoms[ 9 ], "OG", 1.453f, -2.094f, 1.197f, -0.550f );
                SetAtom(&F.Atoms[ 10 ], "HG", 1.746f, -2.579f, 1.973f, 0.310f );
	}
	else if ( !strcmp(Name, "Lthr" ) ){
		F.NAtoms =  14;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, 0.170f );
                SetAtom(&F.Atoms[ 7 ], "HB", 1.580f, -1.780f, 1.205f, 0.082f );
                SetAtom(&F.Atoms[ 8 ], "OG1", 1.530f, -0.101f, 2.411f, -0.550f );
                SetAtom(&F.Atoms[ 9 ], "HG1", 1.823f, -0.585f, 3.187f, 0.310f );
                SetAtom(&F.Atoms[ 10 ], "CG2", 3.510f, -0.835f, 1.244f, -0.191f );
                SetAtom(&F.Atoms[ 11 ], "HG21", 3.844f, -1.384f, 2.125f, 0.065f );
                SetAtom(&F.Atoms[ 12 ], "HG22", 3.860f, -1.343f, 0.346f, 0.065f );
                SetAtom(&F.Atoms[ 13 ], "HG23", 3.918f, 0.177f, 1.271f, 0.065f );
	}
	else if ( !strcmp(Name, "Ltrp" ) ){
		F.NAtoms =  24;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.076f, -0.759f, 1.276f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.547f, -0.251f, 2.084f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, 1.321f, -0.0135f );
                SetAtom(&F.Atoms[ 10 ], "CD1", 1.752f, -3.078f, 2.293f, 0.044f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.365f, -2.906f, 3.178f, 0.093f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.669f, -2.868f, 0.412f, 0.146f );
                SetAtom(&F.Atoms[ 13 ], "NE1", 1.072f, -4.288f, 1.950f, -0.352f );
                SetAtom(&F.Atoms[ 14 ], "HE1", 1.079f, -5.139f, 2.493f, 0.271f );
                SetAtom(&F.Atoms[ 15 ], "CE2", 0.438f, -4.113f, 0.817f, 0.154f );
                SetAtom(&F.Atoms[ 16 ], "CE3", 0.103f, -2.412f, -0.785f, -0.173f );
                SetAtom(&F.Atoms[ 17 ], "HE3", 0.273f, -1.397f, -1.145f, 0.086f );
                SetAtom(&F.Atoms[ 18 ], "CZ2", -0.350f, -5.037f, 0.120f, -0.168f );
                SetAtom(&F.Atoms[ 19 ], "HZ2", -0.515f, -6.050f, 0.487f, 0.084f );
                SetAtom(&F.Atoms[ 20 ], "CZ3", -0.694f, -3.325f, -1.505f, -0.066f );
                SetAtom(&F.Atoms[ 21 ], "HZ3", -1.150f, -3.005f, -2.442f, 0.057f );
		SetAtom(&F.Atoms[ 22 ], "CH2", -0.912f, -4.584f, -1.069f, -0.077f );
                SetAtom(&F.Atoms[ 23 ], "HH2", -1.535f, -5.257f, -1.658f, 0.074f );
	}
	else if ( !strcmp(Name, "Ltyr" ) ){
		F.NAtoms =  21;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 3.077f, -0.816f, 1.241f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.638f, -0.260f, 2.131f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.423f, -2.168f, 1.195f, -0.030f );
                SetAtom(&F.Atoms[ 10 ], "CD1", 1.715f, -3.068f, 2.227f, -0.002f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.348f, -2.758f, 3.058f, 0.064f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.609f, -2.567f, 0.128f, -0.002f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.382f, -1.867f, -0.676f, 0.064f );
                SetAtom(&F.Atoms[ 14 ], "CE1", 1.192f, -4.367f, 2.193f, -0.264f );
                SetAtom(&F.Atoms[ 15 ], "HE1", 1.418f, -5.067f, 2.996f, 0.102f );
                SetAtom(&F.Atoms[ 16 ], "CE2", 0.086f, -3.866f, 0.093f, -0.264f );
                SetAtom(&F.Atoms[ 17 ], "HE2", -0.548f, -4.176f, -0.737f, 0.102f );
                SetAtom(&F.Atoms[ 18 ], "CZ", 0.378f, -4.766f, 1.126f, 0.462f );
                SetAtom(&F.Atoms[ 19 ], "OH", -0.131f, -6.026f, 1.092f, -0.528f );
                SetAtom(&F.Atoms[ 20 ], "HH", 0.132f, -6.557f, 1.849f, 0.334f );
	}
	else if ( !strcmp(Name, "Lval" ) ){
		F.NAtoms =  16;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, -0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, 1.233f, -0.012f );
                SetAtom(&F.Atoms[ 7 ], "HB", 3.077f, -0.816f, 1.241f, 0.024f );
                SetAtom(&F.Atoms[ 8 ], "CG1", 1.499f, -0.057f, 2.490f, -0.091f );
                SetAtom(&F.Atoms[ 9 ], "HG11", 1.832f, -0.606f, 3.370f, 0.031f );
                SetAtom(&F.Atoms[ 10 ], "HG12", 1.906f, 0.953f, 2.516f, 0.031f );
                SetAtom(&F.Atoms[ 11 ], "HG13", 0.410f, -0.010f, 2.481f, 0.031f );
                SetAtom(&F.Atoms[ 12 ], "CG2", 1.418f, -2.182f, 1.194f, -0.091f );
                SetAtom(&F.Atoms[ 13 ], "HG21", 1.751f, -2.732f, 2.075f, 0.031f );
                SetAtom(&F.Atoms[ 14 ], "HG22", 0.329f, -2.136f, 1.186f, 0.031f );
                SetAtom(&F.Atoms[ 15 ], "HG23", 1.767f, -2.692f, 0.296f, 0.031f );
	}
	else if ( !strcmp(Name, "Dace" ) ){
		F.NAtoms =  6;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "H1", 0.000f, 0.000f, 0.000f,0.000f );
                SetAtom(&F.Atoms[ 1 ], "CH3", 0.000f, 1.090f, 0.000f,0.000f );
                SetAtom(&F.Atoms[ 2 ], "H2", 1.028f, 1.453f, 0.000f,0.000f );
                SetAtom(&F.Atoms[ 3 ], "H3", -0.514f, 1.453f, -0.890f ,0.000f);
                SetAtom(&F.Atoms[ 4 ], "C", -0.721f, 1.600f, 1.249f, 0.616f);
		SetAtom(&F.Atoms[ 5 ], "O", -0.839f, 2.806f, 1.453f, -0.504f);
	}
	else if ( !strcmp(Name, "Dala" ) ){
		F.NAtoms =  10;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.580f, -1.779f, -1.205f, 0.036f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 1.638f, -0.260f, -2.131f, 0.036f );
                SetAtom(&F.Atoms[ 9 ], "HB3", 3.077f, -0.816f, -1.241f, 0.036f );
	}
	else if ( !strcmp(Name, "Darg" ) ){
		F.NAtoms =  24;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.080f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.638f, -0.260f, -2.131f, 0.056f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.077f, -0.816f, -1.241f, 0.056f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.418f, -2.183f, -1.195f, -0.103f );
                SetAtom(&F.Atoms[ 10 ], "HG1", 1.767f, -2.692f, -0.296f, 0.074f );
                SetAtom(&F.Atoms[ 11 ], "HG2", 0.328f, -2.136f, -1.186f, 0.074f );
                SetAtom(&F.Atoms[ 12 ], "CD", 1.884f, -2.951f, -2.427f, -0.228f );
                SetAtom(&F.Atoms[ 13 ], "HD1", 1.549f, -2.433f, -3.326f, 0.133f );
                SetAtom(&F.Atoms[ 14 ], "HD2", 2.972f, -3.004f, -2.410f, 0.133f );
                SetAtom(&F.Atoms[ 15 ], "NE", 1.348f, -4.332f, -2.424f, -0.324f );
                SetAtom(&F.Atoms[ 16 ], "HE", 0.761f, -4.619f, -1.655f, 0.269f );
                SetAtom(&F.Atoms[ 17 ], "CZ", 1.606f, -5.210f, -3.390f, 0.760f );
                SetAtom(&F.Atoms[ 18 ], "NH1", 2.371f, -4.905f, -4.434f, -0.624f );
                SetAtom(&F.Atoms[ 19 ], "HH11", 2.774f, -3.982f, -4.509f, 0.361f );
                SetAtom(&F.Atoms[ 20 ], "HH12", 2.545f, -5.597f, -5.148f, 0.361f );
                SetAtom(&F.Atoms[ 21 ], "NH2", 1.074f, -6.424f, -3.287f, -0.624f );
		SetAtom(&F.Atoms[ 22 ], "HH21", 0.494f, -6.652f, -2.492f, 0.361f );
                SetAtom(&F.Atoms[ 23 ], "HH22", 1.252f, -7.112f, -4.004f, 0.361f );
	}
	else if ( !strcmp(Name, "Dasn" ) ){
		F.NAtoms =  14;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.086f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.653f, -0.251f, -2.131f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.076f, -0.821f, -1.214f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.438f, -2.188f, -1.232f, 0.675f );
                SetAtom(&F.Atoms[ 10 ], "OD1", 0.720f, -2.579f, -0.316f, -0.470f );
                SetAtom(&F.Atoms[ 11 ], "ND2", 1.780f, -2.961f, -2.265f, -0.867f );
                SetAtom(&F.Atoms[ 12 ], "HD21", 2.374f, -2.591f, -2.994f, 0.344f );
                SetAtom(&F.Atoms[ 13 ], "HD22", 1.443f, -3.912f, -2.315f, 0.344f );
	}
	else if ( !strcmp(Name, "Dasp" ) ){
		F.NAtoms =  12;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.398f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.638f, -0.260f, -2.131f, 0.071f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.077f, -0.816f, -1.241f, 0.071f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.417f, -2.184f, -1.195f, 0.714f );
                SetAtom(&F.Atoms[ 10 ], "OD1", 0.297f, -2.369f, -1.741f, -0.721f );
                SetAtom(&F.Atoms[ 11 ], "OD2", 2.107f, -3.069f, -0.620f, -0.721f );
	}
	else if ( !strcmp(Name, "Dcys" ) ){
		F.NAtoms =  11;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.060f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.707f, -0.219f, -2.130f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.069f, -0.846f, -1.122f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "SG", 1.409f, -2.479f, -1.365f, -0.135f );
                SetAtom(&F.Atoms[ 10 ], "HG", 1.889f, -3.023f, -2.481f, 0.135f );
	}
	else if ( !strcmp(Name, "Dcyx" ) ){
		F.NAtoms =  10;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.707f, -0.219f, -2.130f, 0.0495f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.069f, -0.846f, -1.122f, 0.0495f );
                SetAtom(&F.Atoms[ 9 ], "SG", 1.409f, -2.479f, -1.365f, 0.015f );
	}
	else if ( !strcmp(Name, "Dgln" ) ){
		F.NAtoms = 17;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.638f, -0.260f, -2.131f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.077f, -0.816f, -1.241f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.418f, -2.183f, -1.195f, -0.102f );
                SetAtom(&F.Atoms[ 10 ], "HG1", 1.752f, -2.685f, -0.287f, 0.057f );
                SetAtom(&F.Atoms[ 11 ], "HG2", 0.330f, -2.115f, -1.205f, 0.057f );
                SetAtom(&F.Atoms[ 12 ], "CD", 1.861f, -2.984f, -2.410f, 0.675f );
                SetAtom(&F.Atoms[ 13 ], "OE1", 2.585f, -2.476f, -3.263f, -0.470f );
                SetAtom(&F.Atoms[ 14 ], "NE2", 1.422f, -4.243f, -2.489f, -0.867f );
                SetAtom(&F.Atoms[ 15 ], "HE21", 0.828f, -4.613f, -1.760f, 0.344f );
                SetAtom(&F.Atoms[ 16 ], "HE22", 1.687f, -4.819f, -3.275f, 0.344f );
	}
	else if ( !strcmp(Name, "Dglu" ) ){
		F.NAtoms =  15;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.184f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.638f, -0.260f, -2.131f, 0.092f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.077f, -0.816f, -1.241f, 0.092f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.423f, -2.168f, -1.195f, -0.398f );
                SetAtom(&F.Atoms[ 10 ], "HG1", 1.772f, -2.677f, -0.296f, 0.071f );
                SetAtom(&F.Atoms[ 11 ], "HG2", 0.334f, -2.122f, -1.186f, 0.071f );
                SetAtom(&F.Atoms[ 12 ], "CD", 1.890f, -2.938f, -2.429f, 0.714f );
                SetAtom(&F.Atoms[ 13 ], "OE1", 2.971f, -3.579f, -2.334f, -0.721f );
                SetAtom(&F.Atoms[ 14 ], "OE2", 1.160f, -2.879f, -3.455f, -0.721f );
	}
	else if ( !strcmp(Name, "Dgly" ) ){
		F.NAtoms =  7;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.027f, 1.358f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.697f, 1.839f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA1", 1.886f, -0.523f, -0.885f, 0.032f );
                SetAtom(&F.Atoms[ 4 ], "HA2", 1.874f, -0.506f, 0.899f, 0.032f );
		SetAtom(&F.Atoms[ 5 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
                SetAtom(&F.Atoms[ 6 ], "O", -0.624f, 1.058f, 0.000f, -0.504f );
	}
	else if ( !strcmp(Name, "Dhid" ) ){
		F.NAtoms =  17;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.695f, -0.225f, -2.131f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.071f, -0.840f, -1.141f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, -1.321f, -0.032f );
                SetAtom(&F.Atoms[ 10 ], "ND1", 1.828f, -3.024f, -2.383f, -0.146f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.411f, -2.776f, -3.170f, 0.228f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.698f, -2.921f, -0.492f, 0.195f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.306f, -2.472f, 0.421f, 0.018f );
                SetAtom(&F.Atoms[ 14 ], "CE1", 1.251f, -4.195f, -2.182f, 0.241f );
                SetAtom(&F.Atoms[ 15 ], "HE1", 1.387f, -4.999f, -2.905f, 0.036f );
                SetAtom(&F.Atoms[ 16 ], "NE2", 0.575f, -4.150f, -1.061f, -0.502f );
	}
	else if ( !strcmp(Name, "Dhie" ) ){
		F.NAtoms =  17;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.695f, -0.225f, -2.131f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.071f, -0.840f, -1.141f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, -1.321f, 0.251f );
                SetAtom(&F.Atoms[ 10 ], "ND1", 1.828f, -3.024f, -2.383f,  -0.502f );
                SetAtom(&F.Atoms[ 11 ], "CD2", 0.698f, -2.921f, -0.492f, -0.184f );
                SetAtom(&F.Atoms[ 12 ], "HD2", 0.306f, -2.472f, 0.421f, 0.114f );
                SetAtom(&F.Atoms[ 13 ], "CE1", 1.251f, -4.195f, -2.182f, 0.241f );
                SetAtom(&F.Atoms[ 14 ], "HE1", 1.387f, -4.999f, -2.905f, 0.036f );
                SetAtom(&F.Atoms[ 15 ], "NE2", 0.575f, -4.150f, -1.061f, -0.146f );
                SetAtom(&F.Atoms[ 16 ], "HE2", 0.041f, -4.917f, -0.677f, 0.228f );
	}
	else if ( !strcmp(Name, "Dhip" ) ){
		F.NAtoms =  18;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.695f, -0.225f, -2.131f, 0.086f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.071f, -0.840f, -1.141f, 0.086f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, -1.321f, 0.058f );
                SetAtom(&F.Atoms[ 10 ], "ND1", 1.828f, -3.024f, -2.383f, -0.058f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.411f, -2.776f, -3.170f, 0.306f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.698f, -2.921f, -0.492f, -0.037f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.306f, -2.472f, 0.421f, 0.153f );
                SetAtom(&F.Atoms[ 14 ], "CE1", 1.251f, -4.195f, -2.182f, 0.114f );
                SetAtom(&F.Atoms[ 15 ], "HE1", 1.387f, -4.999f, -2.905f, 0.158f );
                SetAtom(&F.Atoms[ 16 ], "NE2", 0.575f, -4.150f, -1.061f, -0.058f );
                SetAtom(&F.Atoms[ 17 ], "HE2", 0.041f, -4.917f, -0.677f, 0.306f );
	}
	else if ( !strcmp(Name, "Dhis" ) ){
		F.NAtoms =  18;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.695f, -0.225f, -2.131f, 0.086f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.071f, -0.840f, -1.141f, 0.086f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, -1.321f, 0.058f );
                SetAtom(&F.Atoms[ 10 ], "ND1", 1.828f, -3.024f, -2.383f, -0.058f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.411f, -2.776f, -3.170f, 0.306f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.698f, -2.921f, -0.492f, -0.037f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.248f, -2.586f, 0.442f, 0.153f );
                SetAtom(&F.Atoms[ 14 ], "CE1", 1.251f, -4.195f, -2.182f, 0.114f );
                SetAtom(&F.Atoms[ 15 ], "HE1", 1.326f, -5.058f, -2.843f, 0.158f );
                SetAtom(&F.Atoms[ 16 ], "NE2", 0.575f, -4.150f, -1.061f, -0.058f );
                SetAtom(&F.Atoms[ 17 ], "HE2", 0.041f, -4.917f, -0.677f, 0.306f );
	}
	else if ( !strcmp(Name, "Dile" ) ){
		F.NAtoms =  19;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.875f, -0.500f, 0.902f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 2.009f, -0.733f, -1.245f, -0.012f );
                SetAtom(&F.Atoms[ 7 ], "HB", 1.661f, -0.209f, -2.135f, 0.022f );
                SetAtom(&F.Atoms[ 8 ], "CG1", 1.459f, -2.156f, -1.246f, -0.049f );
                SetAtom(&F.Atoms[ 9 ], "HG11", 1.807f, -2.680f, -0.355f, 0.027f );
                SetAtom(&F.Atoms[ 10 ], "HG12", 0.370f, -2.124f, -1.246f, 0.027f );
                SetAtom(&F.Atoms[ 11 ], "CG2", 3.533f, -0.777f, -1.245f, -0.085f );
                SetAtom(&F.Atoms[ 12 ], "HG21", 3.882f, -1.301f, -2.135f, 0.029f );
                SetAtom(&F.Atoms[ 13 ], "HG22", 3.927f, 0.239f, -1.245f, 0.029f );
                SetAtom(&F.Atoms[ 14 ], "HG23", 3.882f, -1.301f, -0.355f, 0.029f );
                SetAtom(&F.Atoms[ 15 ], "CD1", 1.946f, -2.889f, -2.490f, -0.085f );
                SetAtom(&F.Atoms[ 16 ], "HD11", 1.554f, -3.905f, -2.490f, 0.028f );
                SetAtom(&F.Atoms[ 17 ], "HD12", 1.598f, -2.365f, -3.380f, 0.028f );
                SetAtom(&F.Atoms[ 18 ], "HD13", 3.036f, -2.920f, -2.490f, 0.028f );
	}
	else if ( !strcmp(Name, "Dleu" ) ){
		F.NAtoms = 19;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.061f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.638f, -0.260f, -2.131f, 0.033f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.077f, -0.816f, -1.241f, 0.033f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.418f, -2.183f, -1.195f, -0.010f );
                SetAtom(&F.Atoms[ 10 ], "HG", 1.766f, -2.692f, -0.296f, 0.031f );
                SetAtom(&F.Atoms[ 11 ], "CD1", -0.106f, -2.117f, -1.182f, -0.107f );
                SetAtom(&F.Atoms[ 12 ], "HD11", -0.513f, -3.128f, -1.155f, 0.034f );
                SetAtom(&F.Atoms[ 13 ], "HD12", -0.438f, -1.567f, -0.302f, 0.034f );
                SetAtom(&F.Atoms[ 14 ], "HD13", -0.455f, -1.608f, -2.081f, 0.034f );
                SetAtom(&F.Atoms[ 15 ], "CD2", 1.884f, -2.951f, -2.427f, -0.107f );
                SetAtom(&F.Atoms[ 16 ], "HD21", 1.476f, -3.962f, -2.400f, 0.034f );
                SetAtom(&F.Atoms[ 17 ], "HD22", 1.534f, -2.443f, -3.326f, 0.034f );
                SetAtom(&F.Atoms[ 18 ], "HD23", 2.973f, -2.999f, -2.436f, 0.034f );
	}
	else if ( !strcmp(Name, "Dlys" ) ){
		F.NAtoms =  22;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.638f, -0.260f, -2.131f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.077f, -0.816f, -1.241f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.418f, -2.183f, -1.195f, -0.160f );
                SetAtom(&F.Atoms[ 10 ], "HG1", 1.767f, -2.692f, -0.296f, 0.116f );
                SetAtom(&F.Atoms[ 11 ], "HG2", 0.328f, -2.136f, -1.186f, 0.116f );
                SetAtom(&F.Atoms[ 12 ], "CD", 1.884f, -2.951f, -2.427f, -0.180f );
                SetAtom(&F.Atoms[ 13 ], "HD1", 1.534f, -2.443f, -3.326f, 0.122f );
                SetAtom(&F.Atoms[ 14 ], "HD2", 2.973f, -2.999f, -2.436f, 0.122f );
                SetAtom(&F.Atoms[ 15 ], "CE", 1.313f, -4.366f, -2.389f, -0.038f );
                SetAtom(&F.Atoms[ 16 ], "HE1", 1.663f, -4.874f, -1.491f, 0.098f );
                SetAtom(&F.Atoms[ 17 ], "HE2", 0.224f, -4.318f, -2.380f, 0.098f );
                SetAtom(&F.Atoms[ 18 ], "NZ", 1.762f, -5.106f, -3.577f, -0.138f );
                SetAtom(&F.Atoms[ 19 ], "HZ1", 1.385f, -6.042f, -3.552f, 0.294f );
                SetAtom(&F.Atoms[ 20 ], "HZ2", 1.440f, -4.636f, -4.410f, 0.294f );
                SetAtom(&F.Atoms[ 21 ], "HZ3", 2.771f, -5.149f, -3.585f, 0.294f );
	}
	else if ( !strcmp(Name, "Dmet" ) ){
		F.NAtoms =  17;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.151f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.638f, -0.260f, -2.131f, 0.027f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.077f, -0.816f, -1.241f, 0.027f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.418f, -2.183f, -1.195f, -0.054f );
                SetAtom(&F.Atoms[ 10 ], "HG1", 1.762f, -2.690f, -0.292f, 0.0652f );
                SetAtom(&F.Atoms[ 11 ], "HG2", 0.329f, -2.129f, -1.191f, 0.0652f );
                SetAtom(&F.Atoms[ 12 ], "SD", 1.962f, -3.109f, -2.652f, -0.025f );
                SetAtom(&F.Atoms[ 13 ], "CE", 1.167f, -4.670f, -2.341f, -0.134f );
                SetAtom(&F.Atoms[ 14 ], "HE1", 1.399f, -5.363f, -3.150f, 0.0652f );
                SetAtom(&F.Atoms[ 15 ], "HE2", 1.525f, -5.079f, -1.397f, 0.0652f );
                SetAtom(&F.Atoms[ 16 ], "HE3", 0.087f, -4.523f, -2.287f, 0.0652f );
	}
	else if ( !strcmp(Name, "Dnme" ) ){
		F.NAtoms =  6;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", -1.227f, 0.728f, 2.125f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", -1.124f, -0.261f, 1.947f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", -1.918f, 1.159f, 3.323f, 0.03502f );
                SetAtom(&F.Atoms[ 3 ], "HA1", -1.939f, 2.249f, 3.358f, 0.0586f );
                SetAtom(&F.Atoms[ 4 ], "HA2", -2.939f, 0.777f, 3.311f, 0.0586f );
		SetAtom(&F.Atoms[ 5 ], "HA3", -1.398f, 0.777f, 4.201f, 0.0586f );
	}
	else if ( !strcmp(Name, "Dphe" ) ){
		F.NAtoms =  20;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.100f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.695f, -0.225f, -2.131f, 0.108f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.071f, -0.840f, -1.141f, 0.108f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, -1.321f, -0.100f );
                SetAtom(&F.Atoms[ 10 ], "CD1", 1.856f, -2.993f, -2.410f, -0.150f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.497f, -2.589f, -3.194f, 0.150f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.669f, -2.711f, -0.315f, -0.150f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.385f, -2.087f, 0.533f, 0.150f );
                SetAtom(&F.Atoms[ 14 ], "CE1", 1.398f, -4.313f, -2.492f, -0.150f );
                SetAtom(&F.Atoms[ 15 ], "HE1", 1.681f, -4.937f, -3.340f, 0.150f );
                SetAtom(&F.Atoms[ 16 ], "CE2", 0.210f, -4.031f, -0.397f, -0.150f );
                SetAtom(&F.Atoms[ 17 ], "HE2", -0.431f, -4.436f, 0.387f, 0.150f );
                SetAtom(&F.Atoms[ 18 ], "CZ", 0.575f, -4.833f, -1.486f, -0.150f );
                SetAtom(&F.Atoms[ 19 ], "HZ", 0.217f, -5.861f, -1.550f, 0.150f );
	}
	else if ( !strcmp(Name, "Dpro" ) ){
		F.NAtoms =  14;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.067f, 1.413f, 0.000f, -0.229f );
                SetAtom(&F.Atoms[ 1 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 2 ], "HA", 1.308f, -0.765f, 0.745f, 0.048f );
                SetAtom(&F.Atoms[ 3 ], "C", 0.000f, 0.000f, 0.000f, 0.526f );
                SetAtom(&F.Atoms[ 4 ], "O", -0.624f, 1.059f, 0.000f, -0.500f );
		SetAtom(&F.Atoms[ 5 ], "CB", 2.632f, -0.865f, -0.521f, -0.115f );
                SetAtom(&F.Atoms[ 6 ], "HB1", 2.901f, -1.604f, 0.234f, 0.061f );
                SetAtom(&F.Atoms[ 7 ], "HB2", 2.302f, -1.372f, -1.426f, 0.061f );
                SetAtom(&F.Atoms[ 8 ], "CG", 3.834f, -0.007f, -0.835f, -0.121f );
                SetAtom(&F.Atoms[ 9 ], "HG1", 4.671f, -0.309f, -0.206f, 0.063f );
                SetAtom(&F.Atoms[ 10 ], "HG2", 4.135f, -0.100f, -1.878f, 0.063f );
                SetAtom(&F.Atoms[ 11 ], "CD", 3.438f, 1.400f, -0.496f, -0.0012f );
                SetAtom(&F.Atoms[ 12 ], "HD1", 3.507f, 2.022f, -1.389f, 0.060f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 4.105f, 1.791f, 0.271f, 0.060f );
	}
	else if ( !strcmp(Name, "Dser" ) ){
		F.NAtoms =  11;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, 0.018f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.638f, -0.260f, -2.131f, 0.119f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.077f, -0.816f, -1.241f, 0.119f );
                SetAtom(&F.Atoms[ 9 ], "OG", 1.453f, -2.095f, -1.196f, -0.550f );
                SetAtom(&F.Atoms[ 10 ], "HG", 1.746f, -2.578f, -1.973f, 0.310f );
	}
	else if ( !strcmp(Name, "Dthr" ) ){
		F.NAtoms =  14;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, 0.170f );
                SetAtom(&F.Atoms[ 7 ], "HB", 1.580f, -1.779f, -1.205f, 0.082f );
                SetAtom(&F.Atoms[ 8 ], "OG1", 3.416f, -0.831f, -1.244f, -0.550f );
                SetAtom(&F.Atoms[ 9 ], "HG1", 3.710f, -1.314f, -2.020f, 0.310f );
                SetAtom(&F.Atoms[ 10 ], "CG2", 1.499f, -0.057f, -2.490f, -0.191f );
                SetAtom(&F.Atoms[ 11 ], "HG21", 1.832f, -0.606f, -3.370f, 0.065f );
                SetAtom(&F.Atoms[ 12 ], "HG22", 0.410f, -0.010f, -2.480f, 0.065f );
                SetAtom(&F.Atoms[ 13 ], "HG23", 1.906f, 0.953f, -2.516f, 0.065f );
	}
	else if ( !strcmp(Name, "Dtrp" ) ){
		F.NAtoms =  24;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.695f, -0.225f, -2.131f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.071f, -0.840f, -1.141f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.492f, -2.192f, -1.321f, -0.135f );
                SetAtom(&F.Atoms[ 10 ], "CD1", 1.752f, -3.078f, -2.293f, 0.044f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.365f, -2.907f, -3.178f, 0.093f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.669f, -2.868f, -0.412f, 0.146f );
                SetAtom(&F.Atoms[ 13 ], "NE1", 1.072f, -4.288f, -1.950f, -0.352f );
                SetAtom(&F.Atoms[ 14 ], "HE1", 1.079f, -5.139f, -2.493f, 0.271f );
                SetAtom(&F.Atoms[ 15 ], "CE2", 0.437f, -4.114f, -0.817f, 0.154f );
                SetAtom(&F.Atoms[ 16 ], "CE3", 0.103f, -2.412f, 0.785f, -0.173f );
                SetAtom(&F.Atoms[ 17 ], "HE3", 0.273f, -1.398f, 1.145f, 0.086f );
                SetAtom(&F.Atoms[ 18 ], "CZ2", -0.350f, -5.037f, -0.120f, -0.168f );
                SetAtom(&F.Atoms[ 19 ], "HZ2", -0.515f, -6.050f, -0.487f, 0.084f );
                SetAtom(&F.Atoms[ 20 ], "CZ3", -0.694f, -3.326f, 1.506f, -0.066f );
                SetAtom(&F.Atoms[ 21 ], "HZ3", -1.150f, -3.005f, 2.442f, 0.057f );
		SetAtom(&F.Atoms[ 22 ], "CH2", -0.912f, -4.585f, 1.069f, -0.168f );
                SetAtom(&F.Atoms[ 23 ], "HH2", -1.535f, -5.257f, 1.658f, 0.084f );
	}
	else if ( !strcmp(Name, "Dtyr" ) ){
		F.NAtoms =  21;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.098f );
                SetAtom(&F.Atoms[ 7 ], "HB1", 1.638f, -0.260f, -2.131f, 0.038f );
                SetAtom(&F.Atoms[ 8 ], "HB2", 3.077f, -0.816f, -1.241f, 0.038f );
                SetAtom(&F.Atoms[ 9 ], "CG", 1.423f, -2.168f, -1.195f, -0.030f );
                SetAtom(&F.Atoms[ 10 ], "CD1", 1.715f, -3.069f, -2.228f, -0.002f );
                SetAtom(&F.Atoms[ 11 ], "HD1", 2.348f, -2.758f, -3.058f, 0.064f );
                SetAtom(&F.Atoms[ 12 ], "CD2", 0.609f, -2.567f, -0.128f, -0.002f );
                SetAtom(&F.Atoms[ 13 ], "HD2", 0.382f, -1.866f, 0.676f, 0.064f );
                SetAtom(&F.Atoms[ 14 ], "CE1", 1.191f, -4.367f, -2.193f, -0.264f );
                SetAtom(&F.Atoms[ 15 ], "HE1", 1.418f, -5.067f, -2.996f, 0.102f );
                SetAtom(&F.Atoms[ 16 ], "CE2", 0.086f, -3.865f, -0.094f, -0.264f );
                SetAtom(&F.Atoms[ 17 ], "HE2", -0.548f, -4.176f, 0.737f, 0.102f );
                SetAtom(&F.Atoms[ 18 ], "CZ", 0.378f, -4.765f, -1.126f, 0.462f );
                SetAtom(&F.Atoms[ 19 ], "OH", -0.131f, -6.027f, -1.093f, -0.528f );
                SetAtom(&F.Atoms[ 20 ], "HH", 0.132f, -6.557f, -1.848f, 0.334f );
	}
	else if ( !strcmp(Name, "Dval" ) ){
		F.NAtoms =  16;
		F.Atoms = g_malloc(F.NAtoms*sizeof(Atom));
                SetAtom(&F.Atoms[ 0 ], "N", 2.044f, 1.352f, 0.000f, -0.463f );
                SetAtom(&F.Atoms[ 1 ], "H", 1.721f, 1.837f, 0.824f, 0.252f );
                SetAtom(&F.Atoms[ 2 ], "CA", 1.522f, 0.000f, 0.000f, 0.035f );
                SetAtom(&F.Atoms[ 3 ], "HA", 1.896f, -0.481f, 0.904f, 0.048f );
                SetAtom(&F.Atoms[ 4 ], "C", 0.000f, 0.000f, 0.000f, 0.616f );
		SetAtom(&F.Atoms[ 5 ], "O", -0.624f, 1.060f, 0.000f, -0.504f );
                SetAtom(&F.Atoms[ 6 ], "CB", 1.988f, -0.769f, -1.232f, -0.012f );
                SetAtom(&F.Atoms[ 7 ], "HB", 1.638f, -0.260f, -2.131f, 0.024f );
                SetAtom(&F.Atoms[ 8 ], "CG1", 3.510f, -0.834f, -1.245f, -0.091f );
                SetAtom(&F.Atoms[ 9 ], "HG11", 3.844f, -1.383f, -2.125f, 0.031f );
                SetAtom(&F.Atoms[ 10 ], "HG12", 3.918f, 0.176f, -1.271f, 0.031f );
                SetAtom(&F.Atoms[ 11 ], "HG13", 3.860f, -1.343f, -0.346f, 0.031f );
                SetAtom(&F.Atoms[ 12 ], "CG2", 1.418f, -2.183f, -1.195f, -0.091f );
                SetAtom(&F.Atoms[ 13 ], "HG21", 1.751f, -2.732f, -2.075f, 0.031f );
                SetAtom(&F.Atoms[ 14 ], "HG22", 1.767f, -2.692f, -0.296f, 0.031f );
                SetAtom(&F.Atoms[ 15 ], "HG23", 0.328f, -2.136f, -1.186f, 0.031f );
	}
	/*CenterFrag(&F);*/
	for(i=1;i<(gint)strlen(Name);i++)
		T[i-1] = toupper(Name[i]);
	if(strlen(Name)-1>0)
	{
		T[strlen(Name)-1] ='\0';
		SetResidue(&F,T);
	}
	else
		SetResidue(&F,"UNK");
	return F;

}
