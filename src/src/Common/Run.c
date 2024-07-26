/* Run.c */
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


#include "../../Config.h"
#include <stdlib.h>
#include <glib.h>

#include <unistd.h>

#include <ctype.h>

#include "../Common/Global.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Utils.h"
#include "../Utils/Constantes.h"
#include "../Utils/GabeditTextEdit.h"
#include "../Common/Windows.h"
#include "../Files/ListeFiles.h"
#include "../Files/FileChooser.h"
#include "../Files/GabeditFolderChooser.h"
#include "../NetWork/RemoteCommand.h"
#include "../NetWork/FilesTransfer.h"
#include "../Molcas/MolcasVariables.h"

#include "../../pixmaps/Open.xpm"

static GtkWidget* ButtonLocal = NULL;
static GtkWidget* ButtonRemote = NULL;

static GtkWidget* ButtonGauss = NULL;
static GtkWidget* ButtonMolcas = NULL;
static GtkWidget* ButtonMolpro = NULL;
static GtkWidget* ButtonMPQC = NULL;
static GtkWidget* ButtonOther = NULL;
static GtkWidget* EntryFileData = NULL;
static GtkWidget* EntryCommand = NULL;
static GtkWidget* ComboCommand = NULL;
static GtkWidget* FrameRemote = NULL;
static GtkWidget* FrameNetWork = NULL;
static GtkWidget* LabelDataFile = NULL;
static GtkWidget* EntryLocalDir = NULL;
static GtkWidget* LabelPassWord1 = NULL;
static GtkWidget* LabelPassWord2 = NULL;
static GtkWidget* EntryPassWord = NULL;
static gint typeButton[4] = {0, 1, 2, 3}; /* local, remote, ftp, ssh */
/********************************************************************************/
void set_frame_remote_visibility(GtkWidget *button,gpointer data)
{
	gint* type = NULL;

	if(!button) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)button) & GTK_IN_DESTRUCTION)) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)FrameRemote) & GTK_IN_DESTRUCTION)) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)FrameNetWork) & GTK_IN_DESTRUCTION)) return;

	type = g_object_get_data (G_OBJECT (button), "TypeButton");
	if(!type) return;

	if(*type == typeButton[0] )
	{
		if(GTK_IS_WIDGET(FrameRemote)) gtk_widget_set_sensitive(FrameRemote, FALSE);
		if(GTK_IS_WIDGET(FrameNetWork)) gtk_widget_set_sensitive(FrameNetWork, FALSE);
	}
	else
	if(*type == typeButton[1] )
	{
		if(GTK_IS_WIDGET(FrameRemote)) gtk_widget_set_sensitive(FrameRemote, TRUE);
		if(GTK_IS_WIDGET(FrameNetWork)) gtk_widget_set_sensitive(FrameNetWork, TRUE);
	}
	else
	if(*type == typeButton[2] )
	{
		if(GTK_IS_WIDGET(LabelPassWord1)) gtk_widget_set_sensitive(LabelPassWord1, TRUE);
		if(GTK_IS_WIDGET(LabelPassWord2)) gtk_widget_set_sensitive(LabelPassWord2, TRUE);
		if(GTK_IS_WIDGET(EntryPassWord)) gtk_widget_set_sensitive(EntryPassWord, TRUE);
	}
	else
	if(*type == typeButton[3] )
	{
#ifdef G_OS_WIN32
#else
		if(GTK_IS_WIDGET(LabelPassWord1)) gtk_widget_set_sensitive(LabelPassWord1, FALSE);
		if(GTK_IS_WIDGET(LabelPassWord2)) gtk_widget_set_sensitive(LabelPassWord2, FALSE);
		if(GTK_IS_WIDGET(EntryPassWord)) gtk_widget_set_sensitive(EntryPassWord, FALSE);
#endif
	}
}
/********************************************************************************/
void set_default_entrys(GtkWidget *button,gpointer data)
{
	GList *glist = NULL;
	gint i;

	if (GTK_TOGGLE_BUTTON (button)->active)
	{
		if(button == ButtonGauss )
		{
  			for(i=0;i<gaussianCommands.numberOfCommands;i++)
				glist = g_list_append(glist,gaussianCommands.commands[i]);

  			gtk_combo_box_entry_set_popdown_strings( ComboCommand, glist) ;

  			g_list_free(glist);
			gtk_entry_set_text (GTK_ENTRY (EntryCommand), NameCommandGaussian);
			if(fileopen.command) gtk_entry_set_text (GTK_ENTRY (EntryCommand), fileopen.command);
			gtk_widget_show(LabelDataFile);
		}
		else
		if(button == ButtonMPQC)
		{
  			for(i=0;i<mpqcCommands.numberOfCommands;i++)
				glist = g_list_append(glist,mpqcCommands.commands[i]);

  			gtk_combo_box_entry_set_popdown_strings( ComboCommand, glist) ;

  			g_list_free(glist);
			gtk_entry_set_text (GTK_ENTRY (EntryCommand), NameCommandMPQC);
			if(fileopen.command && strlen(fileopen.command)>0) gtk_entry_set_text (GTK_ENTRY (EntryCommand), fileopen.command);
			gtk_widget_show(LabelDataFile);
		}
		else
		if(button == ButtonMolcas)
		{
  			for(i=0;i<molcasCommands.numberOfCommands;i++)
				glist = g_list_append(glist,molcasCommands.commands[i]);

  			gtk_combo_box_entry_set_popdown_strings( ComboCommand, glist) ;

  			g_list_free(glist);
			gtk_entry_set_text (GTK_ENTRY (EntryCommand), NameCommandMolcas);
			if(fileopen.command && strlen(fileopen.command)>0) gtk_entry_set_text (GTK_ENTRY (EntryCommand), fileopen.command);
			gtk_widget_show(LabelDataFile);
		}
		else
		if(button == ButtonMolpro )
		{
  			for(i=0;i<molproCommands.numberOfCommands;i++)
				glist = g_list_append(glist,molproCommands.commands[i]);

  			gtk_combo_box_entry_set_popdown_strings( ComboCommand, glist) ;

  			g_list_free(glist);
			gtk_entry_set_text (GTK_ENTRY (EntryCommand), NameCommandMolpro);
			if(fileopen.command && strlen(fileopen.command)>0) gtk_entry_set_text (GTK_ENTRY (EntryCommand), fileopen.command);
			gtk_widget_show(LabelDataFile);
		}
		else
		{
#ifdef G_OS_WIN32
			gtk_entry_set_text (GTK_ENTRY (EntryCommand), "type");
			glist = g_list_append(glist,"type");
			glist = g_list_append(glist,"ls -l");
#else
			gtk_entry_set_text (GTK_ENTRY (EntryCommand), "ls -l");
			glist = g_list_append(glist,"ls -l");
#endif
  			gtk_combo_box_entry_set_popdown_strings( ComboCommand, glist) ;
			if(fileopen.command && strlen(fileopen.command)>0) gtk_entry_set_text (GTK_ENTRY (EntryCommand), fileopen.command);
			gtk_widget_hide(LabelDataFile);
  			g_list_free(glist);
		}

	}

}
/********************************************************************************/
GtkWidget* create_text_result_command(GtkWidget* Text[],GtkWidget* Frame[],gchar* title)
{
  GtkWidget *Win;
  GtkWidget *frame;
  GtkWidget *hbox;
  GtkWidget *vboxall;
  GtkWidget *vboxwin;
  GtkWidget *button;


  /* Principal Window */
  Win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(Win),title);
  gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
  gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(Fenetre));
  gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

  gtk_widget_realize(Win);
  init_child(Win,gtk_widget_destroy," Run ");
  g_signal_connect(G_OBJECT(Win),"delete_event",(GtkSignalFunc)destroy_childs,NULL);

  gtk_container_set_border_width (GTK_CONTAINER (Win), 5);
  vboxall = create_vbox(Win);
  vboxwin = vboxall;

  frame = gtk_frame_new (NULL);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_container_add(GTK_CONTAINER(vboxall),frame);
  gtk_widget_show (frame);
  vboxall = create_vbox(frame);

  Text[0] = create_text_widget(vboxall,"Output",&Frame[0]);
  set_font (Text[0],FontsStyleResult.fontname);
  set_base_style(Text[0],FontsStyleResult.BaseColor.red ,FontsStyleResult.BaseColor.green ,FontsStyleResult.BaseColor.blue);
  set_text_style(Text[0],FontsStyleResult.TextColor.red ,FontsStyleResult.TextColor.green ,FontsStyleResult.TextColor.blue);
  Text[1] = create_text_widget(vboxall,"Error",&Frame[1]);
  set_font (Text[1],FontsStyleResult.fontname);
  set_base_style(Text[1],FontsStyleResult.BaseColor.red ,FontsStyleResult.BaseColor.green ,FontsStyleResult.BaseColor.blue);
  set_text_style(Text[1],FontsStyleResult.TextColor.red ,0,0);
  /* boutons box */
  hbox = gtk_hbox_new (FALSE, 4);
  gtk_box_pack_start (GTK_BOX(vboxwin), hbox, FALSE, FALSE, 5);
  gtk_box_set_homogeneous(GTK_BOX(hbox), FALSE);
  gtk_widget_realize(Win);
  button = create_button(Win,"OK");
  gtk_box_pack_end (GTK_BOX( hbox), button, FALSE, FALSE, 5);
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_widget_grab_default(button);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)destroy_childs,G_OBJECT(Win));
  gtk_widget_show (button);
  gtk_window_set_default_size (GTK_WINDOW(Win), 3*ScreenWidth/5, 3*ScreenHeight/5);
  gtk_widget_set_size_request(GTK_WIDGET(Text[0]),-1,1*ScreenHeight/5);
  return Win;
}
/********************************************************************************/
void put_text_in_texts_widget(GtkWidget* Text[],gchar* fout,gchar* ferr)
{  
  gchar *strout;
  gchar *strerr;
  strout = cat_file(fout,TRUE);
  strerr = cat_file(ferr,TRUE);
  if(strout)
 {
	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,strout,-1);   
	g_free(strout);
 }
 if(strerr)
 {
 	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,strerr,-1);   
	g_free(strerr);
 }
 else
 {
 	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"Ok",-1);   
 }
}
/********************************************************************************/
void get_file_frome_remote_host(GtkWidget* wid,gpointer data)
{
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);

  GtkWidget* Text[2];
  gchar* temp = NULL;
  gint type = *((gint*)data);

  Text[0] = TextOutput;
  Text[1] = TextError;
  gtk_notebook_set_current_page((GtkNotebook*)NoteBookInfo,1);     
  ClearText(Text[0]);
  ClearText(Text[1]);

