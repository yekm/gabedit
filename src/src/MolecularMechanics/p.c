/********************************************************************************/
static void reset_traj_directory(GtkWidget *dirSelector, gpointer data)
{
	gchar* dirname = gabedit_folder_chooser_get_current_folder(GABEDIT_FOLDER_CHOOSER(dirSelector));

	if(dirname && strlen(dirname)>0)
	{
		if(dirname[strlen(dirname)-1] != G_DIR_SEPARATOR)
			dirNameTraj = g_strdup_printf("%s%s",dirname,G_DIR_SEPARATOR_S);
		else
			dirNameTraj = g_strdup_printf("%s",dirname);
	}
	else
		dirNameTraj = g_strdup(g_get_home_dir());
	if(dirname) g_free(dirname);
}
/********************************************************************************/
static void set_traj_directory(GtkWidget *win, gpointer data)
{
	GtkWidget *dirSelector;
	dirSelector = selctionOfDir(reset_traj_directory, "Set folder", GABEDIT_TYPEWIN_ORB);
	gtk_window_set_modal (GTK_WINDOW (dirSelector), TRUE);
	gtk_window_set_transient_for(GTK_WINDOW(dirSelector),GTK_WINDOW(PrincipalWindow));
	gtk_window_set_transient_for(GTK_WINDOW(dirSelector),GTK_WINDOW(WinDlg));
}
/********************************************************************************/
static void reset_properties_directory(GtkWidget *dirSelector, gpointer data)
{
	gchar* dirname = gabedit_folder_chooser_get_current_folder(GABEDIT_FOLDER_CHOOSER(dirSelector));

	if(dirname && strlen(dirname)>0)
	{
		if(dirname[strlen(dirname)-1] != G_DIR_SEPARATOR)
			dirNameProperties = g_strdup_printf("%s%s",dirname,G_DIR_SEPARATOR_S);
		else
			dirNameProperties = g_strdup_printf("%s",dirname);
	}
	else
		dirNameProperties = g_strdup(g_get_home_dir());
	if(dirname) g_free(dirname);
}
/********************************************************************************/
static void set_properties_directory(GtkWidget *win, gpointer data)
{
	GtkWidget *dirSelector;
	dirSelector = selctionOfDir(reset_properties_directory, "Set folder", GABEDIT_TYPEWIN_ORB);
	gtk_window_set_modal (GTK_WINDOW (dirSelector), TRUE);
	gtk_window_set_transient_for(GTK_WINDOW(dirSelector),GTK_WINDOW(PrincipalWindow));
	gtk_window_set_transient_for(GTK_WINDOW(dirSelector),GTK_WINDOW(WinDlg));
}
