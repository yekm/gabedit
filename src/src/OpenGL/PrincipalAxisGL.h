
#ifndef __GABEDIT_PRINCIPALAXISGL_H__
#define __GABEDIT_PRINCIPALAXISGL_H__

void getPrincipalAxisProperties(gboolean* show, gboolean* negative, gboolean* def, gfloat origin[], gfloat* radius, gfloat* scal,
		gfloat firstVector[],gfloat secondVector[], gfloat thirdVector[],
		gfloat firstColor[],gfloat secondColor[], gfloat thirdColor[]);
void initPrincipalAxisGL();
void save_principal_axis_properties();
void read_principal_axis_properties();
void set_principal_axisGL_dialog ();
gboolean testShowPrincipalAxisGL();
void showPrincipalAxisGL();
void hidePrincipalAxisGL();
GLuint principalAxisGenList(GLuint axisList);
void principalAxisShowList(GLuint axisList);

#endif /* __GABEDIT_PRINCIPALAXISGL_H__ */