/*  Debug("Begin get_file_freom\n");*/
  while( gtk_events_pending() )
          gtk_main_iteration();


  if(fileopen.remotepass)
	g_free(fileopen.remotepass);
  fileopen.remotepass = g_strdup(gtk_entry_get_text(GTK_ENTRY(ResultEntryPass)));
  switch(type)
  {
  case ALLFILES :
  case LOGFILE :
  	/* get file.log */
/*	Debug("Get File frome remote : %s %s %s %s \n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir,fileopen.logfile);*/
  	get_file(fout,ferr,fileopen.logfile,fileopen.localdir,fileopen.remotedir,
  		fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
/*	Debug("End get_file\n");*/
/*	Debug("End Get File frome remote : %s %s %s %s \n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir,fileopen.logfile);*/
	temp = g_strdup_printf("\nGet %s file from remote host :\n",fileopen.logfile);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);   
	g_free(temp);
  	put_text_in_texts_widget(Text,fout,ferr);
  	view_result(NULL,NULL);
	if(type==LOGFILE || iprogram == PROG_IS_GAUSS)
		break;
  case OUTFILE :
  	/* get file.out */
/*	Debug("Get File frome remote : %s %s %s %s \n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir,fileopen.outputfile);*/
  	get_file(fout,ferr,fileopen.outputfile,fileopen.localdir,fileopen.remotedir,
  		fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
/*	Debug("End Get File frome remote : %s %s %s %s \n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir,fileopen.outputfile);*/
	temp = g_strdup_printf("\nGet %s file from remote host :\n",fileopen.outputfile);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);   
	g_free(temp);
  	put_text_in_texts_widget(Text,fout,ferr);
  	view_result(NULL,NULL);
	if(type==OUTFILE)
		break;
  case MOLDENFILE :
  	/* get file.molden */
/*	Debug("Get File frome remote : %s %s %s %s \n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir,fileopen.moldenfile);*/
	
	if(iprogram == PROG_IS_GAUSS)
  	get_file(fout,ferr,fileopen.moldenfile,fileopen.localdir,fileopen.remotedir,
  		fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
	else
	if(iprogram == PROG_IS_MOLCAS)
	{
#ifdef G_OS_WIN32
		{
			gchar filename[BSIZE];
			sprintf(filename,"%s.scf.molden",fileopen.projectname);
  			get_file(fout,ferr,filename,fileopen.localdir,fileopen.remotedir,
  				fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);

			temp = g_strdup_printf("\nGet %s file from remote host :\n",filename);
  			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);
			g_free(temp);
			put_text_in_texts_widget(Text,fout,ferr);



			sprintf(filename,"%s.geomConv.molden",fileopen.projectname);
  			get_file(fout,ferr,filename,fileopen.localdir,fileopen.remotedir,
  				fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
			temp = g_strdup_printf("\nGet %s file from remote host :\n",filename);
  			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);
			g_free(temp);
			put_text_in_texts_widget(Text,fout,ferr);

			sprintf(filename,"%s.frequence.molden",fileopen.projectname);
  			get_file(fout,ferr,filename,fileopen.localdir,fileopen.remotedir,
  				fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
			temp = g_strdup_printf("\nGet %s file from remote host :\n",filename);
  			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);
			g_free(temp);
			put_text_in_texts_widget(Text,fout,ferr);

			sprintf(filename,"%s.M2Msi",fileopen.projectname);
  			get_file(fout,ferr,filename,fileopen.localdir,fileopen.remotedir,
  				fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
			temp = g_strdup_printf("\nGet %s file from remote host :\n",filename);
  			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);
			g_free(temp);
			put_text_in_texts_widget(Text,fout,ferr);
		}

#else
		if(!strstr(fileopen.moldenfile,"*") || fileopen.netWorkProtocol != GABEDIT_NETWORK_FTP_RSH)
		{
			gchar filename[BSIZE];

  			get_file(fout,ferr,fileopen.moldenfile,fileopen.localdir,fileopen.remotedir,
  				fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
			temp = g_strdup_printf("\nGet %s file from remote host :\n",fileopen.moldenfile);
  			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);
			g_free(temp);
			put_text_in_texts_widget(Text,fout,ferr);

			sprintf(filename,"%s.M2Msi",fileopen.projectname);
  			get_file(fout,ferr,filename,fileopen.localdir,fileopen.remotedir,
  				fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
			temp = g_strdup_printf("\nGet %s file from remote host :\n",filename);
  			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);
			g_free(temp);
			put_text_in_texts_widget(Text,fout,ferr);


		}
		else
		{
			gchar filename[BSIZE];
			sprintf(filename,"%s.scf.molden",fileopen.projectname);
  			get_file(fout,ferr,filename,fileopen.localdir,fileopen.remotedir,
  				fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);

			temp = g_strdup_printf("\nGet %s file from remote host :\n",filename);
  			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);
			g_free(temp);
			put_text_in_texts_widget(Text,fout,ferr);

			sprintf(filename,"%s.geomConv.molden",fileopen.projectname);
  			get_file(fout,ferr,filename,fileopen.localdir,fileopen.remotedir,
  				fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);

			temp = g_strdup_printf("\nGet %s file from remote host :\n",filename);
			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);
			g_free(temp);
			put_text_in_texts_widget(Text,fout,ferr);


			sprintf(filename,"%s.frequence.molden",fileopen.projectname);
  			get_file(fout,ferr,filename,fileopen.localdir,fileopen.remotedir,
  				fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
			temp = g_strdup_printf("\nGet %s file from remote host :\n",filename);
  			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);
			g_free(temp);
			put_text_in_texts_widget(Text,fout,ferr);

			sprintf(filename,"%s.M2Msi",fileopen.projectname);
  			get_file(fout,ferr,filename,fileopen.localdir,fileopen.remotedir,
  				fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
			temp = g_strdup_printf("\nGet %s file from remote host :\n",filename);
  			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);
			g_free(temp);
			put_text_in_texts_widget(Text,fout,ferr);

		}
#endif
	}
	else
	if(iprogram == PROG_IS_MOLPRO)
	{
		g_strdown(fileopen.moldenfile);
  		get_file(fout,ferr,fileopen.moldenfile,fileopen.localdir,fileopen.remotedir,
  		fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
		temp = g_strdup_printf("\nGet %s file from remote host :\n",fileopen.moldenfile);
  		gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,temp,-1);   
  		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,temp,-1);   
		g_free(temp);
  		put_text_in_texts_widget(Text,fout,ferr);

	}
/*	Debug("End Get File frome remote : %s %s %s %s \n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir,fileopen.moldenfile);*/
  }

  g_free(fout);
  g_free(ferr);
}
/***********************************************************************************************************/
static gboolean create_cmd_gaussian(G_CONST_RETURN gchar* command, gboolean local, gchar* cmddir, gchar* cmdfile, gchar* cmdall)
{
        FILE* fcmd = NULL;
#ifndef G_OS_WIN32
	gchar buffer[BSIZE];
#endif

	if(local)
  		sprintf(cmddir,"%s", fileopen.localdir);
	else
		sprintf(cmddir,"%s%stmp", gabedit_directory(), G_DIR_SEPARATOR_S);

#ifndef G_OS_WIN32
	sprintf(cmdfile,"%s.cmd", fileopen.projectname);
#else
	if(!local)
		sprintf(cmdfile,"%s.cmd", fileopen.projectname);
	else
		sprintf(cmdfile,"%s.bat", fileopen.projectname);
#endif
  	sprintf(cmdall,"%s%s%s",cmddir,G_DIR_SEPARATOR_S,cmdfile);


  	fcmd = FOpen(cmdall, "w");
	if(!fcmd)
	{
		if(local)
  			Message("\nI can not create cmd file\n ","Error",TRUE);   
		return FALSE;
	}

	if(local)
		fprintf(fcmd,"cd %s\n", fileopen.localdir);
	else
		fprintf(fcmd,"cd %s\n", fileopen.remotedir);


#ifndef G_OS_WIN32
	fprintf(fcmd,"%s %s &\n",command,fileopen.datafile);
	fprintf(fcmd,"exit\n");
#else
	 if(!local)
	 {
		 fprintf(fcmd,"%s %s &\n",command,fileopen.datafile);
		 fprintf(fcmd,"exit\n");
	 }
	 else
		 fprintf(fcmd,"%s %s \n",command,fileopen.datafile);

#endif
	fclose(fcmd);
#ifndef G_OS_WIN32
  	sprintf(buffer,"chmod u+x %s",cmdall);
	system(buffer);
#endif
	return TRUE;
}
/***********************************************************************************************************/
static gboolean create_cmd_molcas(G_CONST_RETURN gchar* command, gboolean local, gchar* cmddir, gchar* cmdfile, gchar* cmdall)
{
        FILE* fcmd = NULL;
	gchar buffer[BSIZE];
	gint i;

	if(local)
  		sprintf(cmddir,"%s", fileopen.localdir);
	else
		sprintf(cmddir,"%s%stmp", gabedit_directory(), G_DIR_SEPARATOR_S);

#ifndef G_OS_WIN32
	sprintf(cmdfile,"%s.cmd", fileopen.projectname);
#else
	if(!local)
		sprintf(cmdfile,"%s.cmd", fileopen.projectname);
	else
		sprintf(cmdfile,"%s.bat", fileopen.projectname);
#endif

  	sprintf(cmdall,"%s%s%s",cmddir,G_DIR_SEPARATOR_S,cmdfile);


  	fcmd = FOpen(cmdall, "w");
	if(!fcmd)
	{
		if(local)
  			Message("\nI can not create cmd file\n ","Error",TRUE);   
		return FALSE;
	}

#ifndef G_OS_WIN32
	fprintf(fcmd,"#! /bin/sh\n");
	fprintf(fcmd,"#********************************************\n");
	fprintf(fcmd,"# file created by Gabedit\n");
	fprintf(fcmd,"#********************************************\n");
	if(!molcasTrap())
	{
		fprintf(fcmd,"MOLCAS_TRAP='OFF'\n");
		fprintf(fcmd,"export MOLCAS_TRAP\n");
	}
	i = molcasMem();
	if(i>=0)
	{
		fprintf(fcmd,"MOLCASMEM=%d\n",i);
		fprintf(fcmd,"export MOLCASMEM\n");
	}
	i = molcasDisk();
	if(i>=0)
	{
		fprintf(fcmd,"MOLCASDISK=%d\n",i);
		fprintf(fcmd,"export MOLCASDISK\n");
	}
	i = molcasRamd();
	if(i>=0)
	{
		fprintf(fcmd,"MOLCASRAMD=%d\n",i);
		fprintf(fcmd,"export MOLCASRAMD\n");
	}

	molcasWorkDir(buffer);
	if(strcmp(buffer,"Default") != 0)
	{
		fprintf(fcmd,"WorkDir=%s\n",buffer);
		fprintf(fcmd,"export WorkDir\n");
	}

	fprintf(fcmd,"#--------------------------------------------\n");
	fprintf(fcmd,"Project=%s\n", fileopen.projectname);
	fprintf(fcmd,"export Project\n");
	fprintf(fcmd,"#--------------------------------------------\n");
	if(local)
		fprintf(fcmd,"cd %s\n", fileopen.localdir);
	else
		fprintf(fcmd,"cd %s\n", fileopen.remotedir);

	fprintf(fcmd,"%s %s > %s&\n", command, fileopen.datafile, fileopen.outputfile);
	fprintf(fcmd,"exit\n");
	fclose(fcmd);

  	sprintf(buffer,"chmod u+x %s",cmdall);
	system(buffer);
#else
	if(!local)
	{
		fprintf(fcmd,"#! /bin/sh\n");
		fprintf(fcmd,"#********************************************\n");
		fprintf(fcmd,"# file created by Gabedit\n");
		fprintf(fcmd,"#********************************************\n");
		if(!molcasTrap())
		{
			fprintf(fcmd,"MOLCAS_TRAP='OFF'\n");
			fprintf(fcmd,"export MOLCAS_TRAP\n");
		}
		i = molcasMem();
		if(i>=0)
		{
			fprintf(fcmd,"MOLCASMEM=%d\n",i);
			fprintf(fcmd,"export MOLCASMEM\n");
		}
		i = molcasDisk();
		if(i>=0)
		{
			fprintf(fcmd,"MOLCASDISK=%d\n",i);
			fprintf(fcmd,"export MOLCASDISK\n");
		}
		i = molcasRamd();
		if(i>=0)
		{
			fprintf(fcmd,"MOLCASRAMD=%d\n",i);
			fprintf(fcmd,"export MOLCASRAMD\n");
		}

		molcasWorkDir(buffer);
		if(strcmp(buffer,"Default") != 0)
		{
			fprintf(fcmd,"WorkDir=%s\n",buffer);
			fprintf(fcmd,"export WorkDir\n");
		}

		fprintf(fcmd,"#--------------------------------------------\n");
		fprintf(fcmd,"Project=%s\n", fileopen.projectname);
		fprintf(fcmd,"export Project\n");
		fprintf(fcmd,"#--------------------------------------------\n");
		if(local)
			fprintf(fcmd,"cd %s\n", fileopen.localdir);
		else
			fprintf(fcmd,"cd %s\n", fileopen.remotedir);

		fprintf(fcmd,"%s %s > %s&\n", command, fileopen.datafile, fileopen.outputfile);
		fprintf(fcmd,"exit\n");
		fclose(fcmd);
	}
	else
	{
		fprintf(fcmd,"@echo off\n");
		fprintf(fcmd,"@rem ********************************************\n");
		fprintf(fcmd,"@rem  file created by Gabedit\n");
		fprintf(fcmd,"@rem  *******************************************\n");
		if(!molcasTrap())
		{
			fprintf(fcmd,"set MOLCAS_TRAP='OFF'\n");
			
		}
		i = molcasMem();
		if(i>=0)
		{
			fprintf(fcmd,"set MOLCASMEM=%d\n",i);
		}
		i = molcasDisk();
		if(i>=0)
		{
			fprintf(fcmd,"set MOLCASDISK=%d\n",i);
		}
		i = molcasRamd();
		if(i>=0)
		{
			fprintf(fcmd,"set MOLCASRAMD=%d\n",i);
		}

		molcasWorkDir(buffer);
		if(strcmp(buffer,"Default") != 0)
		{
			fprintf(fcmd,"set WorkDir=%s\n",buffer);
		}

		fprintf(fcmd,"@rem --------------------------------------------\n");
		fprintf(fcmd,"set Project=%s\n", fileopen.projectname);
		fprintf(fcmd,"@rem --------------------------------------------\n");
		if(local)
			fprintf(fcmd,"cd %s\n", fileopen.localdir);
		else
			fprintf(fcmd,"cd %s\n", fileopen.remotedir);

		fprintf(fcmd,"%s %s > %s\n", command, fileopen.datafile, fileopen.outputfile);
		fclose(fcmd);

	}

#endif

	return TRUE;
}
/***********************************************************************************************************/
static gboolean create_cmd_molpro(G_CONST_RETURN gchar* command, gboolean local, gchar* cmddir, gchar* cmdfile, gchar* cmdall)
{
        FILE* fcmd = NULL;
#ifndef G_OS_WIN32
	gchar buffer[BSIZE];
#endif

	if(local)
  		sprintf(cmddir,"%s", fileopen.localdir);
	else
		sprintf(cmddir,"%s%stmp", gabedit_directory(), G_DIR_SEPARATOR_S);

#ifndef G_OS_WIN32
	sprintf(cmdfile,"%s.cmd", fileopen.projectname);
#else
	if(!local)
		sprintf(cmdfile,"%s.cmd", fileopen.projectname);
	else
		sprintf(cmdfile,"%s.bat", fileopen.projectname);
#endif

  	sprintf(cmdall,"%s%s%s",cmddir,G_DIR_SEPARATOR_S,cmdfile);


  	fcmd = FOpen(cmdall, "w");
	if(!fcmd)
	{
		if(local)
  			Message("\nI can not create cmd file\n ","Error",TRUE);   
		return FALSE;
	}

	if(local)
		fprintf(fcmd,"cd %s\n", fileopen.localdir);
	else
		fprintf(fcmd,"cd %s\n", fileopen.remotedir);

#ifndef G_OS_WIN32
	fprintf(fcmd,"%s %s &\n",command,fileopen.datafile);
	fprintf(fcmd,"exit\n");
	fclose(fcmd);
  	sprintf(buffer,"chmod u+x %s",cmdall);
	system(buffer);
#else
	if(!local)
	{
		fprintf(fcmd,"%s %s &\n",command,fileopen.datafile);
		fprintf(fcmd,"exit\n");
		fclose(fcmd);
	}
	else
	{
		fprintf(fcmd,"%s %s \n",command,fileopen.datafile);
		fclose(fcmd);
	}
#endif
	return TRUE;
}
/***********************************************************************************************************/
static gboolean create_cmd_mpqc(G_CONST_RETURN gchar* command, gboolean local, gchar* cmddir, gchar* cmdfile, gchar* cmdall)
{
        FILE* fcmd = NULL;
#ifndef G_OS_WIN32
	gchar buffer[BSIZE];
#endif

	if(local)
  		sprintf(cmddir,"%s", fileopen.localdir);
	else
		sprintf(cmddir,"%s%stmp", gabedit_directory(), G_DIR_SEPARATOR_S);

#ifndef G_OS_WIN32
	sprintf(cmdfile,"%s.cmd", fileopen.projectname);
#else
	if(!local)
		sprintf(cmdfile,"%s.cmd", fileopen.projectname);
	else
		sprintf(cmdfile,"%s.bat", fileopen.projectname);
#endif
  	sprintf(cmdall,"%s%s%s",cmddir,G_DIR_SEPARATOR_S,cmdfile);


  	fcmd = FOpen(cmdall, "w");
	if(!fcmd)
	{
		if(local)
  			Message("\nI can not create cmd file\n ","Error",TRUE);   
		return FALSE;
	}

	if(local)
		fprintf(fcmd,"cd %s\n", fileopen.localdir);
	else
		fprintf(fcmd,"cd %s\n", fileopen.remotedir);


#ifndef G_OS_WIN32
	fprintf(fcmd,"%s %s > %s &\n",command,fileopen.datafile, fileopen.outputfile);
	fprintf(fcmd,"exit\n");
#else
	 if(!local)
	 {
		 fprintf(fcmd,"%s %s > %s &\n",command,fileopen.datafile, fileopen.outputfile);
		 fprintf(fcmd,"exit\n");
	 }
	 else
		 fprintf(fcmd,"%s %s > %s\n",command,fileopen.datafile, fileopen.outputfile);

#endif
	fclose(fcmd);
#ifndef G_OS_WIN32
  	sprintf(buffer,"chmod u+x %s",cmdall);
	system(buffer);
#endif
	return TRUE;
}
/***********************************************************************************************************/
static gboolean create_cmd_other(G_CONST_RETURN gchar* command, gboolean local, gchar* cmddir, gchar* cmdfile, gchar* cmdall)
{
        FILE* fcmd = NULL;
#ifndef G_OS_WIN32
	gchar buffer[BSIZE];
#endif

	if(local)
  		sprintf(cmddir,"%s", fileopen.localdir);
	else
		sprintf(cmddir,"%s%stmp", gabedit_directory(), G_DIR_SEPARATOR_S);

  	sprintf(cmdfile,"%s.cmd", fileopen.projectname);
  	sprintf(cmdall,"%s%s%s",cmddir,G_DIR_SEPARATOR_S,cmdfile);


  	fcmd = FOpen(cmdall, "w");
	if(!fcmd)
	{
		if(local)
  			Message("\nI can not create cmd file\n ","Error",TRUE);   
		return FALSE;
	}

	if(local)
		fprintf(fcmd,"cd %s\n", fileopen.localdir);
	else
		fprintf(fcmd,"cd %s\n", fileopen.remotedir);

#ifndef G_OS_WIN32
	fprintf(fcmd,"%s\n",command);
	fprintf(fcmd,"exit\n");
	fclose(fcmd);
  	sprintf(buffer,"chmod u+x %s",cmdall);
	system(buffer);
#else
	if(!local)
	{
		fprintf(fcmd,"%s\n",command);
		fprintf(fcmd,"exit\n");
		fclose(fcmd);
	}
	else
	{
		fprintf(fcmd,"%s\n",command);
		fclose(fcmd);
	}
#endif
	return TRUE;
}
/********************************************************************************/
static void run_remote_gaussian(GtkWidget *b,gpointer data)
{  
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar cmdfile[BSIZE];
  gchar cmddir[BSIZE];
  gchar cmdall[BSIZE];

  GtkWidget* Win;
  GtkWidget* Text[2];
  GtkWidget* Frame[2];
  gchar *temp;
  gchar *NomFichier;
  gchar *Command;
  FILE *fd;
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext0;
  gchar *entrytext;
  gchar* title;
  gint code = 0;
  G_CONST_RETURN gchar *localdir;


  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));
  localdir = gtk_entry_get_text(GTK_ENTRY(EntryLocalDir));
  entrytext = get_dir_file_name(localdir,entrytext0);

  temp = get_suffix_name_file(entrytext);
  fileopen.projectname = get_name_file(temp);
  fileopen.localdir = get_name_dir(temp);
  g_free(temp);
  fileopen.datafile = g_strdup_printf("%s.com",fileopen.projectname);
  fileopen.outputfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.logfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.moldenfile=g_strdup_printf("%s.log",fileopen.projectname);

  fileopen.remotehost = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[2])));
  fileopen.remoteuser = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[3])));
  fileopen.remotepass  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[4])));
  fileopen.remotedir  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[5])));
  fileopen.command  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[1])));

  /* fileopen.netWorkProtocol Deja defini dans run_program*/
  
