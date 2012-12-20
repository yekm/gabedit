/********************************************************************************/
static void set_xyz_to_standard_orientation()
{
	gint i,j;

	gdouble* X;
	gdouble* Y;
	gdouble* Z;
	gchar** symbols;

	if(Natoms<1) return;

	X = g_malloc(Natoms*sizeof(gdouble));
	Y = g_malloc(Natoms*sizeof(gdouble));
	Z = g_malloc(Natoms*sizeof(gdouble));
	symbol = g_malloc(Natoms*sizeof(gchar*));

	for(i = 0;i<Natoms;i++)
	{
		X[i] = geometry0[i].X;
		Y[i] = geometry0[i].Y;
		Z[i] = geometry0[i].Z;
		symbols[i] = g_malloc(geometry0[i].Prop.symbol);
	}

	buildStandardOrientation(Natoms, symbols, X, Y, Z);

	for(i = 0;i<Natoms;i++)
	{
		geometry0[i].X = X[i];
		geometry0[i].Y = Y[i];
		geometry0[i].Z = Z[i];

		geometry[i].X = X[i];
		geometry[i].Y = Y[i];
		geometry[i].Z = Z[i];
	}

	if(symbols) for(i = 0;i<Natoms;i++) if(symbols[i]) g_free(symbols[i]);
	if(symbols) g_free(symbols);
	
	if(X) g_free(X);
	if(Y) g_free(Y);
	if(Z) g_free(Z);

	RebuildGeom = TRUE;
}
/********************************************************************************/
void set_xyz_to_standard_orientation_of_selected_atoms(gpointer data, guint Operation,GtkWidget* wid)
{
	gdouble axis1[3] = {1,0,0};
	gdouble axis2[3] = {0,1,0};
	gdouble axis3[3] = {0,0,1};
	gdouble C[3] = {0,0,0};
	int nFrag = compute_fragment_principal_axes(axis1,axis2,axis3,C,TRUE);
	if(nFrag <2 ) return;
	set_origin_to_point(C);
	if(Operation == 0) set_geom_to_axes(axis1, axis2, axis3);
	else set_geom_to_axes(axis3, axis2, axis1);
	create_GeomXYZ_from_draw_grometry();
	init_quat(Quat);
	RebuildGeom = TRUE;
	drawGeom();
}
