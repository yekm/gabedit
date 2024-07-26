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

#ifndef __GABEDIT_UTILSORB_H__
#define __GABEDIT_UTILSORB_H__

void InitializeAll();
gfloat** CreateTable2(gint N);
gfloat** FreeTable2(gfloat **T,gint N);
gint GetTotalNelectrons();
void DefineNOccs();
gfloat Dpn(gfloat e,gint n);
Slm GetCoefSlm(gint l, gint m);
void printCoefSlm();
gdouble slmGetValue(Slm* slm, gdouble x, gdouble y, gdouble z);
char GetSymmetry(gint l);
gint GetNelectrons(char *symb);
void printLineChar(char c,gint n);
gint m1p(gint i);
gfloat Norme(GTF p);
gfloat dpn(gfloat e,gint n);
void Normalise(GTF* p);
void NormaliseRadial(GTF*p);
void NormaliseCGTF(CGTF*p);
void CalculFact();
void CalculFfact();
void CalculFF();
void CalculCIJ();
gfloat SpqSansNorm(GTF p,GTF q);
gfloat Spq(GTF p,GTF q);
gfloat **CalculSm12(gfloat *S,gint n,gint nvec);
gfloat** CreateTable2(gint N);
gfloat** FreeTable2(gfloat **T,gint N);
void PrintAllOrb(gfloat** M);
gint get_type_file(gchar *NomFichier);
gint get_type_basis_in_gamess_file(gchar *NomFichier);
gint get_type_basis_in_gaussian_file(gchar *NomFichier);
gint get_type_basis_in_qchem_file(gchar *NomFichier);
gint get_type_basis_in_gabedit_file(gchar *NomFichier);
gint get_type_basis_in_molden_file(gchar *NomFichier);
gboolean testi(char c);
gboolean this_is_a_real(gchar *t);
gboolean this_is_a_integer(gchar *t);
gboolean testapointeE(char c);
gboolean testpointeE(const gchar *t);
void free_data_all();
GtkWidget *create_grid_frame( GtkWidget *vboxall,gchar *title);
void create_grid(gchar* title);
void read_any_file(gchar* FileName);
gint get_number_of_point(GtkWidget* Entry);
gboolean get_a_float(GtkWidget* Entry,gfloat* value, gchar* erroMessage);
void initialise_global_orbitals_variables();
void close_window_orb(GtkWidget*win, gpointer data);
gboolean to_cgtf_is_id(CGTF t1,CGTF t2);
void add_glarea_child(GtkWidget* winchild,gchar* title);
void create_color_surfaces_file();
void read_color_surfaces_file();
void create_opengl_file();
void read_opengl_file();
void create_grid_sas(gchar* title);

#endif /* __GABEDIT_UTILSORB_H__ */