/*   Debug("remote gauss : %s %s %s\n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir);*/

  /* save file */
   NomFichier = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.datafile);
  
  CreeFeuille(treeViewProjects, noeud[GABEDIT_TYPENODE_GAUSSIAN],fileopen.projectname,fileopen.datafile,fileopen.localdir,
			fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir,GABEDIT_TYPENODE_GAUSSIAN, fileopen.command, fileopen.netWorkProtocol); 
  add_host(fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir);

/* Save file in local host */
  fd = FOpen(NomFichier, "w");
  if(fd == NULL)
  {
	  Message("Sorry, I can not save file","Error",TRUE);
	  return;
  }
  temp=gabedit_text_get_chars(text,0,-1);
  fprintf(fd,"%s",temp);
  fclose(fd);

  data_modify(FALSE);

  entry=entryall[1];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));

  title = g_strdup_printf("Run Gaussian at host :%s, Login : %s",fileopen.remotehost,fileopen.remoteuser); 
  Win = create_text_result_command(Text,Frame,title);
  g_free(title);
  gtk_widget_show_all(Win);
  while( gtk_events_pending() ) gtk_main_iteration();
  gtk_widget_set_sensitive(Win, FALSE);

  if(!this_is_a_backspace(fileopen.remotedir))
  {
	/* Make Working directory */
	/*  Debug("Make dir remote gauss : %s %s %s\n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir);*/
  	Command = g_strdup_printf("mkdir %s",fileopen.remotedir);
  	/*rsh (fout,ferr,Command,fileopen.remoteuser,fileopen.remotehost);*/
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	g_free(Command);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nMake Working  Directory  remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nMake Working  Directory  remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }

  if(code == 0)
  {
	/* put file.com */
	/*  Debug("Put File remote gauss : %s %s %s\n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir);*/
  	code = put_file(fout,ferr,fileopen.datafile,fileopen.localdir,fileopen.remotedir,
		  	fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nPut Data File at remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nPut Data File at remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if( code==0 )
  {
        if(!create_cmd_gaussian(entrytext0, FALSE, cmddir, cmdfile, cmdall))
	{
  		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL, "\nI can not create cmd file\n ",-1);   
  		gtk_widget_set_sensitive(Win, TRUE);
		return;
	}
	code = 0;
	  
  }
  if(code == 0)
  {
  	code = put_file(fout,ferr,cmdfile,cmddir,"./",
		  	fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nPut CMD File at remote host :\n ",-1); 
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nPut CMD File at remote host :\n ",-1);
  	put_text_in_texts_widget(Text,fout,ferr);
	unlink(cmdall);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if(code == 0)
  {
  	Command = g_strdup_printf("chmod u+x %s",cmdfile);
  	/*rsh (fout,ferr,Command,fileopen.remoteuser,fileopen.remotehost);*/
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nchmod for cmd file :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nchmod for cmd file :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if(code == 0)
  {
  	Command = g_strdup_printf("./%s>/dev/null&",cmdfile);
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nRun gaussian at remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nRun gaussian at remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  gtk_widget_set_sensitive(Win, TRUE);

  g_free(fout);
  g_free(ferr);
}
/********************************************************************************/
static void run_remote_molcas(GtkWidget *b,gpointer data)
{  
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar cmdfile[BSIZE];
  gchar cmddir[BSIZE];
  gchar cmdall[BSIZE];

  GtkWidget* Win;
  GtkWidget* Text[2];
  GtkWidget* Frame[2];
  gchar *temp;
  gchar *NomFichier;
  gchar *Command;
  FILE *fd;
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext0;
  gchar *entrytext;
  gchar* title;
  gint code = 0;
  G_CONST_RETURN gchar *localdir;


  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));
  localdir = gtk_entry_get_text(GTK_ENTRY(EntryLocalDir));
  entrytext = get_dir_file_name(localdir,entrytext0);

  temp = get_suffix_name_file(entrytext);
  fileopen.projectname = get_name_file(temp);
  fileopen.localdir = get_name_dir(temp);
  
  g_free(temp);
  fileopen.datafile = g_strdup_printf("%s.com",fileopen.projectname);
  fileopen.outputfile=g_strdup_printf("%s.out",fileopen.projectname);
  fileopen.logfile=g_strdup_printf("%s.log",fileopen.projectname);
  /* fileopen.moldenfile=g_strdup_printf("%s.molden",fileopen.projectname);*/
  fileopen.moldenfile=g_strdup_printf("'%s.*.molden'", fileopen.projectname);

  fileopen.remotehost = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[2])));
  fileopen.remoteuser = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[3])));
  fileopen.remotepass  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[4])));
  fileopen.remotedir  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[5])));
  fileopen.command  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[1])));
  /* fileopen.netWorkProtocol Deja defini dans run_program*/
  
/*   Debug("remote molcas : %s %s %s\n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir);*/

  /* save file */
   NomFichier = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.datafile);
  
  CreeFeuille(treeViewProjects, noeud[GABEDIT_TYPENODE_MOLCAS],fileopen.projectname,fileopen.datafile,fileopen.localdir,
			fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir,GABEDIT_TYPENODE_MOLCAS, fileopen.command, fileopen.netWorkProtocol); 
  add_host(fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir);

