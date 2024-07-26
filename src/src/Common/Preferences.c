/* Preferences.c */
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
#include "Global.h"
#include "../Common/Help.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/Utils.h"
#include "Windows.h"
#include "TextEdit.h"
#include "../Utils/Vector3d.h"
#include "../OpenGL/PreferencesOrb.h"
#include "../OpenGL/GLArea.h"
#include "../Geometry/ResultsAnalise.h"
#include "../Geometry/GeomGlobal.h"
#include "../Files/FolderChooser.h"
#include "../Files/GabeditFolderChooser.h"
void rafresh_drawing();
void set_color_surface(gint num,gdouble v[]);
#include "../../pixmaps/Open.xpm"
static GtkWidget* entrybabel = NULL;

GtkWidget *NoteBook;
static GtkWidget *Wins = NULL;
static GtkWidget *EntryGamess = NULL;
static GtkWidget *EntryGaussian = NULL;
static GtkWidget *EntryMolcas = NULL;
static GtkWidget *EntryMolpro = NULL;
static GtkWidget *EntryMPQC = NULL;
static GtkWidget *EntryPCGamess = NULL;
static GtkWidget *EntryQChem = NULL;

static GtkWidget *ComboGamess = NULL;
static GtkWidget *ComboGaussian = NULL;
static GtkWidget *ComboMolcas = NULL;
static GtkWidget *ComboMolpro = NULL;
static GtkWidget *ComboMPQC = NULL;
static GtkWidget *ComboPCGamess = NULL;
static GtkWidget *ComboQChem = NULL;

static GtkWidget *ButtonGamess = NULL;
static GtkWidget *ButtonGaussian = NULL;
static GtkWidget *ButtonMolcas = NULL;
static GtkWidget *ButtonMolpro = NULL;
static GtkWidget *ButtonMPQC = NULL;
static GtkWidget *ButtonPCGamess = NULL;
static GtkWidget *ButtonQChem = NULL;

static GtkWidget *EntryBatchType = NULL;
GtkWidget *selectors[3];
GdkColor ColorTemp;
gchar *FontTemp;
static gboolean instal = FALSE;


