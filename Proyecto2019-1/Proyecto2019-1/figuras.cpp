#include "figuras.h"


const double PI = 3.1415926535897;
float text_der = 1.0;
float text_izq = 0.0;

void CFiguras::skybox(float largo, float altura, float profundidad, GLuint text)  //Funcion creacion cielo
{

	GLfloat vertice [8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
				};

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glNormal3f( 0.0f, 0.0f,1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glNormal3f(1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
        	glVertex3fv(vertice[7]);
		glEnd();
}

void CFiguras::prisma (float altura, float largo, float profundidad, GLuint text)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
				};

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[7]);
		glEnd();
}

void CFiguras::prisma2 (GLuint text, GLuint text2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glNormal3f( 0.0f,1.0f, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}

void CFiguras::prisma_anun (GLuint text, GLuint text2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		
		glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
		//glBindTexture(GL_TEXTURE_2D, texture[filter]);   // choose the texture to use.
		glBegin(GL_POLYGON);	//Front
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
		glEnd();
	
		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
			glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
			glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
			glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
		glEnd();

		glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
		glNormal3f( 0.0f,1.0f, 0.0f);
			glTexCoord2f(text_der, 0.0f); glVertex3fv(vertice[4]);
			glTexCoord2f(text_der, 1.0f); glVertex3fv(vertice[5]);
			glTexCoord2f(text_izq, 1.0f); glVertex3fv(vertice[6]);
			glTexCoord2f(text_izq, 0.0f); glVertex3fv(vertice[7]);
		glEnd();
}

void CFiguras::esfera(GLfloat radio, int meridianos, int paralelos, GLuint text )
{
	
	GLdouble angulop = 3.1415/paralelos;
	GLdouble angulom = 3.1415/meridianos;
	GLdouble theta, phi;
	//bool even = true;
	
	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.

	for(double p =-3.14/2; p < 3.14/2; p += angulop)
	{
		for(double m = 0; m < 3.14*2; m+=angulom)
		{
			//glBegin(GL_LINE_LOOP);
			glBegin(GL_POLYGON);
			
			//glBegin(GL_POINTS);
			glNormal3f( radio*cos(p + angulop)*cos(m), radio*sin(p + angulop), radio*cos(p + angulop)*sin(m));			
			glVertex3f( radio*cos(p + angulop)*cos(m), radio*sin(p + angulop), radio*cos(p + angulop)*sin(m));	

			glNormal3f( radio*cos(p + angulop)*cos(m + angulom), radio*sin(p + angulop), radio*cos(p + angulop)*sin(m + angulom));
			glVertex3f( radio*cos(p + angulop)*cos(m + angulom), radio*sin(p + angulop), radio*cos(p + angulop)*sin(m + angulom));

			glNormal3f( radio*cos(p)*cos(m + angulom), radio*sin(p), radio*cos(p)*sin(m + angulom));
			glVertex3f( radio*cos(p)*cos(m + angulom), radio*sin(p), radio*cos(p)*sin(m + angulom));

			glNormal3f(radio*cos(p)*cos(m), radio*sin(p), radio*cos(p)*sin(m));
			glVertex3f( radio*cos(p)*cos(m), radio*sin(p), radio*cos(p)*sin(m));
				
			glEnd();
		}
	}
}

void CFiguras::torus(GLfloat radioM, GLfloat radiom, int meridianos, int paralelos )
{

	float R = 0;
	float r = 0;

	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};

	int i,j;

	GLdouble angulop = 2*3.1415/paralelos;
	GLdouble angulom = 2*3.1415/meridianos;

	r = (radioM - radiom)/2;
	R = radiom + r;

	for(i=0;i<meridianos;i++)
	{
		for(j=0;j<paralelos;j++)
		{
			
			v1[0]=R*cos(angulom*i) + r*cos(angulom*i)*cos(angulop*j);
			v1[2]=R*sin(angulom*i)+ r*sin(angulom*i)*cos(angulop*j);
			v1[1]=r*sin(angulop*j);

			glNormal3f(v1[0], v1[1], v1[2]);
			
			v2[0]=R*cos(angulom*i) + r*cos(angulom*i)*cos(angulop*(j+1));
			v2[2]=R*sin(angulom*i) + r*sin(angulom*i)*cos(angulop*(j+1));
			v2[1]=r*sin(angulop*(j+1));

			glNormal3f(v2[0], v2[1], v2[2]);

			v3[0]=R*cos(angulom*(i+1)) + r*cos(angulom*(i+1))*cos(angulop*(j+1));
			v3[2]=R*sin(angulom*(i+1)) + r*sin(angulom*(i+1))*cos(angulop*(j+1));
			v3[1]=r*sin(angulop*(j+1));

			glNormal3f(v3[0], v3[1], v3[2]);

			v4[0]=R*cos(angulom*(i+1)) + r*cos(angulom*(i+1))*cos(angulop*j);
			v4[2]=R*sin(angulom*(i+1)) + r*sin(angulom*(i+1))*cos(angulop*j);
			v4[1]=r*sin(angulop*j);

			glNormal3f(v4[0], v4[1], v4[2]);
			
			//glBegin(GL_LINE_LOOP);
			glBegin(GL_POLYGON);
				glVertex3fv(v1);
				glVertex3fv(v2);
				glVertex3fv(v3);
				glVertex3fv(v4);
			glEnd();
		}
	}
}

