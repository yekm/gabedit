#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <gtk/gtk.h>
#include "../Utils/Constants.h"

#include "ZlmMG.h"
#include "MathFunctions.h"

/********************************************************************/
/* Types */
typedef struct _Factorial Factorial;
typedef struct _DoubleFactorial DoubleFactorial;
typedef struct _Binomial Binomial;
typedef struct _Fprod Fprod;
typedef struct _ZlmMGTable ZlmMGTable;
typedef struct _Table2 Table2;
struct _Factorial { gdouble* data; gint nMax; };
struct _DoubleFactorial { gdouble* data; gint nMax; };
struct _Binomial { gdouble** data; gint nMax; };
struct _Fprod { gdouble** data; gint nMax; };
struct _ZlmMGTable { ZlmMG** data; gint lMax; };
struct _Table2 { gdouble** data; gint N1; gint N2; };
/* private methods */
static void initFactorial(gint max);
static void resizeFactorial(gint max);
static gdouble getValueFactorial(gint);

static void initDoubleFactorial(gint max);
static void resizeDoubleFactorial(gint max);
static gdouble getValueDoubleFactorial(gint);

static void initBinomial(gint max);
static void resizeBinomial(gint max);
static gdouble getValueBinomial(gint, gint);

static void initFprod(gint max);
static void resizeFprod(gint max);
static gdouble getValueFprod(gint, gint);

