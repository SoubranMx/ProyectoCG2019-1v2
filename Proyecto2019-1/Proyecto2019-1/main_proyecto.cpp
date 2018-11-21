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

//	*********************	KEYFRAMES ***************
float angleDedoI = 0.0f;
float angleDedoE = 0.0f;
float angleCodo = 0.0f;
float angleBrazo = 0.0f;

float transZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

float red[3] = { 1.0, 0.0, 0.0 };
float green[3] = { 0.0,1.0,0.0 };
float blue[3] = { 0.0,0.0,1.0 };
float white[3] = { 1.0,1.0,1.0 };
float yellow[3] = { 1.0,1.0,0.0 };

#define MAX_FRAMES 15		//5 keyframes
int i_max_steps = 90;		//Cantidad de cuadros intermedios	valores pequeños: animacion rápida, valores grandes: animación más pausada
int i_curr_steps = 0;

typedef struct _frame {
	//Variables para guardar KeyFrames
	float angleDedoI;
	float angleDedoE;
	float angleCodo;
	float angleBrazo;

	float transZ;
	float transX;
	float transY;

	float angleX;
	float angleY;
	float angleZ;

	//Incrementos
	float angleDedoIinc;
	float angleDedoEinc;
	float angleCodoinc;
	float angleBrazoinc;

	float transXinc;
	float transYinc;
	float transZinc;

	float angleXinc;
	float angleYinc;
	float angleZinc;

} FRAME;
FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;			//introducir datos
bool play = false;
int playIndex = 0;
int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

//	*********************	KEYFRAMES ***************			

void saveFrame(void) {
	printf("frameindex %d\n", FrameIndex);

	KeyFrame[FrameIndex].transX = transX;
	KeyFrame[FrameIndex].transY = transY;
	KeyFrame[FrameIndex].transZ = transZ;

	KeyFrame[FrameIndex].angleDedoI = angleDedoI;
	KeyFrame[FrameIndex].angleDedoE = angleDedoE;
	KeyFrame[FrameIndex].angleCodo = angleCodo;
	KeyFrame[FrameIndex].angleBrazo = angleBrazo;

	KeyFrame[FrameIndex].angleX = angleX;
	KeyFrame[FrameIndex].angleY = angleY;
	KeyFrame[FrameIndex].angleZ = angleZ;

	FrameIndex++;
}
void resetElements(void)
{
	transX = KeyFrame[0].transX;
	transY = KeyFrame[0].transY;
	transZ = KeyFrame[0].transZ;

	angleDedoI = KeyFrame[0].angleDedoI;
	angleDedoE = KeyFrame[0].angleDedoE;
	angleCodo = KeyFrame[0].angleCodo;
	angleBrazo = KeyFrame[0].angleBrazo;

	angleX = KeyFrame[0].angleX;
	angleY = KeyFrame[0].angleY;
	angleZ = KeyFrame[0].angleZ;
}
void interpolation(void)
{
	//Los incrementos
	KeyFrame[playIndex].transXinc = (KeyFrame[playIndex + 1].transX - KeyFrame[playIndex].transX) / i_max_steps;
	KeyFrame[playIndex].transYinc = (KeyFrame[playIndex + 1].transY - KeyFrame[playIndex].transY) / i_max_steps;
	KeyFrame[playIndex].transZinc = (KeyFrame[playIndex + 1].transZ - KeyFrame[playIndex].transZ) / i_max_steps;

	KeyFrame[playIndex].angleDedoIinc = (KeyFrame[playIndex + 1].angleDedoI - KeyFrame[playIndex].angleDedoI) / i_max_steps;
	KeyFrame[playIndex].angleDedoEinc = (KeyFrame[playIndex + 1].angleDedoE - KeyFrame[playIndex].angleDedoE) / i_max_steps;
	KeyFrame[playIndex].angleCodoinc = (KeyFrame[playIndex + 1].angleCodo - KeyFrame[playIndex].angleCodo) / i_max_steps;
	KeyFrame[playIndex].angleBrazoinc = (KeyFrame[playIndex + 1].angleBrazo - KeyFrame[playIndex].angleBrazo) / i_max_steps;

	KeyFrame[playIndex].angleXinc = (KeyFrame[playIndex + 1].angleX - KeyFrame[playIndex].angleX) / i_max_steps;
	KeyFrame[playIndex].angleYinc = (KeyFrame[playIndex + 1].angleY - KeyFrame[playIndex].angleY) / i_max_steps;
	KeyFrame[playIndex].angleZinc = (KeyFrame[playIndex + 1].angleZ - KeyFrame[playIndex].angleZ) / i_max_steps;
}

