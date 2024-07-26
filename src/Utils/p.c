/**********************************************/
static gdouble GTFstarGTFstarGTFstarGTF(GTF* A,GTF* B, GTF* C, GTF* D)
{
	gdouble sum[3];
	gdouble t;
	gdouble PA[3];
	gdouble PB[3];
	gdouble QC[3];
	gdouble QD[3];
	gdouble P[3];
	gdouble Q[3];
	gdouble GP[3];
	gdouble GQ[3];
	gdouble gama1=A->Ex+B->Ex;
	gdouble gama2=C->Ex+D->Ex;
	gdouble gama=gama1+gama2;
	gdouble R2AB=0.0;
	gdouble R2CD=0.0;
	gdouble R2PQ=0.0;
	gdouble c = 0;
	gint iAB;
	gint i,j;

	for(j=0;j<3;j++)
	{
		t=(A->Ex*A->C[j]+B->Ex*B->C[j])/gama1;
		P[j]=t;
		PA[j]=A->C[j]-t;
		PB[j]=B->C[j]-t;
		R2AB += (A->C[j]-B->C[j])*(A->C[j]-B->C[j]);
	}
	for(j=0;j<3;j++)
	{
		t=(C->Ex*C->C[j]+D->Ex*D->C[j])/gama1;
		Q[j]=t;
		QC[j]=C->C[j]-t;
		QD[j]=D->C[j]-t;
		R2CD += (C->C[j]-D->C[j])*(C->C[j]-D->C[j]);
	}
	for(j=0;j<3;j++)
	{
		t=(gama1*P[j]+gama2*Q->C[j])/gama;
		GP[j]=P[j]-t;
		GQ[j]=Q[j]-t;
		R2PQ += (P[j]-Q[j])*(P[j]-Q[j]);
	}
	c = (PI/gama)*sqrt(PI/gama)
		*exp(-A->Ex*B->Ex/gama1*R2AB)*
		*exp(-C->Ex*D->Ex/gama2*R2CD)*
		exp(-gama1*gama2/gama*R2PQ);


	for(j=0;j<3;j++)
	{
		sum[j]=0.0;
		for(iAB=0;iAB<=(A->l[j]+B->l[j]);iAB++)
		{
			gdouble fiAB = f(iAB,A->l[j],B->l[j],PA[j],PB[j]);
			for(iCD=0;iCD<=(C->l[j]+D->l[j]);iCD++)
			{
				gdouble fiCD = f(iCD,C->l[j],D->l[j],QC[j],QD[j]);
				for(i=0;i<=(iAB+iCD)/2;i++)
				{
					sum[j] +=
					fiAB*
					fiCD*
					f(2*i,iAB,iCD,GP[j],GQ[j])*
					doubleFactorial(2*i-1)/(dpn(2.0,i)*dpn(gama,i));
	 			}
			}
		}
	}
	return  c*sum[0]*sum[1]*sum[2];
}