void CFiguras::cono(float altura, float radio, int resolucion, GLuint text)
{
	
	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};

	float angulo=2*3.14/resolucion;
	
	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	for(int i=0; i <resolucion; i++)
	{
		
		v2[0]=radio*cos(angulo*i);
		v2[1]=0;
		v2[2]=radio*sin(angulo*i);

		v3[0]=radio*cos(angulo*(i+1));
		v3[1]=0;
		v3[2]=radio*sin(angulo*(i+1));
		
		//glBegin(GL_LINE_LOOP);
        glBegin(GL_POLYGON); //Construye Base
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3f(0.0,0.0,0.0);
			glVertex3fv(v2);
			glVertex3fv(v3);
		glEnd();

		glBegin(GL_POLYGON);  //Construye Cuerpo
			glNormal3f( v2[0], 0.25f, v2[2]);
			//glNormal3fv(v2);
			glVertex3fv(v2);
			//glNormal3fv(v3);
			glVertex3fv(v3);
			//glNormal3f(0.0,altura,0);
			glVertex3f(0.0,altura,0.0);
			
		glEnd();
	}
}

void CFiguras::cilindro(float radio, float altura, int resolucion, GLuint text)
{
	
	float v1[]={0.0, 0.0, 0.0};
	float v2[]={0.0, 0.0, 0.0};
	float v3[]={0.0, 0.0, 0.0};
	float v4[]={0.0, 0.0, 0.0};
	float v5[]={0.0, 0.0, 0.0};

	float angulo=2*PI/resolucion;

	//float ctext_s = 1/resolucion-1;
	float ctext_s = 1/resolucion;
	float ctext_t = 0.0;

	//glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	for(int i=0; i <resolucion; i++)
	{
		 
		v2[0]=radio*cos(angulo*i);
		v2[1]=0;
		v2[2]=radio*sin(angulo*i);

		v3[0]=radio*cos(angulo*(i+1));
		v3[1]=0;
		v3[2]=radio*sin(angulo*(i+1));
//	
		v4[0]=radio*cos(angulo*i);
		v4[1]=altura;
		v4[2]=radio*sin(angulo*i);

		v5[0]=radio*cos(angulo*(i+1));
		v5[1]=altura;
		v5[2]=radio*sin(angulo*(i+1));

		//glBegin(GL_LINE_LOOP);
		glBegin(GL_POLYGON);
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3f(0.0,0.0,0.0);
			glVertex3fv(v2);
			glVertex3fv(v3);
		glEnd();

		glBegin(GL_POLYGON);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3f(0.0,altura,0.0);
			glVertex3fv(v4);
			glVertex3fv(v5);
		glEnd();

/*		glBegin(GL_POLYGON);
			glBindTexture(GL_TEXTURE_2D, text);
			glNormal3f( v2[0], 0.0f, v2[2]);
			glTexCoord2f(ctext_s*i, 0.0f);		glVertex3fv(v2);
			glTexCoord2f(ctext_s*(i+1), 0.0f);	glVertex3fv(v3);
			glTexCoord2f(ctext_s*(i+1), 1.0f);	glVertex3fv(v5);
			glTexCoord2f(ctext_s*i, 1.0f);		glVertex3fv(v4);
		glEnd();
*/
		glBegin(GL_POLYGON);
			glNormal3f( v2[0], 0.0f, v2[2]);
			glVertex3fv(v2);
			glVertex3fv(v3);
			glVertex3fv(v5);
			glVertex3fv(v4);
		glEnd();
	}
}	

