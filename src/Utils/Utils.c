/* Utils.c */
/**********************************************************************************************************
Copyright (c) 2002-2009 Abdul-Rahman Allouche. All rights reserved

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the Gabedit), to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions
  of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
************************************************************************************************************/


#include "../../Config.h"
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#include "../Common/Global.h"
#include "../Utils/Constants.h"
#include "../Geometry/GeomGlobal.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Utils.h"
#include "../Utils/GabeditTextEdit.h"
#include "../Geometry/ResultsAnalise.h"
#include "../Geometry/EnergiesCurves.h"
#include "../Common/TextEdit.h"
#include "../Common/Preferences.h"
#include "../Common/Run.h"
#include "../OpenGL/GLArea.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Utils/HydrogenBond.h"
#ifdef G_OS_WIN32
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>
#include <fcntl.h>
#include <io.h>
#else /* G_OS_WIN32 */
#include <stdarg.h> 
#include <pwd.h>
#include <unistd.h> 
#include <sys/times.h>
#endif /* G_OS_WIN32 */

#define DebugFlag 0
#define Debug1Flag 0

void create_color_surfaces_file();
void read_color_surfaces_file();
void create_opengl_file();
void read_opengl_file();
void initAxis();
void save_axis_properties();
void read_axis_properties();
void save_principal_axis_properties();
void read_principal_axis_properties();
void initPrincipalAxisGL();


/********************************************************************************/
#ifndef G_OS_WIN32
#define TIMER_TICK      60
static clock_t it;
static struct tms itt;
void timing(double* cpu,double *sys)
{
	it=times(&itt);
	*cpu=(double) itt.tms_utime / (double) TIMER_TICK;
	*sys=(double) itt.tms_stime / (double) TIMER_TICK;
}
#endif
#ifdef G_OS_WIN32
/************************************************************************
*  error : display an error message and possibly the last Winsock error *
*************************************************************************/
gboolean winsockCheck(FILE* FileErr)
{
    	WORD wVersionRequested;
    	WSADATA wsaData;
    	int err;
    	wVersionRequested = MAKEWORD( 1, 1 );
    	err = WSAStartup( wVersionRequested, &wsaData );
    	if ( err != 0 )
	{
		fprintf(FileErr,"Unsupported version of winsock.dll!\n");
		return FALSE;
	}

    	if ( LOBYTE( wsaData.wVersion ) != 1 || HIBYTE( wsaData.wVersion ) != 1 )
	{
        	fprintf(FileErr,"Unsupported version of winsock.dll!\n");
		return FALSE;
	}

	return TRUE;
}
#endif /* G_OS_WIN32 */
/********************************************************************************/
FILE* FOpen(const gchar *fileutf8, const gchar* type)
{
	FILE* file;
#ifdef G_OS_WIN32
		/* gchar* filename = g_filename_to_utf8(fileutf8);*/
		gchar* filename = g_strdup(fileutf8);
		file = fopen(filename,type);
		if(file) set_last_directory(fileutf8);
		return file;
#else
		file = fopen(fileutf8,type);
		if(file) set_last_directory(fileutf8);
		return file;
#endif
}   
/********************************************************************************/
static void free_commands_list(CommandsList* list)
{
	gint i;
	if(!list)
		return;

	if(list->numberOfCommands<1)
	{
  		list->numberOfCommands = 0;
  		list->numberOfDefaultCommand = 0;
		list->commands = NULL;
		return;
	}
	if(list->commands)
	{
		for(i=0;i<list->numberOfCommands;i++)
			if(list->commands[i])
				g_free(list->commands[i]);
		g_free(list->commands);
	}
  	list->numberOfCommands = 0;
  	list->numberOfDefaultCommand = 0;
	list->commands = NULL;
}
/********************************************************************************/
void free_gamess_commands()
{
	free_commands_list(&gaussianCommands);
}
/********************************************************************************/
void free_gaussian_commands()
{
	free_commands_list(&gaussianCommands);
}
/********************************************************************************/
void free_molcas_commands()
{
	free_commands_list(&molcasCommands);
}
/********************************************************************************/
void free_molpro_commands()
{
	free_commands_list(&molproCommands);
}
/********************************************************************************/
void free_mpqc_commands()
{
	free_commands_list(&mpqcCommands);
}
/********************************************************************************/
void free_orca_commands()
{
	free_commands_list(&orcaCommands);
}
/********************************************************************************/
void free_pcgamess_commands()
{
	free_commands_list(&pcgamessCommands);
}
/********************************************************************************/
void free_qchem_commands()
{
	free_commands_list(&qchemCommands);
}
/********************************************************************************/
void free_mopac_commands()
{
	free_commands_list(&mopacCommands);
}
/********************************************************************************/
void free_povray_commands()
{
	free_commands_list(&povrayCommands);
}
/********************************************************************************/
gchar* get_time_str()
{
	gchar* str=NULL;
	time_t t;
	struct tm* ts;

	t = time(NULL);
	ts = localtime(&t);
	str = asctime (ts);
	return str;
}
/********************************************************************************/
gboolean this_is_a_backspace(gchar *st)
{
        gint i;
        for(i=0;i<(gint)strlen(st);i++)
        	if(st[i] != ' ' && st[i] !='\n' && st[i] !='\r')
                	return FALSE;
        return TRUE;
}   
/********************************************************************************/
void  set_file_open(gchar* remotehost,gchar* remoteuser,gchar* remotedir, GabEditNetWork netWorkProtocol)
{
  gchar localhost[100];

#ifdef G_OS_WIN32
	winsockCheck(stderr);
#endif
  gethostname(localhost,100);

  if(!fileopen.localhost)
  	fileopen.localhost = g_strdup(localhost);

  if(!fileopen.localdir)
  	fileopen.localdir = get_name_dir(fileopen.projectname);

  if(fileopen.remotehost)
	g_free(fileopen.remotehost);
  if(fileopen.remoteuser)
	g_free(fileopen.remoteuser);
  if(fileopen.remotedir)
	g_free(fileopen.remotedir);
  fileopen.remotehost = g_strdup(remotehost);
  fileopen.remoteuser = g_strdup(remotehost);
  fileopen.remotedir = g_strdup(remotedir);
  fileopen.netWorkProtocol = netWorkProtocol;
}
/********************************************************************************/
void filegets(gchar *temp,FILE* fd)
{
	gchar t[BSIZE];
        gint taille = BSIZE;
 	gint k = 0;
 	gint i;
 
 	fgets(t,taille,fd);
	for(i=0;i<taille;i++)
 	{
  		if(t[i] =='\n')
			break;
  		if(t[i] != ' ' && t[i] !='\n')
  		{
   			temp[k] = t[i];
   			k++;
  		}
 	}
 	temp[k] = '\0';
}
/********************************************************************************/
gboolean  this_is_an_object(GtkObject *obj)
{  
	return GTK_IS_OBJECT(obj);
}
/********************************************************************************/
gboolean  add_dir_to_user(User* user, const gchar* dir)
{  
	gint i;
	if(user->ndirs == 0)
	{
		user->ndirs = 1;
		user->dirs = g_malloc(sizeof(gchar*));
		user->dirs[0] = g_strdup(dir);
	}
	else
	{
		for(i=0;i<user->ndirs;i++)
			if(strcmp(dir,user->dirs[i]) == 0)
				return FALSE;

		user->dirs = g_realloc(user->dirs,(user->ndirs+1)*sizeof(gchar*));
		for(i=user->ndirs;i>0;i--)
			user->dirs[i] = user->dirs[i-1];
		user->dirs[0] = g_strdup(dir);
		if(user->ndirs>=NHOSTMAX)
		{
/*			g_free(user->dirs[user->ndirs]);*/
			user->dirs = g_realloc(user->dirs,(user->ndirs)*sizeof(gchar*));
		}
		else
			(user->ndirs)++;
	}
	return TRUE;
}
/********************************************************************************/
gboolean add_user_to_host(Host* host,const gchar *username, const gchar* password, const gchar *dir)
{  
	gint i;
	if(host->nusers == 0)
	{
		host->nusers = 1;
		host->users = g_malloc(sizeof(User));
		host->users[0].username = g_strdup(username);
		if(password)
			host->users[0].password = g_strdup(password);
		else
			host->users[0].password = NULL;
		host->users[0].ndirs = 0;
  		add_dir_to_user(&host->users[0] ,dir);
	}
	else
	{
		for(i=0;i<host->nusers;i++)
			if(strcmp(username,host->users[i].username) == 0)
			{
				return  add_dir_to_user(&host->users[i],dir);
			}
	
		host->users = g_realloc(host->users,(host->nusers+1)*sizeof(User));
		for(i=host->nusers;i>0;i--)
			host->users[i] = host->users[i-1];

		host->users[0].ndirs = 0;
		host->users[0].username = g_strdup(username);
		if(password)
			host->users[0].password = g_strdup(password);
		else
			host->users[0].password = NULL;
  		add_dir_to_user(&host->users[0] ,dir);
		if(host->nusers>=NHOSTMAX)
		{
			for(i=0;i<host->users[host->nusers].ndirs;i++)
			{
				g_free(host->users[host->nusers].dirs[i]);
			}
			g_free(host->users[host->nusers].dirs);
/*			g_free(host->users[host->nusers]);*/
			host->users = g_realloc(host->users,(host->nusers)*sizeof(User));
		}
		else
			(host->nusers)++;
	}
	return TRUE;
}
/********************************************************************************/
void add_host(const gchar *hostname, const gchar* username, const gchar* password, const gchar* dir)
{  
  gint i;
  gint j;

  if(recenthosts.nhosts == 0)
  {
	recenthosts.hosts = g_malloc(sizeof(Host));
 	recenthosts.hosts[0].hostname = g_strdup(hostname);
 	recenthosts.hosts[0].nusers = 0;
 	add_user_to_host(&recenthosts.hosts[0],username,password,dir);
	recenthosts.nhosts = 1;
  }
  else
  {
	for(i=0;i<recenthosts.nhosts;i++)
		if(strcmp(hostname,recenthosts.hosts[i].hostname) == 0)
		{
 			add_user_to_host(&recenthosts.hosts[i],username,password,dir);
			return;
		}

	recenthosts.hosts = g_realloc(recenthosts.hosts , (recenthosts.nhosts+1)*sizeof(Host));
	for(i=recenthosts.nhosts;i>0;i--)
		recenthosts.hosts[i] = recenthosts.hosts[i-1];
 	recenthosts.hosts[0].hostname = g_strdup(hostname);
 	recenthosts.hosts[0].nusers = 0;
 	add_user_to_host(&recenthosts.hosts[0],username,password,dir);
	if(recenthosts.nhosts>=NHOSTMAX)
	{
		for(i=0;i<recenthosts.hosts[recenthosts.nhosts].nusers;i++)
		{
			for(j=0;j<recenthosts.hosts[recenthosts.nhosts].users[i].ndirs;j++)
				g_free(recenthosts.hosts[recenthosts.nhosts].users[i].dirs[j]);
			g_free(recenthosts.hosts[recenthosts.nhosts].users[i].dirs);
		}
		g_free(recenthosts.hosts[recenthosts.nhosts].users);
		recenthosts.hosts = g_realloc(recenthosts.hosts ,(recenthosts.nhosts)*sizeof(Host));
	}
	else
		recenthosts.nhosts++;
	
  }
}
/********************************************************************************/
G_CONST_RETURN gchar *get_local_user()
{  
	

#ifdef G_OS_WIN32
	return NULL;
#else
  	struct passwd *pw;
  	const static gchar* localuser = NULL;

	if(localuser) return localuser;

  	localuser = g_getenv("USER");
  	if( (localuser == NULL) || ((pw = getpwnam(localuser)) && (pw->pw_uid != getuid())) )
  	{
		if ( (pw = getpwuid(getuid())))
			localuser = g_strdup(pw->pw_name);
		else
			localuser = NULL;
  	}
  return localuser;
#endif
}
/*************************************************************************************/
void Waiting(gdouble tsecond)
{
        GTimer *timer;
        gdouble elaps;
        gulong m ;
	
        timer =g_timer_new( );
	g_timer_start( timer );
	g_timer_reset( timer );
        do{
		elaps = g_timer_elapsed( timer,&m);
        }while(elaps<tsecond);
 	g_timer_destroy(timer);
}
/*************************************************************************************/
void Debug(char *fmt,...)
{
	va_list ap;
        if(DebugFlag)
		return;

	va_start(ap,fmt);
	vfprintf(stdout, fmt, ap);
	va_end(ap);
}
/********************************************************************************/
gchar* get_line_chars(gchar c,gint n)
{
	gint i;
	gchar *line = NULL;

	if(n<1)
		return line;
	line = g_malloc((n+1)*sizeof(gchar));
	for(i=0;i<n;i++)
		line[i] = c;
	line[n] = '\0';

	return line;
	
}
/********************************************************************************/
gchar* cat_file(gchar* namefile,gboolean tabulation)
{
 gchar *t = NULL;
 gchar *tsrt = NULL;
 FILE *fd;
 gchar *dump = NULL;


 t=g_malloc(BSIZE*sizeof(gchar));

 fd = FOpen(namefile, "r");
 if(fd)
 {
  	while(!feof(fd))
  	{
    		if(!fgets(t,BSIZE, fd)) break;
                dump = tsrt;
		if(!tsrt)
		{
			if(tabulation)
				tsrt = g_strdup_printf("\t%s",t);
			else
				tsrt = g_strdup_printf("%s",t);
		}
		else
		{
			if(tabulation)
				tsrt = g_strdup_printf("%s\t%s",tsrt,t);
			else
				tsrt = g_strdup_printf("%s%s",tsrt,t);
			g_free(dump);
			dump = NULL;
		}
  	}
 	fclose(fd);
	unlink (namefile);
 }
 else
 {
   tsrt = NULL;
 }
 g_free(t);
 t = tsrt;
 if(t)
 {
 	tsrt = g_locale_to_utf8(t,-1,NULL,NULL,NULL);
	g_free(t);
 }

 return tsrt;
  
}
/*************************************************************************************/
gchar *run_command(gchar *command)
{
 gchar *t;
 gchar *terr = NULL;
 FILE *fd;
 gchar *temp;
 gchar *outfile= g_strdup_printf("%s%stmp%soutfile",gabedit_directory(), G_DIR_SEPARATOR_S, G_DIR_SEPARATOR_S);
 gchar *errfile= g_strdup_printf("%s%stmp%serrfile",gabedit_directory(), G_DIR_SEPARATOR_S, G_DIR_SEPARATOR_S);
 gchar *dump;
 gint taille = BSIZE;

 temp = g_strdup_printf("sh -c '%s >%s 2>%s'",command,outfile,errfile);
 system(temp);

 t=g_malloc(taille);

 fd = FOpen(errfile, "r");
 if(fd)
 {
  	while(!feof(fd))
  	{
    		if(!fgets(t,taille, fd))
			break;
                dump = terr;
		if(!terr)
			terr = g_strdup_printf("%s",t);
		else
		{
			terr = g_strdup_printf("%s%s",terr,t);
			g_free(dump);
		}
  	}
 	fclose(fd);
	unlink (errfile);
 }
 else
   terr = NULL;

 fd = FOpen(outfile, "r");
 if(fd)
 {
	unlink (outfile);
 }

 g_free(t);
 g_free(temp);
 g_free(outfile);
 g_free(errfile);

 return terr;
}
/********************************************************************************/
#ifdef G_OS_WIN32