//	*************	KEY FRAMES	*********************
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

	//	**************	KEY FRAMES	**************
	for (int i = 0; i < MAX_FRAMES; i++)
	{
		KeyFrame[i].transX = 0;
		KeyFrame[i].transY = 0;
		KeyFrame[i].transZ = 0;

		KeyFrame[i].angleDedoI = 0;
		KeyFrame[i].angleDedoE = 0;
		KeyFrame[i].angleCodo = 0;
		KeyFrame[i].angleBrazo = 0;

		KeyFrame[i].angleX = 0;
		KeyFrame[i].angleY = 0;
		KeyFrame[i].angleZ = 0;

		KeyFrame[i].transXinc = 0;
		KeyFrame[i].transYinc = 0;
		KeyFrame[i].transZinc = 0;

		KeyFrame[i].angleDedoIinc = 0;
		KeyFrame[i].angleDedoEinc = 0;
		KeyFrame[i].angleCodoinc = 0;
		KeyFrame[i].angleBrazoinc = 0;

		KeyFrame[i].angleXinc = 0;
		KeyFrame[i].angleYinc = 0;
		KeyFrame[i].angleZinc = 0;
	}

	//Frame 0
	KeyFrame[0].transX = 0.0;
	KeyFrame[0].transY = 0.0;
	KeyFrame[0].transZ = 0.0;

	KeyFrame[0].angleDedoI = 0.0;
	KeyFrame[0].angleDedoE = 0.0;
	KeyFrame[0].angleCodo = 0.0;
	KeyFrame[0].angleBrazo = 0.0;

	KeyFrame[0].angleX = 0.0;
	KeyFrame[0].angleY = 0.0;
	KeyFrame[0].angleZ = 0.0;

	KeyFrame[0].transXinc = 0.0;
	KeyFrame[0].transYinc = 0.0;
	KeyFrame[0].transZinc = 0.0;

	KeyFrame[0].angleDedoIinc = -1.0;
	KeyFrame[0].angleDedoEinc = 0.0;
	KeyFrame[0].angleCodoinc = 0.266;
	KeyFrame[0].angleBrazoinc = 0.088;

	KeyFrame[0].angleXinc = 0.0;
	KeyFrame[0].angleYinc = 0.0;
	KeyFrame[0].angleZinc = 0.0;

	//Frame 1
	KeyFrame[1].transX = 0.0;
	KeyFrame[1].transY = 0.0;
	KeyFrame[1].transZ = 0.0;

	KeyFrame[1].angleDedoI = -90.0;
	KeyFrame[1].angleDedoE = 0.0;
	KeyFrame[1].angleCodo = 24.0;
	KeyFrame[1].angleBrazo = 8.0;

	KeyFrame[1].angleX = 0.0;
	KeyFrame[1].angleY = 0.0;
	KeyFrame[1].angleZ = 0.0;

	KeyFrame[1].transXinc = -0.0133;
	KeyFrame[1].transYinc = 0.0;
	KeyFrame[1].transZinc = 0.0;

	KeyFrame[1].angleDedoIinc = 0.0;
	KeyFrame[1].angleDedoEinc = -1.0;
	KeyFrame[1].angleCodoinc = 0.333;
	KeyFrame[1].angleBrazoinc = -0.244;

	KeyFrame[1].angleXinc = -0.0166;
	KeyFrame[1].angleYinc = -0.4166;
	KeyFrame[1].angleZinc = 0.0;

	//Frame 2
	KeyFrame[2].transX = -1.2;
	KeyFrame[2].transY = 0.0;
	KeyFrame[2].transZ = 0.0;

	KeyFrame[2].angleDedoI = -90.0;
	KeyFrame[2].angleDedoE = -90.0;
	KeyFrame[2].angleCodo = 54.0;
	KeyFrame[2].angleBrazo = -14.0;

	KeyFrame[2].angleX = -1.5;
	KeyFrame[2].angleY = -37.5;
	KeyFrame[2].angleZ = 0.0;

	KeyFrame[2].transXinc = 0.0;
	KeyFrame[2].transYinc = 0.0;
	KeyFrame[2].transZinc = 0.0;

	KeyFrame[2].angleDedoIinc = 1.0;
	KeyFrame[2].angleDedoEinc = 0.0;
	KeyFrame[2].angleCodoinc = 0.0;
	KeyFrame[2].angleBrazoinc = 0.577;

	KeyFrame[2].angleXinc = 0.2166;
	KeyFrame[2].angleYinc = -0.4611;
	KeyFrame[2].angleZinc = 0.0;

	//Frame 3
	KeyFrame[3].transX = -1.2;
	KeyFrame[3].transY = 0.0;
	KeyFrame[3].transZ = 0.0;

	KeyFrame[3].angleDedoI = 0.0;
	KeyFrame[3].angleDedoE = -90.0;
	KeyFrame[3].angleCodo = 54.0;
	KeyFrame[3].angleBrazo = 38.0;

	KeyFrame[3].angleX = 18.0;
	KeyFrame[3].angleY = -79.0;
	KeyFrame[3].angleZ = 0.0;

	KeyFrame[3].transXinc = 0.0044;
	KeyFrame[3].transYinc = 0.0;
	KeyFrame[3].transZinc = 0.0;

	KeyFrame[3].angleDedoIinc = -0.311;
	KeyFrame[3].angleDedoEinc = 0.0;
	KeyFrame[3].angleCodoinc = -0.111;
	KeyFrame[3].angleBrazoinc = -0.1777;

	KeyFrame[3].angleXinc = -0.0055;
	KeyFrame[3].angleYinc = 0.62777;
	KeyFrame[3].angleZinc = 0.0;

	//Frame 4
	KeyFrame[4].transX = -0.7999;
	KeyFrame[4].transY = 0.0;
	KeyFrame[4].transZ = 0.0;

	KeyFrame[4].angleDedoI = -28.0;
	KeyFrame[4].angleDedoE = -90.0;
	KeyFrame[4].angleCodo = 43.999;
	KeyFrame[4].angleBrazo = 22.00008;

	KeyFrame[4].angleX = 17.4999;
	KeyFrame[4].angleY = -22.5;
	KeyFrame[4].angleZ = 0.0;

	KeyFrame[4].transXinc = 0.0177;
	KeyFrame[4].transYinc = 0.0;
	KeyFrame[4].transZinc = 0.0;

	KeyFrame[4].angleDedoIinc = -0.377;
	KeyFrame[4].angleDedoEinc = 0.533;
	KeyFrame[4].angleCodoinc = -0.0444;
	KeyFrame[4].angleBrazoinc = -0.2888;

	KeyFrame[4].angleXinc = -0.2166;
	KeyFrame[4].angleYinc = 0.0;
	KeyFrame[4].angleZinc = 0.0;

	//Frame 5
	KeyFrame[5].transX = 0.8;
	KeyFrame[5].transY = 0.0;
	KeyFrame[5].transZ = 0.0;

	KeyFrame[5].angleDedoI = -35.0;
	KeyFrame[5].angleDedoE = -42.0;
	KeyFrame[5].angleCodo = 39.999;
	KeyFrame[5].angleBrazo = -3.999;

	KeyFrame[5].angleX = -2.0;
	KeyFrame[5].angleY = -22.50;
	KeyFrame[5].angleZ = 0.0;

	KeyFrame[5].transXinc = 0.0;
	KeyFrame[5].transYinc = 0.0133;
	KeyFrame[5].transZinc = -0.00222;

	KeyFrame[5].angleDedoIinc = -0.333;
	KeyFrame[5].angleDedoEinc = 0.488;
	KeyFrame[5].angleCodoinc = -0.4222;
	KeyFrame[5].angleBrazoinc = 0.2;

	KeyFrame[5].angleXinc = 0.1944;
	KeyFrame[5].angleYinc = 0.0;
	KeyFrame[5].angleZinc = 0.0;

	//Frame 6
	KeyFrame[6].transX = 0.8;
	KeyFrame[6].transY = 1.2;
	KeyFrame[6].transZ = -0.2;

	KeyFrame[6].angleDedoI = -92.0;
	KeyFrame[6].angleDedoE = 2.0;
	KeyFrame[6].angleCodo = 2.0;
	KeyFrame[6].angleBrazo = 14.0;

	KeyFrame[6].angleX = 15.499;
	KeyFrame[6].angleY = -22.5004;
	KeyFrame[6].angleZ = 0.0;

	KeyFrame[6].transXinc = 0.0;
	KeyFrame[6].transYinc = 0.0133;
	KeyFrame[6].transZinc = 0.0088;

	KeyFrame[6].angleDedoIinc = 0.0;
	KeyFrame[6].angleDedoEinc = -1.022;
	KeyFrame[6].angleCodoinc = 0.0;
	KeyFrame[6].angleBrazoinc = 0.0;

	KeyFrame[6].angleXinc = 1.5499;
	KeyFrame[6].angleYinc = 0.2166;
	KeyFrame[6].angleZinc = 0.0;

	//Frame 7
	KeyFrame[7].transX = 0.8;
	KeyFrame[7].transY = 2.4;
	KeyFrame[7].transZ = 0.6;

	KeyFrame[7].angleDedoI = -92.0;
	KeyFrame[7].angleDedoE = -90.0;
	KeyFrame[7].angleCodo = 2.0;
	KeyFrame[7].angleBrazo = 14.0;

	KeyFrame[7].angleX = 155.0;
	KeyFrame[7].angleY = -3.0;
	KeyFrame[7].angleZ = 0.0;

	KeyFrame[7].transXinc = 0.0;
	KeyFrame[7].transYinc = 0.0;
	KeyFrame[7].transZinc = 0.0;

	KeyFrame[7].angleDedoIinc = 1.044;
	KeyFrame[7].angleDedoEinc = 1.022;
	KeyFrame[7].angleCodoinc = 0.6;
	KeyFrame[7].angleBrazoinc = 0.022;

	KeyFrame[7].angleXinc = 1.9166;
	KeyFrame[7].angleYinc = 0.0;
	KeyFrame[7].angleZinc = 0.0;

	//Frame 8
	KeyFrame[8].transX = 0.8;
	KeyFrame[8].transY = 2.4;
	KeyFrame[8].transZ = 0.6;

	KeyFrame[8].angleDedoI = 2.0;
	KeyFrame[8].angleDedoE = 2.0;
	KeyFrame[8].angleCodo = 56.0;
	KeyFrame[8].angleBrazo = 16.0;

	KeyFrame[8].angleX = 327.5;
	KeyFrame[8].angleY = -3.0;
	KeyFrame[8].angleZ = 0.0;

	KeyFrame[8].transXinc = 0.0;
	KeyFrame[8].transYinc = 0.0;
	KeyFrame[8].transZinc = 0.0;

	KeyFrame[8].angleDedoIinc = 0.0;
	KeyFrame[8].angleDedoEinc = 0.0;
	KeyFrame[8].angleCodoinc = 0.0;
	KeyFrame[8].angleBrazoinc = 0.0;

	KeyFrame[8].angleXinc = 0.0;
	KeyFrame[8].angleYinc = 0.0;
	KeyFrame[8].angleZinc = 0.0;

	//Frame 9
	KeyFrame[9].transX = 0.0;
	KeyFrame[9].transY = 0.0;
	KeyFrame[9].transZ = 0.0;

	KeyFrame[9].angleDedoI = 0.0;
	KeyFrame[9].angleDedoE = 0.0;
	KeyFrame[9].angleCodo = 0.0;
	KeyFrame[9].angleBrazo = 0.0;

	KeyFrame[9].angleX = 0.0;
	KeyFrame[9].angleY = 0.0;
	KeyFrame[9].angleZ = 0.0;

	KeyFrame[9].transXinc = 0.0;
	KeyFrame[9].transYinc = 0.0;
	KeyFrame[9].transZinc = 0.0;

	KeyFrame[9].angleDedoIinc = 0.0;
	KeyFrame[9].angleDedoEinc = 0.0;
	KeyFrame[9].angleCodoinc = 0.0;
	KeyFrame[9].angleBrazoinc = 0.0;

	KeyFrame[9].angleXinc = 0.0;
	KeyFrame[9].angleYinc = 0.0;
	KeyFrame[9].angleZinc = 0.0;

	FrameIndex = 10;
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

