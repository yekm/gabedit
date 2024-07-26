/********************************************************************************/
void read_geom_conv_from_dalton_output_file(gchar *NomFichier, gint numgeometry)
{
	gchar *t;
	gboolean OK;
	gchar *AtomCoord[5];
	FILE *fd;
	guint taille=BSIZE;
	guint i;
	gint j=0;
	gint l;
	guint numgeom;
	gchar dum[100];
	gint kk;

	for(i=0;i<5;i++) AtomCoord[i]=g_malloc(taille*sizeof(char));
  
	t=g_malloc(taille);
	fd = FOpen(NomFichier, "r");
	if(fd ==NULL)
	{
		g_free(t);
		t = g_strdup_printf("Sorry\nI can not open %s  file ",NomFichier);
		MessageGeom(t," Error ",TRUE);
		g_free(t);
		return;
	}
	numgeom = 0;
	do 
	{
		OK=FALSE;
		while(!feof(fd)){
			fgets(t,taille,fd);
			if(strstr(t,"Next geometry") || strstr(t,"Final geometry"))
			{
	  			fgets(t,taille,fd);
	  			fgets(t,taille,fd);
 				numgeom++;
				if((gint)numgeom == numgeometry ) { OK = TRUE; break; }
				if(numgeometry<0 ) { OK = TRUE; break; }
	  		}
		}
		if(!OK && (numgeom == 0) ){
			g_free(t);
			t = g_strdup_printf("Sorry\nI can not open %s  file ",NomFichier);
			MessageGeom(t," Error ",TRUE);
			g_free(t);
			return;
		}
		if(!OK)break;

		j=-1;
		while(!feof(fd) )
		{
			fgets(t,taille,fd);
			if ( !strcmp(t,"\n"))
			{
				get_dipole_from_dalton_output_file(fd);
				break;
			}
			j++;

			if(GeomXYZ==NULL) GeomXYZ=g_malloc(sizeof(GeomXYZAtomDef));
			else GeomXYZ=g_realloc(GeomXYZ,(j+1)*sizeof(GeomXYZAtomDef));

			kk = sscanf(t,"%s %s %s %s %s",AtomCoord[0],AtomCoord[1], AtomCoord[2],AtomCoord[3], dum);
			if(kk==5) sscanf(t,"%s %s %s %s %s",AtomCoord[0],dum, AtomCoord[1], AtomCoord[2],AtomCoord[3]);
			{
				gint k;
				for(k=0;k<(gint)strlen(AtomCoord[0]);k++) if(isdigit(AtomCoord[0][k])) AtomCoord[0][k] = ' ';
				delete_all_spaces(AtomCoord[0]);
			}

			AtomCoord[0][0]=toupper(AtomCoord[0][0]);
			l=strlen(AtomCoord[0]);
			if (l==2) AtomCoord[0][1]=tolower(AtomCoord[0][1]);
			GeomXYZ[j].Nentry=NUMBER_LIST_XYZ;
			GeomXYZ[j].Symb=g_strdup(AtomCoord[0]);
			GeomXYZ[j].Type=g_strdup(AtomCoord[0]);
			GeomXYZ[j].Residue=g_strdup(AtomCoord[0]);
			GeomXYZ[j].ResidueNumber=0;
			if(Units == 1 )
			{
				GeomXYZ[j].X=g_strdup(bohr_to_ang(AtomCoord[1]));
				GeomXYZ[j].Y=g_strdup(bohr_to_ang(AtomCoord[2]));
				GeomXYZ[j].Z=g_strdup(bohr_to_ang(AtomCoord[3]));
			}
			else
			{
				GeomXYZ[j].X=g_strdup(AtomCoord[1]);
				GeomXYZ[j].Y=g_strdup(AtomCoord[2]);
				GeomXYZ[j].Z=g_strdup(AtomCoord[3]);
			}
			GeomXYZ[j].Charge=g_strdup("0.0");
			GeomXYZ[j].Layer=g_strdup(" ");
		}

		NcentersXYZ = j+1;
		if(OK && numgeometry>=0) break;
	}while(!feof(fd));

	fclose(fd);
	g_free(t);
	for(i=0;i<5;i++) g_free(AtomCoord[i]);
	if(GeomIsOpen && MethodeGeom == GEOM_IS_XYZ)
	{
   		clearList(list);
		append_list();
	}
	MethodeGeom = GEOM_IS_XYZ;
	if(ZoneDessin != NULL) rafresh_drawing();
	if(iprogram == PROG_IS_GAUSS && GeomIsOpen) set_spin_of_electrons();
}