/********************************************************************************/
void destroy_preferences_window(GtkWidget*Win)
{
  destroy_childs(Wins);
  Wins = NULL;
}
/********************************************************************************/
void  modify_color_surfaces()
{
	gdouble Col[4];
	GdkColor color;

	/* positive value */
	gtk_color_button_get_color ((GtkColorButton*)selectors[0], &color);
	Col[0] = color.red/65535.0;
	Col[1] = color.green/65535.0;
	Col[2] = color.blue/65535.0;
	set_color_surface(0,Col);

	/* negative value */
	gtk_color_button_get_color ((GtkColorButton*)selectors[1], &color);
	Col[0] = color.red/65535.0;
	Col[1] = color.green/65535.0;
	Col[2] = color.blue/65535.0;
	set_color_surface(1,Col);
	/* density surface */
	gtk_color_button_get_color ((GtkColorButton*)selectors[2], &color);
	Col[0] = color.red/65535.0;
	Col[1] = color.green/65535.0;
	Col[2] = color.blue/65535.0;
	set_color_surface(2,Col);
	rafresh_window_orb();
}
/********************************************************************************/
void  create_color_surfaces(GtkWidget *Wins,GtkWidget *Frame)
{
  GtkWidget *vbox;

  vbox = create_vbox(Frame);

  create_colorsel_frame(vbox,NULL,selectors);
}
/********************************************************************************/
static void  remove_gamess_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;
  gint inList = -1;

  if(gamessCommands.numberOfCommands<2)
	  return;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryGamess));

  for(i=0;i<gamessCommands.numberOfCommands;i++)
  {
	  if(strcmp(strcom,gamessCommands.commands[i])==0)
	  {
		  inList = i;
		  break;
	  }
  }
  if(inList == -1)
	  return;
  for(i=inList;i<gamessCommands.numberOfCommands-1;i++)
	  gamessCommands.commands[i] = gamessCommands.commands[i+1];

  gamessCommands.numberOfCommands--;
  gamessCommands.commands = g_realloc(
		   gamessCommands.commands,
		   gamessCommands.numberOfCommands*sizeof(gchar*));

  for(i=0;i<gamessCommands.numberOfCommands;i++)
	glist = g_list_append(glist,gamessCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboGamess, glist) ;

  g_list_free(glist);

  if(gamessCommands.numberOfCommands<2) gtk_widget_set_sensitive(ButtonGamess, FALSE);
  else gtk_widget_set_sensitive(ButtonGamess, TRUE);

  NameCommandGamess = g_strdup(gamessCommands.commands[0]);

  str_delete_n(NameCommandGamess);
  delete_last_spaces(NameCommandGamess);
  delete_first_spaces(NameCommandGamess);
}
/********************************************************************************/
void  modify_gamess_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryGamess));
  if(strcmp(strcom,""))
      NameCommandGamess = g_strdup(strcom);

  str_delete_n(NameCommandGamess);
  delete_last_spaces(NameCommandGamess);
  delete_first_spaces(NameCommandGamess);

  for(i=0;i<gamessCommands.numberOfCommands;i++)
  {
	  if(strcmp(NameCommandGamess,gamessCommands.commands[i])==0)
		  return;
  }
  gamessCommands.numberOfCommands++;
  gamessCommands.commands = g_realloc(
		   gamessCommands.commands,
		   gamessCommands.numberOfCommands*sizeof(gchar*));
  gamessCommands.commands[gamessCommands.numberOfCommands-1] = g_strdup(NameCommandGamess);

  for(i=gamessCommands.numberOfCommands-1;i>=0;i--)
	glist = g_list_append(glist,gamessCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboGamess, glist) ;

  g_list_free(glist);
  if(gamessCommands.numberOfCommands<2) gtk_widget_set_sensitive(ButtonGamess, FALSE);
  else gtk_widget_set_sensitive(ButtonGamess, TRUE);
}
/********************************************************************************/
static void  remove_gaussian_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;
  gint inList = -1;

  if(gaussianCommands.numberOfCommands<2)
	  return;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryGaussian));

  for(i=0;i<gaussianCommands.numberOfCommands;i++)
  {
	  if(strcmp(strcom,gaussianCommands.commands[i])==0)
	  {
		  inList = i;
		  break;
	  }
  }
  if(inList == -1)
	  return;
  for(i=inList;i<gaussianCommands.numberOfCommands-1;i++)
	  gaussianCommands.commands[i] = gaussianCommands.commands[i+1];

  gaussianCommands.numberOfCommands--;
  gaussianCommands.commands = g_realloc(
		   gaussianCommands.commands,
		   gaussianCommands.numberOfCommands*sizeof(gchar*));

  for(i=0;i<gaussianCommands.numberOfCommands;i++)
	glist = g_list_append(glist,gaussianCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboGaussian, glist) ;

  g_list_free(glist);

  if(gaussianCommands.numberOfCommands<2) gtk_widget_set_sensitive(ButtonGaussian, FALSE);
  else gtk_widget_set_sensitive(ButtonGaussian, TRUE);

  NameCommandGaussian = g_strdup(gaussianCommands.commands[0]);

  str_delete_n(NameCommandGaussian);
  delete_last_spaces(NameCommandGaussian);
  delete_first_spaces(NameCommandGaussian);
}
/********************************************************************************/
void  modify_gaussian_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryGaussian));
  if(strcmp(strcom,""))
      NameCommandGaussian = g_strdup(strcom);

  str_delete_n(NameCommandGaussian);
  delete_last_spaces(NameCommandGaussian);
  delete_first_spaces(NameCommandGaussian);

  for(i=0;i<gaussianCommands.numberOfCommands;i++)
  {
	  if(strcmp(NameCommandGaussian,gaussianCommands.commands[i])==0)
		  return;
  }
  gaussianCommands.numberOfCommands++;
  gaussianCommands.commands = g_realloc(
		   gaussianCommands.commands,
		   gaussianCommands.numberOfCommands*sizeof(gchar*));
  gaussianCommands.commands[gaussianCommands.numberOfCommands-1] = g_strdup(NameCommandGaussian);

  for(i=gaussianCommands.numberOfCommands-1;i>=0;i--)
	glist = g_list_append(glist,gaussianCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboGaussian, glist) ;

  g_list_free(glist);
  if(gaussianCommands.numberOfCommands<2) gtk_widget_set_sensitive(ButtonGaussian, FALSE);
  else gtk_widget_set_sensitive(ButtonGaussian, TRUE);
}
/********************************************************************************/
static void  remove_molcas_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;
  gint inList = -1;

  if(molcasCommands.numberOfCommands<2)
	  return;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryMolcas));

  for(i=0;i<molcasCommands.numberOfCommands;i++)
  {
	  if(strcmp(strcom,molcasCommands.commands[i])==0)
	  {
		  inList = i;
		  break;
	  }
  }
  if(inList == -1)
	  return;
  for(i=inList;i<molcasCommands.numberOfCommands-1;i++)
	  molcasCommands.commands[i] = molcasCommands.commands[i+1];

  molcasCommands.numberOfCommands--;
  molcasCommands.commands = g_realloc(
		   molcasCommands.commands,
		   molcasCommands.numberOfCommands*sizeof(gchar*));

  for(i=0;i<molcasCommands.numberOfCommands;i++)
	glist = g_list_append(glist,molcasCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboMolcas, glist) ;

  g_list_free(glist);

  if(molcasCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(ButtonMolcas, FALSE);
  else
  	gtk_widget_set_sensitive(ButtonMolcas, TRUE);

  NameCommandMolcas = g_strdup(molcasCommands.commands[0]);

  str_delete_n(NameCommandMolcas);
  delete_last_spaces(NameCommandMolcas);
  delete_first_spaces(NameCommandMolcas);
}
/********************************************************************************/
void  modify_molcas_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryMolcas));
  if(strcmp(strcom,""))
      NameCommandMolcas = g_strdup(strcom);

  str_delete_n(NameCommandMolcas);
  delete_last_spaces(NameCommandMolcas);
  delete_first_spaces(NameCommandMolcas);

  for(i=0;i<molcasCommands.numberOfCommands;i++)
  {
	  if(strcmp(NameCommandMolcas,molcasCommands.commands[i])==0)
		  return;
  }
  molcasCommands.numberOfCommands++;
  molcasCommands.commands = g_realloc(
		   molcasCommands.commands,
		   molcasCommands.numberOfCommands*sizeof(gchar*));
  molcasCommands.commands[molcasCommands.numberOfCommands-1] = g_strdup(NameCommandMolcas);

  for(i=molcasCommands.numberOfCommands-1;i>=0;i--)
	glist = g_list_append(glist,molcasCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboMolcas, glist) ;

  g_list_free(glist);
  if(molcasCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(ButtonMolcas, FALSE);
  else
  	gtk_widget_set_sensitive(ButtonMolcas, TRUE);
}
/********************************************************************************/
static void  remove_mpqc_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;
  gint inList = -1;

  if(mpqcCommands.numberOfCommands<2)
	  return;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryMPQC));

  for(i=0;i<mpqcCommands.numberOfCommands;i++)
  {
	  if(strcmp(strcom,mpqcCommands.commands[i])==0)
	  {
		  inList = i;
		  break;
	  }
  }
  if(inList == -1)
	  return;
  for(i=inList;i<mpqcCommands.numberOfCommands-1;i++)
	  mpqcCommands.commands[i] = mpqcCommands.commands[i+1];

  mpqcCommands.numberOfCommands--;
  mpqcCommands.commands = g_realloc(
		   mpqcCommands.commands,
		   mpqcCommands.numberOfCommands*sizeof(gchar*));

  for(i=0;i<mpqcCommands.numberOfCommands;i++)
	glist = g_list_append(glist,mpqcCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboMPQC, glist) ;

  g_list_free(glist);

  if(mpqcCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(ButtonMPQC, FALSE);
  else
  	gtk_widget_set_sensitive(ButtonMPQC, TRUE);

  NameCommandMPQC = g_strdup(mpqcCommands.commands[0]);

  str_delete_n(NameCommandMPQC);
  delete_last_spaces(NameCommandMPQC);
  delete_first_spaces(NameCommandMPQC);
}
/********************************************************************************/
void  modify_mpqc_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryMPQC));
  if(strcmp(strcom,""))
      NameCommandMPQC = g_strdup(strcom);

  str_delete_n(NameCommandMPQC);
  delete_last_spaces(NameCommandMPQC);
  delete_first_spaces(NameCommandMPQC);

  for(i=0;i<mpqcCommands.numberOfCommands;i++)
  {
	  if(strcmp(NameCommandMPQC,mpqcCommands.commands[i])==0)
		  return;
  }
  mpqcCommands.numberOfCommands++;
  mpqcCommands.commands = g_realloc(
		   mpqcCommands.commands,
		   mpqcCommands.numberOfCommands*sizeof(gchar*));
  mpqcCommands.commands[mpqcCommands.numberOfCommands-1] = g_strdup(NameCommandMPQC);

  for(i=mpqcCommands.numberOfCommands-1;i>=0;i--)
	glist = g_list_append(glist,mpqcCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboMPQC, glist) ;

  g_list_free(glist);
  if(mpqcCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(ButtonMPQC, FALSE);
  else
  	gtk_widget_set_sensitive(ButtonMPQC, TRUE);
}
/********************************************************************************/
static void  remove_molpro_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;
  gint inList = -1;

  if(molproCommands.numberOfCommands<2)
	  return;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryMolpro));

  for(i=0;i<molproCommands.numberOfCommands;i++)
  {
	  if(strcmp(strcom,molproCommands.commands[i])==0)
	  {
		  inList = i;
		  break;
	  }
  }
  if(inList == -1)
	  return;
  for(i=inList;i<molproCommands.numberOfCommands-1;i++)
	  molproCommands.commands[i] = molproCommands.commands[i+1];

  molproCommands.numberOfCommands--;
  molproCommands.commands = g_realloc(
		   molproCommands.commands,
		   molproCommands.numberOfCommands*sizeof(gchar*));

  for(i=0;i<molproCommands.numberOfCommands;i++)
	glist = g_list_append(glist,molproCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboMolpro, glist) ;

  g_list_free(glist);

  if(molproCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(ButtonMolpro, FALSE);
  else
  	gtk_widget_set_sensitive(ButtonMolpro, TRUE);

  NameCommandMolpro = g_strdup(molproCommands.commands[0]);

  str_delete_n(NameCommandMolpro);
  delete_last_spaces(NameCommandMolpro);
  delete_first_spaces(NameCommandMolpro);
}
/********************************************************************************/
void  modify_molpro_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryMolpro));
  if(strcmp(strcom,""))
      NameCommandMolpro = g_strdup(strcom);

  str_delete_n(NameCommandMolpro);
  delete_last_spaces(NameCommandMolpro);
  delete_first_spaces(NameCommandMolpro);

  for(i=0;i<molproCommands.numberOfCommands;i++)
  {
	  if(strcmp(NameCommandMolpro,molproCommands.commands[i])==0)
		  return;
  }
  molproCommands.numberOfCommands++;
  molproCommands.commands = g_realloc(
		   molproCommands.commands,
		   molproCommands.numberOfCommands*sizeof(gchar*));
  molproCommands.commands[molproCommands.numberOfCommands-1] = g_strdup(NameCommandMolpro);

  for(i=molproCommands.numberOfCommands-1;i>=0;i--)
	glist = g_list_append(glist,molproCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboMolpro, glist) ;

  g_list_free(glist);
  if(molproCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(ButtonMolpro, FALSE);
  else
  	gtk_widget_set_sensitive(ButtonMolpro, TRUE);
}
/********************************************************************************/
static void  remove_pcgamess_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;
  gint inList = -1;

  if(pcgamessCommands.numberOfCommands<2)
	  return;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryPCGamess));

  for(i=0;i<pcgamessCommands.numberOfCommands;i++)
  {
	  if(strcmp(strcom,pcgamessCommands.commands[i])==0)
	  {
		  inList = i;
		  break;
	  }
  }
  if(inList == -1)
	  return;
  for(i=inList;i<pcgamessCommands.numberOfCommands-1;i++)
	  pcgamessCommands.commands[i] = pcgamessCommands.commands[i+1];

  pcgamessCommands.numberOfCommands--;
  pcgamessCommands.commands = g_realloc(
		   pcgamessCommands.commands,
		   pcgamessCommands.numberOfCommands*sizeof(gchar*));

  for(i=0;i<pcgamessCommands.numberOfCommands;i++)
	glist = g_list_append(glist,pcgamessCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboPCGamess, glist) ;

  g_list_free(glist);

  if(pcgamessCommands.numberOfCommands<2) gtk_widget_set_sensitive(ButtonPCGamess, FALSE);
  else gtk_widget_set_sensitive(ButtonPCGamess, TRUE);

  NameCommandPCGamess = g_strdup(pcgamessCommands.commands[0]);

  str_delete_n(NameCommandPCGamess);
  delete_last_spaces(NameCommandPCGamess);
  delete_first_spaces(NameCommandPCGamess);
}
/********************************************************************************/
void  modify_pcgamess_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryPCGamess));
  if(strcmp(strcom,""))
      NameCommandPCGamess = g_strdup(strcom);

  str_delete_n(NameCommandPCGamess);
  delete_last_spaces(NameCommandPCGamess);
  delete_first_spaces(NameCommandPCGamess);

  for(i=0;i<pcgamessCommands.numberOfCommands;i++)
  {
	  if(strcmp(NameCommandPCGamess,pcgamessCommands.commands[i])==0)
		  return;
  }
  pcgamessCommands.numberOfCommands++;
  pcgamessCommands.commands = g_realloc(
		   pcgamessCommands.commands,
		   pcgamessCommands.numberOfCommands*sizeof(gchar*));
  pcgamessCommands.commands[pcgamessCommands.numberOfCommands-1] = g_strdup(NameCommandPCGamess);

  for(i=pcgamessCommands.numberOfCommands-1;i>=0;i--)
	glist = g_list_append(glist,pcgamessCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboPCGamess, glist) ;

  g_list_free(glist);
  if(pcgamessCommands.numberOfCommands<2) gtk_widget_set_sensitive(ButtonPCGamess, FALSE);
  else gtk_widget_set_sensitive(ButtonPCGamess, TRUE);
}
/********************************************************************************/
static void  remove_qchem_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;
  gint inList = -1;

  if(qchemCommands.numberOfCommands<2)
	  return;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryQChem));

  for(i=0;i<qchemCommands.numberOfCommands;i++)
  {
	  if(strcmp(strcom,qchemCommands.commands[i])==0)
	  {
		  inList = i;
		  break;
	  }
  }
  if(inList == -1)
	  return;
  for(i=inList;i<qchemCommands.numberOfCommands-1;i++)
	  qchemCommands.commands[i] = qchemCommands.commands[i+1];

  qchemCommands.numberOfCommands--;
  qchemCommands.commands = g_realloc(
		   qchemCommands.commands,
		   qchemCommands.numberOfCommands*sizeof(gchar*));

  for(i=0;i<qchemCommands.numberOfCommands;i++)
	glist = g_list_append(glist,qchemCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboQChem, glist) ;

  g_list_free(glist);

  if(qchemCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(ButtonQChem, FALSE);
  else
  	gtk_widget_set_sensitive(ButtonQChem, TRUE);

  NameCommandQChem = g_strdup(qchemCommands.commands[0]);

  str_delete_n(NameCommandQChem);
  delete_last_spaces(NameCommandQChem);
  delete_first_spaces(NameCommandQChem);
}
/********************************************************************************/
void  modify_qchem_command()
{
  G_CONST_RETURN gchar *strcom;
  GList *glist = NULL;
  gint i;

  strcom = gtk_entry_get_text (GTK_ENTRY (EntryQChem));
  if(strcmp(strcom,""))
      NameCommandQChem = g_strdup(strcom);

  str_delete_n(NameCommandQChem);
  delete_last_spaces(NameCommandQChem);
  delete_first_spaces(NameCommandQChem);

  for(i=0;i<qchemCommands.numberOfCommands;i++)
  {
	  if(strcmp(NameCommandQChem,qchemCommands.commands[i])==0)
		  return;
  }
  qchemCommands.numberOfCommands++;
  qchemCommands.commands = g_realloc(
		   qchemCommands.commands,
		   qchemCommands.numberOfCommands*sizeof(gchar*));
  qchemCommands.commands[qchemCommands.numberOfCommands-1] = g_strdup(NameCommandQChem);

  for(i=qchemCommands.numberOfCommands-1;i>=0;i--)
	glist = g_list_append(glist,qchemCommands.commands[i]);

  gtk_combo_box_entry_set_popdown_strings( ComboQChem, glist) ;

  g_list_free(glist);
  if(qchemCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(ButtonQChem, FALSE);
  else
  	gtk_widget_set_sensitive(ButtonQChem, TRUE);
}
/********************************************************************************/
void apply_all()
{
  modify_gaussian_command();
  modify_molpro_command();
  modify_color_surfaces();
}
/********************************************************************************/
void set_temp_font(GtkFontSelectionDialog *Sel,gpointer *d)
{
        FontTemp =  gtk_font_selection_dialog_get_font_name(Sel);
}
/********************************************************************************/
void set_font_other (gchar *fontname)
{
        GtkStyle *style;
	PangoFontDescription *font_desc = NULL;
 
        style = gtk_widget_get_default_style ();
  	font_desc = pango_font_description_from_string (fontname);
 
	if (font_desc)
        {
    		style->font_desc = font_desc;
		/*
		gtk_widget_set_default_style(style);
		*/
        }
	else
	{
		gchar* temp= NULL;
                temp = g_strdup_printf("Unknown font,\n%s\nPlease select a other\n",fontname);
		Message(temp,"ERROR",TRUE);
		g_free(temp);
	}
 
}
/********************************************************************************/
static void set_button_font(GtkWidget *button,gpointer *data)
{
  GtkWidget *hbox;
  GtkWidget *label;
  gchar *Type = g_object_get_data(G_OBJECT (button), "Type");

  gtk_widget_hide (GTK_WIDGET(button));
  hbox = g_object_get_data(G_OBJECT (button), "Hbox");  
  gtk_widget_destroy(GTK_WIDGET(hbox));

  hbox = gtk_hbox_new (TRUE, 0);
  label = gtk_label_new(FontTemp); 
  gtk_container_add(GTK_CONTAINER(hbox),label);

  gtk_container_add(GTK_CONTAINER(button),hbox);
  g_object_set_data(G_OBJECT (button), "Hbox", hbox);
  gtk_widget_show_all (GTK_WIDGET(button));

  if(strstr(Type,"Data"))
  {
	set_font (text, FontTemp);
        if( FontsStyleData.fontname )
            g_free(FontsStyleData.fontname);
        FontsStyleData.fontname = g_strdup(FontTemp);
  }
  else 
  if(strstr(Type,"Result"))
  {
	set_font (textresult, FontTemp);
	set_font (TextOutput, FontTemp);
	set_font (TextError, FontTemp);
       	if( FontsStyleResult.fontname )
       		g_free(FontsStyleResult.fontname);
       	FontsStyleResult.fontname = g_strdup(FontTemp);
  }
  else 
  if(strstr(Type,"Label"))
  {
       	if( FontsStyleLabel.fontname )
       		g_free(FontsStyleLabel.fontname);
       	FontsStyleLabel.fontname = g_strdup(FontTemp);
 	if(ZoneDessin)
  		rafresh_drawing();
  }
  else
  {
	set_font_other (FontTemp);
       	if( FontsStyleOther.fontname )
       		g_free(FontsStyleOther.fontname);
       	FontsStyleOther.fontname = g_strdup(FontTemp);
  }

}
/********************************************************************************/
static void open_font_dlg(GtkWidget *button,gpointer tdata)
{

	GtkFontSelectionDialog *FontDlg;
	FontDlg = (GtkFontSelectionDialog *)gtk_font_selection_dialog_new("Font selection");
        gtk_window_set_position(GTK_WINDOW(FontDlg),GTK_WIN_POS_CENTER);

	if(!instal)
	{
		add_child(Wins, GTK_WIDGET(FontDlg), gtk_widget_destroy, " Font selction ");
		g_signal_connect(G_OBJECT(FontDlg),"delete_event",(GtkSignalFunc)delete_child,NULL);
	}
	else
	{
		gtk_window_set_modal (GTK_WINDOW (FontDlg), TRUE);
		gtk_window_set_transient_for(GTK_WINDOW(FontDlg),GTK_WINDOW(Wins));
	}

  	gtk_font_selection_dialog_set_font_name    ((GtkFontSelectionDialog *)FontDlg,(gchar*)tdata);

/*  	gtk_widget_hide(FontDlg->help_button);*/
	g_signal_connect_swapped(GTK_OBJECT(FontDlg->ok_button),"clicked", (GtkSignalFunc)set_temp_font,GTK_OBJECT(FontDlg));

	g_signal_connect_swapped(GTK_OBJECT(FontDlg->ok_button),"clicked", (GtkSignalFunc)set_button_font,GTK_OBJECT(button));

	if(!instal)
	{
 		g_signal_connect_swapped(GTK_OBJECT(FontDlg->ok_button),"clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(FontDlg)); 
 		g_signal_connect_swapped(GTK_OBJECT(FontDlg->cancel_button),"clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(FontDlg)); 
	}
	else
	{
 		g_signal_connect_swapped(GTK_OBJECT(FontDlg->ok_button),"clicked",GTK_SIGNAL_FUNC(gtk_widget_destroy),GTK_OBJECT(FontDlg)); 
 		g_signal_connect_swapped(GTK_OBJECT(FontDlg->cancel_button),"clicked",GTK_SIGNAL_FUNC(gtk_widget_destroy),GTK_OBJECT(FontDlg)); 
	}
	gtk_widget_show(GTK_WIDGET(FontDlg));

}
/********************************************************************************/
void set_temp_color(GtkColorSelection *Sel,gpointer *d)
{
	gtk_color_selection_get_current_color(Sel, &ColorTemp);
}
/********************************************************************************/
static void set_button_color(GtkObject *b,gpointer *data)
{
  GtkWidget *hbox;
  GtkWidget *button = GTK_WIDGET(b);
  gchar *Type = g_object_get_data(G_OBJECT (button), "Type");

  gtk_widget_hide (GTK_WIDGET(button));
  hbox = g_object_get_data(G_OBJECT (button), "Hbox");  
  gtk_widget_destroy(GTK_WIDGET(hbox));

  hbox = create_hbox_pixmap_color(Wins,ColorTemp.red,ColorTemp.green,ColorTemp.blue);

  gtk_container_add(GTK_CONTAINER(button),hbox);
  g_object_set_data(G_OBJECT (button), "Hbox", hbox);
  gtk_widget_show (hbox);
  gtk_widget_show_all (GTK_WIDGET(button));
  if(strstr(Type,"Data _Back"))
  {
  	set_base_style(text,ColorTemp.red,ColorTemp.green,ColorTemp.blue);
        FontsStyleData.BaseColor  = ColorTemp;
  }
  else if(strstr(Type,"Data _Fore"))
  {
  	set_text_style(text,ColorTemp.red,ColorTemp.green,ColorTemp.blue);
        FontsStyleData.TextColor  = ColorTemp;
  }
  if(strstr(Type,"Result _Back"))
  {
  	set_base_style(textresult,ColorTemp.red,ColorTemp.green,ColorTemp.blue);
  	set_base_style(TextOutput,ColorTemp.red,ColorTemp.green,ColorTemp.blue);
  	set_base_style(TextError,ColorTemp.red,ColorTemp.green,ColorTemp.blue);
        FontsStyleResult.BaseColor  = ColorTemp;
  }
  else if(strstr(Type,"Result _Fore"))
  {
  	set_text_style(textresult,ColorTemp.red,ColorTemp.green,ColorTemp.blue);
  	set_text_style(TextOutput,ColorTemp.red,ColorTemp.green,ColorTemp.blue);
  	set_text_style(TextError,ColorTemp.red,ColorTemp.green,ColorTemp.blue);
        FontsStyleResult.TextColor  = ColorTemp;
  }
  else if(strstr(Type,"Label_Fore"))
  {
        FontsStyleLabel.TextColor  = ColorTemp;
 	if(ZoneDessin)
  		rafresh_drawing();
  }
}
/********************************************************************************/
static void open_color_dlg(GtkWidget *button,gpointer tcolor)
{

	GtkColorSelectionDialog *ColorDlg;
	ColorDlg = (GtkColorSelectionDialog *)gtk_color_selection_dialog_new("Set Atom Color");
	if(tcolor)
	{
		GdkColor* color = (GdkColor*)tcolor;
		gtk_color_selection_set_current_color (GTK_COLOR_SELECTION (ColorDlg->colorsel), color);
	}
        gtk_window_set_position(GTK_WINDOW(ColorDlg),GTK_WIN_POS_CENTER);

	if(!instal)
	{
		add_child(Wins,GTK_WIDGET(ColorDlg),gtk_widget_destroy," Set Color ");
		g_signal_connect(G_OBJECT(ColorDlg),"delete_event",(GtkSignalFunc)delete_child,NULL);
	}
	else
	{
		gtk_window_set_modal (GTK_WINDOW (ColorDlg), TRUE);
		gtk_window_set_transient_for(GTK_WINDOW(ColorDlg),GTK_WINDOW(Wins));
	}

  	gtk_widget_hide(ColorDlg->help_button);

	g_signal_connect_swapped(GTK_OBJECT(ColorDlg->ok_button),"clicked",
		(GtkSignalFunc)set_temp_color,GTK_OBJECT(ColorDlg->colorsel));

	g_signal_connect_swapped(GTK_OBJECT(ColorDlg->ok_button),"clicked",
		(GtkSignalFunc)set_button_color,GTK_OBJECT(button));

	if(!instal)
	{
 		g_signal_connect_swapped(GTK_OBJECT(ColorDlg->ok_button),"clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(ColorDlg)); 
 		g_signal_connect_swapped(GTK_OBJECT(ColorDlg->cancel_button),"clicked",GTK_SIGNAL_FUNC(delete_child),GTK_OBJECT(ColorDlg)); 
	}
	else
	{
 		g_signal_connect_swapped(GTK_OBJECT(ColorDlg->ok_button),"clicked",GTK_SIGNAL_FUNC(gtk_widget_destroy),GTK_OBJECT(ColorDlg)); 
 		g_signal_connect_swapped(GTK_OBJECT(ColorDlg->cancel_button),"clicked",GTK_SIGNAL_FUNC(gtk_widget_destroy),GTK_OBJECT(ColorDlg)); 
	}

	gtk_widget_show(GTK_WIDGET(ColorDlg));

}
/********************************************************************************/
GtkWidget*  add_button_color(GtkWidget *hbox,gushort red,gushort green,gushort blue)
{
  GtkWidget *button;
  GdkColor* color = g_malloc(sizeof(GdkColor));

  color->red = red;
  color->green = green;
  color->blue = blue;

  button = create_button_pixmap_color(Wins,red,green,blue);
  g_object_set_data_full (G_OBJECT (button), "InitialCOlor", color,g_free);
  g_signal_connect(G_OBJECT(button), "clicked",(GtkSignalFunc)open_color_dlg,color);

  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, FALSE, 1);

  return button;
}
/********************************************************************************/
GtkWidget*  add_label_color(GtkWidget *hbox,gchar *tlabel)
{
  GtkWidget *label;

  label = gtk_label_new (tlabel);
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, TRUE, 1);

  return label;
}
/********************************************************************************/
void add_frame_label(GtkWidget *hboxall)
{
  GtkWidget *vbox;
  GtkWidget *frame;
  GtkWidget *button;
  GtkWidget *label;
  GtkWidget *hboxbutton;
  gchar *type;
  gchar *tfont;
  gchar *tlabel = g_strdup("Label");
  GtkWidget *table = gtk_table_new(2,3,FALSE);


  frame = create_frame(Wins,hboxall,tlabel); 
  vbox = create_vbox(frame);
  gtk_container_add(GTK_CONTAINER(vbox),table);

  add_label_table(table," Default font          ",0,0);
  add_label_table(table," : ",0,1);

  hboxbutton = gtk_hbox_new (TRUE, 0);
  gtk_widget_set_size_request(GTK_WIDGET(hboxbutton), -1,  (gint)(ScreenHeight/50));

  tfont = g_strdup(FontsStyleLabel.fontname);
  label = gtk_label_new(tfont);
  button = gtk_button_new();
  gtk_container_add(GTK_CONTAINER(hboxbutton),label);
  gtk_container_add(GTK_CONTAINER(button),hboxbutton);
  g_object_set_data(G_OBJECT (button), "Hbox", hboxbutton);

  add_widget_table(table,button,0,2);
  g_signal_connect(G_OBJECT(button), "clicked",(GtkSignalFunc)open_font_dlg,(gpointer)tfont);
  type = g_strdup_printf("%s",tlabel);
  g_object_set_data(G_OBJECT (button), "Type", type);                                                                                    

  add_label_table(table," Foreground color ",1,0);
  add_label_table(table," : ",1,1);

  hboxbutton = gtk_hbox_new (FALSE, 0);
  button = add_button_color(hboxbutton,
  FontsStyleLabel.TextColor.red,FontsStyleLabel.TextColor.green,FontsStyleLabel.TextColor.blue);

  add_widget_table(table,hboxbutton,1,2);
  type = g_strdup_printf("%s_Fore",tlabel);
  g_object_set_data(G_OBJECT (button), "Type", type);

}
/********************************************************************************/
/*
void add_frame_other(GtkWidget *hboxall)
{
  GtkWidget *vbox;
  GtkWidget *frame;
  GtkWidget *button;
  GtkWidget *label;
  GtkWidget *hboxbutton;
  gchar *type;
  gchar *tfont;
  gchar *tlabel = g_strdup("Other");
  GtkWidget *table = gtk_table_new(1,3,FALSE);


  frame = create_frame(Wins,hboxall,tlabel); 
  vbox = create_vbox(frame);
  gtk_container_add(GTK_CONTAINER(vbox),table);

  add_label_table(table," Default font          ",0,0);
  add_label_table(table," : ",0,1);

  hboxbutton = gtk_hbox_new (TRUE, 0);
  gtk_widget_set_size_request(GTK_WIDGET(hboxbutton), -1,  (gint)(ScreenHeight/50));

  tfont = g_strdup(FontsStyleOther.fontname);
  label = gtk_label_new(tfont);
  button = gtk_button_new();
  gtk_container_add(GTK_CONTAINER(hboxbutton),label);
  gtk_container_add(GTK_CONTAINER(button),hboxbutton);
  g_object_set_data(G_OBJECT (button), "Hbox", hboxbutton);

  add_widget_table(table,button,0,2);
  g_signal_connect(G_OBJECT(button), "clicked",(GtkSignalFunc)open_font_dlg,(gpointer)tfont);
  type = g_strdup_printf("%s",tlabel);
  g_object_set_data(G_OBJECT (button), "Type", type);                                                                                    

}
*/
/********************************************************************************/
void add_frame_data_result(GtkWidget *hboxall,gchar *tlabel)
{
  GtkWidget *hboxbutton;
  GtkWidget *vbox;
  GtkWidget *frame;
  GtkWidget *button;
  GtkWidget *label;
  gchar *type;
  gchar *tfont;
  GtkWidget *table = gtk_table_new(3,3,FALSE);



  frame = create_frame(Wins,hboxall,tlabel); 
  vbox = create_vbox(frame);
  gtk_container_add(GTK_CONTAINER(vbox),table);

  add_label_table(table," Default font ",0,0);
  add_label_table(table," : ",0,1);
  hboxbutton = gtk_hbox_new (TRUE, 0);
  gtk_widget_set_size_request(GTK_WIDGET(hboxbutton), -1,  (gint)(ScreenHeight/50));
  if(strstr(tlabel,"Data"))
        tfont = g_strdup(FontsStyleData.fontname);
  else
        tfont = g_strdup(FontsStyleResult.fontname);

  label = gtk_label_new(tfont);
  button = gtk_button_new();
  gtk_container_add(GTK_CONTAINER(hboxbutton),label);
  gtk_container_add(GTK_CONTAINER(button),hboxbutton);
  g_object_set_data(G_OBJECT (button), "Hbox", hboxbutton);
  add_widget_table(table,button,0,2);
  g_signal_connect(G_OBJECT(button), "clicked",(GtkSignalFunc)open_font_dlg,(gpointer)tfont);
  type = g_strdup_printf("%s",tlabel);
  g_object_set_data(G_OBJECT (button), "Type", type);
                                                                                    

  add_label_table(table," Background color ",1,0);
  add_label_table(table," : ",1,1);
  if(strstr(tlabel,"Data"))
  {
  	hboxbutton = gtk_hbox_new (FALSE, 0);
  	button = add_button_color(hboxbutton,
	FontsStyleData.BaseColor.red,FontsStyleData.BaseColor.green,FontsStyleData.BaseColor.blue);
  }
  else
  {
  	hboxbutton = gtk_hbox_new (FALSE, 0);
  	button = add_button_color(hboxbutton,
	FontsStyleResult.BaseColor.red,FontsStyleResult.BaseColor.green,FontsStyleResult.BaseColor.blue);
  }
  add_widget_table(table,hboxbutton,1,2);
  type = g_strdup_printf("%s_Back",tlabel);
  g_object_set_data(G_OBJECT (button), "Type", type);

  add_label_table(table," Foreground color ",2,0);
  add_label_table(table," : ",2,1);

  if(strstr(tlabel,"Data"))
  {
  	hboxbutton = gtk_hbox_new (FALSE, 0);
  	button = add_button_color(hboxbutton,
	FontsStyleData.TextColor.red,FontsStyleData.TextColor.green,FontsStyleData.TextColor.blue);
  }
  else
  {
  	hboxbutton = gtk_hbox_new (FALSE, 0);
  	button = add_button_color(hboxbutton,
	FontsStyleResult.TextColor.red,FontsStyleResult.TextColor.green,FontsStyleResult.TextColor.blue);
  }
  add_widget_table(table,hboxbutton,2,2);
  type = g_strdup_printf("%s_Fore",tlabel);
  g_object_set_data(G_OBJECT (button), "Type", type);
}
/********************************************************************************/
void  create_font_color(GtkWidget *Wins,GtkWidget *Frame)
{
  GtkWidget *vbox;
  GtkWidget *hboxall;

  gtk_widget_realize(Wins);
  vbox = create_vbox(Frame);

  hboxall = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hboxall, FALSE, FALSE, 1);
  add_frame_data_result(hboxall," Data ");

  hboxall = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hboxall, FALSE, FALSE, 1);
  add_frame_data_result(hboxall," Result ");

  hboxall = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hboxall, FALSE, FALSE, 1);
  add_frame_label(hboxall);

  /* add_frame_other(hboxall);*/

}
/********************************************************************************/
void  create_font_color_in_box(GtkWidget *Win,GtkWidget *Box)
{
  GtkWidget *vbox;
  GtkWidget *Frame;
  GtkWidget *hboxall;

  Frame= gtk_frame_new(NULL);
  gtk_container_set_border_width(GTK_CONTAINER(Frame), 10);
  gtk_container_add(GTK_CONTAINER(Box),Frame);

  Wins = Win;
  instal = TRUE;
  gtk_widget_realize(Wins);
  vbox = create_vbox(Frame);

  hboxall = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hboxall, FALSE, FALSE, 1);
  add_frame_data_result(hboxall," Data ");

  hboxall = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hboxall, FALSE, FALSE, 1);
  add_frame_data_result(hboxall," Result ");

  hboxall = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hboxall, FALSE, FALSE, 1);
  add_frame_label(hboxall);

  hboxall = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hboxall, FALSE, FALSE, 1);
  /* add_frame_other(hboxall);*/

  gtk_widget_show_all(Frame);

}
/********************************************************************************/
static void  modify_batch_command(GtkWidget *Entry,gpointer data)
{
	GtkWidget* entryType   = GTK_WIDGET(data);
  	G_CONST_RETURN gchar*     textType  =  gtk_entry_get_text (GTK_ENTRY (entryType));
  	G_CONST_RETURN gchar*     textEntry  =  gtk_entry_get_text (GTK_ENTRY (Entry));
  	GtkWidget* entryAll   = g_object_get_data(G_OBJECT (entryType), "EntryAll");
  	GtkWidget* entryUser  = g_object_get_data(G_OBJECT (entryType), "EntryUser");
  	GtkWidget* entryKill  = g_object_get_data(G_OBJECT (entryType), "EntryKill");
  	GtkWidget* entryJobId = g_object_get_data(G_OBJECT (entryType), "EntryJobId");
	gchar* temp = g_strdup(textEntry);


  	gint n=-1;
  	gint i;

	if(!temp) return;
	if(strlen(temp)<1) return;

  	for(i=0;i<batchCommands.numberOfTypes;i++)
		if(strcmp(textType,batchCommands.types[i])==0)
	  	{
			n = i;
		  	break;
	  	}
	if(n<0) return;

	if(NameTypeBatch) g_free(NameTypeBatch);
	NameTypeBatch = g_strdup(batchCommands.types[n]);

	if(Entry==entryAll)
	{
		if(batchCommands.commandListAll[n]) g_free(batchCommands.commandListAll[n]);
		batchCommands.commandListAll[n] = g_strdup(temp);
		if(NameCommandBatchAll) g_free(NameCommandBatchAll);
		NameCommandBatchAll = g_strdup(temp);
	}
	else
	if(Entry==entryUser)
	{
		if(batchCommands.commandListUser[n]) g_free(batchCommands.commandListUser[n]);
		batchCommands.commandListUser[n] = g_strdup(temp);
		if(NameCommandBatchUser) g_free(NameCommandBatchUser);
		NameCommandBatchUser = g_strdup(temp);
	}
	else
	if(Entry==entryKill)
	{
		if(batchCommands.commandKill[n]) g_free(batchCommands.commandKill[n]);
		batchCommands.commandKill[n] = g_strdup(temp);
		if(NameCommandBatchKill) g_free(NameCommandBatchKill);
		NameCommandBatchKill = g_strdup(temp);
	}
	else
	if(Entry==entryJobId)
	{
		if(batchCommands.jobIdTitle[n]) g_free(batchCommands.jobIdTitle[n]);
		batchCommands.jobIdTitle[n] = g_strdup(temp);
		if(NamejobIdTitleBatch) g_free(NamejobIdTitleBatch);
		NamejobIdTitleBatch = g_strdup(temp);
	}
	g_free(temp);


}
/********************************************************************************/
static void  modify_batch_entrys(GtkWidget *Entry,gpointer data)
{
  GtkWidget* entryAll   = g_object_get_data(G_OBJECT (Entry), "EntryAll");
  GtkWidget* entryUser  = g_object_get_data(G_OBJECT (Entry), "EntryUser");
  GtkWidget* entryKill  = g_object_get_data(G_OBJECT (Entry), "EntryKill");
  GtkWidget* entryJobId = g_object_get_data(G_OBJECT (Entry), "EntryJobId");
  G_CONST_RETURN gchar*     textType  =  gtk_entry_get_text (GTK_ENTRY (Entry));
  gint n=-1;
  gint i;
  for(i=0;i<batchCommands.numberOfTypes;i++)
	  if(strcmp(textType,batchCommands.types[i])==0)
	  {
		  n = i;
		  break;
	  }
  if(n<0) return;
  gtk_entry_set_text (GTK_ENTRY (entryAll),batchCommands.commandListAll[n]);
  gtk_entry_set_text (GTK_ENTRY (entryUser),batchCommands.commandListUser[n]);
  gtk_entry_set_text (GTK_ENTRY (entryKill),batchCommands.commandKill[n]);
  gtk_entry_set_text (GTK_ENTRY (entryJobId),batchCommands.jobIdTitle[n]);
	
  if(n==0 || n == 1 || n == 2)
  {
  	gtk_editable_set_editable((GtkEditable*)entryAll,FALSE);
  	gtk_editable_set_editable((GtkEditable*)entryUser,FALSE);
  	gtk_editable_set_editable((GtkEditable*)entryKill,FALSE);
  	gtk_editable_set_editable((GtkEditable*)entryJobId,FALSE);

	gtk_widget_set_sensitive(entryAll, FALSE);
	gtk_widget_set_sensitive(entryUser, FALSE);
	gtk_widget_set_sensitive(entryKill, FALSE);
	gtk_widget_set_sensitive(entryJobId, FALSE);
  }
  else
  {
  	gtk_editable_set_editable((GtkEditable*)entryAll,TRUE);
  	gtk_editable_set_editable((GtkEditable*)entryUser,TRUE);
  	gtk_editable_set_editable((GtkEditable*)entryKill,TRUE);
  	gtk_editable_set_editable((GtkEditable*)entryJobId,TRUE);

	gtk_widget_set_sensitive(entryAll, TRUE);
	gtk_widget_set_sensitive(entryUser, TRUE);
	gtk_widget_set_sensitive(entryKill, TRUE);
	gtk_widget_set_sensitive(entryJobId, TRUE);

  }

}
/********************************************************************************/
void  create_batch_commands(GtkWidget *Wins,GtkWidget *vbox,gboolean expand)
{
  GtkWidget *frame;
  GtkWidget *combo;
  GtkWidget *entry;
  GtkWidget *table = gtk_table_new(4,3,FALSE);
  gint i;


  frame = gtk_frame_new ("Batch Commands");
  gtk_widget_show (frame);
  gtk_box_pack_start (GTK_BOX (vbox), frame, expand, expand, 0);
  gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

  vbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (frame), vbox);
  gtk_box_pack_start (GTK_BOX (vbox), table, TRUE, TRUE, 0);


