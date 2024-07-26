/* MopacMolecule.c */
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

#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "../../Config.h"
#include "../Common/Global.h"
#include "../Mopac/MopacTypes.h"
#include "../Mopac/MopacGlobal.h"
#include "../Mopac/MopacRem.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/GeomConversion.h"
#include "../Geometry/GeomXYZ.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Utils/Utils.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Constantes.h"
#include "../Utils/GabeditTextEdit.h"
#include "../Geometry/InterfaceGeom.h"
#include "../Common/Windows.h"
#include "../Utils/Constantes.h"
#include "../Utils/AtomsProp.h"

/************************************************************************************************************/
static gint totalCharge = 0;
static gint spinMultiplicity=1;
/************************************************************************************************************/
gint getMopacMultiplicity()
{
	return spinMultiplicity;
}
/************************************************************************************************************/
void initMopacMoleculeButtons()
{
}
/************************************************************************************************************/
void initMopacMolecule()
{
	mopacMolecule.listOfAtoms = NULL;  
	mopacMolecule.totalNumberOfElectrons = 0;
	mopacMolecule.numberOfValenceElectrons = 0;
	mopacMolecule.numberOfAtoms = 0;
}
/************************************************************************************************************/
void freeMopacMolecule()
{
	static gboolean first = TRUE;

	if(first)
	{
		initMopacMolecule();
		first = FALSE;
		return;
	}

	if(mopacMolecule.listOfAtoms) g_free(mopacMolecule.listOfAtoms);
	initMopacMolecule();
}
/************************************************************************************************************/
static gint setMopacMoleculeFromSXYZ(gint nAtoms, gchar** symbols, gdouble* X, gdouble* Y, gdouble* Z)
{
	gint n;
	MopacAtom* atomList = NULL;

	mopacMolecule.listOfAtoms = NULL;  
	mopacMolecule.numberOfAtoms = 0;
	if(nAtoms<1) return 1;

	mopacMolecule.listOfAtoms = (MopacAtom*)g_malloc(sizeof(MopacAtom)*(nAtoms));
	if(mopacMolecule.listOfAtoms==NULL) return -1;

	mopacMolecule.numberOfAtoms = nAtoms;

	atomList = mopacMolecule.listOfAtoms;
	for(n=0; n<mopacMolecule.numberOfAtoms; n++)
	{
		atomList->position[0]  = X[n];
		atomList->position[1]  = Y[n];
		atomList->position[2]  = Z[n];
		atomList->symbol  = g_strdup(symbols[n]);
		atomList++;
	}

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
static gboolean setMopacMoleculeFromGeomXYZ()
{
	gint i;
	gchar** symbols = NULL;
	gdouble* X = NULL;
	gdouble* Y = NULL;
	gdouble* Z = NULL;
	gint numberOfAtoms = NcentersXYZ;

	if(numberOfAtoms<1) return FALSE;

	symbols = (gchar**)g_malloc(sizeof(gchar*)*(numberOfAtoms));

	if(symbols == NULL) return FALSE;

	X = (gdouble*)g_malloc(sizeof(gdouble)*(numberOfAtoms));
	if(X == NULL) return FALSE;
	Y = (gdouble*)g_malloc(sizeof(gdouble)*(numberOfAtoms));
	if(Y == NULL) return FALSE;
	Z = (gdouble*)g_malloc(sizeof(gdouble)*(numberOfAtoms));
	if(Z == NULL) return FALSE;

	mopacMolecule.totalNumberOfElectrons = 0;
	for(i=0; i<numberOfAtoms; i++)
	{
		SAtomsProp prop = prop_atom_get(GeomXYZ[i].Symb);

		symbols[i] = g_strdup(GeomXYZ[i].Symb);
		setXYZFromGeomXYZ(i, &X[i] , &Y[i] , &Z[i]);
		mopacMolecule.totalNumberOfElectrons += prop.atomicNumber;
	}
	mopacMolecule.numberOfValenceElectrons = mopacMolecule.totalNumberOfElectrons;
	setMopacMoleculeFromSXYZ(numberOfAtoms, symbols, X, Y, Z);

	for (i=0;i<(gint)NcentersXYZ;i++) g_free( symbols[i]);
	g_free( symbols);
	g_free(X);
	g_free(Y);
	g_free(Z);
	return TRUE;
}
/************************************************************************************************************/
static gboolean setMopacMoleculeFromGeomZMatrix()
{
	iprogram=PROG_IS_GAMESS;
	if(!zmat_to_xyz()) return FALSE;
	delete_dummy_atoms();
	/* conversion_zmat_to_xyz();*/
	return setMopacMoleculeFromGeomXYZ();
}
/************************************************************************************************************/
gboolean setMopacMolecule()
{
	freeMopacMolecule();
	if(MethodeGeom==GEOM_IS_XYZ && setMopacMoleculeFromGeomXYZ()) return TRUE;
	if(setMopacMoleculeFromGeomZMatrix()) return TRUE;
	return FALSE;
}
/************************************************************************************************************/
void setMopacGeometryFromInputFile(gchar* fileName)
{
	read_XYZ_from_mopac_input_file(fileName);
	setMopacMolecule();
}
/*************************************************************************************************************/
static gdouble getMinDistance()
{
	gdouble d=0;
	gint i;
	gint k;
	MopacAtom* atomList = mopacMolecule.listOfAtoms;
	for(i=0; i<mopacMolecule.numberOfAtoms-1; i++)
	{
		gdouble dd = 0;
		for(k=0;k<3;k++) 
		{
			gdouble xx = atomList->position[k]-atomList->position[k+1];
			dd += xx*xx;
		}
		if(i==0) d = dd;
		else if(d>dd) d= dd;
		atomList++;
	}
	d = sqrt(d);

	return d;
}
/*************************************************************************************************************/
static void setFirstAtomToXAxis(gint numberOfAtoms, gdouble* X, gdouble* Y, gdouble*Z)
{
	gdouble d;
	gdouble s;
	gdouble c;
	gint i;
	gdouble positionTolerance = -1;

	if(numberOfAtoms<1) return;
	d = X[0]*X[0]+Y[0]*Y[0];
	if(d<1e-10) return;
	d = sqrt(d);
	if(positionTolerance<0) positionTolerance= getMinDistance()/50;

	/* perform rotation */
	s = -Y[0]/d;
	c = +X[0]/d;

	for (i=0;i<numberOfAtoms;i++)
	 {
		 gdouble x = X[i];
		 gdouble y = Y[i];
		X[i] = c*x - s*y;
		Y[i] = s*x + c*y;
		/* if(fabs(X[i])<positionTolerance) X[i]=0.0;*/
		if(fabs(Y[i])<positionTolerance) Y[i]=0.0;
	 }
	/* printf("tolerance position = %f\n",positionTolerance);*/

}
/*************************************************************************************************************/
static gint getRealNumberXYZVariables()
{
	gint k=0;
	gint i;
        for(i=0;i<NcentersXYZ;i++)
	{
		if(!test(GeomXYZ[i].X))k++;
		if(!test(GeomXYZ[i].Y))k++;
		if(!test(GeomXYZ[i].Z))k++;
	}
	return k;
}
/*************************************************************************************************************/
static void setValueVariableXYZ(gchar* source, gchar* value, gint* k)
{
	if(!test(source)) 
	{
		sprintf(value,"%f ", get_value_variableXYZ(source));
		*k = 1;
	}
	else
	{
		sprintf(value,"%s ",source);
		*k = 0;
	}
}
/*************************************************************************************************************/
static void setValueVariableZmat(gchar* source, gchar* value, gint* k)
{
	if(!test(source)) 
	{
		sprintf(value,"%f ", get_value_variableZmat(source));
		*k = 1;
	}
	else
	{
		sprintf(value,"%s ",source);
		*k = 0;
	}
}
/*************************************************************************************************************/
static gint getRealNumberZmatVariables()
{
	gint k=0;
	gint i;
        for(i=0;i<NcentersZmat;i++)
	{
        	if(Geom[i].Nentry>NUMBER_ENTRY_0 && !test(Geom[i].R)) k++;
        	if(Geom[i].Nentry>NUMBER_ENTRY_R && !test(Geom[i].Angle)) k++;
        	if(Geom[i].Nentry>NUMBER_ENTRY_ANGLE && !test(Geom[i].Dihedral)) k++;
	}
	return k;
}
/*************************************************************************************************************/
static void putMopacMoleculeInTextEditor()
{
        gchar buffer[BSIZE];
        gchar b1[20];
        gchar b2[20];
        gchar b3[20];
        gchar con[20];
	gint i;
	gint k1 = 0;
	gint k2 = 0;
	gint k3 = 0;
	gint nvar = 0;

	if(mopacMolecule.numberOfAtoms<1) return;
	if(MethodeGeom==GEOM_IS_XYZ)
		nvar  = getRealNumberXYZVariables();
	else
		nvar  = getRealNumberZmatVariables();

	if(MethodeGeom==GEOM_IS_XYZ)
      		for (i=0;i<NcentersXYZ;i++)
		{
			setValueVariableXYZ(GeomXYZ[i].X, b1, &k1);
			setValueVariableXYZ(GeomXYZ[i].Y, b2, &k2);
			setValueVariableXYZ(GeomXYZ[i].Z, b3, &k3);
			if(nvar==0) { k1 = 1; k2 = 1; k3 = 1;}

			sprintf(buffer,"%s  %s %d %s %d %s %d\n",GeomXYZ[i].Symb,
					b1, k1,
					b2, k2,
					b3, k3
					);
        		gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, buffer, -1);
		}
	else
	{
        	for(i=0;i<NcentersZmat;i++)
        	{
			SAtomsProp prop = prop_atom_get(Geom[i].Symb);
        		if(Geom[i].Nentry>NUMBER_ENTRY_ANGLE)
			{
				setValueVariableZmat(Geom[i].R, b1, &k1);
				setValueVariableZmat(Geom[i].Angle, b2, &k2);
				setValueVariableZmat(Geom[i].Dihedral, b3, &k3);
				sprintf(con,"%s %s %s", Geom[i].NR, Geom[i].NAngle, Geom[i].NDihedral);
				if(nvar==0) { k1 = 1; k2 = 1; k3 = 1;}

				sprintf(buffer,"%s  %s %d %s %d %s %d %s\n",
						Geom[i].Symb,
						b1, k1,
						b2, k2,
						b3, k3,
						con
						);
        			gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, &prop.color, buffer, -1);
			}
			else
        		if(Geom[i].Nentry>NUMBER_ENTRY_R)
			{
				setValueVariableZmat(Geom[i].R, b1, &k1);
				setValueVariableZmat(Geom[i].Angle, b2, &k2);
				sprintf(b3,"0.0"); k3 = 0;
				sprintf(con,"%s %s %s", Geom[i].NR, Geom[i].NAngle, "0");

				if(nvar==0) { k1 = 1; k2 = 1;}
				sprintf(buffer,"%s  %s %d %s %d %s %d %s\n",
						Geom[i].Symb,
						b1, k1,
						b2, k2,
						b3, k3,
						con
						);

        			gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, &prop.color, buffer, -1);
			}
			else
        		if(Geom[i].Nentry>NUMBER_ENTRY_0)
			{
				setValueVariableZmat(Geom[i].R, b1, &k1);
				sprintf(b2,"0.0"); k2 = 0;
				sprintf(b3,"0.0"); k3 = 0;
				sprintf(con,"%s %s %s", Geom[i].NR, "0", "0");

				if(nvar==0) { k1 = 1;}
				sprintf(buffer,"%s  %s %d %s %d %s %d %s\n",
						Geom[i].Symb,
						b1, k1,
						b2, k2,
						b3, k3,
						con
						);
        			gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, &prop.color, buffer, -1);
			}
			else
			{
				sprintf(b1,"0.0"); k1 = 0;
				sprintf(b2,"0.0"); k2 = 0;
				sprintf(b3,"0.0"); k3 = 0;
				sprintf(con,"%s %s %s", "0.0", "0", "0");
				sprintf(buffer,"%s  %s %d %s %d %s %d %s\n",
						Geom[i].Symb,
						b1, k1,
						b2, k2,
						b3, k3,
						con
						);
        			gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, &prop.color, buffer, -1);
			}
        	}
	}

}
/************************************************************************************************************/
static void getMultiplicityName(gint multiplicity, gchar* buffer)
{
	if(multiplicity==1) sprintf(buffer,"Singlet");
	else if(multiplicity==2) sprintf(buffer,"Doublet");
	else if(multiplicity==3) sprintf(buffer,"Triplet");
	else if(multiplicity==4) sprintf(buffer,"Quartet");
	else if(multiplicity==5) sprintf(buffer,"Quintet");
	else if(multiplicity==6) sprintf(buffer,"Sextet");
	else sprintf(buffer,"UNKNOWN");
}
/************************************************************************************************************/
void putMopacChargeMultiplicityInTextEditor()
{
	gchar buffer[BSIZE];
	gchar mul[20];
	getMultiplicityName(spinMultiplicity, mul);
	sprintf(buffer,"CHARGE=%d %s ",totalCharge,mul);
        gabedit_text_insert (GABEDIT_TEXT(text), NULL,  NULL, NULL, buffer,-1);
}
/************************************************************************************************************/
void putMopacMoleculeInfoInTextEditor()
{
	putMopacMoleculeInTextEditor();
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
                  2,2);

	g_object_set_data(G_OBJECT (newButton), "Label",NULL);
	g_object_set_data(G_OBJECT (newButton), "Type",NULL);
	return newButton;
}
/************************************************************************************************************/
static void setComboSpinMultiplicity(GtkWidget *comboSpinMultiplicity)
{
	GList *glist = NULL;
	gint i;
	gint nlist = 0;
	gchar** list = NULL;
	gint k;
	gint kinc;
	gint ne = mopacMolecule.numberOfValenceElectrons - totalCharge;

	if(ne%2==0) nlist = ne/2+1;
	else nlist = (ne+1)/2;

	if(nlist<1) return;
	list = g_malloc(nlist*sizeof(gchar*));
	if(!list) return;
	for(i=0;i<nlist;i++)
		list[i] = g_malloc(10*sizeof(gchar));


	if(GTK_IS_WIDGET(comboSpinMultiplicity)) gtk_widget_set_sensitive(comboSpinMultiplicity, TRUE);
	if(ne%2==0) k = 1;
	else k = 2;

	kinc = 2;
	for(i=0;i<nlist;i++)
	{
		sprintf(list[i],"%d",k);
		k+=kinc;
	}

  	for(i=0;i<nlist;i++) glist = g_list_append(glist,list[i]);

  	gtk_combo_box_entry_set_popdown_strings( comboSpinMultiplicity, glist) ;
  	g_list_free(glist);
	if(list)
	{
		for(i=0;i<nlist;i++) if(list[i]) g_free(list[i]);
		g_free(list);
	}
}
/********************************************************************************/
static void setComboCharge(GtkWidget *comboCharge)
{
	GList *glist = NULL;
	gint i;
	gint nlist;
	gchar** list = NULL;
	gint k;

	nlist = mopacMolecule.numberOfValenceElectrons*2-2+1;

	if(nlist<1) return;
	list = g_malloc(nlist*sizeof(gchar*));
	if(!list) return;
	for(i=0;i<nlist;i++)
		list[i] = g_malloc(10*sizeof(gchar));


	sprintf(list[0],"0");
	k = 1;
	for(i=1;i<nlist-1;i+=2)
	{
		sprintf(list[i],"+%d",k);
		sprintf(list[i+1],"%d",-k);
		k += 1;
	}

  	for(i=0;i<nlist;i++) glist = g_list_append(glist,list[i]);

  	gtk_combo_box_entry_set_popdown_strings( comboCharge, glist) ;
  	g_list_free(glist);
	if(list)
	{
		for(i=0;i<nlist;i++) if(list[i]) g_free(list[i]);
		g_free(list);
	}
}
/**********************************************************************/
static void changedEntrySpinMultiplicity(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* entryText = NULL;
	 
	if(!GTK_IS_WIDGET(entry)) return;

	entryText = gtk_entry_get_text(GTK_ENTRY(entry));
	if(strlen(entryText)<1)return;

	spinMultiplicity=atoi(entryText);
	if(spinMultiplicity==1)
	{
		/* OK RHF*/
	}
	else 
	{
		/* remove RHF from list*/
	}
}
/**********************************************************************/
static void changedEntryCharge(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* entryText = NULL;
	GtkWidget* comboSpinMultiplicity = NULL;
	GtkWidget* labelNumberOfElectrons = NULL;
	 
	if(!GTK_IS_WIDGET(entry)) return;

	entryText = gtk_entry_get_text(GTK_ENTRY(entry));
	if(strlen(entryText)<1)return;

	totalCharge = atoi(entryText);

	comboSpinMultiplicity  = g_object_get_data(G_OBJECT (entry), "ComboSpinMultiplicity");
	if(GTK_IS_WIDGET(comboSpinMultiplicity)) setComboSpinMultiplicity(comboSpinMultiplicity);

	labelNumberOfElectrons = g_object_get_data(G_OBJECT (entry), "LabelNumberOfElectrons");

	if(GTK_IS_WIDGET(labelNumberOfElectrons))
	{
		gint ne = mopacMolecule.numberOfValenceElectrons - totalCharge;
		gchar buffer[BSIZE];
		sprintf(buffer, "Number of electrons = %d",ne);
		gtk_label_set_text(GTK_LABEL(labelNumberOfElectrons),buffer);
	}
}
/**********************************************************************/
static GtkWidget* addComboListToATable(GtkWidget* table,
		gchar** list, gint nlist, gint i, gint j, gint k)
{
	GtkWidget *entry = NULL;
	GtkWidget *combo = NULL;

	combo = create_combo_box_entry(list, nlist, TRUE, -1, -1);

	gtk_table_attach(GTK_TABLE(table),combo,j,j+k,i,i+1,
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
		(GtkAttachOptions)	(GTK_FILL | GTK_SHRINK),
                  2,2);
	entry = GTK_BIN (combo)->child;
	g_object_set_data(G_OBJECT (entry), "Combo",combo);
	gtk_widget_set_size_request(GTK_WIDGET(entry),(gint)(ScreenHeight*0.2),-1);

	return entry;
}
/***********************************************************************************************/
static GtkWidget *addMopacChargeToTable(GtkWidget *table, gint i)
{
	GtkWidget* entryCharge = NULL;
	GtkWidget* comboCharge = NULL;
	gint nlistCharge = 1;
	gchar* listCharge[] = {"0"};

	add_label_table(table,"Charge",(gushort)i,0);
	add_label_table(table,":",(gushort)i,1);
	entryCharge = addComboListToATable(table, listCharge, nlistCharge, i, 2, 1);
	comboCharge  = g_object_get_data(G_OBJECT (entryCharge), "Combo");
	gtk_widget_set_sensitive(entryCharge, FALSE);

	return comboCharge;
}
/***********************************************************************************************/
static GtkWidget *addMopacSpinToTable(GtkWidget *table, gint i)
{
	GtkWidget* entrySpinMultiplicity = NULL;
	GtkWidget* comboSpinMultiplicity = NULL;
	gint nlistspinMultiplicity = 1;
	gchar* listspinMultiplicity[] = {"0"};

	add_label_table(table,"Spin multiplicity",(gushort)i,0);
	add_label_table(table,":",(gushort)i,1);
	entrySpinMultiplicity = addComboListToATable(table, listspinMultiplicity, nlistspinMultiplicity, i, 2, 1);
	comboSpinMultiplicity  = g_object_get_data(G_OBJECT (entrySpinMultiplicity), "Combo");
	gtk_widget_set_sensitive(entrySpinMultiplicity, FALSE);

	g_signal_connect(G_OBJECT(entrySpinMultiplicity),"changed", GTK_SIGNAL_FUNC(changedEntrySpinMultiplicity),NULL);
	return comboSpinMultiplicity;
}
/***********************************************************************************************/
static GtkWidget *addLabelNumberOfElectronsToTable(GtkWidget *table, gint i, GtkWidget *comboCharge)
{
	GtkWidget* labelNumberOfElectrons = NULL;
	GtkWidget* hbox = NULL;
	GtkWidget* entryCharge = GTK_BIN(comboCharge)->child;

	labelNumberOfElectrons = gtk_label_new(" ");
	hbox = gtk_hbox_new(0,FALSE);
	gtk_box_pack_start (GTK_BOX (hbox), labelNumberOfElectrons, FALSE, FALSE, 0);
	gtk_table_attach(GTK_TABLE(table),hbox,0,0+3,i,i+1,
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
		(GtkAttachOptions)	(GTK_FILL | GTK_SHRINK),
                  2,2);

	g_object_set_data(G_OBJECT (entryCharge), "LabelNumberOfElectrons", labelNumberOfElectrons);
	g_signal_connect(G_OBJECT(entryCharge),"changed", GTK_SIGNAL_FUNC(changedEntryCharge),NULL);
	return labelNumberOfElectrons;
}
/***********************************************************************************************/
void createMopacChargeMultiplicityFrame(GtkWidget *box)
{
	GtkWidget* frame;
	GtkWidget* sep;
	GtkWidget* labelNumberOfElectrons;
	GtkWidget* vboxFrame;
	GtkWidget* comboSpinMultiplicity = NULL;
	GtkWidget* comboCharge = NULL;
	GtkWidget *table = NULL;
	gint i;

	totalCharge = 0;
	spinMultiplicity=1;

	table = gtk_table_new(3,5,FALSE);

	frame = gtk_frame_new ("Charge & Multiplicty");
	gtk_widget_show (frame);
	gtk_box_pack_start (GTK_BOX (box), frame, TRUE, TRUE, 3);
	gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

	vboxFrame = gtk_vbox_new (FALSE, 3);
	gtk_widget_show (vboxFrame);
	gtk_container_add (GTK_CONTAINER (frame), vboxFrame);

	gtk_box_pack_start (GTK_BOX (vboxFrame), table, TRUE, TRUE, 0);

	i = 0;
	comboCharge = addMopacChargeToTable(table, i);
	i = 1;
	comboSpinMultiplicity = addMopacSpinToTable(table, i);
	i = 2;
	sep = gtk_hseparator_new ();;
	gtk_table_attach(GTK_TABLE(table),sep,0,0+3,i,i+1,
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
                  2,2);

	i = 3;
	labelNumberOfElectrons=addLabelNumberOfElectronsToTable(table, i, comboCharge);

	if(GTK_IS_COMBO_BOX(comboCharge))
		g_object_set_data(G_OBJECT (GTK_BIN(comboCharge)->child), "ComboSpinMultiplicity", comboSpinMultiplicity);
	setComboCharge(comboCharge);
	setComboSpinMultiplicity(comboSpinMultiplicity);
	if(GTK_IS_WIDGET(labelNumberOfElectrons))
	{
		gint ne = mopacMolecule.numberOfValenceElectrons - totalCharge;
		gchar buffer[BSIZE];
		sprintf(buffer, "Number of electrons = %d",ne);
		gtk_label_set_text(GTK_LABEL(labelNumberOfElectrons),buffer);
	}

	/* activate sensitivity */
	/*
	if(GTK_IS_WIDGET(comboMethod)) setComboMethod(comboMethod);
	g_object_set_data(G_OBJECT (box), "EntryMethod", GTK_BIN(comboMethod)->child);
	*/
}
/************************************************************************************************************/