/*PROYECTO*/

//Sin uso?
void CFiguras::torreA(GLuint text)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(15.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(15.0f, 10.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(15.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(15.0f, 10.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
		//glColor3f(0.0,1.0,0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(15.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(15.0f, 10.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(15.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(15.0f, 10.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
		//glColor3f(0.4,0.2,0.6);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
		//glColor3f(0.8,0.2,0.4);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

// Para que cuadren perfecto las texturas.
void CFiguras::torreMedia(GLuint text,GLuint text2, float scaleX, float scaleY, float scaleZ)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(scaleX, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(scaleX, scaleY); glVertex3fv(vertice[4]);
		glTexCoord2f(0.0f, scaleY); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(scaleZ, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(scaleZ, scaleY); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, scaleY); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, scaleY); glVertex3fv(vertice[6]);
		glTexCoord2f(scaleX, scaleY); glVertex3fv(vertice[5]);
		glTexCoord2f(scaleX, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(scaleZ, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(scaleZ, scaleY); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, scaleY); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(scaleX, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(0.0f, scaleZ); glVertex3fv(vertice[2]);
		glTexCoord2f(scaleX, scaleZ); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(scaleX, 0.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(scaleX, scaleZ); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, scaleZ); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void CFiguras::jardineraI(GLuint text, GLuint text2)
{

	GLfloat vertice[16][3] = {
				{0.0  , 0.0, 0.0},    //Coordenadas Vértice 0 V0
				{-6.0 , 0.0, 0.0},    //Coordenadas Vértice 1 V1
				{-6.0 , 0.0, -2.33},    //Coordenadas Vértice 2 V2
				{-5.5 , 0.0, -4.6},    //Coordenadas Vértice 3 V3
				{-4.3 , 0.0, -7.0},    //Coordenadas Vértice 4 V4
				{-3.2 , 0.0, -6.7},    //Coordenadas Vértice 5 V5
				{-2.2 , 0.0, -6.2},    //Coordenadas Vértice 6 V6
				{0.0, 0.0, -5.0},    //Coordenadas Vértice 7 V7

				{0.0  , 1.0,  0.0},    //Coordenadas Vértice 8 V8
				{0.0, 1.0, -5.0},    //Coordenadas Vértice 9 V9
				{-2.2 , 1.0, -6.2},    //Coordenadas Vértice 10 V10
				{-3.2 , 1.0, -6.7},    //Coordenadas Vértice 11 V11
				{-4.3 , 1.0, -7.0},    //Coordenadas Vértice 12 V12
				{-5.5 , 1.0, -4.6},    //Coordenadas Vértice 13 V13
				{-6.0 , 1.0, -2.33},    //Coordenadas Vértice 14 V14
				{-6.0 , 1.0, 0.0},    //Coordenadas Vértice 15 V15
	};


	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(1.000, 0.000); glVertex3fv(vertice[0]);
		glTexCoord2f(0.000, 0.000); glVertex3fv(vertice[1]);
		glTexCoord2f(0.000, 0.333); glVertex3fv(vertice[2]);
		glTexCoord2f(0.083, 0.657); glVertex3fv(vertice[3]);
		glTexCoord2f(0.283, 1.000); glVertex3fv(vertice[4]);
		glTexCoord2f(0.466, 0.957); glVertex3fv(vertice[5]);
		glTexCoord2f(0.633, 0.885); glVertex3fv(vertice[6]);
		glTexCoord2f(1.000, 0.714); glVertex3fv(vertice[7]);
	glEnd();

	glBegin(GL_POLYGON);	//Front
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[8]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[15]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[9]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[8]);
	glEnd();

	glBegin(GL_POLYGON);	//BackA
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[12]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[11]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//BackB
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[11]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[10]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);	//BackC
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[10]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[9]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);  //LeftA
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(8.0, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(8.0, 1.0); glVertex3fv(vertice[15]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[14]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //LeftB
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(8.0, 0.0f); glVertex3fv(vertice[2]);
		glTexCoord2f(8.0, 1.0); glVertex3fv(vertice[14]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[13]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //LeftC
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(8.0, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(8.0, 1.0); glVertex3fv(vertice[13]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[12]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text2);
	glBegin(GL_POLYGON);
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(1.0, 0.0); glVertex3fv(vertice[8]);
		glTexCoord2f(1.0, 0.71); glVertex3fv(vertice[9]);
		glTexCoord2f(0.63, 0.88); glVertex3fv(vertice[10]);
		glTexCoord2f(0.46, 0.95); glVertex3fv(vertice[11]);
		glTexCoord2f(0.283, 1.0); glVertex3fv(vertice[12]);
		glTexCoord2f(0.083, 0.65); glVertex3fv(vertice[13]);
		glTexCoord2f(0.0, 0.332); glVertex3fv(vertice[14]);
		glTexCoord2f(0.0, 0.0); glVertex3fv(vertice[15]);
	glEnd();
}

void CFiguras::jardineraJ(GLuint text, GLuint text2)
{

	GLfloat vertice[16][3] = {
				{0.0  , 0.0, 0.0},    //Coordenadas Vértice 0 V0
				{-6.0 , 0.0, 0.0},    //Coordenadas Vértice 1 V1
				{-6.0 , 0.0, -2.33},    //Coordenadas Vértice 2 V2
				{-5.5 , 0.0, -4.6},    //Coordenadas Vértice 3 V3
				{-4.3 , 0.0, -7.0},    //Coordenadas Vértice 4 V4
				{-3.2 , 0.0, -6.7},    //Coordenadas Vértice 5 V5
				{-2.2 , 0.0, -6.2},    //Coordenadas Vértice 6 V6
				{0.0, 0.0, -5.0},    //Coordenadas Vértice 7 V7

				{0.0  , 1.0,  0.0},    //Coordenadas Vértice 8 V8
				{0.0, 1.0, -5.0},    //Coordenadas Vértice 9 V9
				{-2.2 , 1.0, -6.2},    //Coordenadas Vértice 10 V10
				{-3.2 , 1.0, -6.7},    //Coordenadas Vértice 11 V11
				{-4.3 , 1.0, -7.0},    //Coordenadas Vértice 12 V12
				{-5.5 , 1.0, -4.6},    //Coordenadas Vértice 13 V13
				{-6.0 , 1.0, -2.33},    //Coordenadas Vértice 14 V14
				{-6.0 , 1.0, 0.0},    //Coordenadas Vértice 15 V15
	};


	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Top
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(1.0, 0.0); glVertex3fv(vertice[8]);
		glTexCoord2f(1.0, 0.71); glVertex3fv(vertice[9]);
		glTexCoord2f(0.63, 0.88); glVertex3fv(vertice[10]);
		glTexCoord2f(0.46, 0.95); glVertex3fv(vertice[11]);
		glTexCoord2f(0.283, 1.0); glVertex3fv(vertice[12]);
		glTexCoord2f(0.083, 0.65); glVertex3fv(vertice[13]);
		glTexCoord2f(0.0, 0.332); glVertex3fv(vertice[14]);
		glTexCoord2f(0.0, 0.0); glVertex3fv(vertice[15]);
	glEnd();
	
	glBegin(GL_POLYGON);	//Front
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[8]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[15]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[9]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[8]);
	glEnd();

	glBegin(GL_POLYGON);	//BackA
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[12]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[11]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//BackB
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[11]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[10]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[5]);
	glEnd();

	glBegin(GL_POLYGON);	//BackC
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[10]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[9]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glEnd();

	glBegin(GL_POLYGON);  //LeftA
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(8.0, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(8.0, 1.0); glVertex3fv(vertice[15]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[14]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //LeftB
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(8.0, 0.0f); glVertex3fv(vertice[2]);
		glTexCoord2f(8.0, 1.0); glVertex3fv(vertice[14]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[13]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //LeftC
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(8.0, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(8.0, 1.0); glVertex3fv(vertice[13]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[12]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text2);
	glBegin(GL_POLYGON);	//Bottom
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(1.000, 0.000); glVertex3fv(vertice[0]);
		glTexCoord2f(0.000, 0.000); glVertex3fv(vertice[1]);
		glTexCoord2f(0.000, 0.333); glVertex3fv(vertice[2]);
		glTexCoord2f(0.083, 0.657); glVertex3fv(vertice[3]);
		glTexCoord2f(0.283, 1.000); glVertex3fv(vertice[4]);
		glTexCoord2f(0.466, 0.957); glVertex3fv(vertice[5]);
		glTexCoord2f(0.633, 0.885); glVertex3fv(vertice[6]);
		glTexCoord2f(1.000, 0.714); glVertex3fv(vertice[7]);
	glEnd();
}

void CFiguras::jardineraG(GLuint text, GLuint text2)
{
	
	GLfloat vertice[16][3] = {
				{0.0 , 0.0, 0.0},    //Coordenadas Vértice 0 V0
				{-2.67 , 0.0, 2.0},    //Coordenadas Vértice 1 V1
				{-5.34 ,0.0, 3.5},    //Coordenadas Vértice 2 V2
				{-8.0 ,0.0, 4.0},    //Coordenadas Vértice 3 V3
				{-8.0 ,0.0, -12.0},    //Coordenadas Vértice 4 V4
				{-4.0 ,0.0, -12.0},    //Coordenadas Vértice 5 V5
				{-2.7 ,0.0, -7.0},    //Coordenadas Vértice 6 V6
				{-0.89 ,0.0, -1.85},    //Coordenadas Vértice 7 V7

				{0.0 , 1.0, 0.0},    //Coordenadas Vértice 8 V8
				{-0.89 ,1.0, -1.85},    //Coordenadas Vértice 9 V9
				{-2.7 ,1.0, -7.0},    //Coordenadas Vértice 10 V10
				{-4.0 ,1.0, -12.0},    //Coordenadas Vértice 11 V11
				{-8.0 ,1.0, -12.0},    //Coordenadas Vértice 12 V12
				{-8.0 ,1.0, 4.0},    //Coordenadas Vértice 13 V13
				{-5.34 ,1.0, 3.5},    //Coordenadas Vértice 14 V14
				{-2.67 , 1.0, 2.0},    //Coordenadas Vértice 15 V15
	};


	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	
	glBegin(GL_TRIANGLE_FAN);	//Bottom
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.333+1, 0.0313+1); glVertex3fv(vertice[2]);
		glTexCoord2f(0.666+1, 0.125+1); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0+1, 0.25+1); glVertex3fv(vertice[0]);
		glTexCoord2f(0.889+1, 0.3656+1); glVertex3fv(vertice[7]);
		glTexCoord2f(0.663+1, 0.6875+1); glVertex3fv(vertice[6]);
		glTexCoord2f(0.5+1, 1.0+1); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0, 1.0+1); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//FrontA
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[8]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[15]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//FrontB
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[15]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[14]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);	//FrontC
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[2]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[14]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[13]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glEnd();
	
	glBegin(GL_POLYGON);	//RightA
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[11]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[10]);
	glEnd();
	
	glBegin(GL_POLYGON);	//RightB
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[10]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[9]);
	glEnd();

	glBegin(GL_POLYGON);	//RightC
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[9]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[8]);
	glEnd();
	
	glBegin(GL_POLYGON);	//Back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[12]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[11]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(8.0, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(8.0, 1.0); glVertex3fv(vertice[13]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[12]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text2);
	glBegin(GL_TRIANGLE_FAN);	//Top
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[13]);
		glTexCoord2f(0.333, 0.0313); glVertex3fv(vertice[14]);
		glTexCoord2f(0.666, 0.125); glVertex3fv(vertice[15]);
		glTexCoord2f(1.0, 0.25); glVertex3fv(vertice[8]);
		glTexCoord2f(0.889, 0.3656); glVertex3fv(vertice[9]);
		glTexCoord2f(0.663, 0.6875); glVertex3fv(vertice[10]);
		glTexCoord2f(0.5, 1.0); glVertex3fv(vertice[11]);
		glTexCoord2f(0.0, 1.0); glVertex3fv(vertice[12]);
	glEnd();
}

void CFiguras::jardineraH(GLuint text, GLuint text2)
{

	GLfloat vertice[16][3] = {
				{0.0 , 0.0, 0.0},    //Coordenadas Vértice 0 V0
				{-2.67 , 0.0, 2.0},    //Coordenadas Vértice 1 V1
				{-5.34 ,0.0, 3.5},    //Coordenadas Vértice 2 V2
				{-8.0 ,0.0, 4.0},    //Coordenadas Vértice 3 V3
				{-8.0 ,0.0, -12.0},    //Coordenadas Vértice 4 V4
				{-4.0 ,0.0, -12.0},    //Coordenadas Vértice 5 V5
				{-2.7 ,0.0, -7.0},    //Coordenadas Vértice 6 V6
				{-0.89 ,0.0, -1.85},    //Coordenadas Vértice 7 V7

				{0.0 , 1.0, 0.0},    //Coordenadas Vértice 8 V8
				{-0.89 ,1.0, -1.85},    //Coordenadas Vértice 9 V9
				{-2.7 ,1.0, -7.0},    //Coordenadas Vértice 10 V10
				{-4.0 ,1.0, -12.0},    //Coordenadas Vértice 11 V11
				{-8.0 ,1.0, -12.0},    //Coordenadas Vértice 12 V12
				{-8.0 ,1.0, 4.0},    //Coordenadas Vértice 13 V13
				{-5.34 ,1.0, 3.5},    //Coordenadas Vértice 14 V14
				{-2.67 , 1.0, 2.0},    //Coordenadas Vértice 15 V15
	};


	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.

	glBegin(GL_TRIANGLE_FAN);	//Top
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[13]);
		glTexCoord2f(0.333, 0.0313); glVertex3fv(vertice[14]);
		glTexCoord2f(0.666, 0.125); glVertex3fv(vertice[15]);
		glTexCoord2f(1.0, 0.25); glVertex3fv(vertice[8]);
		glTexCoord2f(0.889, 0.3656); glVertex3fv(vertice[9]);
		glTexCoord2f(0.663, 0.6875); glVertex3fv(vertice[10]);
		glTexCoord2f(0.5, 1.0); glVertex3fv(vertice[11]);
		glTexCoord2f(0.0, 1.0); glVertex3fv(vertice[12]);
	glEnd();
	

	glBegin(GL_POLYGON);	//FrontA
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[8]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[15]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//FrontB
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[15]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[14]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);	//FrontC
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[2]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[14]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[13]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);	//RightA
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[11]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[10]);
	glEnd();

	glBegin(GL_POLYGON);	//RightB
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[10]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[9]);
	glEnd();

	glBegin(GL_POLYGON);	//RightC
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[9]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[8]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[12]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[11]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(8.0, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(8.0, 1.0); glVertex3fv(vertice[13]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[12]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text2);
		glBegin(GL_TRIANGLE_FAN);	//Bottom
		glNormal3f(0.0, -1.0, 0.0);
		glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.333 + 1, 0.0313 + 1); glVertex3fv(vertice[2]);
		glTexCoord2f(0.666 + 1, 0.125 + 1); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0 + 1, 0.25 + 1); glVertex3fv(vertice[0]);
		glTexCoord2f(0.889 + 1, 0.3656 + 1); glVertex3fv(vertice[7]);
		glTexCoord2f(0.663 + 1, 0.6875 + 1); glVertex3fv(vertice[6]);
		glTexCoord2f(0.5 + 1, 1.0 + 1); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0, 1.0 + 1); glVertex3fv(vertice[4]);
	glEnd();
}

