
#include "freeglut_klawiatura.h"
#include "klasa_prostokat.h"
#include "klasa_auto.h"
#include "klasa_boost.h"
#include "global.h"
using namespace std;




//C_prostokat sciana(2, 0, 2, 0.5);


C_boost punkt(0, 0, 0.1, 0.1, 0, 0, 1);


float proportion = (float)glutWindowWidth / (float)glutWindowHeight;

static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;
	proportion = ar;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


static void idle(void)
{
	glutPostRedisplay();
}

bool keyStates[256];

void keyPressed(unsigned char key, int x, int y)
{
	keyStates[key] = true;

	switch (key)
	{

	case 'w':
	{
		//car.jedzie_w_przod = 1;
		car.przyspiesza = 1;
		//car.jedzie_w_tyl = 0;

		car.y +=  car.speed *cos(car.angle * M_PI / 180);
		car.x +=  car.speed *sin(car.angle * M_PI / 180);
		
		break;
	}

	case 's':
	{

		//car.jedzie_w_przod = 0;
		car.przyspiesza = 0;
		if (car.speed > 0)
			car.speed -= 0.001;
		if (car.speed < 0)
			car.speed = 0;
		//car.jedzie_w_tyl = 1;
	//	car.y -= car.speed*cos(car.angle * M_PI / 180);
	//	car.x -= car.speed*sin(car.angle * M_PI / 180);

		break;
	}

	case 'd':
	{
		car.angle += 5;
		break;
	}

	case 'a':
	{
		car.angle -= 5;
		break;
	}

	}
}


void keyUp(unsigned char key, int x, int y)
{
	keyStates[key] = false;

	switch (key)
	{

	case 'w':
	{
		
		car.y +=  car.speed *cos(car.angle * M_PI / 180);
		car.x +=  car.speed *sin(car.angle * M_PI / 180);

		car.przyspiesza = 0;
		if (car.speed > 0)
			car.speed -= 0.001;
		if (car.speed < 0)
			car.speed = 0;
		break;
	}

	case 's':
	{
		
		break;
	}

	}

}


void keyOperations(void)
{
	double x, y;
	x = y = 0;
	if (keyStates['a'])
		keyPressed('a', x, y);
	else
		keyUp('a', x, y);

	if (keyStates['d'])
		keyPressed('d', x, y);
	else
		keyUp('d', x, y);

	if (keyStates['w'])
		keyPressed('w', x, y);
	else
		keyUp('w', x, y);

	if (keyStates['s'])
		keyPressed('s', x, y);
	else
		keyUp('s', x, y);

	if (keyStates['c'])
		keyPressed('c', x, y);
	else
		keyUp('c', x, y);


	if (keyStates['j'])
		keyPressed('j', x, y);
	else
		keyUp('j', x, y);

	if (keyStates['l'])
		keyPressed('l', x, y);
	else
		keyUp('l', x, y);

	if (keyStates['i'])
		keyPressed('i', x, y);
	else
		keyUp('i', x, y);

	if (keyStates['k'])
		keyPressed('k', x, y);
	else
		keyUp('k', x, y);

	if (keyStates['n'])
		keyPressed('n', x, y);
	else
		keyUp('n', x, y);
}

static void display()
{
	static bool czy_wyswietlic_info = true;
	// wyczyszenie sceny
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	keyOperations();


	car.za_mapa();
	glPushMatrix();

	// prostokat.Draw();
	
	//punkt.Draw_boost(car);
	car.Draw();
	
	// glPopMatrix();

	cout << car.time << " " << car.acc << " " << car.speed << " " << car.x<< " " << car.y<<endl;
	glPopMatrix();


	glutSwapBuffers();
}

void timer(int t)
{
	
	car.zmien_predkosc();


	glutPostRedisplay();

	// nastêpne wywo³anie funkcji timera
	glutTimerFunc(100, timer, car.time );
}

int main(int argc, char *argv[])
{



	glutInitWindowSize(glutWindowWidth, glutWindowHeight);
	glutInitWindowPosition(40, 40);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("OpenGLUT Shapes"); //tworzy okno, jak nazwa mowi

	glutPostRedisplay();
	glutReshapeFunc(resize);
	glutDisplayFunc(display);

	glutIdleFunc(idle);

	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	// set white as clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);


	glutTimerFunc(100, timer, 0);
	glutMainLoop();

	return 0;
}