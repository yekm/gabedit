/* BuildPolyPeptide.c */
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

#include "../Common/Global.h"
#include "../Utils/Utils.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/Constantes.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Geometry/GeomXYZ.h"
#include "../Geometry/InterfaceGeom.h"
#include "../Geometry/FragmentsPPD.h"
#include "../Geometry/RotFragments.h"
#include "../Geometry/MenuToolBarGeom.h"
#include "../MolecularMechanics/PDBTemplate.h"

void dessine();
void define_good_factor();
void create_GeomXYZ_from_draw_grometry();

#define LigneT 6
#define ColonneT 5

static GtkWidget* Entrys[3];
static GtkWidget* ButtonL = NULL;
static GtkWidget* ButtonD = NULL;
static int nbuffer = 0;
static int ibuffer = 0;
static gfloat phiBuffer[ 4 ];
static gfloat psiBuffer[ 4 ];
static gfloat omegaBuffer[ 4 ];

static gchar conf[30];
static gint lastFragNumber = -1;
static gint CA = -1;
static gint C = -1;
static gint N = -1;
static gint O = -1;
static gint H = -1;
static gint CH3 = -1;

static gint lastCA = -1;
static gint lastC = -1;
static gint lastN = -1;
static gint lastO = -1;
static gint lastH = -1;
static gint lastCH3 = -1;
static gdouble phi = -57;
static gdouble psi = 47;
static gdouble omega = 180;
static gdouble lastOmega = 180;
static gdouble lastPsi = 180;
static gchar  fragName[30] = "L";
static gchar  fullFragName[30] = "L";
static gboolean NCapped = FALSE;
static gboolean CCapped = FALSE;
static gboolean zwitterionic = FALSE;
static Fragment Frag = {0,NULL};
static GeomDef* G=NULL;
static gint Nb = 0;
static GtkWidget* NCap=NULL;
static GtkWidget* ZwitterionButton=NULL;
static GtkWidget* UndoZwitterionButton=NULL;

