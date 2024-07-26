/* GInterfaceRoute.c */
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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Common/Global.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/GabeditTextEdit.h"
#include "GInterfaceLink.h"
#include "GInterfaceMethodeBase.h"
#include "GaussGlobal.h"

/*****************************************************************************************/
static void polar_activate(GtkWidget *button,gpointer data)
{
  	GtkWidget* buttonOptions =(GtkWidget*)data;
	if (GTK_TOGGLE_BUTTON (button)->active) 
	{
  		if(Tpolar == NULL ) Tpolar=g_malloc(50*sizeof(gchar));
  		sprintf(Tpolar," polar");
		if(GTK_IS_WIDGET(buttonOptions)) gtk_widget_set_sensitive(buttonOptions,TRUE);
	}
	else
	{
  		if(Tpolar) g_free(Tpolar);
  		Tpolar = NULL;
		if(GTK_IS_WIDGET(buttonOptions)) gtk_widget_set_sensitive(buttonOptions,FALSE);
	}
}
/*****************************************************************************************/
static void gene_polar(GtkWidget *b,gpointer data)
{
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext;
  guint ipar;
  ipar=0;
  if(Tpolar == NULL ) Tpolar=g_malloc(50*sizeof(gchar));
  sprintf(Tpolar," polar");
  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entrytext,"default") )
  {
  ipar=1;
  sprintf(Tpolar,"%s(%s",Tpolar,entrytext);
  }
  entry=entryall[1];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entrytext,"default") )
  {
  if(ipar)
  sprintf(Tpolar,"%s,Step=%s",Tpolar,entrytext);
  else 
  {
  ipar=1;
  sprintf(Tpolar,"%s(Step=%s",Tpolar,entrytext);
  }
  }
  if(ipar)
  sprintf(Tpolar,"%s) ",Tpolar);
}
/*****************************************************************************************/
static void create_polar_option (GtkWidget* Wins)
{
  GtkWidget *fp;
  GtkWidget *frame;
  GtkWidget **entry;
  GtkWidget *vboxall;
  GtkWidget *vboxframe;
  GtkWidget *hbox1;
  GtkWidget *hbox2;
  GtkWidget *button;
  int nlist = 1;
  gchar *list[4];
  entry=g_malloc(2*sizeof(GtkWidget*));
  
  fp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_modal(GTK_WINDOW(fp),TRUE);
  gtk_window_set_position(GTK_WINDOW(fp),GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(fp),"Options for dipole polarizabilities");
  gtk_container_set_border_width (GTK_CONTAINER (fp), 5);
  gtk_window_set_transient_for(GTK_WINDOW(fp),GTK_WINDOW(Wins));
  gtk_window_set_modal (GTK_WINDOW (fp), TRUE);

  add_child(Wins,fp,gtk_widget_destroy,"  Dipole polar. ");
  g_signal_connect(G_OBJECT(fp),"delete_event",(GtkSignalFunc)delete_child,NULL);

  vboxall = create_vbox(fp);
  frame = gtk_frame_new ("Dipole polarizabilities");
  gtk_widget_ref (frame);
  g_object_set_data_full (G_OBJECT (fp), "frame", frame,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  gtk_container_add (GTK_CONTAINER (vboxall), frame);
  gtk_widget_show (frame);

  vboxframe = create_vbox(frame);
  nlist=4;
  list[0]=g_strdup("default");
  list[1]=g_strdup("Analytic");
  list[2]=g_strdup("Numerical");
  list[3]=g_strdup("EnOnly");
  hbox1 = create_hbox(vboxframe);
  entry[0]= create_combo_box_entry_liste(fp,hbox1,"Type of second derivatives  : ",list,nlist);
  nlist=4;
  list[0]=g_strdup("default");
  list[1]=g_strdup("1");
  list[2]=g_strdup("10");
  list[3]=g_strdup("100");
  hbox1 = create_hbox(vboxframe);
  entry[1]= create_combo_box_entry_liste(fp,hbox1,"Step size in the electric field :",list,nlist);

  hbox2 = create_hbox(vboxall);
  gtk_widget_realize(fp);

  button = create_button(fp,"Cancel");
  gtk_box_pack_start (GTK_BOX( hbox2), button, TRUE, TRUE, 3);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(fp));
  gtk_widget_show (button);

  button = create_button(fp,"OK");
  gtk_box_pack_start (GTK_BOX( hbox2), button, TRUE, TRUE, 3);
  gtk_widget_show (button);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(gene_polar),(gpointer)entry);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(fp));

   
  gtk_widget_show_all(fp);
}
/*****************************************************************************************/
static void gene_scf(GtkWidget *b,gpointer data)
{
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext;
  guint ipar;
  ipar=0;
  if(Tscf == NULL ) Tscf=g_malloc(50*sizeof(gchar));
  sprintf(Tscf," SCF");
  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entrytext,"default") )
  {
  ipar=1;
  sprintf(Tscf,"%s(%s",Tscf,entrytext);
  }
  entry=entryall[1];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entrytext,"default") )
  {
  if(ipar)
  sprintf(Tscf,"%s,Vshift=%s",Tscf,entrytext);
  else 
  {
  ipar=1;
  sprintf(Tscf,"%s(Vshift=%s",Tscf,entrytext);
  }
  }
  entry=entryall[2];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entrytext,"default") )
  {
  if(ipar)
  sprintf(Tscf,"%s,MaxCycle=%s",Tscf,entrytext);
  else 
  {
  ipar=1;
  sprintf(Tscf,"%s(MaxCycle=%s",Tscf,entrytext);
  }
  }
  entry=entryall[3];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entrytext,"default") )
  {
  if(ipar)
  sprintf(Tscf,"%s,MaxRot=%s",Tscf,entrytext);
  else 
  {
  ipar=1;
  sprintf(Tscf,"%s(MaxRot=%s",Tscf,entrytext);
  }
  }
  entry=entryall[4];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entrytext,"default") )
  {
  if(ipar)
  sprintf(Tscf,"%s,Conver=%s",Tscf,entrytext);
  else 
  {
  ipar=1;
  sprintf(Tscf,"%s(Conver=%s",Tscf,entrytext);
  }
  }
  if(ipar)
  sprintf(Tscf,"%s) ",Tscf);
  else
  {
  	g_free(Tscf);
        Tscf = (char *)NULL;
  }
}
/*****************************************************************************************/
static void create_scf_option (GtkWidget* Wins)
{
  GtkWidget *fp;
  GtkWidget *frame;
  GtkWidget **entry;
  GtkWidget *vboxall;
  GtkWidget *vboxframe;
  GtkWidget *hbox1;
  GtkWidget *hbox2;
  GtkWidget *button;
  int nlist = 1;
  gchar *list[10];
  entry=g_malloc(5*sizeof(GtkWidget*));
  
  fp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_modal(GTK_WINDOW(fp),TRUE);
  gtk_window_set_position(GTK_WINDOW(fp),GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(fp),"Controls of the SCF procedure");
  gtk_container_set_border_width (GTK_CONTAINER (fp), 5);
  gtk_window_set_transient_for(GTK_WINDOW(fp),GTK_WINDOW(Wins));
  gtk_window_set_modal (GTK_WINDOW (fp), TRUE);

  add_child(Wins,fp,gtk_widget_destroy,"  Dipole polar. ");
  g_signal_connect(G_OBJECT(fp),"delete_event",(GtkSignalFunc)delete_child,NULL);

  vboxall = create_vbox(fp);
  frame = gtk_frame_new ("SCF procedure");
  gtk_widget_ref (frame);
  g_object_set_data_full (G_OBJECT (fp), "frame", frame,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  gtk_container_add (GTK_CONTAINER (vboxall), frame);
  gtk_widget_show (frame);

  vboxframe = create_vbox(frame);
  hbox1 = create_hbox(vboxframe);
  list[0]=g_strdup("");
  nlist=9;
  list[0]=g_strdup("default");
  list[1]=g_strdup("Direct");
  list[2]=g_strdup("InCore");
  list[3]=g_strdup("QC");
  list[4]=g_strdup("DIIS");
  list[5]=g_strdup("SD");
  list[6]=g_strdup("SSD");
  list[7]=g_strdup("DM");
  list[8]=g_strdup("Conventional");
  entry[0]= create_combo_box_entry_liste(fp,hbox1,"Algorithm  : ",list,nlist);
  nlist=3;
  list[0]=g_strdup("default");
  list[1]=g_strdup("100");
  list[2]=g_strdup("200");
  hbox1 = create_hbox(vboxframe);
  entry[1]= create_combo_box_entry_liste(fp,hbox1,"Shift orbital energies : ",list,nlist);
  nlist=3;
  list[0]=g_strdup("default");
  list[1]=g_strdup("64");
  list[2]=g_strdup("512");
  hbox1 = create_hbox(vboxframe);
  entry[2]= create_combo_box_entry_liste(fp,hbox1,"Maximum number of SCF cycles : ",list,nlist);
  nlist=4;
  list[0]=g_strdup("default");
  list[1]=g_strdup("2");
  list[2]=g_strdup("3");
  list[3]=g_strdup("4");
  hbox1 = create_hbox(vboxframe);
  entry[3]= create_combo_box_entry_liste(fp,hbox1,"Maximum rotation gradient :",list,nlist);
  nlist=5;
  list[0]=g_strdup("default");
  list[1]=g_strdup("6");
  list[2]=g_strdup("7");
  list[3]=g_strdup("8");
  list[4]=g_strdup("9");
  hbox1 = create_hbox(vboxframe);
  entry[4]= create_combo_box_entry_liste(fp,hbox1,"Convergence criterion :",list,nlist);
  
  hbox2 = create_hbox(vboxall);
  gtk_widget_realize(fp);

  button = create_button(fp,"Cancel");
  gtk_box_pack_start (GTK_BOX( hbox2), button, TRUE, TRUE, 3);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(fp));
  gtk_widget_show (button);

  button = create_button(fp,"OK");
  gtk_box_pack_start (GTK_BOX( hbox2), button, TRUE, TRUE, 3);
  gtk_widget_show (button);
  g_signal_connect(G_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(gene_scf),(gpointer)entry);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(fp));


   
  gtk_widget_show_all(fp);
}
/*****************************************************************************************/
static void freq_activate(GtkWidget *button,gpointer data)
{
  	GtkWidget* buttonOptions =(GtkWidget*)data;
	if (GTK_TOGGLE_BUTTON (button)->active) 
	{
  		if(Tfreq == NULL ) Tfreq=g_malloc(50*sizeof(gchar));
  		sprintf(Tfreq," freq");
		if(GTK_IS_WIDGET(buttonOptions)) gtk_widget_set_sensitive(buttonOptions,TRUE);
	}
	else
	{
  		if(Tfreq) g_free(Tfreq);
  		Tfreq = NULL;
		if(GTK_IS_WIDGET(buttonOptions)) gtk_widget_set_sensitive(buttonOptions,FALSE);
	}
}
/*****************************************************************************************/
static void gene_freq(GtkWidget *b,gpointer data)
{
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext;
  guint ipar;
  ipar=0;
  if(Tfreq == NULL ) Tfreq=g_malloc(50*sizeof(gchar));
  sprintf(Tfreq," freq");
  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (!strcmp(entrytext,"Yes") )
  {
  ipar=1;
  sprintf(Tfreq,"%s(VCD",Tfreq);
  }
  entry=entryall[1];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (!strcmp(entrytext,"Yes") )
  {
  if(ipar)
  sprintf(Tfreq,"%s,Raman",Tfreq);
  else 
  {
  ipar=1;
  sprintf(Tfreq,"%s(Raman",Tfreq);
  }
  }
  entry=entryall[2];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entrytext,"default") )
  {
  if(ipar)
  sprintf(Tfreq,"%s,%s",Tfreq,entrytext);
  else 
  {
  ipar=1;
  sprintf(Tfreq,"%s(%s",Tfreq,entrytext);
  }
  }
  entry=entryall[3];
  entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
  if (strcmp(entrytext,"default") )
  {
  if(ipar)
  sprintf(Tfreq,"%s,Step=%s",Tfreq,entrytext);
  else 
  {
  ipar=1;
  sprintf(Tfreq,"%s(Step=%s",Tfreq,entrytext);
  }
  }
  if(ipar)
  sprintf(Tfreq,"%s) ",Tfreq);
}
/*****************************************************************************************/
static void create_freq_option ( GtkWidget *Wins)
{
  GtkWidget *fp;
  GtkWidget *frame;
  GtkWidget **entry;
  GtkWidget *vboxall;
  GtkWidget *vboxframe;
  GtkWidget *hbox1;
  GtkWidget *hbox2;
  GtkWidget *button;
  int nlist = 1;
  gchar *list[4];
  entry=g_malloc(4*sizeof(GtkWidget*));

  fp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_modal(GTK_WINDOW(fp),TRUE);
  gtk_window_set_position(GTK_WINDOW(fp),GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(fp),"Compute frequencies");
  gtk_container_set_border_width (GTK_CONTAINER (fp), 5);

  gtk_window_set_transient_for(GTK_WINDOW(fp),GTK_WINDOW(Wins));
  gtk_window_set_modal (GTK_WINDOW (fp), TRUE);

  add_child(Wins,fp,gtk_widget_destroy," Constants force ");
  g_signal_connect(G_OBJECT(fp),"delete_event",(GtkSignalFunc)delete_child,NULL);

  vboxall = create_vbox(fp);
  frame = gtk_frame_new ("Force constants");
  gtk_widget_ref (frame);
  g_object_set_data_full (G_OBJECT (fp), "frame", frame,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  gtk_container_add (GTK_CONTAINER (vboxall), frame);
  gtk_widget_show (frame);

  vboxframe = create_vbox(frame);
  hbox1 = create_hbox(vboxframe);
  list[0]=g_strdup("");
  nlist=2;
  list[0]=g_strdup("No");
  list[1]=g_strdup("Yes");
  entry[0]= create_combo_box_entry_liste(fp,hbox1,"Compute the vibrational circular dichroism ? : ",list,nlist);
  nlist=2;
  list[0]=g_strdup("No");
  list[1]=g_strdup("Yes");
  hbox1 = create_hbox(vboxframe);
  entry[1]= create_combo_box_entry_liste(fp,hbox1,"Compute Raman intensities ? : ",list,nlist);
  nlist=4;
  list[0]=g_strdup("default");
  list[1]=g_strdup("Analytic");
  list[2]=g_strdup("Numerical");
  list[3]=g_strdup("EnOnly");
  hbox1 = create_hbox(vboxframe);
  entry[2]= create_combo_box_entry_liste(fp,hbox1,"Type of second derivatives  : ",list,nlist);
  nlist=4;
  list[0]=g_strdup("default");
  list[1]=g_strdup("1");
  list[2]=g_strdup("10");
  list[3]=g_strdup("100");
  hbox1 = create_hbox(vboxframe);
  entry[3]= create_combo_box_entry_liste(fp,hbox1,"Step-size for numerical differentiation :",list,nlist);
  
  hbox2 = create_hbox(vboxall);
  gtk_widget_realize(fp);

  button = create_button(fp,"Cancel");
  gtk_box_pack_start (GTK_BOX( hbox2), button, TRUE, TRUE, 3);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(fp));
  gtk_widget_show (button);

  button = create_button(fp,"OK");
  gtk_box_pack_start (GTK_BOX( hbox2), button, TRUE, TRUE, 3);
  gtk_widget_show (button);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(gene_freq),(gpointer)entry);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(fp));

   
  gtk_widget_show_all(fp);
}
/*****************************************************************************************/
static void timeDependent_activate(GtkWidget *button,gpointer data)
{
  	GtkWidget* buttonOptions =(GtkWidget*)data;
	if (GTK_TOGGLE_BUTTON (button)->active) 
	{
  		if(TtimeDependent == NULL ) TtimeDependent=g_malloc(50*sizeof(gchar));
  		sprintf(TtimeDependent," TD");
		if(GTK_IS_WIDGET(buttonOptions)) gtk_widget_set_sensitive(buttonOptions,TRUE);
	}
	else
	{
  		if(TtimeDependent) g_free(TtimeDependent);
  		TtimeDependent = NULL;
		if(GTK_IS_WIDGET(buttonOptions)) gtk_widget_set_sensitive(buttonOptions,FALSE);
	}
}
/*****************************************************************************************/
static void gene_timeDependent(GtkWidget *b,gpointer data)
{
	GtkWidget **entryall;
	GtkWidget *entry;
	G_CONST_RETURN gchar *entrytext;
	guint ipar;
	ipar=0;
	if(TtimeDependent == NULL ) TtimeDependent=g_malloc(50*sizeof(gchar));
	sprintf(TtimeDependent," TD");
	entryall=(GtkWidget **)data;
	entry=entryall[0];
	entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
	if (strcmp(entrytext,"default") )
	{
		ipar=1;
		sprintf(TtimeDependent,"%s(%s",TtimeDependent,entrytext);
	}
	entry=entryall[1];
	entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
	if (strcmp(entrytext,"default") )
	{
		if(ipar) sprintf(TtimeDependent,"%s, NStates=%s",TtimeDependent,entrytext);
		else 
		{
			ipar=1;
			sprintf(TtimeDependent,"%s(NStates=%s",TtimeDependent,entrytext);
		}
	}
	entry=entryall[2];
	entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
	if (strcmp(entrytext,"default") )
	{
		if(ipar) sprintf(TtimeDependent,"%s, Root=%s",TtimeDependent,entrytext);
		else 
		{
			ipar=1;
			sprintf(TtimeDependent,"%s(Root=%s",TtimeDependent,entrytext);
		}
	}
	if(ipar) sprintf(TtimeDependent,"%s) ",TtimeDependent);
}
/*****************************************************************************************/
static void create_timeDependent_option (GtkWidget* Wins)
{
	GtkWidget *fp;
	GtkWidget *frame;
	GtkWidget **entry;
	GtkWidget *vboxall;
	GtkWidget *vboxframe;
	GtkWidget *hbox1;
	GtkWidget *hbox2;
	GtkWidget *button;
	gint nlist = 1;
	gchar *list[4];
	entry=g_malloc(3*sizeof(GtkWidget*));
  
	fp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_modal(GTK_WINDOW(fp),TRUE);
	gtk_window_set_position(GTK_WINDOW(fp),GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(fp),"time-dependent (HF or DFT)");
	gtk_container_set_border_width (GTK_CONTAINER (fp), 5);
	gtk_window_set_transient_for(GTK_WINDOW(fp),GTK_WINDOW(Wins));
	gtk_window_set_modal (GTK_WINDOW (fp), TRUE);

	add_child(Wins,fp,gtk_widget_destroy," timeDependent. ");
	g_signal_connect(G_OBJECT(fp),"delete_event",(GtkSignalFunc)delete_child,NULL);

	vboxall = create_vbox(fp);
	frame = gtk_frame_new (NULL);
	gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
	gtk_container_add (GTK_CONTAINER (vboxall), frame);
	gtk_widget_show (frame);

	vboxframe = create_vbox(frame);
	nlist=3;
	list[0]=g_strdup("Singlets");
	list[1]=g_strdup("Triplets");
	list[2]=g_strdup("50-50");
	hbox1 = create_hbox(vboxframe);
	entry[0] = create_combo_box_entry_liste(fp,hbox1," Type :",list,nlist);

	nlist=4;
	list[0]=g_strdup("default");
	list[1]=g_strdup("3");
	list[2]=g_strdup("6");
	list[3]=g_strdup("12");
	hbox1 = create_hbox(vboxframe);
	entry[1] = create_combo_box_entry_liste(fp,hbox1," NStates  :",list,nlist);

	nlist=4;
	list[0]=g_strdup("default");
	list[1]=g_strdup("1");
	list[2]=g_strdup("2");
	list[3]=g_strdup("3");
	hbox1 = create_hbox(vboxframe);
	entry[2] = create_combo_box_entry_liste(fp,hbox1," Root  :",list,nlist);

	hbox2 = create_hbox(vboxall);
	gtk_widget_realize(fp);

	button = create_button(fp,"Cancel");
	gtk_box_pack_start (GTK_BOX( hbox2), button, TRUE, TRUE, 3);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(fp));
	gtk_widget_show (button);

	button = create_button(fp,"OK");
	gtk_box_pack_start (GTK_BOX( hbox2), button, TRUE, TRUE, 3);
	gtk_widget_show (button);
	g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(gene_timeDependent),(gpointer)entry);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(fp));
   
	gtk_widget_show_all(fp);
}
/*****************************************************************************************/
void traite_button_general (GtkWidget *button, gpointer data)
{
 GtkWidget *Wins = GTK_WIDGET(g_object_get_data (G_OBJECT (button), "Window"));  
 if (!strcmp((char *)data,"Compute frequencies") ) create_freq_option(Wins);
  else
 if (!strcmp((char *)data,"    Controls the SCF procedure" ) ) create_scf_option(Wins);
  else
 if (!strcmp((char *)data,"Compute the dipole polarizabilities" ) ) create_polar_option(Wins);
 else
 if (!strcmp((char *)data,"Time dependent (HF or DFT)" ) ) create_timeDependent_option(Wins);
}
/*****************************************************************************************/
void connect_button(GtkWidget *Wins,GtkWidget *button,gchar *t)
{
  g_object_set_data(G_OBJECT (button), "Window", Wins);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(traite_button_general),(gpointer)t);
}
/*****************************************************************************************/
void create_liste_general(GtkWidget*Wins,GtkWidget*win,GtkWidget *frame)
{
  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *hseparator;
  GtkWidget *checkbutton;
  gchar *t;
  GtkWidget *table;
  gint i;
  gint j;

  vbox =create_vbox(frame);
  hseparator = create_hseparator(vbox);

  table = gtk_table_new(8,2,FALSE);
  gtk_box_pack_start (GTK_BOX (vbox), table, FALSE, FALSE, 0);
  /* polarisability */
  {
  	GtkWidget *buttonCheck;
  	GtkWidget *buttonOption;

	i = 0;
  	t=g_strdup("Compute the dipole polarizabilities");
  	buttonCheck = gtk_check_button_new_with_label (t);
	j = 0;
	gtk_table_attach(GTK_TABLE(table),buttonCheck,j,j+1,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  	gtk_widget_show (buttonCheck);

  	buttonOption = gtk_button_new_with_label ("Options");
	j = 1;
	gtk_table_attach(GTK_TABLE(table),buttonOption,j,j+1,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  	gtk_widget_show (buttonOption);
	if(GTK_IS_WIDGET(buttonOption)) gtk_widget_set_sensitive(buttonOption,FALSE);
  	connect_button(Wins,buttonOption,t);
  	g_signal_connect(G_OBJECT(buttonCheck), "clicked",GTK_SIGNAL_FUNC(polar_activate),(gpointer)buttonOption);
	hseparator = gtk_hseparator_new ();

	i++;
	gtk_table_attach(GTK_TABLE(table),hseparator,0,0+2,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  }
  /* force constantes */
  {
  	GtkWidget *buttonCheck;
  	GtkWidget *buttonOption;

	i++;
  	t=g_strdup("Compute frequencies");
  	buttonCheck = gtk_check_button_new_with_label (t);
	j = 0;
	gtk_table_attach(GTK_TABLE(table),buttonCheck,j,j+1,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  	gtk_widget_show (buttonCheck);

  	buttonOption = gtk_button_new_with_label ("Options");
	j = 1;
	gtk_table_attach(GTK_TABLE(table),buttonOption,j,j+1,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  	gtk_widget_show (buttonOption);
	if(GTK_IS_WIDGET(buttonOption)) gtk_widget_set_sensitive(buttonOption,FALSE);
  	connect_button(Wins,buttonOption,t);
  	g_signal_connect(G_OBJECT(buttonCheck), "clicked",GTK_SIGNAL_FUNC(freq_activate),(gpointer)buttonOption);
	hseparator = gtk_hseparator_new ();

	i++;
	gtk_table_attach(GTK_TABLE(table),hseparator,0,0+2,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  }
  /* Time dependent (HF or DFT) */
  {
  	GtkWidget *buttonCheck;
  	GtkWidget *buttonOption;

	i++;
  	t=g_strdup("Time dependent (HF or DFT)");
  	buttonCheck = gtk_check_button_new_with_label (t);
	j = 0;
	gtk_table_attach(GTK_TABLE(table),buttonCheck,j,j+1,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  	gtk_widget_show (buttonCheck);

  	buttonOption = gtk_button_new_with_label ("Options");
	j = 1;
	gtk_table_attach(GTK_TABLE(table),buttonOption,j,j+1,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  	gtk_widget_show (buttonOption);
	if(GTK_IS_WIDGET(buttonOption)) gtk_widget_set_sensitive(buttonOption,FALSE);
  	connect_button(Wins,buttonOption,t);
  	g_signal_connect(G_OBJECT(buttonCheck), "clicked",GTK_SIGNAL_FUNC(timeDependent_activate),(gpointer)buttonOption);
	hseparator = gtk_hseparator_new ();

	i++;
	gtk_table_attach(GTK_TABLE(table),hseparator,0,0+2,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  }

  /* scf procedure */
  {
  	GtkWidget *label;
  	GtkWidget *buttonOption;
	GtkWidget *hbox = gtk_hbox_new(0,FALSE);
	

	i++;
  	t=g_strdup("    Controls the SCF procedure");
  	label = gtk_label_new (t);
	gtk_label_set_justify(GTK_LABEL(label),GTK_JUSTIFY_LEFT);
	gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 0);
  	gtk_widget_show (label);
  	gtk_widget_show (hbox);
	j = 0;
	gtk_table_attach(GTK_TABLE(table),hbox,j,j+1,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_SHRINK) , (GtkAttachOptions)(GTK_FILL | GTK_SHRINK), 1,1);

  	buttonOption = gtk_button_new_with_label ("Go");
	j = 1;
	gtk_table_attach(GTK_TABLE(table),buttonOption,j,j+1,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  	gtk_widget_show (buttonOption);
	if(GTK_IS_WIDGET(buttonOption)) gtk_widget_set_sensitive(buttonOption,TRUE);
  	connect_button(Wins,buttonOption,t);
	hseparator = gtk_hseparator_new ();

	i++;
	gtk_table_attach(GTK_TABLE(table),hseparator,0,0+2,i,i+1, (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) , (GtkAttachOptions)(GTK_FILL | GTK_EXPAND), 1,1);
  }

  hbox =create_hbox(vbox);
  checkbutton = gtk_check_button_new_with_label ("Extra print keys for gabedit");
  CheckButtons[0]=checkbutton;
  gtk_widget_ref (checkbutton);
  g_object_set_data_full (G_OBJECT (win), "checkbutton", checkbutton,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (checkbutton), TRUE);
  gtk_widget_show (checkbutton);
  gtk_box_pack_start (GTK_BOX (hbox), checkbutton, TRUE, TRUE, 0);

  checkbutton = gtk_check_button_new_with_label ("Full population analysis");
  CheckButtons[1]=checkbutton;
  gtk_widget_ref (checkbutton);
  g_object_set_data_full (G_OBJECT (win), "checkbutton", checkbutton,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (checkbutton), TRUE);
  gtk_widget_show (checkbutton);
  gtk_box_pack_start (GTK_BOX (hbox), checkbutton, TRUE, TRUE, 0);

  hbox =create_hbox(vbox);
  checkbutton = gtk_check_button_new_with_label ("Archive");
  CheckButtons[2]=checkbutton;
  gtk_widget_ref (checkbutton);
  g_object_set_data_full (G_OBJECT (win), "checkbutton", checkbutton,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (checkbutton);
  gtk_box_pack_start (GTK_BOX (hbox), checkbutton, TRUE, TRUE, 0);

  checkbutton = gtk_check_button_new_with_label ("Ignore Symmetry");
  CheckButtons[3]=checkbutton;
  gtk_widget_ref (checkbutton);
  g_object_set_data_full (G_OBJECT (win), "checkbutton", checkbutton,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (checkbutton);
  gtk_box_pack_start (GTK_BOX (hbox), checkbutton, TRUE, TRUE, 0);

  hbox =create_hbox(vbox);
  checkbutton = gtk_check_button_new_with_label ("Addtional print");
  CheckButtons[4]=checkbutton;
  gtk_widget_ref (checkbutton);
  g_object_set_data_full (G_OBJECT (win), "checkbutton", checkbutton,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (checkbutton), TRUE);
  gtk_widget_show (checkbutton);
  gtk_box_pack_start (GTK_BOX (hbox), checkbutton, TRUE, TRUE, 0);

  checkbutton = gtk_check_button_new_with_label ("Density");
  CheckButtons[5]=checkbutton;
  gtk_widget_ref (checkbutton);
  g_object_set_data_full (G_OBJECT (win), "checkbutton", checkbutton,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (checkbutton), TRUE);
  gtk_widget_show (checkbutton);
  gtk_box_pack_start (GTK_BOX (hbox), checkbutton, TRUE, TRUE, 0);

  checkbutton = gtk_check_button_new_with_label ("Mix HOMO & LUMO in initial guess");
  CheckButtons[6]=checkbutton;
  gtk_widget_ref (checkbutton);
  g_object_set_data_full (G_OBJECT (win), "checkbutton", checkbutton,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (checkbutton);
  gtk_box_pack_start (GTK_BOX (vbox), checkbutton, FALSE, FALSE, 0);

  checkbutton = gtk_check_button_new_with_label ("Read initial Guess from checkpoint");
  CheckButtons[7]=checkbutton;
  gtk_widget_ref (checkbutton);
  g_object_set_data_full (G_OBJECT (win), "checkbutton", checkbutton,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (checkbutton);
  gtk_box_pack_start (GTK_BOX (vbox), checkbutton, FALSE, FALSE, 0);

  checkbutton = gtk_check_button_new_with_label ("Read geometry from checkpoint");
  CheckButtons[8]=checkbutton;
  gtk_widget_ref (checkbutton);
  g_object_set_data_full (G_OBJECT (win), "checkbutton", checkbutton,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (checkbutton);
  gtk_box_pack_start (GTK_BOX (vbox), checkbutton, FALSE, FALSE, 0);

  hseparator = create_hseparator(vbox);

}
/*****************************************************************************************/
void  c_opt_combo()
{
  gchar *liste[9];
  int nliste = 0;
  nliste=3;
  liste[0]=g_strdup("Redundant");
  liste[1]=g_strdup("Z-matrix");
  liste[2]=g_strdup("Cartesian");
  HboxT[0] = create_hbox(VboxT);
  EntryTypes[0]= create_combo_box_entry_liste(FrameT,HboxT[0]," Coordinate system options :",liste,nliste);
  nliste=4;
  liste[0]=g_strdup("default");
  liste[1]=g_strdup("Tight");
  liste[2]=g_strdup("VeryTight");
  liste[3]=g_strdup("Loose");
  HboxT[1] = create_hbox(VboxT);
  EntryTypes[1]= create_combo_box_entry_liste(FrameT,HboxT[1],"  Convergence criteries :",liste,nliste);
  nliste=4;
  liste[0]=g_strdup("20");
  liste[1]=g_strdup("10");
  liste[2]=g_strdup("30");
  liste[3]=g_strdup("40");
  HboxT[2] = create_hbox(VboxT);
  EntryTypes[2]= create_combo_box_entry_liste(FrameT,HboxT[2]," MaxCycle  :",liste,nliste);
  nliste=4;
  liste[0]=g_strdup("default");
  liste[1]=g_strdup("20");
  liste[2]=g_strdup("30");
  liste[3]=g_strdup("40");
  HboxT[3] = create_hbox(VboxT);
  EntryTypes[3]= create_combo_box_entry_liste(FrameT,HboxT[3]," StepSize  :",liste,nliste);
  nliste=4;
  liste[0]=g_strdup("No");
  liste[1]=g_strdup("1");
  liste[2]=g_strdup("2");
  liste[3]=g_strdup("3");
  HboxT[4] = create_hbox(VboxT);
  EntryTypes[4]= create_combo_box_entry_liste(FrameT,HboxT[4],"  Saddle point of order :",liste,nliste);
  nliste=2;
  liste[0]=g_strdup("No");
  liste[1]=g_strdup("Yes");
  HboxT[5] = create_hbox(VboxT);
  EntryTypes[5]= create_combo_box_entry_liste(FrameT,HboxT[5]," optimization  a transition  :",liste,nliste);
}
/********************************************************************************************************/
static void traite_types (GtkComboBox *combobox, gpointer d)
{
	guint i;
	GtkTreeIter iter;
	gchar* data = NULL;
	if (gtk_combo_box_get_active_iter (combobox, &iter))
	{
		GtkTreeModel* model = gtk_combo_box_get_model(combobox);
		gtk_tree_model_get (model, &iter, 0, &data, -1);
	}
	if(Types) g_free(Types);
	Types = NULL;
	if (data) Types = g_strdup(data);

	for (i=0;i<nHboxT;i++)
	{
		if(HboxT[i]!=NULL)
		{
			gtk_widget_destroy(HboxT[i]);
			HboxT[i] = NULL;
		}
	}
	if (!strcmp((char *)data,"Geometry Optimization") ) c_opt_combo();
	gtk_widget_show_all(FrameT);
}
/********************************************************************************************************/
static GtkWidget *create_liste_types(GtkWidget*win,GtkWidget *frame)
{
	GtkWidget *hbox;
	GtkWidget *vbox;
	GtkWidget *hseparator;
        GtkTreeIter iter;
        GtkTreeStore *store;
	GtkTreeModel *model;
	GtkWidget *combobox;
	GtkCellRenderer *renderer;

	vbox =create_vbox(frame);
  	VboxT=vbox;
	hbox =create_hbox(vbox);

	store = gtk_tree_store_new (1,G_TYPE_STRING);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Single Point", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Geometry Optimization", -1);

        model = GTK_TREE_MODEL (store);
	combobox = gtk_combo_box_new_with_model (model);
	g_object_unref (model);
	gtk_box_pack_start (GTK_BOX (hbox), combobox, TRUE, TRUE, 1);
	g_signal_connect (G_OBJECT(combobox), "changed", G_CALLBACK(traite_types), NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (combobox), renderer, TRUE);
	gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (combobox), renderer, "text", 0, NULL);

	hseparator = gtk_hseparator_new ();
	gtk_widget_show (hseparator);
	gtk_box_pack_start (GTK_BOX (vbox), hseparator, FALSE, FALSE, 1);
	gtk_combo_box_set_active (GTK_COMBO_BOX (combobox), 0);
	return combobox;
}
/*****************************************************************************************/
GtkWidget *create_add_keyword (GtkWidget* win,GtkWidget *vbox,gchar *tlabel)
{
  GtkWidget *label;
  GtkWidget *entry;
  GtkWidget *hbox;

  hbox = gtk_hbox_new (FALSE, 0);
  gtk_widget_ref (hbox);
  gtk_widget_show (hbox);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);

  label = gtk_label_new (tlabel);
  gtk_widget_ref (label);
  g_object_set_data_full (G_OBJECT (win), "label", label,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (label);
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, FALSE, 0);

  entry = gtk_entry_new ();
  gtk_widget_ref (entry);
  g_object_set_data_full (G_OBJECT (win), "entry", entry,
                            (GtkDestroyNotify) gtk_widget_unref);
  gtk_widget_show (entry);
  gtk_box_pack_start (GTK_BOX (hbox), entry, TRUE, TRUE, 0);
  
  return entry;
}
/*****************************************************************************************/
void GAjoutePageRoute(GtkWidget *NoteBook,GtkWidget *Wins)
{
  GtkWidget *Frame;
  GtkWidget *LabelOnglet;
  GtkWidget *LabelMenu;
  GtkWidget *window1;
  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *FrameLink;
  GtkWidget *FrameTitle;
  GtkWidget *FrameType;
  GtkWidget *FrameGeneral;
  GtkWidget *FrameMethodeBase;
  guint i;
  
  Tfreq=NULL;
  Tscf=NULL;
  Tpolar=NULL;
  TtimeDependent=NULL;
  Types=NULL;
  nHboxT=NHBOXT_MAX;

  for(i=0;i<nHboxT;i++)
  	HboxT[i]=NULL;
  
  Frame = gtk_frame_new(NULL);
  gtk_container_set_border_width(GTK_CONTAINER(Frame), 10);
  
  LabelOnglet = gtk_label_new("Calculation commands");
  LabelMenu = gtk_label_new("Calculation commands");
  gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
                                Frame,
                                LabelOnglet, LabelMenu);

  window1 = Frame;
  g_object_set_data(G_OBJECT (window1), "window1", window1);
  
  vbox =create_vbox(window1);
 
  hbox =create_hbox(vbox);

  FrameLink = create_frame(window1,hbox,"LINK OPTIONS");
  create_button_link(FrameLink,Wins);

  FrameTitle = create_frame(window1,hbox,"Title");
  TextTitle = create_text(window1,FrameTitle,TRUE);
  gabedit_text_insert (GABEDIT_TEXT (TextTitle), NULL, NULL, NULL, "Input file generated by gabedit...", -1);

  hbox =create_hbox(vbox);

  FrameMethodeBase = create_frame(window1,hbox,"METHOD");
  create_notebook_MB( FrameMethodeBase);

  hbox =create_hbox(vbox);

  FrameType = create_frame(window1,hbox,"TYPE");
  FrameT=FrameType;
  create_liste_types(window1,FrameType);
  FrameGeneral = create_frame(window1,hbox,"GENERAL");
  create_liste_general(Wins,window1,FrameGeneral);
  gtk_widget_show_all(Frame);
  gtk_widget_hide (CheckButtons[8]);
}

