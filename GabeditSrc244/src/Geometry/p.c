/*************************************************************************************/
void read_Zmat_from_psicode_input_file(gchar *NomFichier)
{
	gchar *t;
 	gboolean OK;
 	gchar *AtomCoord[7];
 	FILE *file;
 	guint taille=BSIZE;
 	guint i;
 	gint j;
	gint k;
 	gboolean Uvar=FALSE;
 	GeomAtomDef* Geomtemp=NULL;
 	gint Ncent = 0;
 	gint Nvar = 0;
 	VariablesDef* Variablestemp=NULL;
 	gchar symb[BSIZE];
 	gchar type[BSIZE];
 	gchar charge[BSIZE];
	gint globalCharge, mult;
 
 	if ( strcmp(NomFichier,"") == 0 ) return;

	file = FOpen(NomFichier, "rb");
	OK=TRUE;
 	if(file==NULL)
	{
   		MessageGeom(_("Sorry\n I can not read geometry in Psicode input file"),_("Error"),TRUE);
   		return;
	}
	t=g_malloc(taille*sizeof(gchar));
	for(i=0;i<5;i++)
		AtomCoord[i]=g_malloc(taille*sizeof(char));

	 while(!feof(file))
	 {
		if(!fgets(t,taille,file))
		{
			OK = FALSE;
			break;
		}
		g_strup(t);
		if(strstr(t,"* INT") && 4==sscanf(t,"%s %s %d %d",AtomCoord[0],AtomCoord[1],&globalCharge, &mult) )
		{
			OK = TRUE;
			break;
		}
	 }

 	for(i=0;i<7;i++)
		AtomCoord[i]=g_malloc(taille*sizeof(gchar));
 

  	Ncent = 0;
  	while(!feof(file) && OK )
  	{
    		{ char* e = fgets(t,taille,file);}
                for(i=0;i<(gint)strlen(t);i++) if(t[i] != ' ') break;
                if(i<=(gint)strlen(t) && t[i] == '*') break;
		for(k=0;k<(gint)strlen(t);k++) if(t[k]=='{' || t[k]=='}') t[k] = ' ';

    		i = sscanf(t,"%s ",AtomCoord[0]);
                if(i != 1)
		{
			OK = FALSE;
			break;
		}
  		Ncent++;
		if(Ncent==1) Geomtemp=g_malloc(Ncent*sizeof(GeomAtomDef));
		else Geomtemp=g_realloc(Geomtemp,Ncent*sizeof(GeomAtomDef));
        	switch( Ncent ){
        	case 1 : 
  			Geomtemp[Ncent-1].Nentry=NUMBER_ENTRY_0;

			get_symb_type_charge(AtomCoord[0],symb,type,charge);
    			Geomtemp[Ncent-1].Symb = g_strdup(symb);
    			Geomtemp[Ncent-1].mmType = g_strdup(type);
    			Geomtemp[Ncent-1].pdbType = g_strdup(type);
  			Geomtemp[Ncent-1].Charge=g_strdup(charge);

  			Geomtemp[Ncent-1].Residue=g_strdup("DUM");
			Geomtemp[Ncent-1].ResidueNumber=0;
  			Geomtemp[Ncent-1].Layer=g_strdup(" ");
			break;
        	case 2 : 
                 	i =  sscanf(
				t,"%s %s %s %s %s",
				AtomCoord[0],AtomCoord[1],AtomCoord[2],
				AtomCoord[3],AtomCoord[4]
				);
                	if( i != 5 )
                	{
				Ncent--;
  				Geomtemp=g_realloc(Geomtemp,Ncent*sizeof(GeomAtomDef));
				OK = FALSE;
                	}
                        if( !test(AtomCoord[4]) ) Uvar = TRUE;
  			Geomtemp[Ncent-1].Nentry=NUMBER_ENTRY_R;

			get_symb_type_charge(AtomCoord[0],symb,type,charge);
    			Geomtemp[Ncent-1].Symb = g_strdup(symb);
    			Geomtemp[Ncent-1].mmType = g_strdup(type);
    			Geomtemp[Ncent-1].pdbType = g_strdup(type);
  			Geomtemp[Ncent-1].Charge=g_strdup(charge);

  			Geomtemp[Ncent-1].Residue=g_strdup("DUM");
			Geomtemp[Ncent-1].ResidueNumber=0;
  			Geomtemp[Ncent-1].NR=g_strdup(AtomCoord[1]);
  			Geomtemp[Ncent-1].R=g_strdup(AtomCoord[4]);
  			Geomtemp[Ncent-1].Layer=g_strdup(" ");
			break;
   		case 3 : 
                 	i =  sscanf(
				t,"%s %s %s %s %s %s",
				AtomCoord[0],AtomCoord[1],AtomCoord[2],
				AtomCoord[3],AtomCoord[4],AtomCoord[5]
				);
			if(i != 6) 
                	{
				Ncent--;
  				Geomtemp=g_realloc(Geomtemp,Ncent*sizeof(GeomAtomDef));
				OK = FALSE;
                	}
                        if(!test(AtomCoord[4]) || !test(AtomCoord[5]) )
                              Uvar = TRUE;
  			Geomtemp[Ncent-1].Nentry=NUMBER_ENTRY_ANGLE;

			get_symb_type_charge(AtomCoord[0],symb,type,charge);
    			Geomtemp[Ncent-1].Symb = g_strdup(symb);
    			Geomtemp[Ncent-1].mmType = g_strdup(type);
    			Geomtemp[Ncent-1].pdbType = g_strdup(type);
  			Geomtemp[Ncent-1].Charge=g_strdup(charge);

  			Geomtemp[Ncent-1].Residue=g_strdup("DUM");
			Geomtemp[Ncent-1].ResidueNumber=0;
  			Geomtemp[Ncent-1].NR=g_strdup(AtomCoord[1]);
  			Geomtemp[Ncent-1].R=g_strdup(AtomCoord[4]);
  			Geomtemp[Ncent-1].NAngle=g_strdup(AtomCoord[2]);
  			Geomtemp[Ncent-1].Angle=g_strdup(AtomCoord[5]);
  			Geomtemp[Ncent-1].Layer=g_strdup(" ");
			break;
        	default :
                 	i =  sscanf(
				t,"%s %s %s %s %s %s %s",
				AtomCoord[0],AtomCoord[1],AtomCoord[2],
				AtomCoord[3],AtomCoord[4],AtomCoord[5],AtomCoord[6]
				);
			if( i!= 7)
                 	{
				Ncent--;
  				Geomtemp=g_realloc(Geomtemp,Ncent*sizeof(GeomAtomDef));
				OK = FALSE;
                 	}
                        if(!test(AtomCoord[4]) || !test(AtomCoord[5]) || !test(AtomCoord[6]))
                              Uvar = TRUE;
  			Geomtemp[Ncent-1].Nentry=NUMBER_ENTRY_DIHEDRAL;

			get_symb_type_charge(AtomCoord[0],symb,type,charge);
    			Geomtemp[Ncent-1].Symb = g_strdup(symb);
    			Geomtemp[Ncent-1].mmType = g_strdup(type);
    			Geomtemp[Ncent-1].pdbType = g_strdup(type);
  			Geomtemp[Ncent-1].Charge=g_strdup(charge);

  			Geomtemp[Ncent-1].Residue=g_strdup("DUM");
			Geomtemp[Ncent-1].ResidueNumber=0;
  			Geomtemp[Ncent-1].NR=g_strdup(AtomCoord[1]);
  			Geomtemp[Ncent-1].R=g_strdup(AtomCoord[4]);
  			Geomtemp[Ncent-1].NAngle=g_strdup(AtomCoord[2]);
  			Geomtemp[Ncent-1].Angle=g_strdup(AtomCoord[5]);
  			Geomtemp[Ncent-1].NDihedral=g_strdup(AtomCoord[3]);
  			Geomtemp[Ncent-1].Dihedral=g_strdup(AtomCoord[6]);
  			Geomtemp[Ncent-1].Layer=g_strdup(" ");
	}/*end switch*/
  	}/*end while*/
/* Variables */
	Nvar=0;
	fseek(file, 0L, SEEK_SET);
	if(Uvar)
	{
		OK =FALSE;
  		while(!feof(file) && Uvar)
  		{
 			if(!fgets(t,taille,file)) break;
			g_strup(t);
			if(strstr(t,"PARAS")) 
			{
				OK = TRUE;
				break;
			}
  		}
  	}
	while(!feof(file) && Uvar && OK )
	{
		g_strup(t);
		for(k=0;k<(gint)strlen(t);k++) if(t[k]=='=') t[k] = ' ';
        	for(j=0;j<Ncent;j++)
		{
			gchar* co[3] = {Geomtemp[j].R,Geomtemp[j].Angle,Geomtemp[j].Dihedral};
        		for(k=0;k<3;k++)
			if(!test(co[k]))
			{
				gchar* b = strstr(t,co[k]);
				if(b) 
				{
					b = b+strlen(co[k])+1;
  					Nvar++;
  					if(Nvar==1) Variablestemp = g_malloc(Nvar*sizeof(VariablesDef));
  					else Variablestemp = g_realloc(Variablestemp,Nvar*sizeof(VariablesDef));
  					Variablestemp[Nvar-1].Name=g_strdup(co[k]);
  					Variablestemp[Nvar-1].Value=g_strdup_printf("%f",atof(b));
  					Variablestemp[Nvar-1].Used=TRUE;
				}
			}
		}
		if(strstr(t,"END")) break;
    		{ char* e = fgets(t,taille,file);}
  	}
/* end while variables */
	fclose(file);
	if(OK)
 	{
		TotalCharges[0] = globalCharge;
		SpinMultiplicities[0] = mult;
 	}

	g_free(t);
	for(i=0;i<7;i++) g_free(AtomCoord[i]);
	if( !OK || Ncent <1 )
	{
		FreeGeom(Geomtemp,Variablestemp,Ncent,Nvar);
		MessageGeom(_("Sorry\n I can not read geometry in Q-Chem input file"),_("Error"),TRUE);
		return;
	}
	if(Geom) freeGeom();
	if(Variables) freeVariables(Variables);
	Geom = Geomtemp;
	NcentersZmat = Ncent;
	NVariables = Nvar;
	Variables = Variablestemp;
	MethodeGeom = GEOM_IS_ZMAT;
	if( Units== 0 ) Geom_Change_Unit(FALSE);
	if(GeomIsOpen)
		create_geom_interface (GABEDIT_TYPEFILEGEOM_UNKNOWN);

	if(GeomDrawingArea != NULL) rafresh_drawing();
	set_last_directory(NomFichier);
}
