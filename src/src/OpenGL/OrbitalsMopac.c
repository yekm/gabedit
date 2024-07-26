/* OrbitalsMopac.c */
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
#include "../Utils/AtomsProp.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Utils.h"
#include "../Utils/Constants.h"
#include "../Geometry/GeomGlobal.h"
#include "GeomDraw.h"
#include "GLArea.h"
#include "UtilsOrb.h"
#include "Basis.h"
#include "GeomOrbXYZ.h"
#include "AtomicOrbitals.h"
#include "StatusOrb.h"
#include "Basis.h"
#include "Orbitals.h"
#include "GeomOrbXYZ.h"
#include "BondsOrb.h"

/********************************************************************************/
static gboolean read_geomorb_mopac_file_geom(gchar *fileName)
{
	return gl_read_mopac_aux_file_geomi(fileName, -1);
}
/********************************************************************************/
static void DefineMopacSphericalBasis(gchar** strbasis, gint* nums, gint* pqn, gdouble*zetas, gint nrows)
{
 gint i,k;
 gint c;
 CSTF *temp;
 Slm Stemp;
 gint n;

 NOrb = nrows;

 temp  = g_malloc(NOrb*sizeof(CSTF));
 for(k=0;k<nrows;k++)
 {
	i = nums[k]-1;
	Stemp =  GetCoefSlm(0,0);
	if(!strcmp(strbasis[k],"S")) Stemp =  GetCoefSlm(0,0);
	else if(!strcmp(strbasis[k],"PZ")) Stemp =  GetCoefSlm(1,0);
	else if(!strcmp(strbasis[k],"PX")) Stemp =  GetCoefSlm(1,1);
	else if(!strcmp(strbasis[k],"PY")) Stemp =  GetCoefSlm(1,-1);
	else if(!strcmp(strbasis[k],"Z2")) Stemp =  GetCoefSlm(2,0);
	else if(!strcmp(strbasis[k],"XZ")) Stemp =  GetCoefSlm(2,1);
	else if(!strcmp(strbasis[k],"YZ")) Stemp =  GetCoefSlm(2,-1);
	else if(!strcmp(strbasis[k],"X2")) Stemp =  GetCoefSlm(2,2);
	else if(!strcmp(strbasis[k],"XY")) Stemp =  GetCoefSlm(2,-2);
	else if(!strcmp(strbasis[k],"Z3")) Stemp =  GetCoefSlm(3,0);
	else if(!strcmp(strbasis[k],"XZ2")) Stemp =  GetCoefSlm(3,1);
	else if(!strcmp(strbasis[k],"YZ2")) Stemp =  GetCoefSlm(3,-1);
	else if(!strcmp(strbasis[k],"ZX2")) Stemp =  GetCoefSlm(3,2);
	else if(!strcmp(strbasis[k],"XYZ")) Stemp =  GetCoefSlm(3,-2);
	else if(!strcmp(strbasis[k],"X3")) Stemp =  GetCoefSlm(3,3);
	else if(!strcmp(strbasis[k],"Y3")) Stemp =  GetCoefSlm(3,-3);

	temp[k].N=Stemp.N;
	temp[k].NumCenter=i;
	temp[k].Stf =g_malloc(temp[k].N*sizeof(STF));
	for(n=0;n<Stemp.N;n++)
	{
		temp[k].Stf[n].pqn   = pqn[k];
		temp[k].Stf[n].Ex   = zetas[k];
	   	temp[k].Stf[n].Coef = Stemp.lxyz[n].Coef;
		/* printf("Coef Sph = %f l=%d %d %d\n", temp[k].Stf[n].Coef,Stemp.lxyz[n].l[0],Stemp.lxyz[n].l[1],Stemp.lxyz[n].l[2]);*/
	   	temp[k].Stf[n].Coef *= pow(2*zetas[k],pqn[k]+0.5)/sqrt(fact[2*pqn[k]]);
	   	for(c=0;c<3;c++)
	   	{
	   		temp[k].Stf[n].C[c] = GeomOrb[i].C[c];
	   		temp[k].Stf[n].l[c] = Stemp.lxyz[n].l[c];
	   	}
	 }
 }
 NAOrb = NOrb;
 SAOrb = temp;
 if(AOrb) g_free(AOrb);
 AOrb = NULL;
 DefineAtomicNumOrb();
}
/********************************************************************************/
static gdouble* read_basis_zeta_from_a_mopac_output_file(gchar *FileName, gint* nrs)
{
 	gchar **str;
 	FILE *file;
	gdouble *zetas = NULL;
	gint i;
	
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry No file slected\n","Error",TRUE);
    		return NULL;
 	}

 	file = FOpen(FileName, "rb");
 	if(file ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
  		return NULL;
 	}
	str = get_one_block_from_aux_mopac_file(file, "AO_ZETA[",  nrs);
	fclose(file);
	if(!str) return NULL;

	zetas = g_malloc((*nrs)*sizeof(gdouble));
	for(i=0;i<*nrs;i++)
	{
		/*zetas[i] = atof(str[i])*ANG_TO_BOHR;*/
		zetas[i] = atof(str[i]);
	}
	free_one_string_table(str,*nrs);

	return zetas;
}
/********************************************************************************/
static gdouble* read_overlap_matrix_from_a_mopac_output_file(gchar *FileName, gint* nrs)
{
 	gchar **str;
 	FILE *file;
	gdouble *overlapMatrix = NULL;
	gint i;
	
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry No file slected\n","Error",TRUE);
    		return NULL;
 	}

 	file = FOpen(FileName, "rb");
 	if(file ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
  		return NULL;
 	}
	str = get_one_block_from_aux_mopac_file(file, "OVERLAP_MATRIX[",  nrs);
	fclose(file);
	if(!str) return NULL;

	overlapMatrix = g_malloc((*nrs)*sizeof(gdouble));
	for(i=0;i<*nrs;i++)
	{
		overlapMatrix[i] = atof(str[i]);
	}
	free_one_string_table(str,*nrs);

	return overlapMatrix;
}
/********************************************************************************/
static gint* read_basis_atompqn_from_a_mopac_output_file(gchar *FileName, gint* nrs)
{
 	gchar **str;
 	FILE *file;
	gint *pqn = NULL;
	gint i;
	
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry No file slected\n","Error",TRUE);
    		return NULL;
 	}

 	file = FOpen(FileName, "rb");
 	if(file ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
  		return NULL;
 	}
	str = get_one_block_from_aux_mopac_file(file, "ATOM_PQN[",  nrs);
	fclose(file);
	if(!str) return NULL;

	pqn = g_malloc((*nrs)*sizeof(gint));
	for(i=0;i<*nrs;i++)
	{
		pqn[i] = atoi(str[i]);
		/* printf("n=%d\n",pqn[i]);*/
	}
	free_one_string_table(str,*nrs);

	return pqn;
}
/********************************************************************************/
static gint* read_basis_atomnums_from_a_mopac_output_file(gchar *FileName, gint* nrs)
{
 	gchar **str;
 	FILE *file;
	gint *nums = NULL;
	gint i;
	
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry No file slected\n","Error",TRUE);
    		return NULL;
 	}

 	file = FOpen(FileName, "rb");
 	if(file ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
  		return NULL;
 	}
	str = get_one_block_from_aux_mopac_file(file, "AO_ATOMINDEX[",  nrs);
	fclose(file);
	if(!str) return NULL;

	nums = g_malloc((*nrs)*sizeof(gint));
	for(i=0;i<*nrs;i++)
	{
		nums[i] = atoi(str[i]);
	}
	free_one_string_table(str,*nrs);

	return nums;
}
/********************************************************************************/
static gchar** read_basis_types_from_a_mopac_output_file(gchar *FileName, gint* nrs)
{
 	gchar **strbasis;
 	FILE *file;
	
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry No file slected\n","Error",TRUE);
    		return NULL;
 	}

 	file = FOpen(FileName, "rb");
 	if(file ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
  		return NULL;
 	}
	strbasis = get_one_block_from_aux_mopac_file(file, "ATOM_SYMTYPE[",  nrs);
	fclose(file);
	return strbasis;
}
/********************************************************************************/
static gboolean set_sym_orbitals(gchar* FileName)
{
 	FILE *file;
	gchar**  strAlpha = NULL;
	gchar**  strBeta = NULL;
	gchar**  str = NULL;
	gint nAlpha = 0;
	gint nBeta = 0;
	gint n = 0;
	gint i;

 	file = FOpen(FileName, "rb");
 	if(file ==NULL) return FALSE;

	strAlpha = get_one_block_from_aux_mopac_file(file, "ALPHA_M.O.SYMMETRY_LABELS[",  &nAlpha);
	if(strAlpha)
	{
		fseek(file, 0L, SEEK_SET);
		strBeta = get_one_block_from_aux_mopac_file(file, "BETA_M.O.SYMMETRY_LABELS[",  &nBeta);
	}
	else 
	{
		fseek(file, 0L, SEEK_SET);
		str = get_one_block_from_aux_mopac_file(file, "M.O.SYMMETRY_LABELS[",  &n);
	}
	if(n>0)
	{
		SymAlphaOrbitals = g_malloc(NOrb*sizeof(gchar*));
		for(i=0;i<NOrb;i++) SymAlphaOrbitals[i] = g_strdup(str[i]);
		SymBetaOrbitals = SymAlphaOrbitals;
	}
	if(nAlpha>0 && nAlpha==nBeta)
	{
		SymAlphaOrbitals = g_malloc(NOrb*sizeof(gchar*));
		for(i=0;i<NOrb;i++) SymAlphaOrbitals[i] = g_strdup(strAlpha[i]);
		SymBetaOrbitals = g_malloc(NOrb*sizeof(gchar*));
		for(i=0;i<NOrb;i++) SymBetaOrbitals[i] = g_strdup(strBeta[i]);
	}

	if(file) fclose(file);
	free_one_string_table(strAlpha, nAlpha);
	free_one_string_table(strBeta, nBeta);
	free_one_string_table(str, n);
	if(n>0 || (nAlpha>0 && nAlpha==nBeta)) return TRUE;
	else 
	{
		SymAlphaOrbitals = g_malloc(NOrb*sizeof(gchar*));
		for(i=0;i<NOrb;i++) SymAlphaOrbitals[i] = g_strdup("UNK");
		SymBetaOrbitals = SymAlphaOrbitals;
		return TRUE;
	}
}
/********************************************************************************/
static gboolean set_ener_orbitals(gchar* FileName)
{
 	FILE *file;
	gchar**  strAlpha = NULL;
	gchar**  strBeta = NULL;
	gchar**  str = NULL;
	gint nAlpha = 0;
	gint nBeta = 0;
	gint n = 0;
	gint i;

 	file = FOpen(FileName, "rb");
 	if(file ==NULL) return FALSE;

	strAlpha = get_one_block_from_aux_mopac_file(file, "ALPHA_EIGENVALUES[",  &nAlpha);
	if(strAlpha)
	{
		fseek(file, 0L, SEEK_SET);
		strBeta = get_one_block_from_aux_mopac_file(file, "BETA_EIGENVALUES[",  &nBeta);
	}
	else 
	{
		fseek(file, 0L, SEEK_SET);
		str = get_one_block_from_aux_mopac_file(file, "EIGENVALUES[",  &n);
	}
	if(n>0)
	{
		EnerAlphaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		EnerBetaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		for(i=0;i<NOrb;i++) EnerAlphaOrbitals[i] = atof(str[i]);
		for(i=0;i<NOrb;i++) EnerBetaOrbitals[i] = atof(str[i]);
	}
	if(nAlpha>0)
	{
		EnerAlphaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		for(i=0;i<NOrb;i++) EnerAlphaOrbitals[i] = atof(strAlpha[i]);
	}
	if(nBeta>0)
	{
		EnerBetaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		for(i=0;i<NOrb;i++) EnerBetaOrbitals[i] = atof(strBeta[i]);
	}

	if(file) fclose(file);
	free_one_string_table(strAlpha, nAlpha);
	free_one_string_table(strBeta, nBeta);
	free_one_string_table(str, n);
	if(n>0 || (nAlpha>0 && nAlpha==nBeta)) return TRUE;
	else return FALSE;
}
/********************************************************************************/
static gboolean normalize_orbitals(gchar* FileName, gfloat**CoefOrbitals)
{
	gint nn;
	gint N = NOrb*(NOrb+1)/2;
	gdouble* S = read_overlap_matrix_from_a_mopac_output_file(FileName, &nn);
	gint i;
	gint k;
	gint l;
	/* printf("nn=%d N = %d\n",nn,N);*/
	if(nn != N) return FALSE;
	for(i=0;i<NOrb;i++) 
	{
		gdouble ovOM = 0;
		gint kk =0;
		for(k=0;k<NOrb;k++)
		{
			for(l=0;l<=k;l++)
			{
				if(l!=k)
					ovOM += 2*CoefOrbitals[i][k]*CoefOrbitals[i][l]*S[kk++];
				else
					ovOM += CoefOrbitals[i][k]*CoefOrbitals[i][l]*S[kk++];
			}
		}
		
		ovOM = 1.0/sqrt(ovOM+1e-20); 
		for(k=0;k<NOrb;k++)
			CoefOrbitals[i][k] *= ovOM;
	}
	return TRUE;
}
/********************************************************************************/
static gboolean set_occ_orbitals(gchar* FileName)
{
 	FILE *file;
	gchar**  strAlpha = NULL;
	gchar**  strBeta = NULL;
	gchar**  str = NULL;
	gint nAlpha = 0;
	gint nBeta = 0;
	gint n = 0;
	gint i;

 	file = FOpen(FileName, "rb");
 	if(file ==NULL) return FALSE;

	strAlpha = get_one_block_from_aux_mopac_file(file, "ALPHA_MOLECULAR_ORBITAL_OCCUPANCIES[",  &nAlpha);
	if(strAlpha)
	{
		fseek(file, 0L, SEEK_SET);
		strBeta = get_one_block_from_aux_mopac_file(file, "BETA_MOLECULAR_ORBITAL_OCCUPANCIES[",  &nBeta);
	}
	else 
	{
		fseek(file, 0L, SEEK_SET);
		str = get_one_block_from_aux_mopac_file(file, "MOLECULAR_ORBITAL_OCCUPANCIES[",  &n);
	}
	if(n>0)
	{
		OccAlphaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		OccBetaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		for(i=0;i<NOrb;i++) OccAlphaOrbitals[i] = atof(str[i]);
		for(i=0;i<NOrb;i++) if(OccAlphaOrbitals[i]>=2) OccAlphaOrbitals[i] = 1;
		for(i=0;i<NOrb;i++) OccBetaOrbitals[i] = atof(str[i]);
		for(i=0;i<NOrb;i++) if(OccBetaOrbitals[i]>=2) OccBetaOrbitals[i] -= 1;
	}
	if(nAlpha>0 && nAlpha==nBeta)
	{
		OccAlphaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		for(i=0;i<NOrb;i++) OccAlphaOrbitals[i] = atof(strAlpha[i]);
		OccBetaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		for(i=0;i<NOrb;i++) OccBetaOrbitals[i] = atof(strBeta[i]);
	}

	fclose(file);
	free_one_string_table(strAlpha, nAlpha);
	free_one_string_table(strBeta, nBeta);
	free_one_string_table(str, n);
	if(n>0 || (nAlpha>0 && nAlpha==nBeta)) return TRUE;
	else return FALSE;
}
/********************************************************************************/
static gboolean set_coef_orbitals(gchar* FileName)
{
 	FILE *file;
	gchar**  strAlpha = NULL;
	gchar**  strBeta = NULL;
	gchar**  str = NULL;
	gint nAlpha = 0;
	gint nBeta = 0;
	gint n = 0;
	gint i,j,k;

 	file = FOpen(FileName, "rb");
 	if(file ==NULL) return FALSE;

	strAlpha = get_one_block_from_aux_mopac_file(file, "ALPHA_EIGENVECTORS[",  &nAlpha);
	if(strAlpha)
	{
		fseek(file, 0L, SEEK_SET);
		strBeta = get_one_block_from_aux_mopac_file(file, "BETA_EIGENVECTORS[",  &nBeta);
	}
	else 
	{
		fseek(file, 0L, SEEK_SET);
		str = get_one_block_from_aux_mopac_file(file, "EIGENVECTORS[",  &n);
	}
	if(n>0)
	{
		CoefAlphaOrbitals = CreateTable2(NOrb);
		CoefBetaOrbitals = CoefAlphaOrbitals;
		k = 0;
		for(i=0;i<NOrb;i++) 
			for(j=0;j<NOrb;j++)
				CoefAlphaOrbitals[i][j]=atof(str[k++]);
		normalize_orbitals(FileName, CoefAlphaOrbitals);
	}
	if(nAlpha>0 && nAlpha==nBeta)
	{
		CoefAlphaOrbitals = CreateTable2(NOrb);
		CoefBetaOrbitals = CreateTable2(NOrb);
		k = 0;
		for(i=0;i<NOrb;i++) 
			for(j=0;j<NOrb;j++)
			{
				CoefAlphaOrbitals[i][j]=atof(strAlpha[k]);
				CoefBetaOrbitals[i][j]=atof(strBeta[k++]);
			}
		normalize_orbitals(FileName, CoefAlphaOrbitals);
		normalize_orbitals(FileName, CoefBetaOrbitals);
	}
	if(file) fclose(file);
	free_one_string_table(strAlpha, nAlpha);
	free_one_string_table(strBeta, nBeta);
	free_one_string_table(str, n);
	if(n>0 || (nAlpha>0 && nAlpha==nBeta)) return TRUE;
	else return FALSE;
}
/********************************************************************************/
static gboolean set_ener_orbitals_localized(gchar* FileName)
{
 	FILE *file;
	gchar**  strAlpha = NULL;
	gchar**  strBeta = NULL;
	gchar**  str = NULL;
	gint nAlpha = 0;
	gint nBeta = 0;
	gint n = 0;
	gint i;

 	file = FOpen(FileName, "rb");
 	if(file ==NULL) return FALSE;

	strAlpha = get_one_block_from_aux_mopac_file(file, "ALPHA_LMO_E[",  &nAlpha);
	if(strAlpha)
	{
		fseek(file, 0L, SEEK_SET);
		strBeta = get_one_block_from_aux_mopac_file(file, "BETA_LMO_E[",  &nBeta);
	}
	else 
	{
		fseek(file, 0L, SEEK_SET);
		str = get_one_block_from_aux_mopac_file(file, "LMO_E[",  &n);
	}
	if(n>0)
	{
		EnerAlphaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		EnerBetaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		for(i=0;i<n;i++) EnerAlphaOrbitals[i] = atof(str[i]);
		for(i=0;i<n;i++) EnerBetaOrbitals[i] = atof(str[i]);
		for(i=n;i<NOrb;i++) EnerAlphaOrbitals[i] = 0.0;
		for(i=n;i<NOrb;i++) EnerBetaOrbitals[i] = 0.0;

		if(SymAlphaOrbitals)
		{
			for(i=0;i<NOrb;i++) if(SymAlphaOrbitals[i]) g_free(SymAlphaOrbitals[i]);
			for(i=0;i<n;i++) SymAlphaOrbitals[i] = g_strdup("UNK");
			for(i=n;i<NOrb;i++) SymAlphaOrbitals[i] = g_strdup("DELETED");
		}
	}
	if(nAlpha>0)
	{
		EnerAlphaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		for(i=0;i<nAlpha;i++) EnerAlphaOrbitals[i] = atof(strAlpha[i]);
		for(i=nAlpha;i<NOrb;i++) EnerAlphaOrbitals[i] = 0.0;
		if(SymAlphaOrbitals)
		{
			for(i=0;i<NOrb;i++) if(SymAlphaOrbitals[i]) g_free(SymAlphaOrbitals[i]);
			for(i=0;i<nAlpha;i++) SymAlphaOrbitals[i] = g_strdup("UNK");
			for(i=nAlpha;i<NOrb;i++) SymAlphaOrbitals[i] = g_strdup("DELETED");
		}
	}
	if(nBeta>0)
	{
		EnerBetaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		for(i=0;i<nBeta;i++) EnerBetaOrbitals[i] = atof(strBeta[i]);
		for(i=nBeta;i<NOrb;i++) EnerBetaOrbitals[i] = 0.0;
		if(SymBetaOrbitals)
		{
			for(i=0;i<NOrb;i++) if(SymBetaOrbitals[i]) g_free(SymBetaOrbitals[i]);
			for(i=0;i<nBeta;i++) SymBetaOrbitals[i] = g_strdup("UNK");
			for(i=nBeta;i<NOrb;i++) SymBetaOrbitals[i] = g_strdup("DELETED");
		}
	}

	if(file) fclose(file);
	free_one_string_table(strAlpha, nAlpha);
	free_one_string_table(strBeta, nBeta);
	free_one_string_table(str, n);
	if(n>0 || (nAlpha>0 && nAlpha==nBeta)) return TRUE;
	else return FALSE;
}
/********************************************************************************/
static gboolean set_coef_orbitals_localized(gchar* FileName)
{
 	FILE *file;
	gchar**  strAlpha = NULL;
	gchar**  strBeta = NULL;
	gchar**  str = NULL;
	gint nAlpha = 0;
	gint nBeta = 0;
	gint n = 0;
	gint i,j,k;

 	file = FOpen(FileName, "rb");
 	if(file ==NULL) return FALSE;

	strAlpha = get_one_block_from_aux_mopac_file(file, "ALPHA_LMO_MO[",  &nAlpha);
	if(strAlpha)
	{
		fseek(file, 0L, SEEK_SET);
		strBeta = get_one_block_from_aux_mopac_file(file, "BETA_LMO_MO[",  &nBeta);
	}
	else 
	{
		fseek(file, 0L, SEEK_SET);
		str = get_one_block_from_aux_mopac_file(file, "LMO_MO[",  &n);
	}
	if(n>0)
	{
		gint no = n/NOrb;
		gint nMax = (no>NOrb)?no:NOrb;
		CoefAlphaOrbitals = CreateTable2(nMax);
		CoefBetaOrbitals = CoefAlphaOrbitals;
		k = 0;
		for(i=0;i<no;i++) 
			for(j=0;j<NOrb;j++)
				CoefAlphaOrbitals[i][j]=atof(str[k++]);
		for(i=no;i<NOrb;i++) 
			for(j=0;j<NOrb;j++)
			{
				CoefAlphaOrbitals[i][j]=0;
				CoefBetaOrbitals[i][j]=0;
			}
		normalize_orbitals(FileName, CoefAlphaOrbitals);
	}
	if(nAlpha>0 && nAlpha==nBeta)
	{
		gint no = nAlpha/NOrb;
		gint nMax = (no>NOrb)?no:NOrb;
		CoefAlphaOrbitals = CreateTable2(nMax);
		CoefBetaOrbitals = CreateTable2(nMax);
		k = 0;
		for(i=0;i<no;i++) 
			for(j=0;j<NOrb;j++)
			{
				CoefAlphaOrbitals[i][j]=atof(strAlpha[k]);
				CoefBetaOrbitals[i][j]=atof(strBeta[k++]);
			}
		for(i=no;i<NOrb;i++) 
			for(j=0;j<NOrb;j++)
			{
				CoefAlphaOrbitals[i][j]=0;
				CoefBetaOrbitals[i][j]=0;
			}
		normalize_orbitals(FileName, CoefAlphaOrbitals);
		normalize_orbitals(FileName, CoefBetaOrbitals);
	}
	if(file) fclose(file);
	free_one_string_table(strAlpha, nAlpha);
	free_one_string_table(strBeta, nBeta);
	free_one_string_table(str, n);
	if(n>0 || (nAlpha>0 && nAlpha==nBeta)) return TRUE;
	else return FALSE;
}
/********************************************************************************/
void read_mopac_orbitals(gchar* FileName)
{
	gint typefile;
	/* gint typebasis=1;*/ /* Mopac print OM in cartezian presentation even ISPHER=0 or 1 or -1 */
	gchar *t = NULL;
	gint nrs;
	gchar** strbasis=NULL;
	gint i;
	gboolean Ok;
	gdouble* zetas = NULL;
	gint* nums = NULL;
	gint* pqn = NULL;
	gint nNums = 0;
	gint nZetas = 0;
	gint nPqn = 0;


	typefile =get_type_file(FileName);
	if(typefile==GABEDIT_TYPEFILE_UNKNOWN) return;


	if(typefile != GABEDIT_TYPEFILE_MOPAC_AUX)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not read this format from '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return ;
	}

	free_data_all();
	t = get_name_file(FileName);
	set_status_label_info("File Name",t);
	g_free(t);
	set_status_label_info("File Type","Mopac");
	set_status_label_info("Mol. Orb.","Reading");
	
	free_orbitals();	

 	Ok = read_geomorb_mopac_file_geom(FileName);
 	if(!Ok)
	{
		free_geometry();
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
		return;
	}
	strbasis=read_basis_types_from_a_mopac_output_file(FileName, &nrs);
	zetas = read_basis_zeta_from_a_mopac_output_file(FileName, &nZetas);
	nums = read_basis_atomnums_from_a_mopac_output_file(FileName, &nNums);
	pqn = read_basis_atompqn_from_a_mopac_output_file(FileName, &nPqn);
	if(!strbasis || !zetas || !nums || nrs<1 || nZetas<1 || nNums<1  || nPqn<1 || nrs!= nZetas || nrs!=nNums || nrs !=nPqn)
	{
		if(GeomOrb)
		{
			init_atomic_orbitals();
			for(i=0;i<Ncenters;i++) GeomOrb[i].Prop = prop_atom_get("H");
			free_geometry();
		}
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
		free_one_string_table(strbasis,nrs);
		if(nums) g_free(nums);
		if(zetas) g_free(zetas);
		if(pqn) g_free(pqn);
		return;
	}

	set_status_label_info("Mol. Orb.","Reading");
 	InitializeAll();
	buildBondsOrb();
	RebuildGeom = TRUE;
	reset_grid_limits();
	init_atomic_orbitals();
	set_status_label_info("Geometry","Ok");
	glarea_rafresh(GLArea); /* for geometry*/


 	DefineMopacSphericalBasis(strbasis, nums, pqn, zetas, nrs);
	free_one_string_table(strbasis,nrs);
	if(nums) g_free(nums);
	if(zetas) g_free(zetas);
	if(pqn) g_free(pqn);

 	
 	/* PrintAllBasis();*/

	Ok = set_occ_orbitals(FileName);
	/* printf("OK occ = %d\n",Ok);*/
	if(Ok) Ok = set_sym_orbitals(FileName);
	if(Ok) 
	{
		Ok = set_ener_orbitals_localized(FileName);
		if(Ok) Ok = set_coef_orbitals_localized(FileName);
		else
		{
			Ok = set_ener_orbitals(FileName);
			if(Ok) Ok = set_coef_orbitals(FileName);
		}
	}

	if(Ok)
	{
		/*PrintAllOrb(CoefAlphaOrbitals);*/
		set_status_label_info("Mol. Orb.","Ok");
		glarea_rafresh(GLArea); /* for geometry*/
		NumSelOrb = 0;
		for(i=0;i<NOrb;i++) 
		if(OccAlphaOrbitals[i]<0.1) 
		{
			if(i<1)NumSelOrb = 0;
			else NumSelOrb = i-1;
			break;
		}
  		NAlphaOrb =NOrb;
  		NBetaOrb =NOrb;
  		NAlphaOcc =NOrb;
		NBetaOcc = NOrb;
		NTotOcc = NOrb;
		TypeSelOrb = 1;
		create_list_orbitals();
	}
	else
	{
		free_orbitals();	
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
	}

} 
