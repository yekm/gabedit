/**************************************************************/
static void get_one_point(gdouble v1, gdouble v2, gdouble x1, gdouble y1, gdouble x2, gdouble y2, gdouble* x, gdouble* y)
{
	gdouble u1 = x1;
	gdouble u2 = x2;
	if(v1==0) *x = u1;
	else *x = u1 - v1 *(u2-u1)/(v2-v1);
	u1 = y1;
	u2 = y2;
	if(v1==0) *y = u1;
	else *y = u1 - v1 *(u2-u1)/(v2-v1);
}
/**************************************************************/
ContourData* get_contour_point(ContoursPlotData *data, gdouble value)
{
	gint i;
	gint j;
	gint k;
	gint c;
	Point5 t[4];
	gdouble u1;
	gdouble u2;
	gdouble v1;
	gdouble v2;
	gint ix=0,iy=0;
	gint ix1=0,iy1=0;
	gint ix2=0,iy2=0;
	gint ix3=0,iy3=0;
	gint ix4=0,iy4=0;
	gdouble x1,x2,y1,y2,x,y;
	gdouble dx, dy;

	dx = (data->xmax-data->xmin)/(data->xsize-1);
	dy = (data->ymax-data->ymin)/(data->ysize-1);
	for( i = 0; i<xsize-1;i++)
	{
		for( j = 0; j<ysize-1;j++)
		{
			ix = i;
			ix1 = ix2 = ix + 1;
			ix4 = ix3 = ix;
			iy = j; 
			iy1 = iy4 =  iy; 
			iy2 = iy3 = iy+1 ;
        
			k = -1;
			
			v1 = data->zValues[ix*data->xsize+iy]-value,
			v2 = data->zValues[ix1*data->xsize+iy1]-value;
			x1 = xmin+ix*dx;
			y1 = ymin+iy*dy;
			x2 = xmin+ix1*dx;
			y2 = ymin+iy1*dx;
			if( v1*v2 <0 )
			{
				k++;
				get_one_point(v1, v2, x1, y1, x2, y2, &x, &y);
			}
			v1 = v2;
			v2 = data->zValues[ix2*data->xsize+iy2]-value;
			x1 = xmin+ix1*dx;
			y1 = ymin+iy1*dy;
			x2 = xmin+ix2*dx;
			y2 = ymin+iy2*dx;
			if( v1*v2 <0 )
			{
				k++;
				get_one_point(v1, v2, x1, y1, x2, y2, &x, &y);
			}
			v1 = v2;
			v2 = data->zValues[ix3*data->xsize+iy3]-value;
			x1 = xmin+ix2*dx;
			y1 = ymin+iy2*dy;
			x2 = xmin+ix3*dx;
			y2 = ymin+iy3*dx;
			if( v1*v2 <0 )
			{
				k++;
				get_one_point(v1, v2, x1, y1, x2, y2, &x, &y);
			}
			v1 = v2;
			v2 = data->zValues[ix4*data->xsize+iy4]-value;
			x1 = xmin+ix3*dx;
			y1 = ymin+iy3*dy;
			x2 = xmin+ix4*dx;
			y2 = ymin+iy4*dx;

			if( v1*v2 <0 )
			{
				k++;
				get_one_point(v1, v2, x1, y1, x2, y2, &x, &y);
			}
		}
	}

}