/* ------------------------------------------------------------------*/
  i = 0;
  add_label_table(table," Batch Type ",(gushort)i,0);
  add_label_table(table," : ",(gushort)i,1);

  combo = create_combo_box_entry(batchCommands.types,batchCommands.numberOfTypes,TRUE,-1,-1);
  EntryBatchType = GTK_BIN(combo)->child;
  add_widget_table(table,combo,(gushort)i,2);
  gtk_editable_set_editable((GtkEditable*)EntryBatchType,FALSE);
  gtk_entry_set_text (GTK_ENTRY (EntryBatchType),NameTypeBatch);
/* ------------------------------------------------------------------*/
  i = 1;
  add_label_table(table," Command for list of all Job ",(gushort)i,0);
  add_label_table(table," : ",(gushort)i,1);
  entry = gtk_entry_new();
  add_widget_table(table,entry,(gushort)i,2);
  gtk_entry_set_text (GTK_ENTRY (entry),NameCommandBatchAll);
  g_object_set_data(G_OBJECT (EntryBatchType), "EntryAll", entry);
  gtk_editable_set_editable((GtkEditable*)entry,FALSE);
  gtk_widget_set_sensitive(entry, FALSE);
  g_signal_connect(G_OBJECT (entry), "changed", (GtkSignalFunc)modify_batch_command,EntryBatchType);
