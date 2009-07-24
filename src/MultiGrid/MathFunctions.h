#ifndef __GABEDIT_MATHFUNCS_H__
#define __GABEDIT_MATHFUNCS_H__
gdouble factorial(gint);
gdouble doubleFactorial(gint);
gdouble binomial(gint, gint);
gdouble fprod(gint, gint);
ZlmMG fZlmMG(gint, gint);
gdouble modifiedSphericalBessel(gint l, gdouble z);
void modifiedSphericalBessel0(gint l, gdouble z[], gdouble b[], gint n);
void destroyFactorial();
void destroyDoubleFactorial();
void destroyBinomial();
void destroyFprod();
void destroyZlmMGTable();
#endif /* __GABEDIT_MATHFUNCS_H__ */