void laboratorio() {
	
	glPushMatrix();
		glTranslatef(-8.0, 3.0, -5.0);
		salon.labCG(t_LabCG, 8.0, 3.0, 7.0);

		glPushMatrix();
		glTranslatef(0.0, 0.0, 3.495);	//Fix? en realidad no tendria que funcionar pero ... bueno. Arregla el problema de la posición del laboratorio.
		glPushMatrix();
			glTranslatef(0.0, 0.0, -3.495);
			//glTranslatef(0.0, 0.0, 0.0);
			glPushMatrix();//Pizarron
				glBindTexture(GL_TEXTURE_2D, t_pizarron.GLindex);
				glTranslatef(-1.5, -1.2, -3.495);
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
				glTranslatef(0.03, 0.03, -0.09);
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
	glDisable(GL_COLOR_MATERIAL);
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
		Fuera de eso, podrias poner otro plano en la izquierda para que se vea una puerta, pero eso puede quedar fuera.			*/


		//SILLAS
			if (banderaAula == true) {


				//	SILLAS
				aux = -3.0;
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 8; j++) {
						glPushMatrix();
						glTranslatef(-3.5 + j * 0.98, -1.5, aux);		//izq,
						glRotatef(-90, 0.0, 1.0, 0.0);
						glScalef(0.01, 0.015, 0.01);
						sillaClase.GLrender(NULL, _SHADED, 1.0);
						glPopMatrix();
					}
					aux += 1.0;
				}

				// ESCRITORIOS

				glPushMatrix();	//Desk1 frente
					glTranslatef(1.5, -1.5, 2.0);
					glScalef(0.005, 0.005, 0.005);
					desk.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();

				glPushMatrix();	//Desk2	lado
					glTranslatef(3.0, -1.5, 2.5);
					glRotatef(-90, 0.0, 1.0, 0.0);
					glScalef(0.003, 0.005, 0.005);
					desk.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();

				//PC

				glPushMatrix();
					glTranslatef(2.8, -0.8, 3.0);
					glRotatef(-90, 0.0, 1.0, 0.0);
					glScalef(0.008, 0.008, 0.008);
					pc_Pro.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(1.7 , -1.5, 3.0);
					glRotatef(180, 0.0, 1.0, 0.0);
					glScalef(0.03, 0.04, 0.02);
					sillaLab.GLrender(NULL, _SHADED, 1.0);
				glPopMatrix();
   
			}

			glPopMatrix();	//Pop de banderaAula
			glPopMatrix();	//Pop del fix
			glPopMatrix();	//Pop General
			glEnable(GL_COLOR_MATERIAL);
}
		