/* ------------------------------------------------------------------*/
  i = 2;
  add_label_table(table," Command for list of user Job ",(gushort)i,0);
  add_label_table(table," : ",(gushort)i,1);
  entry = gtk_entry_new();
  add_widget_table(table,entry,(gushort)i,2);
  gtk_entry_set_text (GTK_ENTRY (entry),NameCommandBatchUser);
  g_object_set_data(G_OBJECT (EntryBatchType), "EntryUser", entry);
  gtk_editable_set_editable((GtkEditable*)entry,FALSE);
  gtk_widget_set_sensitive(entry, FALSE);
  g_signal_connect(G_OBJECT (entry), "changed", (GtkSignalFunc)modify_batch_command,EntryBatchType);
/* ------------------------------------------------------------------*/
  i = 3;
  add_label_table(table," Command for kill a Job ",(gushort)i,0);
  add_label_table(table," : ",(gushort)i,1);
  entry = gtk_entry_new();
  add_widget_table(table,entry,(gushort)i,2);
  gtk_entry_set_text (GTK_ENTRY (entry),NameCommandBatchKill);
  g_object_set_data(G_OBJECT (EntryBatchType), "EntryKill", entry);
  gtk_editable_set_editable((GtkEditable*)entry,FALSE);
  gtk_widget_set_sensitive(entry, FALSE);
  g_signal_connect(G_OBJECT (entry), "changed", (GtkSignalFunc)modify_batch_command,EntryBatchType);
