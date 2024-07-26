/* Mesure.c */
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
#include <stdlib.h>
#include <math.h>

#include "../Common/Global.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Utils.h"
#include "../Utils/AtomsProp.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"

GtkWidget *LabelDistances[12];
GtkWidget *LabelAngles[4];
GtkWidget *LabelDihedral[2];
GtkWidget *LabelAveraged;
GtkWidget *TableDistances;
GtkWidget *TableAngles;
GtkWidget *TableDihedral;


/************************************************************************************************************/
void set_averaged_bond()
{
	gchar *t;
	gint i;
	gint k;
	gint j;
	gfloat averaged_value = 0.0;

	k=0;
	for(i=0;i<(gint)Natoms-1;i++)
		for(j=i+1;j<(gint)Natoms;j++)
	if(draw_lines_yes_no(i,j))
	{
		t = get_distance((gint)geometry[i].N,(gint)geometry[j].N);
		k++;
		averaged_value+=atof(t);
		g_free(t);
	}
	if(k>0)
		averaged_value /= k;
	t = g_strdup_printf(" %f ",averaged_value); 
	gtk_label_set_text(GTK_LABEL(LabelAveraged),t);
	g_free(t);
}
/************************************************************************************************************/
void set_distances()
{
	gchar *t1;
	gchar *t2;
	gchar *t;
	gint N[4];
	gint i;
	gint k;
	gint j;
	gint num[4] = {-1,-1,-1,-1};

	for(i=0;i<4;i++)
	{
		N[i] = NumSelAtoms[i];
		for(j=0;j<(gint)Natoms;j++)
			if((gint)geometry[j].N == N[i])
			{
				num[i] = j;
				break;
			}
	}


	k=-1;
	for(i=0;i<3;i++)
	{
		if(num[i] != -1)
			t1 = g_strdup_printf("%s[%d]",geometry[num[i]].Prop.symbol,geometry[num[i]].N);
		else 
			t1 = g_strdup(" ");

		for(j=i+1;j<4;j++)
		{
			if(num[j] != -1)
				t2 = g_strdup_printf("%s[%d]",geometry[num[j]].Prop.symbol,geometry[num[j]].N);
			else 
				t2 = g_strdup(" ");
			t=g_strdup_printf("%s-%s",t1,t2);
			k++;
			if (N[i] != -1 && N[j] != -1 && N[i] <=(gint)Natoms&& N[j] <=(gint)Natoms)
					gtk_label_set_text(GTK_LABEL(LabelDistances[k]),t); 
			else
					gtk_label_set_text(GTK_LABEL(LabelDistances[k])," ");

			g_free(t);
			g_free(t2);
		}
		g_free(t1);
	}


	k = 6;
	for(i=0;i<3;i++)
	for(j=i+1;j<4;j++)
	{
		if (N[i] != -1 && N[j] != -1 && N[i] <=(gint)Natoms&& N[j] <=(gint)Natoms)
		{
			t = g_strdup_printf(" :  %s",get_distance(N[i],N[j]));
			gtk_label_set_text(GTK_LABEL(LabelDistances[k]),t);
			g_free(t);
		}
		else
				gtk_label_set_text(GTK_LABEL(LabelDistances[k])," ");

		k++;
	}
}
/************************************************************************************************************/
void set_angles()
{
	gint N[4];
	gint i;
	gint j;
	gchar *t;
	gchar *t1;
	gboolean OK;
	gint num[4] = {-1,-1,-1,-1};

	for(i=0;i<4;i++)
	{
		N[i] = NumSelAtoms[i];
		for(j=0;j<(gint)Natoms;j++)
			if((gint)geometry[j].N == N[i])
			{
				num[i] = j;
				break;
			}
	}


	OK = TRUE;
	for(i=0;i<3;i++)
	{
	  if(num[i] == -1)
	  {
		  OK = FALSE;
		  break;
	  }
	}
	if(OK)
	for(i=0;i<2;i++)
	{
	  if(N[i] == N[i+1])
	  {
		  OK = FALSE;
		  break;
	  }
	}

	if(OK)
	{
		t = g_strdup_printf("%s[%d]-%s[%d]-%s[%d]",
			geometry[num[0]].Prop.symbol,geometry[num[0]].N,
			geometry[num[1]].Prop.symbol,geometry[num[1]].N,
			geometry[num[2]].Prop.symbol,geometry[num[2]].N);
		t1 = g_strdup_printf(" : %s ",get_angle(N[0],N[1],N[2]));
	}
	else
	{
		t  = g_strdup(" ");
		t1 = g_strdup(" ");
	}

	gtk_label_set_text(GTK_LABEL(LabelAngles[0]),t);
	gtk_label_set_text(GTK_LABEL(LabelAngles[1]),t1);
	g_free(t);
	g_free(t1);

	OK = TRUE;
	for(i=1;i<4;i++)
	{
	  if(num[i] == -1)
	  {
		  OK = FALSE;
		  break;
	  }
	}
	if(OK)
	for(i=1;i<3;i++)
	{
	  if(N[i] == N[i+1])
	  {
		  OK = FALSE;
		  break;
	  }
	}

	if(OK)
	{
		t = g_strdup_printf("%s[%d]-%s[%d]-%s[%d]",
			geometry[num[1]].Prop.symbol,geometry[num[1]].N,
			geometry[num[2]].Prop.symbol,geometry[num[2]].N,
			geometry[num[3]].Prop.symbol,geometry[num[3]].N);
		t1 = g_strdup_printf(" : %s ",get_angle(N[1],N[2],N[3]));
	}
	else
	{
		t  = g_strdup(" ");
		t1 = g_strdup(" ");
	}


	gtk_label_set_text(GTK_LABEL(LabelAngles[2]),t);
	gtk_label_set_text(GTK_LABEL(LabelAngles[3]),t1);

	g_free(t);
	g_free(t1);

}
/************************************************************************************************************/
void set_dihedral()
{
	gint N[4];
	gint i;
	gint j;
	gchar *t;
	gchar *t1;
	gboolean OK;
	gint num[4] = {-1,-1,-1,-1};

	for(i=0;i<4;i++)
	{
		N[i] = NumSelAtoms[i];
		for(j=0;j<(gint)Natoms;j++)
			if((gint)geometry[j].N == N[i])
			{
				num[i] = j;
				break;
			}
	}

	OK = TRUE;
	for(i=0;i<4;i++)
	{
	  if(num[i] == -1)
	  {
		  OK = FALSE;
		  break;
	  }
	}
	if(OK)
	for(i=0;i<3;i++)
	{
	  if(N[i] == N[i+1])
	  {
		  OK = FALSE;
		  break;
	  }
	}

	if(OK)
	{
		t = g_strdup_printf("%s[%d]-%s[%d]-%s[%d]-%s[%d]",
			geometry[num[0]].Prop.symbol,geometry[num[0]].N,
			geometry[num[1]].Prop.symbol,geometry[num[1]].N,
			geometry[num[2]].Prop.symbol,geometry[num[2]].N,
			geometry[num[3]].Prop.symbol,geometry[num[3]].N);

		t1 = g_strdup_printf(" : %s ",get_dihedral(N[0],N[1],N[2],N[3]));
	}
	else
	{
		t  = g_strdup(" ");
		t1 = g_strdup(" ");
	}

	gtk_label_set_text(GTK_LABEL(LabelDihedral[0]),t);
	gtk_label_set_text(GTK_LABEL(LabelDihedral[1]),t1);
	g_free(t);
	g_free(t1);
}
/************************************************************************************************************/
void change_of_center(GtkWidget *entry,gpointer d)
{
  set_distances();
  set_angles();
  set_dihedral();
  set_averaged_bond();
}
/************************************************************************************************************/
void create_frame_distances(GtkWidget *Dialogue,GtkWidget *vboxframe)
{
  GtkWidget *vbox;
  GtkWidget *Table;
  GtkWidget *FrameDistances;
  guint i;

  for(i=0;i<12;i++)
  	LabelDistances[i] = NULL;

  FrameDistances = create_frame(Dialogue,vboxframe,"Distances (Angstroms)");  
  vbox = create_vbox(FrameDistances);
  TableDistances = gtk_table_new(6,2,TRUE);
  Table=TableDistances;
  gtk_container_add(GTK_CONTAINER(vbox),Table);

  for(i=0;i<6;i++)
	LabelDistances[i] = add_label_table(Table," ",(gushort)i,0); 
  for(i=6;i<12;i++)
	LabelDistances[i] = add_label_table(Table," ",(gushort)(i-6),1); 

  set_distances();

}
/************************************************************************************************************/
void create_frame_angles(GtkWidget *Dialogue,GtkWidget *hbox)
{
  GtkWidget *FrameAngles;
  GtkWidget *Table;
  GtkWidget *vbox;
  guint i;

  FrameAngles = create_frame(Dialogue,hbox,"Angles (Degrees)");  
  vbox = create_vbox(FrameAngles);
  TableAngles = gtk_table_new(2,2,FALSE);
  Table=TableAngles;
  gtk_container_add(GTK_CONTAINER(vbox),Table);

  for(i=0;i<2;i++)
  	LabelAngles[i] = add_label_table(Table," ",0,(gushort)i);;
  for(i=2;i<4;i++)
  	LabelAngles[i] = add_label_table(Table," ",1,(gushort)(i-2));;
	

  set_angles();

}
/************************************************************************************************************/
void create_frame_dihedral(GtkWidget *Dialogue,GtkWidget *hbox)
{
  GtkWidget *FrameDihedral;
  GtkWidget *Table;
  GtkWidget *vbox;
  guint i;
  FrameDihedral = create_frame(Dialogue,hbox,"Dihedral (Degrees)");  

  vbox = create_vbox(FrameDihedral);
  TableDihedral = gtk_table_new(1,1,FALSE);
  Table=TableDihedral;
  gtk_container_add(GTK_CONTAINER(vbox),Table);

  for(i=0;i<2;i++)
  	LabelDihedral[i] = add_label_table(Table," ",0,(gushort)i);;;

  set_dihedral();
}
/************************************************************************************************************/
void create_frame_averaged(GtkWidget *Dialogue,GtkWidget *hbox)
{
  GtkWidget *FrameAveraged;
  GtkWidget *Table;
  GtkWidget *vbox;
  FrameAveraged = create_frame(Dialogue,hbox,"Averaged distance (Angstroms)");  
  vbox = create_vbox(FrameAveraged);
  Table = gtk_table_new(1,1,FALSE);
  gtk_container_add(GTK_CONTAINER(vbox),Table);

  LabelAveraged = add_label_table(Table," ",0,0);

  set_averaged_bond();
}
/************************************************************************************************************/
void AddMesure(GtkWidget *Dialogue,GtkWidget *vboxframe)
{
  GtkWidget *hbox;
  hbox = create_hbox(vboxframe);
  create_frame_distances(Dialogue,hbox);
  hbox = create_hbox(vboxframe);
  create_frame_angles(Dialogue,hbox);
  hbox = create_hbox(vboxframe);
  create_frame_dihedral(Dialogue,hbox);
  hbox = create_hbox(vboxframe);
  create_frame_averaged(Dialogue,hbox);

}