/* Save file in local host */
  fd = FOpen(NomFichier, "w");
  if(fd == NULL)
  {
	  Message("Sorry, I can not save file","Error",TRUE);
	  return;
  }
  temp=gabedit_text_get_chars(text,0,-1);
  fprintf(fd,"%s",temp);
  fclose(fd);

  data_modify(FALSE);

  entry=entryall[1];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));

  title = g_strdup_printf("Run molcas at host :%s, Login : %s",fileopen.remotehost,fileopen.remoteuser); 
  Win = create_text_result_command(Text,Frame,title);
  g_free(title);
  gtk_widget_show_all(Win);
  while( gtk_events_pending() ) gtk_main_iteration();
  gtk_widget_set_sensitive(Win, FALSE);

  if(!this_is_a_backspace(fileopen.remotedir))
  {
	/* Make Working directory */
	/*  Debug("Make dir remote molcas : %s %s %s\n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir);*/
  	Command = g_strdup_printf("mkdir %s",fileopen.remotedir);
  	/*rsh (fout,ferr,Command,fileopen.remoteuser,fileopen.remotehost);*/
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	g_free(Command);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nMake Working  Directory  remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nMake Working  Directory  remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }

  if(code == 0)
  {
	/* put file.com */
	/*  Debug("Put File remote molcas : %s %s %s\n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir);*/
  	code = put_file(fout,ferr,fileopen.datafile,fileopen.localdir,fileopen.remotedir,
		  	fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nPut Data File at remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nPut Data File at remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if( code==0 )
  {
        if(!create_cmd_molcas(entrytext0, FALSE, cmddir, cmdfile, cmdall))
	{
  		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL, "\nI can not create cmd file\n ",-1);   
  		gtk_widget_set_sensitive(Win, TRUE);
		return;
	}
	code = 0;
  }
  if(code == 0)
  {
  	code = put_file(fout,ferr,cmdfile,cmddir,"./",
		  	fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nPut CMD File at remote host :\n ",-1); 
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nPut CMD File at remote host :\n ",-1);
  	put_text_in_texts_widget(Text,fout,ferr);
	unlink(cmdall);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if(code == 0)
  {
  	Command = g_strdup_printf("chmod u+x %s",cmdfile);
  	/*rsh (fout,ferr,Command,fileopen.remoteuser,fileopen.remotehost);*/
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nchmod for cmd file :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nchmod for cmd file :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if(code == 0)
  {
  	Command = g_strdup_printf("./%s>/dev/null&",cmdfile);
  	/*rsh (fout,ferr,Command,fileopen.remoteuser,fileopen.remotehost);*/
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nRun molcas at remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nRun molcas at remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
 }
  gtk_widget_set_sensitive(Win, TRUE);

  g_free(fout);
  g_free(ferr);
}
/********************************************************************************/
static void run_remote_molpro(GtkWidget *b,gpointer data)
{  
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar cmdfile[BSIZE];
  gchar cmddir[BSIZE];
  gchar cmdall[BSIZE];

  GtkWidget* Win;
  GtkWidget* Text[2];
  GtkWidget* Frame[2];
  gchar *temp;
  gchar *Tompon;
  gchar *pdest;
  gchar *t;
  gchar *NomFichier;
  gchar *Command;
  FILE *fd;
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext0;
  gchar *entrytext;
  gchar* title;
  gint code = 0;
  G_CONST_RETURN gchar *localdir;


  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));
  localdir = gtk_entry_get_text(GTK_ENTRY(EntryLocalDir));
  entrytext = get_dir_file_name(localdir,entrytext0);

  temp = get_suffix_name_file(entrytext);
  fileopen.projectname = get_name_file(temp);
  fileopen.localdir = get_name_dir(temp);
  /*Debug("localdir = %s\n",fileopen.localdir);*/
  g_free(temp);
  fileopen.datafile = g_strdup_printf("%s.com",fileopen.projectname);
  fileopen.outputfile=g_strdup_printf("%s.out",fileopen.projectname);
  fileopen.logfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.moldenfile=g_strdup_printf("%s.molden",fileopen.projectname);
  g_strdown(fileopen.moldenfile);

  fileopen.remotehost = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[2])));
  fileopen.remoteuser = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[3])));
  fileopen.remotepass  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[4])));
  fileopen.remotedir  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[5])));
  fileopen.command  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[1])));
  /* fileopen.netWorkProtocol Deja defini dans run_program*/
  
/*   Debug("remote molpro : %s %s %s\n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir);*/

  Tompon=gabedit_text_get_chars(text,0,-1);
  pdest = strstr( Tompon, fileopen.moldenfile);
  if( pdest == NULL )
  {
  	pdest = strstr( Tompon,"put,molden");
	if(pdest)
	{
		temp = strstr(pdest,";");
		t = strstr(pdest,"\n");
		if(temp && t && t<temp)
			temp = t;
		if(!temp)
			temp = t;
		if(temp)
		{
/*			Debug("%d\n",(guint)(pdest-Tompon));*/
/*			Debug("%d\n",(guint)(temp-pdest));*/
        		gabedit_text_set_point(GABEDIT_TEXT(text),(guint)(pdest-Tompon));
        		gabedit_text_forward_delete(GABEDIT_TEXT(text),(guint)(temp-pdest+1));
		}
		
	}
	temp = g_strdup_printf("put,molden,%s",fileopen.moldenfile);
	gabedit_text_set_point(GABEDIT_TEXT(text),gabedit_text_get_length(GABEDIT_TEXT(text)));  
  	gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL,temp,-1);
	g_free(temp);
   	gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, "\n",-1);
  }
  if(Tompon != NULL) 
	g_free(Tompon);

  /* save file */
   NomFichier = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.datafile);
  
  CreeFeuille(treeViewProjects, noeud[GABEDIT_TYPENODE_MOLPRO],fileopen.projectname,fileopen.datafile,fileopen.localdir,
			fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir,GABEDIT_TYPENODE_MOLPRO, fileopen.command, fileopen.netWorkProtocol); 
  add_host(fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir);

/* Save file in local host */
  fd = FOpen(NomFichier, "w");
  if(fd == NULL)
  {
	  Message("Sorry, I can not save file","Error",TRUE);
	  return;
  }
  temp=gabedit_text_get_chars(text,0,-1);
  fprintf(fd,"%s",temp);
  fclose(fd);

  data_modify(FALSE);

  entry=entryall[1];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));

  title = g_strdup_printf("Run molpro at host :%s, Login : %s",fileopen.remotehost,fileopen.remoteuser); 
  Win = create_text_result_command(Text,Frame,title);
  g_free(title);
  gtk_widget_show_all(Win);
  while( gtk_events_pending() ) gtk_main_iteration();
  gtk_widget_set_sensitive(Win, FALSE);

  if(!this_is_a_backspace(fileopen.remotedir))
  {
	/* Make Working directory */
	/*  Debug("Make dir remote molpro : %s %s %s\n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir);*/
  	Command = g_strdup_printf("mkdir %s",fileopen.remotedir);
  	/*rsh (fout,ferr,Command,fileopen.remoteuser,fileopen.remotehost);*/
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	g_free(Command);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nMake Working  Directory  remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nMake Working  Directory  remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }

  if(code == 0)
  {
	/* put file.com */
	/*  Debug("Put File remote molpro : %s %s %s\n",fileopen.remotehost,fileopen.remoteuser,fileopen.remotedir);*/
  	code = put_file(fout,ferr,fileopen.datafile,fileopen.localdir,fileopen.remotedir,
		  	fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nPut Data File at remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nPut Data File at remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if( code==0 )
  {
        if(!create_cmd_molpro(entrytext0, FALSE, cmddir, cmdfile, cmdall))
	{
  		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL, "\nI can not create cmd file\n ",-1);   
  		gtk_widget_set_sensitive(Win, TRUE);
		return;
	}
	code = 0;
	  
  }
  if(code == 0)
  {
  	code = put_file(fout,ferr,cmdfile,cmddir,"./",
		  	fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nPut CMD File at remote host :\n ",-1); 
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nPut CMD File at remote host :\n ",-1);
  	put_text_in_texts_widget(Text,fout,ferr);
	unlink(cmdall);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if(code == 0)
  {
  	Command = g_strdup_printf("chmod u+x %s",cmdfile);
  	/*rsh (fout,ferr,Command,fileopen.remoteuser,fileopen.remotehost);*/
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nchmod for cmd file :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nchmod for cmd file :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if(code == 0)
  {
  	Command = g_strdup_printf("./%s>/dev/null&",cmdfile);
  	/*rsh (fout,ferr,Command,fileopen.remoteuser,fileopen.remotehost);*/
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nRun molpro at remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nRun molpro at remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
 }
  gtk_widget_set_sensitive(Win, TRUE);

  g_free(fout);
  g_free(ferr);
}
/********************************************************************************/
static void run_remote_mpqc(GtkWidget *b,gpointer data)
{  
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar cmdfile[BSIZE];
  gchar cmddir[BSIZE];
  gchar cmdall[BSIZE];

  GtkWidget* Win;
  GtkWidget* Text[2];
  GtkWidget* Frame[2];
  gchar *temp;
  gchar *NomFichier;
  gchar *Command;
  FILE *fd;
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext0;
  gchar *entrytext;
  gchar* title;
  gint code = 0;
  G_CONST_RETURN gchar *localdir;


  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));
  localdir = gtk_entry_get_text(GTK_ENTRY(EntryLocalDir));
  entrytext = get_dir_file_name(localdir,entrytext0);

  temp = get_suffix_name_file(entrytext);
  fileopen.projectname = get_name_file(temp);
  fileopen.localdir = get_name_dir(temp);
  g_free(temp);
  fileopen.datafile = g_strdup_printf("%s.com",fileopen.projectname);
  fileopen.outputfile=g_strdup_printf("%s.out",fileopen.projectname);
  fileopen.logfile=g_strdup_printf("%s.out",fileopen.projectname);
  fileopen.moldenfile=g_strdup_printf("%s.molden",fileopen.projectname);

  fileopen.remotehost = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[2])));
  fileopen.remoteuser = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[3])));
  fileopen.remotepass  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[4])));
  fileopen.remotedir  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[5])));
  fileopen.command  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[1])));

  /* save file */
   NomFichier = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.datafile);
  
  CreeFeuille(treeViewProjects, noeud[GABEDIT_TYPENODE_MPQC],fileopen.projectname,fileopen.datafile,fileopen.localdir,
			fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir,GABEDIT_TYPENODE_MPQC, fileopen.command, fileopen.netWorkProtocol); 
  add_host(fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir);

  fd = FOpen(NomFichier, "w");
  if(fd == NULL)
  {
	  Message("Sorry, I can not save file","Error",TRUE);
	  return;
  }
  temp=gabedit_text_get_chars(text,0,-1);
  fprintf(fd,"%s",temp);
  fclose(fd);

  data_modify(FALSE);

  entry=entryall[1];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));

  title = g_strdup_printf("Run MPQC at host :%s, Login : %s",fileopen.remotehost,fileopen.remoteuser); 
  Win = create_text_result_command(Text,Frame,title);
  g_free(title);
  gtk_widget_show_all(Win);
  while( gtk_events_pending() ) gtk_main_iteration();
  gtk_widget_set_sensitive(Win, FALSE);

  if(!this_is_a_backspace(fileopen.remotedir))
  {
	/* Make Working directory */
  	Command = g_strdup_printf("mkdir %s",fileopen.remotedir);
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	g_free(Command);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nMake Working  Directory  remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nMake Working  Directory  remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }

  if(code == 0)
  {
	/* put file.com */
  	code = put_file(fout,ferr,fileopen.datafile,fileopen.localdir,fileopen.remotedir,
		  	fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nPut Data File at remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nPut Data File at remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if( code==0 )
  {
        if(!create_cmd_mpqc(entrytext0, FALSE, cmddir, cmdfile, cmdall))
	{
  		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL, "\nI can not create cmd file\n ",-1);   
  		gtk_widget_set_sensitive(Win, TRUE);
		return;
	}
	code = 0;
	  
  }
  if(code == 0)
  {
  	code = put_file(fout,ferr,cmdfile,cmddir,"./",
		  	fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nPut CMD File at remote host :\n ",-1); 
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nPut CMD File at remote host :\n ",-1);
  	put_text_in_texts_widget(Text,fout,ferr);
	unlink(cmdall);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if(code == 0)
  {
  	Command = g_strdup_printf("chmod u+x %s",cmdfile);
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nchmod for cmd file :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nchmod for cmd file :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if(code == 0)
  {
  	Command = g_strdup_printf("./%s>/dev/null&",cmdfile);
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nRun MPQC at remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nRun MPQC at remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  gtk_widget_set_sensitive(Win, TRUE);
  g_free(fout);
  g_free(ferr);
}
/********************************************************************************/
static void run_remote_other(GtkWidget *b,gpointer data)
{  
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar cmdfile[BSIZE];
  gchar cmddir[BSIZE];
  gchar cmdall[BSIZE];

  GtkWidget* Win;
  GtkWidget* Text[2];
  GtkWidget* Frame[2];
  gchar *temp;
  gchar *NomFichier;
  gchar *Command;
  FILE *fd;
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext0;
  gchar *entrytext;
  gchar* title;
  gint code = 0;
  G_CONST_RETURN gchar *localdir;


  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));
  localdir = gtk_entry_get_text(GTK_ENTRY(EntryLocalDir));
  entrytext = get_dir_file_name(localdir,entrytext0);

  temp = get_suffix_name_file(entrytext);
  fileopen.projectname = get_name_file(temp);
  fileopen.localdir = get_name_dir(temp);
  g_free(temp);
  fileopen.datafile = g_strdup_printf("%s.com",fileopen.projectname);
  fileopen.outputfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.logfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.moldenfile=g_strdup_printf("%s.log",fileopen.projectname);

  fileopen.remotehost = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[2])));
  fileopen.remoteuser = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[3])));
  fileopen.remotepass  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[4])));
  fileopen.remotedir  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[5])));
  fileopen.command  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[1])));
  /* fileopen.netWorkProtocol Deja defini dans run_program*/
  

  /* save file */
   NomFichier = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.datafile);
  
  CreeFeuille(treeViewProjects, noeud[GABEDIT_TYPENODE_OTHER],fileopen.projectname,fileopen.datafile,fileopen.localdir,
			fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir,GABEDIT_TYPENODE_OTHER, fileopen.command, fileopen.netWorkProtocol); 
  add_host(fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir);


  fd = FOpen(NomFichier, "w");
  if(fd == NULL)
  {
	  Message("Sorry, I can not save file","Error",TRUE);
	  return;
  }
  temp=gabedit_text_get_chars(text,0,-1);
  fprintf(fd,"%s",temp);
  fclose(fd);

  data_modify(FALSE);

  entry=entryall[1];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));

  title = g_strdup_printf("Run \"%s %s\" Command  at host : %s, Login : %s", 
		  entrytext0, fileopen.datafile, fileopen.remotehost,fileopen.remoteuser); 
  Win = create_text_result_command(Text,Frame,title);
  g_free(title);
  gtk_widget_show_all(Win);
  while( gtk_events_pending() ) gtk_main_iteration();
  gtk_widget_set_sensitive(Win, FALSE);

  if(!this_is_a_backspace(fileopen.remotedir))
  {
	/* Make Working directory */
  	Command = g_strdup_printf("mkdir %s",fileopen.remotedir);
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	g_free(Command);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nMake Working  Directory  remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nMake Working  Directory  remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }

  if(code == 0)
  {
	/* put file.com */
  	code = put_file(fout,ferr,fileopen.datafile,fileopen.localdir,fileopen.remotedir,
		  	fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nPut Data File at remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nPut Data File at remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if( code==0 )
  {
        if(!create_cmd_other(entrytext0, FALSE, cmddir, cmdfile, cmdall))
	{
  		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL, "\nI can not create cmd file\n ",-1);   
  		gtk_widget_set_sensitive(Win, TRUE);
		return;
	}
	code = 0;
	  
  }
  if(code == 0)
  {
  	code = put_file(fout,ferr,cmdfile,cmddir,"./",
		  	fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nPut CMD File at remote host :\n ",-1); 
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nPut CMD File at remote host :\n ",-1);
  	put_text_in_texts_widget(Text,fout,ferr);
	unlink(cmdall);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if(code == 0)
  {
  	Command = g_strdup_printf("chmod u+x %s",cmdfile);
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nchmod for cmd file :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nchmod for cmd file :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  if(code == 0)
  {
  	Command = g_strdup_printf("./%s>/dev/null&",cmdfile);
  	remote_command (fout,ferr,Command,fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass);
  	gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,"\nRun gaussian at remote host :\n ",-1);   
  	gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,"\nRun gaussian at remote host :\n ",-1);   
  	put_text_in_texts_widget(Text,fout,ferr);
  	while( gtk_events_pending() )
          gtk_main_iteration();
  }
  gtk_widget_set_sensitive(Win, TRUE);
  g_free(fout);
  g_free(ferr);
}
/********************************************************************************/
static void run_local_gaussian(GtkWidget *b,gpointer data)
{  
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);

  GtkWidget* Win;
  GtkWidget* Text[2];
  GtkWidget* Frame[2];
  gchar *strout;
  gchar *strerr;
  gchar *temp;
  gchar *NomFichier;
  gchar Command[BSIZE];
  FILE *fd;
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext0;
  gchar *entrytext;
  gchar* title;
  G_CONST_RETURN gchar *localdir;
  gchar cmdFileAllName[BSIZE];
  gchar cmdDir[BSIZE];
  gchar cmdFile[BSIZE];


  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));
  localdir = gtk_entry_get_text(GTK_ENTRY(EntryLocalDir));
  entrytext = get_dir_file_name(localdir,entrytext0);

  temp = get_suffix_name_file(entrytext);
  fileopen.projectname = get_name_file(temp);
  fileopen.localdir = get_name_dir(temp);
  g_free(temp);
  fileopen.datafile = g_strdup_printf("%s.com",fileopen.projectname);
  fileopen.outputfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.logfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.moldenfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.remotehost = NULL;
  fileopen.remoteuser = NULL;
  fileopen.remotedir = NULL;

  /* save file */
   NomFichier = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.datafile);
  
  fileopen.remotehost = NULL;
  fileopen.remoteuser = NULL;
  fileopen.remotepass = NULL;
  fileopen.remotedir = NULL;
  fileopen.command  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[1])));
  CreeFeuille(treeViewProjects, noeud[GABEDIT_TYPENODE_GAUSSIAN],fileopen.projectname,fileopen.datafile,fileopen.localdir,
			fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir,GABEDIT_TYPENODE_GAUSSIAN, fileopen.command, fileopen.netWorkProtocol); 