void prisma(float color[3])
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V7
	};

	glColor3fv(color);
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void dedoExterno(float rotate) {	//Solo debe generar un dedo y ya está
	glPushMatrix();
		glTranslatef(0.375, 0.0, 0.0);
		glRotatef(angleDedoE, 0.0, 0.0, rotate);	//Rotación Dedo Externo
		glTranslatef(0.250, 0.0, 0.0);
		//Construccion del dedo externo
		glPushMatrix();
			glScalef(0.5, 0.3, 0.25);
			prisma(white);
		glPopMatrix();
	glPopMatrix();

}

void dedoInterno(float x, float y, float z, float rotate) {
	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(angleDedoI, 0.0, 0.0, rotate);	//Rotación Dedo Interno
		glTranslatef(0.375, 0.0, 0.0);
		//Construccion del dedo Interno
		glPushMatrix();
			glScalef(0.75, 0.3, 0.25);
			prisma(green);
		glPopMatrix();
		dedoExterno(-rotate);
	glPopMatrix();

}

void parteC() {
	glPushMatrix();		//Dedos
		glTranslatef(1.0, 0.0, 0.0);
		//Pivote = 3.5,0,0
		glPushMatrix();
			//Dedos generalizados
			dedoInterno(0.0, 0.35, 0.375, -1.0);	//Genera Dedo C y D
			dedoInterno(0.0, 0.35, 0.0, -1.0);		//Genera Dedo G y H
			dedoInterno(0.0, 0.35, -0.375, -1.0);	//Genera Dedo I y J
			dedoInterno(0.0, -0.35, 0.375, 1.0);	//Genera Dedo E y F
		glPopMatrix();
	glPopMatrix();
}

