/*********************************************************************************/
static void applyRattleSecondPortion(MolecularDynamics* molecularDynamics)
{
	gint i;
	gint k;
	gint maxIter = 100;
	gdouble sor = 1.25; /* teemination */
	gdouble tolerance = 1.25; /* teemination */
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
	Molecule* m = &molecularDynamics->forceField->molecule;
	ForceField* forceField = molecularDynamics->forceField;
	gdouble vterm = 2;
	gdouble r2ij;

	if(!forceField->options.rattleConstraints) return;
	tolerance /= molecularDynamics->dt;
	vterm /= molecularDynamics->dt;
	for (i = 0; i < molecularDynamics->numberOfAtoms; i++)
	{
			molecularDynamics->moved[i] = TRUE;
			molecularDynamics->update[i] = TRUE;
	}
	do{
		for (i = 0; i < molecularDynamics->forceField->numberOfRattleConstraintsTerms; i++)
		{
			a1 = (gint)molecularDynamics->forceField->rattleConstraintsTerms[i][0];
			a2 = (gint)molecularDynamics->forceField->rattleConstraintsTerms[i][1];
			r2ij = (gint)molecularDynamics->forceField->rattleConstraintsTerms[i][2];
			if(
				!molecularDynamics->moved[a1] &&
				!molecularDynamics->moved[a2] 
			) continue;
			/* here : rattle image for PBC, not yet implemented */
			dot = 0;
			for (k=0;k<3;k++)
			{
				d = m->atoms[a2].coordinates[k]-m->atoms[a1].coordinates[k];
				dot +=d*(molecularDynamics->velocity[a2][k]-
				molecularDynamics->velocity[a1][k]);
			}
			rm1 = molecularDynamics->forceField->molecule.atoms[a1].prop.masse;
			rm2 = molecularDynamics->forceField->molecule.atoms[a2].prop.masse;
		        term = -dot / ((rm1+rm1)*r2ij);
			if(fabs(term)<=tolerance) continue;
			done = FALSE;
			molecularDynamics->update[a1] = TRUE;
			molecularDynamics->update[a2] = TRUE;
		        term *= sor;

			for (k=0;k<3;k++)
			{
				d = m->atoms[a2].coordinates[k]-m->atoms[a1].coordinates[k];
				terms[k] = d*term;
			}
			for (k=0;k<3;k++) molecularDynamics->velocity[a1][k] -= terms[k]*rm1;
			for (k=0;k<3;k++) molecularDynamics->velocity[a2][k] += terms[k]*rm2;
		}
		for (i = 0; i < molecularDynamics->numberOfAtoms; i++)
		{
			molecularDynamics->moved[i] = molecularDynamics->update[i];
			molecularDynamics->update[i] = FALSE;
		}
	}while(!done && nIter<maxIter);
}
