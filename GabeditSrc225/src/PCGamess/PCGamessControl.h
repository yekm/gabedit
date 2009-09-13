#ifndef __GABEDIT_PCGAMESSCONTROL_H__
#define __GABEDIT_PCGAMESSCONTROL_H__

gboolean pcgamessSemiEmperical();
void putPCGamessControlInfoInTextEditor();
void createPCGamessControlFrame(GtkWidget *win, GtkWidget *box);
void setPCGamessSCFMethod(gboolean okRHF);
void setPCGamessTD(gboolean ok);

#endif /* __GABEDIT_PCGAMESSCONTROL_H__ */
