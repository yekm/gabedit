/*********************************************************************************/
static void applyRattleFirstPortion(MolecularDynamics* semiEmpiricalMD)
{
	gint i;
	gint k;
	gint maxIter = 100;
	gdouble sor = 1.25; /* termination */
	gdouble tolerance = 1e-6; /* tolerance */
	gboolean done = FALSE;
	gint nIter = 0;
	gint a1 = 0;
	gint a2 = 0;
	gdouble r2ij;
	gdouble dot;
	gdouble rm1;
	gdouble rm2;
	gdouble delta;
	gdouble term = 0;
	gdouble terms[3];
	gdouble d;
	MoleculSEe* m = &semiEmpiricalMD->seModel->molecule;
	ForceField* seModel = semiEmpiricalMD->seModel;

	if(seModel->rattleConstraints==NOCONSTRAINTS) return;
	for (i = 0; i < semiEmpiricalMD->numberOfAtoms; i++)
	{
			semiEmpiricalMD->moved[i] = TRUE;
			semiEmpiricalMD->update[i] = FALSE;
	}
	do{
		nIter++;
		done=TRUE;
		for (i = 0; i < semiEmpiricalMD->seModel->numberOfRattleConstraintsTerms; i++)
		{
			a1 = (gint)semiEmpiricalMD->seModel->rattleConstraintsTerms[0][i];
			a2 = (gint)semiEmpiricalMD->seModel->rattleConstraintsTerms[1][i];
			if( !semiEmpiricalMD->moved[a1] && !semiEmpiricalMD->moved[a2] ) continue;
			r2ij = 0;
			for (k=0;k<3;k++)
			{
				d = m->atoms[a2].coordinates[k]-m->atoms[a1].coordinates[k];
				r2ij +=d*d;
			}
			delta = semiEmpiricalMD->seModel->rattleConstraintsTerms[2][i]-r2ij;
			if(fabs(delta)<=tolerance) continue;
			done = FALSE;
			semiEmpiricalMD->update[a1] = TRUE;
			semiEmpiricalMD->update[a2] = TRUE;
			/* here : rattle image for PBC, not yet implemented */
			dot = 0;
			for (k=0;k<3;k++)
			{
				d = m->atoms[a2].coordinates[k]-m->atoms[a1].coordinates[k];
				dot +=d*(semiEmpiricalMD->coordinatesOld[a2][k]-semiEmpiricalMD->coordinatesOld[a1][k]);
			}
			rm1 = 1/m->atoms[a1].prop.masse;
			rm2 = 1/m->atoms[a2].prop.masse;
		        term = sor*delta / (2.0*(rm1+rm2)*dot);
			for (k=0;k<3;k++)
			{
				terms[k] = (semiEmpiricalMD->coordinatesOld[a2][k]-semiEmpiricalMD->coordinatesOld[a1][k])*term;
			}
			for (k=0;k<3;k++) m->atoms[a1].coordinates[k] -= terms[k]*rm1;
			for (k=0;k<3;k++) m->atoms[a2].coordinates[k] += terms[k]*rm2;

			rm1 /= semiEmpiricalMD->dt;
			rm2 /= semiEmpiricalMD->dt;
			for (k=0;k<3;k++) semiEmpiricalMD->velocity[a1][k] -= terms[k]*rm1;
			for (k=0;k<3;k++) semiEmpiricalMD->velocity[a2][k] += terms[k]*rm2;
		}
		for (i = 0; i < semiEmpiricalMD->numberOfAtoms; i++)
		{
			semiEmpiricalMD->moved[i] = semiEmpiricalMD->update[i];
			semiEmpiricalMD->update[i] = FALSE;
		}
	}while(!done && nIter<maxIter);
	if(nIter>=maxIter)
	{
		printf("Rattle first portion : Warning, distance constraints not satisfied\n");
	}

}
/*********************************************************************************/
static void applyRattleSecondPortion(MolecularDynamics* semiEmpiricalMD)
{
	gint i;
	gint k;
	gint maxIter = 100;
	gdouble sor = 1.25; /* termination */
	gdouble tolerance = 1e-6; /* tolerance */
	gboolean done = FALSE;
	gint nIter = 0;
	gint a1 = 0;
	gint a2 = 0;
	gdouble r2ij;
	gdouble dot;
	gdouble rm1;
	gdouble rm2;
	gdouble term = 0;
	gdouble terms[3];
	gdouble d;
	MoleculeSE* m = &semiEmpiricalMD->seModel->molecule;
	ForceField* seModel = semiEmpiricalMD->seModel;

	if(seModel->constraints==NOCONSTRAINTS) return;
	tolerance /= semiEmpiricalMD->dt;
	for (i = 0; i < semiEmpiricalMD->numberOfAtoms; i++)
	{
			semiEmpiricalMD->moved[i] = TRUE;
			semiEmpiricalMD->update[i] = FALSE;
	}
	do{
		nIter++;
		done=TRUE;
		for (i = 0; i < semiEmpiricalMD->seModel->numberOfRattleConstraintsTerms; i++)
		{
			a1 = (gint)semiEmpiricalMD->seModel->rattleConstraintsTerms[0][i];
			a2 = (gint)semiEmpiricalMD->seModel->rattleConstraintsTerms[1][i];
			r2ij = (gint)semiEmpiricalMD->seModel->rattleConstraintsTerms[2][i];
			if( !semiEmpiricalMD->moved[a1] && !semiEmpiricalMD->moved[a2] ) continue;
			/* here : rattle image for PBC, not yet implemented */
			dot = 0;
			for (k=0;k<3;k++)
			{
				d = m->atoms[a2].coordinates[k]-m->atoms[a1].coordinates[k];
				dot +=d*(semiEmpiricalMD->velocity[a2][k]-semiEmpiricalMD->velocity[a1][k]);
			}
			rm1 = 1/semiEmpiricalMD->seModel->molecule.atoms[a1].prop.masse;
			rm2 = 1/semiEmpiricalMD->seModel->molecule.atoms[a2].prop.masse;
		        term = -dot / ((rm1+rm2)*r2ij);
			if(fabs(term)<=tolerance) continue;
			done = FALSE;
			semiEmpiricalMD->update[a1] = TRUE;
			semiEmpiricalMD->update[a2] = TRUE;
		        term *= sor;

			for (k=0;k<3;k++)
			{
				d = m->atoms[a2].coordinates[k]-m->atoms[a1].coordinates[k];
				terms[k] = d*term;
			}
			for (k=0;k<3;k++) semiEmpiricalMD->velocity[a1][k] -= terms[k]*rm1;
			for (k=0;k<3;k++) semiEmpiricalMD->velocity[a2][k] += terms[k]*rm2;
		}
		for (i = 0; i < semiEmpiricalMD->numberOfAtoms; i++)
		{
			semiEmpiricalMD->moved[i] = semiEmpiricalMD->update[i];
			semiEmpiricalMD->update[i] = FALSE;
		}
	}while(!done && nIter<maxIter);
	if(nIter>=maxIter)
	{
		printf("Rattle second portion : Warning, velocity constraints not satisfied\n");
	}
}
