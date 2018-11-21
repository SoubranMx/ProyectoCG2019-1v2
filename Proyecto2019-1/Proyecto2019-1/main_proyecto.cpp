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


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

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
/*CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01*/

CFiguras fig1;
//CFiguras fig2;*/
CFiguras fig3;
/*CFiguras fig4;	//Pasto01
CFiguras fig5;	//Casa01
CFiguras fig6;*/

//Texturas usadas
CTexture t_pasto;
CTexture t_concreto;
CTexture t_tierra;
CTexture t_tile1;	//Fachada de Torres Altas?
CTexture t_dado;
CTexture t_tree;
CTexture t_tree2;

//Texturas de LabCG
CTexture t_fumar;
CTexture t_comer;
CTexture t_hablar;
CTexture t_celular;
CTexture t_pizarron;
CTexture t_ventana;
CTexture t_pisoCG;
CTexture t_metalCG;
CTexture t_techoCG;

GLuint t_LabCG [9];

CTexture t_pizarronCG;

//Texturas de Salon
CTexture t_ventanaI;
CTexture t_pared;

GLuint t_aulaI [4];	//ventana, pared, piso, techo

//Figuras a "mano"
CFiguras plancha;
CFiguras torreIzquierda;
CFiguras torreMedia;
CFiguras torreDerecha;
CFiguras jardinera;
CFiguras tree;
CFiguras salon;

//Figuras de 3D Studio
CModel hammer;
CModel cubo;
CModel coche;

CModel streetLamp;
CModel pc_Pro;
CModel pc_Old;
CModel sillaClase;
CModel sillaLab;
CModel desk;
CModel trashCan;


CModel banca;

//Auxiliares para dejar en su lugar cualquier cosa cuando la mueves con 568 o kli
float  Lx = 0.0;
float  Ly = 0.0;
float  Lz = 0.0;
float aux = 0.0;

float iPizCG = 1.0;
float jPizCG = 0.0;
float iTree = 0.0;
float jTree = 0.0;
float iLamp = 0.0;
float jLamp = 0.0;

// Banderas
bool banderaCG = false;	//para mostrar las PC, son pesadas.
bool banderaAula = false;
bool f_PizarronCG = false;
bool f_TreeCG = false;
bool f_LampCG = false;
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

//ANIMACION
bool cameraMode = false;
float giro_llanta = 0.0f;
bool loop_animacion = true;

float UpX = 0.0;

//END ANIMACION
			
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

