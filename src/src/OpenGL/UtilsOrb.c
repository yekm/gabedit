/* UtilsOrb.c */
/**********************************************************************************************************
Copyright (c) 2002 Abdul-Rahman Allouche. All rights reserved

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the Gabedit), to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions
  of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
************************************************************************************************************/


#include "../../Config.h"
#include "../OpenGL/GlobalOrb.h"
#include "../Utils/Vector3d.h"
#include "../OpenGL/GLArea.h"
#include "../OpenGL/Orbitals.h"
#include "../OpenGL/OrbitalsMolpro.h"
#include "../OpenGL/GeomOrbXYZ.h"
#include "../OpenGL/UtilsOrb.h"
#include "../OpenGL/TriangleDraw.h"
#include "../Utils/Utils.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Constantes.h"
#include "../Common/Windows.h"
#include "../OpenGL/Vibration.h"
#include "../OpenGL/ContoursPov.h"
#include "../OpenGL/PlanesMappedPov.h"

void CalculFfact();
void CalculFact();
void CalculCIJ();
gfloat Dpn(gfloat e,gint n);
gint m1p(gint i);
gfloat SpqSansNorm(GTF p,GTF q);
/**********************************************/
void InitializeAll()
{
 	CoefAlphaOrbitals = NULL;
 	EnerAlphaOrbitals = NULL;
	TypeSelOrb = 1; 
	NumSelOrb = -1;
 	CalculFact();
 	CalculFfact();
 	CalculCIJ();
}
/**********************************************/
gfloat** CreateTable2(gint N)
{
 gfloat** T;
 gint i;
 T = g_malloc(N*sizeof(gfloat*)) ;

 for(i=0;i<N;i++)
   T[i] = g_malloc(N*sizeof(gfloat));

 return T;
}
/**********************************************/
gfloat** FreeTable2(gfloat **T,gint N)
{
 gint i;
  for(i=0;i<N;i++)
   g_free(T[i]);

 g_free(T);

 return NULL;
}
/**********************************************/
gfloat f(gint i,gint l,gint m,gfloat A,gfloat B)
{
  gint j,jmin,jmax;
  gfloat Som=0.0;

  jmin = 0;
  if(jmin<i-m)
    jmin =i-m;
  jmax = i;
  if(jmax>l)
   jmax = l;
  for( j=jmin;j<=jmax;j++)
  {
     Som += CIJ[l][j]*CIJ[m][i-j]*
          Dpn(-A,l-j)*Dpn(-B,m-i+j);

  }
  return Som; 
}
/**********************************************/
gint GetTotalNelectrons()
{
  gint i;
  gint N=0;
 for(i=0;i<Ncenters;i++)
 {
         if(Type[GeomOrb[i].NumType].N>0)
              N +=Type[GeomOrb[i].NumType].N;
 }
 return N;
}
/**********************************************/
void DefineNOccs()
{
  NTotOcc = GetTotalNelectrons();
  NAlphaOcc =NTotOcc/2+1;
  NBetaOcc =NTotOcc/2;
  NTotOcc /=2;
  TypeSelOrb = 1;
  NumSelOrb = NAlphaOcc-1;
}
/**********************************************/
gfloat Dpn(gfloat e,gint n)
{
 gfloat p=1.0;
 gint k;
 if(fabs(e)<1e-10)
 {
  if (n==0)
   return 1.0;
  else
   return 0.0;
 }
 for(k=1;k<=n;k++)
  p *=e;
 return p;
}
/**********************************************/
gfloat Cklm(gint k,gint l,gint m)
{
   gfloat p=1.0;
   gint j;
   for(j=0;j<=k-1;j++)
    p *=(gfloat)(l-m-2*j)*(gfloat)(l-m-2*j-1)/( 2*(gfloat)(j+1)*(gfloat)(2*l-2*j-1));

    return p;

}
/**********************************************/
void prinfSlm(Slm S)
{
	gint i,j;
	char XYZ[4]={'x','y','z'};
   	printf("l=%d m =%d N=%d \n",S.l,S.m,S.N);
   	for(i=0;i<S.N;i++)
   	{
   	  printf("%9.6f ",S.lxyz[i].Coef);
   	  for(j=0;j<3;j++)
   	  {
   	   if(S.lxyz[i].l[j] !=0)
   	   {
   	   		if(S.lxyz[i].l[j] >1)
   				printf("%c%d",XYZ[j],S.lxyz[i].l[j]);
   			else
   				printf("%c",XYZ[j]);
   		}
   	  }
   	 printf("\n");
   	}
}
/**********************************************/
Slm DeleteEqSml(Slm S)
{
   Slm St;
   gint Nc;
   gint ok;
   gint i,j,k;
   gint* Ndel= g_malloc(S.N*sizeof(gint));

   St.l=S.l;
   St.m=S.m;
   St.N=S.N;
   for(i=0;i<S.N;i++)
   	   	Ndel[i] = 0;

   St.lxyz = g_malloc(St.N*sizeof(LXYZ));
   	Nc=-1;
   	
   	
   	for(i=0;i<S.N;i++)
   	{
   	  if(Ndel[i] == 1  )
   	     continue;
   	   Nc++;
   	 	for(j=0;j<3;j++)
   	   		St.lxyz[Nc].l[j] = S.lxyz[i].l[j];
   	  	St.lxyz[Nc].Coef = S.lxyz[i].Coef;
   	
   		for(k=i+1;k<S.N;k++)
   		{
   			ok=1; /* les 2 sont identiques*/
   	   		for(j=0;j<3;j++)
   	   		if( St.lxyz[Nc].l[j] != S.lxyz[k].l[j] )
   	      	{
   	      		ok =0;
   	      		break;
   	      	}
   	   	  	if(ok == 1)
   	   	  	{
   	   	  	 St.lxyz[Nc].Coef += S.lxyz[k].Coef;
   	   	  	 Ndel[k] = 1;
   	   	  	 }
   		}
   	}
   	St.N = Nc+1;
   	g_free(S.lxyz);
   	g_free(Ndel);
   	return St;
   	

}
/**********************************************/
Slm GetCoefSlP(gint l, gint m)
{
   Slm S;
   gint k,i,r,s;
   gint Nc=0;
   gfloat Norm;

   S.m = m;
   S.l = l;


 Norm = sqrt((2*l+1)/(4*PI))/sqrt(fact[l-m]*fact[l+m])*ffact[l];	
   for(k=0;k<=(l-m)/2;k++)
   	for(i=0;i<=m/2;i++)
   		for(r=0;r<=k;r++)
   			for(s=0;s<=k-r;s++)
   	{
   	   Nc++;
   	}
   	S.N=Nc;
   	S.lxyz = g_malloc(Nc*sizeof(LXYZ));
   	Nc=-1;
   	for(k=0;k<=(l-m)/2;k++)
   	for(i=0;i<=m/2;i++)
   		for(r=0;r<=k;r++)
   			for(s=0;s<=k-r;s++)
   	{
   	   Nc++;
   	  S.lxyz[Nc].Coef =Norm*
   	  m1p(k+i)*
   	 Cklm(k,l,m)*
   	  fact[m]/fact[2*i]/fact[m-2*i]*
   	  fact[k]/fact[r]/fact[k-r]*
   	  fact[k-r]/fact[s]/fact[k-r-s];
   	

   	   S.lxyz[Nc].l[0] =2*r+m-2*i;
	   S.lxyz[Nc].l[1] =2*s+2*i;   	
	   S.lxyz[Nc].l[2] =l-m-2*r-2*s;   	

   	}
/*
   	printf("avant elimination\n");
   	prinfSlm(S);
   	*/
   	S = DeleteEqSml(S);
/*   	printf("apres elimination\n");*/
/*   	prinfSlm(S);*/
   	return S;

}
/**********************************************/
Slm GetCoefSlM(gint l, gint m)
{
   Slm S;
   gint k,i,r,s;
   gint Nc=0;
   gfloat Norm;

   S.m = -m;
   S.l = l;
   Norm = sqrt((2*l+1)/(4*PI))/sqrt(fact[l-m]*fact[l+m])*ffact[l];	
   for(k=0;k<=(l-m)/2;k++)
   	for(i=0;i<=(m-1)/2;i++)
   		for(r=0;r<=k;r++)
   			for(s=0;s<=k-r;s++)
   	{
   	   Nc++;
   	}
   	S.N=Nc;
   	S.lxyz = g_malloc(Nc*sizeof(LXYZ));   	
 	Nc=-1;
   for(k=0;k<=(l-m)/2;k++)
   	for(i=0;i<=(m-1)/2;i++)
   		for(r=0;r<=k;r++)
   			for(s=0;s<=k-r;s++)
   	{
   	   Nc++;
   	  S.lxyz[Nc].Coef =Norm*
   	  m1p(k+i)*
   	  Cklm(k,l,m)*
   	  fact[m]/fact[2*i+1]/fact[m-2*i-1]*
   	  fact[k]/fact[r]/fact[k-r]*
   	  fact[k-r]/fact[s]/fact[k-r-s];
   	

   	   S.lxyz[Nc].l[0] =2*r+m-2*i-1;
	   S.lxyz[Nc].l[1] =2*s+2*i+1;   	
	   S.lxyz[Nc].l[2] =l-m-2*r-2*s;   	

   	}

  /* 	printf("avant elimination\n");*/
  /*	prinfSlm(S);*/
   	S = DeleteEqSml(S);
 /*  	printf("apres elimination\n");*/
/*   	prinfSlm(S);*/
   	
   	return S;
}
/**********************************************/
Slm GetCoefSlm(gint l, gint m)
{
	if(m>=0)
			return GetCoefSlP(l,m);
		else
			return GetCoefSlM(l,-m);
}
/**********************************************/
char GetSymmetry(gint l)
{
        switch(l)
        {
        case 0 : return 'S';
        case 1 : return 'P';
        case 2 : return 'D';
        case 3 : return 'F';
        case 4 : return 'G';
        case 5 : return 'H';
        case 6 : return 'I';
        }
       return 'x';
}
/**********************************************/
gint GetNelectrons(char *symb)
{
  gint i;
  gint  Z[NATOMS]={
	1,2,
	3,4,5,6,7,8,9,10,
	11,12,13,14,15,16,17,18,
	19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,
        37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,
        55,56,57,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,
        87,88,89,
        58,59,60,61,62,63,64,65,66,67,68,69,70,71, 
        90,91,92,93,94,95,96,97,98,99,100,101,102,103,
        0
	};
  char *Symb[NATOMS]={
	"H","He",
	"Li","Be","B","C","N","O","F","Ne",
	"Na","Mg","Al","Si","P","S","Cl","Ar",
	"K","Ca","Sc","Ti","V","Cr","Mn","Fe",
	"Co","Ni","Cu","Zn","Ga","Ge","As","Se",
	"Br","Kr","Rb","Sr","Y","Zr","Nb","Mo",
	"Tc","Ru","Rh","Pd","Ag","Cd","In",
	"Sn","Sb","Te","I","Xe","Cs","Ba","La",
	"Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl",
	"Pb","Bi","Po","At","Rn","Fr","Ra","Ac",
	"Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb",
	"Dy","Ho","Er","Tm","Yb","Lu",
	"Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf",
	"Es","Fm","Md","No","Lr",
        "X"
	};

   for(i=0;i<NATOMS;i++)
    if( !strcmp(symb,Symb[i]) )
      return Z[i];

   return -1;
}
/**********************************************/
void printLineChar(char c,gint n)
{
  gint i;
  for(i=0;i<n;i++)
  	printf("%c",c);
  printf("\n");
}
/**********************************************/
gint m1p(gint i)
{
 if(i%2==0)
    return 1;
 else
    return -1;
}
/**********************************************/
void CalculFact()
{
 gint i;
 fact[0]=1.0;
 fact[1]=1.0;

 for(i=2;i<MAX_FACT;i++)
	fact[i]=fact[i-1]*i;
}
/**********************************************/
void CalculFfact()
{
/* ffact[i] = (2*i-1)!!*/
 gint i;
 ffact[0]=1.0;
 ffact[1]=1.0;

 for(i=2;i<MAX_FACT;i++)
	ffact[i]=ffact[i-1]*(2*i-1);
}
/**********************************************/
void CalculCIJ()
{
 gint i,j;

 for(i=0;i<MAX_FACT;i++)
 {
 	for(j=0;j<=i;j++)
		CIJ[i][j]=fact[i]/fact[j]/fact[i-j];
	for(j=i+1;j<MAX_FACT;j++)
	 	CIJ[i][j]=CIJ[i][j-i];
 }
}
/**********************************************/
gfloat NormeGTF(GTF p)
{
 /*
 printf("%f\n",2*p.Ex/Pi);
 printf("%f\n",Dpn(4*p.Ex,p.l[0]+p.l[1]+p.l[2]));
 printf("%d\n",p.l[0]);
 printf("%f\n",ffact[p.l[0]]);
 */
 return sqrt(2*p.Ex/PI*sqrt(2*p.Ex/PI)*Dpn(4*p.Ex,p.l[0]+p.l[1]+p.l[2])
        /(ffact[p.l[0]]*ffact[p.l[1]]*ffact[p.l[2]]) );
}
/**********************************************/
void NormaliseRadial(GTF*p)
{
  	GTF q=*p;
  	gint l=q.l[0]+q.l[1]+q.l[2];
  	
  	q.l[0]=l;
	q.l[1]=0;
	q.l[2]=0;
 p->Coef *= NormeGTF(q);
}
/**********************************************/
void Normalise(GTF*p)
{
 p->Coef *= NormeGTF(*p);
}
/**********************************************/
void NormaliseCGTF(CGTF*p)
{
 gint n,np;
 gfloat Som=0.0;
 for(n=0;n<p->N;n++)
   Som += p->Gtf[n].Coef*p->Gtf[n].Coef*SpqSansNorm(p->Gtf[n],p->Gtf[n]);
 for(n=0;n<p->N-1;n++)
  for(np=n+1;np<p->N;np++)
   Som +=2*( p->Gtf[n].Coef*p->Gtf[np].Coef*SpqSansNorm(p->Gtf[n],p->Gtf[np]));

 if(Som>1.e-20)
 {
 Som = sqrt(Som);
 for(n=0;n<p->N;n++)
  p->Gtf[n].Coef /= Som;
 }
 else
 {
 printf("Error : a CGTF is nul\n");
 exit(1);
 }

}
/**********************************************/
gfloat SpqSansNorm(GTF p,GTF q)
{
  gint i,j;
  gfloat Som[3];
  gfloat t;
  gfloat PA[3];
  gfloat PB[3];
  gfloat gama=p.Ex+q.Ex;
  gfloat R2=0.0;

  for(j=0;j<3;j++)
  {
    t=(p.Ex*p.C[j]+q.Ex*q.C[j])/gama;
    PA[j]=p.C[j]-t;
    PB[j]=q.C[j]-t;
    R2 += (p.C[j]-q.C[j])*(p.C[j]-q.C[j]);
  }


  for(j=0;j<3;j++)
  {
   Som[j]=0.0;
   for(i=0;i<=(p.l[j]+q.l[j])/2;i++)
   {
     Som[j] +=f(2*i,p.l[j],q.l[j],PA[j],PB[j])*ffact[i]
              /(Dpn(2.0,i)*Dpn(gama,i));
   }
  }
  return  (PI/gama)*sqrt(PI/gama)
         *exp(-p.Ex*q.Ex/gama*R2)
         *Som[0]*Som[1]*Som[2];
}
/**********************************************/
gfloat Spq(GTF p,GTF q)
{
  return  p.Coef*q.Coef*SpqSansNorm(p,q);
}
/**********************************************/
gfloat SpqCGTF(CGTF p,CGTF q)
{
  gint n;
  gint np;
  gfloat Som=0.0;

  for(n=0;n<p.N;n++)
   for(np=0;np<q.N;np++)
    Som += Spq(p.Gtf[n],q.Gtf[np]); 

  return Som;
}
/************************************************/
gint get_type_file(gchar *NomFichier)
{
 	gchar *t;
 	FILE *fd;
 	guint taille=BSIZE;
	gint ktype = GABEDIT_TYPEFILE_UNKNOWN;

 	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r");

 	if(fd ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",NomFichier);
  		Message(buffer,"Error",TRUE);
 		g_free(t);
  		return ktype;
 	}
	fgets(t,taille,fd);
	g_strup(t);
        if(strstr(t, "ENTERING" ))
		ktype = GABEDIT_TYPEFILE_GAUSSIAN;
	else
        if(strstr( t, "[MOLDEN FORMAT]" ))
			ktype = GABEDIT_TYPEFILE_MOLDEN;
	else
	if(strstr( t, "[GABEDIT FORMAT]" ))
		ktype = GABEDIT_TYPEFILE_GABEDIT;
	else
	if(atoi(t)>0)
		ktype = GABEDIT_TYPEFILE_XYZ;
	if( ktype == GABEDIT_TYPEFILE_UNKNOWN)
	{
		while(!feof(fd))
		{
			fgets(t,taille,fd);
			if(strstr(t,"PROGRAM SYSTEM MOLPRO"))
			{
				ktype = GABEDIT_TYPEFILE_MOLPRO;
				break;
			}
		}
	}

 	fclose(fd);
 	g_free(t);
 	if(ktype==GABEDIT_TYPEFILE_UNKNOWN)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry,  I can not determine the type of '%s' file\n",NomFichier);
  		Message(buffer,"Error",TRUE);
 	}
	return ktype;
        
}
/**********************************************************/
/* return 
   -1 : undefined
    0 : cartezian
    1 : Spherical
*/
gint get_type_basis_in_gaussian_file(gchar *NomFichier)
{
 	gchar *t;
 	FILE *fd;
 	guint taille=BSIZE;
	gint ktype = -1;

 	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r");

 	if(fd ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",NomFichier);
  		Message(buffer,"Error",TRUE);

 		g_free(t);
  		return ktype;
 	}
	ktype = 0;
	while(!feof(fd))
	{
		fgets(t,taille,fd);
        	if(strstr( t, "(5D, 7F)"))
		{
			ktype = 1;
			break;
		}
        	if(strstr( t, "(6D, 7F)"))
		{
			ktype = 0;
			break;
		}
        	if(strstr( t, "(6D, 10F)"))
		{
			ktype = 0;
			break;
		}
	}

 	fclose(fd);
 	g_free(t);
	return ktype;
        
}
/**********************************************************/
/* return 
   -1 : undefined
    0 : cartezian
    1 : Spherical
*/
gint get_type_basis_in_gabedit_file(gchar *NomFichier)
{
 	gchar *t;
 	FILE *fd;
 	guint taille=BSIZE;
	gint ktype = -1;

 	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r");

 	if(fd ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",NomFichier);
  		Message(buffer,"Error",TRUE);
 		g_free(t);
  		return ktype;
 	}
	ktype = -1;
	fgets(t,taille,fd);
	g_strup(t);
	if(strstr( t, "[GABEDIT FORMAT]"))
	{
		if(strstr( t, "SPHE"))
			ktype = 1;
		else
			ktype = 0;
	}
	
 	fclose(fd);
 	g_free(t);
	return ktype;
        
}
/**********************************************************/
/* return 
   -1 : undefined
    0 : cartezian
    1 : Spherical
*/
gint get_type_basis_in_molden_file(gchar *NomFichier)
{
 	gchar *t;
 	FILE *fd;
 	guint taille=BSIZE;
	gint ktype = -1;

 	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r");

 	if(fd ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",NomFichier);
  		Message(buffer,"Error",TRUE);
 		g_free(t);
  		return ktype;
 	}
	ktype = -1;
	fgets(t,taille,fd);
	g_strup(t);
	if(strstr( t, "[MOLDEN FORMAT]"))
	{
		ktype = 0;
		while(!feof(fd))
		{
			fgets(t,taille,fd);
			if(strstr( t, "GTO"))
				break;
			if(strstr( t, "[5D]"))
			{
				ktype = 1;
				break;
			}
		}
	}
	
 	fclose(fd);
 	g_free(t);
	return ktype;        
}
/**********************************************************/
void PrintAllOrb(gfloat** M)
{
 gint i,j;


 gint Nblock;
 gint Nrest;
 gint Nb;
 gint Nbmax=5;
 gint Nbj,Nej;
 gint l;
 char *XYZ[]={"x","y","z"};

 Nblock = NAOrb/Nbmax;
 Nrest = NAOrb%Nbmax;
 if(Nrest !=0) Nblock++;
 

 for(Nb=0;Nb<Nblock;Nb++)
 { 
 printf("\n");
 printf("\t");
 Nbj=Nbmax*Nb;
 Nej=Nbmax*Nb+Nbmax;
 if(Nb==Nblock-1 && Nrest !=0)
 	Nej=Nbmax*Nb+Nrest;
 for( j=Nbj;j<Nej;j++)
 {
     if(j<NTotOcc)
	printf("%9s ","Occuped");
     else
	printf("%9s ","Virtual");
 }
 printf("\n");
 printf("\t");
 for( j=Nbj;j<Nej;j++)
	printf("%9s ","-------");
 printf("\n");
 i=-1;

 for( i=0;i<NAOrb;i++)
 {
		 l=0;
		 for(j=0;j<3;j++)
		   l += AOrb[i].Gtf[0].l[j];

		 printf("%c",GetSymmetry(l));
		 for(j=0;j<3;j++)
		 {
			 switch(AOrb[i].Gtf[0].l[j])
			 {
			 case 0:break;
			 case 1:printf("%s",XYZ[j]);break;
			 default :printf("%s%d",XYZ[j],AOrb[i].Gtf[0].l[j]);
			 }
		 }
		printf("\t");

 for( j=Nbj;j<Nej;j++)
     printf("%9.6f ",M[j][i]);
   printf("\n");
 }

 }/*End Nb loop */
   printf("\n");
}
/*************************************************************************************/
static gboolean testascii(char c)
{
	switch ( c )
	{
	case	'0':
	case	'1':
	case	'2':
	case	'3':
	case	'4':
	case	'5':
	case	'6':
	case	'7':
	case	'8':
	case	'9':
	case	'.':
	case	'e':
	case	'E':
	case	'+':
	case	'-':return TRUE;
	}
	return FALSE;
}
/*************************************************************************************/
gboolean testi(char c)
{
	switch ( c )
	{
	case	'0':
	case	'1':
	case	'2':
	case	'3':
	case	'4':
	case	'5':
	case	'6':
	case	'7':
	case	'8':
	case	'9': return TRUE;
	}
	return FALSE;
}
/*************************************************************************************/
gboolean this_is_a_real(gchar *t)
{
	guint i;
	for(i=0;i<strlen(t);i++)
		if(!testascii(t[i]) ) return FALSE;
	if(t[0] =='e' || t[0] =='E' ) return FALSE;
	return TRUE;

}
/*************************************************************************************/
gboolean this_is_a_integer(gchar *t)
{
	guint i;
	if(!testi(t[0])&& t[0] != '-' ) return FALSE;
	for(i=1;i<strlen(t);i++)
		if(!testi(t[i]) ) return FALSE;
	return TRUE;

}
/*************************************************************************************/
void free_data_all()
{
        free_grid_all();
        free_iso_all();
        free_orbitals();
        free_geometry();
}  
/********************************************************************************/
static void change_entry_value(GtkWidget *Entry, gpointer data)
{
	GtkWidget **entriestmp = NULL;
	gushort ii;
	gushort jj;
	gushort i;
	gushort j;
	gint k;
	gchar* temp;
	GtkWidget *entries[3][6];
	if(GTK_IS_WIDGET(Entry))
	{
		entriestmp = (GtkWidget **)g_object_get_data (G_OBJECT (Entry), "Entries");
	}
	else return;

	if(entriestmp==NULL) return;

	for(i=0;i<3;i++)
	for(j=0;j<6;j++)
		entries[i][j] = entriestmp[i*6+j];

	for(i=0;i<3;i++)
	for(j=0;j<6;j++)
		if(!GTK_IS_WIDGET(entries[i][j]))return;
	ii = 10;
	jj = 10;
	for(i=0;i<3;i++)
	for(j=0;j<6;j++)
	{
		if(Entry == entries[i][j])
		{
			ii = i;
			jj = j;
			break;
		}
	}
	if(ii==10 || jj == 10) return;
	/* reset second and third direction */
	if(ii==0 && jj <= 2)
	{
		gdouble C1[3];
		gdouble C2[3];
		gdouble C3[3];
		gdouble p = 0;

		for(i=0;i<3;i++) C1[i] = atof(gtk_entry_get_text(GTK_ENTRY(entries[0][i])));
		for(i=0;i<3;i++) C2[i] = 0.0;
		for(i=0;i<3;i++)
			if(fabs(C1[i])<1e-6)
			{
				C2[i] = 1.0;
				break;
			}
		if(i==3) for(i=0;i<3;i++) C2[i] = 1.0;

		k = 0;
		for(i=0;i<3;i++)
		{
			if(fabs(C1[i])>1e-6)
			{
				k = i;
				break;
			}
		}
		if(C1[k]!=0)
		{
			for(i=0;i<3;i++) if(k!=i) p += C1[i]*C2[i];
			C2[k] = -p/C1[k];
		}
		for(i=0;i<3;i++)
			C3[i] = C1[(i+1)%3]*C2[(i+2)%3] - C2[(i+1)%3]*C1[(i+2)%3];
		for(i=0;i<3;i++)
		{
			temp = g_strdup_printf("%f",C2[i]);
		       	gtk_entry_set_text(GTK_ENTRY(entries[1][i]),temp);
			g_free(temp);
			temp = g_strdup_printf("%f",C3[i]);
		       	gtk_entry_set_text(GTK_ENTRY(entries[2][i]),temp);
			g_free(temp);
		}
		return ;
	}
	/* reset z for second direction, reset third direction */
	if(ii==1 && jj <= 1)
	{
		gdouble C1[3];
		gdouble C2[3];
		gdouble C3[3];
		gdouble p = 0;

		for(i=0;i<3;i++) C1[i] = atof(gtk_entry_get_text(GTK_ENTRY(entries[0][i])));
		for(i=0;i<3;i++) C2[i] = atof(gtk_entry_get_text(GTK_ENTRY(entries[1][i])));

		k = 2;
		if(C1[k]!=0)
		{
			for(i=0;i<3;i++) if(k!=i) p += C1[i]*C2[i];
			C2[k] = -p/C1[k];
		}
		for(i=0;i<3;i++) C3[i] = C1[(i+1)%3]*C2[(i+2)%3] - C2[(i+1)%3]*C1[(i+2)%3];

		temp = g_strdup_printf("%f",C2[k]);
		gtk_entry_set_text(GTK_ENTRY(entries[1][k]),temp);
		g_free(temp);

		for(i=0;i<3;i++)
		{
			temp = g_strdup_printf("%f",C3[i]);
		       	gtk_entry_set_text(GTK_ENTRY(entries[2][i]),temp);
			g_free(temp);
		}
		return;
	}
	if(jj==3)
	{
		gdouble min = 0;
		gdouble max = 0;

		min = atof(gtk_entry_get_text(GTK_ENTRY(entries[ii][jj])));
		max = -min;

		temp = g_strdup_printf("%f",max);
		gtk_entry_set_text(GTK_ENTRY(entries[ii][jj+1]),temp);
		g_free(temp);
		if(ii<2)
		{
			temp = g_strdup_printf("%f",min);
			gtk_entry_set_text(GTK_ENTRY(entries[ii+1][jj]),temp);
			g_free(temp);
		}

		return;
	}
	if(jj==4&& ii<2)
	{
		gdouble max = 0;

		max = atof(gtk_entry_get_text(GTK_ENTRY(entries[ii][jj])));
		temp = g_strdup_printf("%f",max);
		gtk_entry_set_text(GTK_ENTRY(entries[ii+1][jj]),temp);
		g_free(temp);
		return;
	}
	if(jj==5 && ii<2)
	{
		gint nPoints = 10;

		nPoints = atoi(gtk_entry_get_text(GTK_ENTRY(entries[ii][jj])));
		temp = g_strdup_printf("%d", nPoints);
		gtk_entry_set_text(GTK_ENTRY(entries[ii+1][jj]),temp);
		g_free(temp);
		return;
	}
}
/********************************************************************************/
GtkWidget *create_grid_frame( GtkWidget *vboxall,gchar* title)
{
	GtkWidget *frame;
	GtkWidget *vboxframe;
	gushort i;
	gushort j;
	GtkWidget *Table;
	gchar* temp = NULL;
	static GtkWidget* entries[3][6];

	frame = gtk_frame_new (title);
	gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
	gtk_container_add (GTK_CONTAINER (vboxall), frame);
	gtk_widget_show (frame);

	vboxframe = create_vbox(frame);
	Table = gtk_table_new(4,7,FALSE);
	gtk_container_add(GTK_CONTAINER(vboxframe),Table);

	/* first line , titles */
	i = 0; j = 0;
	j++;
	add_label_at_table(Table, "Vx",(gushort)i,(gushort)j,GTK_JUSTIFY_CENTER);
	j++;
	add_label_at_table(Table, "Vy",(gushort)i, (gushort)j,GTK_JUSTIFY_CENTER);
	j++;
	add_label_at_table(Table, "Vz",(gushort)i, (gushort)j,GTK_JUSTIFY_CENTER);
	j++;
	add_label_at_table(Table, "Minimum",(gushort)i, (gushort)j,GTK_JUSTIFY_CENTER);
	j++;
	add_label_at_table(Table, "Maximum",(gushort)i, (gushort)j,GTK_JUSTIFY_CENTER);
	j++;
	add_label_at_table(Table, "Number of points",(gushort)i, (gushort)j,GTK_JUSTIFY_CENTER);

	/* First direction */
	j = 0;
	i++;
	add_label_at_table(Table, "First direction ",(gushort)i,(gushort)j,GTK_JUSTIFY_LEFT);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),50,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"1.0");

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),50,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"0.0");

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),50,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"0.0");

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),100,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	temp = g_strdup_printf("%f",limits.MinMax[0][0]);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),temp);
	if(temp) g_free(temp);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),100,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	temp = g_strdup_printf("%f",limits.MinMax[1][0]);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),temp);
	if(temp) g_free(temp);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),100,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"33");

	/* Second direction */
	j = 0;
	i++;
	add_label_at_table(Table, "Second direction ",(gushort)i,(gushort)j,GTK_JUSTIFY_LEFT);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),50,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"0.0");

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),50,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"1.0");

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),50,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"0.0");
	gtk_widget_set_sensitive(entries[i-1][j-1], FALSE);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),100,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	temp = g_strdup_printf("%f",limits.MinMax[0][1]);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),temp);
	if(temp) g_free(temp);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),100,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	temp = g_strdup_printf("%f",limits.MinMax[1][1]);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),temp);
	if(temp) g_free(temp);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),100,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"33");

	/* Third direction */
	j = 0;
	i++;
	add_label_at_table(Table, "Third direction ",(gushort)i,(gushort)j,GTK_JUSTIFY_LEFT);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),50,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"0.0");
	gtk_widget_set_sensitive(entries[i-1][j-1], FALSE);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),50,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"0.0");
	gtk_widget_set_sensitive(entries[i-1][j-1], FALSE);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),50,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"1.0");
	gtk_widget_set_sensitive(entries[i-1][j-1], FALSE);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),100,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	temp = g_strdup_printf("%f",limits.MinMax[0][2]);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),temp);
	if(temp) g_free(temp);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),100,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	temp = g_strdup_printf("%f",limits.MinMax[1][2]);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),temp);
	if(temp) g_free(temp);

	j++;
	entries[i-1][j-1] = gtk_entry_new ();
    	gtk_widget_set_size_request(GTK_WIDGET(entries[i-1][j-1]),100,-1);
	add_widget_table(Table,entries[i-1][j-1],(gushort)i,(gushort)j);
	gtk_entry_set_text(GTK_ENTRY(entries[i-1][j-1]),"33");



	for(i=0;i<3;i++)
	for(j=0;j<6;j++)
	{
		g_object_set_data (G_OBJECT (entries[i][j]), "Entries", &entries);
	}

	for(i=0;i<3;i++)
	for(j=0;j<6;j++)
  		g_signal_connect(G_OBJECT(entries[i][j]), "changed",GTK_SIGNAL_FUNC(change_entry_value),entries[i][j]);

	gtk_widget_show_all(frame);
	g_object_set_data (G_OBJECT (frame), "Entries",&entries);

  	return frame;
}
/********************************************************************************/
void create_grid(gchar* title)
{
	GtkWidget *Win;
	GtkWidget *frame;
	GtkWidget *hbox;
	GtkWidget *vboxall;
	GtkWidget *vboxwin;
	GtkWidget *button;
	GtkWidget** entries;

	if(!GeomOrb)
	{
		Message("Sorry, Please load a file before\n","Error",TRUE);
		return;
	}
	if(!CoefAlphaOrbitals)
	{
		Message("Sorry, Please load the MO before\n","Error",TRUE);
		return;
	}

	if(!AOAvailable &&(TypeGrid == GABEDIT_TYPEGRID_DDENSITY || TypeGrid == GABEDIT_TYPEGRID_ADENSITY))
	{
		Message("Sorry, No atomic orbitals available.\nPlease use a gabedit file for load : \n"
		  "Geometry, Molecular and Atomic Orbitals\n","Error",TRUE);
		return;
	}
	
	Win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(Win),title);
	gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width (GTK_CONTAINER (Win), 5);
	gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(PrincipalWindow));
	gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

	add_glarea_child(Win,"Grid ");

	vboxall = create_vbox(Win);
	vboxwin = vboxall;
	frame = create_grid_frame(vboxall,"Box & Grid");
	entries = (GtkWidget**) g_object_get_data (G_OBJECT (frame), "Entries");
	g_object_set_data (G_OBJECT (Win), "Entries",entries);
   

	hbox = create_hbox_false(vboxwin);
	gtk_widget_realize(Win);

	button = create_button(Win,"Cancel");
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)delete_child, G_OBJECT(Win));
	g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)gtk_widget_destroy,G_OBJECT(Win));
	gtk_widget_show (button);

	button = create_button(Win,"OK");
	gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_widget_grab_default(button);
	gtk_widget_show (button);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)applygrid,G_OBJECT(Win));
  

	gtk_widget_show_all (Win);
}
/********************************************************************************/
void read_any_file(gchar* FileName)
{
	gint filetype = get_type_file(FileName);
	switch(filetype)
	{
		case GABEDIT_TYPEFILE_GAUSSIAN : read_gauss_orbitals(FileName);break;
		case GABEDIT_TYPEFILE_MOLPRO : read_molpro_orbitals(FileName);break;
		case GABEDIT_TYPEFILE_MOLDEN : read_molden_orbitals(FileName);break;
		case GABEDIT_TYPEFILE_GABEDIT : read_gabedit_orbitals(FileName);break;
		case GABEDIT_TYPEFILE_XYZ : gl_read_xyz_file(FileName);break;
		case GABEDIT_TYPEFILE_GAUSIANINPUT : 
		case GABEDIT_TYPEFILE_MOLCASINPUT :  
		case GABEDIT_TYPEFILE_MOLPROINPUT :  
		case GABEDIT_TYPEFILE_UNKNOWN : break;
	}
}
/********************************************************************************/
gint get_number_of_point(GtkWidget* Entry)
{
	gchar* t = NULL;
	gint N = -1;
        G_CONST_RETURN gchar* temp = gtk_entry_get_text(GTK_ENTRY(Entry)); 
	if(temp)
	{
		t = g_strdup(temp);
		delete_first_spaces(t);
		delete_last_spaces(t);
	}
	if(t && !this_is_a_integer(t))
	{
		GtkWidget* win = Message("Error : The number of points should be integer. ","Error",TRUE);
  		gtk_window_set_modal (GTK_WINDOW (win), TRUE);
		g_free(t);
		return -1;
	}
	if(t) g_free(t);
	N = atoi(temp);
	if(N<=0)
	{
		GtkWidget* win = Message("Error : The number of points should be positive. ","Error",TRUE);
  		gtk_window_set_modal (GTK_WINDOW (win), TRUE);
		return -1;
	}
	return N;
}
/********************************************************************************/
gboolean get_a_float(GtkWidget* Entry,gfloat* value, gchar* errorMessage)
{
	G_CONST_RETURN gchar* temp;
	gchar* t = NULL;
        temp	= gtk_entry_get_text(GTK_ENTRY(Entry)); 
	if(temp&& strlen(temp)>0)
	{
		t = g_strdup(temp);
		delete_first_spaces(t);
		delete_last_spaces(t);
	}
	else
	{
		GtkWidget* win = Message(errorMessage,"Error",TRUE);
  		gtk_window_set_modal (GTK_WINDOW (win), TRUE);
		return FALSE;
	}
	if(t && !this_is_a_real(t))
	{
		GtkWidget* win = Message(errorMessage,"Error",TRUE);
		g_free(t);
  		gtk_window_set_modal (GTK_WINDOW (win), TRUE);
		return FALSE;
	}
	if(t) g_free(t);
	*value = atof(temp);
	return TRUE;
}
/********************************************************************************/
void initialise_global_orbitals_variables()
{
	gint i;
	PopupMenuIsOpen = FALSE;
	GeomOrb = NULL;
	GLArea = NULL;
	Ncenters =0;
 	ShowDipoleOrb = TRUE;
 	ShowHBondOrb = FALSE;
 	ShowVibration = FALSE;
	TypeGrid = GABEDIT_TYPEGRID_ORBITAL;
	TypeGeom = GABEDIT_TYPEGEOM_STICK;
	TypeBlend = GABEDIT_BLEND_YES;
	TypePosWireFrame = GABEDIT_POS_WIREFRAME_NO;
	TypeNegWireFrame = GABEDIT_NEG_WIREFRAME_NO;
	SurfShow = GABEDIT_SURFSHOW_POSNEG;
	TypeTexture = GABEDIT_TYPETEXTURE_NONE;
	Title = NULL;
	ScreenWidth = gdk_screen_width();
	ScreenHeight = gdk_screen_height();
	for(i=0;i<3;i++)
		limits.MinMax[0][i] = -5;
	for(i=0;i<3;i++)
		limits.MinMax[1][i] = 5;
	NumPoints[0] = 30;
	NumPoints[1] = 30;
	NumPoints[2] = 30;
	CoefAlphaOrbitals = NULL;
	EnerAlphaOrbitals = NULL;
	OccAlphaOrbitals = NULL;
	SymAlphaOrbitals = NULL;
	CoefBetaOrbitals = NULL;
	EnerBetaOrbitals = NULL;
	OccBetaOrbitals = NULL;
	SymBetaOrbitals = NULL;
	isopositive = NULL;
	isonegative = NULL;
	isonull = NULL;
	grid = NULL;
	gridPlaneForContours = NULL;
	gridPlaneForPlanesMapped = NULL;

	reDrawContoursPlane = FALSE;
	reDrawPlaneMappedPlane = FALSE;

	AOAvailable = FALSE;
	RebuildSurf = TRUE;
	RebuildGeom = TRUE;
	newContours = TRUE;
	newSurface = FALSE;
	DeleteContours = FALSE;
	CancelCalcul = FALSE;
	init_vibration();
	createBMPFiles = FALSE;
	numBMPFile = 0;
	createPPMFiles = FALSE;
	numPPMFile = 0;
	createPOVFiles = FALSE;
	numPOVFile = 0;
}
/********************************************************************************/
void close_window_orb(GtkWidget*win, gpointer data)
{
	if(!GTK_IS_WIDGET(PrincipalWindow)) return;

	CancelCalcul = TRUE;
	while( gtk_events_pending() ) gtk_main_iteration();

	free_data_all();
	free_objects_all();

  	destroy_childs(PrincipalWindow);

	GLArea = NULL;
	PrincipalWindow = NULL;
}
/********************************************************************************/
gboolean to_cgtf_is_id(CGTF t1,CGTF t2)
{
	gint i;
	gint c;
	if(t1.N != t2.N)
		return FALSE;
	for(i=0;i<3;i++)
		if(t1.Gtf[0].l[i] != t2.Gtf[0].l[i])
			return FALSE;
	for(i=0;i<t1.N;i++)
	{
		if(fabs(t1.Gtf[i].Ex-t2.Gtf[i].Ex)>1e-10)
			return FALSE;
		if(fabs(t1.Gtf[i].Coef-t2.Gtf[i].Coef)>1e-10)
			return FALSE;
		for(c=0;c<3;c++)
			if(fabs(t1.Gtf[i].C[c]-t2.Gtf[i].C[c])>1e-10)
				return FALSE;
	}
	return TRUE;
}
/********************************************************************************/
void add_glarea_child(GtkWidget* winchild,gchar* title)
{
  if(GLArea)
  {
  	add_child(PrincipalWindow,winchild,gtk_widget_destroy,title);
  	g_signal_connect(G_OBJECT(winchild),"delete_event",(GtkSignalFunc)delete_child,NULL);
  }
  else
  {
  	add_button_windows(title,winchild);
  	g_signal_connect(G_OBJECT(winchild), "delete_event",(GtkSignalFunc)destroy_button_windows,NULL);
  	g_signal_connect(G_OBJECT(winchild), "delete_event",GTK_SIGNAL_FUNC(gtk_widget_destroy),NULL);
  }
}
/*************************************************************************************/
void create_color_surfaces_file()
{
	gchar *colorsurface;
	FILE *fd;
	gdouble v[4];
	gint i;
	gint j;
	gint n=3;

	colorsurface = g_strdup_printf("%s/colorssurface",gabedit_directory());

	fd = FOpen(colorsurface, "w");
	if(fd)
	{
		fprintf(fd,"%d\n",n);
		for(i=0;i<n;i++)
		{
			get_color_surface(i,v) ;
			for(j=0;j<4;j++)
				fprintf(fd,"%lf ",v[j]);
			fprintf(fd,"\n");
		}
		fclose(fd);
	}

	g_free(colorsurface);
}
/*************************************************************************************/
void read_color_surfaces_file()
{
	gchar *colorsurface; 
	FILE *fd;
	gint i;
	gint n = 0;
	gchar t[BSIZE];
	gint len = BSIZE;
	gdouble v[4];

	colorsurface = g_strdup_printf("%s/colorssurface",gabedit_directory());

	fd = FOpen(colorsurface, "r");
	if(fd)
	{
		fgets(t,len,fd);
		n = atoi(t);
		for(i=0;i<n;i++)
		{
			fgets(t,len,fd);
			sscanf(t,"%lf %lf %lf %lf",&v[0],&v[1],&v[2],&v[3]);
			set_color_surface(i,v);
		}
 		fclose(fd);
	}
	g_free(colorsurface);
}
/*************************************************************************************/
void create_opengl_file()
{
	gchar *openglfile;
	FILE *fd;

	openglfile = g_strdup_printf("%s%sopengl",gabedit_directory(),G_DIR_SEPARATOR_S);

	fd = FOpen(openglfile, "w");
	if(fd !=NULL)
	{
		fprintf(fd,"%d\n",openGLOptions.rgba);
		fprintf(fd,"%d\n",openGLOptions.doubleBuffer);
		fprintf(fd,"%d\n",openGLOptions.alphaSize);
		fprintf(fd,"%d\n",openGLOptions.depthSize);
		fprintf(fd,"%d\n",openGLOptions.numberOfSubdivisionsCylindre);
		fprintf(fd,"%d\n",openGLOptions.numberOfSubdivisionsSphere);
		fclose(fd);
	}
	g_free(openglfile);
}
/*************************************************************************************/
void read_opengl_file()
{
	gchar *openglfile;
	FILE *fd;

	openglfile = g_strdup_printf("%s%sopengl",gabedit_directory(),G_DIR_SEPARATOR_S);

	fd = FOpen(openglfile, "r");
	openGLOptions.rgba = 1;
	openGLOptions.doubleBuffer = 1;
	openGLOptions.alphaSize = 0;
	openGLOptions.depthSize = 0;
	openGLOptions.numberOfSubdivisionsCylindre = 10; 
	openGLOptions.numberOfSubdivisionsSphere = 15; 
	if(fd !=NULL)
	{
 		guint taille = BSIZE;
 		gchar t[BSIZE];
 		if(fgets(t,taille,fd))
			if(sscanf(t,"%d",&openGLOptions.rgba)!=1)
				openGLOptions.rgba = 1;
 		if(fgets(t,taille,fd))
			if(sscanf(t,"%d",&openGLOptions.doubleBuffer)!=1)
				openGLOptions.doubleBuffer = 1;
 		if(fgets(t,taille,fd))
			if(sscanf(t,"%d",&openGLOptions.alphaSize)!=1)
				openGLOptions.alphaSize = 1;
 		if(fgets(t,taille,fd))
			if(sscanf(t,"%d",&openGLOptions.depthSize)!=1)
				openGLOptions.depthSize = 1;
 		if(fgets(t,taille,fd))
			if(sscanf(t,"%d",&openGLOptions.numberOfSubdivisionsCylindre)!=1)
				openGLOptions.numberOfSubdivisionsCylindre = 10;
 		if(fgets(t,taille,fd))
			if(sscanf(t,"%d",&openGLOptions.numberOfSubdivisionsSphere)!=1)
				openGLOptions.numberOfSubdivisionsSphere = 10;

		fclose(fd);
	}
	g_free(openglfile);
}
/*************************************************************************************/
