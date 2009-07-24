
#ifndef __GABEDIT_PCGAMESSMOLECULE_H__
#define __GABEDIT_PCGAMESSMOLECULE_H__

gint getPCGamessMultiplicity();
void initPCGamessMoleculeButtons();
void initPCGamessMolecule();
void freePCGamessMolecule();
void putPCGamessGeometryInfoInTextEditor();
gboolean setPCGamessMolecule();
void createPCGamessSymmetryFrame(GtkWidget *win, GtkWidget *box);
void createPCGamessChargeMultiplicityFrame(GtkWidget *box);
void putPCGamessChargeAndSpinInfoInTextEditor();

#endif /* __GABEDIT_PCGAMESSMOLECULE_H__ */

