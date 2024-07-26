/********************************************************************************/
void redrawGeomGL2PS()
{
	GtkWidget* widget = GeomDrawingArea;
	GLdouble m[4][4];
	if(Zoom>=180) Zoom = 160;
	
	if(!GTK_IS_WIDGET(widget)) return TRUE;
	if(!GTK_WIDGET_REALIZED(widget)) return TRUE;

    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
	addFog();
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	set_background_color();

	mYPerspective(45,(GLdouble)widget->allocation.width/(GLdouble)widget->allocation.height,1,100);
    	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(optcol==-1) drawChecker();

    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
	if(PersMode)
		mYPerspective(Zoom,(GLdouble)widget->allocation.width/(GLdouble)widget->allocation.height,zNear,zFar);
	else
	{
	  	gdouble fw = (GLdouble)widget->allocation.width/(GLdouble)widget->allocation.height;
	  	gdouble fh = 1.0;
		glOrtho(-fw,fw,-fh,fh,-1,1);
	}

    	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(PersMode)
		glTranslatef(Trans[0],Trans[1],Trans[2]);
	else
	{
		 glTranslatef(Trans[0]/10,Trans[1]/10,0);
		 glScalef(1/Zoom*2,1/Zoom*2,1/Zoom*2);
	}
	SetLight();

	build_rotmatrix(m,Quat);
	glMultMatrixd(&m[0][0]);

	redrawGeometry();
	redrawSelection();
	redrawLabels();


	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetDoublev(GL_MODELVIEW_MATRIX, mvmatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projmatrix);

	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthRange(0.0f,1.0f);
	glFlush ();
}