void parteB() {
	glPushMatrix();		//Parte B
		glTranslatef(0.75, 0.0, 0.0);	//Pivote = 1.5,0,0
		glRotatef(angleCodo, 0.0, 0.0, 1.0);		//Rotación del CODO
		glTranslatef(1.0, 0.0, 0.0);
		//Pivote = 2.5,0,0
		glPushMatrix();
			glScalef(2.0, 1.0, 1.0);
			prisma(blue);
			//Prisma generado a partir de 2.5,0,0
		glPopMatrix();
		//Pivote = 2.5,0,0
		parteC();
	glPopMatrix();
}

void parteA() {
	glPushMatrix();		//Parte A
		//Pivote = 0,0,0
		glRotatef(angleBrazo, 0.0, 0.0, 1.0);	//Rotación a partir de 0,0,0.	Rotación del BRAZO
		glTranslatef(0.75, 0.0, 0.0);		//Si ya empezamos en 0,0,0 entonces de ahi rotar y generar la figura a partir de 0.75,0,0
		//Pivote 0.75,0,0
		glPushMatrix();
			glScalef(1.5, 1.0, 1.0);
			prisma(red);
			//Prisma generado a partir de 0.75,0,0
		glPopMatrix();
		//Pivote en 0.75,0,0
		parteB();

	glPopMatrix();
}

