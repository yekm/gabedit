#ifndef __GABEDIT_ZLMMG_H__
#define __GABEDIT_ZLMMG_H__
typedef struct _LXYZMG LXYZMG;
struct _LXYZMG
{
	gdouble Coef;
	gint l[3];
};

typedef struct _ZlmMG ZlmMG;
struct _ZlmMG
{
	gint l;
	gint m;
	gint numberOfCoefficients;
	LXYZMG* lxyz;
};

ZlmMG getZlmMG(int , int);
void destroyZlmMG(ZlmMG*);
void copyZlmMG(ZlmMG*, ZlmMG*);
gdouble getValueZlmMG(ZlmMG*, gdouble, gdouble, gdouble);
void printfZlmMG(ZlmMG*);

#endif /* __GABEDIT_ZLMMG_H__ */
