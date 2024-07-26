
#ifndef __GABEDIT_PDBTEMPLATE_H__
#define __GABEDIT_PDBTEMPLATE_H__

typedef struct _PDBTemplate  PDBTemplate;
typedef struct _PDBResidueTemplate  PDBResidueTemplate;
typedef struct _PDBTypeTemplate  PDBTypeTemplate;

/************************************/
struct _PDBTypeTemplate
{
	gchar* pdbType;
	gchar* mmType;
	gdouble charge;
};
/************************************/
struct _PDBResidueTemplate
{
	gchar* residueName;
	gint numberOfTypes;
	PDBTypeTemplate* typeTemplates;
};
/************************************/
struct _PDBTemplate
{
	gint numberOfResidues;
	PDBResidueTemplate* residueTemplates;
};
PDBTemplate* LoadPersonalPDBTpl();
PDBTemplate* LoadDefaultPDBTpl();
void LoadPDBTpl();
gchar* getMMTypeFromPDBTpl(gchar* residueName,gchar* pdbType,gdouble* charge);
PDBTemplate* getPointerPDBTemplate();
void setPointerPDBTemplate(PDBTemplate* ptr);
void savePersonalPDBTpl(GtkWidget* win);

#endif /* __GABEDIT_PDBTEMPLATE_H__ */