void pruebas() {
	glPushMatrix();
		glTranslatef(0.0, 1.0, 10.0);
		glPushMatrix();
			glEnable(GL_COLOR_MATERIAL);
			glTranslatef(transX, transY, transZ);
			glRotatef(angleY, 0.0, 1.0, 0.0);
			glRotatef(angleX, 1.0, 0.0, 0.0);
			glRotatef(angleZ, 0.0, 0.0, 1.0);
			//Poner Código Aquí.
			glPushMatrix();
				glRotatef(angleZ, 0.0, 0.0, 1.0);
				parteA();
			glPopMatrix();
			glDisable(GL_COLOR_MATERIAL);
		glPopMatrix();
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
			
			
			laboratorio();
			aula();

			pruebas();
			//	¿Porque se cambia el laboratorio=?!?!?!?!?!?
			

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

	if (dwElapsedTime >= 80)
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
	
	//Movimiento del brazo mecánico
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex > FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			transX += KeyFrame[playIndex].transXinc;
			transY += KeyFrame[playIndex].transYinc;
			transZ += KeyFrame[playIndex].transZinc;

			angleDedoI += KeyFrame[playIndex].angleDedoIinc;
			angleDedoE += KeyFrame[playIndex].angleDedoEinc;
			angleCodo += KeyFrame[playIndex].angleCodoinc;
			angleBrazo += KeyFrame[playIndex].angleBrazoinc;

			angleX += KeyFrame[playIndex].angleXinc;
			angleY += KeyFrame[playIndex].angleYinc;
			angleZ += KeyFrame[playIndex].angleZinc;


			i_curr_steps++;
		}

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
	float efe = 2.0;
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
		/*case 'i':
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
			break;*/

