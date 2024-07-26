/* NMRSpectrum.c */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Jacobi.h"
#include "TQLI.h"

#define NMAXGROUP 20
typedef int gboolean;
#define TRUE 1
#define FALSE 0
#define BSIZE 1024

/********************************************************************************/
gboolean this_is_a_backspace(char *st)
{
        int i;
        for(i=0;i<(int)strlen(st);i++)
        	if(st[i] != ' ' && st[i] !='\n' && st[i] !='\r')
                	return FALSE;
        return TRUE;
}   
/********************************************************************************/
static void initTables(int nSpins, int* binomialCoef, int* basis, int *start)
{
	/* binomialCoef binomial coefficients. nSpins+1 elements */
	/* bIndex element i is locn of fn i in basis[] */
	/* start indexes to successive Fz blocks in basis[]. nSpins+1 elements */
	/* basis : coded basis functions  : 2**nSpins*nSpins*/
	int m,k,i,j,ik;
	int nBasis;
	int* sumSpin = NULL;

	binomialCoef[0] = 1;
	start[0] = 0;
	for(i=1, k=nSpins, m=1;  i<=nSpins;  i++, k--, m++)
	{
		binomialCoef[i] = (binomialCoef[i-1] * k) / m;
		start[i] = start[i-1] + binomialCoef[i-1];
	}
	nBasis = 1 << nSpins;
	/* basis = -1 (alpha) or +1(beta) */
	for ( i=0 ; i<nBasis ; i++ )
	{
		int a=i;
		for ( j=0 ; j<nSpins ; j++ )
		{
			int b=1<<(nSpins-j-1) ;
			k=nSpins-j-1;
			ik = i+k*nBasis;
			basis[ik]=a/b;
			a=a-b*basis[ik] ;
			if ( basis[ik] == 0 ) basis[ik]=-1 ;
		}
	}
	sumSpin = malloc(nBasis*sizeof(int));
	for ( i=0 ; i<nBasis ; i++ )
	{
		int is = 0;
		for ( j=0 ; j<nSpins ; j++ )
			is +=basis[i+j*nBasis];
		sumSpin[i] = is;
	}
	for ( i=0 ; i<nBasis-1 ; i++ )
	{
		int k = i;
		for ( j=i+1 ; j<nBasis ; j++ )
			if(sumSpin[k]>sumSpin[j]) k = j;
		if(k!=i)
		{
			int t = sumSpin[k];
			sumSpin[k]= sumSpin[i];
			sumSpin[j]= t;
			for ( j=0 ; j<nSpins ; j++ )
			{
				t = basis[i+j*nBasis];
				basis[i+j*nBasis] = basis[k+j*nBasis];
				basis[k+j*nBasis] = t;
			}
		}
	}
	free(sumSpin);
	/*
	for ( i=0 ; i<nBasis ; i++ )
	{
		int is = 0;
		for ( j=0 ; j<nSpins ; j++ )
		{
			printf("%d ",basis[i+j*nBasis]);
			is +=basis[i+j*nBasis];
		}
		printf(" S=%d ",is);
		printf("\n");
	}
	printf("End Basis\n");
	for(i=0;  i<=nSpins;  i++)
		printf("Block # %d bnom = %d start = %d\n",i+1,binomialCoef[i],start[i]);
		*/
}
/********************************************************************************/
static void buildFreqAndJ( double operatingFrequency, int nGroups, 
		int* numberOfSpins, double* chemichalShifts, double** JCouplings, 
		int nCoup, double* frequencies, double* ppmJCouplings)
{
	int nSpins = 0 ;
	int k = 0 ;
	int iGroup = -1 ;
	int jGroup = -1 ;
	int jj,ii;
	jj = -1 ;
	nSpins = 0;
	for (iGroup=0 ; iGroup<nGroups ; iGroup++ )
   		for ( k=0 ; k<numberOfSpins[iGroup] ; k++ )
		{
			frequencies[nSpins] = chemichalShifts[iGroup] ;
			/* printf("nSpins = %d f = %f\n",nSpins, frequencies[nSpins]);*/
			nSpins++ ; 
		   	for ( jGroup=0 ; jGroup<iGroup ; jGroup++ )
		   	{
           			for ( ii=0 ; ii<numberOfSpins[jGroup] ; ii++ )
				{
   					jj++ ; 
					/* printf("iGroup = %d jGroupe= %d",iGroup, jGroup);*/
					ppmJCouplings[jj] = JCouplings[iGroup][jGroup]/operatingFrequency ;
					/* printf("jx = %f ",ppmJCouplings[jj]);*/
				}
   			}
			/* equivalent nucleus */
			for ( ii=0 ; ii<=k ; ii++ )
			{
				   jj++;
				   ppmJCouplings[jj]=0 ;
				/* printf("jx = %f ",ppmJCouplings[jj]);*/
			}
			/* printf("\n");*/
		}

}
/********************************************************************************/
static void buildHamiltonianOneBlock(int istart, int size,
	int nBasis, int nSpins,
	double* frequencies,
	double* ppmJCouplings,
	int* basis ,
	double* hamilt)
{
	int i = 0;
	int j = 0 ;
	int k = 0 ;
	int l = 0 ;
	int ja, jb;
	int ii, ik, is;
	double dum;
	int dumja, dumjb;

	/* diagonal elements of hamiltonian*/
	ii=0 ;
	for ( i=istart ; i<istart+size ; i++ )
	{
		dum=0.0 ;
  		ik = -1 ;
		for ( l=0 ; l<nSpins ; l++ )
		{
			ik++ ;
			dum += frequencies[l]*basis[i+l*nBasis]/2 ;
			for ( k=0 ; k<l ; k++ )
			{
		  		dum=dum+ppmJCouplings[ik]*basis[i+l*nBasis]*basis[i+k*nBasis]/4. ;
				ik++;
			}
		}
		ii=ii+i+1 -istart;
		hamilt[ii-1]=dum ;
		/* printf("hamilt[%d] = %f\n",ii-1, hamilt[ii-1]);*/
	}
	/* printf("End calculate diagonal elements of hamiltonian\n");*/

//	calculate off diagonal elements of hamiltonian
	ii=-1 ;
	for ( ja=istart+1 ; ja<istart+size ; ja++)
	{
		ii=ii+1 ;
		for ( jb=istart ; jb<ja; jb++ )
		{
			ii=ii+1 ;
			is=0 ; dumja=0 ; dumjb=0 ;
			/* to delete ? */
		   	for ( i=0; i<nSpins ; i++ )
			{
				is+=basis[ja+i*nBasis]*basis[jb+i*nBasis] ;
        			dumja+=basis[ja+i*nBasis] ;
        			dumjb+=basis[jb+i*nBasis] ;
			}
			if ( (dumja != dumjb) || (is != nSpins-4) )
			{
			   hamilt[ii]=0.0 ;
			   /* printf("ii = %d hamilt[ii] = %f\n",ii, hamilt[ii]);*/
			   continue ;
			}
		 	for ( i=0; i<nSpins-1 ; i++ )
			{
			    if ( basis[ja+i*nBasis] != basis[jb+i*nBasis] ) break ;
			}
			for ( j=i+1 ; j<nSpins ; j++ )
			{
			   if ( basis[ja+j*nBasis] != basis[jb+j*nBasis] ) break ;
			}
			hamilt[ii] = 0.5*ppmJCouplings[(j+1)*j/2+i] ;
			/* printf("ii = %d hamilt[ii] = %f\n",ii, hamilt[ii]);*/
		}
	}
}
/********************************************************************************/
static void diagonaliseJacobiOneBlock(int size, double* hamilt, double* eValues, double** eVectors)
{
	int i,j,ja,jb,ik;
	/* hamilt from inf to sup*/
	ik = 0;
	for ( ja=0 ; ja<size ; ja++)
	{
		for ( jb=0 ; jb<=ja; jb++ )
		{
	   		eVectors[ja][jb] = hamilt[ik++];
	   		eVectors[jb][ja] = eVectors[ja][jb];
		}
	}
	ik = 0;
	for ( i=0 ; i<size ; i++)
		for ( j=i ; j<size; j++ )
	   		hamilt[ik++]=eVectors[i][j];

	printf("Begin diagonalisation by jacobi. size = %d\n",size);
	jacobi(hamilt,size,eValues,eVectors,&i) ;
	printf("End of diagonalisation by jacobi\n");

	/*
	for ( i=0 ; i<size ; i++)
	{
		printf("Eigenvalue[%d]=%f ",i,eValues[i]);
		printf(" Vector = ");
		for ( jb=0 ; jb<size; jb++ )
			printf("%f ",eVectors[jb][i]);
		printf("\n");
	}
	*/
}
/********************************************************************************/
static int addTransitions(int nBasis,int nSpins, int istartPrev, int istart, int sizePrev, int size,
					int* basis,
					double* eValuesPrev, double* eValues, 
					double** eVectorsPrev, double** eVectors,
					int ifreqSpec, double* frequenciesSpectrum, double* intensities,
					double* transProb, int* lfs, int* mfs)
{
	int i = 0;
	int ja, jb;
	int ii, ik;
	int nfs = 0;
	int nDim = sizePrev*size;
	int l,m;

	for ( i=0 ; i<nDim ; i++) transProb[i] = 0;
	printf("Begin transition propability calculation\n");
	ii=0 ;
	nfs = 0;
	for ( l=istartPrev ; l<istartPrev+sizePrev ; l++)
		for ( m=istart ; m<istart+size; m++ )
		{
			int is;
	      		is = 0 ;
           		for ( i=0; i<nSpins ; i++ )
	       			is += basis[l+i*nBasis]*basis[m+i*nBasis] ;
              		if ( is == nSpins-2 ) 
			{
				lfs[nfs] = l-istartPrev;
				mfs[nfs] = m-istart;
				nfs++;
			}
		}
	printf("End lfs/mfs calculation nfs %d\n",nfs);
	ii=0;
	for ( ja=0 ; ja<sizePrev ; ja++)
		for ( jb=0 ; jb<size; jb++ )
		{
			double dum=0.0;
			for ( ik=0 ; ik<nfs ; ik++)
         			dum +=   eVectorsPrev[lfs[ik]][ja]*eVectors[mfs[ik]][jb];
	  		transProb[ii++]=dum*dum ;
   		}
	
	printf("End transProb calculations\n");
	/* transition frequencies*/
	ii=0;
	ik = ifreqSpec;
	printf("Begin intensities calculations\n");
	for ( ja=0 ; ja<sizePrev ; ja++)
		for ( jb=0 ; jb<size; jb++ )
		{
			if ( transProb[ii] > .0001 )
			{
				frequenciesSpectrum[ik] = fabs(eValues[jb]-eValuesPrev[ja]);
				intensities[ik] = transProb[ii];
				ik++;
			}
			ii++;
		}
	printf("End intensities calculations\n");
	return ik;
}
/********************************************************************************/
static int getSizeMax(int nSpins, int* binomialCoef)
{
	int sizeMax = 0;
	int i;

	for(i=0; i<=nSpins;  i++)
		if( binomialCoef[i]>sizeMax) sizeMax = binomialCoef[i];
	return sizeMax;
}
/********************************************************************************/
static int getSizeTrans(int nSpins, int* binomialCoef)
{
	int size = 0;
	int i;

	for(i=1; i<=nSpins;  i++)
		size += binomialCoef[i]*binomialCoef[i-1];
	return size;
}
/********************************************************************************/
static void printMatInf(int istart, int size, double* mat, char* name)
{
	int i,j,ik;
	ik = 0;
	if(name) printf("%s\n",name);
	for ( i=istart ; i<istart+size ; i++)
	{
		for ( j=istart ; j<=i; j++ )
		{
	   		printf("%0.10f ",mat[ik++]);
		}
		printf("\n");
	}
}
/********************************************************************************/
static void getNumberOfSpinsCouples(int nGroups, int* numberOfSpins, int* pnSpins, int* pnCoup)
{
	int nSpins = 0 ;
	int jj;
	int iGroup;
	int jGroup;
	int ii;
	int k;

	jj = 0 ;
	for (iGroup=0 ; iGroup<nGroups ; iGroup++ )
   		for ( k=0 ; k<numberOfSpins[iGroup] ; k++ )
		{
			nSpins++ ; 
		   	for ( jGroup=0 ; jGroup<iGroup ; jGroup++ )
           			for ( ii=0 ; ii<numberOfSpins[jGroup] ; ii++ ) jj++ ; 
			for ( ii=0 ; ii<=k ; ii++ ) jj++;
		}
	*pnSpins = nSpins;
	*pnCoup = jj;
}
/********************************************************************************/
static int removeIdenticalFrequencies(int nFrequencies, double* frequenciesSpectrum, double* intensities)
{
	int i,j;
	if(nFrequencies<0) return 0;

	/* add intensity to first and set it to -1 for the second */
	for(i=0;i<nFrequencies-1;i++) 
	{
		if(intensities[i]<0) continue;
		for(j=i+1;j<nFrequencies;j++) 
		{
			if(intensities[j]<0) continue;
			if(fabs(frequenciesSpectrum[i]-frequenciesSpectrum[j])<1e-10)
			{
				intensities[i] += intensities[j];
				intensities[j] = -1;
			}
		}
	}
	/* negative intensities at last */
	for(i=0;i<nFrequencies-1;i++) 
	{
		if(intensities[i]>0) continue;
		for(j=i+1;j<nFrequencies;j++) 
		{
			if(intensities[j]>0) 
			{
				double t =  intensities[i];
				intensities[i] =  intensities[j];
				intensities[j] = t;
				break;
			}
		}
	}
	for(i=0;i<nFrequencies;i++) 
			if(intensities[i]<0) break;
	return i;
}
	
