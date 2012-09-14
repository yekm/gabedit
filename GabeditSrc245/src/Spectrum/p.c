/********************************************************************************/
static gboolean read_psicode_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;
 	gchar t[BSIZE];
 	gchar sdum1[BSIZE];
 	gboolean OK;
 	FILE *fd;
 	guint taille=BSIZE;
	gint numberOfFrequencies = 0;
	gdouble *frequencies = NULL;
	gdouble *intensities = NULL;

	if(response_id != GTK_RESPONSE_OK) return FALSE;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);

 	fd = FOpen(FileName, "rb");
	if(!fd) return FALSE;

 	do 
 	{
 		OK=FALSE;
		while(!feof(fd) )
                {
                        if(!fgets(t,taille,fd)) break;
                        if(strstr(t,"Projected Infra Red Intensities"))
                        {
				numberOfFrequencies = 0;
				if(frequencies) g_free(frequencies);
				if(intensities) g_free(intensities);
				frequencies = NULL;
				intensities = NULL;
                                if(!fgets(t,taille,fd)) break;
                                if(!fgets(t,taille,fd)) break;
                                 while(!feof(fd) )
                                {
                                        if(!fgets(t,taille,fd)) break;
					if(strstr(t,"---------"))break;
					numberOfFrequencies++;
					frequencies = g_realloc(frequencies, numberOfFrequencies*sizeof(gdouble));
					intensities = g_realloc(intensities, numberOfFrequencies*sizeof(gdouble));
                                        sscanf(t,"%s %lf %s %s %s %lf", sdum1,&frequencies[numberOfFrequencies-1],sdum1,sdum1,sdum1, &intensities[numberOfFrequencies-1]);
                                }
				OK = TRUE;
                        }
                }
		if(!OK) break;
 	}while(!feof(fd));

	if(numberOfFrequencies>0)
	{
		createIRSpectrumWin(numberOfFrequencies, frequencies, intensities);
	}
	else
	{
		messageErrorFreq(FileName);
	}


	if(frequencies) g_free(frequencies);
	if(intensities) g_free(intensities);
	fclose(fd);

	return TRUE;
}
