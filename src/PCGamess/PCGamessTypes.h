
#ifndef __GABEDIT_GAMESSTYPES_H__
#define __GABEDIT_GAMESSTYPES_H__

typedef struct _PCGamessColorBack
{
	GdkColor keyWord;
	GdkColor description;
}PCGamessColorBack;

typedef struct _PCGamessColorFore
{
	GdkColor keyWord;
	GdkColor description;
}PCGamessColorFore;

typedef struct _PCGamessAtom
{
	gdouble position[3];
	gchar* symbol;
}PCGamessAtom;

typedef struct _PCGamessMolecule
{
	gint numberOfAtoms;
	gint totalNumberOfElectrons;
	gint numberOfValenceElectrons;
	PCGamessAtom* listOfAtoms;
	gchar* groupSymmetry;
}PCGamessMolecule;

typedef struct _PCGamessBasis
{
	gchar* name;
	gchar* molecule;
	int numberOfBasisTypes;
	gchar** basisNames;
}PCGamessBasis;

typedef enum
{
 LSDAC = 0, PBEC, PW91C, P86C, NewP86C, VWN1LC, VWN1LCRPA, VWN2LC, VWN3LC, VWN4LC, VWN5LC, PW92LC, PZ81LC, LYPC,
 HFX, Xalpha, SlaterX, Becke88X, PBEX, PW86X, PW91X, mPW91_B88X, mPW91_PW91X,mPW91_mPW91X, G96X
} PCGamessFunctionalType;

typedef enum
{
 XALPHA = 0, HFS, HFB, HFG96, G96LYP, BLYP, SVWN1, SVWN1RPA, SVWN2, SVWN3, 
 SVWN4, SVWN5, SPZ81, SPW92, BPW91, BP86, B3LYP, B3PW91, B3P86, PBE, PW91,
 mPW_PW91_PW91, mPWPW91, mPW1PW91
} PCGamessStdFunctionalType;

typedef struct _PCGamessFunctional
{
	PCGamessFunctionalType type;
	gchar* name;
	gchar* comment;
}PCGamessFunctional;
typedef struct _PCGamessStdFunctional
{
	PCGamessStdFunctionalType type;
	gchar* name;
	gint n;
	PCGamessFunctionalType* listOfTypes;
	gfloat* coefficients;
}PCGamessStdFunctional;

#endif /* __GABEDIT_GAMESSTYPES_H__ */
