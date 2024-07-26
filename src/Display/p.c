/*****************************************/
void compute_charge_transfer_dipole()
{
	gdouble D[3];
	int c;
	gdouble CN[3];
	gdouble CP[3];
	gdouble QCTp;
	gdouble QCTm;
	if(!grid)
	{
		GtkWidget* message =Message(_("Sorry, Grid not defined "),_("Error"),TRUE);
  		gtk_window_set_modal (GTK_WINDOW (message), TRUE);
		return;
	}
	if(!get_charge_transfer_centers(grid, CN, CP, QCTp, QCTm)) return;

	for(c=0;c<3;c++)
		D[c] = CP[c] - CN[c];

	Dipole.def = TRUE;
	for(c=0;c<3;c++)
		Dipole.value[c] = D[c]*(fabs(QCTp)+fabs(QCTm))/2;

	gchar* str = NULL;
	gchar* tmp = NULL;
	str = g__strdup_printf("Index of Spatial Extent in Charge-Transfer Excitations\n");

	tmp = str;
	str = g_strdup_printf("%s Center of negative charges(Bohr) = %f %f %f\n",tmp,CN[0],CN[1],CN[2]);
	g_free(tmp);

	tmp = str;
	str = g_strdup_printf("%s Center of positive charges(Bohr) = %f %f %f\n",tmp,CP[0],CP[1],CP[2]);
	g_free(tmp);

	tmp = str;
	str = g_strdup_printf("%s Sum of positive density difference = %f\n",tmp,QCTp);
	g_free(tmp);

	tmp = str;
	str = g_strdup_printf("%s Sum of negative density difference = %f\n",tmp,QCTp);
	g_free(tmp);

	for(c=0;c<3;c++) CP[c] *= ANGTOBOHR;
	for(c=0;c<3;c++) CM[c] *= ANGTOBOHR;

	tmp = str;
	str = g_strdup_printf("%s Center of negative charges(Ang) = %f %f %f\n",tmp,CN[0],CN[1],CN[2]);
	g_free(tmp);

	tmp = str;
	str = g_strdup_printf("%s Center of positive charges(Ang) = %f %f %f\n",tmp,CP[0],CP[1],CP[2]);
	g_free(tmp);

	tmp = str;
	str = g_strdup_printf("%s Dipole (Debye) = %f %f %f\n",tmp,Dipole.value[0],Dipole.value[1],Dipole.value[2]);
	g_free(tmp);

	pritnf("%s",str);
	g_free(str);
}