/********************************************************************************/
void computeNMRSpectrumByBlock(
		double operatingFrequency, 
		int nGroups, int* numberOfSpins, double* chemichalShifts,
		double** JCouplings, int *n, double**X, double** Y)
{
	int nSpins = 0 ;
	int i = 0;
	int nBasis = 0;
	int nDim = 0;
	int nCoup = 0;

	double* frequencies  = NULL;
	double* frequenciesSpectrum  = NULL;
	double* intensities  = NULL;
	double* ppmJCouplings  = NULL;
	int* basis  = NULL;
	double* transProb  = NULL;
	double* hamilt  = NULL;
	double** eVectors  = NULL;
	double* eValues  = NULL;
	double** eVectorsPrev  = NULL;
	double* eValuesPrev  = NULL;
	int* lfs  = NULL;
	int* mfs  = NULL;
	int nFrequencies = 0;
	int* start = NULL;
	int* binomialCoef = NULL;
	int sizeMax;
	int sizeTrans;
	int ifreqSpec = 0;

	*n = 0;
	*X = NULL;
	*Y = NULL;

	getNumberOfSpinsCouples(nGroups, numberOfSpins, &nSpins, &nCoup);
	
	printf("# Spins = %d\n",nSpins);
	if(nSpins<1) return;
	if(nSpins>NMAXGROUP+2)
	{
		printf("Sorry\nThe number of spins is larger than %d.\n", NMAXGROUP+2);
		return;
	}
	if(nCoup<1) return;
	frequencies = malloc(nSpins*sizeof(double));
	ppmJCouplings = malloc(nCoup*sizeof(double));
	/* frequency array and coupling matrix*/
	buildFreqAndJ(operatingFrequency,  nGroups, numberOfSpins, chemichalShifts, JCouplings, 
		nCoup, frequencies, ppmJCouplings);
	printf("End build FreqJ\n");
	/* basis set */
	nBasis = 1<<nSpins;
	/* printf("nBasis =%d\n",nBasis);*/
	basis = malloc(nBasis*nSpins*sizeof(int));
	start = malloc((nSpins+1)*sizeof(int));
	binomialCoef = malloc((nSpins+1)*sizeof(int));
	initTables(nSpins, binomialCoef, basis, start);
	sizeMax = getSizeMax(nSpins, binomialCoef);
	sizeTrans = getSizeTrans(nSpins, binomialCoef);
	printf("nBasis  = %d sizeTrans = %d\n",nBasis,sizeTrans);
	printf("End initTables\n");

	nDim = sizeMax*(sizeMax+1)/2;
	hamilt = malloc(nDim*sizeof(double));
	transProb = malloc(sizeMax*sizeMax*sizeof(double));
	printf("End transProb alloc\n");
	eValues = malloc(sizeMax*sizeof(double));
	eVectors  = malloc(sizeMax*sizeof(double*));
	if(eVectors) for(i=0;i<sizeMax;i++) eVectors[i] = malloc(sizeMax*sizeof(double));
	eValuesPrev = malloc(sizeMax*sizeof(double));
	eVectorsPrev  = malloc(sizeMax*sizeof(double*));
	if(eVectorsPrev) for(i=0;i<sizeMax;i++) eVectorsPrev[i] = malloc(sizeMax*sizeof(double));

	printf("Begin alloc freq and int\n");
	frequenciesSpectrum  = malloc(sizeTrans*sizeof(double));
	intensities  = malloc(sizeTrans*sizeof(double));
	if(!intensities)
	{
		printf("Allocation impossible nBasis  = %d sizeTrans = %d\n",nBasis,sizeTrans);
		return;
	}
	lfs  = malloc(sizeMax*sizeMax*sizeof(int));
	mfs  = malloc(sizeMax*sizeMax*sizeof(int));
	ifreqSpec = 0;
	for(i=0;i<=nSpins;i++)
	{
		int istart = start[i];
		int size = binomialCoef[i];
		double* e;
		double** v;
		buildHamiltonianOneBlock(istart, size, 
				nBasis, nSpins, frequencies, ppmJCouplings, basis , hamilt);
		/* printMatInf(0, size, hamilt, "H");*/
		//diagonaliseJacobiOneBlock(size, hamilt, eValues, eVectors);

		printf("Diag par TQLI size = %d\n",size);
		eigentqli(hamilt, size, eValues, eVectors);
		if(i!=0)
		{
			printf("Begin transition calculations\n");
			ifreqSpec = addTransitions(nBasis,nSpins,start[i-1], istart, binomialCoef[i-1], size,
					basis,
					eValuesPrev, eValues, 
					eVectorsPrev, eVectors,
					ifreqSpec, frequenciesSpectrum, intensities,transProb,lfs,mfs);
		}
		/* swith prev and current eigenvalues and eigenvectors */
		e = eValuesPrev;
		eValuesPrev = eValues;
		eValues = e;
		v = eVectorsPrev;
		eVectorsPrev = eVectors;
		eVectors = v;
	}
	if(frequencies) free(frequencies);
	if(ppmJCouplings) free(ppmJCouplings);
	if(hamilt) free(hamilt);
	if(lfs) free(lfs);
	if(mfs) free(mfs);
	/* print Hamiltonian */

	if(eVectorsPrev) 
	{
		for(i=0;i<sizeMax;i++) if(eVectorsPrev[i]) free(eVectorsPrev[i]);
		free(eVectorsPrev);
	}
	if(eVectors) 
	{
		for(i=0;i<sizeMax;i++) if(eVectors[i]) free(eVectors[i]);
		free(eVectors);
	}
	if(eValues) free(eValues);
	if(eValuesPrev) free(eValuesPrev);
	if(transProb) free(transProb);

	nFrequencies = ifreqSpec;
	if(nFrequencies>0)
	{
		/*
		int i;
		for(i=0;i<nFrequencies;i++) 
		{
			printf("%f %f\n",frequenciesSpectrum[i],intensities[i]);
		}
		*/
		/*
		nFrequencies =  removeIdenticalFrequencies(nFrequencies, frequenciesSpectrum, intensities);
		*/
		if(nFrequencies<1)
		{
			if(frequenciesSpectrum) free(frequenciesSpectrum);
			frequenciesSpectrum = NULL;
			if(intensities) free(intensities);
			intensities = NULL;
		}
		else
		{
			frequenciesSpectrum = realloc(frequenciesSpectrum,nFrequencies*sizeof(double));
			intensities = realloc(intensities,nFrequencies*sizeof(double));
		}
	}

	*n = nFrequencies;
	*X = frequenciesSpectrum;
	*Y = intensities;

	printf("End Computing\n");
}
/********************************************************************************/
static void buildDiagonalHamiltonian( int nBasis, int nSpins, double* frequencies, double* ppmJCouplings,
	int* basis , double* hamilt)
{
	int i = 0;
	int k = 0 ;
	int l = 0 ;
	int ik;
	double dum;

	/* diagonal elements of hamiltonian*/
	for ( i=0 ; i<nBasis ; i++ )
	{
		dum=0.0 ;
  		ik = -1 ;
		for ( l=0 ; l<nSpins ; l++ )
		{
			ik++ ;
			dum += frequencies[l]*basis[i+l*nBasis]/2 ;
			for ( k=0 ; k<l ; k++ )
			{
		  		dum=dum+ppmJCouplings[ik]*basis[i+l*nBasis]*basis[i+k*nBasis]/4. ;
				ik++;
			}
		}
		hamilt[i]=dum ;
		/* printf("hamilt[%d] = %f\n",ii-1, hamilt[ii-1]);*/
	}
}
/********************************************************************************/
static int addTransitionsDiagonal(int nBasis,int nSpins, int istartPrev, int istart, int sizePrev, int size,
					int* basis, double* hamilt,
					int ifreqSpec, double* frequenciesSpectrum, double* intensities
					)
{
	int i = 0;
	int ik;
	int l,m;

	printf("Begin intensities calculations\n");
	ik = ifreqSpec;
	for ( l=istartPrev ; l<istartPrev+sizePrev ; l++)
		for ( m=istart ; m<istart+size; m++ )
		{
			int is;
	      		is = 0 ;
           		for ( i=0; i<nSpins ; i++ )
	       			is += basis[l+i*nBasis]*basis[m+i*nBasis] ;
              		if ( is == nSpins-2 ) 
			{
				frequenciesSpectrum[ik] = fabs(hamilt[m]-hamilt[l]);
				intensities[ik] = 1;
				ik++;
			}
		}
	printf("End intensities calculations\n");
	return ik;
}
/********************************************************************************/
void computeNMRSpectrumWeaklyCoupled(
		double operatingFrequency, 
		int nGroups, int* numberOfSpins, double* chemichalShifts,
		double** JCouplings, int *n, double**X, double** Y)
{
	int nSpins = 0 ;
	int i = 0;
	int nBasis = 0;
	int nDim = 0;
	int nCoup = 0;

	double* frequencies  = NULL;
	double* frequenciesSpectrum  = NULL;
	double* intensities  = NULL;
	double* ppmJCouplings  = NULL;
	int* basis  = NULL;
	double* hamilt  = NULL;
	int nFrequencies = 0;
	int* start = NULL;
	int* binomialCoef = NULL;
	int sizeMax;
	int sizeTrans;
	int ifreqSpec = 0;

	*n = 0;
	*X = NULL;
	*Y = NULL;

	getNumberOfSpinsCouples(nGroups, numberOfSpins, &nSpins, &nCoup);
	
	/* printf("NB Spin = %d\n",nSpins);*/
	if(nSpins<1) return;
	if(nSpins>NMAXGROUP+2)
	{
		printf("Sorry\nThe number of spins is larger than %d.\n", NMAXGROUP+2);
		return;
	}
	if(nCoup<1) return;
	frequencies = malloc(nSpins*sizeof(double));
	ppmJCouplings = malloc(nCoup*sizeof(double));
	/* frequency array and coupling matrix*/
	buildFreqAndJ(operatingFrequency,  nGroups, numberOfSpins, chemichalShifts, JCouplings, 
		nCoup, frequencies, ppmJCouplings);
	/* basis set */
	nBasis = 1<<nSpins;
	/* printf("nBasis =%d\n",nBasis);*/
	basis = malloc(nBasis*nSpins*sizeof(int));
	start = malloc((nSpins+1)*sizeof(int));
	binomialCoef = malloc((nSpins+1)*sizeof(int));
	initTables(nSpins, binomialCoef, basis, start);
	sizeMax = getSizeMax(nSpins, binomialCoef);
	sizeTrans = getSizeTrans(nSpins, binomialCoef);

	nDim = nBasis;
	hamilt = malloc(nDim*sizeof(double));

	frequenciesSpectrum  = malloc(sizeTrans*sizeof(double));
	intensities  = malloc(sizeTrans*sizeof(double));
	printf("nBasis  = %d sizeTrans = %d\n",nBasis,sizeTrans);
	if(!intensities)
	{
		printf("Allocation impossible nBasis  = %d sizeTrans = %d\n",nBasis,sizeTrans);
		return;
	}
	ifreqSpec = 0;
	buildDiagonalHamiltonian(nBasis, nSpins, frequencies, ppmJCouplings, basis , hamilt);
	if(frequencies) free(frequencies);
	if(ppmJCouplings) free(ppmJCouplings);
	for(i=0;i<=nSpins;i++)
	{
		int istart = start[i];
		int size = binomialCoef[i];
		printf("i =%d\n",i);
		if(i!=0)
		{
			printf("Begin transition calculations\n");
			ifreqSpec = addTransitionsDiagonal(nBasis,nSpins,start[i-1], istart, binomialCoef[i-1], size,
					basis, hamilt, ifreqSpec, frequenciesSpectrum, intensities);
		}
		/* swith prev and current eigenvalues and eigenvectors */
	}
	printf("Free hamil\n");
	if(hamilt) free(hamilt);
	/* print Hamiltonian */
	nFrequencies = ifreqSpec;
	if(nFrequencies>0)
	{
		/*
		nFrequencies =  removeIdenticalFrequencies(nFrequencies, frequenciesSpectrum, intensities);
		if(nFrequencies>0)
		*/
		{
			frequenciesSpectrum = realloc(frequenciesSpectrum,nFrequencies*sizeof(double));
			intensities = realloc(intensities,nFrequencies*sizeof(double));
		}
	}
	if(nFrequencies<1)
	{
		printf("nFrequencies=%d\n",nFrequencies);
		if(frequenciesSpectrum) free(frequenciesSpectrum);
		if(intensities) free(intensities);
	}

	*n = nFrequencies;
	*X = frequenciesSpectrum;
	*Y = intensities;

	printf("End Computing\n");
}
/********************************************************************************/
void computeNMRSpectrumNonCoupled(
		int nGroups, int* numberOfSpins, double* chemichalShifts,
		int *n, double**X, double** Y)
{
	int nSpins = 0 ;
	int nCoup = 0;
	int k;
	int iGroup;
	    

	double* frequenciesSpectrum  = NULL;
	double* intensities  = NULL;
	int nFrequencies = 0;

	*n = 0;
	*X = NULL;
	*Y = NULL;
	getNumberOfSpinsCouples(nGroups, numberOfSpins, &nSpins, &nCoup);
	
	if(nSpins<1) return;
	if(nCoup<1) return;
	nFrequencies = nSpins;
	frequenciesSpectrum  = malloc(nSpins*sizeof(double));
	intensities  = malloc(nSpins*sizeof(double));
	nSpins = 0;
	for (iGroup=0 ; iGroup<nGroups ; iGroup++ )
   		for ( k=0 ; k<numberOfSpins[iGroup] ; k++ )
		{
			frequenciesSpectrum[nSpins] = chemichalShifts[iGroup] ;
			intensities[nSpins] = 1;
			nSpins++;
		}
			/* printf("nSpins = %d f = %f\n",nSpins, frequencies[nSpins]);*/

	*n = nFrequencies;
	*X = frequenciesSpectrum;
	*Y = intensities;

	printf("End Computing\n");
}
/********************************************************************************/
int readDataAndComputeNMRSpectrum(char*fileName, int level)
{
 	FILE *file;
	double operatingFrequency = 300;
	int nGroups = NMAXGROUP;
	int nMax = NMAXGROUP;
	int* numberOfSpins = NULL;
	double* chemichalShifts = NULL;
	double** JCouplings = NULL;
	int i;
	int j;
	char tmp[BSIZE];
	long int pos = 0;
	double* X;
	double* Y;
	int n;

 	file = fopen(fileName, "r");
	if(!file) return FALSE;
	nGroups  = -1;

	pos = ftell(file);

	while(!feof(file))
	{
		if(!fgets(tmp,BSIZE,file))break;
		if(this_is_a_backspace(tmp)) break;
		nGroups++;
	}

	if(nGroups<=0) return FALSE;
	if(nGroups>nMax) nGroups = nMax;

	fseek(file, pos, SEEK_SET);

	numberOfSpins = malloc(nGroups*sizeof(int));
	chemichalShifts = malloc(nGroups*sizeof(double));
	JCouplings = malloc(nGroups*sizeof(double*));

	fscanf(file,"%lf",&operatingFrequency);
	for(i=0;i<nGroups;i++)
	{
		fscanf(file,"%lf %d",&chemichalShifts[i], &numberOfSpins[i]);
		JCouplings[i] =  malloc(nGroups*sizeof(double));
		for(j=0;j<i;j++)
			fscanf(file,"%lf",&JCouplings[i][j]);
	}

	fclose(file);
	if(level==2) computeNMRSpectrumByBlock(operatingFrequency, nGroups, numberOfSpins, chemichalShifts, JCouplings,&n, &X, &Y);
	else if(level==1) computeNMRSpectrumWeaklyCoupled(operatingFrequency, nGroups, numberOfSpins, chemichalShifts, JCouplings,&n, &X, &Y);
	else computeNMRSpectrumNonCoupled(nGroups, numberOfSpins, chemichalShifts, &n, &X, &Y);

 	file = fopen("spectrumNew.txt", "w");
	for(i=0;i<n;i++)
		fprintf(file,"%f\t%f\n",X[i],Y[i]);
	fclose(file);

	if(numberOfSpins) free(numberOfSpins);
	if(chemichalShifts) free(chemichalShifts);
	if(JCouplings)
	{
		for(i=0;i<nGroups;i++)
			if(JCouplings[i]) free(JCouplings[i]);
		free(JCouplings);
	}
	return TRUE;

}