/* ------------------------------------------------------------------*/
  i = 4;
  add_label_table(table," Title for Job id ",(gushort)i,0);
  add_label_table(table," : ",(gushort)i,1);
  entry = gtk_entry_new();
  add_widget_table(table,entry,(gushort)i,2);
  gtk_entry_set_text (GTK_ENTRY (entry),NamejobIdTitleBatch);
  g_object_set_data(G_OBJECT (EntryBatchType), "EntryJobId", entry);
  gtk_editable_set_editable((GtkEditable*)entry,FALSE);
  gtk_widget_set_sensitive(entry, FALSE);
  g_signal_connect(G_OBJECT (entry), "changed", (GtkSignalFunc)modify_batch_command,EntryBatchType);
/* ------------------------------------------------------------------*/

  g_signal_connect(G_OBJECT (EntryBatchType), "changed", (GtkSignalFunc)modify_batch_entrys, NULL);
  gtk_entry_set_text (GTK_ENTRY (EntryBatchType)," ");
  gtk_entry_set_text (GTK_ENTRY (EntryBatchType),NameTypeBatch);
  gtk_widget_show_all(frame);

}
/********************************************************************************/
static void changed_babel(GtkWidget* wid)
{
  	if(babelCommand) g_free(babelCommand);
	babelCommand = g_strdup(gtk_entry_get_text(GTK_ENTRY(entrybabel)));
}
/********************************************************************************/
static void set_entry_babel(GtkWidget* SelFile, gint response_id)
{
  GtkWidget *entry = NULL;
  gchar *longfile = NULL;
   if(response_id != GTK_RESPONSE_OK) return;

  entry = (GtkWidget*)(g_object_get_data(G_OBJECT(SelFile),"EntryFile"));	
  longfile = gabedit_file_chooser_get_current_file(GABEDIT_FILE_CHOOSER(SelFile));
  gtk_entry_set_text(GTK_ENTRY(entry),longfile);

  if(babelCommand) g_free(babelCommand);
  babelCommand = g_strdup(gtk_entry_get_text(GTK_ENTRY(entrybabel)));

}
/********************************************************************************/
static void set_entry_babel_selction(GtkWidget* entry)
{
  GtkWidget *SelFile;

  SelFile = gabedit_file_chooser_new("File chooser", GTK_FILE_CHOOSER_ACTION_OPEN);
  gtk_window_set_modal (GTK_WINDOW (SelFile), TRUE);
  gabedit_file_chooser_hide_hidden(GABEDIT_FILE_CHOOSER(SelFile));
  g_signal_connect(G_OBJECT(SelFile),"delete_event", (GtkSignalFunc)gtk_widget_destroy,NULL);

  g_object_set_data(G_OBJECT (SelFile), "EntryFile", entry);

  g_signal_connect (SelFile, "response",  G_CALLBACK (set_entry_babel), GTK_OBJECT(SelFile));
  g_signal_connect (SelFile, "response",  G_CALLBACK (gtk_widget_destroy), GTK_OBJECT(SelFile));

  /* g_signal_connect (SelFile, "close",  G_CALLBACK (gtk_widget_destroy), GTK_OBJECT(SelFile));*/
  gtk_widget_show(SelFile);
}
/********************************************************************************/
#ifdef G_OS_WIN32
static void set_entry_gamessdir(GtkWidget* dirSelector, gint response_id)
{
	gchar* dirname = NULL;
	GtkWidget *entry;
	if(response_id != GTK_RESPONSE_OK) return;
	dirname = gabedit_folder_chooser_get_current_folder(GABEDIT_FOLDER_CHOOSER(dirSelector));


	entry = (GtkWidget*)(g_object_get_data(G_OBJECT(dirSelector),"EntryFile"));	
	gtk_entry_set_text(GTK_ENTRY(entry),dirname);

	if(gamessDirectory) g_free(gamessDirectory);
	gamessDirectory = g_strdup(dirname);
}
/********************************************************************************/
static void set_entry_gamessDir_selection(GtkWidget* entry)
{
	GtkWidget *dirSelector;
	dirSelector = selctionOfDir(set_entry_gamessdir, "Select Gamess folder", GABEDIT_TYPEWIN_ORB); 
  	gtk_window_set_modal (GTK_WINDOW (dirSelector), TRUE);
  	g_signal_connect(G_OBJECT(dirSelector),"delete_event", (GtkSignalFunc)gtk_widget_destroy,NULL);

	g_object_set_data(G_OBJECT (dirSelector), "EntryFile", entry);

	g_signal_connect (dirSelector, "response",  G_CALLBACK (set_entry_gamessdir), GTK_OBJECT(dirSelector));
	g_signal_connect (dirSelector, "response",  G_CALLBACK (gtk_widget_destroy), GTK_OBJECT(dirSelector));

	gtk_widget_show(dirSelector);
}
/********************************************************************************/
static void set_entry_pcgamessdir(GtkWidget* dirSelector, gint response_id)
{
	gchar* dirname = NULL;
	gchar* t = NULL;
	GtkWidget *entry;
	if(response_id != GTK_RESPONSE_OK) return;
	dirname = gabedit_folder_chooser_get_current_folder(GABEDIT_FOLDER_CHOOSER(dirSelector));


	entry = (GtkWidget*)(g_object_get_data(G_OBJECT(dirSelector),"EntryFile"));	
	gtk_entry_set_text(GTK_ENTRY(entry),dirname);

	if(pcgamessDirectory) g_free(pcgamessDirectory);
	pcgamessDirectory = g_strdup(dirname);
	t = g_strdup_printf("%s;%cPATH%c",pcgamessDirectory,'%','%');
	g_setenv("PATH",t,TRUE);
	g_free(t);
}
/********************************************************************************/
static void set_entry_pcgamessDir_selection(GtkWidget* entry)
{
	GtkWidget *dirSelector;
	dirSelector = selctionOfDir(set_entry_pcgamessdir, "Select PCGamess folder", GABEDIT_TYPEWIN_ORB); 
  	gtk_window_set_modal (GTK_WINDOW (dirSelector), TRUE);
  	g_signal_connect(G_OBJECT(dirSelector),"delete_event", (GtkSignalFunc)gtk_widget_destroy,NULL);

	g_object_set_data(G_OBJECT (dirSelector), "EntryFile", entry);

	g_signal_connect (dirSelector, "response",  G_CALLBACK (set_entry_pcgamessdir), GTK_OBJECT(dirSelector));
	g_signal_connect (dirSelector, "response",  G_CALLBACK (gtk_widget_destroy), GTK_OBJECT(dirSelector));

	gtk_widget_show(dirSelector);
}
#endif
/********************************************************************************/
void  create_execucte_commands(GtkWidget *Wins,GtkWidget *vbox,gboolean expand)
{
  GtkWidget *hbox;
  GtkWidget *label;
  GtkWidget *frame;
  GtkWidget *combo;
  GtkWidget *button;

  frame = gtk_frame_new ("Commands for execute Gaussian, Molcas, Molpro, MPQC, PCGamess, Q-Chem or Babel");
  gtk_widget_show (frame);
  gtk_box_pack_start (GTK_BOX (vbox), frame, expand, expand, 0);
  gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

  vbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (frame), vbox);


