//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Estrada Soubran Uriel Alejandro			******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

#include "cmodel/CModel.h"

//Solo para Visual Studio 2015 o mayor
#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

CCamera objCamera; 
GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 27.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01

CFiguras fig1;
CFiguras fig2;
CFiguras fig3;
CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;
//Texturas usadas
CTexture t_pasto;
CTexture t_concreto;
CTexture t_tierra;
CTexture t_tile1;	//Fachada de Torres Altas?
CTexture t_dado;
CTexture t_tree;
CTexture t_tree2;

//Figuras a "mano"
CFiguras plancha;
CFiguras torreIzquierda;
CFiguras torreMedia;
CFiguras torreDerecha;
CFiguras jardinera;
CFiguras tree;
//Figuras de 3D Studio
CModel hammer;
CModel cubo;
CModel streetLamp;
CModel coche;
CModel PC;
float  Lx = 0.0;
float  Ly = 0.0;
float  Lz = 0.0;
/*
	Modelos a tener en cuenta:
	Proyector
	Silla1 (como las del lab CG)
	Silla2 (como las del I)
	Escritorio
	PC1(la del I)
	PC2(la de CG, aca pueden ser 1 o más, supuestamente PROPC)
	MesaLarga (para las compus, de 2 diferentes tamaños)
	Teclado
	Mouse
	Monitor
	Puerta1 (azul, del I)
	Puerta2 (blanca, de CG)
	Cajas	(en CG, extras?)
	Garrafon (de CG)
	BoteBasuraAmarillo (del I)

	Luces?
*/
//Animación del coche
float movKit = 0.0;
bool g_fanimacion = false;


//MOD MIA
bool cameraMode = false;
float giro_llanta = 0.0f;
bool loop_animacion = true;

float UpX = 0.0;

