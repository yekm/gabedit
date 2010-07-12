/****************************************************************************************/
static void set_object_image(GabeditXYPlot *xyplot, XYPlotObjectText* objectImage, guint xi, guint yi, guint w, guint h)
{
	if(!str) return;
	objectImage->xi = xi;
	objectImage->yi = yi;
	objectImage->w = w;
	objectImage->h = h;
}
/**************************************************************************************************/
static XYPlotObjectImage get_object_image(GabeditXYPlot *xyplot, gint xi, gint yi, G_CONST_RETURN gchar* fileName)
{
	gint w;
	gint h;
	gint nw;
	gint nh;
	XYPlotObjectImage objectImage;
	objectImage.w=0;
	objectImage.h=0;
	objectImage.xi=xi;
	objectImage.yi=yi;
	objectImage.fileName = fileName;
	objectImage.image=NULL;
	if(!fileName) return objectImage;
	objectImage.image = cairo_image_surface_create_from_png (objectImage.fileName);
        if(!objectImage.image) return;
        w = cairo_image_surface_get_width (objectImage.image);
	h = cairo_image_surface_get_height (objectImage.image);

	nw = xyplot->plotting_rect.width-xi;
	nh = xyplot->plotting_rect.height-yi;
	if(nw<w) w = nw;
	if(nh<h) h = nh;
	objectImage.w = w;
	objectImage.h = h;
	return objectImage;
}
/****************************************************************************************/
static void add_object_image(GabeditXYPlot *xyplot, guint xi, guint yi, G_CONST_RETURN gchar* fileName)
{
	XYPlotObjectImage objectImage = get_object_image(xyplot, xi, yi, fileName);
	if(!objectImage.image) return;
	xyplot->nObjectsImage++;
	if(xyplot->nObjectsImage==1) xyplot->objectsImage = g_malloc(sizeof(XYPlotObjectImage));
	else xyplot->objectsImage = g_realloc(xyplot->objectsImage,xyplot->nObjectsImage*sizeof(XYPlotObjectImage));
	xyplot->objectsImage[xyplot->nObjectsImage-1] = objectImage;
}
/****************************************************************************************/
static gint get_object_image_num(GabeditXYPlot *xyplot, guint xi, guint yi)
{
	gint i;
	if(!xyplot) return -1;
	for(i=0;i<xyplot->nObjectsImage;i++)
	{
		if(xi>=xyplot->objectsImage[i].xi && yi>=xyplot->objectsImage[i].yi
		&& xi<=xyplot->objectsImage[i].xi+xyplot->objectsImage[i].width 
		&& yi<=xyplot->objectsImage[i].yi+xyplot->objectsImage[i].height)
			return i;
	}
	return -1;
}
/****************************************************************************************/
static void delete_objects_image(GtkWidget *widget)
{
	GabeditXYPlot *xyplot = NULL;
	gint i;
	if(!widget) return;
	if(!GTK_IS_WIDGET(widget)) return;
	xyplot = GABEDIT_XYPLOT(widget);
	for(i=0;i<xyplot->nObjectsImage;i++)
	{
		if(xyplot->objectsImage[i].fileName) g_free(xyplot->objectsImage[i].fileName);
		if(xyplot->objectsImage[i].image) cairo_surface_destroy (xyplot->objectsImage[i].image);
	}
	xyplot->nObjectsImage = 0;
	if(xyplot->objectsImage) g_free(xyplot->objectsImage);
	xyplot->objectsImage = NULL;
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));
}
/********************************************************************************/
static gboolean read_image_png(GtkFileChooser *filesel, gint response_id)
{
	gchar *fileName;
 	gchar t[BSIZE];
 	FILE *fd;
	GtkWidget* xyplot = NULL;
	gchar** strsplit;
	gchar* str = NULL;
	gint* numberOfPoints = NULL;
	gdouble** X = NULL;
	gdouble** Y = NULL;
	gint nmax = 0;
	gint i;
	gint k;
	gdouble x=0;
	XYPlotObjectImage* objectImage = NULL;

	if(response_id != GTK_RESPONSE_OK) return FALSE;
 	fileName = gtk_file_chooser_get_filename(filesel);
	xyplot = g_object_get_data(G_OBJECT (filesel), "XYPLOT");
	objectImage = g_object_get_data(G_OBJECT(filesel),"ObjectImage");
	if(objectImage)
	{
		add_object_image(GABEDIT_XYPLOT(xyplot), objectImage->x, objectImage->y, fileName);
		g_free(objectImage);
	}
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	return TRUE;

}
/********************************************************************************/
static void add_set_object_image_dialog(GtkWidget* xyplot, guint xi, guint yi)
{
	GtkWidget* parentWindow = NULL;
	gchar* patternsfiles[] = {"*.png","*",NULL}; 
	GtkWidget* filesel= NULL;
	XYPlotObjectImage* objectImage = NULL;

	objectImage = g_malloc(sizeof(XYPlotObjectImage));
	objectImage->xi = xi;
	objectImage->yi = yi;
	objectImage->fileName = NULL;
	objectImage->image = NULL;

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	filesel= new_file_chooser_open(parentWindow, 
			(GCallback *)read_data_xy1yncolumns, 
			_("Read image from a png file"), 
			patternsfiles);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
	g_object_set_data(G_OBJECT (filesel), "XYPLOT", xyplot);
	g_object_set_data(G_OBJECT(filesel),"ObjectImage", objectImage);
}
/****************************************************************************************/
static void begin_insert_objects_image(GtkWidget *widget)
{
	if(!widget) return;
	if(!GTK_IS_WIDGET(widget)) return;
	GABEDIT_XYPLOT(widget)->t_key_pressed = TRUE;
}