static gdouble getTorsion(GeomDef* geom, gint a1, gint a2, gint a3,gint a4)
{
	gdouble C1[3]={geom[a1].X,geom[a1].Y,geom[a1].Z};
	gdouble C2[3]={geom[a2].X,geom[a2].Y,geom[a2].Z};
	gdouble C3[3]={geom[a3].X,geom[a3].Y,geom[a3].Z};
	gdouble C4[3]={geom[a4].X,geom[a4].Y,geom[a4].Z};
	return TorsionToAtoms(C4,C1,C2,C3);
}
/********************************************************************************/
static void init_variables()
{
	lastFragNumber = -1;
	CA = -1;
	C = -1;
	N = -1;
	O = -1;
	H = -1;
	CH3 = -1;

	lastCA = -1;
	lastC = -1;
	lastN = -1;
	lastO = -1;
	lastH = -1;
	lastCH3 = -1;

	phi = -57;
	psi = 47;
	omega = 180;

	lastOmega = 180;
	lastPsi = 180;
	sprintf(fragName,"%s","L");
	sprintf(fullFragName,"%s","L");
	NCapped = FALSE;
	CCapped = FALSE;
	zwitterionic = FALSE;
	if(Nb!=0)
	{
		gint i;
                for (i=0;i<Nb;i++)
		{
			g_free(G[i].Prop.symbol);
			g_free(G[i].Prop.name);
			g_free(G[i].mmType);
			g_free(G[i].pdbType);
			g_free(G[i].Residue);
		}

		if(G)
			g_free(G);
	}
	Nb=0;
	G = NULL;

	NCap=NULL;
	ZwitterionButton=NULL;
	UndoZwitterionButton=NULL;

}
/*****************************************************************************/
static void destroy_dlg(GtkWidget* Dlg,gpointer data) 
{
	delete_child(Dlg);
	if(Nb!=0)
	{
		gint i;
                for (i=0;i<Nb;i++)
		{
			g_free(G[i].Prop.symbol);
			g_free(G[i].Prop.name);
			g_free(G[i].mmType);
			g_free(G[i].pdbType);
			g_free(G[i].Residue);
		}

		if(G)
			g_free(G);
	}
	Nb=0;
	G = NULL;
	
	activate_rotation();
}
/*****************************************************************************/
static void define_geometry_to_draw()
{
	gint i;
	gdouble C[3] = {0.0,0.0,0.0};
	gint n;

	Free_One_Geom(geometry0,Natoms);
	Free_One_Geom(geometry ,Natoms);
	Natoms = 0;
	geometry0 = NULL;
	geometry  = NULL;

	Natoms = Nb;
	geometry0 = g_malloc((Natoms)*sizeof(GeomDef));
	geometry  = g_malloc((Natoms)*sizeof(GeomDef));
	n = 0;
	for(i=0;i<Nb;i++)
	{
		if(G[i].N == 0)
			continue;
		geometry0[n].X = G[i].X;
		geometry0[n].Y = G[i].Y;
		geometry0[n].Z = G[i].Z;
		geometry0[n].Charge = G[i].Charge;
		geometry0[n].Prop = prop_atom_get(G[i].Prop.symbol);
		geometry0[n].mmType = g_strdup(G[i].mmType);
		geometry0[n].pdbType = g_strdup(G[i].pdbType);
		geometry0[n].Residue = g_strdup(G[i].Residue);
		geometry0[n].ResidueNumber = G[i].ResidueNumber;
		geometry0[n].show = TRUE;
		geometry0[n].Layer = HIGH_LAYER;
		geometry0[n].Variable = FALSE;


		geometry0[n].N = n+1;

		geometry[n].X = G[i].X;
		geometry[n].Y = G[i].Y;
		geometry[n].Z = G[i].Z;
		geometry[n].Charge = G[i].Charge;
		geometry[n].Prop = prop_atom_get(G[i].Prop.symbol);
		geometry[n].mmType = g_strdup(geometry0[n].mmType);
		geometry[n].pdbType = g_strdup(geometry0[n].pdbType);
		geometry[n].Residue = g_strdup(geometry0[n].Residue);
		geometry[n].ResidueNumber = G[i].ResidueNumber;
		geometry[n].show = TRUE;
		geometry[n].N = n+1;
		geometry[n].Layer = HIGH_LAYER;
		geometry[n].Variable = FALSE;
		C[0] +=  G[i].X;
		C[1] +=  G[i].Y;
		C[2] +=  G[i].Z;
		n++;
	}
	if(n>0)
	for(i=0;i<3;i++)
		C[i] /= n;
	/* center */
	for(i=0;i<n;i++)
	{
		geometry0[i].X -= C[0];
		geometry0[i].Y -= C[1];
		geometry0[i].Z -= C[2];

		geometry[i].X -= C[0];
		geometry[i].Y -= C[1];
		geometry[i].Z -= C[2];
	}
	Natoms = n;
	if(n>0)
	{
		geometry0 = g_realloc(geometry0,(Natoms)*sizeof(GeomDef));
		geometry  = g_realloc(geometry,(Natoms)*sizeof(GeomDef));
	}

}
/********************************************************************************/
void re_set_angles()
{
	gchar* t = NULL;
	if(nbuffer<1)
		return;
	ibuffer++;
	if(ibuffer>nbuffer-1)
		ibuffer = 0;
	t = g_strdup_printf("%0.1f ",phiBuffer[ibuffer]);
	gtk_entry_set_text(GTK_ENTRY(Entrys[0]),t);
	g_free(t);

	t = g_strdup_printf("%0.1f ",psiBuffer[ibuffer]);
	gtk_entry_set_text(GTK_ENTRY(Entrys[1]),t);
	g_free(t);

	t = g_strdup_printf("%0.1f ",omegaBuffer[ibuffer]);
	gtk_entry_set_text(GTK_ENTRY(Entrys[2]),t);
	g_free(t);
		
}
/********************************************************************************/
static void add_fragment(gchar* what)
{
	gint i;
	gint j;
	gint omegaArrayCounter=0;
	gint* omegaArray=NULL;
	gint phiArrayCounter = 0;
	gint* phiArray = NULL;
	gchar error[BSIZE];

	G_CONST_RETURN gchar* t;

	t = gtk_entry_get_text(GTK_ENTRY(Entrys[0]));
	phi = atof(t);
	t = gtk_entry_get_text(GTK_ENTRY(Entrys[1]));
	psi = atof(t);
	t = gtk_entry_get_text(GTK_ENTRY(Entrys[2]));
	omega = atof(t);
	if ( CCapped )
	{
         sprintf( error,"The polypeptide sequence has a C-terminating residue ( Nme ).\n You can no longer add residues to this polypeptide,\n Suggestion:  Do not add Nme until the end.");
	 Message(error,"Error",TRUE);
	 return ;
	}
	if ( !strcmp (what,"Ace(N-cap)") && lastFragNumber != -1  )
	{
	 sprintf(error,"Ace is a N-terminating residue.\n It can only be added as the first residue in a polypeptide,\n Suggestion:  Forget about Acetyl.  There are plenty of other residues.");
	 Message(error,"Error",TRUE);
	 return ;
	}
	else if ( !strcmp(what , "Nme(C-cap)" ))
	{
		CCapped = TRUE;
	}

	/*
	for(i=0;i<Frag.NAtoms;i++)
	{
		printf("%s %f %f %f\n",
			Frag.Atoms[i].Name,
			Frag.Atoms[i].Coord[0],Frag.Atoms[i].Coord[1],Frag.Atoms[i].Coord[2]);
	}
	*/
	if(Nb>0)
		G = g_realloc(G,(Nb+Frag.NAtoms+1)*sizeof(GeomDef));
	else
		G = g_malloc((Frag.NAtoms+1)*sizeof(GeomDef));

	omegaArray  = g_malloc(Frag.NAtoms*sizeof(gint)); 
	phiArray    = g_malloc(Frag.NAtoms*sizeof(gint)); 

	Ddef = FALSE;

	j=Nb-1;
	for(i=0;i<Frag.NAtoms;i++)
	{
		j++;
		G[j].X=Frag.Atoms[i].Coord[0];
		G[j].Y=Frag.Atoms[i].Coord[1];
		G[j].Z=Frag.Atoms[i].Coord[2];
		G[j].Charge=Frag.Atoms[i].Charge;
		G[j].mmType=g_strdup(Frag.Atoms[i].mmType);
		G[j].pdbType=g_strdup(Frag.Atoms[i].pdbType);
		G[j].Residue=g_strdup(Frag.Atoms[i].Residue);
		G[j].ResidueNumber=lastFragNumber+1;

		G[j].Prop = prop_atom_get(Frag.Atoms[i].Symb);
		G[j].N = j+1;

		if(!strcmp(Frag.Atoms[i].pdbType,"C"))
		{
			C =  j;
			phiArray[ phiArrayCounter++ ] =  j;
		}
		else
		if(!strcmp(Frag.Atoms[i].pdbType,"N"))
			N =  j;
		else
		if(!strcmp(Frag.Atoms[i].pdbType,"CA"))
			CA = j;
		else
		if(!strcmp(Frag.Atoms[i].pdbType,"CH3"))
			CH3 = j;
		else
		if(!strcmp(Frag.Atoms[i].pdbType,"O"))
		{
			O =  j;
			phiArray[ phiArrayCounter++ ] =  j;
		}
		else
		if(!strcmp(Frag.Atoms[i].pdbType,"H"))
		{
			H =  j;
			phiArray[ phiArrayCounter++ ] =  j;
		}
		else
			phiArray[ phiArrayCounter++ ] =  j;


		omegaArray[ omegaArrayCounter++ ] = j;
	}
	Nb += Frag.NAtoms;
	if(lastFragNumber != -1)
	{
		if(lastC != -1 && N != -1)
			SetBondDistance(G,lastC,N,1.47,omegaArray,omegaArrayCounter);

		if ( lastN > -1 )
		{
			if ( lastN > -1 && lastCA > -1 &&  lastC > 1 && N > -1 )
			{
				SetAngle( Nb,G,lastCA, lastC, N, 
					111.2, omegaArray, omegaArrayCounter); 
				SetAngle( Nb,G, lastC, N, CA,
					121.9, omegaArray, omegaArrayCounter); 

				SetTorsion( Nb,G,lastN, lastCA, lastC, N,
					   lastPsi, omegaArray, omegaArrayCounter );
			}
			if ( !CCapped )
				if ( lastCA > -1 &&  lastC > 1 && N > -1  && C > -1)
				SetTorsion( Nb,G, lastCA, lastC, N, C, lastOmega, 
					omegaArray, omegaArrayCounter );
		}

		if ( !CCapped )
			if ( lastC > -1 &&  N > 1 && CA > -1  && C > -1)
			SetTorsion( Nb,G, lastC, N, CA, C, phi, 
			phiArray, phiArrayCounter );  
	}
	g_free(omegaArray);
	g_free(phiArray);
	/* Pseudo atom */
	G[Nb].X=0.0;
	G[Nb].Y=0.0;
	G[Nb].Z=0.0;

	G[Nb].Charge = 0.0;
	G[Nb].Prop = prop_atom_get("H");
	G[Nb].mmType = g_strdup("H");
	G[Nb].pdbType = g_strdup("H");
	G[Nb].Residue = g_strdup("H");
	G[Nb].ResidueNumber = lastFragNumber+1; 
	G[Nb].N = Nb+1;
	if ( lastCA > -1 && N > -1)
	{
        	G[Nb].X = (G[lastCA].X + G[N].X)/2.0;
        	G[Nb].Y = (G[lastCA].Y + G[N].Y)/2.0;
        	G[Nb].Z = (G[lastCA].Z + G[N].Z)/2.0;
	}
	else
	if ( lastCH3 > -1 && N > -1)
	{
        	G[Nb].X = (G[lastCH3].X + G[N].X)/2.0;
        	G[Nb].Y = (G[lastCH3].Y + G[N].Y)/2.0;
        	G[Nb].Z = (G[lastCH3].Z + G[N].Z)/2.0;
	}
	if(lastC>-1 && lastO>-1)
		SetAngle( Nb+1,G,Nb, lastC, lastO, 180.0, NULL, 0 );
	if ( strcmp(what, "Pro") )
	{
		if ( CA > -1 && lastC > -1)
		{
        	G[Nb].X = (G[CA].X + G[lastC].X)/2.0;
        	G[Nb].Y = (G[CA].Y + G[lastC].Y)/2.0;
        	G[Nb].Z = (G[CA].Z + G[lastC].Z)/2.0;
		if(N>-1 && H > -1)
			SetAngle( Nb+1,G,Nb, N, H, 180.0, NULL, 0 );
		}
	}



	define_geometry_to_draw();
	define_good_factor();
	unselect_all_atoms();
	dessine();
	create_GeomXYZ_from_draw_grometry();
	lastFragNumber++;
	lastC = C;
	lastN = N;
	lastCA = CA;
	lastCH3 = CH3;
	lastO = O;
	lastH = H;
	lastOmega = omega;
	lastPsi = psi;
}
/********************************************************************************/
static gchar* getmmType(gchar* pdbtype, gchar* residue)
{
	gchar* mmType;
	gdouble charge;

	mmType = getMMTypeFromPDBTpl(residue,pdbtype,&charge);
	if(!strcmp(mmType,"UNK"))
	{
		g_free(mmType);
		return g_strdup(pdbtype);
	}
	return mmType;
}
/********************************************************************************/
static void add_zwitterion()
{
	/* do first fragment*/
	gint firstN = -1, firstH = -1, firstC = -1, firstHA1 = -1, firstCA = -1;
	gint firstCH3 = -1, firstH1 = -1, firstO = -1;
	gint i;
	gdouble originalTorsion = 0.0;
	for ( i = 0; i < Nb; i++ )
	{
		if(G[i].ResidueNumber != 0)
			continue;

		if(!strcmp(G[i].pdbType,"N"))
			firstN = i;
		if(!strcmp(G[i].pdbType,"H"))
			firstH = i;
		if(!strcmp(G[i].pdbType,"CA"))
			firstCA = i;
		if(!strcmp(G[i].pdbType,"C"))
			firstC = i;
		if(!strcmp(G[i].pdbType,"CH3"))
			firstC = i;
		if(!strcmp(G[i].pdbType,"HA1"))
			firstHA1 = i;
	}
	if ( ( firstN != -1 ) && ( firstH != -1 ) && ( firstCA != -1 ) )
	{
		if(G[firstH].pdbType)
			g_free(G[firstH].pdbType);
		G[firstH].pdbType = g_strdup("1H");

		if(Nb>0)
			G = g_realloc(G,(Nb+2)*sizeof(GeomDef));
		else
			G = g_malloc((2)*sizeof(GeomDef));

		G[Nb].X=G[firstH].X;
		G[Nb].Y=G[firstH].Y;
		G[Nb].Z=G[firstH].Z;

		G[Nb].Charge = 0.0;
		G[Nb].Prop = prop_atom_get("H");
		G[Nb].pdbType = g_strdup("2H");
		G[Nb].mmType =getmmType(G[Nb].pdbType, G[0].Residue);
		G[Nb].Residue = g_strdup(G[0].Residue);
		G[Nb].ResidueNumber = 0;
		G[Nb].N = Nb+1;

		G[Nb+1].X=G[firstH].X;
		G[Nb+1].Y=G[firstH].Y;
		G[Nb+1].Z=G[firstH].Z;

		G[Nb+1].Charge = 0.0;
		G[Nb+1].Prop = prop_atom_get("H");
		G[Nb+1].pdbType = g_strdup("3H");
		G[Nb+1].mmType =getmmType(G[Nb+1].pdbType, G[0].Residue);

		G[Nb+1].Residue = g_strdup(G[0].Residue);
		G[Nb+1].ResidueNumber = 0;
		G[Nb+1].N = Nb+2;

		if ( firstC != -1 )
		{
			originalTorsion = getTorsion(G, firstC, firstCA, firstN, firstH);
			/* set H2 Torsion */
			SetTorsion( Nb+2,G, firstC, firstCA, firstN, Nb,
				120+ originalTorsion, NULL, 0 );  
			/* set H3 Torsion */
			SetTorsion( Nb+2,G, firstC, firstCA, firstN, Nb+1,
				240 + originalTorsion, NULL, 0 );  
		}
		else if ( firstHA1 != -1 )
		{
			originalTorsion = getTorsion(G,firstHA1, firstCA, firstN, firstH);
			/* set H2 Torsion */
			SetTorsion( Nb+2,G, firstHA1, firstCA, firstN, Nb,
				120+ originalTorsion, NULL, 0 );  
			/* set H3 Torsion */
			SetTorsion( Nb+2,G, firstHA1, firstCA, firstN, Nb+1,
				240 + originalTorsion, NULL, 0 );  
		}
		Nb += 2;
	}
	/* now do C-cap at lastFragment*/
	for ( i = 0; i < Nb; i++ )
	{
		if(G[i].ResidueNumber != lastFragNumber)
			continue;

		if(!strcmp(G[i].pdbType,"N"))
			firstN = i;
		if(!strcmp(G[i].pdbType,"O"))
			firstO = i;
		if(!strcmp(G[i].pdbType,"CA"))
			firstCA = i;
		if(!strcmp(G[i].pdbType,"C"))
			firstC = i;
		if(!strcmp(G[i].pdbType,"CH3"))
			firstC = i;
		if(!strcmp(G[i].pdbType,"HA1"))
			firstHA1 = i;
	}
	if ( ( firstCA != -1 ) && ( firstC != -1 ) && ( firstO != -1 ) )
	{
		if(Nb>0)
			G = g_realloc(G,(Nb+1)*sizeof(GeomDef));
		else
			G = g_malloc((1)*sizeof(GeomDef));

		G[Nb].X=G[firstO].X;
		G[Nb].Y=G[firstO].Y;
		G[Nb].Z=G[firstO].Z;

		G[Nb].Charge = 0.0;
		G[Nb].Prop = prop_atom_get("O");
		G[Nb].pdbType = g_strdup("OXT");
		{
			gint k;
			gint n=0;
			for(k=0;k<Nb;k++)
			{
				if(G[k].ResidueNumber==lastFragNumber)
				{
					n = k;
					break;
				}
			}
			G[Nb].Residue = g_strdup(G[k].Residue);
		}
		G[Nb].mmType =getmmType(G[Nb].pdbType, G[Nb].Residue);
		G[Nb].ResidueNumber = lastFragNumber;
		G[Nb].N = Nb+1;

		if ( firstN != -1 )
		{
			originalTorsion = getTorsion(G,firstN, firstCA, firstC, firstO);

			SetTorsion( Nb+1,G, firstN, firstCA, firstC, Nb, 
				180 + originalTorsion, NULL, 0 );  
		}
		else if ( ( firstH1 != -1 ) && ( firstCH3 != -1 ) )
		{
			originalTorsion = getTorsion(G,firstH1, firstCH3, firstC, firstO);

			SetTorsion( Nb+1,G, firstH1, firstCH3, firstC, Nb, 
				180 + originalTorsion, NULL, 0 );  
		}
		Nb += 1;
	}
	define_geometry_to_draw();
	define_good_factor();
	create_GeomXYZ_from_draw_grometry();
	dessine();
}
/********************************************************************************/
static void delete_zwitterion()
{
	gint firstN = -1, firstH1 = -1, firstH2 = -1, firstH3 = -1, firstOXT = -1;
	gint i;
	for ( i = 0; i < Nb; i++ )
	{
		if(G[i].ResidueNumber != 0)
			continue;

		if(!strcmp(G[i].pdbType,"N"))
			firstN = i;
		if(!strcmp(G[i].pdbType,"1H"))
			firstH1 = i;
		if(!strcmp(G[i].pdbType,"2H"))
			firstH2 = i;
		if(!strcmp(G[i].pdbType,"3H"))
			firstH3 = i;
	}
	if ( ( firstN != -1 ) && ( firstH1 != -1 ) && ( firstH2 != -1 ) &&( firstH3 != -1 ) )
	{
		G[firstH2].N = 0;
		if(G[firstH2].pdbType)
			g_free(G[firstH2].pdbType);
		G[firstH2].pdbType = g_strdup("Unknown");

		if(G[firstH2].mmType)
			g_free(G[firstH2].mmType);
		G[firstH2].mmType = g_strdup("Unknown");

		G[firstH3].N = 0;
		if(G[firstH3].pdbType)
			g_free(G[firstH3].pdbType);
		G[firstH3].pdbType = g_strdup("Unknown");

		if(G[firstH3].mmType)
			g_free(G[firstH3].mmType);
		G[firstH3].mmType = g_strdup("Unknown");

		if(G[firstH1].pdbType)
			g_free(G[firstH1].pdbType);
		G[firstH1].pdbType = g_strdup("H");

		if(G[firstH1].mmType)
			g_free(G[firstH1].mmType);
		G[firstH1].mmType = g_strdup("H");
	}
	for ( i = 0; i < Nb; i++ )
	{
		if(G[i].ResidueNumber != lastFragNumber)
			continue;

		if(!strcmp(G[i].pdbType,"OXT"))
			firstOXT = i;
	}
	if ( firstOXT != -1 )
	{
		G[firstOXT].N = 0;
		if(G[firstOXT].pdbType)
			g_free(G[firstOXT].pdbType);
		G[firstOXT].pdbType = g_strdup("Unknown");
		if(G[firstOXT].mmType)
			g_free(G[firstOXT].mmType);
		G[firstOXT].mmType = g_strdup("Unknown");
	}
	define_geometry_to_draw();
	define_good_factor();
	create_GeomXYZ_from_draw_grometry();
	dessine();
}
/********************************************************************************/
static void build_polypeptide(GtkWidget *w,gpointer data)
{
	sprintf(fragName,"%s",(gchar*)data);
	if ( !strcmp((gchar*)data , "Nme(C-cap)" ))
		sprintf(fragName,"nme");
	if ( !strcmp ((gchar*)data,"Ace(N-cap)"))
		sprintf(fragName,"ace");

	lowercase(fragName);
	if (GTK_TOGGLE_BUTTON (ButtonL)->active)
		sprintf(fullFragName,"L%s",fragName);
	else
		sprintf(fullFragName,"D%s",fragName);

	if(strcmp((gchar*)data,"Zwitterion")==0)
	{
		gtk_widget_set_sensitive(ZwitterionButton, FALSE);
		gtk_widget_set_sensitive(UndoZwitterionButton,TRUE);
		add_zwitterion();
		return;
	}
	if(strcmp((gchar*)data,"Undo Zwit.")==0)
	{
		gtk_widget_set_sensitive(ZwitterionButton, TRUE);
		gtk_widget_set_sensitive(UndoZwitterionButton,FALSE);
		delete_zwitterion();
		return;
	}
	FreeFragment(&Frag);
	Frag = GetFragmentPPD(fullFragName);
	add_fragment((gchar*)data);
	re_set_angles();
	gtk_widget_set_sensitive(NCap, FALSE);
	if(lastFragNumber==0)
	{
		gtk_widget_set_sensitive(ZwitterionButton, TRUE);
		gtk_widget_set_sensitive(UndoZwitterionButton,FALSE);
	}
}
/********************************************************************************************************/
static void traite_conformation(GtkComboBox *combobox, gpointer d)
{
	gint i;
	GtkTreeIter iter;
	gchar* option = NULL;
	if (gtk_combo_box_get_active_iter (combobox, &iter))
	{
		GtkTreeModel* model = gtk_combo_box_get_model(combobox);
		gtk_tree_model_get (model, &iter, 0, &option, -1);
	}
	if(!option) return;
	ibuffer = 0;
	sprintf(conf,"%s",option);
	if(!strcmp(option,"Other"))
		for(i=0;i<3;i++)
		{
  			gtk_editable_set_editable((GtkEditable*) Entrys[i],TRUE);
		}
	else
		for(i=0;i<3;i++)
		{
  			gtk_editable_set_editable((GtkEditable*) Entrys[i],FALSE);
		}

	if ( !strcmp(option, "3-10 Helix" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-49.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-26.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");
		nbuffer = 0;
		return ;
	}	
	else if ( !strcmp(option, "Alpha Helix" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");
		nbuffer = 0;
		return ;
	}
	else if ( !strcmp(option, "Alpha Helix (LH)" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");
		nbuffer = 0;
		return ;
	}
	else if ( !strcmp(option, "Beta Sheet (anti-prl)" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-139.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"135.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"-178.0");
		nbuffer = 0;
		return ;
	}	
	else if ( !strcmp(option, "Beta Sheet (parallel)" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-119.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"113.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"-178.0");
		nbuffer = 0;
		return ;
	}	
	else if ( !strcmp(option, "Omega Helix" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"64.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"55.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");
		nbuffer = 0;
		return ;
	}
	else if ( !strcmp(option, "Pi Helix" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-70.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");
		nbuffer = 0;
		return ;
	}
	else if ( !strcmp(option, "Polyglycine II" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"80.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-150.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");
		nbuffer = 0;
		return ;
	}
	else if ( !strcmp(option, "Polyglycine II (LH)" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-80.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"150.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");
		nbuffer = 0;
		return ;
	}
	else if ( !strcmp(option, "Polyproline I" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-83.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"158.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"0.0");
		nbuffer = 0;
		return ;
	}
	else if ( !strcmp(option, "Polyproline II" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-80.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"150.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");
		nbuffer = 0;
		return ;
	}
	else if ( !strcmp(option, "Other" ))
	{
		nbuffer = 0;
		return ;
	}
	else if ( !strcmp(option, "Extended" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"180.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"180.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");
		nbuffer = 0;
		return ;
	}	
	else if ( !strcmp(option, "Gamma Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"180.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"180.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 3;

		phiBuffer[ 0 ] = 180.0;
		phiBuffer[ 1 ] = 75.0;
		phiBuffer[ 2 ] = 180.0;

		psiBuffer[ 0 ] = 180.0;
		psiBuffer[ 1 ] = -65.0;
		psiBuffer[ 2 ] = 180.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Gamma Turn (rev)" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 3;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = -75.0;
		phiBuffer[ 2 ] = 180.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = 65.0;
		psiBuffer[ 2 ] = 180.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 1 Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = -60.0;
		phiBuffer[ 2 ] = -90.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = -30.0;
		psiBuffer[ 2 ] = 0.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 2 Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = -60.0;
		phiBuffer[ 2 ] = 80.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = 120.0;
		psiBuffer[ 2 ] = 0.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 3 Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = -60.0;
		phiBuffer[ 2 ] = -60.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = -30.0;
		psiBuffer[ 2 ] = -30.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 5 Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = -80.0;
		phiBuffer[ 2 ] = -80.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = 80.0;
		psiBuffer[ 2 ] = 80.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 6a Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = -60.0;
		phiBuffer[ 2 ] = -90.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = 120.0;
		psiBuffer[ 2 ] = 0.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 6b Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = -120.0;
		phiBuffer[ 2 ] = -60.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = 120.0;
		psiBuffer[ 2 ] = 0.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 8 Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = -60.0;
		phiBuffer[ 2 ] = -120.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = -30.0;
		psiBuffer[ 2 ] = 120.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 1' Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = 60.0;
		phiBuffer[ 2 ] = 90.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = 30.0;
		psiBuffer[ 2 ] = 0.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 2' Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = 60.0;
		phiBuffer[ 2 ] = -80.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = -120.0;
		psiBuffer[ 2 ] = 0.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 3' Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = 60.0;
		phiBuffer[ 2 ] = 60.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = 30.0;
		psiBuffer[ 2 ] = 30.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
	else if ( !strcmp(option, "Beta 5' Turn" ))
	{
		gtk_entry_set_text(GTK_ENTRY(Entrys[0]),"-57.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[1]),"-47.0");
		gtk_entry_set_text(GTK_ENTRY(Entrys[2]),"180.0");

		nbuffer = 4;


		phiBuffer[ 0 ] = -57.0;
		phiBuffer[ 1 ] = 80.0;
		phiBuffer[ 2 ] = 80.0;
		phiBuffer[ 3 ] = -57.0;

		psiBuffer[ 0 ] = -47.0;
		psiBuffer[ 1 ] = -80.0;
		psiBuffer[ 2 ] = -80.0;
		psiBuffer[ 3 ] = -47.0;

		omegaBuffer[ 0 ] = 180.0;
		omegaBuffer[ 1 ] = 180.0;
		omegaBuffer[ 2 ] = 180.0;
		omegaBuffer[ 3 ] = 180.0;
		return ;
	}	
}
/********************************************************************************************************/
static GtkWidget *get_button_conformation()
{
        GtkTreeIter iter;
        GtkTreeStore *store;
	GtkTreeModel *model;
	GtkWidget *combobox;
	GtkCellRenderer *renderer;

	store = gtk_tree_store_new (1,G_TYPE_STRING);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "3-10 Helix", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Alpha Helix", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Alpha Helix (LH)", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta Sheet (anti-prl)", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta Sheet (parallel)", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 1 Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 1' Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 2 Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 2' Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 3 Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 3' Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 5 Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 5' Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 6a Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 6b Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Beta 8 Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Extended", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Gamma Turn", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Gamma Turn (rev)", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Omega Helix", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Pi Helix", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Polyglycine II", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Polyproline I", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Polyproline II", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Other", -1);

	sprintf(conf,"Extended");

        model = GTK_TREE_MODEL (store);
	combobox = gtk_combo_box_new_with_model (model);
	g_object_unref (model);
	g_signal_connect (G_OBJECT(combobox), "changed", G_CALLBACK(traite_conformation), NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (combobox), renderer, TRUE);
	gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (combobox), renderer, "text", 0, NULL);

	return combobox;
}
/********************************************************************************/
static GtkWidget* add_options(GtkWidget* Dlg,GtkWidget *box)
{
	GtkWidget* Table;
	GtkWidget* frame;
	GtkWidget* combobox;
	GtkWidget* Label;
	gchar* tlabel[] = {"Phi","Psi","Omega"};
	gchar* elabel[] = {"180.0","180.0","180.0"};
	gint i;

	frame = gtk_frame_new ("Conformation");
	gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
	gtk_container_set_border_width (GTK_CONTAINER (frame), 10);

	gtk_container_add(GTK_CONTAINER(box),frame);  
	gtk_widget_show (frame);

	Table = gtk_table_new(5,3,TRUE);
	gtk_container_add(GTK_CONTAINER(frame),Table);
  
	combobox =get_button_conformation();
	gtk_table_attach(GTK_TABLE(Table), combobox,0,3,0,1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  1,1);
	for(i=0;i<3;i++)
	{
		Label = gtk_label_new(tlabel[i]);
		gtk_table_attach(GTK_TABLE(Table),Label,0,1,i+1,i+2,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  1,1);
		Entrys[i] = gtk_entry_new();
		gtk_table_attach(GTK_TABLE(Table),Entrys[i],1,3,i+1,i+2,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  1,1);
  		gtk_editable_set_editable((GtkEditable*) Entrys[i],FALSE);
  		gtk_entry_set_text(GTK_ENTRY(Entrys[i]),elabel[i]);
	}
	Label = gtk_label_new("Isomer");
	gtk_table_attach(GTK_TABLE(Table),Label,0,1,4,5,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  1,1);
	ButtonL = gtk_radio_button_new_with_label( NULL," L " );
	gtk_table_attach(GTK_TABLE(Table),ButtonL,1,2,4,5,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  1,1);
  	ButtonD = gtk_radio_button_new_with_label( gtk_radio_button_get_group (GTK_RADIO_BUTTON (ButtonL)),
                       " D "); 
	gtk_table_attach(GTK_TABLE(Table),ButtonD,2,3,4,5,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  1,1);
  	g_object_set_data(G_OBJECT (Dlg), "ButtonL",ButtonL);
  	g_object_set_data(G_OBJECT (Dlg), "ButtonD",ButtonD);
	return combobox;
}
/******************************************************************************/
static void add_buttons(GtkWidget *Dlg,GtkWidget* box)
{
	GtkWidget* Table;
	GtkWidget* button;
	GtkWidget* frame;
	guint i;
	guint j;
        GtkStyle *button_style;
        GtkStyle *style;

	static char *Symb[ColonneT][LigneT]={
		{"Ala","Cys","Gly","His","Met","Thr"},
		{"Arg","Cyx","Hid","Ile","Phe","Tyr"},
		{"Asn","Gln","Hie","Leu","Pro","Trp"},
		{"Asp","Glu","Hip","Lys","Ser","Val"},
		{"Ace(N-cap)","Nme(C-cap)","Zwitterion","Undo Zwit." ,"00","00"}
		};
	static char *SymbOne[ColonneT][LigneT]={
		{"A","C","G","H","M","T"},
		{"R","C","H","I","F","Y"},
		{"N","Q","H","L","P","W"},
		{"D","E","H","K","S","V"},
		{"00","00","00","00" ,"00","00"}
		};

  frame = gtk_frame_new (NULL);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 10);

  gtk_container_add(GTK_CONTAINER(box),frame);  
  gtk_widget_show (frame);

  Table = gtk_table_new(LigneT,ColonneT,TRUE);
  gtk_container_add(GTK_CONTAINER(frame),Table);
  button_style = gtk_widget_get_style(Dlg); 
  
  for ( i = 0;i<LigneT;i++)
	  for ( j = 0;j<ColonneT;j++)
  {
	  if(strcmp(Symb[j][i],"00"))
	  {
		gchar tmp[100];
		if(strcmp(SymbOne[j][i],"00"))
			sprintf(tmp,"%s (%s)",Symb[j][i],SymbOne[j][i]);
		else
			sprintf(tmp,"%s",Symb[j][i]);
	  	button = gtk_button_new_with_label(tmp);

          	style=set_button_style(button_style,button,"H");
          	g_signal_connect(G_OBJECT(button), "clicked",
                            (GtkSignalFunc)build_polypeptide,(gpointer )Symb[j][i]);
	  	gtk_table_attach(GTK_TABLE(Table),button,j,j+1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  1,1);
	  	if(!strcmp(Symb[j][i],"Nme(C-cap)"))
          		g_signal_connect_swapped(G_OBJECT(button), "clicked",
                            (GtkSignalFunc)destroy_dlg,GTK_OBJECT(Dlg));
	  	if(!strcmp(Symb[j][i],"Ace(N-cap)"))
			  NCap = button;
	  	if(!strcmp(Symb[j][i],"Zwitterion"))
		{
			ZwitterionButton=button;
			gtk_widget_set_sensitive(button, FALSE);
		}
	  	if(!strcmp(Symb[j][i],"Undo Zwit."))
	  	{
			UndoZwitterionButton=button;
			gtk_widget_set_sensitive(button, FALSE);
	  	}
	  }

  }
  
}
/**********************************************************************/
void build_polypeptide_dlg()
{
  GtkWidget *Dlg;
  GtkWidget *Button;
  GtkWidget *hbox;
  GtkWidget *frame;
  GtkWidget *vboxframe;
  GtkWidget *combobox;
  
  init_variables();
  Dlg = gtk_dialog_new();
  gtk_window_set_title(GTK_WINDOW(Dlg),"Build PolyPeptide molecule");
  gtk_window_set_modal (GTK_WINDOW (Dlg), TRUE);
  gtk_window_set_transient_for(GTK_WINDOW(Dlg),GTK_WINDOW(GeomDlg));


  add_child(GeomDlg,Dlg,gtk_widget_destroy," Build PolyPep. mol. ");

  g_signal_connect(G_OBJECT(Dlg),"delete_event",(GtkSignalFunc)destroy_dlg,NULL);

  frame = gtk_frame_new (NULL);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 10);
  gtk_box_pack_start_defaults(GTK_BOX(GTK_DIALOG(Dlg)->vbox), frame);
  gtk_widget_show (frame);

  vboxframe = create_vbox(frame);

  hbox = create_hbox_false(vboxframe);
  hbox = vboxframe;

  add_buttons(Dlg,hbox);
  combobox = add_options(Dlg,hbox);


  gtk_box_set_homogeneous (GTK_BOX( GTK_DIALOG(Dlg)->action_area), FALSE);
  gtk_widget_realize(Dlg);
  Button = create_button(Dlg,"Close");
  gtk_box_pack_end (GTK_BOX( GTK_DIALOG(Dlg)->action_area), Button, FALSE, TRUE, 5);  
  g_signal_connect_swapped(G_OBJECT(Button), "clicked",(GtkSignalFunc)destroy_dlg,GTK_OBJECT(Dlg));

  GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
  gtk_widget_grab_default(Button);
  gtk_widget_show_all(GTK_DIALOG(Dlg)->vbox);
  gtk_widget_show_all(GTK_DIALOG(Dlg)->action_area);
  gtk_widget_show_now(Dlg);

  fit_windows_position(GeomDlg, Dlg);

  gtk_combo_box_set_active (GTK_COMBO_BOX (combobox), 16);
}

