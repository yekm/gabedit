
#ifndef __GABEDIT_AXISGL_H__
#define __GABEDIT_AXISGL_H__

void getAxisProperties(gboolean* show, gboolean* negative, gfloat origin[], gfloat* radius, gfloat* scal, gfloat xColor[], gfloat yColor[], gfloat zColor[]);
void initAxis();
void save_axis_properties();
void read_axis_properties();
void set_axis_dialog ();
gboolean testShowAxis();
void showAxis();
void hideAxis();
GLuint axisGenList(GLuint axisList);
void axisShowList(GLuint axisList);

#endif /* __GABEDIT_AXISGL_H__ */

