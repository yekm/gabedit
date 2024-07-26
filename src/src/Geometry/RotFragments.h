
#ifndef __GABEDIT_ROTFRAGMENTS_H__
#define __GABEDIT_ROTFRAGMENTS_H__

gdouble TorsionToAtoms(gdouble*C4,gdouble*C1,gdouble* C2,gdouble* C3);
void SetBondDistance(GeomDef* geom,gint n1,gint n2,gfloat bondLength,gint list[],gint nlist);
void setAngle(gint closeatom,gint ToBond,gint Natoms,GeomDef *geometry,gint NatomsToRot,gint* atomlist,gdouble Angle);
void SetTorsion(gint Natoms,GeomDef *geometry, gint a1num, gint a2num, gint a3num, gint a4num, gdouble torsion,gint atomList[], gint numberOfElements );
void SetAngle(gint Natoms,GeomDef *geometry, gint a1num, gint a2num, gint a3num, gdouble angle,gint atomList[], gint numberOfElements );

#endif /* __GABEDIT_ROTFRAGMENTS_H__ */