static void initZlmMGTable(gint max);
static void resizeZlmMGTable(gint max);
static ZlmMG getValueZlmMGTable(gint, gint);
/********************************************************************/
static Factorial* f = NULL;
/********************************************************************/
gdouble factorial(gint n)
{
	return getValueFactorial(n);
}
/********************************************************************/
static void initFactorial(gint max)
{
	gint i;

	if(max<1) max = 1;
	if(!f) g_free(f);
	f = g_malloc(sizeof(Factorial));
	f->nMax = max;
	f->data = g_malloc((f->nMax+1)*sizeof(gdouble));
	f->data[0] = 1.0;
	for( i=1;i<f->nMax+1;i++)
	{
		f->data[i] = f->data[i-1]*i;
	}
}
/********************************************************************/
static void resizeFactorial(gint max)
{
	gint i;
	gint min;
	gdouble* dataNew =NULL;
	if(max<1) max = 1;
	if(f==NULL || f->data == NULL)
	{
		initFactorial(max);
		return;
	}
	dataNew =g_malloc((max+1)*sizeof(gdouble));
	min =(f->nMax>max)?max:f->nMax;
	for(i=0;i<min+1;i++)
	{
		dataNew[i] = f->data[i];
	}
	for(i=min+1;i<max+1;i++)
	{
		dataNew[i] = dataNew[i-1]*i;
	}
	f->nMax = max;
	g_free(f->data);
	f->data = dataNew;
}
/********************************************************************/
static gdouble getValueFactorial(gint n)
{
	if(n<=1) return 1.0;
	if(!f) 
	{
		if(n>10) resizeFactorial(n);
		else resizeFactorial(10);
	}
	if(n>f->nMax) resizeFactorial(n);
	return f->data[n];
}
/********************************************************************/
void destroyFactorial()
{
	if(f && f->data) g_free(f->data);
	if(f) g_free(f);
	f = NULL; 
}
/********************************************************************/
static DoubleFactorial* df = NULL;
/********************************************************************/
gdouble doubleFactorial(gint n)
{
	return getValueDoubleFactorial(n);
}
/********************************************************************/
static void initDoubleFactorial(gint max)
{
	gint i;
	if(max<1) max = 1;
	if(!df) g_free(df); 
	df = g_malloc(sizeof(DoubleFactorial));
	df->nMax = max;
	df->data = g_malloc((df->nMax+1)*sizeof(gdouble));
	df->data[0] = 1.0;
	for(i=2;i<df->nMax+1;i+=2)
	{
		df->data[i] = df->data[i-2]*i;
	}
	df->data[1] = 1.0;
	for(i=3;i<df->nMax+1;i+=2)
	{
		df->data[i] = df->data[i-2]*i;
	}
}
/********************************************************************/
static void resizeDoubleFactorial(gint max)
{
	gint i;
	gint min;
	gdouble* dataNew =NULL;

	if(max<1) max = 1;
	if(df==NULL || df->data == NULL)
	{
		initDoubleFactorial(max);
		return;
	}
	dataNew =g_malloc((max+1)*sizeof(gdouble));
	min =(df->nMax>max)?max:df->nMax;
	for(i=0;i<min+1;i++)
	{
		dataNew[i] = df->data[i];
	}
	for(i=min+1;i<max+1;i+=2)
	{
		dataNew[i] = dataNew[i-2]*i;
	}
	for(i=min+2;i<max+1;i+=2)
	{
		dataNew[i] = dataNew[i-2]*i;
	}
	df->nMax = max;
	if(df->data) g_free(df->data);
	df->data = dataNew;
}
/********************************************************************/
static gdouble getValueDoubleFactorial(gint n)
{
	if(n<=1) return 1.0;
	if(!df) 
	{
		if(n>10) resizeDoubleFactorial(n);
		else resizeDoubleFactorial(10);
	}
	if(n>df->nMax) resizeDoubleFactorial(n);
	return df->data[n];
}
/********************************************************************/
void destroyDoubleFactorial()
{
	if(df && df->data) g_free(df->data);
	if(df) g_free(df);
	df = NULL;
}
/********************************************************************/
static Binomial* b = NULL;
/********************************************************************/
gdouble binomial(gint i, gint j)
{
	return getValueBinomial(i, j);
}
/********************************************************************/
static void initBinomial(gint max)
{
	gint i,j;
	if(max<1) max = 1;
	if(b) g_free(b); 
	b = g_malloc(sizeof(Binomial));
	b->nMax = max;
	b->data = g_malloc((b->nMax+1)*sizeof(gdouble*));
	for( i=0;i<b->nMax+1;i++)
		b->data[i] = g_malloc((i+1)*sizeof(gdouble));

	for( i=0;i<b->nMax+1;i++)
	for( j=0;j<=i;j++)
		b->data[i][j] = factorial(i)/factorial(j)/factorial(i-j);
}
/********************************************************************/
static void resizeBinomial(gint max)
{
	gint i,j;
	gint min;
	gdouble** dataNew = NULL;
	if(max<1) max = 1;
	if(b==NULL || b->data == NULL)
	{
		initBinomial(max);
		return;
	}
	dataNew = g_malloc((max+1)*sizeof(gdouble*));
	for( i=0;i<max+1;i++)
		dataNew[i] =  g_malloc((i+1)*sizeof(gdouble));

	min =(b->nMax>max)?max:b->nMax;
	for( i=0;i<min+1;i++)
	for( j=0;j<=i;j++)
	{
		dataNew[i][j] = b->data[i][j];
	}
	for( i=min+1;i<max+1;i++)
	for( j=0;j<=i;j++)
	{
		dataNew[i][j] = factorial(i)/factorial(j)/factorial(i-j);
	}
	if(b->data)
	{
		for( i=0;i<b->nMax+1;i++) g_free(b->data[i]);
		g_free(b->data);
	}

	b->nMax = max;
	b->data = dataNew;
}
/********************************************************************/
static gdouble getValueBinomial(gint i, gint j)
{
	if(j>i)
	{
		gint c = i;
		i = j;
		j = c;
	}

	if(i<=1) return 1.0;
	if(!b)
	{
		if(i>10) resizeBinomial(i);
		else resizeBinomial(10);
	}
	if(i>b->nMax) resizeBinomial(i);
	return b->data[i][j];
}
/********************************************************************/
void destroyBinomial()
{
	if(b)
	{
		if(b->data)
		{
			gint i;
			for( i=0;i<b->nMax+1;i++) g_free(b->data[i]);
			g_free(b->data);
		}
		g_free(b);
	}
	b = NULL;
}
/********************************************************************/
static Fprod* fp = NULL;
/********************************************************************/
gdouble fprod(gint i, gint j)
{
	return getValueFprod(i, j);
}
/********************************************************************/
static void initFprod(gint max)
{
	gint i,j;
	if(max<1) max = 1;

	if(fp) g_free(fp); 
	fp = g_malloc(sizeof(Fprod));

	fp->nMax = max;
	fp->data = g_malloc((fp->nMax+1)*sizeof(gdouble*));
	for( i=0;i<fp->nMax+1;i++)
		fp->data[i] = g_malloc((i+1)*sizeof(gdouble));

	for( i=0;i<fp->nMax+1;i++)
	{
		fp->data[i][0] = 1.0;
		for( j=1;j<=i;j++)
			fp->data[i][j] = fp->data[i][j-1]*(gdouble)(i-j+1)*(gdouble)(i+j)/(gdouble)(j);
	}
}
/********************************************************************/
static void resizeFprod(gint max)
{
	gint i;
	gint j;
	gint min;
	gdouble** dataNew = NULL;

	if(max<1) max = 1;
	if(fp==NULL ||fp->data == NULL)
	{
		initFprod(max);
		return;
	}
	dataNew = g_malloc((max+1)*sizeof(gdouble*));
	for( i=0;i<max+1;i++)
		dataNew[i] =  g_malloc((i+1)*sizeof(gdouble));

	min =(fp->nMax>max)?max:fp->nMax;
	for( i=0;i<min+1;i++)
	for( j=0;j<=i;j++)
	{
		dataNew[i][j] = fp->data[i][j];
	}
	for( i=min+1;i<max+1;i++)
	{
		dataNew[i][0] = 1.0;
		for( j=1;j<=i;j++)
			dataNew[i][j] = dataNew[i][j-1]*(gdouble)(i-j+1)*(gdouble)(i+j)/(gdouble)(j);
	}

	if(fp->data)
	{
		for( i=0;i<fp->nMax+1;i++) g_free(fp->data[i]);
		g_free(fp->data);
	}

	fp->nMax = max;
	fp->data = dataNew;
}
/********************************************************************/
static gdouble getValueFprod(gint i, gint j)
{
	if(j>i)
	{
		gint c = i;
		i = j;
		j = c;
	}

	if(i<=0) return 1.0;
	if(!fp)
	{
		if(i>10) resizeFprod(i);
		else resizeFprod(10);
	}
	if(i>fp->nMax) resizeFprod(i);
	return fp->data[i][j];
}
/********************************************************************/
void destroyFprod()
{
	if(fp)
	{
		gint i;
		if(fp->data)
		{
			for( i=0;i<fp->nMax+1;i++) g_free(fp->data[i]);
			g_free(fp->data);
		}
		g_free(fp);
	}
	fp = NULL;
}
/********************************************************************/
static ZlmMGTable *z = NULL;
/********************************************************************/
ZlmMG fZlmMG(gint l, gint m)
{
	return getValueZlmMGTable(l, m);
}
/********************************************************************/
static void initZlmMGTable(gint max)
{
	gint l,m;
	if(max<0) max = 0;
	if(z) g_free(z);
	z = g_malloc(sizeof(ZlmMGTable));
	z->lMax = max;
	z->data = g_malloc((z->lMax+1)*sizeof(ZlmMG*));
	for( l=0;l<=z->lMax;l++)
		z->data[l] = g_malloc((2*l+1+1)*sizeof(ZlmMG));

	for( l=0;l<=z->lMax;l++)
		for( m=-l;m<=l;m++)
			z->data[l][m+l] = getZlmMG(l,m);
}
/********************************************************************/
static void resizeZlmMGTable(gint max)
{
	if(!z && max<5) initZlmMGTable(5);
	else initZlmMGTable(max);
}
/********************************************************************/
static ZlmMG getValueZlmMGTable(gint l, gint m)
{
	if(m>l) m = l;
	if(m<-l) m = -l;
	if(!z)
	{
		if(l>10) resizeZlmMGTable(l);
		else resizeZlmMGTable(10);
	}

	if(l>z->lMax) resizeZlmMGTable(l);
	return z->data[l][m+l];
}
/********************************************************************/
void destroyZlmMGTable()
{
	gint l;
	if(z)
	{
		for(l=0;l<=z->lMax;l++) if(z->data[l]) g_free(z->data[l]);
		if(z->data) g_free(z->data);
	}
	z = NULL;
}
/********************************************************************/
static Table2 getNewTable2(gint n1,gint n2)
{
	Table2 t;
	t.N1 = n1;
	t.N2 = n2;
	if(n1<1) t.N1 = 1;
	if(n2<1) t.N2 = 1;
	t.data = g_malloc(t.N1*t.N2*sizeof(gdouble));
	return t;
}
/********************************************************************/
gdouble getValueTable2(Table2* t, gint i, gint j)
{
	if(i>j) { gint a = i; i=j; j = a;};
	if(i<0) i = 0;
	if(j<0) j = 0;
	if(i<t->N1-1) i = t->N1-1;
	if(j<t->N2-1) j = t->N2-1;
	return t->data[i][j];
}
/********************************************************************/
void setValueTable2(Table2* t, gint i, gint j, gdouble v)
{
	if(i>j) { gint a = i; i=j; j = a;};
	if(i<0) i = 0;
	if(j<0) j = 0;
	if(i<t->N1-1) i = t->N1-1;
	if(j<t->N2-1) j = t->N2-1;
	t->data[i][j] = v;
}
/*********************************************************************/
static gint m1p(gint i)
{
	if(i%2==0)
		return 1;
	else
		return -1;
}
/********************************************************************/
gdouble modifiedSphericalBessel(gint l, gdouble z)
{
	/* evaluates modified spherical bessel function.*/
	/* scaled by exp(-z) to prevent overflows */
	static gdouble acc = 5.0e-14;
	gint k;

	if (z<0.0)
		return 0.0;
	
	if(z==0)
	{
		if(l != 0) return 0.0;
		return 1.0;
	}

	if(z<=5.0)
	{
		gdouble zp = z*z/2.0;
		gdouble term =pow(z,l)/doubleFactorial(l+l+1);
		gdouble bess=term;
		gint j=0;
		while(fabs(term/bess)>acc)
		{
			j=j+1;
			term=term*zp/(gdouble)(j*(l+l+j+j+1));
			bess += term;
		}
		bess *=exp(-z);
		return bess;
	}
	if(z<=16.1)
	{
		gdouble rp=0.0;
		gdouble rm=0.0;
		gdouble tzp=2.0*z;
		gdouble tzm=-tzp;
		for( k = 0; k<=l ; k++)
		{
			rp +=fprod(l,k)/pow(tzp,k);
			rm +=fprod(l,k)/pow(tzm,k);
		}
		gdouble bess=(rm-m1p(l)*rp*exp(tzm))/tzp;
		return bess;
	}
	gdouble rm=0.0;
	gdouble tzm=-2.0*z;
	for( k=0; k<=l; k++)
		rm +=fprod(l,k)/pow(tzm,k);

	gdouble bess=rm/(-tzm);
	return bess;
}
/*********************************************************************/
void modifiedSphericalBessel0(gint l, gdouble z[], gdouble b[], gint n)
{
/*

     this routine evaluates modified spherical bessel functions.
     vector version.

     the arguments:
       b[]  bessel function at requested points.
       z[]  the points at which the function is to be evaluated.
             assumed to be in ascending order.
       l    the l value of the function.
       n    the number of requested points.


       for arguments (z.le.5.0)  use power series
                                 15 terms good to 5.0d-14
                     (z.gt.5.0)  use exponential representation.
                     (z.gt.16.1) only first term in exponential
                                 representation is required.

     result has a factor of exp(-z) included to avoid overflow.

*/

/*     determine the number of points in each region.*/
	gint ilo1 = 0, ilo2 = 0, ilo3 = 0;
	gint n1 = 0, n2 = 0, n3 = 0;

	static gdouble* zp = NULL;
	static gdouble* rp = NULL;
	static gdouble* rm = NULL;
	static gdouble* tzmi = NULL;
	static gdouble* texm = NULL;
	gint i,j,k1;
	Table2 denm;
	Table2 denp;
	gint ihi1;
	gint ihi2;
	gint ihi3;

	if(zp==NULL)
	{
		zp = g_malloc((125+1)*sizeof(gdouble));
		rp = g_malloc((125+1)*sizeof(gdouble));
		rm = g_malloc((125+1)*sizeof(gdouble));
		tzmi = g_malloc((125+1)*sizeof(gdouble));
		texm = g_malloc((125+1)*sizeof(gdouble));
	}
	if(n>125)
	{
		g_free(zp);
		g_free(rp);
		g_free(rm);
		g_free(tzmi);
		g_free(texm);
		zp = g_malloc((n+1)*sizeof(gdouble));
		rp = g_malloc((n+1)*sizeof(gdouble));
		rm = g_malloc((n+1)*sizeof(gdouble));
		tzmi = g_malloc((n+1)*sizeof(gdouble));
		texm = g_malloc((n+1)*sizeof(gdouble));

	}

	denm = getNewTable2(n+1,l+2);
	denp = getNewTable2(n+1,l+2);

	for( i=1; i<=n; i++)
	{
		if(z[i]<0)
		{
			b[i] = 0;
			continue;
		}
		if(z[i]==0)
		{
			b[i] = 0;
			if(l==0) b[i] = 1.0;
			continue;
		}
		if(z[i]<=5.0)
		{
			if(ilo1==0) ilo1 = i;
			n1++;
			continue;
		}
		if(z[i]<=16.1)
		{
			if(ilo2==0) ilo2 = i;
			n2++;
			continue;
		}
		if(ilo3==0) ilo3 = i;
		n3++;

	}

	ihi1=ilo1+n1-1;
	ihi2=ilo2+n2-1;
	ihi3=ilo3+n3-1;

	if(n1 != 0)
	{
		/*power series.*/
		gdouble v = 1.0/doubleFactorial(l+l+1);
		for( i = ilo1; i<= ihi1; i++)
		{
			zp[i]=z[i]*z[i]*0.5;
			rm[i]=pow(z[i],l)*v;
			b[i]=rm[i];
		}

		for( j=1; j<=15; j++)
			rp[j]=1.0/(gdouble)(j*(l+l+j+j+1));

		for( j=1; j<=15; j++)
		for( i = ilo1; i<= ihi1; i++)
		{
				rm[i] *=zp[i]*rp[j];
				b[i]=b[i]+rm[i];
		}

		for( i = ilo1; i<= ihi1; i++)
			b[i] *=exp(-z[i]);
	}
	if(n2 != 0)
	{
		/* exponential represention.*/
		gint l1=l+1;
		gdouble tzi;
		gdouble v = fprod(l,0);
		for( i = ilo2; i<= ihi2; i++)
		{
			rp[i]=v;
			rm[i]=v;
			tzi=2.0*z[i];
			zp[i]=1.0/tzi;
			tzmi[i]=-zp[i];
			texm[i]=exp(-tzi);
			setValueTable2(&denm, i,1,1.0);
			setValueTable2(&denp, i,1,1.0);
		}
		if(l1>1)
		{
		   for( k1=2; k1<=l1; k1++)
			for( i = ilo2; i<= ihi2; i++)
			{
				setValueTable2(&denp,i,k1,getValueTable2(&denp,i,k1-1)*zp[i]);
				setValueTable2(&denm, i,k1, getValueTable2(&denm,i,k1-1)*tzmi[i]);

			}
		   for( k1=2; k1<=l1; k1++)
			for( i = ilo2; i<= ihi2; i++)
			{
				rp[i] += getValueTable2(&denp,i,k1)*fprod(l, k1-1);
				rm[i] += getValueTable2(&denm,i,k1)*fprod(l, k1-1);
			}
		}
		v =  m1p(l);
		for( i = ilo2; i<= ihi2; i++)
			b[i]=(rm[i]-v*rp[i]*texm[i])*zp[i];
	}

	/*only first term in exponential representation.*/
	if(n3 != 0)
	{
		gint l1=l+1;
		gdouble v = fprod(0,l);
		for( i = ilo3; i<= ihi3; i++)
		{
			rm[i]=v;
			tzmi[i]=-0.5/z[i];
			setValueTable2(&denm, i,1,1.0);
		}
		if(l1>1)
		{
			for( k1=2; k1<=l1; k1++)
				for( i = ilo3; i<= ihi3; i++)
					setValueTable2(&denm,i,k1,getValueTable2(&denm,i,k1-1)*tzmi[i]);
			for( k1=2; k1<=l1; k1++)
				for( i = ilo3; i<= ihi3; i++)
					rm[i] += getValueTable2(&denm,i,k1)*fprod(k1-1,l);
		}
		for( i = ilo3; i<= ihi3; i++)
			b[i]=-rm[i]*tzmi[i];
	}
}
