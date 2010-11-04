/*****************************************************************************/
static void gl_build_dipole()
{	
	V4d Specular = {1.0f,1.0f,1.0f,1.0f};
	V4d Diffuse  = {0.0f,0.0f,1.0f,1.0f};
	V4d Ambiant  = {0.0f,0.0f,0.1f,1.0f};
	V3d Base1Pos  = {0.0f,0.0f,0.0f};
	V3d Base2Pos  = {Dipole.Value[0],Dipole.Value[1],Dipole.Value[2]};
	GLdouble radius = Dipole.radius;
	V3d Center;
	GLdouble scal = 2;
	V3d Direction;
	double lengt;
	gint i;

	for(i=0;i<3;i++)
	{
		Diffuse[i] = Dipole.color[i]/65535.0;
		Ambiant[i] = Diffuse[i]/10;
	}

	Direction[0] = Base2Pos[0]-Base1Pos[0];
	Direction[1] = Base2Pos[1]-Base1Pos[1];
	Direction[2] = Base2Pos[2]-Base1Pos[2];
	lengt = v3d_length(Direction);
	if(radius<0.1) radius = 0.1;

	Direction[0] /= lengt;
	Direction[1] /= lengt;
	Direction[2] /= lengt;

	Base2Pos[0] *= scal;
	Base2Pos[1] *= scal;
	Base2Pos[2] *= scal;

	Center[0] = Base2Pos[0];
	Center[1] = Base2Pos[1];
	Center[2] = Base2Pos[2];

	Base2Pos[0] += Direction[0]*2*radius;
	Base2Pos[1] += Direction[1]*2*radius;
	Base2Pos[2] += Direction[2]*2*radius;

	Cylinder_Draw_Color(radius/2,Base1Pos,Center,Specular,Diffuse,Ambiant);
	for(i=0;i<3;i++)
	{
		Diffuse[i] *=0.6;
		Ambiant[i] *=0.6;
	}
	Diffuse[1] = Diffuse[2];
	Prism_Draw_Color(radius/1.5,Center,Base2Pos,Specular,Diffuse,Ambiant);
}