//	TEXTURAS LAB CG
	t_fumar.LoadTGA("Texturas/CG/noFumar.tga");
	t_fumar.BuildGLTexture();
	t_fumar.ReleaseImage();

	t_comer.LoadTGA("Texturas/CG/noComer.tga");
	t_comer.BuildGLTexture();
	t_comer.ReleaseImage();

	t_hablar.LoadTGA("Texturas/CG/noHablar.tga");
	t_hablar.BuildGLTexture();
	t_hablar.ReleaseImage();

	t_celular.LoadTGA("Texturas/CG/noCelular.tga");
	t_celular.BuildGLTexture();
	t_celular.ReleaseImage();

	t_pizarron.LoadTGA("Texturas/CG/pizarron2.tga");
	t_pizarron.BuildGLTexture();
	t_pizarron.ReleaseImage();

	t_ventana.LoadTGA("Texturas/CG/ventana.tga");
	t_ventana.BuildGLTexture();
	t_ventana.ReleaseImage();

	t_pisoCG.LoadTGA("Texturas/CG/pisoCG.tga");
	t_pisoCG.BuildGLTexture();
	t_pisoCG.ReleaseImage();

	t_metalCG.LoadTGA("Texturas/CG/metalCG.tga");
	t_metalCG.BuildGLTexture();
	t_metalCG.ReleaseImage();

	t_techoCG.LoadTGA("Texturas/CG/techo.tga");
	t_techoCG.BuildGLTexture();
	t_techoCG.ReleaseImage();

	t_LabCG[0] = t_fumar.GLindex;
	t_LabCG[1] = t_comer.GLindex;
	t_LabCG[2] = t_hablar.GLindex;
	t_LabCG[3] = t_celular.GLindex;
	t_LabCG[4] = t_pizarron.GLindex;
	t_LabCG[5] = t_ventana.GLindex;
	t_LabCG[6] = t_pisoCG.GLindex;
	t_LabCG[7] = t_metalCG.GLindex;
	t_LabCG[8] = t_techoCG.GLindex;

	t_pizarronCG.LoadTGA("Texturas/CG/labCG.tga");
	t_pizarronCG.BuildGLTexture();
	t_pizarronCG.ReleaseImage();
	
	//Texturas de Salon I
	t_pared.LoadTGA("Texturas/Salon/pared.tga");
	t_pared.BuildGLTexture();
	t_pared.ReleaseImage();

	t_ventanaI.LoadTGA("Texturas/Salon/ventana.tga");
	t_ventanaI.BuildGLTexture();
	t_ventanaI.ReleaseImage();

	t_aulaI[0] = t_pared.GLindex;
	t_aulaI[1] = t_ventanaI.GLindex;
	t_aulaI[2] = t_pisoCG.GLindex;
	t_aulaI[3] = t_techoCG.GLindex;

	//Carga de Figuras

	streetLamp._3dsLoad("Modelos/streetLamp.3DS");
	streetLamp.VertexNormals();

	pc_Pro._3dsLoad("Modelos/pcPro.3DS");	//Buen modelo

	// Por una razón que sigo sin comprender, no tienen texturas ni materiales... kinda pssed off.
	sillaClase._3dsLoad("Modelos/sillaClase.3DS");	
	sillaLab._3dsLoad("Modelos/Vitra03_3DS.3DS");		//Por alguna razón, no importó las patas de la derecha ???
	//sillaLab._3dsLoad("Modelos/chair.3DS");		//Por alguna razón, no importó las patas de la derecha ???
	trashCan._3dsLoad("Modelos/bin.3DS");

	desk._3dsLoad("Modelos/desk.3ds");
	desk.VertexNormals();
	
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
			glPushMatrix();
				glRotatef(iTree, 0.0, 1.0, 0.0);
				glTranslatef(0.0, jTree, 0.0);
				tree.tree(t_tree.GLindex);
			glPopMatrix();
			//tree.tree(t_tree.GLindex);
		glPopMatrix();
	glPopMatrix();
	glPushMatrix();	//H
		glTranslatef(13.0, 1.052, 12.0);
		glPushMatrix();	//Arbol
			glTranslatef(5.0, 0.0, -4.0);
			glPushMatrix();
				glRotatef(iTree, 0.0, 1.0, 0.0);
				glTranslatef(0.0, jTree, 0.0);
				tree.tree(t_tree.GLindex);
			glPopMatrix();
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
		//	tree.tree(t_tree2.GLindex);
			glPushMatrix();
				glRotatef(iTree, 0.0, 1.0, 0.0);
				glTranslatef(0.0, jTree, 0.0);
				tree.tree(t_tree2.GLindex);
			glPopMatrix();
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
			glPushMatrix();
				glRotatef(iTree, 0.0, 1.0, 0.0);
				glTranslatef(0.0, jTree, 0.0);
			tree.tree(t_tree2.GLindex);
			glPopMatrix();
			//tree.tree(t_tree2.GLindex);
		glPopMatrix();
		glRotatef(-90, 0.0, 1.0, 0.0);
		glDisable(GL_LIGHTING);
		jardinera.jardineraE(t_tierra.GLindex, t_pasto.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();	//I
		glTranslatef(-6.0, 0.052, 20.0);
		glPushMatrix();	//Lampara
			glTranslatef(-21,0.4,-11.2);
			glScalef(0.05, 0.05, 0.05);
			glPushMatrix();
				glTranslatef(iLamp, 0.0, 0.0);
				streetLamp.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
		glPopMatrix();
		glDisable(GL_LIGHTING);
		jardinera.jardineraI(t_tierra.GLindex, t_pasto.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();	//J
		glTranslatef(6.0, 1.052, 20.0);
		glPushMatrix();	//Lampara
			glTranslatef(-8.2,-0.5,-11.2);
			glScalef(0.05, 0.05, 0.05);
			glPushMatrix();
				glTranslatef(-jLamp, 0.0, 0.0);
				streetLamp.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();
		glPopMatrix();
		glRotatef(180, 0.0, 0.0, 1.0);
		glDisable(GL_LIGHTING);
		jardinera.jardineraJ(t_tierra.GLindex, t_pasto.GLindex);
		glEnable(GL_LIGHTING);
	glPopMatrix();
}

void pruebas() {
	glDisable(GL_COLOR_MATERIAL);
	glPushMatrix();
		glTranslatef(0.0, 0.0, 20.0);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(0.008, 0.008, 0.008);
		sillaLab.GLrender(NULL, _SHADED, 1.0);
	glPopMatrix();
	glEnable(GL_COLOR_MATERIAL);
}

void laboratorio() {
	
	glPushMatrix();
		glTranslatef(-8.0, 3.0, -5.0);
		salon.labCG(t_LabCG, 8.0, 3.0, 7.0);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);	//Fix? en realidad no tendria que funcionar pero ... bueno. Arregla el problema de la posición del laboratorio.
		glPushMatrix();
			glTranslatef(0.0, 0.0, -3.495);
			glPushMatrix();//Pizarron
				glBindTexture(GL_TEXTURE_2D, t_pizarron.GLindex);
				glTranslatef(-1.5, -1.2, 0.0);
				glScalef(4.5, 4.5, 1.0);
				glBegin(GL_POLYGON);
					glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.5, 0.0);	//6
					glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0.0);	//5
					glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.0, 0.0);	//3
					glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);	//2
				glEnd();
				// ANIMACION
				glBindTexture(GL_TEXTURE_2D, t_pizarronCG.GLindex);
				glTranslatef(0.03, 0.03, 0.0);
				glBegin(GL_POLYGON);
					glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2f(jPizCG      , iPizCG);		glVertex3f(0.0, 0.4, 0.1);
					glTexCoord2f(jPizCG+0.166, iPizCG);		glVertex3f(0.4, 0.4, 0.1);
					glTexCoord2f(jPizCG+0.166, iPizCG-0.2); glVertex3f(0.4, 0.0, 0.1);
					glTexCoord2f(jPizCG      , iPizCG-0.2); glVertex3f(0.0, 0.0, 0.1);
				glEnd();
			glPopMatrix();

			glPushMatrix();
			//NoFumar
				glBindTexture(GL_TEXTURE_2D, t_fumar.GLindex);
				glTranslatef(-1.2, 1.13, -3.490);
				glScalef(0.5, 0.5, 1.0);
				glBegin(GL_POLYGON);
					glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.5, 0.0);	//6
					glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0.0);	//5
					glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.0, 0.0);	//3
					glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);	//2
				glEnd();
			//NoComer
				glTranslatef(-0.6, 0.0, 0.0);
				glBindTexture(GL_TEXTURE_2D, t_comer.GLindex);
				glBegin(GL_POLYGON);
					glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.5, 0.0);	//6
					glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0.0);	//5
					glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.0, 0.0);	//3
					glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);	//2
				glEnd();
			//NoHablar
				glTranslatef(3.4, 0.0, 0.0);
				glBindTexture(GL_TEXTURE_2D, t_hablar.GLindex);
				glBegin(GL_POLYGON);
					glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.5, 0.0);	//6
					glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0.0);	//5
					glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.0, 0.0);	//3
					glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);	//2
				glEnd();
			//NoCelular
				glTranslatef(0.6, 0.0, 0.0);
				glBindTexture(GL_TEXTURE_2D, t_celular.GLindex);
				glBegin(GL_POLYGON);
					glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.5, 0.0);	//6
					glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0.0);	//5
					glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.0, 0.0);	//3
					glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);	//2
				glEnd();
			glPopMatrix();

			//MetalCG
			glPushMatrix();
				glTranslatef(-0.8, -1.49, -3.5);
				glBindTexture(GL_TEXTURE_2D, t_metalCG.GLindex);
				glBegin(GL_POLYGON);
					glNormal3f(0.0f, 1.0f, 0.0f);
					glTexCoord2f(0.0f, 7.0f); glVertex3f(0.0, 0.0, 7.0);	//6
					glTexCoord2f(1.0f, 7.0f); glVertex3f(0.5, 0.0, 7.0);	//5
					glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.0, 0.0);	//3
					glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);	//2
				glEnd();
			glPopMatrix();

		//	FIGURAS 3D
			glDisable(GL_COLOR_MATERIAL);
			
			//No puedo poner las PC con push y pop, desaparecen los renders ???
			glPushMatrix();	//Desk4	frente
				glTranslatef(0.5, -1.5, -1.7);
				glScalef(0.010, 0.005, 0.005);
				desk.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix();	//Desk3 frente
				glTranslatef(-3.5, -1.5, -1.7);
				glScalef(0.008, 0.005, 0.005);
				desk.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix();	//Desk4 medio
				glTranslatef(0.5, -1.5, 0.0);
				glScalef(0.01, 0.005, 0.005);
				desk.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix();	//Desk3 medio
				glTranslatef(-3.5, -1.5, 0.0);
				glScalef(0.008, 0.005, 0.005);
				desk.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix();	//Desk4 atras
				glTranslatef(0.5, -1.5, 2.0);
				glScalef(0.01, 0.005, 0.005);
				desk.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();

			glPushMatrix();	//Desk3 atras
				glTranslatef(-3.5, -1.5, 1.8);
				glScalef(0.008, 0.005, 0.005);
				desk.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix();


		//PC's
			if (banderaCG == true) {
				aux = -1.8;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						glPushMatrix();
							glTranslatef(-3.5 + j, -0.81, aux);	//-3.5, -0.8, -1.8
							//glTranslatef(Lx, -0.8, -1.8);
							glScalef(0.008, 0.008, 0.008);
							pc_Pro.GLrender(NULL, _SHADED, 1.0);
						glPopMatrix();
					}
					aux += 1.8;
				}

				aux = -1.8;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 4; j++) {
						glPushMatrix();
							glTranslatef(0.5 + j, -0.81, aux);	//-3.5, -0.8, -1.8
							//glTranslatef(-3.5+Lx, -0.8+Ly, -1.8+1.8+1.8);
							glScalef(0.008, 0.008, 0.008);
							pc_Pro.GLrender(NULL, _SHADED, 1.0);
						glPopMatrix();
					}
					aux += 1.8;
				}

		//	SILLAS
				aux = -1.0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						glPushMatrix();
						glTranslatef(-3.5 + j * 0.98, -1.5, aux);
						glRotatef(180, 0.0, 1.0, 0.0);
						//glScalef(0.01, 0.015, 0.01);
						glScalef(0.03, 0.04, 0.02);
						sillaLab.GLrender(NULL, _SHADED, 1.0);
						glPopMatrix();
					}
					aux += 1.8;
				}

				aux = -1.0;
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 4; j++) {
						glPushMatrix();
							glTranslatef(0.5 + j*0.9, -1.5, aux);
							glRotatef(180, 0.0, 1.0, 0.0);
							//glScalef(0.01, 0.015, 0.01);
							glScalef(0.03, 0.04, 0.02);
							sillaLab.GLrender(NULL, _SHADED, 1.0);
						glPopMatrix();
					}
					aux += 1.8;
				}
			}//	If
			glEnable(GL_COLOR_MATERIAL);
		glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