/* ------------------------------------------------------------------*/
  hbox = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 3);
  label = gtk_label_new ("Command for execute Gamess : ");
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, TRUE, 3);

  combo = create_combo_box_entry(gamessCommands.commands,gamessCommands.numberOfCommands,TRUE,-1,-1);
  ComboGamess = combo;
  EntryGamess = GTK_BIN(combo)->child;
  gtk_box_pack_start (GTK_BOX (hbox), combo, TRUE, TRUE, 3);
  gtk_entry_set_text (GTK_ENTRY (EntryGamess),NameCommandGamess );
  g_signal_connect(G_OBJECT (EntryGamess), "activate",
			(GtkSignalFunc)modify_gamess_command,
			NULL);

  button = create_button(Wins,"  Remove from list  ");
  ButtonGamess = button;
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  if(gamessCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(button, FALSE);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(remove_gamess_command),NULL);

  button = create_button(Wins,"  Help  ");
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(help_commands),NULL);
/* ------------------------------------------------------------------*/
  gtk_widget_realize(Wins);

  create_hseparator(vbox);

/* ------------------------------------------------------------------*/
  hbox = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 3);
  label = gtk_label_new ("Command for execute Gaussian : ");
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, TRUE, 3);

  combo = create_combo_box_entry(gaussianCommands.commands,gaussianCommands.numberOfCommands,TRUE,-1,-1);
  ComboGaussian = combo;
  EntryGaussian = GTK_BIN(combo)->child;
  gtk_box_pack_start (GTK_BOX (hbox), combo, TRUE, TRUE, 3);
  gtk_entry_set_text (GTK_ENTRY (EntryGaussian),NameCommandGaussian );
  g_signal_connect(G_OBJECT (EntryGaussian), "activate",
			(GtkSignalFunc)modify_gaussian_command,
			NULL);

  button = create_button(Wins,"  Remove from list  ");
  ButtonGaussian = button;
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  if(gaussianCommands.numberOfCommands<2) gtk_widget_set_sensitive(button, FALSE);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(remove_gaussian_command),NULL);

  button = create_button(Wins,"  Help  ");
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(help_commands),NULL);
/* ------------------------------------------------------------------*/

  create_hseparator(vbox);

/* ------------------------------------------------------------------*/
  hbox = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 3);
  label = gtk_label_new ("Command for execute Molpro    : ");
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, TRUE, 3);

  combo = create_combo_box_entry(molproCommands.commands,molproCommands.numberOfCommands,TRUE,-1,-1);
  ComboMolpro = combo;
  EntryMolpro =  GTK_BIN(combo)->child;
  gtk_box_pack_start (GTK_BOX (hbox), combo, TRUE, TRUE, 3);
  gtk_entry_set_text (GTK_ENTRY (EntryMolpro),NameCommandMolpro);
  g_signal_connect(G_OBJECT (EntryMolpro), "activate",
			(GtkSignalFunc)modify_molpro_command,
			NULL);
  button = create_button(Wins,"  Remove from list  ");
  ButtonMolpro = button;
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  if(molproCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(button, FALSE);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(remove_molpro_command),NULL);

  button = create_button(Wins,"  Help  ");
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(help_commands),NULL);
/* ------------------------------------------------------------------*/

  create_hseparator(vbox);

/* ------------------------------------------------------------------*/
  hbox = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 3);
  label = gtk_label_new ("Command for execute Molcas    : ");
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, TRUE, 3);

  combo = create_combo_box_entry(molcasCommands.commands,molcasCommands.numberOfCommands,TRUE,-1,-1);
  ComboMolcas = combo;
  EntryMolcas =  GTK_BIN(combo)->child;
  gtk_box_pack_start (GTK_BOX (hbox), combo, TRUE, TRUE, 3);
  gtk_entry_set_text (GTK_ENTRY (EntryMolcas),NameCommandMolcas);
  g_signal_connect(G_OBJECT (EntryMolcas), "activate",
			(GtkSignalFunc)modify_molcas_command,
			NULL);
  button = create_button(Wins,"  Remove from list  ");
  ButtonMolcas = button;
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  if(molcasCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(button, FALSE);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(remove_molcas_command),NULL);

  button = create_button(Wins,"  Help  ");
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(help_commands),NULL);
/* ------------------------------------------------------------------*/

  create_hseparator(vbox);

/* ------------------------------------------------------------------*/
  hbox = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 3);
  label = gtk_label_new ("Command for execute MPQC    : ");
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, TRUE, 3);

  combo = create_combo_box_entry(mpqcCommands.commands,mpqcCommands.numberOfCommands,TRUE,-1,-1);
  ComboMPQC = combo;
  EntryMPQC =  GTK_BIN(combo)->child;
  gtk_box_pack_start (GTK_BOX (hbox), combo, TRUE, TRUE, 3);
  gtk_entry_set_text (GTK_ENTRY (EntryMPQC),NameCommandMPQC);
  g_signal_connect(G_OBJECT (EntryMPQC), "activate",
			(GtkSignalFunc)modify_mpqc_command,
			NULL);
  button = create_button(Wins,"  Remove from list  ");
  ButtonMPQC = button;
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  if(mpqcCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(button, FALSE);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(remove_mpqc_command),NULL);

  button = create_button(Wins,"  Help  ");
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(help_commands),NULL);

  create_hseparator(vbox);
/* ------------------------------------------------------------------*/
  hbox = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 3);
  label = gtk_label_new ("Command for execute PCGamess    : ");
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, TRUE, 3);

  combo = create_combo_box_entry(pcgamessCommands.commands,pcgamessCommands.numberOfCommands,TRUE,-1,-1);
  ComboPCGamess = combo;
  EntryPCGamess =  GTK_BIN(combo)->child;
  gtk_box_pack_start (GTK_BOX (hbox), combo, TRUE, TRUE, 3);
  gtk_entry_set_text (GTK_ENTRY (EntryPCGamess),NameCommandPCGamess);
  g_signal_connect(G_OBJECT (EntryPCGamess), "activate", (GtkSignalFunc)modify_pcgamess_command, NULL);
  button = create_button(Wins,"  Remove from list  ");
  ButtonPCGamess = button;
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  if(pcgamessCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(button, FALSE);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(remove_pcgamess_command),NULL);

  button = create_button(Wins,"  Help  ");
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(help_commands),NULL);
/* ------------------------------------------------------------------*/

  create_hseparator(vbox);
/* ------------------------------------------------------------------*/
  hbox = gtk_hbox_new (FALSE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 3);
  label = gtk_label_new ("Command for execute Q-Chem    : ");
  gtk_box_pack_start (GTK_BOX (hbox), label, FALSE, TRUE, 3);

  combo = create_combo_box_entry(qchemCommands.commands,qchemCommands.numberOfCommands,TRUE,-1,-1);
  ComboQChem = combo;
  EntryQChem =  GTK_BIN(combo)->child;
  gtk_box_pack_start (GTK_BOX (hbox), combo, TRUE, TRUE, 3);
  gtk_entry_set_text (GTK_ENTRY (EntryQChem),NameCommandQChem);
  g_signal_connect(G_OBJECT (EntryQChem), "activate", (GtkSignalFunc)modify_qchem_command, NULL);
  button = create_button(Wins,"  Remove from list  ");
  ButtonQChem = button;
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  if(qchemCommands.numberOfCommands<2)
  	gtk_widget_set_sensitive(button, FALSE);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(remove_qchem_command),NULL);

  button = create_button(Wins,"  Help  ");
  gtk_box_pack_start (GTK_BOX (hbox), button, FALSE, TRUE, 3);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(help_commands),NULL);
