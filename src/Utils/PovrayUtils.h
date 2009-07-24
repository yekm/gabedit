
#ifndef __GABEDIT_POVRAYUTILS_H__
#define __GABEDIT_POVRAYUTILS_H__

void createPOVBackgroundFrame(GtkWidget *box);
void applyPovrayOptions(GtkWidget *win, gpointer data);
void createPovrayOptionsWindow(GtkWidget* win);
gchar *get_pov_background(gfloat xScale, gfloat yScale, gfloat zScale);

#endif /* __GABEDIT_POVRAYUTILS_H__ */