/* Save file in local host */
  fd = FOpen(NomFichier, "w");
  if(fd == NULL)
  {
	  Message("Sorry, I can not save file","Error",TRUE);
	  return;
  }
  temp=gabedit_text_get_chars(text,0,-1);
  fprintf(fd,"%s",temp);
  fclose(fd);

  data_modify(FALSE);

  entry=entryall[1];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));

  if(!create_cmd_gaussian(entrytext0, TRUE, cmdDir, cmdFile, cmdFileAllName)) return;
  sprintf(Command ,"%s",cmdFileAllName);

  run_local_command(fout,ferr,Command,TRUE);
  title = g_strdup_printf("Run gaussian in local : %s",Command); 
  Win = create_text_result_command(Text,Frame,title);
  g_free(title);
  strout = cat_file(fout,FALSE);
  strerr = cat_file(ferr,FALSE);
  if(!strout && !strerr)
  	destroy_childs(Win);
  else
  {
  	if(strout)
	{
 		gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,strout,-1);   
		g_free(strout);
	}
  	if(strerr)
	{
 		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,strerr,-1);   
		g_free(strerr);
	}
  	gtk_widget_show_all(Win);
  	if(!strout)
  		gtk_widget_hide(Frame[0]);
  }
  g_free(fout);
  g_free(ferr);
}
/********************************************************************************/
static void run_local_molcas(GtkWidget *b,gpointer data)
{  
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);

  GtkWidget* Win;
  GtkWidget* Text[2];
  GtkWidget* Frame[2];
  gchar *strout;
  gchar *strerr;
  gchar *temp;
  gchar *NomFichier;
  gchar *Command;
  FILE *fd;
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext0;
  gchar *entrytext;
  gchar* title;
  G_CONST_RETURN gchar *localdir;
  gchar cmdFileAllName[BSIZE];
  gchar cmdDir[BSIZE];
  gchar cmdFile[BSIZE];

  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));
  localdir = gtk_entry_get_text(GTK_ENTRY(EntryLocalDir));
  entrytext = get_dir_file_name(localdir,entrytext0);


  temp = get_suffix_name_file(entrytext);
  fileopen.projectname = get_name_file(temp);
  fileopen.localdir = get_name_dir(temp);
  g_free(temp);
  fileopen.datafile = g_strdup_printf("%s.com",fileopen.projectname);
  fileopen.outputfile=g_strdup_printf("%s.out",fileopen.projectname);
  fileopen.logfile=g_strdup_printf("%s.log",fileopen.projectname);
  /* fileopen.moldenfile=g_strdup_printf("%s.molden",fileopen.projectname);*/
  fileopen.moldenfile=g_strdup_printf("'%s.*.molden'", fileopen.projectname);
  fileopen.remotehost = NULL;
  fileopen.remoteuser = NULL;
  fileopen.remotedir = NULL;

  /* save file */
  NomFichier = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.datafile);
  
  fileopen.remotehost = NULL;
  fileopen.remoteuser = NULL;
  fileopen.remotepass = NULL;
  fileopen.remotedir = NULL;
  fileopen.command  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[1])));
  CreeFeuille(treeViewProjects, noeud[GABEDIT_TYPENODE_MOLCAS],fileopen.projectname,fileopen.datafile,fileopen.localdir,
			fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir,GABEDIT_TYPENODE_MOLCAS, fileopen.command, fileopen.netWorkProtocol); 

/* Save file in local host */
  fd = FOpen(NomFichier, "w");
  if(fd == NULL)
  {
	  Message("Sorry, I can not save the input file","Error",TRUE);
	  return;
  }
  temp=gabedit_text_get_chars(text,0,-1);
  fprintf(fd,"%s",temp);
  fclose(fd);

  data_modify(FALSE);

  entry=entryall[1];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));

  if(!create_cmd_molcas(entrytext0, TRUE, cmdDir, cmdFile, cmdFileAllName)) return;
  
  Command = g_strdup_printf("%s ",cmdFileAllName);
 


  create_popup_win("\nPlease Wait\n");
  run_local_command(fout,ferr,Command,TRUE);

  title = g_strdup_printf("Run molcas in local : %s",Command); 
  Win = create_text_result_command(Text,Frame,title);
  g_free(title);
  strout = cat_file(fout,FALSE);
  strerr = cat_file(ferr,FALSE);
  if(!strout && !strerr) destroy_childs(Win);
  else
  {
  	if(strout)
	{
 		gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,strout,-1);   
		g_free(strout);
	}
  	if(strerr)
	{
 		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,strerr,-1);   
		g_free(strerr);
	}
  	gtk_widget_show_all(Win);
  	if(!strout)
  		gtk_widget_hide(Frame[0]);
  }
  g_free(fout);
  g_free(ferr);
}
/********************************************************************************/
static void run_local_molpro(GtkWidget *b,gpointer data)
{  
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);

  GtkWidget* Win;
  GtkWidget* Text[2];
  GtkWidget* Frame[2];
  gchar *strout;
  gchar *strerr;
  gchar *temp;
  gchar *t;
  gchar *NomFichier;
  gchar Command[BSIZE];
  FILE *fd;
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext0;
  gchar *entrytext;
  gchar* title;
  gchar *pdest;
  gchar *Tompon;
  G_CONST_RETURN gchar *localdir;
  gchar cmdFileAllName[BSIZE];
  gchar cmdDir[BSIZE];
  gchar cmdFile[BSIZE];


  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));
  localdir = gtk_entry_get_text(GTK_ENTRY(EntryLocalDir));
  entrytext = get_dir_file_name(localdir,entrytext0);


  temp = get_suffix_name_file(entrytext);
  fileopen.projectname = get_name_file(temp);
  fileopen.localdir = get_name_dir(temp);
  g_free(temp);
  fileopen.datafile = g_strdup_printf("%s.com",fileopen.projectname);
  fileopen.outputfile=g_strdup_printf("%s.out",fileopen.projectname);
  fileopen.logfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.moldenfile=g_strdup_printf("%s.molden",fileopen.projectname);
  fileopen.remotehost = NULL;
  fileopen.remoteuser = NULL;
  fileopen.remotedir = NULL;

  Tompon=gabedit_text_get_chars(text,0,-1);
  pdest = strstr( Tompon, fileopen.moldenfile);
  if( pdest == NULL )
  {
  	pdest = strstr( Tompon,"put,molden");
	if(pdest)
	{
		temp = strstr(pdest,";");
		t = strstr(pdest,"\n");
		if(temp && t && t<temp)
			temp = t;
		if(!temp)
			temp = t;
		if(temp)
		{
/*			Debug("%d\n",(guint)(pdest-Tompon));*/
/*			Debug("%d\n",(guint)(temp-pdest));*/
        		gabedit_text_set_point(GABEDIT_TEXT(text),(guint)(pdest-Tompon));
        		gabedit_text_forward_delete(GABEDIT_TEXT(text),(guint)(temp-pdest+1));
		}
		
	}
	temp = g_strdup_printf("put,molden,%s",fileopen.moldenfile);
	gabedit_text_set_point(GABEDIT_TEXT(text), gabedit_text_get_length(GABEDIT_TEXT(text)));  
  	gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL,temp,-1);
	g_free(temp);
   	gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, "\n",-1);
  }
  if(Tompon != NULL) 
	g_free(Tompon);

  /* save file */
  NomFichier = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.datafile);
  
  fileopen.remotehost = NULL;
  fileopen.remoteuser = NULL;
  fileopen.remotepass = NULL;
  fileopen.remotedir = NULL;
  fileopen.command  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[1])));
  CreeFeuille(treeViewProjects, noeud[GABEDIT_TYPENODE_MOLPRO],fileopen.projectname,fileopen.datafile,fileopen.localdir,
			fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir,GABEDIT_TYPENODE_MOLPRO, fileopen.command, fileopen.netWorkProtocol); 

