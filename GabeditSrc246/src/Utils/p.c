/**********************************************/
void reset_dipole()
{
	gint i;
	init_dipole();
	for(i=0;i<3;i++) Dipole.value[i] = 0.0;
	Dipole.radius = atof(tentry)/AUTODEB;
	Dipole.color[0] = color->red;
	Dipole.color[1] = color->green;
	Dipole.color[2] = color->blue;
	for(i=0;i<3;i++) Dipole.Origin[i] = 0.0;
}