void CFiguras::jardineraE(GLuint text, GLuint text2)
{
	
	GLfloat vertice[8][3] = {
				{0.0, 0.0, 0.0},    //Coordenadas Vértice 0 V0
				{-4.0, 0.0, 0.0},    //Coordenadas Vértice 1 V1
				{-4.0 ,0.0, -12.0},    //Coordenadas Vértice 2 V2
				{0.0 ,0.0, -8.0},    //Coordenadas Vértice 3 V3
				{0.0 ,1.0, 0.0},    //Coordenadas Vértice 4 V4
				{0.0 ,1.0, -8.0},    //Coordenadas Vértice 5 V5
				{-4.0 ,1.0, -12.0},    //Coordenadas Vértice 6 V6
				{-4.0 ,1.0, 0.0},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(4.0, 2.0); glVertex3fv(vertice[4]);
		glTexCoord2f(0.0f, 2.0); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(4.0, 2.0); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 2.0); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 2.0); glVertex3fv(vertice[6]);
		glTexCoord2f(4.0, 2.0); glVertex3fv(vertice[5]);
		glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(4.0, 2.0); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 2.0); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(0.0f, 2.0); glVertex3fv(vertice[2]);
		glTexCoord2f(4.0, 2.0); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(4.0, 2.0); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 2.0); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void CFiguras::jardineraF(GLuint text, GLuint text2)	//Lo mismo que E, pero cambia el orden de las texturas para cuando se rote en Z.
{

	GLfloat vertice[8][3] = {
				{0.0, 0.0, 0.0},    //Coordenadas Vértice 0 V0
				{-4.0, 0.0, 0.0},    //Coordenadas Vértice 1 V1
				{-4.0 ,0.0, -12.0},    //Coordenadas Vértice 2 V2
				{0.0 ,0.0, -8.0},    //Coordenadas Vértice 3 V3
				{0.0 ,1.0, 0.0},    //Coordenadas Vértice 4 V4
				{0.0 ,1.0, -8.0},    //Coordenadas Vértice 5 V5
				{-4.0 ,1.0, -12.0},    //Coordenadas Vértice 6 V6
				{-4.0 ,1.0, 0.0},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[4]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[6]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[5]);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text2);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Bottom
		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[2]);
		glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[3]);
	glEnd();
}

