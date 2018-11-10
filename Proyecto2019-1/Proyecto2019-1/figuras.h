//#include <windows.h>  //Solo para Windows
//#include <GL/gl.h>     // The GL Header File
//#include <stdio.h>

//#include <math.h>
#include "Main.h"


class CFiguras
{
	public:

	float text_der;
	float text_izq;

	void esfera(GLfloat radio, int meridianos, int paralelos, GLuint text); //Funcíon creacion esfera
	void cilindro(float radio, float altura, int resolucion, GLuint text);	//Funcíon creacion cilindro
	void cono(float altura, float radio, int resolucion, GLuint text);		//Funcíon creacion cono
	void prisma_anun (GLuint text, GLuint text2);							//Funcíon creacion movimiento
	void prisma (float altura, float largo, float profundidad, GLuint text);//Funcíon creacion prisma
	void prisma2 (GLuint text, GLuint text2);
	void skybox(float altura, float largo, float profundidad, GLuint text);	//Funcion creacion cielo
	
/*PROYECTO*/
	void torreA(GLuint text);
	void torreMedia(GLuint text, float scaleX, float scaleY, float scaleZ);
	void plancha(GLuint text);

	void jardineraA(GLuint text, float scaleX, float scaleY, float scaleZ);
	void jardineraB(GLuint text, GLuint text2, float scaleX, float scaleY, float scaleZ);
	void jardineraC(GLuint text, GLuint text2, float scaleX, float scaleY, float scaleZ);
	void jardineraD(GLuint text, GLuint text2, float scaleX, float scaleY, float scaleZ);
	void jardineraE(GLuint text, GLuint text2);
	void jardineraF(GLuint text, GLuint text2);
	void jardineraG(GLuint text, GLuint text2);
	void jardineraH(GLuint text, GLuint text2);
	void jardineraI(GLuint text, GLuint text2);
	void jardineraJ(GLuint text, GLuint text2);
/*PROYECTO*/
	//void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos, GLuint text );
	void torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos);

};