//END MOD
			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On
    
    text1.LoadBMP("Texturas/01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	t_pasto.LoadTGA("Texturas/pasto.tga");
	t_pasto.BuildGLTexture();
	t_pasto.ReleaseImage();

	t_concreto.LoadTGA("Texturas/concreto.tga");
	t_concreto.BuildGLTexture();
	t_concreto.ReleaseImage();

	t_tierra.LoadTGA("Texturas/tierra.tga");
	t_tierra.BuildGLTexture();
	t_tierra.ReleaseImage();

	t_tile1.LoadTGA("Texturas/tile1.tga");
	t_tile1.BuildGLTexture();
	t_tile1.ReleaseImage();

	t_dado.LoadTGA("Texturas/dado.tga");
	t_dado.BuildGLTexture();
	t_dado.ReleaseImage();

	t_tree.LoadTGA("Texturas/tree2.tga");
	t_tree.BuildGLTexture();
	t_tree.ReleaseImage();

	t_tree2.LoadTGA("Texturas/tree3.tga");
	t_tree2.BuildGLTexture();
	t_tree2.ReleaseImage();

	//Carga de Figuras
	hammer._3dsLoad("Modelos/hammer_paint.3ds");
	hammer.VertexNormals();

	streetLamp._3dsLoad("Modelos/streetLamp.3DS");
	streetLamp.VertexNormals();

	coche._3dsLoad("Modelos/coche.3ds");
	coche.VertexNormals();

	PC._3dsLoad("Modelos/PC_CG.3DS");	//Buen modelo

	objCamera.Position_Camera(10,2.5f,13, 10,2.5f,10, 0, 1, 0);

}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void jardineras() {
	glPushMatrix();
		glTranslatef(0.0, 0.5, -5.0);
		glScalef(26.0, 1.0, 10.0);
		glDisable(GL_LIGHTING);
		jardinera.torreMedia(t_tierra.GLindex, t_concreto.GLindex, 26.0, 1.0, 10.0);
		glEnable(GL_LIGHTING);
	glPopMatrix();
		

	glPushMatrix();	//E
		glTranslatef(-17.0, 0.0, -3.0);
		glDisable(GL_LIGHTING);
		jardinera.jardineraE(t_tierra.GLindex,t_pasto.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();	//F
		glTranslatef(17.0, 1.052, -3.0);
		glRotatef(180, 0.0, 0.0, 1.0);
		glDisable(GL_LIGHTING);
		jardinera.jardineraF(t_tierra.GLindex, t_pasto.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();	//G
		glTranslatef(-13.0, 0.052, 12.0);
		glDisable(GL_LIGHTING);
		jardinera.jardineraG(t_tierra.GLindex, t_pasto.GLindex);
		glEnable(GL_LIGHTING);
		glPushMatrix();	//Arbol
			glTranslatef(-5.0, 1.0, -4.0);
			tree.tree(t_tree.GLindex);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();	//H
		glTranslatef(13.0, 1.052, 12.0);
		glPushMatrix();	//Arbol
			glTranslatef(5.0, 0.0, -4.0);
			tree.tree(t_tree.GLindex);
		glPopMatrix();
		glRotatef(180, 0.0, 0.0, 1.0);
		glDisable(GL_LIGHTING);
		jardinera.jardineraH(t_tierra.GLindex, t_pasto.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();	//C	sin curva
		glTranslatef(-8.0, 1.052, -17.0);
		glPushMatrix();	//Arbol
			glTranslatef(-4.0, -0.05, -2.0);
			tree.tree(t_tree2.GLindex);
		glPopMatrix();
		glRotatef(180, 0.0, 0.0, 1.0);
		glRotatef(-90, 0.0, 1.0, 0.0);
		glDisable(GL_LIGHTING);
		jardinera.jardineraF(t_tierra.GLindex, t_pasto.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();	//D	sin curva
		glTranslatef(8.0, 0.052, -17.0);
		glPushMatrix();	//Arbol
			glTranslatef(4.0, 0.95, -2.0);
			tree.tree(t_tree2.GLindex);
		glPopMatrix();
		glRotatef(-90, 0.0, 1.0, 0.0);
		glDisable(GL_LIGHTING);
		jardinera.jardineraE(t_tierra.GLindex, t_pasto.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();	//I
		glTranslatef(-6.0, 0.052, 20.0);
		glDisable(GL_LIGHTING);
		jardinera.jardineraI(t_tierra.GLindex, t_pasto.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();	//J
		glTranslatef(6.0, 1.052, 20.0);
		glRotatef(180, 0.0, 0.0, 1.0);
		glDisable(GL_LIGHTING);
		jardinera.jardineraJ(t_tierra.GLindex, t_pasto.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	glPushMatrix();	//General

		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
		
		
		glPushMatrix();		
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(130.0, 130.0, 130.0,text1.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
/*
			glPushMatrix();	//Lampara
				glDisable(GL_COLOR_MATERIAL);
				//glRotatef(90, 0, 1, 0);
				//glTranslatef(Lx, Ly, Lz);
				glTranslatef(0.0, 0.0, 0.0);
				glScalef(0.05, 0.05, 0.05);
				streetLamp.GLrender(NULL,_SHADED,1.0);
			glPopMatrix();
*/
/*			glPushMatrix();	//PC
				glDisable(GL_COLOR_MATERIAL);
				//glRotatef(90, 0, 1, 0);
				//glTranslatef(Lx, Ly, Lz);
				glTranslatef(0.0, 0.0, 10.0);
				glScalef(0.005, 0.005, 0.005);
				PC.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
*/
			glPushMatrix();	//Torre Izquierda
				glTranslatef(-8.0, 8.502, -5.0);
				glScalef(10.0, 15.0, 10.0);
				glDisable(GL_LIGHTING);
				torreIzquierda.torreMedia(t_tile1.GLindex, t_tile1.GLindex, 10.0, 15.0, 10.0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();	//Torre Derecha
				glTranslatef(8.0, 8.502, -5.0);
				glScalef(10.0, 15.0, 10.0);
				glDisable(GL_LIGHTING);
				torreDerecha.torreMedia(t_tile1.GLindex, t_tile1.GLindex, 10.0, 15.0, 10.0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();	//Torre Media
				glTranslatef(0.0, 2.502, -4.0);
				glScalef(6.0, 3.0, 8.0);
				glDisable(GL_LIGHTING);
				torreMedia.torreMedia(t_tile1.GLindex, t_tile1.GLindex, 6.0,3.0,8.0);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			jardineras();
			
			//Para que el comando glColor funcione con iluminacion
			glEnable(GL_COLOR_MATERIAL);

			glPushMatrix(); //Plancha
				glTranslatef(0.0,0.0,0.0);
				glScalef(50,0.1,50);
				glDisable(GL_LIGHTING);
				plancha.plancha(t_concreto.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

	glPopMatrix();	//General

	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
		glColor3f(1.0,0.0,0.0);
		pintaTexto(-12,12.0,-14.0,(void *)font,"Proyecto");
		pintaTexto(-12,10.5,-14,(void *)font,"Edificio");
		glColor3f(1.0,1.0,1.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.001;
	fig3.text_der-= 0.001;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;

	
	glutPostRedisplay();
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case ' ':		//Poner algo en movimiento
			//Commit?
			printf("X = %f\n", Lx);
			printf("Y = %f\n", Ly);
			printf("Z = %f\n\n", Lz);
			/*printf("mPos.x = %f\tmPos.y = %f\tmPos.z = %f\n",objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z);
			printf("mView.x = %f\tmView.y = %f\tmView.z = %f\n", objCamera.mView.x, objCamera.mView.y, objCamera.mView.z);
			printf("mUp.x = %f\tmUp.y = %f\tmUp.z = %f\n", objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
			printf("glookupdown = %f\n", g_lookupdown);
			printf("CAMERASPEED: %f\n", CAMERASPEED);
			printf("******************************************\n");*/
			
			break;
		case '0':	//Original
			objCamera.Position_Camera(10, 2.5f, 13, 10, 2.5f, 10, 0, 1, 0);
			g_lookupdown = 0.0;
			break;
		case '1':	//Top
		/*
		void CCamera::Position_Camera(float pos_x,  float pos_y,  float pos_z,
							  float view_x, float view_y, float view_z,
							  float up_x,   float up_y,   float up_z)
		*/
			g_lookupdown = 119.0;
			objCamera.Position_Camera(7.18, 42.8, -5.63, 7.18, 44.5, -8.63, objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
			break;
		case '2':	//Front
			g_lookupdown = 0.0;
			objCamera.Position_Camera(2.95, 3.9, 44.59, 2.95, 3.9, 41.59, objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
			break;
		case '3':	//Right
			g_lookupdown = 0.0;
			objCamera.Position_Camera(45.73, 4.6, -3.63, 42.73, 4.6, -3.72, objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
			break;
		case '4':	//Left
			g_lookupdown = 0.0;
			objCamera.Position_Camera(-36.92, 4.6, -4.69, -33.92, 4.6, -4.63, objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
			break;
		case '5':
			Lz += 1.0;
			break;
		case '6':
			Lx += 1.0;
			break;
		case '8':
			Ly += 1.0;
			break;
		case 'i':
			Ly -= 1.0;
			break;
		case 'k':
			Lz -= 1.0;
			break;
		case 'l':
			Lx -= 1.0;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }

  glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (1600, 900);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 10"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
