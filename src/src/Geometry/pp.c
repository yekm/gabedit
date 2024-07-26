	gint hcd; /* the higher common divisor of both n and m */
	gint L;
	gfloat Rm;
	gfloat radius; /* tube radius */
	gint dR; 
	gint Nc; /* the number of two-atom unit cells in the translational cell */
	gfloat phi;
	gfloat t;
	gint p1;
	gint p2;
	gfloat alpha;
	gfloat h;
	gfloat* coord[4];
	gint i;

	if(m==0) hcd = n;
	else
	{
		for(hcd = m; hcd>=1; hcd--)
			if(n%hcd ==0 && m%hcd==0) break;
	}
	L = m*m+n*m+n*n;
	Rm = b*sqrt(3.0*L);
	radius = Rm/2.0/PI;
	if((n-m) % 3*hcd==0)
		dR = 3*hcd;
	else dR = hcd;

	Nc = 2*L/dR;
	for(i=0;i<4;i++)
		coord[i] = g_malloc(2*Nc*ncells*sizeof(float));
	phi = (PI*(m+n))/L;
	t = (b*(m-n)*(m-n))/(2*L);
	p1 = 0;
	p2 = 0;
	for(p1=0; p1<=n; p1++)
	{
		float pp2;
		pp2 = (float)(hcd+p1*m)/n;
		if(fabs(pp2 -(int)pp2)<1e-10)
		{
			p2 = (int)pp2;
			break;
		}
	}

	alpha = PI*(m*(2*p2+p1)+n*(2*p1+p2))/L;
	h = (3*hcd*b)/(2*sqrt(1.0*L));

	/* Set the first atom position in the two-atom unit cell */
	coord[0][0] = radius;
	coord[1][0] = 0.0;
	coord[2][0] = 0.0;
	coord[3][0] = 0.0;

	/* Set the second atom position in the two-atom unit cell */
	coord[0][1] = radius*cos(phi);
	coord[1][1] = radius*sin(phi);
	coord[2][1] = t;
	coord[3][1] = coord[3][0]+phi;
	/* Complete the tubule helical motif */
	for(i=2; i<2*hcd; i++)
	{
		coord[0][i] = radius*cos(coord[3][i-2]+(2*PI)/hcd);
		coord[1][i] = radius*sin(coord[3][i-2]+(2*PI)/hcd);
		coord[2][i] = coord[2][i-2];
		coord[3][i] = coord[3][i-2]+(2*PI)/hcd;
	}
	/* Complete the translational unit cell */
	for(i=2*hcd; i<2*Nc*ncells; i++)
	{
		coord[0][i] = radius*cos((coord[3][i-(2*hcd)])+alpha);
		coord[1][i] = radius*sin((coord[3][i-(2*hcd)])+alpha);
		coord[2][i] = coord[2][i-(2*hcd)]+h;
		coord[3][i] = coord[3][i-(2*hcd)]+alpha;
	}
	for(i=0;i<4;i++)
		g_free(coord[i]);
