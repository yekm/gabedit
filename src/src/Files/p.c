	   case GABEDIT_TYPEFILE_DALTON : 
					   gabedit_file_chooser_set_filter(GABEDIT_FILE_CHOOSER(gabeditFileChooser),"*.out");
					   temp = g_strdup_printf("%s.out",fileopen.projectname);
					   break;
