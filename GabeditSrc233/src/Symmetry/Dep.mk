MoleculeSymmetry.o: MoleculeSymmetry.c ../../Config.h \
  ../Symmetry/MoleculeSymmetryType.h ../Symmetry/MoleculeSymmetry.h \
  ../Symmetry/PrincipalAxis.h ../Symmetry/PolyHedralOperators.h \
  ../Symmetry/SymmetryOperators.h ../Symmetry/ReduceMolecule.h \
  ../Symmetry/GenerateMolecule.h ../Common/GabeditType.h \
  ../Utils/AtomsProp.h ../Utils/Constants.h
MoleculeSymmetryInterface.o: MoleculeSymmetryInterface.c ../../Config.h \
  ../Common/Global.h ../Common/../Files/GabeditFileChooser.h \
  ../Common/../Common/GabeditType.h ../Utils/UtilsInterface.h \
  ../Utils/Utils.h ../Utils/Constants.h ../Utils/GabeditTextEdit.h \
  ../Common/Windows.h ../Symmetry/MoleculeSymmetry.h
PolyHedralOperators.o: PolyHedralOperators.c ../../Config.h \
  ../Utils/Constants.h ../Symmetry/MoleculeSymmetryType.h \
  ../Symmetry/MoleculeSymmetry.h ../Symmetry/PolyHedralOperators.h \
  ../Symmetry/SymmetryOperators.h
ReducePolyHedralMolecule.o: ReducePolyHedralMolecule.c ../../Config.h \
  ../Symmetry/MoleculeSymmetryType.h ../Symmetry/MoleculeSymmetry.h \
  ../Symmetry/PolyHedralOperators.h \
  ../Symmetry/ReducePolyHedralMolecule.h ../Symmetry/SymmetryOperators.h
PrincipalAxis.o: PrincipalAxis.c ../../Config.h \
  ../Symmetry/MoleculeSymmetryType.h ../Symmetry/MoleculeSymmetry.h \
  ../Symmetry/SymmetryOperators.h
ReduceMolecule.o: ReduceMolecule.c ../../Config.h ../Utils/Constants.h \
  ../Symmetry/MoleculeSymmetryType.h ../Symmetry/MoleculeSymmetry.h \
  ../Symmetry/SymmetryOperators.h ../Symmetry/ReduceMolecule.h \
  ../Symmetry/ReducePolyHedralMolecule.h
SymmetryOperators.o: SymmetryOperators.c ../../Config.h \
  ../Utils/Constants.h ../Symmetry/MoleculeSymmetryType.h \
  ../Symmetry/MoleculeSymmetry.h ../Symmetry/SymmetryOperators.h
GenerateMolecule.o: GenerateMolecule.c ../../Config.h \
  ../Symmetry/MoleculeSymmetryType.h ../Symmetry/MoleculeSymmetry.h \
  ../Symmetry/SymmetryOperators.h ../Symmetry/ReduceMolecule.h \
  ../Symmetry/ReducePolyHedralMolecule.h
