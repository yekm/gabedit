/* Basis.c */
/**********************************************************************************************************
Copyright (c) 2002-2009 Abdul-Rahman Allouche. All rights reserved

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
#include "GlobalOrb.h"
#include "UtilsOrb.h"
#include "../Utils/Utils.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Constants.h"

/********************************************************************************/
void save_basis_gabedit_format(FILE* file)
{
	gint i;
	gint j;
	gint k;
	gint c;
	fprintf(file,"[Basis]\n");
	for(c = 0;c<Ncenters; c++)
	{
		i = GeomOrb[c].NumType;
		fprintf(file,"   %d 0\n", c+1);
 		for(j=0;j<Type[i].Norb;j++)
		{
			fprintf(file," %c %d 1.0\n",GetSymmetry(Type[i].Ao[j].L),Type[i].Ao[j].N);
			for(k=0;k<Type[i].Ao[j].N;k++)
				fprintf(file," %14.6f %14.6f\n",Type[i].Ao[j].Ex[k],Type[i].Ao[j].Coef[k]);
		}
		fprintf(file,"\n");
	}
	fprintf(file,"\n");
}
/**********************************************/
gint ReadCommandLines()
{
  gint taille=BSIZE;
  char *t = g_malloc(taille);

  if(forb == NULL)
	return 0;
  while(!feof(forb))
  {
   fgets(t,taille,forb);
   if(!strcmp(t," ") ||  !strcmp(t,"\n") )
        return 1; 
   if( t[0] != '#' )
   {
     Debug("\n\nERROR : theyre firsts lines is not a commads lines\n\n");
     return 0;
   }
  }
 return 0;
}
/**********************************************/
gint OpenDataFile(char * NameFile)
{
 forb = FOpen(NameFile, "rb");
 if(forb == NULL)
 {
   Debug("\n\nERROR Can not open %s data file\n\n",NameFile);
   return 0;
 }
 return 1;
}
/**********************************************/
void PrintBasis()
{
 gint i;
 gint j,k;
 Debug("\n\n");
 printLineChar('*',72);
 for(i=0;i<Ntype;i++)
 {
  Debug("Basis for center %s \n",Type[i].Symb);
  Debug("====================\n");
  Debug("Norb\t\t= %d\n",Type[i].Norb);
  Debug("\n");
 Debug("- --------- --------- \n");
 Debug("l     Ex       Coef   \n");
 Debug("- --------- --------- \n");
 for(j=0;j<Type[i].Norb;j++)
 {	k=0;
	Debug("%c %14.6f %14.6f\n",GetSymmetry(Type[i].Ao[j].L),Type[i].Ao[j].Ex[k],Type[i].Ao[j].Coef[k]);
	for(k=1;k<Type[i].Ao[j].N;k++)
		Debug("  %14.6f %14.6f\n",Type[i].Ao[j].Ex[k],Type[i].Ao[j].Coef[k]);
    
 }
 Debug("\n");
 /*
 if(Type[i].nps>0)
 {
	Debug("Pseudo potential for center %s\n",Type[i].Symb);
  	Debug("==============================\n\n");
 	Debug("-\t-  --------- ---------\n");
 	Debug("l\tn    Eps       Tau\n");
 	Debug("-\t-  --------- ---------\n");
 }
 else
	Debug("No Pseudo potential for %s\n",Type[i].Symb);
 for(j=0;j<Type[i].nps;j++)
 {
    Debug("%d\t%d %9.6f %9.6f ",Type[i].ps[j].l,Type[i].ps[j].n,Type[i].ps[j].eps,Type[i].ps[j].tau);
    Debug("\n");

 }
 */
 printLineChar('*',72);
 Debug("\n");
 }
}