/* Save file in local host */
  fd = FOpen(NomFichier, "w");
  if(fd == NULL)
  {
	  Message("Sorry, I can not save file","Error",TRUE);
	  return;
  }
  temp=gabedit_text_get_chars(text,0,-1);
  fprintf(fd,"%s",temp);
  fclose(fd);

  data_modify(FALSE);

  entry=entryall[1];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));

  if(!create_cmd_molpro(entrytext0, TRUE, cmdDir, cmdFile, cmdFileAllName)) return;
  sprintf(Command ,"%s",cmdFileAllName);


  create_popup_win("\nPlease Wait\n");
  run_local_command(fout,ferr,Command,TRUE);
  title = g_strdup_printf("Run molpro in local : %s",Command); 
  Win = create_text_result_command(Text,Frame,title);
  g_free(title);
  strout = cat_file(fout,FALSE);
  strerr = cat_file(ferr,FALSE);
  if(!strout && !strerr)
  	destroy_childs(Win);
  else
  {
  	if(strout)
	{
 		gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,strout,-1);   
		g_free(strout);
	}
  	if(strerr)
	{
 		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,strerr,-1);   
		g_free(strerr);
	}
  	gtk_widget_show_all(Win);
  	if(!strout)
  		gtk_widget_hide(Frame[0]);
  }
  g_free(fout);
  g_free(ferr);
}
/********************************************************************************/
static void run_local_mpqc(GtkWidget *b,gpointer data)
{  
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);

  GtkWidget* Win;
  GtkWidget* Text[2];
  GtkWidget* Frame[2];
  gchar *strout;
  gchar *strerr;
  gchar *temp;
  gchar *NomFichier;
  gchar *Command;
  FILE *fd;
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext0;
  gchar *entrytext;
  gchar* title;
  G_CONST_RETURN gchar *localdir;
  gchar cmdFileAllName[BSIZE];
  gchar cmdDir[BSIZE];
  gchar cmdFile[BSIZE];

  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));
  localdir = gtk_entry_get_text(GTK_ENTRY(EntryLocalDir));
  entrytext = get_dir_file_name(localdir,entrytext0);


  temp = get_suffix_name_file(entrytext);
  fileopen.projectname = get_name_file(temp);
  fileopen.localdir = get_name_dir(temp);
  g_free(temp);
  fileopen.datafile = g_strdup_printf("%s.com",fileopen.projectname);
  fileopen.outputfile=g_strdup_printf("%s.out",fileopen.projectname);
  fileopen.logfile=g_strdup_printf("%s.out",fileopen.projectname);
  /* fileopen.moldenfile=g_strdup_printf("%s.molden",fileopen.projectname);*/
  fileopen.moldenfile=g_strdup_printf("'%s.*.molden'", fileopen.projectname);
  fileopen.remotehost = NULL;
  fileopen.remoteuser = NULL;
  fileopen.remotedir = NULL;

  /* save file */
  NomFichier = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.datafile);
  
  fileopen.remotehost = NULL;
  fileopen.remoteuser = NULL;
  fileopen.remotepass = NULL;
  fileopen.remotedir = NULL;
  fileopen.command  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[1])));
  CreeFeuille(treeViewProjects, noeud[GABEDIT_TYPENODE_MPQC],fileopen.projectname,fileopen.datafile,fileopen.localdir,
			fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir,GABEDIT_TYPENODE_MPQC, fileopen.command, fileopen.netWorkProtocol); 

/* Save file in local host */
  fd = FOpen(NomFichier, "w");
  if(fd == NULL)
  {
	  Message("Sorry, I can not save the input file","Error",TRUE);
	  return;
  }
  temp=gabedit_text_get_chars(text,0,-1);
  fprintf(fd,"%s",temp);
  fclose(fd);

  data_modify(FALSE);

  entry=entryall[1];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));

  if(!create_cmd_mpqc(entrytext0, TRUE, cmdDir, cmdFile, cmdFileAllName)) return;
  
  Command = g_strdup_printf("%s ",cmdFileAllName);
 


  create_popup_win("\nPlease Wait\n");
  run_local_command(fout,ferr,Command,TRUE);

  title = g_strdup_printf("Run MPQC in local : %s",Command); 
  Win = create_text_result_command(Text,Frame,title);
  g_free(title);
  strout = cat_file(fout,FALSE);
  strerr = cat_file(ferr,FALSE);
  if(!strout && !strerr) destroy_childs(Win);
  else
  {
  	if(strout)
	{
 		gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,strout,-1);   
		g_free(strout);
	}
  	if(strerr)
	{
 		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,strerr,-1);   
		g_free(strerr);
	}
  	gtk_widget_show_all(Win);
  	if(!strout)
  		gtk_widget_hide(Frame[0]);
  }
  g_free(fout);
  g_free(ferr);
}
/********************************************************************************/
static void run_local_other(GtkWidget *b,gpointer data)
{  
  gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
  gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);

  GtkWidget* Win;
  GtkWidget* Text[2];
  GtkWidget* Frame[2];
  gchar *strout;
  gchar *strerr;
  gchar *temp;
  gchar *NomFichier;
  gchar Command[BSIZE];
  FILE *fd;
  GtkWidget **entryall;
  GtkWidget *entry;
  G_CONST_RETURN gchar *entrytext0;
  gchar *entrytext;
  gchar* title;
  G_CONST_RETURN gchar *localdir;
  gchar cmdFileAllName[BSIZE];
  gchar cmdDir[BSIZE];
  gchar cmdFile[BSIZE];


  entryall=(GtkWidget **)data;
  entry=entryall[0];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));
  localdir = gtk_entry_get_text(GTK_ENTRY(EntryLocalDir));
  entrytext = get_dir_file_name(localdir,entrytext0);

  temp = get_suffix_name_file(entrytext);
  fileopen.projectname = get_name_file(temp);
  fileopen.localdir = get_name_dir(temp);
  g_free(temp);
  fileopen.datafile = g_strdup_printf("%s.com",fileopen.projectname);
  fileopen.outputfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.logfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.moldenfile=g_strdup_printf("%s.log",fileopen.projectname);
  fileopen.remotehost = NULL;
  fileopen.remoteuser = NULL;
  fileopen.remotedir = NULL;

  /* save file */
   NomFichier = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.datafile);
  
  fileopen.remotehost = NULL;
  fileopen.remoteuser = NULL;
  fileopen.remotepass = NULL;
  fileopen.remotedir = NULL;
  fileopen.command  = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryall[1])));
  CreeFeuille(treeViewProjects, noeud[GABEDIT_TYPENODE_OTHER],fileopen.projectname,fileopen.datafile,fileopen.localdir,
			fileopen.remotehost,fileopen.remoteuser,fileopen.remotepass,fileopen.remotedir,GABEDIT_TYPENODE_OTHER, fileopen.command, fileopen.netWorkProtocol); 

