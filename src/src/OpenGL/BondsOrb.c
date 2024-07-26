/* BondsOrb.c */
/**********************************************************************************************************
Copyright (c) 2002-2007 Abdul-Rahman Allouche. All rights reserved

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
#include "BondsOrb.h"
#include "../Utils/Vector3d.h"
#include "../Utils/Transformation.h"
#include "../Utils/Utils.h"
#include "../Utils/Constantes.h"
#include "../Utils/HydrogenBond.h"

static gint *nBonds = NULL;
/************************************************************************/
static gboolean bonded(gint i,gint j)
{
	GLfloat distance;
	V3d dif;
	gint k;
	
	for(k=0;k<3;k++)
		dif[k] = (GeomOrb[i].C[k] - GeomOrb[j].C[k]);

	distance = v3d_length(dif);

	if(distance<(GeomOrb[i].Prop.covalentRadii + GeomOrb[j].Prop.covalentRadii))
		return TRUE;
	else 
		return FALSE;
}
/************************************************************************/
static gboolean hbonded(gint i,gint j)
{
	gfloat minDistanceH;
	gfloat maxDistanceH;
	gfloat minDistanceH2;
	gfloat maxDistanceH2;
	gfloat minAngleH;
	gfloat maxAngleH;
	gfloat distance2;
	gfloat angle;
	gchar* strAngle;
	Point A;
	Point B;
	gdouble dx, dy, dz;

	gint k;
	gint kH;
	gint kO;

	if(strcmp(GeomOrb[i].Symb,"H") == 0 )
	{
		kH = i;
		kO = j;
		if(!atomCanDoHydrogenBond(GeomOrb[j].Symb)) return FALSE;
	}
	else
	{
		if(strcmp(GeomOrb[j].Symb,"H") == 0 )
		{
			kH = j;
			kO = i;
			if(!atomCanDoHydrogenBond(GeomOrb[i].Symb)) return FALSE;
		}
		else return FALSE;
	}
	minDistanceH = getMinDistanceHBonds();
	minDistanceH2 = minDistanceH*minDistanceH*ANG_TO_BOHR*ANG_TO_BOHR;

	maxDistanceH = getMaxDistanceHBonds();
	maxDistanceH2 = maxDistanceH*maxDistanceH*ANG_TO_BOHR*ANG_TO_BOHR;

	minAngleH = getMinAngleHBonds();
	maxAngleH = getMaxAngleHBonds();

	dx = GeomOrb[i].C[0] - GeomOrb[j].C[0];
	dy = GeomOrb[i].C[1] - GeomOrb[j].C[1];
	dz = GeomOrb[i].C[2] - GeomOrb[j].C[2];
	distance2 = (dx*dx+dy*dy+dz*dz);
	if(distance2<minDistanceH2 || distance2>maxDistanceH2) return FALSE;

	for(k=0;k<Ncenters;k++)
	{
		if(k==kH) continue;
		if(k==kO) continue;
		/* angle kO, kH, connection to kH */
		if(!bonded(kH,k)) continue;
		A.C[0]=GeomOrb[kO].C[0]-GeomOrb[kH].C[0];
		A.C[1]=GeomOrb[kO].C[1]-GeomOrb[kH].C[1];
		A.C[2]=GeomOrb[kO].C[2]-GeomOrb[kH].C[2];

		B.C[0]=GeomOrb[k].C[0]-GeomOrb[kH].C[0];
		B.C[1]=GeomOrb[k].C[1]-GeomOrb[kH].C[1];
		B.C[2]=GeomOrb[k].C[2]-GeomOrb[kH].C[2];
        
        	strAngle = get_angle_vectors(A,B);
		angle = atof(strAngle);
		if(strAngle) g_free(strAngle);
		if(angle>=minAngleH &&angle<=maxAngleH) return TRUE;
	}
	return FALSE;
}
/************************************************************************/
void freeBondsOrb()
{
	GList* list;
	if(!BondsOrb) return;
	for(list=BondsOrb;list!=NULL;list=list->next)
	{
		if(list->data) g_free(list->data);
	}
	g_list_free(BondsOrb);
	BondsOrb = NULL;


}
/************************************************************************/
static void setMultipleBonds()
{
	GList* list;
	if(!BondsOrb) return;
	for(list=BondsOrb;list!=NULL;list=list->next)
	{
		BondType* data=(BondType*)list->data;
		gint i = data->n1;
		gint j = data->n2;
		if(data->bondType == GABEDIT_BONDTYPE_HYDROGEN) continue;
		if(
		 nBonds[i] < GeomOrb[i].Prop.maximumBondValence -1 &&
		 nBonds[j] < GeomOrb[j].Prop.maximumBondValence -1 
		)
		{
			data->bondType = GABEDIT_BONDTYPE_TRIPLE;
			nBonds[i] += 2;
			nBonds[j] += 2;
		}
		else
		if(
		 nBonds[i] < GeomOrb[i].Prop.maximumBondValence &&
		 nBonds[j] < GeomOrb[j].Prop.maximumBondValence 
		)
		{
			data->bondType = GABEDIT_BONDTYPE_DOUBLE;
			nBonds[i] += 1;
			nBonds[j] += 1;
		}
	}
}
/************************************************************************/
void buildBondsOrb()
{
	gint i;
	gint j;
	freeBondsOrb();
	if(Ncenters<1) return ;
	nBonds =g_malloc(Ncenters*sizeof(Ncenters));
	for(i = 0;i<Ncenters;i++) nBonds[i] = 0;
	for(i = 0;i<Ncenters;i++)
	{
		for(j=i+1;j<Ncenters;j++)
			if(bonded(i,j))
			{
				BondType* A=g_malloc(sizeof(BondType));
				A->n1 = i;
				A->n2 = j;
				nBonds[i]++;
				nBonds[j]++;
				A->bondType = GABEDIT_BONDTYPE_SINGLE;
				BondsOrb = g_list_append(BondsOrb,A);
			}
		        else
			if(ShowHBondOrb && hbonded(i,j))
			{
				BondType* A=g_malloc(sizeof(BondType));
				A->n1 = i;
				A->n2 = j;
				A->bondType = GABEDIT_BONDTYPE_HYDROGEN;
				BondsOrb = g_list_append(BondsOrb,A);
			}
	  }
	if(ShowMultiBondsOrb) setMultipleBonds();
	g_free(nBonds);
	nBonds = NULL;
}
/************************************************************************/
