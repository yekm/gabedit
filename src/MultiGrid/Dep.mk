DomainMG.o: DomainMG.c ../../Config.h ../Utils/Vector3d.h \
  ../Utils/Transformation.h ../Utils/Constants.h DomainMG.h TypesMG.h
GridMG.o: GridMG.c ../../Config.h ../Utils/Vector3d.h \
  ../Utils/Transformation.h ../Utils/Constants.h GridMG.h DomainMG.h \
  TypesMG.h
PoissonMG.o: PoissonMG.c ../../Config.h ../Utils/Vector3d.h \
  ../Utils/Transformation.h ../Utils/Constants.h ../Utils/Zlm.h \
  ../Utils/../Common/GabeditType.h ../Utils/MathFunctions.h \
  ../Utils/Zlm.h PoissonMG.h GridMG.h DomainMG.h TypesMG.h \
  ../Common/GabeditType.h ../OpenGL/GlobalOrb.h \
  ../OpenGL/../Files/GabeditFileChooser.h \
  ../OpenGL/../../gtkglarea/gtkglarea.h ../OpenGL/../../gtkglarea/gdkgl.h \
  ../OpenGL/../../gl2ps/gl2ps.h ../OpenGL/Grid.h \
  ../OpenGL/../MultiGrid/PoissonMG.h ../OpenGL/IsoSurface.h \
  ../OpenGL/../Common/GabeditType.h ../OpenGL/StatusOrb.h
