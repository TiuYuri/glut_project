#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "FileReader.hpp"
#include "Forms.hpp"

using namespace std;

vector<Forms*> vetor_feliz;
vector<float> cor_sececionada;
vector<float> cor_salva;

int ponteiro = 0;

float angle = 0;
float AnguloX =   0.0f;
float AnguloY =   0.0f;
float AnguloZ =   0.0f;
bool firstRender;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;

	float ratio =  w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	0.0f, 0.0f, AnguloZ - 10.0f,
				0.0f, 0.0f,  0.0f,
				0.0f, 1.0f,  0.0f);

	glRotatef(AnguloX, 0.0f, 1.0f, 0.0f);
	glRotatef(AnguloY, 1.0f, 0.0f, 0.0f);

		//cout << cor_salva[0] << " " << cor_salva[1] << " " << cor_salva[2] << endl;
	for(int i = 0; i < vetor_feliz.size(); i++){
		if(i == ponteiro){
			vetor_feliz[i]->isSelected = true;
			vetor_feliz[i]->render();
			vetor_feliz[i]->isSelected = false;
		} else{
			vetor_feliz[i]->render();
		}
	}


	angle+=1.1f;

	glutSwapBuffers();
}

void Teclado(unsigned char key, int x, int y)
{
	// Trata as diversas teclas
	switch(key)
	{
		//movimento camera
		case 'a':   
			AnguloX++; 
			break; 
		case 'd':
			AnguloX--;
			break;
		case 'w':
			AnguloZ++;
			break;
		case 's':
			AnguloZ--;
			break;
		case 'q':
			AnguloY--;
			break;
		case 'e':
			AnguloY++;
			break;

		//seleciona objeto
		case '\t':
			if(ponteiro < vetor_feliz.size() - 1){
				ponteiro ++;
				cout << "ponteiro" << ponteiro << endl;

			}else{
				ponteiro = 0;
				cout<< "voltou" << endl;
			}
			break;

		//movimento objeto
		case 'j':   
			vetor_feliz[ponteiro]->move(-1.0f, 0.0f, 0.0f);
			break; 
		case 'l':
			vetor_feliz[ponteiro]->move(1.0f, 0.0f, 0.0f);
			break;
		case 'i':
			vetor_feliz[ponteiro]->move(0.0f, 1.0f, 0.0f);
			break;
		case 'k':
			vetor_feliz[ponteiro]->move(0.0f, -1.0f, 0.0f);
			break;
		case 'u':
			vetor_feliz[ponteiro]->move(0.0f, 0.0f, 1.0f);
			break;
		case 'o':
			vetor_feliz[ponteiro]->move(0.0f, 0.0f, -1.0f);
			break; 
		// Sai do programa
		case 27:
					exit(1);
				break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	FileReader leitor;
	vetor_feliz = leitor.readFile();

	cor_sececionada.push_back(1);
	cor_sececionada.push_back(0);
	cor_sececionada.push_back(1);

	cor_salva = vetor_feliz[vetor_feliz.size() - 1]->getColor();
	cout << cor_salva[0] << " " << cor_salva[1] << " " << cor_salva[2] << endl;
	//
	//***** NAO MUDAR ABAIXO ********
	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("coisa do trabalho trabalhoso");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POLYGON_SMOOTH_HINT);
	glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);

	//LIGHT
	// GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	// GLfloat mat_shininess[] = { 50.0 };
	// GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	// glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	// glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	// glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	// glEnable(GL_LIGHTING);
	// glEnable(GL_LIGHT0);


	// teclado

	glutKeyboardFunc(Teclado);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}