/* Save file in local host */
  fd = FOpen(NomFichier, "w");
  if(fd == NULL)
  {
	  temp = g_strdup_printf(" I can not save %s file", NomFichier);
	  Message(temp,"Error",TRUE);
	  g_free(temp);
	  return;
  }
  temp=gabedit_text_get_chars(text,0,-1);
  fprintf(fd,"%s",temp);
  fclose(fd);

  data_modify(FALSE);

  entry=entryall[1];
  entrytext0 = gtk_entry_get_text(GTK_ENTRY(entry));

  /*
  printf("entrytext = %s\n",entrytext);
  */

  if(!create_cmd_other(entrytext0, TRUE, cmdDir, cmdFile, cmdFileAllName)) return;

  sprintf(Command ,"%s",cmdFileAllName);
  

  run_local_command(fout,ferr,Command,TRUE);
  title = g_strdup_printf("Run \"%s %s\" command in local host", entrytext0, fileopen.datafile); 
  Win = create_text_result_command(Text,Frame,title);
  g_free(title);
  strout = cat_file(fout,FALSE);
  strerr = cat_file(ferr,FALSE);
  if(!strout && !strerr)
  	destroy_childs(Win);
  else
  {
  	if(strout)
	{
 		gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,strout,-1);   
		g_free(strout);
	}
  	if(strerr)
	{
 		gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,strerr,-1);   
		g_free(strerr);
	}
  	gtk_widget_show_all(Win);
  	if(!strout)
  		gtk_widget_hide(Frame[0]);
  }
  g_free(fout);
  g_free(ferr);
}
/********************************************************************************/
void run_program(GtkWidget *button,gpointer data)
{
  	GtkWidget* ButtonSsh = g_object_get_data(G_OBJECT (button),"ButtonSsh");
	/*
  	GtkWidget* ButtonFtpRsh = g_object_get_data(G_OBJECT (button),"ButtonFtpRsh");
	*/

	if(ButtonSsh && GTK_TOGGLE_BUTTON (ButtonSsh)->active)
	{
		fileopen.netWorkProtocol = GABEDIT_NETWORK_SSH;
	}
	else
	{
		fileopen.netWorkProtocol = GABEDIT_NETWORK_FTP_RSH;
	}

	if(GTK_TOGGLE_BUTTON (ButtonLocal)->active)
	{
		if (GTK_TOGGLE_BUTTON (ButtonGauss)->active)
			run_local_gaussian(NULL,data);
		else
		if (GTK_TOGGLE_BUTTON (ButtonMolcas)->active)
			run_local_molcas(NULL,data);
		else
		if (GTK_TOGGLE_BUTTON (ButtonMPQC)->active)
			run_local_mpqc(NULL,data);
		else
		if (GTK_TOGGLE_BUTTON (ButtonMolpro)->active)
			run_local_molpro(NULL,data);
		else
		if (GTK_TOGGLE_BUTTON (ButtonOther)->active)
			run_local_other(NULL,data);
	}
	else
	{
		if (GTK_TOGGLE_BUTTON (ButtonGauss)->active)
			run_remote_gaussian(NULL,data);
		else
		if (GTK_TOGGLE_BUTTON (ButtonMolcas)->active)
			run_remote_molcas(NULL,data);
		else
		if (GTK_TOGGLE_BUTTON (ButtonMPQC)->active)
			run_remote_mpqc(NULL,data);
		else
		if (GTK_TOGGLE_BUTTON (ButtonMolpro)->active)
			run_remote_molpro(NULL,data);
		else
		run_remote_other(NULL,data);
	}
	gtk_notebook_set_current_page((GtkNotebook*)NoteBookText,0);
}
/********************************************************************************/
static void set_entrys_folder(GtkWidget* selFolder)
{
  GtkWidget *entry = (GtkWidget*)(g_object_get_data(G_OBJECT(selFolder),"EntryDirectory"));	
  gchar *dirname = gabedit_folder_chooser_get_current_folder((GabeditFolderChooser *)selFolder);
  gchar *longfile = g_strdup_printf("%s%sdump.txt",dirname, G_DIR_SEPARATOR_S);
  gtk_entry_set_text(GTK_ENTRY(entry),dirname);
  set_last_directory(longfile);
}
/********************************************************************************/
static void set_entry_directory_selection(GtkWidget* table)
{
  GtkWidget *selFolder;
  GtkWidget *Win = (GtkWidget*)(g_object_get_data(G_OBJECT(table),"Window"));
  GtkWidget *entrydirectory = (GtkWidget*)(g_object_get_data(G_OBJECT(table),"Entry"));

  selFolder = gabedit_folder_chooser_new("Folder chooser");
  add_child(Win,selFolder,gtk_widget_destroy," Folder selection ");
  g_signal_connect(G_OBJECT(selFolder),"delete_event",(GtkSignalFunc)delete_child,NULL);

  g_object_set_data (G_OBJECT (selFolder), "EntryDirectory", entrydirectory);

  g_signal_connect (selFolder, "response",  G_CALLBACK (set_entrys_folder), G_OBJECT(selFolder));
  g_signal_connect (selFolder, "response",  G_CALLBACK (delete_child), G_OBJECT(selFolder));

  gtk_widget_show(selFolder);
}
/********************************************************************************/
static GtkWidget *create_hbox_browser_run(GtkWidget* Wins,GtkWidget* Table,
							   gchar *LabelRight,gchar *LabelLeft,
							   gchar *deffile,gushort row)
{
  GtkWidget *Entry = NULL;
  GtkWidget* Label;

  Label = add_label_table(Table,LabelLeft,row,0);
  Label = add_label_table(Table,":",row,1);
  Entry = gtk_entry_new();
  if(deffile) gtk_entry_set_text(GTK_ENTRY(Entry),deffile);
  gtk_table_attach(GTK_TABLE(Table),Entry,2,3,row,row+1,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  1,1);
  add_label_table(Table,LabelRight,row,3);
  g_object_set_data (G_OBJECT (Table), "Entry", Entry);
  g_object_set_data (G_OBJECT (Table), "Label", Label);
  g_object_set_data (G_OBJECT (Table), "Window", Wins);
  return Entry;
}
/********************************************************************************/
GtkWidget* create_server_frame(GtkWidget* hbox)
{
  GtkWidget *frame;
  GtkWidget *Table;
  GtkWidget *vboxframe;

  frame = gtk_frame_new ("Server");
  gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  gtk_box_pack_start (GTK_BOX( hbox), frame, TRUE, TRUE, 5);
  gtk_widget_show (frame);

  vboxframe = create_vbox(frame);
  Table = gtk_table_new(2,1,FALSE);
  gtk_container_add(GTK_CONTAINER(vboxframe),Table);

  ButtonLocal = gtk_radio_button_new_with_label( NULL,"Local" );
  add_widget_table(Table,ButtonLocal,0,0);
  ButtonRemote = gtk_radio_button_new_with_label(
                       gtk_radio_button_get_group (GTK_RADIO_BUTTON (ButtonLocal)),
                       "Remote host "); 
  add_widget_table(Table,ButtonRemote,1,0);
  return frame;
}
/********************************************************************************/
GtkWidget* create_programs_frame(GtkWidget *hbox)
{
  GtkWidget *frame;
  GtkWidget *vboxframe;
  GtkWidget *Table;

  frame = gtk_frame_new ("Program");
  gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  gtk_box_pack_start (GTK_BOX( hbox), frame, TRUE, TRUE, 5);
  gtk_widget_show (frame);

  vboxframe = create_vbox(frame);
  Table = gtk_table_new(2,3,FALSE);
  gtk_container_add(GTK_CONTAINER(vboxframe),Table);

  ButtonGauss = gtk_radio_button_new_with_label( NULL,"Gaussian" );
  add_widget_table(Table,ButtonGauss,0,0);

  ButtonMolcas = gtk_radio_button_new_with_label( gtk_radio_button_get_group (GTK_RADIO_BUTTON (ButtonGauss)), "Molcas "); 
  add_widget_table(Table,ButtonMolcas,0,1);

  ButtonMolpro = gtk_radio_button_new_with_label( gtk_radio_button_get_group (GTK_RADIO_BUTTON (ButtonGauss)), "Molpro "); 
  add_widget_table(Table,ButtonMolpro,0,2);

  ButtonMPQC = gtk_radio_button_new_with_label( gtk_radio_button_get_group (GTK_RADIO_BUTTON (ButtonGauss)), "MPQC "); 
  add_widget_table(Table,ButtonMPQC,1,0);

  ButtonOther = gtk_radio_button_new_with_label( gtk_radio_button_get_group (GTK_RADIO_BUTTON (ButtonGauss)), "Other "); 
  add_widget_table(Table,ButtonOther,1,1);
  return frame;
}
/********************************************************************************/
GtkWidget *create_local_frame(GtkWidget *Window, GtkWidget *vboxall)
{
	GtkWidget* frame;
	GtkWidget* vboxframe;
	GtkWidget* Table;
	GtkWidget* button;
        gchar* DefLocalDir = NULL;

  	DefLocalDir  = g_strdup(fileopen.localdir);
  	frame = gtk_frame_new ("Local");
  	gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  	gtk_container_add (GTK_CONTAINER (vboxall), frame);
  	gtk_widget_show (frame);

  	vboxframe = create_vbox(frame);
  	Table = gtk_table_new(1,5,FALSE);
  	gtk_container_add(GTK_CONTAINER(vboxframe),Table);

	add_label_table(Table,"Local Directory ",0,0);
	add_label_table(Table,":",0,1);
  	EntryLocalDir = gtk_entry_new ();
	gtk_entry_set_text (GTK_ENTRY (EntryLocalDir), DefLocalDir);
  	gtk_table_attach(GTK_TABLE(Table),EntryLocalDir,2,3,0,1,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  1,1);

	button = create_button_pixmap(Window,open_xpm,NULL);
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	g_signal_connect_swapped(G_OBJECT (button), "clicked", G_CALLBACK(set_entry_directory_selection), G_OBJECT(Table));
	add_widget_table(Table,button,0,4);
	g_object_set_data (G_OBJECT (Table), "Button", button);
	g_object_set_data (G_OBJECT (Table), "Window", Window);
	g_object_set_data (G_OBJECT (Table), "Entry", EntryLocalDir);

        g_free(DefLocalDir);
	return frame;
}
/********************************************************************************/
GtkWidget *create_local_remote_frame(GtkWidget *Window, GtkWidget *vboxall,GtkWidget **entry,gchar* type)
{
	GtkWidget* frame;
	GtkWidget* vboxframe;
	GtkWidget* Table;
	GtkWidget* Label;
	GtkWidget* combo;
#define NLAB 2
  	gchar      *LabelRight[NLAB];
  	gchar      *LabelLeft[NLAB];
  	gchar      *liste[NLAB];
	gint i;
	GtkWidget *hbox = gtk_hbox_new(0,FALSE);

  	LabelLeft[0] = g_strdup("Save data in file");
  	LabelLeft[1] = g_strdup("Command to execute");

  	LabelRight[0] = g_strdup(".com");
  	LabelRight[1] = g_strdup(" DataFile.com ");

  	liste[0]  = g_strdup(fileopen.projectname);
  	if(strstr(type,"Molpro")) liste[1]  = g_strdup(NameCommandMolpro);
  	else if(strstr(type,"Molcas")) liste[1]  = g_strdup(NameCommandMolcas);
	else liste[1]  = g_strdup(NameCommandGaussian);

  	frame = gtk_frame_new ("Local/Remote");
  	gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  	gtk_container_add (GTK_CONTAINER (vboxall), frame);
  	gtk_widget_show (frame);

  	vboxframe = create_vbox(frame);
  	Table = gtk_table_new(2,5,FALSE);
  	gtk_container_add(GTK_CONTAINER(vboxframe),Table);

  	entry[0] = create_hbox_browser_run(Window,Table,
			  LabelRight[0],LabelLeft[0],
		          liste[0],0);

	add_label_table(Table,LabelLeft[1],1,0);
	add_label_table(Table,":",1,1);
  	if(strstr(type,"Molpro")) combo = create_combo_box_entry(molproCommands.commands,molproCommands.numberOfCommands,TRUE,-1,-1);
	else if(strstr(type,"Molcas")) combo = create_combo_box_entry(molcasCommands.commands,molcasCommands.numberOfCommands,TRUE,-1,-1);
	else combo = create_combo_box_entry(gaussianCommands.commands,gaussianCommands.numberOfCommands,TRUE,-1,-1);

	ComboCommand = combo;
	entry[1] = GTK_BIN(combo)->child;
	gtk_entry_set_text (GTK_ENTRY (entry[1]), liste[1]);
	if(fileopen.command && strlen(fileopen.command)>0) gtk_entry_set_text (GTK_ENTRY (entry[1]), fileopen.command);
	add_widget_table(Table,combo,1,2);

	Label = gtk_label_new(LabelRight[1]);
	LabelDataFile = Label;
   	gtk_label_set_justify(GTK_LABEL(Label),GTK_JUSTIFY_LEFT);
	gtk_box_pack_start (GTK_BOX (hbox), Label, FALSE, FALSE, 0);
	gtk_table_attach(GTK_TABLE(Table),hbox,3,5,1,1+1,
                  (GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
                  (GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
                  1,1);
  	for (i=0;i<NLAB;i++)
        	g_free(LabelLeft[i]);
  	for (i=0;i<NLAB;i++)
        	g_free(LabelRight[i]);
	return frame;
}
/********************************************************************************/
static void changedEntryFileData(GtkWidget *entry,gpointer data)
{
	G_CONST_RETURN gchar* entrytext = gtk_entry_get_text(GTK_ENTRY(entry));
	if(entrytext)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"%s.com",entrytext);
		gtk_label_set_text(GTK_LABEL(LabelDataFile), buffer);
	}
}
/********************************************************************************/
void changed_user(GtkWidget *combo,gpointer data)
{
	GtkWidget **entry = (GtkWidget **)data;
	gint nlistdir = 1;
	G_CONST_RETURN gchar *hostname;
	G_CONST_RETURN gchar *username;
	gint numhost = -1;
	gint numuser = -1;
	GtkWidget* combodir = NULL;
	gint i;
	gint j;
        GList *glist = NULL;

	if(!entry[1]) return;
	if(!entry[2]) return;
	if(!entry[3]) return;
	if(!entry[5]) return;
	if (!GTK_IS_WIDGET((GtkWidget*)entry[1])) return;
	if (!GTK_IS_WIDGET((GtkWidget*)entry[2])) return;
	if (!GTK_IS_WIDGET((GtkWidget*)entry[3])) return;
	if (!GTK_IS_WIDGET((GtkWidget*)entry[5])) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)entry[1]) & GTK_IN_DESTRUCTION)) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)entry[2]) & GTK_IN_DESTRUCTION)) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)entry[3]) & GTK_IN_DESTRUCTION)) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)entry[5]) & GTK_IN_DESTRUCTION)) return;

	hostname = gtk_entry_get_text(GTK_ENTRY(entry[2]));

	username = gtk_entry_get_text(GTK_ENTRY(entry[3]));

	combodir = g_object_get_data (G_OBJECT (entry[5]), "Combo");


        if(!combodir) return;

	if(recenthosts.nhosts>0)
  	{
		for(i=0;i<recenthosts.nhosts;i++)
  			if(strcmp(hostname,recenthosts.hosts[i].hostname) == 0)
			{
				numhost = i;
				for(j=0;j<recenthosts.hosts[numhost].nusers;j++)
  					if(strcmp(username,recenthosts.hosts[i].users[j].username) == 0)
					{
						numuser = j;
						break;
					}
				
				break;
			}
		if(numhost<0) return;
		if(numuser<0) return;

        	nlistdir = recenthosts.hosts[numhost].users[numuser].ndirs;
		for(i=nlistdir-1;i>=0;i--)
  			glist = g_list_append(glist,recenthosts.hosts[numhost].users[numuser].dirs[i]);
  	}
  	else
		return;


	if (!(GTK_OBJECT_FLAGS((GtkObject*)combodir) & GTK_IN_DESTRUCTION))
        	gtk_combo_box_entry_set_popdown_strings( combodir, glist) ;


	g_list_free(glist);
}
/********************************************************************************/
void changed_host(GtkWidget *combo,gpointer data)
{
	GtkWidget **entry = (GtkWidget **)data;
	gint nlistuser = 1;
	G_CONST_RETURN gchar *hostname;
	gint numhost = -1;
	GtkWidget* combouser = NULL;
	gint i;
        GList *glist = NULL;

	if(!entry[1]) return;
	if(!entry[2]) return;
	if(!entry[3]) return;
	if(!entry[5]) return;
	if (!GTK_IS_WIDGET((GtkWidget*)entry[1])) return;
	if (!GTK_IS_WIDGET((GtkWidget*)entry[2])) return;
	if (!GTK_IS_WIDGET((GtkWidget*)entry[3])) return;
	if (!GTK_IS_WIDGET((GtkWidget*)entry[5])) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)entry[1]) & GTK_IN_DESTRUCTION)) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)entry[2]) & GTK_IN_DESTRUCTION)) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)entry[3]) & GTK_IN_DESTRUCTION)) return;
	if ((GTK_OBJECT_FLAGS((GtkObject*)entry[5]) & GTK_IN_DESTRUCTION)) return;
	hostname = gtk_entry_get_text(GTK_ENTRY(entry[2]));
	combouser = g_object_get_data (G_OBJECT (entry[3]), "Combo");
        if(!combouser) return;
	if(recenthosts.nhosts>0)
  	{
		for(i=0;i<recenthosts.nhosts;i++)
  			if(strcmp(hostname,recenthosts.hosts[i].hostname) == 0)
			{
				numhost = i;
				break;
			}
		if(numhost<0)
			return;

        	nlistuser = recenthosts.hosts[numhost].nusers;
		for(i=0;i<recenthosts.hosts[numhost].nusers;i++)
		glist = g_list_append(glist,recenthosts.hosts[numhost].users[i].username);
  	}
  	else
		return;


	if (!(GTK_OBJECT_FLAGS((GtkObject*)combouser) & GTK_IN_DESTRUCTION))
  	for (i=0;i<nlistuser;i++)
        	gtk_combo_box_entry_set_popdown_strings( combouser, glist) ;


	g_list_free(glist);
}
/********************************************************************************/
static  GtkWidget* create_network_protocols(GtkWidget* Win,GtkWidget *vbox,gboolean expand)
{
	GtkWidget *frame;
	GtkWidget *ButtonFtpRsh;
	GtkWidget *ButtonSsh;
	GtkWidget *vboxframe;
	GtkWidget *table = gtk_table_new(1,2,FALSE);
	gchar ftprsh[] = "FTP and rsh protocols";
	gchar ssh[]    = "ssh/scp protocols    ";

	frame = gtk_frame_new ("NetWork protocols");
	gtk_widget_show (frame);
	gtk_box_pack_start (GTK_BOX (vbox), frame, expand, expand, 0);

	vboxframe = gtk_vbox_new (TRUE, 0);
	gtk_widget_show (vboxframe);
	gtk_container_add (GTK_CONTAINER (frame), vboxframe);

	gtk_box_pack_start (GTK_BOX (vboxframe), table, expand, expand, 0);

	ButtonFtpRsh = gtk_radio_button_new_with_label( NULL,ftprsh);
	gtk_table_attach(GTK_TABLE(table),ButtonFtpRsh,0,1,0,1,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  1,1);
	gtk_widget_show (ButtonFtpRsh);

	ButtonSsh = gtk_radio_button_new_with_label( gtk_radio_button_get_group (GTK_RADIO_BUTTON (ButtonFtpRsh)), ssh); 
	gtk_table_attach(GTK_TABLE(table),ButtonSsh,1,2,0,1,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  1,1);
	gtk_widget_show (ButtonSsh);


	g_object_set_data(G_OBJECT (Win),"ButtonSsh", ButtonSsh);
	g_object_set_data(G_OBJECT (Win),"ButtonFtpRsh",ButtonFtpRsh);

	g_object_set_data (G_OBJECT (ButtonFtpRsh), "TypeButton", &typeButton[2]);
	g_signal_connect(G_OBJECT(ButtonFtpRsh), "clicked",G_CALLBACK(set_frame_remote_visibility),NULL);

	g_object_set_data (G_OBJECT (ButtonSsh), "TypeButton", &typeButton[3]);
	g_signal_connect(G_OBJECT(ButtonSsh), "clicked",G_CALLBACK(set_frame_remote_visibility),NULL);

  	FrameNetWork = frame;
	gtk_widget_show_all(frame);
	return frame;
}
/********************************************************************************/
GtkWidget *create_remote_frame( GtkWidget *vboxall,GtkWidget **entry)
{
  GtkWidget *frame;
  GtkWidget *combo;
  GtkWidget *vboxframe;
#define NL 4
  gchar      *LabelLeft[NL];
  gushort i;
  GtkWidget *Table;
  gchar      *tlisthost[NHOSTMAX];
  gchar      *tlistuser[NHOSTMAX];
  gchar      *tlistdir[NHOSTMAX];
  gint nlisthost = 1;
  gint nlistuser = 1;
  gint nlistdir  = 1;

  if(recenthosts.nhosts>0)
  {
  	nlisthost = recenthosts.nhosts;
	for(i=0;i<nlisthost;i++)
  		tlisthost[i] = g_strdup(recenthosts.hosts[i].hostname);
        nlistuser = recenthosts.hosts[0].nusers;
	for(i=0;i<recenthosts.hosts[0].nusers;i++)
  		tlistuser[i] = g_strdup(recenthosts.hosts[0].users[i].username);
        nlistdir = recenthosts.hosts[0].users[0].ndirs;
	for(i=0;i<recenthosts.hosts[0].users[0].ndirs;i++)
  		tlistdir[i] = g_strdup(recenthosts.hosts[0].users[0].dirs[i]);
  }
  else
  {
  	tlisthost[0] = g_strdup("hostname");
  	tlistuser[0] = g_strdup("login");
  	tlistdir[0] = g_strdup("tmp");
  }

  LabelLeft[0] = g_strdup("Host name");
  LabelLeft[1] = g_strdup("Login");
  LabelLeft[2] = g_strdup("Password");
  LabelLeft[3] = g_strdup("Working Directory");

  frame = gtk_frame_new ("Remote host");
  FrameRemote = frame;
  gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  gtk_container_add (GTK_CONTAINER (vboxall), frame);
  gtk_widget_show (frame);

  vboxframe = create_vbox(frame);
  Table = gtk_table_new(3,3,FALSE);
  gtk_container_add(GTK_CONTAINER(vboxframe),Table);

	i = 2;
	add_label_table(Table,LabelLeft[i-2],(gushort)(i-2),0);
	add_label_table(Table,":",(gushort)(i-2),1);
	combo = create_combo_box_entry(tlisthost,nlisthost,TRUE,-1,-1);

	gtk_table_attach(GTK_TABLE(Table),combo,2,3,i-2,i+1-2,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  1,1);
	gtk_widget_show (combo);
	entry[i] = GTK_BIN(combo)->child;
        g_object_set_data (G_OBJECT (entry[i]), "Combo",combo);
        g_signal_connect(G_OBJECT(GTK_COMBO_BOX(combo)), "changed",G_CALLBACK(changed_host),entry);

	i = 3;
	add_label_table(Table,LabelLeft[i-2],(gushort)(i-2),0);
	add_label_table(Table,":",(gushort)(i-2),1);
	combo = create_combo_box_entry(tlistuser,nlistuser,TRUE,-1,-1);
	add_widget_table(Table,combo,(gushort)(i-2),2);
	entry[i] = GTK_BIN(combo)->child;
        g_object_set_data (G_OBJECT (entry[i]), "Combo",combo);
        g_signal_connect(G_OBJECT(GTK_COMBO_BOX(combo)), "changed",G_CALLBACK(changed_user),entry);

	i = 4;
	{
		LabelPassWord1 = add_label_table(Table,LabelLeft[i-2],(gushort)(i-2),0);
		LabelPassWord2 = add_label_table(Table,":",(gushort)(i-2),1);
		entry[i] = gtk_entry_new ();
		gtk_entry_set_visibility(GTK_ENTRY (entry[i]),FALSE);
		add_widget_table(Table,entry[i],(gushort)(i-2),2);
		EntryPassWord = entry[i];
	}

	i = 5;
	add_label_table(Table,LabelLeft[i-2],(gushort)(i-2),0);
	add_label_table(Table,":",(gushort)(i-2),1);
	combo = create_combo_box_entry(tlistdir,nlistdir,TRUE,-1,-1);
	add_widget_table(Table,combo,(gushort)(i-2),2);
	entry[i] = GTK_BIN(combo)->child;
        g_object_set_data (G_OBJECT (entry[i]), "Combo",combo);

	gtk_widget_show_all(frame);
  
	if(fileopen.remotehost)
		gtk_entry_set_text(GTK_ENTRY(entry[2]),fileopen.remotehost);
	if(fileopen.remoteuser)
		gtk_entry_set_text(GTK_ENTRY(entry[3]),fileopen.remoteuser);
	if(fileopen.remotepass)
		gtk_entry_set_text(GTK_ENTRY(entry[4]),fileopen.remotepass);

	if(fileopen.remotedir && !this_is_a_backspace(fileopen.remotedir))
		gtk_entry_set_text(GTK_ENTRY(entry[5]),fileopen.remotedir);
	else
		gtk_entry_set_text(GTK_ENTRY(entry[5]),"tmp");

  for (i=0;i<NL;i++)
        g_free(LabelLeft[i]);
  for (i=0;i<nlisthost;i++)
        g_free(tlisthost[i]);
  for (i=0;i<nlistuser;i++)
        g_free(tlistuser[i]);
  for (i=0;i<nlistdir;i++)
        g_free(tlistdir[i]);

  return frame;
}
/********************************************************************************/
void create_run_dialogue_box(GtkWidget *w,gchar *type,GtkSignalFunc func)
{
  GtkWidget *fp;
  GtkWidget *sep;
  GtkWidget *frame;
  GtkWidget *vboxall;
  GtkWidget *vboxwin;
  GtkWidget *hbox;
  GtkWidget *button;
  GtkWidget **entry;
  gchar *title = g_strdup_printf("Run ");
  GtkWidget* ButtonSsh = NULL;
  GtkWidget* ButtonFtpRsh = NULL;

  entry=g_malloc(6*sizeof(GtkWidget *));

  /* Principal Window */
  fp = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(fp),title);
  gtk_window_set_position(GTK_WINDOW(fp),GTK_WIN_POS_CENTER);
  gtk_window_set_transient_for(GTK_WINDOW(fp),GTK_WINDOW(Fenetre));

  gtk_widget_realize(fp);
  init_child(fp,gtk_widget_destroy," Run ");
  g_signal_connect(G_OBJECT(fp),"delete_event",(GtkSignalFunc)destroy_childs,NULL);

  gtk_container_set_border_width (GTK_CONTAINER (fp), 5);
  vboxall = create_vbox(fp);
  vboxwin = vboxall;

  frame = gtk_frame_new (NULL);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_container_add(GTK_CONTAINER(vboxall),frame);
  gtk_widget_show (frame);

  vboxall = create_vbox(frame);

  hbox = create_hbox(vboxall);

  frame = create_programs_frame(hbox);

  frame = create_server_frame(hbox);

  frame = create_local_frame(fp,vboxall);

  frame = create_local_remote_frame(fp,vboxall,entry,type);

  frame = create_network_protocols(fp,vboxall,TRUE);

  frame = create_remote_frame(vboxall,entry);

  EntryFileData = entry[0];

  g_signal_connect(G_OBJECT(EntryFileData),"changed", G_CALLBACK(changedEntryFileData),NULL);
  /* pour appeler changedEntryFileData */
  gtk_entry_set_text(GTK_ENTRY(EntryFileData)," ");
  gtk_entry_set_text(GTK_ENTRY(EntryFileData),fileopen.projectname);

  EntryCommand  = entry[1];
  sep = gtk_hseparator_new();
  gtk_box_pack_start(GTK_BOX(vboxwin), sep, FALSE, FALSE, 2);
  gtk_widget_show(sep);
  /* boutons box */
  hbox = create_hbox(vboxwin);
  gtk_widget_realize(fp);

  button = create_button(fp,"Cancel");
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 5);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)destroy_childs,G_OBJECT(fp));
  gtk_widget_show (button);

  button = create_button(fp,"OK");
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 5);
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_widget_grab_default(button);
  gtk_widget_show (button);

  ButtonSsh = g_object_get_data(G_OBJECT (fp),"ButtonSsh");
  ButtonFtpRsh = g_object_get_data(G_OBJECT (fp),"ButtonFtpRsh");
  g_object_set_data(G_OBJECT (button),"ButtonSsh", ButtonSsh);
  g_object_set_data(G_OBJECT (button),"ButtonFtpRsh",ButtonFtpRsh);

  if(fileopen.netWorkProtocol==GABEDIT_NETWORK_SSH)
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonSsh), TRUE);
  else
 	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonSsh), FALSE);

  g_signal_connect(G_OBJECT(button), "clicked",G_CALLBACK(func),(gpointer)entry);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)destroy_childs,G_OBJECT(fp));
  g_signal_connect_swapped (G_OBJECT (entry[4]), "activate", (GtkSignalFunc) gtk_button_clicked, G_OBJECT (button));
  
  g_signal_connect(G_OBJECT(ButtonGauss), "clicked",G_CALLBACK(set_default_entrys),NULL);
  g_signal_connect(G_OBJECT(ButtonMolcas), "clicked",G_CALLBACK(set_default_entrys),NULL);
  g_signal_connect(G_OBJECT(ButtonMolpro), "clicked",G_CALLBACK(set_default_entrys),NULL);
  g_signal_connect(G_OBJECT(ButtonMPQC), "clicked",G_CALLBACK(set_default_entrys),NULL);
  g_signal_connect(G_OBJECT(ButtonOther), "clicked",G_CALLBACK(set_default_entrys),NULL);
  if(strstr(type,"Molpro"))
	  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonMolpro), TRUE);
  else
  if(strstr(type,"Gaussian"))
	  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonGauss), TRUE);
  else
  if(strstr(type,"Molcas"))
	  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonMolcas), TRUE);
  else
  if(strstr(type,"MPQC"))
	  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonMPQC), TRUE);
  else
	  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonOther), TRUE);
  
  g_object_set_data (G_OBJECT (ButtonLocal), "TypeButton", &typeButton[0]);
  g_signal_connect(G_OBJECT(ButtonLocal), "clicked",G_CALLBACK(set_frame_remote_visibility),NULL);

  g_object_set_data (G_OBJECT (ButtonRemote), "TypeButton", &typeButton[1]);
  g_signal_connect(G_OBJECT(ButtonRemote), "clicked",G_CALLBACK(set_frame_remote_visibility),NULL);
  