void createProcessWin32(char* myChildProcess)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

	printf("Command = %s\n",myChildProcess);
	/* Start the child process. */
	if( !CreateProcess( NULL,   /* No module name (use command line). */
		TEXT(myChildProcess), /* Command line. */
	                     NULL,      /* Process handle not inheritable. */
	                     NULL,      /* Thread handle not inheritable. */
	                    FALSE,      /* Set handle inheritance to FALSE. */
	                    0,          /* No creation flags. */
	                   NULL,        /* Use parent's environment block. */
	                   NULL,        /* Use parent's starting directory. */
	                   &si,         /* Pointer to STARTUPINFO structure.*/
	                  &pi )         /* Pointer to PROCESS_INFORMATION structure.*/
                        ) 
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"CreateProcess failed (%d)",(int)GetLastError());
        	Message(buffer, "Error", TRUE);
		return;
    }

        /* Wait until child process exits.*/
        /* WaitForSingleObject( pi.hProcess, INFINITE );*/

        /* Close process and thread handles. */
       CloseHandle( pi.hProcess );
       CloseHandle( pi.hThread );
}

#endif
/********************************************************************************/
void run_local_command(gchar *outfile,gchar *errfile,gchar* command,gboolean under)
{
	gchar *temp;
	gint ierr = 0;

	unlink (outfile);
	unlink (errfile);

	if(under)
	{
#ifdef G_OS_WIN32
		temp = g_strdup_printf("%s >%s 2>%s ",command, outfile, errfile);
		createProcessWin32(temp);

#else
		if(strstr(command,">"))
 		temp = g_strdup_printf("sh -c '%s 2>%s&'",command, errfile);
		else
 		temp = g_strdup_printf("sh -c '%s >%s 2>%s&'",command, outfile, errfile);
		ierr = system(temp);
#endif
 		
		Waiting(0.5);
	}
	else
	{
#ifdef G_OS_WIN32
		temp = g_strdup_printf("%s >%s 2>%s",command,outfile,errfile);
#else
 		temp = g_strdup_printf("sh -c '%s >%s 2>%s'",command,outfile,errfile);
#endif
 		ierr = system(temp);
	}

	g_free(temp);
}
/*************************************************************************************/
const gchar *gabedit_directory(void)
{
  static gchar *gabedit_dir = NULL;
  gchar *home_dir;
  gchar *home_dir_sep;
#ifdef G_OS_WIN32
  gchar* Version_S = g_strdup_printf("%d%d%d",MAJOR_VERSION,MINOR_VERSION,MICRO_VERSION);
#else
  gchar* Version_S = g_strdup_printf("%d.%d.%d",MAJOR_VERSION,MINOR_VERSION,MICRO_VERSION);
#endif

  if (gabedit_dir != NULL)
    return gabedit_dir;

  home_dir = g_strdup(g_get_home_dir());

  if (home_dir != NULL && home_dir[strlen(home_dir)-1] != G_DIR_SEPARATOR)
    home_dir_sep = G_DIR_SEPARATOR_S;
  else
    home_dir_sep = "";

  if (!home_dir)
  {
#ifdef G_OS_WIN32
		home_dir = g_strdup("C:");
#else  /* G_OS_WIN32 */
		home_dir = g_strdup("/tmp");
#endif /* G_OS_WIN32 */
		home_dir_sep = G_DIR_SEPARATOR_S;
  }
#ifdef G_OS_WIN32
  gabedit_dir = g_strconcat(home_dir,home_dir_sep,"gabedit",Version_S,NULL);
#else
  gabedit_dir = g_strconcat(home_dir,home_dir_sep,".gabedit-",Version_S,NULL);
#endif

  g_free(Version_S);
  return gabedit_dir;
}
/*************************************************************************************/
void DeleteLastChar(gchar *str)
{
        str[strlen(str)-1]='\0';
}
/*************************************************************************************/
gchar *get_dir_file_name(G_CONST_RETURN gchar* dirname, G_CONST_RETURN gchar* filename)
{
   gchar *name = NULL;

   name = g_strdup_printf("%s%s%s",dirname,G_DIR_SEPARATOR_S,filename); 
   
   return name;
}
/*************************************************************************************/
gchar *get_name_dir(const gchar* allname)
{
   gchar *name;
   name = g_path_get_dirname(allname);
   if(strcmp(name,".")==0) 
   {
	   g_free(name);
	   name = g_strdup(g_get_current_dir());
   }
   
  return name;
}
/*************************************************************************************/
gchar *get_suffix_name_file(const gchar* allname)
{
   gchar *filename= g_path_get_basename(allname);
   gchar *dirname= g_path_get_dirname(allname);
   gchar *temp= g_strdup(filename);
   gint len=strlen(filename);
   gint i;
   gchar* name = NULL;

   if(!allname || strlen(allname)<1) return g_strdup("error");
   filename= g_path_get_basename(allname);
   dirname= g_path_get_dirname(allname);
   temp= g_strdup(filename);
   len=strlen(filename);

   for(i=len;i>0;i--)
	if(temp[i]=='.')
	{
		temp[i] = '\0';
		break;
	}
   name = g_strdup_printf("%s%s%s",dirname,G_DIR_SEPARATOR_S,temp);
   if(temp) g_free(temp);
   if(dirname) g_free(dirname);
   if(filename) g_free(filename);

   if(strcmp(name,".")==0) name = g_strdup(g_get_current_dir());
   
  return name;
}
/*************************************************************************************/
gchar *get_name_file(const gchar* allname)
{
   gchar *name= g_path_get_basename(allname);
	/*
   gchar *name=g_strdup(allname);
   gint i;
   gint len=strlen(allname);
   gint islash=0;

   for(i=len;i>0;i--)
   if(allname[i]==G_DIR_SEPARATOR)
   {
     islash=i+1;
     break;
   }
   if(islash>0)
   {
	if(name)
		g_free(name);
   	name=g_malloc(len-islash+2);
   	for(i=islash;i<=len;i++)
    		name[i-islash]=allname[i];
   	name[len-islash+1]='\0';
   }
   */
   
  return name;
}
/*************************************************************************************/
Point get_produit_vectoriel(Point V1,Point V2)
{
   Point PV;

   PV.C[0]= V1.C[1]*V2.C[2]-V1.C[2]*V2.C[1];
   PV.C[1]= V1.C[2]*V2.C[0]-V1.C[0]*V2.C[2];
   PV.C[2]= V1.C[0]*V2.C[1]-V1.C[1]*V2.C[0];

  return PV;
} 
/*************************************************************************************/
gchar *get_distance_points(Point P1,Point P2,gboolean f3)
{
   gchar *distance;
   gdouble Distance;
   guint i;

   Distance = 0.0;
   for(i=0;i<3;i++)
 	Distance += (P1.C[i]- P2.C[i])*(P1.C[i]- P2.C[i]);
	
   Distance = sqrt(Distance)*BOHR_TO_ANG;
   if(f3)
   	distance = g_strdup_printf("%7.3f",Distance);
   else
   	distance = g_strdup_printf("%f",Distance);
  return distance;
} 
/*************************************************************************************/
gdouble get_module(Point V)
{
   gdouble Module;
   guint i;

   Module = 0.0;
   for(i=0;i<3;i++)
 	Module += V.C[i]*V.C[i];

  return sqrt(Module);
	
}
/*************************************************************************************/
gdouble get_scalaire(Point V1,Point V2)
{
   gdouble Scalaire;
   guint i;

   Scalaire = 0.0;
   for(i=0;i<3;i++)
 	Scalaire += V1.C[i]*V2.C[i];

  return Scalaire;
	
}
/*************************************************************************************/
gchar *get_angle_vectors(Point V1,Point V2)
{
   gchar *angle;
   gdouble Angle;
   gdouble modv1v2 = get_module(V1)*get_module(V2);
 
 
   if(fabs(modv1v2)>1e-14 )
   {
        Angle = get_scalaire(V1,V2)/modv1v2;
/*	Debug("Pscal = %f\n",Angle);*/
	if(Angle<=-1)
        	return g_strdup("180.0");
	if(Angle>=1)
        	return g_strdup_printf("0.0");

        Angle = acos(Angle)/DEG_TO_RAD;
/*	Debug("Angle = %f\n",Angle);*/
        angle = g_strdup_printf("%f",Angle);
   }
   else
        angle = g_strdup_printf("ERROR");   

  return angle;
} 
/*************************************************************************************/
void add_fonts_in_file(FILE *fd,FontsStyle fontsstyle)
{

 if(fontsstyle.fontname[strlen(fontsstyle.fontname)-1] !='\n')
 	fprintf(fd,"%s\n",fontsstyle.fontname);
 else
 	fprintf(fd,"%s",fontsstyle.fontname);

 fprintf(fd,"%d\n",fontsstyle.BaseColor.red);
 fprintf(fd,"%d\n",fontsstyle.BaseColor.green);
 fprintf(fd,"%d\n",fontsstyle.BaseColor.blue);

 fprintf(fd,"%d\n",fontsstyle.TextColor.red);
 fprintf(fd,"%d\n",fontsstyle.TextColor.green);
 fprintf(fd,"%d\n",fontsstyle.TextColor.blue);
}
/*************************************************************************************/
void create_hosts_file()
{
 gchar *hostsfile;
 FILE *fd;
 gint i;
 gint j;
 gint k;

 hostsfile = g_strdup_printf("%s%shosts",gabedit_directory(),G_DIR_SEPARATOR_S);

 fd = FOpen(hostsfile, "w");
 if(fd)
 {
	fprintf(fd,"%d\n",recenthosts.nhosts);
	for(i=0;i<recenthosts.nhosts;i++)
	{
		fprintf(fd,"%s\n",recenthosts.hosts[i].hostname);
		fprintf(fd,"%d\n",recenthosts.hosts[i].nusers);
		for(j=0;j<recenthosts.hosts[i].nusers;j++)
		{
			fprintf(fd,"%s\n",recenthosts.hosts[i].users[j].username);
			fprintf(fd,"%d\n",recenthosts.hosts[i].users[j].ndirs);
			for(k=0;k<recenthosts.hosts[i].users[j].ndirs;k++)
			{
				fprintf(fd,"%s\n",recenthosts.hosts[i].users[j].dirs[k]);
			}
		}
	}
 	fclose(fd);
 }

 g_free(hostsfile);
}
/*************************************************************************************/
void create_fonts_file()
{
 gchar *fontsfile;
 FILE *fd;

 fontsfile = g_strdup_printf("%s%sfonts",gabedit_directory(),G_DIR_SEPARATOR_S);

 fd = FOpen(fontsfile, "w");

 add_fonts_in_file(fd,FontsStyleData);
 add_fonts_in_file(fd,FontsStyleResult);
 add_fonts_in_file(fd,FontsStyleLabel);
 add_fonts_in_file(fd,FontsStyleOther);

 fclose(fd);
 g_free(fontsfile);
}
/*************************************************************************************/
void create_commands_file()
{
	gchar *commandsfile;
	FILE *fd;
	gint i;

	commandsfile = g_strdup_printf("%s%scommands",gabedit_directory(),G_DIR_SEPARATOR_S);

	fd = FOpen(commandsfile, "w");

	fprintf(fd,"Begin Batch\n");

	str_delete_n(NameTypeBatch);
 	fprintf(fd,"%s\n",NameTypeBatch);

	str_delete_n(NameCommandBatchAll);
 	fprintf(fd,"%s\n",NameCommandBatchAll);

	str_delete_n(NameCommandBatchUser);
 	fprintf(fd,"%s\n",NameCommandBatchUser);

	str_delete_n(NameCommandBatchKill);
 	fprintf(fd,"%s\n",NameCommandBatchKill);


	str_delete_n(NamejobIdTitleBatch);
 	fprintf(fd,"%s\n",NamejobIdTitleBatch);

 	fprintf(fd,"%d\n",batchCommands.numberOfTypes);
	for(i=0;i<batchCommands.numberOfTypes;i++)
	{
		str_delete_n(batchCommands.types[i]);
		fprintf(fd,"%s\n",batchCommands.types[i]);
		str_delete_n(batchCommands.commandListAll[i]);
		fprintf(fd,"%s\n",batchCommands.commandListAll[i]);
		str_delete_n(batchCommands.commandListUser[i]);
		fprintf(fd,"%s\n",batchCommands.commandListUser[i]);
		str_delete_n(batchCommands.commandKill[i]);
		fprintf(fd,"%s\n",batchCommands.commandKill[i]);
		str_delete_n(batchCommands.jobIdTitle[i]);
		fprintf(fd,"%s\n",batchCommands.jobIdTitle[i]);
	}
	fprintf(fd,"End\n");
/*-----------------------------------------------------------------------------*/

	fprintf(fd,"Begin Gamess\n");
	str_delete_n(NameCommandGamess);
	delete_last_spaces(NameCommandGamess);
	delete_first_spaces(NameCommandGamess);
 	fprintf(fd,"%s\n",NameCommandGamess);
 	fprintf(fd,"%d\n",gamessCommands.numberOfCommands);
	for(i=0;i<gamessCommands.numberOfCommands;i++)
	{
		str_delete_n(gamessCommands.commands[i]);
		delete_last_spaces(gamessCommands.commands[i]);
		delete_first_spaces(gamessCommands.commands[i]);
		fprintf(fd,"%s\n",gamessCommands.commands[i]);
	}
	fprintf(fd,"End\n");

/*-----------------------------------------------------------------------------*/

	fprintf(fd,"Begin Gaussian\n");
	str_delete_n(NameCommandGaussian);
	delete_last_spaces(NameCommandGaussian);
	delete_first_spaces(NameCommandGaussian);
 	fprintf(fd,"%s\n",NameCommandGaussian);
 	fprintf(fd,"%d\n",gaussianCommands.numberOfCommands);
	for(i=0;i<gaussianCommands.numberOfCommands;i++)
	{
		str_delete_n(gaussianCommands.commands[i]);
		delete_last_spaces(gaussianCommands.commands[i]);
		delete_first_spaces(gaussianCommands.commands[i]);
		fprintf(fd,"%s\n",gaussianCommands.commands[i]);
	}
	fprintf(fd,"End\n");

/*-----------------------------------------------------------------------------*/

	fprintf(fd,"Begin Molcas\n");
	str_delete_n(NameCommandMolcas);
	delete_last_spaces(NameCommandMolcas);
	delete_first_spaces(NameCommandMolcas);
 	fprintf(fd,"%s\n",NameCommandMolcas);
 	fprintf(fd,"%d\n",molcasCommands.numberOfCommands);
	for(i=0;i<molcasCommands.numberOfCommands;i++)
	{
		str_delete_n(molcasCommands.commands[i]);
		delete_last_spaces(molcasCommands.commands[i]);
		delete_first_spaces(molcasCommands.commands[i]);
		fprintf(fd,"%s\n",molcasCommands.commands[i]);
	}
	fprintf(fd,"End\n");
/*-----------------------------------------------------------------------------*/

	fprintf(fd,"Begin Molpro\n");
	str_delete_n(NameCommandMolpro);
	delete_last_spaces(NameCommandMolpro);
	delete_first_spaces(NameCommandMolpro);
 	fprintf(fd,"%s\n",NameCommandMolpro);
 	fprintf(fd,"%d\n",molproCommands.numberOfCommands);
	for(i=0;i<molproCommands.numberOfCommands;i++)
	{
		str_delete_n(molproCommands.commands[i]);
		delete_last_spaces(molproCommands.commands[i]);
		delete_first_spaces(molproCommands.commands[i]);
		fprintf(fd,"%s\n",molproCommands.commands[i]);
	}
	fprintf(fd,"End\n");
/*-----------------------------------------------------------------------------*/

	fprintf(fd,"Begin MPQC\n");
	str_delete_n(NameCommandMPQC);
	delete_last_spaces(NameCommandMPQC);
	delete_first_spaces(NameCommandMPQC);
 	fprintf(fd,"%s\n",NameCommandMPQC);
 	fprintf(fd,"%d\n",mpqcCommands.numberOfCommands);
	for(i=0;i<mpqcCommands.numberOfCommands;i++)
	{
		str_delete_n(mpqcCommands.commands[i]);
		delete_last_spaces(mpqcCommands.commands[i]);
		delete_first_spaces(mpqcCommands.commands[i]);
		fprintf(fd,"%s\n",mpqcCommands.commands[i]);
	}
	fprintf(fd,"End\n");
/*-----------------------------------------------------------------------------*/
	fprintf(fd,"Begin Orca\n");
	str_delete_n(NameCommandOrca);
	delete_last_spaces(NameCommandOrca);
	delete_first_spaces(NameCommandOrca);
 	fprintf(fd,"%s\n",NameCommandOrca);
 	fprintf(fd,"%d\n",orcaCommands.numberOfCommands);
	for(i=0;i<orcaCommands.numberOfCommands;i++)
	{
		str_delete_n(orcaCommands.commands[i]);
		delete_last_spaces(orcaCommands.commands[i]);
		delete_first_spaces(orcaCommands.commands[i]);
		fprintf(fd,"%s\n",orcaCommands.commands[i]);
	}
	fprintf(fd,"End\n");
/*-----------------------------------------------------------------------------*/
	fprintf(fd,"Begin PCGamess\n");
	str_delete_n(NameCommandPCGamess);
	delete_last_spaces(NameCommandPCGamess);
	delete_first_spaces(NameCommandPCGamess);
 	fprintf(fd,"%s\n",NameCommandPCGamess);
 	fprintf(fd,"%d\n",pcgamessCommands.numberOfCommands);
	for(i=0;i<pcgamessCommands.numberOfCommands;i++)
	{
		str_delete_n(pcgamessCommands.commands[i]);
		delete_last_spaces(pcgamessCommands.commands[i]);
		delete_first_spaces(pcgamessCommands.commands[i]);
		fprintf(fd,"%s\n",pcgamessCommands.commands[i]);
	}
	fprintf(fd,"End\n");
/*-----------------------------------------------------------------------------*/
	fprintf(fd,"Begin QChem\n");
	str_delete_n(NameCommandQChem);
	delete_last_spaces(NameCommandQChem);
	delete_first_spaces(NameCommandQChem);
 	fprintf(fd,"%s\n",NameCommandQChem);
 	fprintf(fd,"%d\n",qchemCommands.numberOfCommands);
	for(i=0;i<qchemCommands.numberOfCommands;i++)
	{
		str_delete_n(qchemCommands.commands[i]);
		delete_last_spaces(qchemCommands.commands[i]);
		delete_first_spaces(qchemCommands.commands[i]);
		fprintf(fd,"%s\n",qchemCommands.commands[i]);
	}
	fprintf(fd,"End\n");
/*-----------------------------------------------------------------------------*/
	fprintf(fd,"Begin Mopac\n");
	str_delete_n(NameCommandMopac);
	delete_last_spaces(NameCommandMopac);
	delete_first_spaces(NameCommandMopac);
 	fprintf(fd,"%s\n",NameCommandMopac);
 	fprintf(fd,"%d\n",mopacCommands.numberOfCommands);
	for(i=0;i<mopacCommands.numberOfCommands;i++)
	{
		str_delete_n(mopacCommands.commands[i]);
		delete_last_spaces(mopacCommands.commands[i]);
		delete_first_spaces(mopacCommands.commands[i]);
		fprintf(fd,"%s\n",mopacCommands.commands[i]);
	}
	fprintf(fd,"End\n");
/*-----------------------------------------------------------------------------*/
	fprintf(fd,"Begin PovRay\n");
	str_delete_n(NameCommandPovray);
	delete_last_spaces(NameCommandPovray);
	delete_first_spaces(NameCommandPovray);
 	fprintf(fd,"%s\n",NameCommandPovray);
 	fprintf(fd,"%d\n",povrayCommands.numberOfCommands);
	for(i=0;i<povrayCommands.numberOfCommands;i++)
	{
		str_delete_n(povrayCommands.commands[i]);
		delete_last_spaces(povrayCommands.commands[i]);
		delete_first_spaces(povrayCommands.commands[i]);
		fprintf(fd,"%s\n",povrayCommands.commands[i]);
	}
	fprintf(fd,"End\n");
/*-----------------------------------------------------------------------------*/
	fprintf(fd,"Begin Babel\n");
	str_delete_n(babelCommand);
	delete_last_spaces(babelCommand);
	delete_first_spaces(babelCommand);
	fprintf(fd,"%s\n",babelCommand);
	fprintf(fd,"End\n");

	fprintf(fd,"Begin GamessDir\n");
	str_delete_n(gamessDirectory);
	delete_last_spaces(gamessDirectory);
	delete_first_spaces(gamessDirectory);
	fprintf(fd,"%s\n",gamessDirectory);
	fprintf(fd,"End\n");

	fprintf(fd,"Begin OrcaDir\n");
	str_delete_n(orcaDirectory);
	delete_last_spaces(orcaDirectory);
	delete_first_spaces(orcaDirectory);
	fprintf(fd,"%s\n",orcaDirectory);
	fprintf(fd,"End\n");

	fprintf(fd,"Begin PCGamessDir\n");
	str_delete_n(pcgamessDirectory);
	delete_last_spaces(pcgamessDirectory);
	delete_first_spaces(pcgamessDirectory);
	fprintf(fd,"%s\n",pcgamessDirectory);
	fprintf(fd,"End\n");

	fprintf(fd,"Begin MopacDir\n");
	str_delete_n(mopacDirectory);
	delete_last_spaces(mopacDirectory);
	delete_first_spaces(mopacDirectory);
	fprintf(fd,"%s\n",mopacDirectory);
	fprintf(fd,"End\n");

	fprintf(fd,"Begin GaussDir\n");
	str_delete_n(gaussDirectory);
	delete_last_spaces(gaussDirectory);
	delete_first_spaces(gaussDirectory);
	fprintf(fd,"%s\n",gaussDirectory);
	fprintf(fd,"End\n");

	fprintf(fd,"Begin PovRayDir\n");
	str_delete_n(povrayDirectory);
	delete_last_spaces(povrayDirectory);
	delete_first_spaces(povrayDirectory);
	fprintf(fd,"%s\n",povrayDirectory);
	fprintf(fd,"End\n");

	fclose(fd);

	g_free(commandsfile);
}
/*************************************************************************************/
void create_network_file()
{
 gchar *networkfile;
 FILE *fd;

 networkfile = g_strdup_printf("%s%snetwork",gabedit_directory(),G_DIR_SEPARATOR_S);

 fd = FOpen(networkfile, "w");

 if(defaultNetWorkProtocol == GABEDIT_NETWORK_FTP_RSH) fprintf(fd,"0\n");
 else fprintf(fd,"1\n");

 fprintf(fd,"%s\n",pscpplinkDirectory);
 fclose(fd);

 g_free(networkfile);
}
/*************************************************************************************/
void create_ressource_file()
{
 save_atoms_prop();
 create_commands_file();
 create_network_file();
 create_fonts_file();
 create_color_surfaces_file();
 create_opengl_file();
 save_axis_properties();
 save_principal_axis_properties();
 save_HBonds_properties();
 create_drawmolecule_file();
}
/*************************************************************************************/
void read_hosts_file()
{
 gchar *hostsfile;
 FILE *fd;
 gint i;
 gint j;
 gint k;
 gchar t[BSIZE];
 gint len = BSIZE;

 hostsfile = g_strdup_printf("%s%shosts",gabedit_directory(),G_DIR_SEPARATOR_S);

 fd = FOpen(hostsfile, "r");
 if(fd)
 {
	fgets(t,len,fd);recenthosts.nhosts = atoi(t);
	recenthosts.hosts = g_malloc(recenthosts.nhosts*sizeof(Host));
	for(i=0;i<recenthosts.nhosts;i++)
	{
		filegets(t,fd);recenthosts.hosts[i].hostname = g_strdup(t);
		fgets(t,len,fd);recenthosts.hosts[i].nusers = atoi(t);
		recenthosts.hosts[i].users = g_malloc(recenthosts.hosts[i].nusers*sizeof(User));
		for(j=0;j<recenthosts.hosts[i].nusers;j++)
		{
			filegets(t,fd);
				recenthosts.hosts[i].users[j].username = g_strdup(t);
				recenthosts.hosts[i].users[j].password = NULL;
			fgets(t,len,fd);recenthosts.hosts[i].users[j].ndirs = atoi(t);
			recenthosts.hosts[i].users[j].dirs = g_malloc(recenthosts.hosts[i].users[j].ndirs*sizeof(gchar*));
			for(k=0;k<recenthosts.hosts[i].users[j].ndirs;k++)
			{
				filegets(t,fd);recenthosts.hosts[i].users[j].dirs[k] = g_strdup(t);
			}
		}
	}
 	fclose(fd);
 }

 g_free(hostsfile);
}
/*************************************************************************************/
void read_fonts_in_file(FILE *fd,FontsStyle* fontsstyle)
{
	guint taille = BSIZE;
	gchar *t = NULL;
	gchar *temp = NULL;
	gint i;
	gint k;

	t = g_malloc0(taille*sizeof(gchar));
	temp = g_malloc0(taille*sizeof(gchar));
	fgets(t,taille,fd);
 
	k = 0;
	for(i=0;i<(gint)taille;i++)
	{
		if(t[i] =='\n')
		break;
		temp[k++] = t[i];
	}
	temp[k] = '\0';
	g_strchug(temp);
	g_strchomp(temp);

	fontsstyle->fontname= g_strdup(temp);

	fgets(t,taille,fd);fontsstyle->BaseColor.red =(gushort) atoi(t);
	fgets(t,taille,fd);fontsstyle->BaseColor.green =(gushort)  atoi(t);
	fgets(t,taille,fd);fontsstyle->BaseColor.blue = (gushort) atoi(t);
 
	fgets(t,taille,fd);fontsstyle->TextColor.red = (gushort) atoi(t);
	fgets(t,taille,fd);fontsstyle->TextColor.green = (gushort) atoi(t);
	fgets(t,taille,fd);fontsstyle->TextColor.blue = (gushort) atoi(t);                                                                                          
	g_free(t);
	g_free(temp);
}
/*************************************************************************************/
void read_fonts_file()
{
 gchar *fontsfile;
 FILE *fd;

 fontsfile = g_strdup_printf("%s%sfonts",gabedit_directory(),G_DIR_SEPARATOR_S);

 fd = FOpen(fontsfile, "r");
 if(fd !=NULL)
 {
 	read_fonts_in_file(fd,&FontsStyleData);
 	read_fonts_in_file(fd,&FontsStyleResult);
 	read_fonts_in_file(fd,&FontsStyleLabel);
 	read_fonts_in_file(fd,&FontsStyleOther);
 	fclose(fd);

  	set_font (text,FontsStyleData.fontname);
  	set_base_style(text,FontsStyleData.BaseColor.red ,FontsStyleData.BaseColor.green ,FontsStyleData.BaseColor.blue);
  	set_text_style(text,FontsStyleData.TextColor.red ,FontsStyleData.TextColor.green ,FontsStyleData.TextColor.blue);

  	set_font (textresult,FontsStyleResult.fontname);
  	set_base_style(textresult,FontsStyleResult.BaseColor.red ,FontsStyleResult.BaseColor.green ,FontsStyleResult.BaseColor.blue);
  	set_text_style(textresult,FontsStyleResult.TextColor.red ,FontsStyleResult.TextColor.green ,FontsStyleResult.TextColor.blue);

  	set_font (TextOutput,FontsStyleResult.fontname);
  	set_base_style(TextOutput,FontsStyleResult.BaseColor.red ,FontsStyleResult.BaseColor.green ,FontsStyleResult.BaseColor.blue);
  	set_text_style(TextOutput,FontsStyleResult.TextColor.red ,FontsStyleResult.TextColor.green ,FontsStyleResult.TextColor.blue);

  	set_font (TextError,FontsStyleResult.fontname);
  	set_base_style(TextError,FontsStyleResult.BaseColor.red ,FontsStyleResult.BaseColor.green ,FontsStyleResult.BaseColor.blue);
  	set_text_style(TextError,FontsStyleResult.TextColor.red ,FontsStyleResult.TextColor.green ,FontsStyleResult.TextColor.blue);

 }
 set_font_other (FontsStyleOther.fontname);

}
/********************************************************************************/
void free_batch_commands()
{
	gint i;
	for(i=0;i<batchCommands.numberOfTypes;i++)
	{
		if(batchCommands.types[i])
			g_free(batchCommands.types[i]);
		if(batchCommands.commandListAll[i])
			g_free(batchCommands.commandListAll[i]);
		if(batchCommands.commandListUser[i])
			g_free(batchCommands.commandListUser[i]);
		if(batchCommands.jobIdTitle[i])
			g_free(batchCommands.jobIdTitle[i]);

	}
	if(batchCommands.types)
		g_free(batchCommands.types);
	if(batchCommands.commandListAll)
		g_free(batchCommands.commandListAll);
	if(batchCommands.commandListUser)
		g_free(batchCommands.commandListUser);
	if(batchCommands.jobIdTitle)
		g_free(batchCommands.jobIdTitle);

	if(NameTypeBatch)
		g_free(NameTypeBatch);
	if(NameCommandBatchAll)
		g_free(NameCommandBatchAll);
	if(NameCommandBatchUser)
		g_free(NameCommandBatchUser);
	if(NamejobIdTitleBatch)
		g_free(NamejobIdTitleBatch);
}
/*************************************************************************************/
void read_commands_file()
{
 guint taille = BSIZE;
 gchar t[BSIZE];
 gchar *commandsfile;
 FILE *fd;
 gint i;
 gint k;
 gchar *tmp[4] = {NULL,NULL,NULL,NULL};

 commandsfile = g_strdup_printf("%s%scommands",gabedit_directory(),G_DIR_SEPARATOR_S);

 fd = FOpen(commandsfile, "r");
 if(fd !=NULL)
 {

 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin Batch"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
		free_batch_commands();

 		NameTypeBatch= g_strdup(t);
		str_delete_n(NameTypeBatch);

		for(k=0;k<4;k++)
		if(fgets(t,taille,fd))
		{
			tmp[k] = g_strdup(t);
			str_delete_n(tmp[k]);
		}
		else
		{
			fclose(fd);
			initialise_batch_commands();
			return;
		}

		NameCommandBatchAll  = tmp[0];
		NameCommandBatchUser = tmp[1];
		NameCommandBatchKill = tmp[2];
		NamejobIdTitleBatch  = tmp[3];
	}
	else
	{
		fclose(fd);
		initialise_batch_commands();
		return;
	}


 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		batchCommands.numberOfTypes = atoi(t);
		batchCommands.types = g_malloc(batchCommands.numberOfTypes*sizeof(gchar*));
		batchCommands.commandListAll = g_malloc(batchCommands.numberOfTypes*sizeof(gchar*));
		batchCommands.commandListUser = g_malloc(batchCommands.numberOfTypes*sizeof(gchar*));
		batchCommands.jobIdTitle = g_malloc(batchCommands.numberOfTypes*sizeof(gchar*));

		for(i=0;i<batchCommands.numberOfTypes;i++)
		{
			batchCommands.types[i] = g_strdup(" ");
			batchCommands.commandListAll[i] = g_strdup(" ");
			batchCommands.commandListUser[i] = g_strdup(" ");
			batchCommands.jobIdTitle[i] = g_strdup(" ");
		}
		for(i=0;i<batchCommands.numberOfTypes;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_batch_commands();
				fclose(fd);
				initialise_batch_commands();
				return;
			}
			else
			{

 				batchCommands.types[i]= g_strdup(t);
				str_delete_n(batchCommands.types[i]);
				
				for(k=0;k<4;k++)
				if(!fgets(t,taille,fd) || strstr(t,"End"))
				{
					free_batch_commands();
					fclose(fd);
					initialise_batch_commands();
					return;
				}
				else
				{
					tmp[k] = g_strdup(t);
					str_delete_n(tmp[k]);
				}
				batchCommands.commandListAll[i]  = tmp[0];
				batchCommands.commandListUser[i] = tmp[1];
				batchCommands.commandKill[i] = tmp[2];
				batchCommands.jobIdTitle[i]  = tmp[3];

			}
		}
	}
	else
	{
		fclose(fd);
		initialise_batch_commands();
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of Batch */
	{
		fclose(fd);
		initialise_batch_commands();
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin Gamess"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		NameCommandGamess= g_strdup(t);
		str_delete_n(NameCommandGamess);
		delete_last_spaces(NameCommandGamess);
		delete_first_spaces(NameCommandGamess);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		free_gamess_commands();
		gamessCommands.numberOfCommands = atoi(t);
		gamessCommands.commands = g_malloc(gamessCommands.numberOfCommands*sizeof(gchar*));
		for(i=0;i<gamessCommands.numberOfCommands;i++)
			gamessCommands.commands[i]  = g_strdup(" ");
		for(i=0;i<gamessCommands.numberOfCommands;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_gamess_commands();
  				gamessCommands.numberOfCommands = 1;
  				gamessCommands.numberOfDefaultCommand = 0;
  				gamessCommands.commands = g_malloc(sizeof(gchar*));
  				gamessCommands.commands[0] = g_strdup("nohup g03");

				fclose(fd);
				return;
			}
			else
			{
				gamessCommands.commands[i] = g_strdup(t); 
				str_delete_n(gamessCommands.commands[i]);
				delete_last_spaces(gamessCommands.commands[i]);
				delete_first_spaces(gamessCommands.commands[i]);
			}
		}
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of gamess */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin Gaussian"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		NameCommandGaussian= g_strdup(t);
		str_delete_n(NameCommandGaussian);
		delete_last_spaces(NameCommandGaussian);
		delete_first_spaces(NameCommandGaussian);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		free_gaussian_commands();
		gaussianCommands.numberOfCommands = atoi(t);
		gaussianCommands.commands = g_malloc(gaussianCommands.numberOfCommands*sizeof(gchar*));
		for(i=0;i<gaussianCommands.numberOfCommands;i++)
			gaussianCommands.commands[i]  = g_strdup(" ");
		for(i=0;i<gaussianCommands.numberOfCommands;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_gaussian_commands();
  				gaussianCommands.numberOfCommands = 1;
  				gaussianCommands.numberOfDefaultCommand = 0;
  				gaussianCommands.commands = g_malloc(sizeof(gchar*));
  				gaussianCommands.commands[0] = g_strdup("nohup g03");

				fclose(fd);
				return;
			}
			else
			{
				gaussianCommands.commands[i] = g_strdup(t); 
				str_delete_n(gaussianCommands.commands[i]);
				delete_last_spaces(gaussianCommands.commands[i]);
				delete_first_spaces(gaussianCommands.commands[i]);
			}
		}
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of gaussian */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin Molcas"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		NameCommandMolcas= g_strdup(t);
		str_delete_n(NameCommandMolcas);
		delete_last_spaces(NameCommandMolcas);
		delete_first_spaces(NameCommandMolcas);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		free_molcas_commands();
		molcasCommands.numberOfCommands = atoi(t);
		molcasCommands.commands = g_malloc(molcasCommands.numberOfCommands*sizeof(gchar*));
		for(i=0;i<molcasCommands.numberOfCommands;i++)
			molcasCommands.commands[i]  = g_strdup(" ");
		for(i=0;i<molcasCommands.numberOfCommands;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_molcas_commands();
  				molcasCommands.numberOfCommands = 1;
  				molcasCommands.numberOfDefaultCommand = 0;
  				molcasCommands.commands = g_malloc(sizeof(gchar*));
  				molcasCommands.commands[0] = g_strdup("nohup g03");

				fclose(fd);
				return;
			}
			else
			{
				molcasCommands.commands[i] = g_strdup(t); 
				str_delete_n(molcasCommands.commands[i]);
				delete_last_spaces(molcasCommands.commands[i]);
				delete_first_spaces(molcasCommands.commands[i]);
			}
		}
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of Molcas */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin Molpro"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		NameCommandMolpro= g_strdup(t);
		str_delete_n(NameCommandMolpro);
		delete_last_spaces(NameCommandMolpro);
		delete_first_spaces(NameCommandMolpro);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		free_molpro_commands();
		molproCommands.numberOfCommands = atoi(t);
		molproCommands.commands = g_malloc(molproCommands.numberOfCommands*sizeof(gchar*));
		for(i=0;i<molproCommands.numberOfCommands;i++)
			molproCommands.commands[i]  = g_strdup(" ");
		for(i=0;i<molproCommands.numberOfCommands;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_molpro_commands();
  				molproCommands.numberOfCommands = 1;
  				molproCommands.numberOfDefaultCommand = 0;
  				molproCommands.commands = g_malloc(sizeof(gchar*));
  				molproCommands.commands[0] = g_strdup("nohup g03");

				fclose(fd);
				return;
			}
			else
			{
				molproCommands.commands[i] = g_strdup(t); 
				str_delete_n(molproCommands.commands[i]);
				delete_last_spaces(molproCommands.commands[i]);
				delete_first_spaces(molproCommands.commands[i]);
			}
		}
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of Molpro */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin MPQC"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		NameCommandMPQC= g_strdup(t);
		str_delete_n(NameCommandMPQC);
		delete_last_spaces(NameCommandMPQC);
		delete_first_spaces(NameCommandMPQC);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		free_mpqc_commands();
		mpqcCommands.numberOfCommands = atoi(t);
		mpqcCommands.commands = g_malloc(mpqcCommands.numberOfCommands*sizeof(gchar*));
		for(i=0;i<mpqcCommands.numberOfCommands;i++)
			mpqcCommands.commands[i]  = g_strdup(" ");
		for(i=0;i<mpqcCommands.numberOfCommands;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_mpqc_commands();
  				mpqcCommands.numberOfCommands = 1;
  				mpqcCommands.numberOfDefaultCommand = 0;
  				mpqcCommands.commands = g_malloc(sizeof(gchar*));
  				mpqcCommands.commands[0] = g_strdup("nohup mpqc");

				fclose(fd);
				return;
			}
			else
			{
				mpqcCommands.commands[i] = g_strdup(t); 
				str_delete_n(mpqcCommands.commands[i]);
				delete_last_spaces(mpqcCommands.commands[i]);
				delete_first_spaces(mpqcCommands.commands[i]);
			}
		}
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of MPQC */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin Orca"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		NameCommandOrca= g_strdup(t);
		str_delete_n(NameCommandOrca);
		delete_last_spaces(NameCommandOrca);
		delete_first_spaces(NameCommandOrca);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		free_orca_commands();
		orcaCommands.numberOfCommands = atoi(t);
		orcaCommands.commands = g_malloc(orcaCommands.numberOfCommands*sizeof(gchar*));
		for(i=0;i<orcaCommands.numberOfCommands;i++)
			orcaCommands.commands[i]  = g_strdup(" ");
		for(i=0;i<orcaCommands.numberOfCommands;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_orca_commands();
  				orcaCommands.numberOfCommands = 1;
  				orcaCommands.numberOfDefaultCommand = 0;
  				orcaCommands.commands = g_malloc(sizeof(gchar*));
  				orcaCommands.commands[0] = g_strdup("nohup orca");

				fclose(fd);
				return;
			}
			else
			{
				orcaCommands.commands[i] = g_strdup(t); 
				str_delete_n(orcaCommands.commands[i]);
				delete_last_spaces(orcaCommands.commands[i]);
				delete_first_spaces(orcaCommands.commands[i]);
			}
		}
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of Orca */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin PCGamess"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		NameCommandPCGamess= g_strdup(t);
		str_delete_n(NameCommandPCGamess);
		delete_last_spaces(NameCommandPCGamess);
		delete_first_spaces(NameCommandPCGamess);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		free_pcgamess_commands();
		pcgamessCommands.numberOfCommands = atoi(t);
		pcgamessCommands.commands = g_malloc(pcgamessCommands.numberOfCommands*sizeof(gchar*));
		for(i=0;i<pcgamessCommands.numberOfCommands;i++)
			pcgamessCommands.commands[i]  = g_strdup(" ");
		for(i=0;i<pcgamessCommands.numberOfCommands;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_pcgamess_commands();
  				pcgamessCommands.numberOfCommands = 1;
  				pcgamessCommands.numberOfDefaultCommand = 0;
  				pcgamessCommands.commands = g_malloc(sizeof(gchar*));
  				pcgamessCommands.commands[0] = g_strdup("nohup pcgamess");

				fclose(fd);
				return;
			}
			else
			{
				pcgamessCommands.commands[i] = g_strdup(t); 
				str_delete_n(pcgamessCommands.commands[i]);
				delete_last_spaces(pcgamessCommands.commands[i]);
				delete_first_spaces(pcgamessCommands.commands[i]);
			}
		}
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of PCGamess */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin QChem"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		NameCommandQChem= g_strdup(t);
		str_delete_n(NameCommandQChem);
		delete_last_spaces(NameCommandQChem);
		delete_first_spaces(NameCommandQChem);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		free_qchem_commands();
		qchemCommands.numberOfCommands = atoi(t);
		qchemCommands.commands = g_malloc(qchemCommands.numberOfCommands*sizeof(gchar*));
		for(i=0;i<qchemCommands.numberOfCommands;i++)
			qchemCommands.commands[i]  = g_strdup(" ");
		for(i=0;i<qchemCommands.numberOfCommands;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_qchem_commands();
  				qchemCommands.numberOfCommands = 1;
  				qchemCommands.numberOfDefaultCommand = 0;
  				qchemCommands.commands = g_malloc(sizeof(gchar*));
  				qchemCommands.commands[0] = g_strdup("nohup qchem");

				fclose(fd);
				return;
			}
			else
			{
				qchemCommands.commands[i] = g_strdup(t); 
				str_delete_n(qchemCommands.commands[i]);
				delete_last_spaces(qchemCommands.commands[i]);
				delete_first_spaces(qchemCommands.commands[i]);
			}
		}
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of QChem */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin Mopac"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		NameCommandMopac= g_strdup(t);
		str_delete_n(NameCommandMopac);
		delete_last_spaces(NameCommandMopac);
		delete_first_spaces(NameCommandMopac);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		free_mopac_commands();
		mopacCommands.numberOfCommands = atoi(t);
		mopacCommands.commands = g_malloc(mopacCommands.numberOfCommands*sizeof(gchar*));
		for(i=0;i<mopacCommands.numberOfCommands;i++)
			mopacCommands.commands[i]  = g_strdup(" ");
		for(i=0;i<mopacCommands.numberOfCommands;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_mopac_commands();
  				mopacCommands.numberOfCommands = 1;
  				mopacCommands.numberOfDefaultCommand = 0;
  				mopacCommands.commands = g_malloc(sizeof(gchar*));
  				mopacCommands.commands[0] = g_strdup("nohup mopac");

				fclose(fd);
				return;
			}
			else
			{
				mopacCommands.commands[i] = g_strdup(t); 
				str_delete_n(mopacCommands.commands[i]);
				delete_last_spaces(mopacCommands.commands[i]);
				delete_first_spaces(mopacCommands.commands[i]);
			}
		}
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of Mopac */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin PovRay"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		NameCommandPovray= g_strdup(t);
		str_delete_n(NameCommandPovray);
		delete_last_spaces(NameCommandPovray);
		delete_first_spaces(NameCommandPovray);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd) && atoi(t)>0)
	{
		free_povray_commands();
		povrayCommands.numberOfCommands = atoi(t);
		povrayCommands.commands = g_malloc(povrayCommands.numberOfCommands*sizeof(gchar*));
		for(i=0;i<povrayCommands.numberOfCommands;i++)
			povrayCommands.commands[i]  = g_strdup(" ");
		for(i=0;i<povrayCommands.numberOfCommands;i++)
		{
			if(!fgets(t,taille,fd) || strstr(t,"End"))
			{
				free_povray_commands();
  				povrayCommands.numberOfCommands = 1;
  				povrayCommands.numberOfDefaultCommand = 0;
  				povrayCommands.commands = g_malloc(sizeof(gchar*));
  				povrayCommands.commands[0] = g_strdup("povray +A0.3 -UV");

				fclose(fd);
				return;
			}
			else
			{
				povrayCommands.commands[i] = g_strdup(t); 
				str_delete_n(povrayCommands.commands[i]);
				delete_last_spaces(povrayCommands.commands[i]);
				delete_first_spaces(povrayCommands.commands[i]);
			}
		}
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of PovRay */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin Babel"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		babelCommand= g_strdup(t);
		str_delete_n(babelCommand);
		delete_last_spaces(babelCommand);
		delete_first_spaces(babelCommand);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of Babel */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin GamessDir"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		gamessDirectory= g_strdup(t);
		str_delete_n(gamessDirectory);
		delete_last_spaces(gamessDirectory);
		delete_first_spaces(gamessDirectory);
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of GamessDir */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin OrcaDir"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		orcaDirectory= g_strdup(t);
		str_delete_n(orcaDirectory);
		delete_last_spaces(orcaDirectory);
		delete_first_spaces(orcaDirectory);
#ifdef G_OS_WIN32
		{
		gchar t[BSIZE];
		sprintf(t,"%s;%cPATH%c",orcaDirectory,'%','%');
		if(strlen(t)>1) g_setenv("PATH",t,TRUE);
		}
#endif
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of OrcaDir */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin PCGamessDir"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		pcgamessDirectory= g_strdup(t);
		str_delete_n(pcgamessDirectory);
		delete_last_spaces(pcgamessDirectory);
		delete_first_spaces(pcgamessDirectory);
#ifdef G_OS_WIN32
		{
		gchar t[BSIZE];
		sprintf(t,"%s;%cPATH%c",pcgamessDirectory,'%','%');
		if(strlen(t)>1) g_setenv("PATH",t,TRUE);
		}
#endif
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of PCGamessDir */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin MopacDir"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		mopacDirectory= g_strdup(t);
		str_delete_n(mopacDirectory);
		delete_last_spaces(mopacDirectory);
		delete_first_spaces(mopacDirectory);
#ifdef G_OS_WIN32
		{
		gchar t[BSIZE];
		sprintf(t,"%s;%cPATH%c",mopacDirectory,'%','%');
		if(strlen(t)>1) g_setenv("PATH",t,TRUE);
		}
#endif
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of MopacDir */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin GaussDir"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		gaussDirectory= g_strdup(t);
		str_delete_n(gaussDirectory);
		delete_last_spaces(gaussDirectory);
		delete_first_spaces(gaussDirectory);
#ifdef G_OS_WIN32
		{
		gchar t[BSIZE];
		sprintf(t,"%s;%cPATH%c",gaussDirectory,'%','%');
		if(strlen(t)>1) g_setenv("PATH",t,TRUE);
		}
#endif
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of GaussDir */
	{
		fclose(fd);
		return;
	}
/*-----------------------------------------------------------------------------*/
 	if(fgets(t,taille,fd))
	if(!strstr(t,"Begin PovRayDir"))
	{
		fclose(fd);
		return;
	}
 	if(fgets(t,taille,fd))
	{
 		povrayDirectory= g_strdup(t);
		str_delete_n(povrayDirectory);
		delete_last_spaces(povrayDirectory);
		delete_first_spaces(povrayDirectory);
#ifdef G_OS_WIN32
		{
		gchar t[BSIZE];
		sprintf(t,"%s;%cPATH%c",povrayDirectory,'%','%');
		if(strlen(t)>1) g_setenv("PATH",t,TRUE);
		}
#endif
	}
	else
	{
		fclose(fd);
		return;
	}
 	if(!fgets(t,taille,fd)) /* End of PovRayDir */
	{
		fclose(fd);
		return;
	}
 	fclose(fd);
 }
}
/*************************************************************************************/
void read_network_file()
{
 gchar *networkfile;
 FILE *fd;

 networkfile = g_strdup_printf("%s%snetwork",gabedit_directory(),G_DIR_SEPARATOR_S);

 fd = FOpen(networkfile, "r");
 if(fd !=NULL)
 {
 	guint taille = BSIZE;
 	gchar t[BSIZE];
	gint i;
 	if(fgets(t,taille,fd))
	{
		if(sscanf(t,"%d",&i)!=1)
			defaultNetWorkProtocol = GABEDIT_NETWORK_SSH;
		else
		{
 			if(i==0) 
				defaultNetWorkProtocol = GABEDIT_NETWORK_FTP_RSH;
 			else 
				defaultNetWorkProtocol = GABEDIT_NETWORK_SSH;
		}
	}
	else
		defaultNetWorkProtocol = GABEDIT_NETWORK_SSH;

 	if(fgets(t,taille,fd))
	{
		if(pscpplinkDirectory)
			g_free(pscpplinkDirectory);
		pscpplinkDirectory = g_strdup(t);
		
		str_delete_n(pscpplinkDirectory);
		delete_last_spaces(pscpplinkDirectory);
		delete_first_spaces(pscpplinkDirectory);
		sprintf(t,"%s;%cPATH%c",pscpplinkDirectory,'%','%');
#ifdef G_OS_WIN32
		g_setenv("PATH",t,TRUE);
#endif
	}
 	fclose(fd);
 }
}
/***********************************************************************/
void set_path()
{
#ifdef G_OS_WIN32
	{
		gchar t[BSIZE];
		sprintf(t,"%s;%s;%s;%s;%s;%s;%cPATH%c",
		orcaDirectory,
		pcgamessDirectory,
		mopacDirectory,
		gaussDirectory,
		pscpplinkDirectory,
		povrayDirectory,
		'%','%');
		if(strlen(t)>1) g_setenv("PATH",t,TRUE);
	}
#endif
}
/*************************************************************************************/
void read_ressource_file()
{
 gboolean rOK = FALSE;
 
 define_default_atoms_prop();
 rOK = read_atoms_prop();
 if(!rOK)
 	define_default_atoms_prop();
 read_commands_file();
 read_network_file();
 read_fonts_file();
 read_hosts_file();
 read_color_surfaces_file();
 read_opengl_file();
 fileopen.netWorkProtocol= defaultNetWorkProtocol;
 read_axis_properties();
 read_principal_axis_properties();
 read_HBonds_properties();
 read_drawmolecule_file();
}
/*************************************************************************************/
gchar *ang_to_bohr(gchar *angstr)
{
        gchar *austr;
        gdouble numb;
       
        austr = g_strdup(angstr);
        numb = atof(angstr)*ANG_TO_BOHR;
        austr = g_strdup_printf("%f",numb);
	return austr;
}
/*************************************************************************************/
gchar *bohr_to_ang(gchar *angstr)
{
        gchar *austr;
        gdouble numb;
       
        austr = g_strdup(angstr);
        numb = atof(angstr)*BOHR_TO_ANG;
        austr = g_strdup_printf("%f",numb);
	return austr;
}
/*************************************************************************************/
static gboolean debug1flag()
{
   gchar localhost[100];
   if(!Debug1Flag) return FALSE;

#ifdef G_OS_WIN32
   winsockCheck(stderr);
#endif
   gethostname(localhost,100);
   if(strlen(localhost)>=5)
   {
	   g_strup(localhost);
	   gchar* d = strstr(localhost,"L");
	   if(!d) return FALSE;
   	   if(strlen(d)<5) return FALSE;
	   if(d[0]=='L' && d[1]=='A')
	   if(d[2]=='S' && d[3]=='I')
	   if(d[4]=='M') return TRUE;
   }
   return FALSE;
}
/*************************************************************************************/
guint get_number_electrons(guint type)
{
/* 
   type = 1 : Medium and High
   type = 2 : High
   type = other : All
*/
   guint i;
   guint Ne=0;
   SAtomsProp Atom;
   if(MethodeGeom == GEOM_IS_XYZ)
   {
   	for(i=0;i<NcentersXYZ;i++)
   	{
	       Atom = prop_atom_get(GeomXYZ[i].Symb);
               switch (type)
               {
        	case 1 : if(this_is_a_backspace (GeomXYZ[i].Layer) || 
			    !strcmp(GeomXYZ[i].Layer,"High") ||
			    !strcmp(GeomXYZ[i].Layer,"Medium") )
				Ne += Atom.atomicNumber;
			 break;
        	case 2 : if(this_is_a_backspace (GeomXYZ[i].Layer) || 
			    !strcmp(GeomXYZ[i].Layer,"High") )
				 {
				Ne += Atom.atomicNumber;
				 }
			 break;
        	default : Ne += Atom.atomicNumber;
               }
   	}
   }
   if(MethodeGeom == GEOM_IS_ZMAT)
   {
   	for(i=0;i<NcentersZmat;i++)
   	{
		Atom = prop_atom_get(Geom[i].Symb);
               switch (type)
               {
        	case 1 : if(this_is_a_backspace (Geom[i].Layer) || 
			    !strcmp(Geom[i].Layer,"High") ||
			    !strcmp(Geom[i].Layer,"Medium") )
				Ne += Atom.atomicNumber;
			 break;
        	case 2 : if(this_is_a_backspace (Geom[i].Layer) || 
			    !strcmp(Geom[i].Layer,"High") )
		        	 Ne += Atom.atomicNumber;
			 break;
        	default : Ne += Atom.atomicNumber;
               }
   	}
   }
   return Ne;
} 
/*************************************************************************************/
gdouble get_value_variableZmat(gchar *NameV)
{
   guint i;
   for(i=0;i<NVariables;i++)
 	if (!strcmp((char*)NameV, Variables[i].Name))
		return atof(Variables[i].Value);
	
  return 0.0;
} 
/*************************************************************************************/
gdouble get_value_variableXYZ(gchar *NameV)
{
   guint i;
   for(i=0;i<NVariablesXYZ;i++)
 	if (!strcmp((char*)NameV, VariablesXYZ[i].Name))
		return atof(VariablesXYZ[i].Value);
	
  return 0.0;
} 
/*************************************************************************************/
guint get_num_variableXYZ(gchar *NameV)
{
   guint i;
   for(i=0;i<NVariablesXYZ;i++)
 	if (!strcmp((char*)NameV, VariablesXYZ[i].Name))
		return i;
	
  return 0;
} 
/*************************************************************************************/
guint get_num_variableZmat(gchar *NameV)
{
   guint i;
   for(i=0;i<NVariables;i++)
 	if (!strcmp((char*)NameV, Variables[i].Name))
		return i;
	
  return 0;
} 
/*************************************************************************************/
gboolean geometry_with_medium_layer()
{

   gint i;

   if(debug1flag()) return FALSE;

   if(MethodeGeom == GEOM_IS_XYZ)
   {
   	for(i=0;i<NcentersXYZ;i++)
		if(strstr(GeomXYZ[i].Layer,"Med") ) return TRUE;
   }
   else if(MethodeGeom == GEOM_IS_ZMAT)
   {
   	for(i=0;i<NcentersZmat;i++)
		if(strstr(Geom[i].Layer,"Med") ) return TRUE;
   }
   return FALSE;
} 
/*************************************************************************************/
gboolean geometry_with_lower_layer()
{
   gint i;

   if(debug1flag()) return FALSE;

   if(MethodeGeom == GEOM_IS_XYZ)
   {
   	for(i=0;i<NcentersXYZ;i++)
		if(strstr(GeomXYZ[i].Layer,"Lo") ) return TRUE;
   }
   else if(MethodeGeom == GEOM_IS_ZMAT)
   {
   	for(i=0;i<NcentersZmat;i++)
		if(strstr(Geom[i].Layer,"Lo") ) return TRUE;
   }
   return FALSE;
} 
/*************************************************************************************/
void uppercase(gchar *str)
{
  while( *str != '\0')
  {
    if (isalpha((gint)*str))
      if (islower((gint)*str))
        *str = toupper((gint)*str);
    str ++;
  }
}
/*************************************************************************************/
void lowercase(gchar *str)
{
  while( *str != '\0')
  {
    *str = (gchar)tolower((gint)*str);
    str ++;
  }
}
/*************************************************************************************/
void initialise_fonts_style()
{
#ifdef G_OS_WIN32
        FontsStyleData.fontname = g_strdup("courier 12");
        FontsStyleResult.fontname = g_strdup("courier 12");
	FontsStyleOther.fontname = g_strdup("sans 12");
	{
  		PangoFontDescription *font_desc;
  		font_desc = pango_font_description_from_string (FontsStyleOther.fontname);
		if(!font_desc)
		{
			g_free(FontsStyleOther.fontname);
			FontsStyleOther.fontname = g_strdup("sans 12");
  			font_desc = pango_font_description_from_string (FontsStyleOther.fontname);
			if(!font_desc)
			{
				g_free(FontsStyleOther.fontname );
				FontsStyleOther.fontname = g_strdup("helvetica 12");
			}
			/*
			else
			pango_font_description_free (font_desc);
			*/
			
		}
		/*
		else
		pango_font_description_free (font_desc);
		*/
	}

	FontsStyleLabel.fontname=g_strdup("sans bold 12");

#else
        FontsStyleData.fontname = g_strdup("courier 14");
        FontsStyleResult.fontname = g_strdup("courier bold 12");
	FontsStyleOther.fontname = g_strdup("helvetica 12");
	FontsStyleLabel.fontname=g_strdup("times bold 14");
#endif

        FontsStyleData.BaseColor.red  = 65535;
        FontsStyleData.BaseColor.green  = 65535;
        FontsStyleData.BaseColor.blue  = 65535;

        FontsStyleData.TextColor.red  = 0;
        FontsStyleData.TextColor.green  = 0;
        FontsStyleData.TextColor.blue  = 0;

        FontsStyleResult.BaseColor.red  = 58980;
        FontsStyleResult.BaseColor.green  = 58980;
        FontsStyleResult.BaseColor.blue  = 58980;

        FontsStyleResult.TextColor.red  = 32768;
        FontsStyleResult.TextColor.green  = 0;
        FontsStyleResult.TextColor.blue  = 0;

        FontsStyleLabel.BaseColor.red  = 0;
        FontsStyleLabel.BaseColor.green  = 0;
        FontsStyleLabel.BaseColor.blue  = 0;

        FontsStyleLabel.TextColor.red  = 65535;
        FontsStyleLabel.TextColor.green  = 65535;
        FontsStyleLabel.TextColor.blue  = 65535;

	FontsStyleOther.BaseColor.red  = 58980;
        FontsStyleOther.BaseColor.green  = 58980;
        FontsStyleOther.BaseColor.blue  = 58980;

        FontsStyleOther.TextColor.red  = 32768;
        FontsStyleOther.TextColor.green  = 0;
        FontsStyleOther.TextColor.blue  = 0;
}
/*************************************************************************************/
void reset_name_files()
{
	if(fileopen.projectname) g_free(fileopen.projectname);
	if(fileopen.datafile) g_free(fileopen.datafile);
	if(fileopen.outputfile) g_free(fileopen.outputfile);
	if(fileopen.logfile) g_free(fileopen.logfile);
	if(fileopen.moldenfile) g_free(fileopen.moldenfile);
	if(fileopen.remotehost) g_free(fileopen.remotehost);
	if(fileopen.remoteuser) g_free(fileopen.remoteuser);
	if(fileopen.remotepass) g_free(fileopen.remotepass);
	if(fileopen.remotedir) g_free(fileopen.remotedir);

	fileopen.projectname=g_strdup("NoName");
	fileopen.datafile=g_strdup("NoName");
	fileopen.outputfile=g_strdup("Unknown");
	fileopen.logfile=g_strdup("Unknown");
	fileopen.moldenfile=g_strdup("Unknown");
	fileopen.remotehost=g_strdup("");
	fileopen.remoteuser=g_strdup("");
	fileopen.remotepass=g_strdup("");
	fileopen.remotedir=g_strdup("");
	fileopen.netWorkProtocol= defaultNetWorkProtocol;
}
/*************************************************************************************/
void initialise_name_file()
{
	fileopen.projectname=g_strdup("NoName");
	fileopen.datafile=g_strdup("NoName");
	fileopen.outputfile=g_strdup("Unknown");
	fileopen.logfile=g_strdup("Unknown");
	fileopen.moldenfile=g_strdup("Unknown");
	fileopen.remotehost=g_strdup("");
	fileopen.remoteuser=g_strdup("");
	fileopen.remotepass=g_strdup("");
	fileopen.remotedir=g_strdup("");
	fileopen.netWorkProtocol= defaultNetWorkProtocol;
}
/*************************************************************************************/
void initialise_name_commands()
{
#ifdef G_OS_WIN32
	gchar t[BSIZE];
	NameCommandGamess=g_strdup("submitGMS");
	NameCommandGaussian=g_strdup("g03.exe");
	NameCommandMolcas=g_strdup("molcas");
	NameCommandMolpro=g_strdup("molpro");
	NameCommandMPQC=g_strdup("mpqc");
	NameCommandPCGamess=g_strdup("pcgamess");
	NameCommandQChem=g_strdup("qc");
	NameCommandOrca=g_strdup("orca");
	NameCommandMopac=g_strdup("MOPAC2007");
	NameCommandPovray=g_strdup("start /w pvengine /nr /exit /render +A0.3 -UV");
#else
	NameCommandGamess=g_strdup("submitGMS");
	NameCommandGaussian=g_strdup("nohup g03");
	NameCommandMolcas=g_strdup("nohup molcas");
	NameCommandMolpro=g_strdup("nohup molpro");
	NameCommandMPQC=g_strdup("nohup mpqc");
	NameCommandPCGamess=g_strdup("pcgamess");
	NameCommandQChem=g_strdup("qchem");
	NameCommandOrca=g_strdup("orca");
	NameCommandMopac=g_strdup("/opt/mopac/MOPAC2007.out");
	NameCommandPovray=g_strdup("povray +A0.3 -UV");
#endif


#ifdef G_OS_WIN32
	babelCommand = g_strdup_printf("%s%sobabel.exe",g_get_current_dir(),G_DIR_SEPARATOR_S);
	gamessDirectory= g_strdup_printf("C:%sWinGAMESS",G_DIR_SEPARATOR_S);
	orcaDirectory= g_strdup_printf("C:%sORCA_DevCenter%sorca%sx86_exe%srelease%sOrca",G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
	pcgamessDirectory= g_strdup_printf("C:%sPCGAMESS",G_DIR_SEPARATOR_S);
	mopacDirectory= g_strdup_printf("\"C:%sProgram Files%sMOPAC\"",G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
	povrayDirectory= g_strdup_printf("\"C:%sProgram Files%sPovRay%sbin\"",G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
	gaussDirectory= g_strdup_printf("\"C:%sG03W\"",G_DIR_SEPARATOR_S);
	sprintf(t,"%s;%s;%s;%s;%s;%cPATH%c",orcaDirectory,pcgamessDirectory,mopacDirectory,gaussDirectory,povrayDirectory,'%','%');
	g_setenv("PATH",t,TRUE);
#else
	babelCommand=g_strdup("babel");
	gamessDirectory= g_strdup_printf("%s%sGamess",g_get_home_dir(),G_DIR_SEPARATOR_S);
	orcaDirectory= g_strdup_printf("%s%sOrca",g_get_home_dir(),G_DIR_SEPARATOR_S);
	pcgamessDirectory= g_strdup_printf("%s%sPCGamess",g_get_home_dir(),G_DIR_SEPARATOR_S);
	mopacDirectory= g_strdup_printf("/opt/mopac");
	povrayDirectory= g_strdup_printf("/usr/local/bin");
#endif
}
/*************************************************************************************/
void initialise_batch_commands()
{

	batchCommands.numberOfTypes = 4;
	batchCommands.types = g_malloc(batchCommands.numberOfTypes*sizeof(gchar*));
	batchCommands.types[0] = g_strdup("LSF");
	batchCommands.types[1] = g_strdup("LoadLeveler");
	batchCommands.types[2] = g_strdup("PBS");
	batchCommands.types[3] = g_strdup("Other");

	batchCommands.commandListAll = g_malloc(batchCommands.numberOfTypes*sizeof(gchar*));
	batchCommands.commandListAll[0] = g_strdup("bjobs -u all");
	batchCommands.commandListAll[1] = g_strdup("llq");
	batchCommands.commandListAll[2] = g_strdup("qstat -a");
	batchCommands.commandListAll[3] = g_strdup("ps -ef");

	batchCommands.commandListUser = g_malloc(batchCommands.numberOfTypes*sizeof(gchar*));
	batchCommands.commandListUser[0] = g_strdup("bjobs -u ");
	batchCommands.commandListUser[1] = g_strdup("llq -u ");
	batchCommands.commandListUser[2] = g_strdup("qstat ");
	batchCommands.commandListUser[3] = g_strdup("ps -fu");

	batchCommands.commandKill = g_malloc(batchCommands.numberOfTypes*sizeof(gchar*));
	batchCommands.commandKill[0] = g_strdup("bkill ");
	batchCommands.commandKill[1] = g_strdup("llcancel ");
	batchCommands.commandKill[2] = g_strdup("qdel ");
	batchCommands.commandKill[3] = g_strdup("kill ");

	batchCommands.jobIdTitle = g_malloc(batchCommands.numberOfTypes*sizeof(gchar*));
	batchCommands.jobIdTitle[0] = g_strdup("JOBID");
	batchCommands.jobIdTitle[1] = g_strdup("Id");
	batchCommands.jobIdTitle[2] = g_strdup("Job");
	batchCommands.jobIdTitle[3] = g_strdup("PID");

	NameTypeBatch = g_strdup(batchCommands.types[0]);
	NameCommandBatchAll = g_strdup(batchCommands.commandListAll[0]);
	NameCommandBatchUser = g_strdup(batchCommands.commandListUser[0]);
	NameCommandBatchKill = g_strdup(batchCommands.commandKill[0]);
	NamejobIdTitleBatch = g_strdup(batchCommands.jobIdTitle[0]);

}
/*************************************************************************************/
void initialise_global_variables()
{
  gint i;
  for(i=0;i<3;i++)
  {
 	TotalCharges[i] = 0;
  	SpinMultiplicities[i] = 1;
  }

  ResultEntryPass = NULL;
  ZoneDessin = NULL;
  FrameWins = NULL;
  FrameList = NULL;
  Hpaned  = NULL;


  GeomXYZ = NULL;
  Geom = NULL;
  MesureIsHide = TRUE;
  VariablesXYZ = NULL;
  Variables = NULL;
  NcentersXYZ =0;
  NcentersZmat =0;
  NVariablesXYZ = 0;
  NVariables    = 0;
  Nelectrons = 0;
  GeomIsOpen = FALSE;
  iprogram = PROG_IS_OTHER;
  Units = 1;
  NSA = -1;
  ScreenWidth = gdk_screen_width();
  ScreenHeight = gdk_screen_height();
  GeomConvIsOpen = FALSE;
  recenthosts.nhosts = 0;
  recenthosts.hosts = NULL;
  defaultNetWorkProtocol = GABEDIT_NETWORK_SSH;
  initialise_name_file();
  set_file_open(NULL,NULL,NULL, defaultNetWorkProtocol);
  initialise_name_commands();
  initialise_fonts_style();
  lastdirectory = g_strdup_printf("%s", g_get_current_dir());
  pscpCommand = g_strdup_printf("pscp.exe");
  plinkCommand = g_strdup_printf("plink.exe");
  pscpplinkDirectory = g_strdup_printf("%s",g_get_current_dir());

#ifdef G_OS_WIN32
  {
	gchar* t = g_strdup_printf("%s;%cPATH%c",pscpplinkDirectory,'%','%');
	g_setenv("PATH",t,TRUE);
	g_free(t);
  }
#endif

  gamessCommands.numberOfCommands = 2;
  gamessCommands.numberOfDefaultCommand = 0;
  gamessCommands.commands = g_malloc(gamessCommands.numberOfCommands*sizeof(gchar*));
  gamessCommands.commands[0] = g_strdup("submitGMS");
  gamessCommands.commands[1] = g_strdup("submitGamess 1:0:0");

  gaussianCommands.numberOfCommands = 2;
#ifdef G_OS_WIN32
  gaussianCommands.numberOfCommands = 3;
#endif
  gaussianCommands.numberOfDefaultCommand = 0;
  gaussianCommands.commands = g_malloc(gaussianCommands.numberOfCommands*sizeof(gchar*));
  gaussianCommands.commands[0] = g_strdup("nohup g03");
  gaussianCommands.commands[1] = g_strdup("submitGaussian 1:0:0");
#ifdef G_OS_WIN32
    gaussianCommands.commands[2] = g_strdup("g03.exe");
#endif


  molcasCommands.numberOfCommands = 2;
#ifdef G_OS_WIN32
    molcasCommands.numberOfCommands = 3;
#endif
  molcasCommands.numberOfDefaultCommand = 0;
  molcasCommands.commands = g_malloc(molcasCommands.numberOfCommands*sizeof(gchar*));
  molcasCommands.commands[0] = g_strdup("nohup molcas");
  molcasCommands.commands[1] = g_strdup("submitMolcas 1:0:0");
#ifdef G_OS_WIN32
  molcasCommands.commands[2] = g_strdup("molcas");
#endif

  molproCommands.numberOfCommands = 2;
#ifdef G_OS_WIN32
      molproCommands.numberOfCommands = 3;
#endif

  molproCommands.numberOfDefaultCommand = 0;
  molproCommands.commands = g_malloc(molproCommands.numberOfCommands*sizeof(gchar*));
  molproCommands.commands[0] = g_strdup("nohup molpro");
  molproCommands.commands[1] = g_strdup("submitMolpro 1:0:0");
#ifdef G_OS_WIN32
  molproCommands.commands[2] = g_strdup("molpro");
#endif

	mpqcCommands.numberOfCommands = 2;
#ifdef G_OS_WIN32
      mpqcCommands.numberOfCommands = 3;
#endif

  mpqcCommands.numberOfDefaultCommand = 0;
  mpqcCommands.commands = g_malloc(mpqcCommands.numberOfCommands*sizeof(gchar*));
  mpqcCommands.commands[0] = g_strdup("nohup mpqc");
  mpqcCommands.commands[1] = g_strdup("submitMPQC 1:0:0");
#ifdef G_OS_WIN32
  mpqcCommands.commands[2] = g_strdup("mpqc");
#endif

	orcaCommands.numberOfCommands = 2;
#ifdef G_OS_WIN32
      orcaCommands.numberOfCommands = 3;
#endif

  orcaCommands.numberOfDefaultCommand = 0;
  orcaCommands.commands = g_malloc(orcaCommands.numberOfCommands*sizeof(gchar*));
  orcaCommands.commands[0] = g_strdup("nohup orca");
  orcaCommands.commands[1] = g_strdup("submitOrca 1:0:0");
#ifdef G_OS_WIN32
  orcaCommands.commands[2] = g_strdup("orca");
#endif


	pcgamessCommands.numberOfCommands = 2;
#ifdef G_OS_WIN32
      pcgamessCommands.numberOfCommands = 3;
#endif

  pcgamessCommands.numberOfDefaultCommand = 0;
  pcgamessCommands.commands = g_malloc(pcgamessCommands.numberOfCommands*sizeof(gchar*));
  pcgamessCommands.commands[0] = g_strdup("nohup pcgamess");
  pcgamessCommands.commands[1] = g_strdup("submitPCGamess 1:0:0");
#ifdef G_OS_WIN32
  pcgamessCommands.commands[2] = g_strdup("pcgamess");
#endif

	qchemCommands.numberOfCommands = 2;
#ifdef G_OS_WIN32
      qchemCommands.numberOfCommands = 3;
#endif

  qchemCommands.numberOfDefaultCommand = 0;
  qchemCommands.commands = g_malloc(qchemCommands.numberOfCommands*sizeof(gchar*));
  qchemCommands.commands[0] = g_strdup("nohup qchem");
  qchemCommands.commands[1] = g_strdup("submitQChem 1:0:0");
#ifdef G_OS_WIN32
  qchemCommands.commands[2] = g_strdup("qc");
#endif

	mopacCommands.numberOfCommands = 2;
#ifdef G_OS_WIN32
	mopacCommands.numberOfCommands = 3;
#endif
  mopacCommands.numberOfDefaultCommand = 0;
  mopacCommands.commands = g_malloc(mopacCommands.numberOfCommands*sizeof(gchar*));
  mopacCommands.commands[0] = g_strdup("mopac");
  mopacCommands.commands[1] = g_strdup("submitMopac 1:0:0");
#ifdef G_OS_WIN32
  mopacCommands.commands[2] = g_strdup("MOPAC2007");
#endif

	povrayCommands.numberOfCommands = 1;
  povrayCommands.numberOfDefaultCommand = 0;
  povrayCommands.commands = g_malloc(povrayCommands.numberOfCommands*sizeof(gchar*));
#ifdef G_OS_WIN32
  povrayCommands.commands[0] = g_strdup("start /w pvengine /nr /exit /render +A0.3 -UV");
#else
  povrayCommands.commands[0] = g_strdup("povray +A0.3 -UV");
#endif


 
  initialise_batch_commands();
  Dipole.def = FALSE;
  Dipole.radius = 0.25;
  Dipole.color[0] = 0;
  Dipole.color[1] = 0;
  Dipole.color[2] = 65535;
  initAxis();
  initPrincipalAxisGL();
}
/*************************************************************************************/
void run_molden (gchar *titre)
{
	gchar *fout =  g_strdup_printf("%s%stmp%sfout",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
	gchar *ferr =  g_strdup_printf("%s%stmp%sferr",gabedit_directory(),G_DIR_SEPARATOR_S,G_DIR_SEPARATOR_S);
	gchar* strout = NULL;
	gchar* strerr = NULL;
	GtkWidget* Text[2];
	GtkWidget* Frame[2];
	GtkWidget* Win;
	gchar*  title;

	gchar *temp=NULL;
	gchar *NameLower=NULL;

	NameLower = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.moldenfile);
	if(iprogram == PROG_IS_MOLPRO)
  		g_strdown(NameLower);

	temp=g_strdup_printf("molden %s ",NameLower);
	
	run_local_command(fout,ferr,temp,TRUE);

	title = g_strdup_printf("Run Molden: %s",temp); 
	Win = create_text_result_command(Text,Frame,title);
	g_free(title);
	strout = cat_file(fout,FALSE);
	strerr = cat_file(ferr,FALSE);
	if(!strout && !strerr) destroy_childs(Win);
	else
	{
  		if(strout)
		{
 			gabedit_text_insert (GABEDIT_TEXT(Text[0]), NULL, NULL, NULL,strout,-1);   
			g_free(strout);
		}
  		if(strerr)
		{
 			gabedit_text_insert (GABEDIT_TEXT(Text[1]), NULL, NULL, NULL,strerr,-1);   
			g_free(strerr);
		}
  		gtk_widget_show_all(Win);
  		if(!strout)
  			gtk_widget_hide(Frame[0]);
	}

	if(temp !=NULL)
		g_free(temp);
	if(NameLower !=NULL)
		g_free(NameLower);
	g_free(fout);
	g_free(ferr);
}
/*************************************************************************************/
gboolean variable_name_valid(gchar *t)
{
    gchar FirstForbidden[]={
	'0','1','2','3','4','5','6','7','8','9',
    	'+','-','/','%','$','*','!','@','#','^',
    	'&','(',')','|','\\','<','>','?',',','~',
    	'`','\'','.','"',':',';'};
    guint All=36;
    guint j;
    guint i;
    for(i=0;i<All;i++)
	if(t[0]==FirstForbidden[i] ) return FALSE;

    for(i=0;i<strlen(t);i++)
    	for(j=11;j<All;j++)
	if(t[i]==FirstForbidden[j] ) return FALSE;

	return TRUE;

}
/*************************************************************************************/
gboolean testa(char c)
{
	switch ( c )
	{
	case	'0':
	case	'1':
	case	'2':
	case	'3':
	case	'4':
	case	'5':
	case	'6':
	case	'7':
	case	'8':
	case	'9':
	case	'.':
	case	'e':
	case	'E':
	case	'+':
	case	'-':return TRUE;
	}
	return FALSE;
}
/*************************************************************************************/
gboolean test(const gchar *t)
{
	guint i;
	for(i=0;i<strlen(t);i++)
		if(!testa(t[i]) ) return FALSE;
	if(t[0] =='e' || t[0] =='E' ) return FALSE;
	return TRUE;

}
/*************************************************************************************/
gboolean testapointeE(char c)
{
	switch ( c )
	{
	case	'.':
	case	'e':
	case	'E':return TRUE;
	}
	return FALSE;
}
/*************************************************************************************/
gboolean testpointeE(const gchar *t)
{
	guint i;
	for(i=0;i<strlen(t);i++)
		if(testapointeE(t[i]) ) return TRUE;
	return FALSE;

}
/*************************************************************************************/
void set_font_style (GtkStyle* style,gchar *fontname)
{
  	PangoFontDescription *font_desc;
  	font_desc = pango_font_description_from_string (fontname);
	if (font_desc)
	{
		/*
		pango_font_description_free (style->font_desc);
		*/
		style->font_desc = font_desc;
	}
}         
/*************************************************************************************/
void set_font (GtkWidget *view, gchar *fontname)
{
        GtkStyle *style;
  	PangoFontDescription *font_desc;
 
	if(!GTK_IS_WIDGET(view)) return;
        style = gtk_style_copy (gtk_widget_get_style (view));
  	font_desc = pango_font_description_from_string (fontname);

	if (font_desc)
	{
		/*
		pango_font_description_free (style->font_desc);
		*/
		style->font_desc = font_desc;
	}
 
        gtk_widget_set_style (GTK_WIDGET(view), style);
 
        g_object_unref (style);
}         
/*************************************************************************************/
void set_tab_size (GtkWidget *view, gint tab_size)
{
	PangoTabArray* tabs = pango_tab_array_new(tab_size,FALSE);
	gtk_text_view_set_tabs          ((GtkTextView *)view, tabs);
}
/*************************************************************************************/
GtkStyle *set_text_style(GtkWidget *text,gushort red,gushort green,gushort blue)
{
	  GtkStyle *style;
          style =  gtk_style_copy(text->style); 
          style->text[0].red=red;
          style->text[0].green=green;
          style->text[0].blue=blue;
	  gtk_widget_set_style(text, style );
          return style;
}
/********************************************************************************/
GtkStyle *set_base_style(GtkWidget *text,gushort red,gushort green,gushort blue)
{
	  GtkStyle *style;
          style =  gtk_style_copy(text->style); 
          style->base[0].red=red;
          style->base[0].green=green;
          style->base[0].blue=blue;
	  gtk_widget_set_style(text, style );
          return style;
}
/********************************************************************************/
GtkStyle *set_fg_style(GtkWidget *wid,gushort red,gushort green,gushort blue)
{
	  GtkStyle *style;
          style =  gtk_style_copy(wid->style); 
          style->fg[0].red=red;
          style->fg[0].green=green;
          style->fg[0].blue=blue;
	  gtk_widget_set_style(wid, style );
          return style;
}
/********************************************************************************/
GtkStyle *set_bg_style(GtkWidget *wid,gushort red,gushort green,gushort blue)
{
	  GtkStyle *style;
          style =  gtk_style_copy(wid->style); 
          style->bg[0].red=red;
          style->bg[0].green=green;
          style->bg[0].blue=blue;
	  gtk_widget_set_style(wid, style );
          return style;
}
/********************************************************************************/
gint numb_of_string_by_row(gchar *str)
{
	gint n=0;
	gchar* t=str;
	while(*t!='\n' && *t !='\0')
	{
		if(*t!=' ')
		{
			n++;
			while(*t!=' ')
			{
				t++;
				if(*t =='\n' || *t =='\0')
					break;
			}

		}
		else
		{
			while(*t ==' ' )
			{
				t++;
				if(*t =='\n' || *t =='\0')
					break;
			}
		}
	}
	return n;
}
/********************************************************************************/
gint numb_of_reals_by_row(gchar *str)
{
	gint n=0;
	gchar* t=str;
	gchar p[BSIZE];
	while(*t!='\n' && *t !='\0')
	{
		if(*t =='\t') *t =' ';
		if(*t =='\r') *t =' ';
		if(*t!=' ')
		{
			sscanf(t,"%s",p);
			if(test(p)) n++;
			while(*t!=' ')
			{
				t++;
				if(*t =='\n' || *t =='\0')
					break;
			}

		}
		else
		{
			while(*t ==' ' )
			{
				t++;
				if(*t =='\n' || *t =='\0')
					break;
			}
		}
	}
	return n;
}
/********************************************************************************/
gchar** gab_split(gchar *str)
{
	gchar** strsplit= g_malloc(sizeof(gchar*));
	gint n=0;
	gchar* t=str;
	gchar p[BSIZE];
	while(*t!='\n' && *t !='\0')
	{
		if(*t!=' ')
		{
			n++;
			strsplit= g_realloc(strsplit,(n+1)*sizeof(gchar*));
			sscanf(t,"%s",p);
			strsplit[n-1]= g_strdup(p);
			while(*t!=' ')
			{
				t++;
				if(*t =='\n' || *t =='\0')
					break;
			}

		}
		else
		{
			while(*t ==' ' )
			{
				t++;
				if(*t =='\n' || *t =='\0')
					break;
			}
		}
	}
	strsplit[n]= NULL;
	return strsplit;
}
/********************************************************************************/
void get_dipole_from_gamess_output_file(FILE* fd)
{
 	guint taille=BSIZE;
  	gchar *t = g_malloc(BSIZE*sizeof(gchar));
  	gchar* t1;

	Dipole.def = FALSE;

  	while(!feof(fd) )
	{
    		t1 = NULL;
    		if(!fgets(t,taille,fd))break;
    		t1 = strstr( t, "ELECTROSTATIC MOMENTS");
		if(t1)
		{
  			while(!feof(fd) )
			{
    				if(!fgets(t,taille,fd))break;
    				t1 = strstr( t, "DEBYE");
				if(t1)
				{
					gint i;
    					if(!fgets(t,taille,fd))break;
					sscanf(t,"%lf %lf %lf",&Dipole.Value[0],&Dipole.Value[1],&Dipole.Value[2]);
					for(i=0;i<3;i++) Dipole.Value[i] /= AUTODEB;
					Dipole.def = TRUE;
					break;
				}
			}
			break;
		}
		else
		{
			if(strstr( t, "END OF PROPERTY" )) break;
		}

	}
	g_free(t);
}
/********************************************************************************/
void get_dipole_from_gaussian_output_file(FILE* fd)
{
 	guint taille=BSIZE;
  	gchar *t = g_malloc(BSIZE*sizeof(gchar));
  	gchar* pdest;
	gint ngrad = 0;
	gint i;

	Dipole.def = FALSE;

  	while(!feof(fd) )
	{
    		pdest = NULL;
		Dipole.def = FALSE;
    		fgets(t,taille,fd);
    		pdest = strstr( t, "Dipole moment (Debye)");

		if(pdest)
		{
    		if(!feof(fd))
			fgets(t,taille,fd);
		else
			break;
		Dipole.def = TRUE;
    		pdest = strstr( t, "X=")+2;
		sscanf(pdest,"%lf",&Dipole.Value[0]);
    		pdest = strstr( t, "Y=")+2;
		sscanf(pdest,"%lf",&Dipole.Value[1]);
    		pdest = strstr( t, "Z=")+2;
		sscanf(pdest,"%lf",&Dipole.Value[2]);
		/*
		Debug("t =%s\n",t);
		Debug("Dipole = %f %f %f\n",Dipole.Value[0],Dipole.Value[1],Dipole.Value[2]);
		*/
		for(i=0;i<3;i++)
			Dipole.Value[i] /= AUTODEB;
		break;
		}
		else
		{
          		pdest = strstr( t, "GradGradGrad" );
			if(pdest)
			{
				ngrad++;
			/*	Debug("ngrad = %d\n",ngrad);*/
			}
			if(ngrad>2)
				break;
		}

	}
	g_free(t);
}
/********************************************************************************/
void get_dipole_from_molpro_output_file(FILE* fd)
{
 	guint taille=BSIZE;
  	gchar *t = g_malloc(BSIZE*sizeof(gchar));
  	gchar* t1;
  	gchar* t2;

	Dipole.def = FALSE;

  	while(!feof(fd) )
	{
    		t1 = NULL;
    		fgets(t,taille,fd);
    		t1 = strstr( t, "DIPOLE MOMENTS:");

		if(t1)
		{
		Dipole.def = TRUE;
    		t2 = strstr( t1, ":")+2;
		sscanf(t2,"%lf %lf %lf",&Dipole.Value[0],&Dipole.Value[1],&Dipole.Value[2]);
		/*
		Debug("t =%s\n",t);
		Debug("Dipole = %f %f %f\n",Dipole.Value[0],Dipole.Value[1],Dipole.Value[2]);
		*/
		break;
		}
		else
		{
          		t1 = strstr( t, "GEOMETRY OPTIMIZATION STEP" );
			if(t1)
				break;
          		t1 = strstr( t, "SEWARD" );
			if(t1)
				break;
		}

	}
	g_free(t);
}
/********************************************************************************/
void get_dipole_from_dalton_output_file(FILE* fd)
{
 	guint taille=BSIZE;
  	gchar *t = g_malloc(BSIZE*sizeof(gchar));
  	gchar* t1;
  	gchar* t2;
	gchar dum[100];

	Dipole.def = FALSE;

  	while(!feof(fd) )
	{
    		t1 = NULL;
    		if(!fgets(t,taille,fd))break;
    		t1 = strstr( t, "Dipole moment components");
		if(t1)
		{
    			if(!fgets(t,taille,fd))break;
    			if(!fgets(t,taille,fd))break;
    			if(!fgets(t,taille,fd))break;
    			if(!fgets(t,taille,fd))break;
    			t2 = strstr( t1, ":")+2;
    			if(!fgets(t,taille,fd))break;
			sscanf(t,"%s %lf",dum, &Dipole.Value[0]);
    			if(!fgets(t,taille,fd))break;
			sscanf(t,"%s %lf",dum, &Dipole.Value[1]);
    			if(!fgets(t,taille,fd))break;
			sscanf(t,"%s %lf",dum, &Dipole.Value[2]);
			Dipole.def = TRUE;
		/*
			Debug("t =%s\n",t);
			Debug("Dipole = %f %f %f\n",Dipole.Value[0],Dipole.Value[1],Dipole.Value[2]);
		*/
			break;
		}
		else
		{
			if(strstr( t, ">>>>" )) break;
		}

	}
	g_free(t);
}
/********************************************************************************/
void get_dipole_from_orca_output_file(FILE* fd)
{
 	guint taille=BSIZE;
  	gchar *t = g_malloc(BSIZE*sizeof(gchar));
  	gchar* pdest;

	Dipole.def = FALSE;

  	while(!feof(fd) )
	{
    		pdest = NULL;
		Dipole.def = FALSE;
    		fgets(t,taille,fd);
    		pdest = strstr( t, "Total Dipole Moment");

		if(pdest && strstr( t,":"))
		{
			pdest = strstr( t,":")+1;
			Dipole.def = TRUE;
			sscanf(pdest,"%lf %lf %lf",&Dipole.Value[0],&Dipole.Value[1],&Dipole.Value[2]);
			break;
		}
	}
	g_free(t);
}
/********************************************************************************/
void get_dipole_from_qchem_output_file(FILE* fd)
{
 	guint taille=BSIZE;
  	gchar *t = g_malloc(BSIZE*sizeof(gchar));
  	gchar* pdest;
	gint ngrad = 0;
	gint i;

	Dipole.def = FALSE;

  	while(!feof(fd) )
	{
    		pdest = NULL;
		Dipole.def = FALSE;
    		fgets(t,taille,fd);
    		pdest = strstr( t, "Dipole Moment (Debye)");

		if(pdest)
		{
    		if(!feof(fd)) fgets(t,taille,fd);
		else break;
		Dipole.def = TRUE;
    		pdest = strstr( t, "X")+2;
		if(pdest) sscanf(pdest,"%lf",&Dipole.Value[0]);
    		pdest = strstr( t, "Y")+2;
		if(pdest) sscanf(pdest,"%lf",&Dipole.Value[1]);
    		pdest = strstr( t, "Z")+2;
		if(pdest) sscanf(pdest,"%lf",&Dipole.Value[2]);
		for(i=0;i<3;i++) Dipole.Value[i] /= AUTODEB;
		break;
		}
		else
		{
          		pdest = strstr( t, "GradGradGrad" );
			if(pdest)
			{
				ngrad++;
			}
			if(ngrad>2) break;
		}

	}
	g_free(t);
}
/********************************************************************************/
void get_dipole_from_mopac_output_file(FILE* fd)
{
 	guint taille=BSIZE;
  	gchar *t = g_malloc(BSIZE*sizeof(gchar));
  	gchar* pdest;
	gint i;
	gchar dum[100];

	Dipole.def = FALSE;

  	while(!feof(fd) )
	{
    		pdest = NULL;
		Dipole.def = FALSE;
    		fgets(t,taille,fd);
    		pdest = strstr( t, "DIPOLE           X         Y         Z");

		if(pdest)
		{
    			if(!fgets(t,taille,fd)) break;
    			if(!fgets(t,taille,fd)) break;
    			if(!fgets(t,taille,fd)) break;
			Dipole.def = TRUE;
    			pdest = strstr( t, "SUM")+2;
			sscanf(t,"%s %lf %lf %lf",dum,&Dipole.Value[0],&Dipole.Value[1], &Dipole.Value[2]);
			for(i=0;i<3;i++) Dipole.Value[i] /= AUTODEB;
			break;
		}
	}
	g_free(t);
}
/********************************************************************************/
void get_dipole_from_mopac_aux_file(FILE* fd)
{
  	gchar t[BSIZE];
  	gchar* pdest;
	gint i;

	Dipole.def = FALSE;

  	while(!feof(fd) )
	{
    		pdest = NULL;
		Dipole.def = FALSE;
    		fgets(t,BSIZE,fd);
    		pdest = strstr( t, "DIPOLE:DEBYE=");

		if(pdest)
		{
			Dipole.def = TRUE;
    			pdest = strstr( t, "=")+1;
			Dipole.Value[0] = 0;
			Dipole.Value[1] = 0;
			Dipole.Value[2] = 0;
			if(pdest) sscanf(pdest,"%lf %lf %lf",&Dipole.Value[0], &Dipole.Value[1],&Dipole.Value[2]);
			for(i=0;i<3;i++) Dipole.Value[i] /= AUTODEB;
			break;
		}
	}
}
/**********************************************/
void set_dipole(GtkWidget* fp,gpointer data)
{
	GtkWidget** entrys = (GtkWidget**)data;
	GdkColor* color = g_object_get_data(G_OBJECT (fp), "Color");
	G_CONST_RETURN gchar* tentry;
	gint i;
	gdouble fact=1.0;

	tentry = gtk_entry_get_text(GTK_ENTRY(entrys[0]));
	fact = atof(tentry);
	Dipole.def = TRUE;
	for(i=1;i<4;i++)
	{
		tentry = gtk_entry_get_text(GTK_ENTRY(entrys[i]));
		Dipole.Value[i-1] = atof(tentry)*fact;
	}
	for(i=0;i<3;i++)
		Dipole.Value[i] /= AUTODEB;

	tentry = gtk_entry_get_text(GTK_ENTRY(entrys[4]));
	Dipole.radius = atof(tentry)/AUTODEB;
	if(Dipole.radius<1e-6) Dipole.radius = 0.1;

	Dipole.color[0] = color->red;
	Dipole.color[1] = color->green;
	Dipole.color[2] = color->blue;
	rafresh_window_orb();

        if(ZoneDessin != NULL)
		 draw_geometry(NULL,NULL);
}
/**********************************************/
void delete_last_spaces(gchar* str)
{
	gchar *s;

	if(str == NULL)
		return;

	if (!*str)
		return;
	for (s = str + strlen (str) - 1; s >= str && isspace ((guchar)*s); s--)
		*s = '\0';
}
/**********************************************/
void delete_first_spaces(gchar* str)
{
	gchar *start;
	gint i;
	gint lenSpace = 0;

	if(str == NULL)
		return;
	if (!*str)
		return;

	for (start = str; *start && isspace (*start); start++)lenSpace++;

	for(i=0;i<(gint)(strlen(str)-lenSpace);i++)
		str[i] = str[i+lenSpace];
	str[strlen(str)-lenSpace] = '\0';
}
/**********************************************/
void delete_all_spaces(gchar* str)
{
	gint i;
	gint j;
	gboolean Ok = FALSE;

	delete_last_spaces(str);
	delete_first_spaces(str);
	while(!Ok)
	{
		Ok = TRUE;
		for(i=0;i<(gint)strlen(str);i++)
		{
			if(isspace(str[i]))
			{
				Ok = FALSE;
				for(j=i;j<(gint)strlen(str);j++)
				{
					str[j] = str[j+1];
				}
				break;
			}
		}
	}
}
/**********************************************/
gchar* get_to_str(gchar* str,gchar* end)
{
	gchar* iend = NULL;
	gchar* res = NULL;
	gint len;
	gint i;

	if(str == NULL || end == NULL)
		return NULL;

	iend = strstr(str,end);
	if(iend==NULL)
		return g_strdup(str);
	len = iend - str;
	if(len<1)
		return NULL;

	res = g_malloc((len+1)*sizeof(gchar));
	for(i=0;i<len;i++)
		res[i] = str[i];

	res[len] = '\0';
	return res;
	
}
/*************************************************************************************/
static gboolean testi(char c)
{
	switch ( c )
	{
	case	'0':
	case	'1':
	case	'2':
	case	'3':
	case	'4':
	case	'5':
	case	'6':
	case	'7':
	case	'8':
	case	'9': return TRUE;
	}
	return FALSE;
}
/*************************************************************************************/
gboolean isInteger(gchar *t)
{
	guint i;
	if(!testi(t[0])&& t[0] != '-' ) return FALSE;
	for(i=1;i<strlen(t);i++)
		if(!testi(t[i]) ) return FALSE;
	return TRUE;

}
/*************************************************************************************/
static gboolean testascii(char c)
{
	switch ( c )
	{
	case	'0':
	case	'1':
	case	'2':
	case	'3':
	case	'4':
	case	'5':
	case	'6':
	case	'7':
	case	'8':
	case	'9':
	case	'.':
	case	'e':
	case	'E':
	case	'+':
	case	'-':return TRUE;
	}
	return FALSE;
}
/*************************************************************************************/
gboolean isFloat(const gchar *t)
{
	guint i;
	for(i=0;i<strlen(t);i++)
		if(!testascii(t[i]) ) return FALSE;
	if(t[0] =='e' || t[0] =='E' ) return FALSE;
	return TRUE;

}
/**********************************************/
void get_symb_type_charge(gchar* str,gchar symb[], gchar type[], gchar charge[])
{
	gint i;
	gchar** split = g_strsplit(str,"-",4);

	sprintf(symb,"H");
	sprintf(type,"H");
	sprintf(charge,"0.0");
	if(!str)
		return;
	sprintf(symb,"%s",str);
	sprintf(type,"%s",str);
	if(split)
	for(i=0;i<4;i++)
	{
		if(!split[i])
			break;

		switch(i)
		{
			case 0: sprintf(symb,"%s",split[0]);
				g_free(split[0]);
				break;
			case 1: sprintf(type,"%s",split[1]);
				g_free(split[1]);
				break;
			case 2: if(strlen(split[2])<1)
				{
					g_free(split[2]);
					break;
				}
				sprintf(charge,"%s",split[2]);
				g_free(split[2]);
				break;
			case 3: sprintf(charge,"-%s",split[3]);
				g_free(split[3]);
		}
	}
}
/**********************************************/
void str_delete_n(gchar* str)
{
	gchar *s;

	if(str == NULL)
		return;

	if (!*str)
		return;
	for (s = str + strlen (str) - 1; s >= str && ((guchar)*s)=='\n'; s--)
		*s = '\0';
}
/**********************************************/
gchar* get_font_label_name()
{
	return FontsStyleLabel.fontname;
}
/*************************************************************************************/
gboolean test_type_program_gaussian(FILE* file)
{
	gchar t[BSIZE];
	guint taille=BSIZE;
	fseek(file, 0L, SEEK_SET);
	if(!fgets(t, taille, file)) return FALSE;
	if((int)t[0]==(int)'#' || (int)t[0]==(int)'%' ) return TRUE;
	return FALSE;
}
/**********************************************************************************/
gboolean test_type_program_molcas(FILE* file)
{
	gchar t[BSIZE];
	guint taille=BSIZE;
	fseek(file, 0L, SEEK_SET);
	while(!feof(file))
	{
		if(!fgets(t, taille, file)) return FALSE;
		g_strup(t);
		if( strstr(t, "&SEWARD") ) return TRUE;
		if( strstr(t, "&GATEWAY") ) return TRUE;
	}
	return FALSE;
}
/**********************************************************************************/
gboolean test_type_program_molpro(FILE* file)
{
	gchar t[BSIZE];
	guint taille=BSIZE;
	fseek(file, 0L, SEEK_SET);
	while(!feof(file))
	{
		if(!fgets(t, taille, file)) return FALSE;
		if( (int)t[0] ==(int)'!' ) continue;
		if( (int)t[0] ==(int)'*' ) return TRUE;
		return FALSE;
	}
	return FALSE;
}
/**********************************************************************************/
gboolean test_type_program_mpqc(FILE* file)
{
	gchar t[BSIZE];
	guint taille=BSIZE;
	fseek(file, 0L, SEEK_SET);
	while(!feof(file))
	{
		if(!fgets(t, taille, file)) return FALSE;
		if(strstr(t,"%"))continue;
		/* Object-Oriented  input file */
		if(strstr(t,"molecule") && strstr(t,"Molecule") && strstr(t,"<") && strstr(t,">")) return TRUE;
		/* sample input file */
		if(strstr(t,"molecule") && strstr(t,":")) return TRUE;
	}
	return FALSE;
}
/**********************************************************************************/
gboolean test_type_program_gamess(FILE* file)
{
	gchar t[BSIZE];
	guint taille=BSIZE;
	fseek(file, 0L, SEEK_SET);
	while(!feof(file))
	{
		if(!fgets(t, taille, file)) return FALSE;
		if(strstr(t,"!"))continue;
		
		if(strstr(t,"$CONTRL")) return TRUE;
		/* sample input file */
		if(strstr(t,"$BASIS")) return TRUE;
		if(strstr(t,"$DATA")) return TRUE;
	}
	return FALSE;
}
/**********************************************************************************/
gboolean test_type_program_pcgamess(FILE* file)
{
	gchar t[BSIZE];
	guint taille=BSIZE;
	fseek(file, 0L, SEEK_SET);
	while(!feof(file))
	{
		if(!fgets(t, taille, file)) return FALSE;
		if(strstr(t,"PCGamess")) return TRUE;
	}
	return FALSE;
}
/**********************************************************************************/
gboolean test_type_program_orca(FILE* file)
{
	gchar t[BSIZE];
	guint taille=BSIZE;
	fseek(file, 0L, SEEK_SET);
	while(!feof(file))
	{
		if(!fgets(t, taille, file)) return FALSE;
		if(strstr(t,"Orca input") && strstr(t,"#")) return TRUE;
		g_strup(t);
		if(strstr(t,"* XYZ")) return TRUE;
		if(strstr(t,"* INT")) return TRUE;
	}
	return FALSE;
}
/**********************************************************************************/
gboolean test_type_program_mopac(FILE* file)
{
	gchar t[BSIZE];
	guint taille=BSIZE;
	fseek(file, 0L, SEEK_SET);
	while(!feof(file))
	{
		if(!fgets(t, taille, file)) return FALSE;
		if(t[0] != '*') break;
		if(t[0] == '*' && strstr(t,"Mopac")) return TRUE;
	}
	if(strstr(t,"BONDS") && strstr(t,"CHARGE")) return TRUE;
	if(!fgets(t, taille, file)) return FALSE;
	if(strstr(t,"Mopac")) return TRUE;
	return FALSE;
}
/**********************************************************************************/
gboolean test_type_program_qchem(FILE* file)
{
	gchar t[BSIZE];
	guint taille=BSIZE;
	fseek(file, 0L, SEEK_SET);
	while(!feof(file))
	{
		if(!fgets(t, taille, file)) return FALSE;
		if(strstr(t,"!"))continue;
		
		if(strstr(t,"$molecule")) return TRUE;
		if(strstr(t,"$rem")) return TRUE;
	}
	return FALSE;
}
/**********************************************************************************/
gint get_type_of_program(FILE* file)
{
	if(test_type_program_orca(file))
	{
		fseek(file, 0L, SEEK_SET);
		return PROG_IS_ORCA;
	}
	if(test_type_program_pcgamess(file))
	{
		fseek(file, 0L, SEEK_SET);
		return PROG_IS_PCGAMESS;
	}
	if(test_type_program_gamess(file))
	{
		fseek(file, 0L, SEEK_SET);
		return PROG_IS_GAMESS;
	}
	if(test_type_program_qchem(file))
	{
		fseek(file, 0L, SEEK_SET);
		return PROG_IS_QCHEM;
	}
	if(test_type_program_mopac(file))
	{
		fseek(file, 0L, SEEK_SET);
		return PROG_IS_MOPAC;
	}
	if(test_type_program_mpqc(file))
	{
		fseek(file, 0L, SEEK_SET);
		return PROG_IS_MPQC;
	}
	if(test_type_program_gaussian(file))
	{
		fseek(file, 0L, SEEK_SET);
		return PROG_IS_GAUSS;
	}
	if(test_type_program_molcas(file))
	{
		fseek(file, 0L, SEEK_SET);
		return PROG_IS_MOLCAS;
	}
	if(test_type_program_molpro(file))
	{
		fseek(file, 0L, SEEK_SET);
		return PROG_IS_MOLPRO;
	}
	fseek(file, 0L, SEEK_SET);
	return PROG_IS_OTHER;
}
/**************************************************************************************************************************************/
void gabedit_string_get_pixel_size(GtkWidget* parent, PangoFontDescription *font_desc, G_CONST_RETURN gchar* t, int *width, int* height)
{
	PangoLayout *layout = gtk_widget_create_pango_layout(parent, t);
	if(font_desc) pango_layout_set_font_description (layout,font_desc);
	pango_layout_set_justify(layout, TRUE);
	pango_layout_get_pixel_size(layout, width,height);
	g_object_unref (layout);
}
/**********************************************************************************/
void gabedit_draw_string(GtkWidget* parent, GdkPixmap* pixmap, PangoFontDescription *font_desc, GdkGC* gc , gint x, gint y, G_CONST_RETURN gchar* t, gboolean centerX, gboolean centerY)
{
	int width  = 0;
	int height = 0;
	PangoLayout *layout = gtk_widget_create_pango_layout(parent, t);
	if(font_desc) pango_layout_set_font_description (layout,font_desc);
	pango_layout_set_justify(layout, TRUE);
	if(centerX || centerY) pango_layout_get_pixel_size(layout, &width,&height);
	 if(centerX) x -= width/2;
	 if(centerY) y -= height/2;
	gdk_draw_layout (pixmap,gc,x,y,layout);
	g_object_unref (layout);
}
/**********************************************************************************************************************************/
void gabedit_save_image(GtkWidget* widget, gchar *fileName, gchar* type)
{       
	int width;
	int height;
	GError *error = NULL;
	GdkPixbuf  *pixbuf = NULL;

	width =  widget->allocation.width;
	height = widget->allocation.height;
	pixbuf = gdk_pixbuf_get_from_drawable(NULL, widget->window, NULL, 0, 0, 0, 0, width, height);
	if(pixbuf)
	{
		if(!fileName)
		{
			GtkClipboard * clipboard;
			clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);
			gtk_clipboard_set_image(clipboard, pixbuf);
		}
		else gdk_pixbuf_save(pixbuf, fileName, type, &error, NULL);
	 	g_object_unref (pixbuf);
	}
}
/**********************************************************************************************************************************/
G_CONST_RETURN gchar* get_open_babel_command()
{       
	return babelCommand;
}
/**********************************************************************************************************************************/
gchar** get_one_block_from_aux_mopac_file(FILE* file, gchar* blockName,  gint* n)
{
	gint nElements = 0;
	gchar** elements = NULL;
	gchar t[BSIZE];
	 while(!feof(file))
	 {
		if(!fgets(t,BSIZE,file))break;
		if(strstr( t, blockName))
		{
			gchar* pdest = strstr( t, "[")+1;
			gint i;
			nElements = atoi(pdest);
			if(nElements<1) break;
			else
			{ 
				long int geomposok = ftell(file);
				if(!fgets(t,BSIZE,file))break;
				if(!strstr(t,"# ")) fseek(file, geomposok, SEEK_SET);
			}

			elements = g_malloc(nElements*sizeof(gchar*));
			for(i=0;i<nElements;i++)
			{
				gint k;
				elements[i] = g_malloc(100*sizeof(gchar));
				k = fscanf(file,"%s",elements[i]);
				if(k<1 || strstr(elements[i],"["))
				{
					if(elements)
					{
						for(i=0;i<nElements;i++)
							if(elements[i]) g_free(elements[i]);
						g_free(elements);
						elements = NULL;
					}
					break;
				}
				else
				{
					for(k=0;k<strlen(elements[i]);k++)
					{
						if(elements[i][k]=='D') elements[i][k]='e';
						if(elements[i][k]=='d') elements[i][k]='e';
					}
				}
			}
			break;
		}
	 }
	 *n = nElements;
	 return elements;
}
/**********************************************************************************************************************************/
gchar** free_one_string_table(gchar** table, gint n)
{
	if(table)
	{
		gint i;
		for(i=0;i<n;i++)
			if(table[i]) g_free(table[i]);
		g_free(table);
	}
	return NULL;
}
/********************************************************************************/
gboolean zmat_mopac_scan_output_file(gchar *FileName)
{
 	guint taille=BSIZE;
  	gchar t[BSIZE];
 	FILE* fd = FOpen(FileName, "r");

	if(!fd) return FALSE;
  	while(!feof(fd) )
	{
    		if(!fgets(t,taille,fd)) break;
		if ( strstr(t,"ATOM  CHEMICAL   BOND LENGTH    BOND ANGLE    TWIST ANGLE"))
		{
			return TRUE;
		}
	}
	return FALSE;
}