/* ------------------------------------------------------------------*/

  create_hseparator(vbox);

/*#ifdef G_OS_WIN32*/
  {
	GtkWidget* entry;
  	GtkWidget *table = gtk_table_new(1,3,FALSE);

	if(!babelCommand)
		babelCommand = g_strdup_printf("%s%sbabel.exe",g_get_current_dir(),G_DIR_SEPARATOR_S);

	gtk_box_pack_start (GTK_BOX (vbox), table, TRUE, TRUE, 0);

	add_label_table(table,"Command for Open Babel         : ",0,0);
  	entry = gtk_entry_new ();
	entrybabel = entry;
	gtk_widget_set_size_request(GTK_WIDGET(entry),-1,32);
	gtk_table_attach(GTK_TABLE(table),entry,1,1+1,0,0+1,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  3,3);
  	gtk_entry_set_text (GTK_ENTRY (entry),babelCommand);
	gtk_editable_set_editable((GtkEditable*)entry,TRUE);
	gtk_widget_set_sensitive(entry, TRUE);
	button = create_button_pixmap(Wins,open_xpm,NULL);
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	g_signal_connect_swapped(GTK_OBJECT (button), "clicked",
                                     GTK_SIGNAL_FUNC(set_entry_babel_selction),
                                     GTK_OBJECT(entry));
	add_widget_table(table,button,0,2);
  	g_signal_connect(G_OBJECT (entrybabel), "changed",
			(GtkSignalFunc)changed_babel,
			NULL);
  }
/*#endif*/
  create_hseparator(vbox);
  gtk_widget_show_all(frame);

}
#ifdef G_OS_WIN32
/********************************************************************************/
void  create_gamess_directory(GtkWidget *Wins,GtkWidget *vbox,gboolean expand)
{
  GtkWidget *frame;
  GtkWidget *button;

  frame = gtk_frame_new (NULL);
  gtk_widget_show (frame);
  gtk_box_pack_start (GTK_BOX (vbox), frame, expand, expand, 0);
  gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

  vbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (frame), vbox);


  {
	GtkWidget* entry;
  	GtkWidget *table = gtk_table_new(1,3,FALSE);

	if(!gamessDirectory) gamessDirectory = g_strdup_printf("%s",g_get_home_dir());

	gtk_box_pack_start (GTK_BOX (vbox), table, TRUE, TRUE, 0);

	add_label_table(table,"Gamess directory                        : ",0,0);
  	entry = gtk_entry_new ();
	gtk_widget_set_size_request(GTK_WIDGET(entry),-1,32);
	gtk_table_attach(GTK_TABLE(table),entry,1,1+1,0,0+1,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  3,3);
  	gtk_entry_set_text (GTK_ENTRY (entry),gamessDirectory);
	gtk_editable_set_editable((GtkEditable*)entry,FALSE);
	gtk_widget_set_sensitive(entry, FALSE);
	button = create_button_pixmap(Wins,open_xpm,NULL);
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	g_signal_connect_swapped(GTK_OBJECT (button), "clicked",
                                     GTK_SIGNAL_FUNC(set_entry_gamessDir_selection),
                                     GTK_OBJECT(entry));
	add_widget_table(table,button,0,2);
  }
  gtk_widget_show_all(frame);
}
#endif
#ifdef G_OS_WIN32
/********************************************************************************/
void  create_pcgamess_directory(GtkWidget *Wins,GtkWidget *vbox,gboolean expand)
{
  GtkWidget *frame;
  GtkWidget *button;

  frame = gtk_frame_new (NULL);
  gtk_widget_show (frame);
  gtk_box_pack_start (GTK_BOX (vbox), frame, expand, expand, 0);
  gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

  vbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (frame), vbox);


  {
	GtkWidget* entry;
  	GtkWidget *table = gtk_table_new(1,3,FALSE);

	if(!pcgamessDirectory) pcgamessDirectory = g_strdup_printf("%s",g_get_home_dir());

	gtk_box_pack_start (GTK_BOX (vbox), table, TRUE, TRUE, 0);

	add_label_table(table,"PCGamess directory                        : ",0,0);
  	entry = gtk_entry_new ();
	gtk_widget_set_size_request(GTK_WIDGET(entry),-1,32);
	gtk_table_attach(GTK_TABLE(table),entry,1,1+1,0,0+1,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  3,3);
  	gtk_entry_set_text (GTK_ENTRY (entry),pcgamessDirectory);
	gtk_editable_set_editable((GtkEditable*)entry,FALSE);
	gtk_widget_set_sensitive(entry, FALSE);
	button = create_button_pixmap(Wins,open_xpm,NULL);
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	g_signal_connect_swapped(GTK_OBJECT (button), "clicked",
                                     GTK_SIGNAL_FUNC(set_entry_pcgamessDir_selection),
                                     GTK_OBJECT(entry));
	add_widget_table(table,button,0,2);
  }
  gtk_widget_show_all(frame);
}
#endif
/********************************************************************************/
void AddPageColorSurf(GtkWidget *NoteBook)
{
  GtkWidget *Frame;
  GtkWidget *LabelOnglet;
  GtkWidget *LabelMenu;
  
  Frame= gtk_frame_new(NULL);
  gtk_container_set_border_width(GTK_CONTAINER(Frame), 10);
  LabelOnglet = gtk_label_new(" Surface colors ");
  LabelMenu = gtk_label_new("   Surface colors  ");
  gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
                                Frame,
                                LabelOnglet, LabelMenu);
  create_color_surfaces(Wins,Frame);
  gtk_widget_show(Frame);
}
/********************************************************************************/
static void  set_network(GtkWidget *Button, gpointer data)
{
	if(!data)
  		defaultNetWorkProtocol = GABEDIT_NETWORK_FTP_RSH;
	else
  		defaultNetWorkProtocol = GABEDIT_NETWORK_SSH;

	set_sensitive_remote_frame(TRUE);
}
/********************************************************************************/
void AddPageFont(GtkWidget *NoteBook)
{
  GtkWidget *Frame;
  GtkWidget *LabelOnglet;
  GtkWidget *LabelMenu;
  
  Frame= gtk_frame_new(NULL);
  gtk_container_set_border_width(GTK_CONTAINER(Frame), 10);
  LabelOnglet = gtk_label_new(" Fonts/Colors ");
  LabelMenu = gtk_label_new(" Fonts/Colors ");
  gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
                                Frame,
                                LabelOnglet, LabelMenu);
  create_font_color(Wins,Frame);
  gtk_widget_show_all(Frame);
}
/********************************************************************************/
void AddPageProp(GtkWidget *NoteBook)
{
  GtkWidget *Frame;
  GtkWidget *LabelOnglet;
  GtkWidget *LabelMenu;
  
  Frame= gtk_frame_new(NULL);
  gtk_container_set_border_width(GTK_CONTAINER(Frame), 10);
  gtk_widget_set_size_request(GTK_WIDGET(Frame), (gint)(ScreenHeight*0.6),  (gint)(ScreenHeight*0.3));
  LabelOnglet = gtk_label_new(" Properties of atoms ");
  LabelMenu = gtk_label_new(" Properties of atoms ");
  gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
                                Frame,
                                LabelOnglet, LabelMenu);
  create_table_prop_in_window(Wins,Frame);
  gtk_widget_show_all(Frame);
}
#ifdef G_OS_WIN32
/********************************************************************************/
static void set_entry_pscpplinkdir(GtkWidget* dirSelector, gint response_id)
{
	gchar* dirname = NULL;
	GtkWidget *entry;
	if(response_id != GTK_RESPONSE_OK) return;
	dirname = gabedit_folder_chooser_get_current_folder(GABEDIT_FOLDER_CHOOSER(dirSelector));


	entry = (GtkWidget*)(g_object_get_data(G_OBJECT(dirSelector),"EntryFile"));	
	gtk_entry_set_text(GTK_ENTRY(entry),dirname);

	if(strcmp(dirname,pscpplinkDirectory)!=0)
	{
		gchar* t = g_strdup_printf("%s;%cPATH%c",dirname,'%','%');
		g_setenv("PATH",t,TRUE);
		g_free(t);
	}

	if(pscpplinkDirectory) g_free(pscpplinkDirectory);
	pscpplinkDirectory = g_strdup(dirname);
}
/********************************************************************************/
static void set_entry_pscpplinkDir_selection(GtkWidget* entry)
{
	GtkWidget *dirSelector;
	dirSelector = selctionOfDir(set_entry_pscpplinkdir, "Select pscp & plink folder", GABEDIT_TYPEWIN_ORB); 
  	gtk_window_set_modal (GTK_WINDOW (dirSelector), TRUE);
  	g_signal_connect(G_OBJECT(dirSelector),"delete_event", (GtkSignalFunc)gtk_widget_destroy,NULL);

	g_object_set_data(G_OBJECT (dirSelector), "EntryFile", entry);

	g_signal_connect (dirSelector, "response",  G_CALLBACK (set_entry_pscpplinkdir), GTK_OBJECT(dirSelector));
	g_signal_connect (dirSelector, "response",  G_CALLBACK (gtk_widget_destroy), GTK_OBJECT(dirSelector));

	gtk_widget_show(dirSelector);
}
/********************************************************************************/
void  create_pscpplink_directory(GtkWidget *Wins,GtkWidget *vbox,gboolean expand)
{
  GtkWidget *frame;
  GtkWidget *button;

  frame = gtk_frame_new (NULL);
  gtk_widget_show (frame);
  gtk_box_pack_start (GTK_BOX (vbox), frame, expand, expand, 0);
  gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

  vbox = gtk_vbox_new (FALSE, 0);
  gtk_container_add (GTK_CONTAINER (frame), vbox);


  {
	GtkWidget* entry;
  	GtkWidget *table = gtk_table_new(1,3,FALSE);

	if(!pscpplinkDirectory) pscpplinkDirectory = g_strdup_printf("%s",g_get_home_dir());

	gtk_box_pack_start (GTK_BOX (vbox), table, TRUE, TRUE, 0);

	add_label_table(table,"pscp & plink directory                    : ",0,0);
  	entry = gtk_entry_new ();
	gtk_widget_set_size_request(GTK_WIDGET(entry),-1,32);
	gtk_table_attach(GTK_TABLE(table),entry,1,1+1,0,0+1,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  3,3);
  	gtk_entry_set_text (GTK_ENTRY (entry),pscpplinkDirectory);
	gtk_editable_set_editable((GtkEditable*)entry,FALSE);
	gtk_widget_set_sensitive(entry, FALSE);
	button = create_button_pixmap(Wins,open_xpm,NULL);
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	g_signal_connect_swapped(GTK_OBJECT (button), "clicked",
                                     GTK_SIGNAL_FUNC(set_entry_pscpplinkDir_selection),
                                     GTK_OBJECT(entry));
	add_widget_table(table,button,0,2);
  }
  gtk_widget_show_all(frame);
}
#endif /* and G_OS_WIN32 for pscp and plink */
/********************************************************************************/
void  create_network_protocols(GtkWidget* Win,GtkWidget *vbox,gboolean expand)
{
  GtkWidget *frame;
  GtkWidget *ButtonFtpRsh;
  GtkWidget *ButtonSsh;
  GtkWidget *button;
  GtkWidget *vboxframe;
  GtkWidget *table = gtk_table_new(2,2,TRUE);
  gchar ftprsh[] = "FTP and Rsh protocols";
  gchar ssh[]    = "ssh protocol            ";

  frame = gtk_frame_new ("Default NetWork protocol");
  gtk_widget_show (frame);
  gtk_box_pack_start (GTK_BOX (vbox), frame, expand, expand, 0);
  gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

  vboxframe = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vboxframe);
  gtk_container_add (GTK_CONTAINER (frame), vboxframe);

  gtk_box_pack_start (GTK_BOX (vboxframe), table, expand, expand, 0);


  ButtonFtpRsh = gtk_radio_button_new_with_label( NULL,ftprsh);
  add_widget_table(table,ButtonFtpRsh,0,0);
  gtk_widget_show (ButtonFtpRsh);
  if(defaultNetWorkProtocol==GABEDIT_NETWORK_FTP_RSH)
  	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonFtpRsh), TRUE);
  else
  	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonFtpRsh), FALSE);

  button = create_button(Win,"  Help  ");
  add_widget_table(table,button,0,1);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(help_ftp_rsh),NULL);

  ButtonSsh = gtk_radio_button_new_with_label(
                       gtk_radio_button_get_group (GTK_RADIO_BUTTON (ButtonFtpRsh)),
                       ssh); 
  add_widget_table(table,ButtonSsh,1,0);
  gtk_widget_show (ButtonSsh);
  if(defaultNetWorkProtocol==GABEDIT_NETWORK_SSH)
  	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonSsh), TRUE);
  else
  	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonSsh), FALSE);

  g_signal_connect(G_OBJECT (ButtonSsh), "clicked", GTK_SIGNAL_FUNC(set_network), ButtonSsh);
  g_signal_connect(G_OBJECT (ButtonFtpRsh), "clicked", GTK_SIGNAL_FUNC(set_network), NULL);
  button = create_button(Win,"  Help  ");
  add_widget_table(table,button,1,1);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(help_ssh),NULL);

