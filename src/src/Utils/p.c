/********************************************************************************/
void get_dipole_from_dalton_output_file(FILE* fd)
{
 	guint taille=BSIZE;
  	gchar *t = g_malloc(BSIZE*sizeof(gchar));
  	gchar* t1;
  	gchar* t2;
	gchar dum[100];

	Dipole.def = FALSE;

  	while(!feof(fd) )
	{
    		t1 = NULL;
    		if(!fgets(t,taille,fd))break;
    		t1 = strstr( t, "Dipole moment components");
		if(t1)
		{
    			if(!fgets(t,taille,fd))break;
    			if(!fgets(t,taille,fd))break;
    			if(!fgets(t,taille,fd))break;
    			if(!fgets(t,taille,fd))break;
    			t2 = strstr( t1, ":")+2;
    			if(!fgets(t,taille,fd))break;
			sscanf(t,"%s %f",dum, &Dipole.Value[0]);
    			if(!fgets(t,taille,fd))break;
			sscanf(t,"%s %f",dum, &Dipole.Value[1]);
    			if(!fgets(t,taille,fd))break;
			sscanf(t,"%s %f",dum, &Dipole.Value[2]);
			Dipole.def = TRUE;
		/*
			Debug("t =%s\n",t);
			Debug("Dipole = %f %f %f\n",Dipole.Value[0],Dipole.Value[1],Dipole.Value[2]);
		*/
			break;
		}
		else
		{
			if(strstr( t, ">>>>" )) break;
		}

	}
	g_free(t);
}