void aula() {
	glPushMatrix();	//Push General
		glTranslatef(8.0, 3.0, -5.0);
		salon.aulaI(t_aulaI, 8.0, 3.0, 7.0);
		glPushMatrix();// Push del fix?
			glTranslatef(0.0, 0.0, 0.0);
			glPushMatrix();	//Pizarron
				glBindTexture(GL_TEXTURE_2D, t_pizarron.GLindex);
				glTranslatef(0.0, -1.0, 3.495);
				glRotatef(180, 0.0, 1.0, 0.0);
				glScalef(7.0, 4.5, 1.0);
				glBegin(GL_POLYGON);
					glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.5, 0.0);	//6
					glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0.0);	//5
					glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.0, 0.0);	//3
					glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);	//2
				glEnd();
			glPopMatrix();	//Pop Pizarron
			glPushMatrix();	//Pizarron	izquierda
				glBindTexture(GL_TEXTURE_2D, t_pizarron.GLindex);
				glTranslatef(2.0, -1.0, 3.495);
				glRotatef(180, 0.0, 1.0, 0.0);
				glScalef(3.0, 4.5, 1.0);
				glBegin(GL_POLYGON);
					glNormal3f(0.0f, 0.0f, 1.0f);
					glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.5, 0.0);	//6
					glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0.0);	//5
					glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.0, 0.0);	//3
					glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);	//2
				glEnd();
			glPopMatrix();	//Pop Pizarron izquierdo

			glPushMatrix();		//Push para el IF banderaAUla
		/*
		Acá harias algo parecido a esto para poner las sillas.
		Tienes que identificar la escala de cada silla para que no se vean demasiado chicas o grandes.
		Rotarlas en Y para que queden viendo hacia los pizarrones.

		Además de eso, habría que poner otros dos escritorio enfrente y una PC a un lado.
		Fuera de eso, podrias poner otro plano en la izquierda para que se vea una puerta, pero eso puede quedar fuera.

		//	SILLAS
		if (banderaAula == true) {

		/* 
		banderaAula es para que la carga no sea tan pesada, se acciona con espacio tanto para aula como para el laboratorio.
		Eso genera que se dibujen en pantalla los objetos.

		Dentro de este if, tienes que poner todos los modelos cargados, que te recomiendo sean:
		
			*	sillaClase.GLrender(NULL, _SHADED, 1.0);
			*	desk.GLrender(NULL, _SHADED, 1.0);
			*	pc_Pro.GLrender(NULL, _SHADED, 1.0);

			Es como cargar prismas, antes de todo los tienes que colocar con translatef en sus lugares, escalarlos y girarlos, y una vez hecho eso los instancias con el GLrender.
			Si ya tienes algunos modelos y quieres usarlos, tienes que declararlos como están hasta arriba (Con CModel) y luego cargarlos en la función init.
		*/
		/*
		
				//	Estos ints son para generar las sillas en filas y columnas. Mas o menos unos 40? el primer for es para las filas, el otro para las columnas.
				//	en el translate, ahi tendrás que jugar con algunos valores para que veas como se van generando.
				//	el 3.5 es por ejemplo de donde empiezan a generarse las sillas, ese lo modificas para que inicien por ejemplo desde la izquierda (si ves el pizarron) y el j*algo es lo que le genera distancia entre si.
				//	Los demás ... creo que no es necesario cambiarlos, chance solo la coordenada Y para ponerlas en su lugar.
				aux = -1.0;
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 8; j++) {
						glPushMatrix();
							glTranslatef(3.5 + j * 0.98, -1.5, aux);
							glRotatef(180, 0.0, 1.0, 0.0);
							glScalef(0.03, 0.04, 0.02);
							sillaClase.GLrender(NULL, _SHADED, 1.0);
						glPopMatrix();
					}
					aux += 1.8;
				}
			}//	If
		*/
			glPopMatrix();	//Pop de banderaAula
		glPopMatrix();	//Pop del fix
	glPopMatrix();	//Pop General
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
			
			//pruebas();
			laboratorio();
			aula();

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
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 150)
	{
		//Animacion Pizarron
		if (f_PizarronCG == true) {

			if (iPizCG >= 0) {
				iPizCG -= 0.2;
				if (jPizCG <= 1.0) {
					jPizCG += 0.166;
				}
				else
					jPizCG = 0.0;
			}
			else {
				iPizCG = 1.0;
			}
		}
			

		dwLastUpdateTime = dwCurrentTime;
	}
	if (dwElapsedTime >= 30)
	{

		if (f_TreeCG == true) {
			if (jTree <= 10) {
				jTree += 0.2;
				iTree += 1.5;
			}
			else {
				jTree = 0.0;
				iTree = 0.0;
			}
		}

		dwLastUpdateTime = dwCurrentTime;
	}
	if (dwElapsedTime >= 30)
	{
		if (f_LampCG == true) {
			if (iLamp <= 500) {
				iLamp+=2;
			}
			else
				iLamp = 0;
			if (jLamp <= 500) {
				jLamp+=2;
			}
			else
				jLamp = 0;
		}
		dwLastUpdateTime = dwCurrentTime;
	}
	
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
			//printf("X = %f\n", Lx);
			//printf("Y = %f\n", Ly);
			//printf("Z = %f\n\n", Lz);
			/*printf("mPos.x = %f\tmPos.y = %f\tmPos.z = %f\n",objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z);
			printf("mView.x = %f\tmView.y = %f\tmView.z = %f\n", objCamera.mView.x, objCamera.mView.y, objCamera.mView.z);
			printf("mUp.x = %f\tmUp.y = %f\tmUp.z = %f\n", objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
			printf("glookupdown = %f\n", g_lookupdown);
			printf("CAMERASPEED: %f\n", CAMERASPEED);
			printf("******************************************\n");*/
			
			//Activa y desactiva la carga de modelos
			banderaCG = !banderaCG;
			banderaAula = !banderaAula;

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
			//Laboratorio
			g_lookupdown = 14.0;
			objCamera.Position_Camera(-11.88, 3.9, -1.698, -9.65, 3.9, -3.701, objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);

			//banderaCG = !banderaCG;
			//Lz += 1.0;
			break;
		case '6':
			//Salon
			g_lookupdown = 14.0;
			objCamera.Position_Camera(4.211, 3.9, -3.035, 6.907, 3.9, -4.344, objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);
			break;
		case '7':
			f_LampCG = !f_LampCG;
			iLamp = 0.0;
			break;
		case '8':
			f_TreeCG = !f_TreeCG;
			iTree = 0.0;
			jTree = 0.0;
			break;
		case '9':
			f_PizarronCG = !f_PizarronCG;
			iPizCG = 1.0;
			jPizCG = 0.0;
			break;
		case 'i':
			Ly += 0.5;
			break;
		case 'I':
			Ly -= 0.5;
			break;
		case 'k':
			Lz += 0.5;
			break;
		case 'K':
			Lz -= 0.5;
			break;
		case 'l':
			Lx += 0.5;
			break;
		case 'L':
			Lx -= 0.5;
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
  glutCreateWindow    ("Proyecto Final"); // Nombre de la Ventana
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