#ifdef G_OS_WIN32
  gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonRemote), TRUE);
  /*gtk_widget_set_sensitive(ButtonLocal, FALSE);*/

#else
  
  if(fileopen.remotedir && !this_is_a_backspace(fileopen.remotedir))
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonRemote), TRUE);
  else
  {
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (ButtonLocal), TRUE);
	gtk_widget_set_sensitive(FrameRemote, FALSE);
	gtk_widget_set_sensitive(FrameNetWork, FALSE);
  }
#endif

  /* Show all */
  gtk_widget_show_all(fp);
  if(!strstr(type,"Gaussian") && !strstr(type,"Molcas") && !strstr(type,"Molpro") && !strstr(type,"MPQC"))
  	gtk_widget_hide(LabelDataFile);
}
/********************************************************************************/
void create_run ()
{
	switch(iprogram)
	{
		case PROG_IS_GAUSS :
		create_run_dialogue_box(NULL,"Gaussian",(GtkSignalFunc)run_program);
		break;

		case PROG_IS_MOLCAS :
		create_run_dialogue_box(NULL,"Molcas",(GtkSignalFunc)run_program);
		break;

		case PROG_IS_MOLPRO :
		create_run_dialogue_box(NULL,"Molpro",(GtkSignalFunc)run_program);
		break;
		case PROG_IS_MPQC :
		create_run_dialogue_box(NULL,"MPQC",(GtkSignalFunc)run_program);
		break;
	default :
		create_run_dialogue_box(NULL,"Other",(GtkSignalFunc)run_program);
	}
}
/********************************************************************************/