/**********************************************/
gboolean ReadOneBasis(gint i,gint j,char *t,gint *nsym)
{
	gint k;
	gint n;
	gint taille = BSIZE;
	gchar *sym = g_malloc(10*sizeof(gchar));
	gint l=1;

	/*Debug("i = %d j= %d\n",i,j);*/
	/*Debug("t One %s\n",t);*/
        /*sscanf(t,"%s %d",sym,&Type[i].Ao[j].N);*/
	sscanf(t,"%s %d",sym,&n);
	/*	Debug("n = %d\n",n);*/
	Type[i].Ao[j].N=n;
	/*Debug("N = %d\n",Type[i].Ao[j].N);*/
	Type[i].Ao[j].Ex=g_malloc(Type[i].Ao[j].N*sizeof(gfloat));
	Type[i].Ao[j].Coef=g_malloc(Type[i].Ao[j].N*sizeof(gfloat));
	/*Debug("avant sym ==\n");*/
	if(strlen(sym)==2)
	{
	 	l=2;
     		Type[i].Ao=g_realloc(Type[i].Ao,(j+2)*sizeof(AO));
        	Type[i].Ao[j+1].N = Type[i].Ao[j].N;
		Type[i].Ao[j+1].Ex=g_malloc(Type[i].Ao[j].N*sizeof(gfloat));
		Type[i].Ao[j+1].Coef=g_malloc(Type[i].Ao[j].N*sizeof(gfloat));
	}
	*nsym = l;
	/*Debug("nsym = %d\n",l);*/

		
	for(k=0;k<Type[i].Ao[j].N;k++)
	{
		fgets(t,taille,forb);
		for(n=0;n<(gint)strlen(t);n++)
			if(t[n]=='D') t[n] = 'e';
		/*Debug("t de One = %s\n",t);*/
		   
		if(l==1) sscanf(t,"%f %f ",&Type[i].Ao[j].Ex[k],&Type[i].Ao[j].Coef[k]);
		else
		{
			sscanf(t,"%f %f %f ",&Type[i].Ao[j].Ex[k],&Type[i].Ao[j].Coef[k],&Type[i].Ao[j+1].Coef[k]);
			Type[i].Ao[j+1].Ex[k] = Type[i].Ao[j].Ex[k];
		}
	}
	/*Debug("end k\n");*/

    switch(sym[0])
    {
        case 's' : 
        case 'S' : Type[i].Ao[j].L=0;break;
        case 'p' :
        case 'P' : Type[i].Ao[j].L=1;break; 
        case 'd' : 
        case 'D' : Type[i].Ao[j].L=2;break;
        case 'f' : 
        case 'F' : Type[i].Ao[j].L=3;break;         
		case 'g' : 
        case 'G' : Type[i].Ao[j].L=4;break;
		case 'h' : 
        case 'H' : Type[i].Ao[j].L=5;break;
		case 'i' : 
        case 'I' : Type[i].Ao[j].L=6;break;
		case 'j' : 
        case 'J' : Type[i].Ao[j].L=7;break;
		case 'k' : 
        case 'K' : Type[i].Ao[j].L=8;break;
		case 'l' : 
        case 'L' : Type[i].Ao[j].L=9;break;
        default :	g_free(sym);
			g_free(Type[i].Ao[j].Ex);
			g_free(Type[i].Ao[j].Coef);
         		return FALSE;
    }
    /*
	if(l == 2)
		Debug(" sym[1] =%c \n",sym[1]);
    */
	if(l == 2)
    switch(sym[1])
    {
        case 's' : 
        case 'S' : Type[i].Ao[j+1].L=0;break;
        case 'p' :
        case 'P' : Type[i].Ao[j+1].L=1;break; 
        case 'd' : 
        case 'D' : Type[i].Ao[j+1].L=2;break;
        case 'f' : 
        case 'F' : Type[i].Ao[j+1].L=3;break;         
		case 'g' : 
        case 'G' : Type[i].Ao[j+1].L=4;break;
		case 'h' : 
        case 'H' : Type[i].Ao[j+1].L=5;break;
		case 'i' : 
        case 'I' : Type[i].Ao[j+1].L=6;break;
		case 'j' : 
        case 'J' : Type[i].Ao[j+1].L=7;break;
		case 'k' : 
        case 'K' : Type[i].Ao[j+1].L=8;break;
		case 'l' : 
        case 'L' : Type[i].Ao[j+1].L=9;break;

        default :	g_free(sym);
			g_free(Type[i].Ao[j+1].Ex);
			g_free(Type[i].Ao[j+1].Coef);
         		return FALSE;
     }
	/*Debug("end readone basis \n");*/
       g_free(sym);
       return TRUE;
}
/**********************************************/
gboolean DefineBasisType(gchar *NomFichier)
{
	gchar *sym;
	gchar *t;
	gchar *pdest;
	gint taille=BSIZE;
	gint i;
	gint j;
	gboolean ok;
	gint nsym;
	long int geompos =  0;

	/* Debug("debut de DefineBasisType\n");*/
 	if ((!NomFichier) || (strcmp(NomFichier,"") == 0))
 	{
		Message("Sorry\n No file slected","Error",TRUE);
    		return FALSE;
 	}

 	t=g_malloc(taille*sizeof(gchar));
 	forb = FOpen(NomFichier, "rb");
 	if(forb == NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",NomFichier);
  		Message(buffer,"Error",TRUE);
  		return FALSE;
 	}
	ok = FALSE;
	while(!feof(forb))
	{
		fgets(t,taille,forb);
		pdest = strstr(t,"asis set"); /* Basis for g98 and basis for g03 */
		if(pdest != NULL)
		{
			ok = TRUE;
			geompos =  ftell(forb);
			/* break; NO for get the last basis */
		}
	}
	if(!ok)
	{
		gchar* t = g_strdup_printf("Sorry,\nI can not read atomic basis and/or molecular orbitals from\n \"%s\"\n file\n"
					   "\nFor display density and/or molecular orbitals from gaussian output file,\n"
					   "the following keywords are required:\n"
					   "#P  Gfinput  IOP(6/7=3)  Pop=full\n"
					   "\n",
					   NomFichier);
		Message(t,"Error",TRUE);
		g_free(t);
  		return FALSE;
	}
	fseek(forb, geompos, SEEK_SET);

	sym=g_malloc(10*sizeof(gchar));

	t=(gchar*)g_malloc(taille*sizeof(gchar));
 
	if(forb !=NULL)
	{
		/* Debug("Ntype = %d\n",Ntype);*/
		Type = g_malloc(Ntype*sizeof(TYPE));
		for(i=0;i<Ntype;i++)
			Type[i].Ao = NULL;
		while(!feof(forb))
		{
			fgets(t,taille,forb);
     			if(!strcmp(t,"\n") || !strcmp(t," ") )
     			{
				g_free(sym);
				g_free(t);
				for(i=0;i<Ntype;i++)
				if(Type[i].Ao == NULL)
				{
					gchar buffer[BSIZE];
					sprintf(buffer,"Sorry, I can not read '%s' file, problem with basis set\n",NomFichier);
  					Message(buffer,"Error",TRUE);
					return FALSE;
				}
       				return TRUE;
			}

			if(  strcmp(t,"\n")!= 0  && strcmp(t," ") && t[1] !='*')
			{
				sscanf(t,"%s",sym);
				sym[0]=toupper(sym[0]);
				if(strlen(sym)>1)
     				sym[1]=tolower(sym[1]);
				/*i=GetNumType(sym);*/
				i=atoi(sym)-1;
				if(i>-1)
				{
					sym = g_strdup( GeomOrb[i].Symb);
					i = GeomOrb[i].NumType;
     					Type[i].Symb=g_strdup(sym);
     					Type[i].N=GetNelectrons(sym);
     					j=-1;
					while(!feof(forb))
     					{
     						fgets(t,taille,forb);
     						if(!strcmp(t,"\n") || t[1]=='*') break;
     						j++;
        					Type[i].Norb=j+1;
     						if(j == 0) Type[i].Ao=g_malloc(sizeof(AO));
     						else Type[i].Ao=g_realloc(Type[i].Ao,(j+1)*sizeof(AO));

     						ok= ReadOneBasis(i,j,t,&nsym);
        					if(nsym==2)
						{
							Type[i].Norb=j+2;
							j++;
						}
						if(!ok)
						{
							j  = j - nsym;
     							if(j==0) Type[i].Ao=g_malloc(sizeof(AO));
     							else Type[i].Ao=g_realloc(Type[i].Ao,(j+1)*sizeof(AO));
        						Type[i].Norb=j+1;
						}
     					}
				}
				else
				{
     					if(!strcmp(t,"\n") || !strcmp(t," ") )
     					{
     						g_free(sym);
       						g_free(t);
						for(i=0;i<Ntype;i++)
						if(Type[i].Ao == NULL)
						{
							gchar buffer[BSIZE];
							sprintf(buffer,"Sorry, I can not read '%s' file, problem with basis set\n",NomFichier);
  							Message(buffer,"Error",TRUE);
							return FALSE;
						}
       						return TRUE;
     					}
        				break;
				}
			}
		}
	}
	for(i=0;i<Ntype;i++)
	if(Type[i].Ao == NULL)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not read '%s' file, problem with basis set\n",NomFichier);
  		Message(buffer,"Error",TRUE);
		return FALSE;
	}
	return TRUE;
}
/**********************************************/
static void resortAtoms(gint* numAtoms)
{
	TypeGeomOrb* newGeom = NULL;
	gint i;
	/* printf("begin resortAtoms\n  ");*/
	if(!numAtoms)return;
	if(Ncenters<1)return;
	/*
	printf("Sorting  ");
	for(i=0;i<Ncenters;i++) printf("%d ",numAtoms[i]);
	printf("\n");
	*/
	for(i=0;i<Ncenters;i++) if(numAtoms[i] == -1) return;
	newGeom = g_malloc(Ncenters*sizeof(TypeGeomOrb));
	for(i=0;i<Ncenters;i++) newGeom[i] = GeomOrb[numAtoms[i]];
	for(i=0;i<Ncenters;i++) GeomOrb[i] = newGeom[i];
	g_free(newGeom);
}
/**********************************************/
gboolean DefineGabeditMoldenBasisType(gchar *NomFichier,gchar* title)
{
	gchar *sym;
	gchar *t;
	gchar *pdest;
	gint taille=BSIZE;
	gint i;
	gint j;
	gboolean ok;
	gint nsym;
	gint* numAtoms = NULL;
	gint nAtoms = 0;

 	if ((!NomFichier) || (strcmp(NomFichier,"") == 0))
 	{
		Message("Sorry\n No file slected","Error",TRUE);
    		return FALSE;
 	}

 	t=g_malloc(taille*sizeof(gchar));
 	forb = FOpen(NomFichier, "rb");
 	if(forb == NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",NomFichier);
  		Message(buffer,"Error",TRUE);
  		return FALSE;
 	}
	ok = FALSE;
	while(!feof(forb))
	{
		fgets(t,taille,forb);
		pdest = strstr(t,title);
		if(pdest != NULL)
		{
			ok = TRUE;
			break;
		}
	}
	if(!ok)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry\nI can not read basis from '%s' file\n",NomFichier);
  		Message(buffer,"Error",TRUE);
  		return FALSE;
	}

	sym=g_malloc(10*sizeof(char));

	if(forb !=NULL)
	{
		/* Debug("Ntype = %d\n",Ntype);*/
		numAtoms = g_malloc(Ncenters*sizeof(gint));
		for(i=0;i<Ncenters;i++) numAtoms[i] = -1;
		nAtoms = 0;
		Type = g_malloc(Ntype*sizeof(TYPE));
		for(i=0;i<Ntype;i++)
		{
			Type[i].Ao = NULL;
        		Type[i].Norb=0;
		}
		sprintf(t," ");
		while(!feof(forb))
		{
			if(strstr(t,"[")) break;
			fgets(t,taille,forb);
			/* Debug("tav = %s\n",t);*/
			if(this_is_a_backspace(t) || strstr(t,"["))
     			{
				g_free(sym);
				g_free(t);
				for(i=0;i<Ntype;i++)
				if(Type[i].Ao == NULL)
				{
					gchar buffer[BSIZE];
					sprintf(buffer,"Sorry, I can not read '%s' file, problem with basis set (1)\n",NomFichier);
  					Message(buffer,"Error",TRUE);
					printf("AO pour i = %d\n", i);
					if(numAtoms) g_free(numAtoms);
					return FALSE;
				}
				resortAtoms(numAtoms);
				if(numAtoms) g_free(numAtoms);
       				return TRUE;
			}

     			if(!this_is_a_backspace(t))
			{
				/*Debug("tap = %s\n",t);*/
				i=atoi(t)-1;
				if(i>-1 && i<Ncenters) numAtoms[nAtoms] = i;
				nAtoms++;
				/*Debug("i1 = %d \n",i);*/
				if(i>-1)
				{
					sym = g_strdup( GeomOrb[i].Symb);
					i = GeomOrb[i].NumType;
					/* printf("numType = %d\n",i);*/
     					Type[i].Symb=g_strdup(sym);
     					Type[i].N=GetNelectrons(sym);
     					j=-1;
					while(!feof(forb))
     					{
     						fgets(t,taille,forb);
						/* Debug("t = %s\n",t);*/
     						if(this_is_a_backspace(t) || strstr(t,"["))
				 		{
							/*Debug("This is a backspace\n");*/
        						break;
						}
						/*
						else
							Debug("This is not a backspace\n");
						*/
     						j++;
        					Type[i].Norb=j+1;
						/*
						Debug("debut Alloc %d %d \n",i,j);
						Debug("point %d \n",Type[i].Ao);
						*/
     						if(j == 0) Type[i].Ao=g_malloc(sizeof(AO));
     						else Type[i].Ao=g_realloc(Type[i].Ao,(j+1)*sizeof(AO));

						/*
						Debug("debut ReadOne i=%d j = %d \n",i,j);
						Debug("debut t = %s \n",t);
						*/
     						ok= ReadOneBasis(i,j,t,&nsym);
						/*Debug("nsym apres = %d\n",nsym);*/
        					if(nsym==2)
						{
							Type[i].Norb = j+2;
							j++;
						}
						if(!ok)
						{
							j  = j - nsym;
     							if(j==0) Type[i].Ao=g_malloc(sizeof(AO));
     							else Type[i].Ao=g_realloc(Type[i].Ao,(j+1)*sizeof(AO));
        						Type[i].Norb=j+1;
						}
     
     					}
				}
				else
				{
    					/*Debug("else = %s\n",t);*/
     					if(this_is_a_backspace(t) || strstr(t,"["))
     					{
     						g_free(sym);
       						g_free(t);
						for(i=0;i<Ntype;i++)
						if(Type[i].Ao == NULL)
						{
							gchar buffer[BSIZE];
							sprintf(buffer,"Sorry, I can not read '%s' file, problem with basis set (2)\n",NomFichier);
  							Message(buffer,"Error",TRUE);
							if(numAtoms) g_free(numAtoms);
							return FALSE;
						}
						resortAtoms(numAtoms);
						if(numAtoms) g_free(numAtoms);
       						return TRUE;
     					}
        				break;
				}
			}
		}
	}
	for(i=0;i<Ntype;i++)
	if(Type[i].Ao == NULL)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not read '%s' file, problem with basis set (3)\n",NomFichier);
  		Message(buffer,"Error",TRUE);
		if(numAtoms) g_free(numAtoms);
		return FALSE;
	}
	resortAtoms(numAtoms);
	if(numAtoms) g_free(numAtoms);
    	return TRUE;
}
/**********************************************/
gboolean DefineMoldenBasisType(gchar *NomFichier)
{
	/* Debug("begin of DefineMoldenBasisType\n");*/
	return DefineGabeditMoldenBasisType(NomFichier,"[GTO]");
}
/**********************************************/
gboolean DefineGabeditBasisType(gchar *NomFichier)
{
/*	Debug("begin of DefineGabeditBasisType\n");*/
	return DefineGabeditMoldenBasisType(NomFichier,"[Basis]");
}
/**********************************************/
void PrintAllBasis()
{
 gint k,j,n;
 gint l;
 char *XYZ[]={"x","y","z"};


 for(k=0;k<NAOrb;k++)
 {

	 for(n=0;n<AOrb[k].N;n++)
	 {
		
		 l=0;
		 for(j=0;j<3;j++)
		   l += AOrb[k].Gtf[n].l[j];

		 Debug("%c",GetSymmetry(l));
		 for(j=0;j<3;j++)
		 {
			 switch(AOrb[k].Gtf[n].l[j])
			 {
			 case 0:break;
			 case 1:Debug("%s",XYZ[j]);break;
			 default :Debug("%s%d",XYZ[j],AOrb[k].Gtf[n].l[j]);
			 }
		 }
			Debug("\t%9.6f %9.6f ",AOrb[k].Gtf[n].Ex,AOrb[k].Gtf[n].Coef);
			Debug("\n");
	 }
	 Debug("\n");
 }
}
/**********************************************/
void NormaliseAllBasis()
{
 gint k,n;

 for(k=0;k<NAOrb;k++)
	 for(n=0;n<AOrb[k].N;n++)
		 NormaliseRadial(&AOrb[k].Gtf[n]);

 for(k=0;k<NAOrb;k++)
		 NormaliseCGTF(&AOrb[k]);
}
/**********************************************/
void DefineAtomicNumOrb()
{
	gint i;
	gint j;
	for(i=0;i<Ncenters;i++)
	{
	/*	Debug("i= %d \n",i);*/
		GeomOrb[i].NAOrb = 0;
		GeomOrb[i].NAlphaOrb = 0;
		GeomOrb[i].NBetaOrb = 0;
		GeomOrb[i].NumOrb = NULL;
		GeomOrb[i].CoefAlphaOrbitals = NULL;
		GeomOrb[i].OccAlphaOrbitals = NULL;
		GeomOrb[i].EnerAlphaOrbitals = NULL;
		GeomOrb[i].SymAlphaOrbitals = NULL;
		GeomOrb[i].CoefBetaOrbitals = NULL;
		GeomOrb[i].EnerBetaOrbitals = NULL;
		GeomOrb[i].OccBetaOrbitals = NULL;
		GeomOrb[i].SymBetaOrbitals = NULL;
	}
	/* Debug("End Geom init \n");*/

	for(j=0;j<NAOrb;j++)
	{
		if(AOrb) i = AOrb[j].NumCenter;
		else if(SAOrb) i = SAOrb[j].NumCenter;
		GeomOrb[i].NAOrb++;
		if(!GeomOrb[i].NumOrb)
			GeomOrb[i].NumOrb = g_malloc(GeomOrb[i].NAOrb*sizeof(gint));
		else
			GeomOrb[i].NumOrb = g_realloc(GeomOrb[i].NumOrb,GeomOrb[i].NAOrb*sizeof(gint));
		GeomOrb[i].NumOrb[GeomOrb[i].NAOrb-1] = j;
	}
}
/**********************************************/
void DefineCartBasis()
{
 gint i,j,k,n;
 gint l1,l2,l3;
 gint L;
 gint *l[3]={NULL,NULL,NULL};
 gint m;

 NAOrb = 0;
 for(i=0;i<Ncenters;i++)
 {
	 for(j=0;j<Type[GeomOrb[i].NumType].Norb;j++)
	 {
		L=Type[GeomOrb[i].NumType].Ao[j].L;
		NAOrb += (L+1)*(L+2)/2;
	 }
 }

 AOrb = g_malloc(NAOrb*sizeof(CGTF));
 if(SAOrb) g_free(SAOrb);
 SAOrb = NULL;
 
 k=-1;
 for(i=0;i<Ncenters;i++)
	 for(j=0;j<Type[GeomOrb[i].NumType].Norb;j++)
 {
	L = Type[GeomOrb[i].NumType].Ao[j].L;

	for(m=0;m<3;m++)
	{
		if(l[m])
		   g_free(l[m]);
		l[m] = g_malloc((L+1)*(L+2)/2*sizeof(gint));
	}
	switch(L)
	{
	  case 1 :
		 m=0;
		 l[0][m] = 1;l[1][m] = 0;l[2][m] = 0; /* X */
		 m++;
		 l[0][m] = 0;l[1][m] = 1;l[2][m] = 0; /* Y */
		 m++;
		 l[0][m] = 0;l[1][m] = 0;l[2][m] = 1; /* Z */
	  	 break;
	  case 2 :
		 m=0;
		 l[0][m] = 2;l[1][m] = 0;l[2][m] = 0; /* XX */
		 m++;
		 l[0][m] = 0;l[1][m] = 2;l[2][m] = 0; /* YY */
		 m++;
		 l[0][m] = 0;l[1][m] = 0;l[2][m] = 2; /* ZZ */
		 m++;
		 l[0][m] = 1;l[1][m] = 1;l[2][m] = 0; /* XY */
		 m++;
		 l[0][m] = 1;l[1][m] = 0;l[2][m] = 1; /* XZ */
		 m++;
		 l[0][m] = 0;l[1][m] = 1;l[2][m] = 1; /* YZ */
		 break;
	  case 3 :
		 m=0;
		 l[0][m] = 3;l[1][m] = 0;l[2][m] = 0; /* XXX */
		 m++;
		 l[0][m] = 0;l[1][m] = 3;l[2][m] = 0; /* YYY */
		 m++;
		 l[0][m] = 0;l[1][m] = 0;l[2][m] = 3; /* ZZZ */
		 m++;
		 l[0][m] = 1;l[1][m] = 2;l[2][m] = 0; /* XYY */
		 m++;
		 l[0][m] = 2;l[1][m] = 1;l[2][m] = 0; /* XXY */
		 m++;
		 l[0][m] = 2;l[1][m] = 0;l[2][m] = 1; /* XXZ */
		 m++;
		 l[0][m] = 1;l[1][m] = 0;l[2][m] = 2; /* XZZ */
		 m++;
		 l[0][m] = 0;l[1][m] = 1;l[2][m] = 2; /* YZZ */
		 m++;
		 l[0][m] = 0;l[1][m] = 2;l[2][m] = 1; /* YYZ */
		 m++;
		 l[0][m] = 1;l[1][m] = 1;l[2][m] = 1; /* XYZ */
		 break;
	  default :
		m=0;
		for(l3=Type[GeomOrb[i].NumType].Ao[j].L;l3>=0;l3--)
			for(l2=Type[GeomOrb[i].NumType].Ao[j].L-l3;l2>=0;l2--)
		{
	 		l1 = Type[GeomOrb[i].NumType].Ao[j].L-l2-l3;
			l[0][m] = l1;
			l[1][m] = l2;
			l[2][m] = l3;
			m++;
		}
	}
		for(m=0;m<(L+1)*(L+2)/2;m++)
 		{
			l1 = l[0][m];
			l2 = l[1][m];
	 		l3 = l[2][m];
	 		k++;
	 		AOrb[k].N=Type[GeomOrb[i].NumType].Ao[j].N;
			AOrb[k].NumCenter = i;
	 		AOrb[k].Gtf =g_malloc(AOrb[k].N*sizeof(GTF));
	 		for(n=0;n<AOrb[k].N;n++)
	 		{
	   			AOrb[k].Gtf[n].Ex   = Type[GeomOrb[i].NumType].Ao[j].Ex[n];
	   			AOrb[k].Gtf[n].Coef = Type[GeomOrb[i].NumType].Ao[j].Coef[n];
	   			AOrb[k].Gtf[n].C[0] = GeomOrb[i].C[0];
	   			AOrb[k].Gtf[n].C[1] = GeomOrb[i].C[1];
	   			AOrb[k].Gtf[n].C[2] = GeomOrb[i].C[2];
	   			AOrb[k].Gtf[n].l[0] = l1;
	   			AOrb[k].Gtf[n].l[1] = l2;
	   			AOrb[k].Gtf[n].l[2] = l3;
	 		}
	 
 		}
}

NOrb = NAOrb;
DefineAtomicNumOrb();
/* DefineNorb();*/
}
/**********************************************/
void DefineSphericalBasis()
{
 gint i,j,k;
 gint c;
 gint kl;
 gint L,M;
 CGTF *temp;
 Slm Stemp;
 gint N,Nc,n;
 gint inc;
 gint  klbeg;
 gint  klend;
 gint  klinc;


 NOrb = 0;
 for(i=0;i<Ncenters;i++)
 {
	 for(j=0;j<Type[GeomOrb[i].NumType].Norb;j++)
	 {
		L=Type[GeomOrb[i].NumType].Ao[j].L;
		NOrb += 2*L+1;
	 }
 }

 temp  = g_malloc(NOrb*sizeof(CGTF));

 k=-1;
 for(i=0;i<Ncenters;i++)
	 for(j=0;j<Type[GeomOrb[i].NumType].Norb;j++)
	{
	 	L =Type[GeomOrb[i].NumType].Ao[j].L;
		/*Debug("L=%d \n",L);*/

		/*Debug("L =%d \n",L);*/
		if(L==1)
		{
                	klbeg = L;
                	klend = 0;
                	klinc = -1;
		}
		else
		{
                	klbeg = 0;
                	klend = L;
                	klinc = +1;
		}
		for(kl = klbeg;(klbeg == 0 && kl<=klend) || (klbeg == L && kl>=klend);kl +=klinc)
		{
		if(kl!=0)
		    inc = 2*kl;	
		else
		    inc = 1;
		for(M=kl;M>=-kl;M -=inc)
    		{
			/*Debug("L =%d kl=%d M=%d \n",L,kl,M);*/
	 		k++;
	 	   	Stemp =  GetCoefSlm(L,M);

	 		temp[k].N=Stemp.N*Type[GeomOrb[i].NumType].Ao[j].N;
		    temp[k].NumCenter=i;
			/*Debug("M=%d N=%d\n",M,temp[k].N);*/
	 		temp[k].Gtf =g_malloc(temp[k].N*sizeof(GTF));
          		Nc=-1;
	 		for(N=0;N<Type[GeomOrb[i].NumType].Ao[j].N;N++)
	 			 for(n=0;n<Stemp.N;n++)
	 			{
	 			   Nc++;
	 			
	   				temp[k].Gtf[Nc].Ex   = Type[GeomOrb[i].NumType].Ao[j].Ex[N];
	   				temp[k].Gtf[Nc].Coef = Type[GeomOrb[i].NumType].Ao[j].Coef[N]*Stemp.lxyz[n].Coef;
	   				for(c=0;c<3;c++)
	   				{
	   					temp[k].Gtf[Nc].C[c] = GeomOrb[i].C[c];
	   					temp[k].Gtf[Nc].l[c] = Stemp.lxyz[n].l[c];
	   				}
	 			}
		if(L==0)
		  break;
	      }
		if(L==0)
		  break;
	      }
	}
	 for(i=0;i<NAOrb;i++)
		g_free(AOrb[i].Gtf);
g_free(AOrb);
NAOrb = NOrb;
AOrb = temp;
 if(SAOrb) g_free(SAOrb);
 SAOrb = NULL;
DefineAtomicNumOrb();
/* DefineNorb();*/
}


