# DO NOT DELETE

GInterfaceBasis.o: ../../Config.h
GInterfaceBasis.o: ../Common/Global.h ../Files/GabeditFileChooser.h
GInterfaceBasis.o: ../Common/GabeditType.h ../Utils/UtilsInterface.h
GInterfaceBasis.o: ../Geometry/GeomGlobal.h GaussGlobal.h GInterfaceBasis.h
GInterfaceGeom.o: ../../Config.h
GInterfaceGeom.o: ../Common/Global.h ../Files/GabeditFileChooser.h
GInterfaceGeom.o: ../Common/GabeditType.h ../Utils/UtilsInterface.h
GInterfaceGeom.o: ../Utils/Utils.h ../Geometry/GeomGlobal.h
GInterfaceGeom.o: ../Geometry/GeomXYZ.h ../Geometry/GeomZmatrix.h
GInterfaceGeom.o: ../Geometry/InterfaceGeom.h GaussGlobal.h
GInterfaceLink.o: ../../Config.h
GInterfaceLink.o: ../Common/Global.h ../Files/GabeditFileChooser.h
GInterfaceLink.o: ../Common/GabeditType.h ../Utils/UtilsInterface.h
GInterfaceLink.o: GaussGlobal.h
GInterfaceMethodeBase.o: ../../Config.h
GInterfaceMethodeBase.o: ../Common/Global.h
GInterfaceMethodeBase.o: ../Files/GabeditFileChooser.h
GInterfaceMethodeBase.o: ../Common/GabeditType.h ../Utils/Utils.h
GInterfaceMethodeBase.o: ../Utils/UtilsInterface.h ../Geometry/GeomGlobal.h
GInterfaceMethodeBase.o: ../Geometry/GeomXYZ.h ../Geometry/InterfaceGeom.h
GInterfaceMethodeBase.o: GInterfaceGeom.h GaussGlobal.h
GInterfaceRoute.o: ../../Config.h
GInterfaceRoute.o: ../Common/Global.h ../Files/GabeditFileChooser.h
GInterfaceRoute.o: ../Common/GabeditType.h ../Utils/Utils.h
GInterfaceRoute.o: ../Utils/UtilsInterface.h ../Utils/GabeditTextEdit.h
GInterfaceRoute.o: ../Geometry/GeomGlobal.h ../Geometry/GeomXYZ.h
GInterfaceRoute.o: ../Geometry/InterfaceGeom.h GInterfaceLink.h
GInterfaceRoute.o: GInterfaceMethodeBase.h GaussGlobal.h GInterfaceGeom.h
Gaussian.o: ../../Config.h
Gaussian.o: ../Common/Global.h
Gaussian.o: ../Files/GabeditFileChooser.h ../Common/GabeditType.h
Gaussian.o: ../Utils/UtilsInterface.h ../Utils/Utils.h
Gaussian.o: ../Utils/GabeditTextEdit.h ../Geometry/GeomGlobal.h
Gaussian.o: ../Geometry/GeomXYZ.h ../Geometry/InterfaceGeom.h
Gaussian.o: ../Utils/AtomsProp.h GaussGlobal.h GInterfaceRoute.h
Gaussian.o: GInterfaceGeom.h GInterfaceBasis.h