/*
		case 'u':
		case 'U':
			if (angleBrazo < 90.0) {
				angleBrazo += efe;
			}
			break;
		case 'i':
		case 'I':
			if (angleCodo < 90.0)
				angleCodo += efe;
			break;
		case 'j':
		case 'J':
			if (angleBrazo > -90.0)
				angleBrazo -= efe;
			break;
		case 'k':
		case 'K':
			if (angleCodo > 0)
				angleCodo -= efe;
			break;

		case 'O':
			if (angleDedoI < 0.0)
				angleDedoI += efe;
			break;
		case 'o':
			if (angleDedoI > -90.0)
				angleDedoI -= efe;
			break;

		case 'L':
			if (angleDedoE < 0.0)
				angleDedoE += efe;
			break;
		case 'l':
			if (angleDedoE > -90.0)
				angleDedoE -= efe;
			break;

			//Animacion de los dedos
		case 'P':
			if (angleDedoI < 0.0) {
				angleDedoI += efe;
				if (angleDedoE < 0.0)
					angleDedoE += efe;
			}
			break;
		case 'p':
			if (angleDedoI > -90.0) {
				angleDedoI -= efe;
				if (angleDedoE > -90.0)
					angleDedoE -= efe;
			}
			break;

			case 'm':		//
			//case 'K':
				if(FrameIndex<MAX_FRAMES)
				{
					saveFrame();
				}

				break;
*/
			//case 'l':
			case ',':
				if(play==false && (FrameIndex>1))
				{

					resetElements();
					//First Interpolation
					interpolation();

					play=true;
					playIndex=0;
					i_curr_steps = 0;
				}
				else
				{
					play=false;
				}
				break;
		/*	case '.':
				for (int i = 0; i < FrameIndex; i++) {
					printf("Frame [%d]\n", i);
					printf("transX = %f\ntransY = %f\ntransZ = %f\n", KeyFrame[i].transX, KeyFrame[i].transY, KeyFrame[i].transZ);
					printf("angleDedoI = %f\nangleDedoE = %f\nangleCodo = %f\nangleBrazo = %f", KeyFrame[i].angleDedoI, KeyFrame[i].angleDedoE, KeyFrame[i].angleCodo, KeyFrame[i].angleBrazo);
					printf("angleX = %f\nangleY = %f\nangleZ = %f\n", KeyFrame[i].angleX, KeyFrame[i].angleY, KeyFrame[i].angleZ);
					printf("\nIncrementos:\n\n");
					printf("transXinc = %f\ntransYinc = %f\ntransZinc = %f\n", KeyFrame[i].transXinc, KeyFrame[i].transYinc, KeyFrame[i].transZinc);
					printf("angleDedoIinc = %f\nangleDedoEinc = %f\nangleCodoinc = %f\nangleBrazoinc = %f\n", KeyFrame[i].angleDedoIinc, KeyFrame[i].angleDedoEinc, KeyFrame[i].angleCodoinc, KeyFrame[i].angleBrazoinc);
					printf("angleXinc = %f\nangleYinc = %f\nangleZinc = %f\n", KeyFrame[i].angleXinc, KeyFrame[i].angleYinc, KeyFrame[i].angleZinc);
					printf("******************************************\n\n");
				}
				break;

			case 'f':
				transX -= 0.2f;
				break;
			case 'h':
				transX += 0.2f;
				break;
			case 'g':
				transZ -= 0.2f;
				break;
			case 't':
				transZ += 0.2f;
				break;
			case 'r':
				transY += 0.2f;
				break;
			case 'R':
				transY -= 0.2f;
				break;

			case 'c':
				angleX += 0.5f;
				break;
			case 'v':
				angleY += 0.5f;
				break;
			case 'b':
				angleZ += 0.5f;
				break;

			case 'C':
				angleX -= 0.5f;
				break;
			case 'V':
				angleY -= 0.5f;
				break;
			case 'B':
				angleZ -= 0.5f;
				break;
	*/
		
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