void CFiguras::plancha(GLuint text)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, 0);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(40.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(40.0f, 40.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 40.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
		//glColor3f(0.0,0.0,1.0);
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(40.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(40.0f, 40.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 40.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
		//glColor3f(0.0,1.0,0.0);
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(40.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(40.0f, 40.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 40.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(40.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(40.0f, 40.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 40.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
		//glColor3f(0.4,0.2,0.6);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(40.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(40.0f, 40.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 40.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
		//glColor3f(0.8,0.2,0.4);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(40.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(40.0f, 40.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 40.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void CFiguras::tree(GLuint text) {
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	glBindTexture(GL_TEXTURE_2D, text);
	for (int i = 0; i < 360; i += 40) {
		glRotatef(i, 0.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
/*			glTexCoord2f(0.0, 0.0); glVertex3f(-0.5, 0.0, 0.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-0.5, 0.5, 0.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(0.5, 0.5, 0.0);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.5, 0.0, 0.0);*/
			glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, 0.0, 0.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 7.5, 0.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(2.0, 7.5, 0.0);
			glTexCoord2f(1.0, 0.0); glVertex3f(2.0, 0.0, 0.0);
		glEnd();
	}
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
}

void CFiguras::labCG(GLuint text [9], float largo, float altura, float profundidad) {
	//texturas:
	/*
		0	NoFumar
		1	NoComer
		2	NoHablar
		3	NoCelular
		4	Pizarron
		5	Ventana
		6	PisoCG
		7	PisoMetal
		8	Techo
	*/
	GLfloat vertice[8][3] = {
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
	};

	glBindTexture(GL_TEXTURE_2D, text[5]);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
		//glColor3f(0.0,0.0,1.0);
		glNormal3f(0.0f, 0.0f, -1.0f);	//la normal para adentro, porque es el laboratorio.
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(4.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
		//glColor3f(0.0,0.0,1.0);
		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
		glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(4.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	//glBindTexture(GL_TEXTURE_2D, text[4]);
	glBegin(GL_POLYGON);	//Back
		//glColor3f(0.0,1.0,0.0);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(4.0f, 1.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[3]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text[5]);
	glBegin(GL_POLYGON);  //Left
		//glColor3f(1.0,1.0,1.0);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[1]);
		glTexCoord2f(4.0f, 1.0f); glVertex3fv(vertice[7]);
		glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text[6]);
	glBegin(GL_POLYGON);  //Bottom
		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0.0f , 0.0f);  glVertex3fv(vertice[0]);
		glTexCoord2f(20.0f, 0.0f);  glVertex3fv(vertice[1]);
		glTexCoord2f(20.0f, 20.0f); glVertex3fv(vertice[2]);
		glTexCoord2f(0.0f , 20.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, text[8]);
	glBegin(GL_POLYGON);  //Top
		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[4]);
		glTexCoord2f(6.0f, 0.0f); glVertex3fv(vertice[5]);
		glTexCoord2f(6.0f, 6.0f); glVertex3fv(vertice[6]);
		glTexCoord2f(0.0f, 6.0f); glVertex3fv(vertice[7]);
	glEnd();


	//	LOGOS Y DEMAS TEXTURAS
	/*
				{0.5*largo ,-0.5*altura, 0.5*profundidad},    //Coordenadas Vértice 1 V1
				{-0.5*largo ,-0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 2 V2
				{-0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 3 V3
				{0.5*largo ,-0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 4 V4
				{0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 5 V5
				{0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 6 V6
				{-0.5*largo ,0.5*altura , -0.5*profundidad},    //Coordenadas Vértice 7 V7
				{-0.5*largo ,0.5*altura , 0.5*profundidad},    //Coordenadas Vértice 8 V8
	*/

	/*glPushMatrix();
		glTranslatef(0.0, 2.5, -6.95);
		glBindTexture(GL_TEXTURE_2D, text[0]);//unitario?
		glBegin(GL_POLYGON);	//No Fumar
			glNormal3f(0.0f, 0.0f, 1.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.5, 0.0);	//6
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0.0);	//5
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.5, 0.0);	//3
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 0.0);	//2
		glEnd();
	glPopMatrix();
	*/
	glBindTexture(GL_TEXTURE_2D, 0);

}

/*PROYECTO*/