#ifdef G_OS_WIN32
#endif

  gtk_widget_show_all(frame);
}
/********************************************************************************/
void AddPageOthers(GtkWidget *NoteBook)
{
  GtkWidget *Frame;
  GtkWidget *LabelOnglet;
  GtkWidget *LabelMenu;
  GtkWidget *vbox;
  
  Frame= gtk_frame_new(NULL);
  gtk_container_set_border_width(GTK_CONTAINER(Frame), 10);
  /* gtk_widget_set_size_request(GTK_WIDGET(Frame), (gint)(ScreenHeight*0.6),  (gint)(ScreenHeight*0.3));*/
  LabelOnglet = gtk_label_new(" Others ");
  LabelMenu = gtk_label_new(" Others ");
  gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook), Frame, LabelOnglet, LabelMenu);
  vbox = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox);
  gtk_container_add (GTK_CONTAINER (Frame), vbox);

#ifdef G_OS_WIN32
  create_gamess_directory(Wins,vbox,FALSE);
  create_pcgamess_directory(Wins,vbox,FALSE);
#endif

  create_opengl_frame(Wins,vbox);
  gtk_widget_show_all(Frame);
}
/********************************************************************************/
void AddPageCommands(GtkWidget *NoteBook)
{
  GtkWidget *Frame;
  GtkWidget *LabelOnglet;
  GtkWidget *LabelMenu;
  GtkWidget *vbox;
  
  Frame= gtk_frame_new(NULL);
  gtk_container_set_border_width(GTK_CONTAINER(Frame), 10);
  /* gtk_widget_set_size_request(GTK_WIDGET(Frame), (gint)(ScreenHeight*0.6),  (gint)(ScreenHeight*0.3));*/
  LabelOnglet = gtk_label_new(" Commands ");
  LabelMenu = gtk_label_new(" Commands ");
  gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
                                Frame,
                                LabelOnglet, LabelMenu);
  vbox = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox);
  gtk_container_add (GTK_CONTAINER (Frame), vbox);

  create_execucte_commands(Wins,vbox,FALSE);
  gtk_widget_show_all(Frame);
}
/********************************************************************************/
void AddPageBatch(GtkWidget *NoteBook)
{
  GtkWidget *Frame;
  GtkWidget *LabelOnglet;
  GtkWidget *LabelMenu;
  GtkWidget *vbox;
  
  Frame= gtk_frame_new(NULL);
  gtk_container_set_border_width(GTK_CONTAINER(Frame), 10);
  /* gtk_widget_set_size_request(GTK_WIDGET(Frame), (gint)(ScreenHeight*0.6),  (gint)(ScreenHeight*0.3));*/
  LabelOnglet = gtk_label_new(" Batch ");
  LabelMenu = gtk_label_new(" Batch ");
  gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
                                Frame,
                                LabelOnglet, LabelMenu);
  vbox = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox);
  gtk_container_add (GTK_CONTAINER (Frame), vbox);

  create_batch_commands(Wins,vbox,FALSE);
  gtk_widget_show_all(Frame);
}
/********************************************************************************/
void AddPageNetWork(GtkWidget *NoteBook)
{
  GtkWidget *Frame;
  GtkWidget *LabelOnglet;
  GtkWidget *LabelMenu;
  GtkWidget *vbox;
  
  Frame= gtk_frame_new(NULL);
  gtk_container_set_border_width(GTK_CONTAINER(Frame), 10);
  /* gtk_widget_set_size_request(GTK_WIDGET(Frame), (gint)(ScreenHeight*0.6),  (gint)(ScreenHeight*0.3));*/
  LabelOnglet = gtk_label_new(" NetWork ");
  LabelMenu = gtk_label_new(" NetWork ");
  gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
                                Frame,
                                LabelOnglet, LabelMenu);
  vbox = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox);
  gtk_container_add (GTK_CONTAINER (Frame), vbox);

#ifdef G_OS_WIN32
  create_pscpplink_directory(Wins,vbox,FALSE);
#endif
  create_network_protocols(Wins,vbox,FALSE);
  gtk_widget_show_all(Frame);
}
/********************************************************************************/
void create_preferences()
{
  GtkWidget *button;

  if(instal)
  	Wins= gtk_dialog_new ();
  else
  {
  	if(!Wins)
  		Wins= gtk_dialog_new ();
  	else
  	{
	  	gtk_widget_hide(Wins);
	 	 gtk_widget_show(Wins);
	  	return;
  	}
  }
  instal = FALSE;
  gtk_window_set_position(GTK_WINDOW(Wins),GTK_WIN_POS_CENTER);
  gtk_window_set_transient_for(GTK_WINDOW(Wins),GTK_WINDOW(Fenetre));
  gtk_window_set_default_size (GTK_WINDOW(Wins), (gushort)(2.9*ScreenWidth/5), (gushort)(2.9*ScreenHeight/5));
/*  gtk_window_set_modal (GTK_WINDOW (Wins), TRUE);*/

  /* Connection des signaux "delete" et "destroy" */
  init_child(Wins,gtk_widget_destroy," Preferences ");
  g_signal_connect(G_OBJECT(Wins),"delete_event",(GtkSignalFunc)destroy_preferences_window,NULL);

  gtk_window_set_title(&GTK_DIALOG(Wins)->window,"Preferences");
 
  /* NoteBook Options */
  NoteBook = gtk_notebook_new();
  gtk_box_pack_start(GTK_BOX (GTK_DIALOG(Wins)->vbox), NoteBook,TRUE, TRUE, 0);
  AddPageProp(NoteBook);
  AddPageFont(NoteBook);
  gtk_widget_show(NoteBook);
  gtk_widget_show(GTK_WIDGET(GTK_DIALOG(Wins)->vbox));

  AddPageColorSurf(NoteBook);

  AddPageCommands(NoteBook);
  AddPageNetWork(NoteBook);
  AddPageBatch(NoteBook);

  AddPageOthers(NoteBook);
  
  gtk_widget_realize(Wins);

  button = create_button(Wins,"Close");
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_box_pack_start (GTK_BOX( GTK_DIALOG(Wins)->action_area), button, TRUE, TRUE, 0);
  g_signal_connect_swapped(GTK_OBJECT(button), "clicked",(GtkSignalFunc)destroy_preferences_window,GTK_OBJECT(Wins));
  gtk_widget_show_all (button);

  button = create_button(Wins,"Save&Apply&Close");
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_box_pack_start (GTK_BOX( GTK_DIALOG(Wins)->action_area), button, TRUE, TRUE, 0);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(apply_all),NULL);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(create_ressource_file),NULL);
  g_signal_connect_swapped(GTK_OBJECT(button), "clicked",(GtkSignalFunc)destroy_preferences_window,GTK_OBJECT(Wins));
  gtk_widget_grab_default(button);
  gtk_widget_show_all (button);

  button = create_button(Wins,"Apply&Close");
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_box_pack_start (GTK_BOX( GTK_DIALOG(Wins)->action_area), button, TRUE, TRUE, 0);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(apply_all),NULL);
  g_signal_connect_swapped(GTK_OBJECT(button), "clicked",(GtkSignalFunc)destroy_preferences_window,GTK_OBJECT(Wins));
  gtk_widget_grab_default(button);
  gtk_widget_show_all (button);

  button = create_button(Wins,"Apply");
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_box_pack_start (GTK_BOX( GTK_DIALOG(Wins)->action_area), button, TRUE, TRUE, 0);
  g_signal_connect(G_OBJECT(button), "clicked",GTK_SIGNAL_FUNC(apply_all),NULL);
  gtk_widget_grab_default(button);
  gtk_widget_show_all (button);


  gtk_widget_show(Wins);
  
}
