static gchar selectedTypeBasis[BSIZE]="";
static gchar selectedBasis[BSIZE]="3-21G";
static gchar selectedBasisPolar[BSIZE]=" ";
static gchar selectedBasisDiffuse[BSIZE]=" ";
/*************************************************************************************************************/
static gchar* listTypeBasisView[] = 
{ 
	"Pople Style basis sets", 
	"Dunning basis sets", 
	"Ahlrichs basis sets", 
	"Def2 Ahlrichs basis sets", 
	"Jensen Basis Sets", 
	"Atomic Natural Orbital Basis Sets", 
	"Miscellenous and Specialized Basis Sets", 
};
static gchar* listTypeBasisReal[] = 
{ 
	"Pople", 
	"Dunning", 
	"Ahlrichs", 
	"Jensen", 
	"ANO", 
	"Miscellenous", 
};
static guint numberOfTypeBasis = G_N_ELEMENTS (listTypeBasisView);
/*************************************************************************************************************/
static gchar* listPopleBasisView[] = 
{ 
	"3-21G Pople 3-21G",
	"3-21GSP Buenker 3-21GSP",
	"4-22GSP Buenker 4-22GSP",
	"6-31G Pople 6-31G and its modifications",
	"6-311G Pople 6-311G and its modifications",

	"3-21+G  3-21G plus diffuse functions on all non-hydrogens atoms",
	"3-21+GSP 3-21GSP plus diffuse functions on all non-hydrogens atoms",
	"4-22+GSP 4-22GSP plus diffuse functions on all non-hydrogens atoms",
	"6-31+G 6-31G plus diffuse functions on all non-hydrogens atoms",
	"6-311+G 6-311G plus diffuse functions on all non-hydrogens atoms",

	"3-21++G  3-21G plus diffuse functions on all atoms",
	"3-21++GSP 3-21GSP plus diffuse functions on all atoms",
	"4-22++GSP 4-22GSP plus diffuse functions on all atoms",
	"6-31++G 6-31G plus diffuse functions on all atoms",
	"6-311++G 6-311G plus diffuse functions on all atoms",

	"3-21G*  3-21G plus one polarisation function all non-hydrogens atoms",
	"3-21GSP* 3-21GSP plus one polarisation function all non-hydrogens atoms",
	"4-22GSP* 4-22GSP plus one polarisation function all non-hydrogens atoms",
	"6-31G* 6-31G plus one polarisation function all non-hydrogens atoms",
	"6-311G* 6-311G plus one polarisation function all non-hydrogens atoms",

	"3-21G**  3-21G plus one polarisation function all atoms",
	"3-21GSP** 3-21GSP plus one polarisation function all atoms",
	"4-22GSP** 4-22GSP plus one polarisation function all atoms",
	"6-31G** 6-31G plus one polarisation function all atoms",
	"6-311G** 6-311G plus one polarisation function all atoms",

	"3-21G(2d)  3-21G plus two polarisation functions all non-hydrogens atoms",
	"3-21GSP(2d) 3-21GSP plus two polarisation functions all non-hydrogens atoms",
	"4-22GSP(2d) 4-22GSP plus two polarisation functions all non-hydrogens atoms",
	"6-31G(2d) 6-31G plus two polarisation functions all non-hydrogens atoms",
	"6-311G(2d) 6-311G plus two polarisation functions all non-hydrogens atoms",

	"3-21G(2d,2p)  3-21G plus two polarisation functions all non-hydrogens atoms",
	"3-21GSP(2d,2p) 3-21GSP plus two polarisation functions all non-hydrogens atoms",
	"4-22GSP(2d,2p) 4-22GSP plus two polarisation functions all non-hydrogens atoms",
	"6-31G(2d,2p) 6-31G plus two polarisation functions all non-hydrogens atoms",
	"6-311G(2d,2p) 6-311G plus two polarisation functions all non-hydrogens atoms",

	"3-21G(2df)  3-21G plus three polarisation functions all non-hydrogens atoms",
	"3-21GSP(2df) 3-21GSP plus three polarisation functions all non-hydrogens atoms",
	"4-22GSP(2df) 4-22GSP plus three polarisation functions all non-hydrogens atoms",
	"6-31G(2df) 6-31G plus three polarisation functions all non-hydrogens atoms",
	"6-311G(2df) 6-311G plus three polarisation functions all non-hydrogens atoms",

	"3-21G(2df,2pd)  3-21G plus three polarisation functions all non-hydrogens atoms",
	"3-21GSP(2df,2pd) 3-21GSP plus three polarisation functions all non-hydrogens atoms",
	"4-22GSP(2df,2pd) 4-22GSP plus three polarisation functions all non-hydrogens atoms",
	"6-31G(2df,2pd) 6-31G plus three polarisation functions all non-hydrogens atoms",
	"6-311G(2df,2pd) 6-311G plus three polarisation functions all non-hydrogens atoms",

	"3-21G(3df)  3-21G plus four polarisation functions all non-hydrogens atoms",
	"3-21GSP(3df) 3-21GSP plus four polarisation functions all non-hydrogens atoms",
	"4-22GSP(3df) 4-22GSP plus four polarisation functions all non-hydrogens atoms",
	"6-31G(3df) 6-31G plus four polarisation functions all non-hydrogens atoms",
	"6-311G(3df) 6-311G plus four polarisation functions all non-hydrogens atoms",

	"3-21G(3df,3pd)  3-21G plus four polarisation functions all non-hydrogens atoms",
	"3-21GSP(3df,3pd) 3-21GSP plus four polarisation functions all non-hydrogens atoms",
	"4-22GSP(3df,3pd) 4-22GSP plus four polarisation functions all non-hydrogens atoms",
	"6-31G(3df,3pd) 6-31G plus four polarisation functions all non-hydrogens atoms",
	"6-311G(3df,3pd) 6-311G plus four polarisation functions all non-hydrogens atoms",

	"3-21+G*  3-21G + diff. non-hydrogens + 1 pol. non-hydrogens",
	"3-21+GSP* 3-21GSP + diff. non-hydrogens + 1 pol. non-hydrogens",
	"4-22+GSP* 4-22GSP + diff. non-hydrogens + 1 pol. non-hydrogens",
	"6-31+G* 6-31G + diff. non-hydrogens + 1 pol. non-hydrogens",
	"6-311+G* 6-311G + diff. non-hydrogens + 1 pol. non-hydrogens",

	"3-21+G**  3-21G + diff. non-hydrogens + 1 pol. ",
	"3-21+GSP** 3-21GSP + diff. non-hydrogens + 1 pol. ",
	"4-22+GSP** 4-22GSP + diff. non-hydrogens + 1 pol. ",
	"6-31+G** 6-31G + diff. non-hydrogens + 1 pol. ",
	"6-311+G** 6-311G + diff. non-hydrogens + 1 pol. ",

	"3-21+G(2d)  3-21G + diff. non-hydrogens + 2 pol. non-hydrogens",
	"3-21+GSP(2d) 3-21GSP + diff. non-hydrogens + 2 pol. non-hydrogens",
	"4-22+GSP(2d) 4-22GSP + diff. non-hydrogens + 2 pol. non-hydrogens",
	"6-31+G(2d) 6-31G + diff. non-hydrogens + 2 pol. non-hydrogens",
	"6-311+G(2d) 6-311G + diff. non-hydrogens + 2 pol. non-hydrogens",

	"3-21+G(2d,2p)  3-21G + diff. non-hydrogens + 2 pol. non-hydrogens",
	"3-21+GSP(2d,2p) 3-21GSP + diff. non-hydrogens + 2 pol. non-hydrogens",
	"4-22+GSP(2d,2p) 4-22GSP + diff. non-hydrogens + 2 pol. non-hydrogens",
	"6-31+G(2d,2p) 6-31G + diff. non-hydrogens + 2 pol. non-hydrogens",
	"6-311+G(2d,2p) 6-311G + diff. non-hydrogens + 2 pol. non-hydrogens",

	"3-21+G(2df)  3-21G + diff. non-hydrogens + 3 pol. non-hydrogens",
	"3-21+GSP(2df) 3-21GSP + diff. non-hydrogens + 3 pol. non-hydrogens",
	"4-22+GSP(2df) 4-22GSP + diff. non-hydrogens + 3 pol. non-hydrogens",
	"6-31+G(2df) 6-31G + diff. non-hydrogens + 3 pol. non-hydrogens",
	"6-311+G(2df) 6-311G + diff. non-hydrogens + 3 pol. non-hydrogens",

	"3-21+G(2df,2pd)  3-21G + diff. non-hydrogens + 3 pol. non-hydrogens",
	"3-21+GSP(2df,2pd) 3-21GSP + diff. non-hydrogens + 3 pol. non-hydrogens",
	"4-22+GSP(2df,2pd) 4-22GSP + diff. non-hydrogens + 3 pol. non-hydrogens",
	"6-31+G(2df,2pd) 6-31G + diff. non-hydrogens + 3 pol. non-hydrogens",
	"6-311+G(2df,2pd) 6-311G + diff. non-hydrogens + 3 pol. non-hydrogens",

	"3-21+G(3df)  3-21G + diff. non-hydrogens + 4 pol. non-hydrogens",
	"3-21+GSP(3df) 3-21GSP + diff. non-hydrogens + 4 pol. non-hydrogens",
	"4-22+GSP(3df) 4-22GSP + diff. non-hydrogens + 4 pol. non-hydrogens",
	"6-31+G(3df) 6-31G + diff. non-hydrogens + 4 pol. non-hydrogens",
	"6-311+G(3df) 6-311G + diff. non-hydrogens + 4 pol. non-hydrogens",

	"3-21+G(3df,3pd)  3-21G + diff. non-hydrogens + 4 pol. non-hydrogens",
	"3-21+GSP(3df,3pd) 3-21GSP + diff. non-hydrogens + 4 pol. non-hydrogens",
	"4-22+GSP(3df,3pd) 4-22GSP + diff. non-hydrogens + 4 pol. non-hydrogens",
	"6-31+G(3df,3pd) 6-31G + diff. non-hydrogens + 4 pol. non-hydrogens",
	"6-311+G(3df,3pd) 6-311G + diff. non-hydrogens + 4 pol. non-hydrogens",

	"3-21++G*  3-21G + diff. + 1 pol. non-hydrogens",
	"3-21++GSP* 3-21GSP + diff. + 1 pol. non-hydrogens",
	"4-22++GSP* 4-22GSP + diff. + 1 pol. non-hydrogens",
	"6-31++G* 6-31G + diff. + 1 pol. non-hydrogens",
	"6-311++G* 6-311G + diff. + 1 pol. non-hydrogens",

	"3-21++G**  3-21G + diff. + 1 pol. ",
	"3-21++GSP** 3-21GSP + diff. + 1 pol. ",
	"4-22++GSP** 4-22GSP + diff. + 1 pol. ",
	"6-31++G** 6-31G + diff. + 1 pol. ",
	"6-311++G** 6-311G + diff. + 1 pol. ",

	"3-21++G(2d)  3-21G + diff. + 2 pol. non-hydrogens",
	"3-21++GSP(2d) 3-21GSP + diff. + 2 pol. non-hydrogens",
	"4-22++GSP(2d) 4-22GSP + diff. + 2 pol. non-hydrogens",
	"6-31++G(2d) 6-31G + diff. + 2 pol. non-hydrogens",
	"6-311++G(2d) 6-311G + diff. + 2 pol. non-hydrogens",

	"3-21++G(2d,2p)  3-21G + diff. + 2 pol. non-hydrogens",
	"3-21++GSP(2d,2p) 3-21GSP + diff. + 2 pol. non-hydrogens",
	"4-22++GSP(2d,2p) 4-22GSP + diff. + 2 pol. non-hydrogens",
	"6-31++G(2d,2p) 6-31G + diff. + 2 pol. non-hydrogens",
	"6-311++G(2d,2p) 6-311G + diff. + 2 pol. non-hydrogens",

	"3-21++G(2df)  3-21G + diff. + 3 pol. non-hydrogens",
	"3-21++GSP(2df) 3-21GSP + diff. + 3 pol. non-hydrogens",
	"4-22++GSP(2df) 4-22GSP + diff. + 3 pol. non-hydrogens",
	"6-31++G(2df) 6-31G + diff. + 3 pol. non-hydrogens",
	"6-311++G(2df) 6-311G + diff. + 3 pol. non-hydrogens",

	"3-21++G(2df,2pd)  3-21G + diff. + 3 pol. non-hydrogens",
	"3-21++GSP(2df,2pd) 3-21GSP + diff. + 3 pol. non-hydrogens",
	"4-22++GSP(2df,2pd) 4-22GSP + diff. + 3 pol. non-hydrogens",
	"6-31++G(2df,2pd) 6-31G + diff. + 3 pol. non-hydrogens",
	"6-311++G(2df,2pd) 6-311G + diff. + 3 pol. non-hydrogens",

	"3-21++G(3df)  3-21G + diff. + 4 pol. non-hydrogens",
	"3-21++GSP(3df) 3-21GSP + diff. + 4 pol. non-hydrogens",
	"4-22++GSP(3df) 4-22GSP + diff. + 4 pol. non-hydrogens",
	"6-31++G(3df) 6-31G + diff. + 4 pol. non-hydrogens",
	"6-311++G(3df) 6-311G + diff. + 4 pol. non-hydrogens",

	"3-21++G(3df,3pd)  3-21G + diff. + 4 pol. non-hydrogens",
	"3-21++GSP(3df,3pd) 3-21GSP + diff. + 4 pol. non-hydrogens",
	"4-22++GSP(3df,3pd) 4-22GSP + diff. + 4 pol. non-hydrogens",
	"6-31++G(3df,3pd) 6-31G + diff. + 4 pol. non-hydrogens",
	"6-311++G(3df,3pd) 6-311G + diff. + 4 pol. non-hydrogens",

};
static gchar* listPopleBasisReal[] = 
{ 
	"3-21G",
	"3-21GSP",
	"4-22GSP',
	"6-31G",
	"6-311G",

	"3-21+G",
	"3-21+GSP",
	"4-22+GSP",
	"6-31+G",
	"6-311+G",

	"3-21++G",
	"3-21++GSP",
	"4-22++GSP",
	"6-31++G",
	"6-311++G",

	"3-21G*",
	"3-21GSP*",
	"4-22GSP*",
	"6-31G*",
	"6-311G*",

	"3-21G**",
	"3-21GSP**",
	"4-22GSP**",
	"6-31G**",
	"6-311G**",

	"3-21G(2d)",
	"3-21GSP(2d)",
	"4-22GSP(2d)",
	"6-31G(2d)",
	"6-311G(2d)",

	"3-21G(2d,2p)",
	"3-21GSP(2d,2p)",
	"4-22GSP(2d,2p)",
	"6-31G(2d,2p)",
	"6-311G(2d,2p)",

	"3-21G(2df)",
	"3-21GSP(2df)",
	"4-22GSP(2df)",
	"6-31G(2df)",
	"6-311G(2df)",

	"3-21G(2df,2pd)",
	"3-21GSP(2df,2pd)",
	"4-22GSP(2df,2pd)",
	"6-31G(2df,2pd)",
	"6-311G(2df,2pd)",

	"3-21G(3df)",
	"3-21GSP(3df)",
	"4-22GSP(3df)",
	"6-31G(3df)",
	"6-311G(3df)",

	"3-21G(3df,3pd)",
	"3-21GSP(3df,3pd)",
	"4-22GSP(3df,3pd)",
	"6-31G(3df,3pd)",
	"6-311G(3df,3pd)",

	"3-21+G*",
	"3-21+GSP*",
	"4-22+GSP*",
	"6-31+G*",
	"6-311+G*",

	"3-21+G**",
	"3-21+GSP**",
	"4-22+GSP**",
	"6-31+G**",
	"6-311+G**",

	"3-21+G(2d)",
	"3-21+GSP(2d)",
	"4-22+GSP(2d)",
	"6-31+G(2d)",
	"6-311+G(2d)",

	"3-21+G(2d,2p)",
	"3-21+GSP(2d,2p)",
	"4-22+GSP(2d,2p)",
	"6-31+G(2d,2p)",
	"6-311+G(2d,2p)",

	"3-21+G(2df)",
	"3-21+GSP(2df)",
	"4-22+GSP(2df)",
	"6-31+G(2df)",
	"6-311+G(2df)",

	"3-21+G(2df,2pd)",
	"3-21+GSP(2df,2pd)",
	"4-22+GSP(2df,2pd)",
	"6-31+G(2df,2pd)",
	"6-311+G(2df,2pd)",

	"3-21+G(3df)",
	"3-21+GSP(3df)",
	"4-22+GSP(3df)",
	"6-31+G(3df)",
	"6-311+G(3df)",

	"3-21+G(3df,3pd)",
	"3-21+GSP(3df,3pd)",
	"4-22+GSP(3df,3pd)",
	"6-31+G(3df,3pd)",
	"6-311+G(3df,3pd)",

	"3-21++G*",
	"3-21++GSP*",
	"4-22++GSP*",
	"6-31++G*",
	"6-311++G*",

	"3-21++G**",
	"3-21++GSP**",
	"4-22++GSP**",
	"6-31++G**",
	"6-311++G**",

	"3-21++G(2d)",
	"3-21++GSP(2d)",
	"4-22++GSP(2d)",
	"6-31++G(2d)",
	"6-311++G(2d)",

	"3-21++G(2d,2p)",
	"3-21++GSP(2d,2p)",
	"4-22++GSP(2d,2p)",
	"6-31++G(2d,2p)",
	"6-311++G(2d,2p)",

	"3-21++G(2df)",
	"3-21++GSP(2df)",
	"4-22++GSP(2df)",
	"6-31++G(2df)",
	"6-311++G(2df)",

	"3-21++G(2df,2pd)",
	"3-21++GSP(2df,2pd)",
	"4-22++GSP(2df,2pd)",
	"6-31++G(2df,2pd)",
	"6-311++G(2df,2pd)",

	"3-21++G(3df)",
	"3-21++GSP(3df)",
	"4-22++GSP(3df)",
	"6-31++G(3df)",
	"6-311++G(3df)",

	"3-21++G(3df,3pd)",
	"3-21++GSP(3df,3pd)",
	"4-22++GSP(3df,3pd)",
	"6-31++G(3df,3pd)",
	"6-311++G(3df,3pd)",
};
static guint numberOfPopleBasis = G_N_ELEMENTS (listPopleBasisView);
/*************************************************************************************************************/
static gchar* listDunningBasisView[] = 
{ 
	"cc-pVDZ Dunning correlation concisistent polarized double zeta",
	"cc-(p)VDZ Same but no polarization on hydrogens",
	"Aug-cc-pVDZ Same but including diffuse functions",
	"cc-pVTZ Dunning correlation concisistent polarized triple zeta",
	"cc-(p)VTZ Same but no polarization on hydrogen",
	"Aug-cc-pVTZ Same but including diffuse functions(g-functions deleted!)",
	"cc-pVQZ Dunning correlation concisistent polarized quadruple zeta",
	"Aug-cc-pVQZ with diffuse functions",
	"cc-pV5Z Dunning correlation concisistent polarized quintuple zeta",
	"Aug-cc-pV5Z with diffuse functions",
	"cc-pV6Z Dunning correlation concisistent polarized sextuple zeta",
	"Aug-cc-pV6Z ... with diffuse functions",
	"cc-pCVDZ Core-polarized double-zeta correlation consistent basis set",
	"cc-pCVTZ Same for triple zeta",
	"cc-pCVQZ Same for quadruple zeta",
	"cc-pCV5Z Same for quintuple zeta",
	"cc-pV6Z Same for sextuple zeta",
	"Aug-pCVDZ Same double zeta with diffuse functions augmented",
	"Aug-pCVTZ Same for triple zeta",
	"Aug-pCVQZ Same for quadruple zeta",
	"Aug-pCV5Z Same for quintuple zeta",
	"Aug-cc-pV6Z Same for sextuple zeta",
	"DUNNING-DZP Dunning's original double zeta basis set",
};
static gchar* listDunningBasisReal[] = 
{ 
	"cc-pVDZ",
	"cc-(p)VDZ",
	"Aug-cc-pVDZ",
	"cc-pVTZ",
	"cc-(p)VTZ",
	"Aug-cc-pVTZ",
	"cc-pVQZ",
	"Aug-cc-pVQZ",
	"cc-pV5Z",
	"Aug-cc-pV5Z",
	"cc-pV6Z",
	"Aug-cc-pV6Z",
	"cc-pCVDZ",
	"cc-pCVTZ",
	"cc-pCVQZ",
	"cc-pCV5Z",
	"cc-pV6Z",
	"Aug-pCVDZ",
	"Aug-pCVTZ",
	"Aug-pCVQZ",
	"Aug-pCV5Z",
	"Aug-cc-pV6Z",
};
static guint numberOfDunningBasis = G_N_ELEMENTS (listDunningBasisView);
/*************************************************************************************************************/
static gchar* listAhlrichsBasisView[] = 
{ 
	"SV Ahlrichs split valence basis set",
	"VDZ Ahlrichs split valence basis set",
	"VTZ Ahlrichs Valence triple zeta basis set",
	"TZV Ahlrichs triple-zeta valence basis set. NOT identical to VTZ",
	"QZVP Ahlrichs quadruple-zeta basis set. P is already polarized",
	"DZ Ahlrichs double zeta basis set",
	"QZVPP(-g,-f) QZVPP with higest polarization functions deleted",

	"SV(P) SV + One polar set on all non-hydrogens atoms",
	"VDZ(P) VDZ + One polar set on all non-hydrogens atoms",
	"VTZ(P) VTZ  + One polar set on all non-hydrogens atoms",
	"TZV(P) TZV  + One polar set on all non-hydrogens atoms",
	"DZ(P)  DZ   + One polar set on all non-hydrogens atoms",

	"SVP SV + One polar set on all atoms",
	"VDZP VDZ + One polar set on all atoms",
	"VTZP VTZ  + One polar set on all atoms",
	"TZVP TZV  + One polar set on all atoms",
	"DZP  DZ   + One polar set on all atoms",

	"SV(2D) SV + Two polar set on all non-hydrogens atoms",
	"VDZ(2D) VDZ + Two polar set on all non-hydrogens atoms",
	"VTZ(2D) VTZ  + Two polar set on all non-hydrogens atoms",
	"TZV(2D) TZV  + Two polar set on all non-hydrogens atoms",
	"DZ(2D)  DZ   + Two polar set on all non-hydrogens atoms",

	"SV(2D,2P) SV + Two polar set on all atoms",
	"VDZ(2D,2P) VDZ + Two polar set on all atoms",
	"VTZ(2D,2P) VTZ  + Two polar set on all atoms",
	"TZV(2D,2P) TZV  + Two polar set on all atoms",
	"DZ(2D,2P)  DZ   + Two polar set on all atoms",

	"SV(2df) SV + Three polar set on all non-hydrogens atoms",
	"VDZ(2df) VDZ + Three polar set on all non-hydrogens atoms",
	"VTZ(2df) VTZ  + Three polar set on all non-hydrogens atoms",
	"TZV(2df) TZV  + Three polar set on all non-hydrogens atoms",
	"DZ(2df)  DZ   + Three polar set on all non-hydrogens atoms",

	"SV(2df,2pd) SV + Three polar set on all atoms",
	"VDZ(2df,2pd) VDZ + Three polar set on all atoms",
	"VTZ(2df,2pd) VTZ  + Three polar set on all atoms",
	"TZV(2df,2pd) TZV  + Three polar set on all atoms",
	"DZ(2df,2pd)  DZ   + Three polar set on all atoms",

	"SV(PP) SV + Three polar set on all non-hydrogens atoms",
	"VDZ(PP) VDZ + Three polar set on all non-hydrogens atoms",
	"VTZ(PP) VTZ  + Three polar set on all non-hydrogens atoms",
	"TZV(PP) TZV  + Three polar set on all non-hydrogens atoms",
	"DZ(PP)  DZ   + Three polar set on all non-hydrogens atoms",

	"SVPP SV + Three polar set on all atoms",
	"VDZPP VDZ + Three polar set on all atoms",
	"VTZPP VTZ  + Three polar set on all atoms",
	"TZVPP TZV  + Three polar set on all atoms",
	"DZPP  DZ   + Three polar set on all atoms",

	"SV(P)+ SV plus Pople diff. func. + 1 polar on non-hydrogens",
	"VDZ(P)+ VDZ plus Pople diff. func. + 1 polar on non-hydrogens",
	"VTZ(P)+ VTZ plus Pople diff. func. + 1 polar on non-hydrogens",
	"TZV(P)+ TZV  plus Pople diff. func. + 1 polar on non-hydrogens",

	"SVP++ SV plus Pople diff. func. + One polar set on all atoms",
	"TZVP++ TZV  plus Pople diff. func. + One polar set on all atoms",
	"TZV(2D) TZV  lus Pople diff. func. + One polar set on all atoms",

	"aug-SV(P) SV plus Dunning diff. One polar set on all non-hydrogens atoms",
	"aug-VDZ(P) VDZ plus Dunning diff. One polar set on all non-hydrogens atoms",
	"aug-VTZ(P) VTZ  plus Dunning diff. One polar set on all non-hydrogens atoms",
	"aug-TZV(P) TZV  plus Dunning diff. One polar set on all non-hydrogens atoms",
	"aug-DZ(P)  DZ   plus Dunning diff. One polar set on all non-hydrogens atoms",

	"aug-SVP SV plus Dunning diff. One polar set on all atoms",
	"aug-VDZP VDZ plus Dunning diff. One polar set on all atoms",
	"aug-VTZP VTZ  plus Dunning diff. One polar set on all atoms",
	"aug-TZVP TZV  plus Dunning diff. One polar set on all atoms",
	"aug-DZP  DZ   plus Dunning diff. One polar set on all atoms",

	"aug-SV(2D) SV plus Dunning diff. Two polar set on all non-hydrogens atoms",
	"aug-VDZ(2D) VDZ plus Dunning diff. Two polar set on all non-hydrogens atoms",
	"aug-VTZ(2D) VTZ  plus Dunning diff. Two polar set on all non-hydrogens atoms",
	"aug-TZV(2D) TZV  plus Dunning diff. Two polar set on all non-hydrogens atoms",
	"aug-DZ(2D)  DZ   plus Dunning diff. Two polar set on all non-hydrogens atoms",

	"aug-SV(2D,2P) SV plus Dunning diff. Two polar set on all atoms",
	"aug-VDZ(2D,2P) VDZ plus Dunning diff. Two polar set on all atoms",
	"aug-VTZ(2D,2P) VTZ  plus Dunning diff. Two polar set on all atoms",
	"aug-TZV(2D,2P) TZV  plus Dunning diff. Two polar set on all atoms",
	"aug-DZ(2D,2P)  DZ   plus Dunning diff. Two polar set on all atoms",

	"aug-SV(2df) SV plus Dunning diff. Three polar set on all non-hydrogens atoms",
	"aug-VDZ(2df) VDZ plus Dunning diff. Three polar set on all non-hydrogens atoms",
	"aug-VTZ(2df) VTZ  plus Dunning diff. Three polar set on all non-hydrogens atoms",
	"aug-TZV(2df) TZV  plus Dunning diff. Three polar set on all non-hydrogens atoms",
	"aug-DZ(2df)  DZ   plus Dunning diff. Three polar set on all non-hydrogens atoms",

	"aug-SV(2df,2pd) SV plus Dunning diff. Three polar set on all atoms",
	"aug-VDZ(2df,2pd) VDZ plus Dunning diff. Three polar set on all atoms",
	"aug-VTZ(2df,2pd) VTZ  plus Dunning diff. Three polar set on all atoms",
	"aug-TZV(2df,2pd) TZV  plus Dunning diff. Three polar set on all atoms",
	"aug-DZ(2df,2pd)  DZ   plus Dunning diff. Three polar set on all atoms",

	"aug-SV(PP) SV plus Dunning diff. Three polar set on all non-hydrogens atoms",
	"aug-VDZ(PP) VDZ plus Dunning diff. Three polar set on all non-hydrogens atoms",
	"aug-VTZ(PP) VTZ  plus Dunning diff. Three polar set on all non-hydrogens atoms",
	"aug-TZV(PP) TZV  plus Dunning diff. Three polar set on all non-hydrogens atoms",
	"aug-DZ(PP)  DZ   plus Dunning diff. Three polar set on all non-hydrogens atoms",

	"aug-SVPP SV plus Dunning diff. Three polar set on all atoms",
	"aug-VDZPP VDZ plus Dunning diff. Three polar set on all atoms",
	"aug-VTZPP VTZ  plus Dunning diff. Three polar set on all atoms",
	"aug-TZVPP TZV  plus Dunning diff. Three polar set on all atoms",
	"aug-DZPP  DZ   plus Dunning diff. Three polar set on all atoms",
};
static gchar* listAhlrichsBasisReal[] = 
{ 
	"SV",
	"VDZ",
	"VTZ",
	"TZV",
	"QZVP",
	"DZ",
	"QZVPP(-g,-f)",

	"SV(P)",
	"VDZ(P)",
	"VTZ(P)",
	"TZV(P)",
	"DZ(P)",

	"SVP",
	"VDZP",
	"VTZP ",
	"TZVP ",
	"DZP",

	"SV(2D)",
	"VDZ(2D)",
	"VTZ(2D)",
	"TZV(2D)",
	"DZ(2D)",

	"SV(2D,2P)",
	"VDZ(2D,2P)",
	"VTZ(2D,2P)",
	"TZV(2D,2P)",
	"DZ(2D,2P)",

	"SV(2df)",
	"VDZ(2df)",
	"VTZ(2df)",
	"TZV(2df)",
	"DZ(2df)",

	"SV(2df,2pd)",
	"VDZ(2df,2pd)",
	"VTZ(2df,2pd)",
	"TZV(2df,2pd)",
	"DZ(2df,2pd)",

	"SV(PP)",
	"VDZ(PP)",
	"VTZ(PP)",
	"TZV(PP)",
	"DZ(PP)",

	"SVPP",
	"VDZPP",
	"VTZPP",
	"TZVPP",
	"DZPP",

	"SV(P)+",
	"VDZ(P)+",
	"VTZ(P)+",
	"TZV(P)+",

	"SVP++",
	"TZVP++",
	"TZV(2D)",

	"aug-SV(P)",
	"aug-VDZ(P)",
	"aug-VTZ(P)",
	"aug-TZV(P)",
	"aug-DZ(P)",

	"aug-SVP",
	"aug-VDZP",
	"aug-VTZP",
	"aug-TZVP",
	"aug-DZP",

	"aug-SV(2D)",
	"aug-VDZ(2D)",
	"aug-VTZ(2D)",
	"aug-TZV(2D)",
	"aug-DZ(2D)",

	"aug-SV(2D,2P)",
	"aug-VDZ(2D,2P)",
	"aug-VTZ(2D,2P)",
	"aug-TZV(2D,2P)",
	"aug-DZ(2D,2P)",

	"aug-SV(2df)",
	"aug-VDZ(2df)",
	"aug-VTZ(2df)",
	"aug-TZV(2df)",
	"aug-DZ(2df)",

	"aug-SV(2df,2pd)",
	"aug-VDZ(2df,2pd)",
	"aug-VTZ(2df,2pd)",
	"aug-TZV(2df,2pd)",
	"aug-DZ(2df,2pd)",

	"aug-SV(PP)",
	"aug-VDZ(PP)",
	"aug-VTZ(PP)",
	"aug-TZV(PP)",
	"aug-DZ(PP)",

	"aug-SVPP",
	"aug-VDZPP",
	"aug-VTZPP",
	"aug-TZVPP",
	"aug-DZPP",

};
static guint numberOfAhlrichsBasis = G_N_ELEMENTS (listAhlrichsBasisView);
/*************************************************************************************************************/
static gchar* listDef2AhlrichsBasisView[] = 
{ 
	"Def2-SV(P) SV basis set with 'new' polarization functions",
	"Def2-SVP",
	"Def2-TZVP TZVP basis set with 'new' polarization functions",
	"Def2-TZVP(-f) Delete the f-polarization functions from def2-TZVP",
	"Def2-TZVP(-df) delete the double d-function and replace it by the older single d-function.",
	"Def2-TZVPP TZVPP basis set with 'new' polarization functions",
	"Def2-aug-TZVPP Same but with diffuse functions from aug-cc-pVTZ",
	"Def2-QZVPP Very accurate quadruple-zeta basis.",
	"Def2-QZVPP(-g,-f) higest angular momentum polarization functions deleted",
};
static gchar* listDef2AhlrichsBasisReal[] = 
{ 
	"Def2-SV(P)",
	"Def2-SVP",
	"Def2-TZVP",
	"Def2-TZVP(-f)",
	"Def2-TZVP(-df)",
	"Def2-TZVPP",
	"Def2-aug-TZVPP",
	"Def2-QZVPP",
	"Def2-QZVPP(-g,-f)",
};
static guint numberOfDef2AhlrichsBasis = G_N_ELEMENTS (listDef2AhlrichsBasisView);
/*************************************************************************************************************/
static gchar* listJensenBasisView[] = 
{ 
	"PC-1 Polarization consistent basis sets (H-Ar) optimized for DFT",
	"PC-2 double zeta polarization consistent basis sets (H-Ar) optimized for DFT",
	"PC-3 triple zeta polarization consistent basis sets (H-Ar) optimized for DFT",
	"PC-4 quadruple zeta polarization consistent basis sets (H-Ar) optimized for DFT",
	"Aug-PC-1 PC-1 with augmentations by diffuse functions",
	"Aug-PC-2 PC-2 with augmentations by diffuse functions",
	"Aug-PC-3 PC-3 with augmentations by diffuse functions",
	"Aug-PC-4 PC-4 with augmentations by diffuse functions",
};
static gchar* listJensenBasisReal[] = 
{ 
	"PC-1",
	"PC-2",
	"PC-3",
	"PC-4",
	"Aug-PC-1",
	"Aug-PC-2",
	"Aug-PC-3",
	"Aug-PC-4",
};
static guint numberOfJensenBasis = G_N_ELEMENTS (listJensenBasisView);
/*************************************************************************************************************/
static gchar* listANOBasisView[] = 
{ 
	"ano-pVDZ better than the cc-pVDZ (but much larger number of primitives of course)",
	"ano-pVTZ",
	"ano-pVQZ",
	"ano-pV5Z",
	"saug-ano-pVDZ ano-pVDZ augmentation with a single set of s,p functions.",
	"saug-ano-pVTZ ano-pVTZ augmentation with a single set of s,p functions.",
	"saug-ano-pVQZ ano-pVQZ augmentation with a single set of s,p functions. ",
	"saug-ano-pV5Z ano-pV5Z augmentation with a single set of s,p functions.",
	"aug-ano-pVDZ ano-pVDZ full augmentation with spd",
	"aug-ano-pVTZ ano-pVTZ full augmentation with spdf",
	"aug-ano-pVQZ ano-pVQZ full augmentation with spdfg",
	"BNANO-DZP (Bonn-ANO-DZP), small DZP type ANO basis set from the Bonn group",
	"BNANO-TZ2P (Bonn-ANO-TZ2P), slightly larger triple-zeta ANO with two pol. Bonn group",
	"BNANO-TZ3P Same but with a contracted set of f-polarization functions on the heavy atoms",
	"NASA-AMES-ANO The original NASA/AMES ANO basis set (quadruple-zeta type)",
	"BAUSCHLICHER ANO First row transition metal ANO sets",
	"ROOS-ANO-DZP A fairly large DZP basis set from Roos, same size as aug-ano-pVDZ",
	"ROOS-ANO-TZP A fairly large TZP basis from Roos, same size as aug-ano-pVTZ",

};
static gchar* listANOBasisReal[] = 
{ 
	"ano-pVDZ",
	"ano-pVTZ",
	"ano-pVQZ",
	"ano-pV5Z",
	"saug-ano-pVDZ",
	"saug-ano-pVTZ",
	"saug-ano-pVQZ",
	"saug-ano-pV5Z",
	"aug-ano-pVDZ",
	"aug-ano-pVTZ",
	"aug-ano-pVQZ",
	"BNANO-DZP",
	"BNANO-TZ2P",
	"BNANO-TZ3P",
	"NASA-AMES-ANO",
	"BAUSCHLICHER",
	"ROOS-ANO-DZP",
	"ROOS-ANO-TZP",
};
static guint numberOfANOBasis = G_N_ELEMENTS (listANOBasisView);
/*************************************************************************************************************/
static gchar* listMiscellenousBasisView[] = 
{ 
	"DGAUSS DGauss polarized valence double zeta basis set",
	"DZVP-DFT DGauss polarized valence double zeta basis set",
	"SADLEJ-PVTZ Sadlej's polarized triple zeta basis for poarlizability and related calculations",
	"EPR-II Barone's Basis set for EPR calculations (double zeta)",
	"EPR-III Barone's Basis set for EPR calculations (triple-zeta)",
	"IGLO-II Kutzelniggs basis set for NMR and EPR calculations",
	"IGLO-III Kutzelniggs basis set for NMR and EPR calculations (accurate)",
	"Partridge-1 Accurate uncontracted basis set",
	"Partridge-2 Accurate uncontracted basis set",
	"Partridge-3 Accurate uncontracted basis set",
	"Wachters Good first row transition metal basis set",

};
static gchar* listMiscellenousBasisReal[] = 
{ 
	"DGAUSS",
	"DZVP-DFT",
	"SADLEJ-PVTZ",
	"EPR-II",
	"EPR-III",
	"IGLO-II",
	"IGLO-III",
	"Partridge-1",
	"Partridge-2",
	"Partridge-3",
	"Wachters",
};
static guint numberOfMiscellenousBasis = G_N_ELEMENTS (listMiscellenousBasisView);
/*************************************************************************************************************/
static void setOrcaBasis()
{
	GtkTreeIter iter;
	GtkTreeIter iter0;
	gint i;
	gchar* listBasisReal = NULL;
	gchar* listBasisView = NULL;
	gint numberOfBasis = 0;

	if(strcmp(selectedTypeBasis, "Pople Style basis sets")==0)
	{
		listBasisView = listPopleBasisView;
		listBasisReal = listPopleBasisReal;
		numberOfBasis = numberOfPopleBasis;
	}
	else if(strcmp(selectedTypeBasis, "Dunning basis sets")==0)
	{
		listBasisView = listDunningBasisView;
		listBasisReal = listDunningBasisReal;
		numberOfBasis = numberOfDunningBasis;
	}
	else if(strcmp(selectedTypeBasis, "Ahlrichs basis sets")==0)
	{
		listBasisView = listAhlrichsBasisView;
		listBasisReal = listAhlrichsBasisReal;
		numberOfBasis = numberOfAhlrichsBasis;
	}
	else if(strcmp(selectedTypeBasis, "Def2 Ahlrichs basis sets")==0)
	{
		listBasisView = listDef2AhlrichsBasisView;
		listBasisReal = listDef2AhlrichsBasisReal;
		numberOfBasis = numberOfDef2AhlrichsBasis;
	}
	else if(strcmp(selectedTypeBasis, "Jensen Basis Sets")==0)
	{
		listBasisView = listJensenBasisView;
		listBasisReal = listJensenBasisReal;
		numberOfBasis = numberOfJensenBasis;
	}
	else if(strcmp(selectedTypeBasis, "Atomic Natural Orbital Basis Sets")==0)
	{
		listBasisView = listANOBasisView;
		listBasisReal = listANOBasisReal;
		numberOfBasis = numberOfANOBasis;
	}
	else if(strcmp(selectedTypeBasis, "Miscellenous and Specialized Basis Sets")==0)
	{
		listBasisView = listMiscellenousBasisView;
		listBasisReal = listMiscellenousBasisReal;
		numberOfBasis = numberOfMiscellenousBasis;
	}
	
	if (comboBasis && gtk_combo_box_get_active_iter (GTK_COMBO_BOX(comboBasis), &iter))
	{
		GtkTreeModel* model = gtk_combo_box_get_model(GTK_COMBO_BOX(comboBasis));
        	GtkTreeStore *store = GTK_TREE_STORE(model);
		gtk_tree_store_clear(store);

		for(i=0;i<numberOfBasis;i++)
		{
        		gtk_tree_store_append (store, &iter, NULL);
			if(i==0) iter0 = iter;
        		gtk_tree_store_set (store, &iter, 0, listBasisView[i], -1);
		}
		gtk_combo_box_set_active_iter(GTK_COMBO_BOX (comboBasis), &iter0);
	}

}
/************************************************************************************************************/
static void traitementTypeBasis (GtkComboBox *combobox, gpointer d)
{
	GtkTreeIter iter;
	gchar* data = NULL;
	gchar* res = NULL;
	gint i;
	/* gchar* s;*/
	if (gtk_combo_box_get_active_iter (combobox, &iter))
	{
		GtkTreeModel* model = gtk_combo_box_get_model(combobox);
		gtk_tree_model_get (model, &iter, 0, &data, -1);
	}
	else return;
	for(i=0;i<numberOfTypeBasis;i++)
	{
		if(strcmp((gchar*)data,listTypeBasisView[i])==0) res = listTypeBasisReal[i];
	}
	if(res) sprintf(selectedTypeBasis,"%s",res);

	setOrcaBasis();
}
/********************************************************************************************************/
static GtkWidget *create_list_type_basis()
{
        GtkTreeIter iter;
        GtkTreeStore *store;
	GtkTreeModel *model;
	GtkWidget *combobox;
	GtkCellRenderer *renderer;
	gint i;
        GtkTreeIter iter0;

	store = gtk_tree_store_new (1,G_TYPE_STRING);

	for(i=0;i<numberOfTypeBasis;i++)
	{
        	gtk_tree_store_append (store, &iter, NULL);
		if(i==0) iter0 = iter;
        	gtk_tree_store_set (store, &iter, 0, listTypeBasisView[i], -1);
	}

        model = GTK_TREE_MODEL (store);
	combobox = gtk_combo_box_new_with_model (model);
	/*
	gtk_combo_box_set_add_tearoffs (GTK_COMBO_BOX (combobox), TRUE);
	*/
	g_object_unref (model);
	g_signal_connect (G_OBJECT(combobox), "changed", G_CALLBACK(traitementTypeBasis), NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (combobox), renderer, TRUE);
	gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (combobox), renderer, "text", 0, NULL);

	gtk_combo_box_set_active_iter(GTK_COMBO_BOX (combobox), &iter0);

	return combobox;
}
