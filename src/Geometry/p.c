/********************************************************************************/
static void rotate_slected_atoms_minimize_rmsd()
{
	gint i,j;

	gint nA = 0;
	gint nB = 0;
	const gint N = 8;
        gdouble d[N];
        gdouble w[N][3] = {
                {1,1,1},
                {-1,1,1},
                {1,-1,1},
                {1,1,-1},
                {-1,-1,1},
                {-1,1,-1},
                {1,-1,-1},
                {-1,-1,-1}
        };
        gdouble x, y, z;
	gint* numA = NULL;
	gint* numB = NULL;
	gint iA, iB;

	if(Natoms<1) return;

	j = 0;
	for(i = 0;i<Natoms;i++)
		if(if_selected(i)) nA++;

	nB = Natoms - nA;
	if(nA!=nB || nA == 0) return;
	numA = g_malloc(nA*sizeof(gint));
	numB = g_malloc(nB*sizeof(gint));
        for (i=0;i<nA;i++) numA[i] = -1;
        for (i=0;i<nA;i++) numB[i] = -1;

	iA = iB = 0;
	for(i = 0;i<Natoms;i++)
		if(if_selected(i)) numA[iA++] = i;
		else numB[iB++] = i;

	for(i = 0;i<nA;i++)
	if(strcmp(geometry[numA[i]].Prop.symbol, geometry[numB[i]].Prop.symbol))
	{
		g_free(numA);
		g_free(numB);
		return;
	}

        for (j=0;j<N;j++) d[j] = 0;
        for (i=0;i<nA;i++)
        {
                for (int j=0;j<N;j++)
                {
                x = geometry[numA[i]].X + w[j][0]*geometry[numB[i]].X;
                y = geometry[numA[i]].Y + w[j][1]*geometry[numB[i]].Y;
                z = geometry[numA[i]].Z + w[j][2]*geometry[numB[i]].Z;
                d[j] += x*x + y*y + z*z;
                }
        }
        double dmin = d[0];
	int jmin = 0;
        for (int j=1;j<N;j++) if(dmin>d[j]) {dmin=d[j]; jmin = j}:
        for (i=0;i<nA;i++)
	{
                geometry[numB[i]].X *=  w[jmin][0];
                geometry[numB[i]].Y *=  w[jmin][1];
                geometry[numB[i]].Z *=  w[jmin][2];
	}


	RebuildGeom = TRUE;
}
