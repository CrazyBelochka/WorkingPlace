#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <cmath>

int x = 0;
int y = 0;
int xi = 0;
int yi = 0;
int r = 0;
bool down = false;

int DefinitionDistance(int x, int y, int xi, int yi)
{
	int r = sqrt(((xi - x)*(xi - x)) + ((yi - y)*(yi - y)));
	return r;
}

void display()
{
	float theta;
	//glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	glBegin(GL_POINTS);
	if (down)
	{
		glVertex2f(x, y);
	}
	glEnd();

	if ((xi!= 0) && (yi!=0) && (x != 0) && (y != 0))
	{
		glColor3f(0.68, 0.11, 0.16);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 360; i++) {
			theta = i * 3.1416 / 180;
			glVertex2f(x + r * cos(theta), y + r * sin(theta));
		}
		glEnd();
	}


	glutSwapBuffers();
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void mouseButton(int button, int state, int ax, int ay)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		x = ax;
		y = ay;
		down = state == GLUT_DOWN;
		glutDisplayFunc(display);
	}

	if (button == GLUT_RIGHT_BUTTON)
	{
		xi = ax;
		yi = ay;
		r = DefinitionDistance(x, y, xi, yi);
		down = state == GLUT_DOWN;

		glutDisplayFunc(display);
	}

}


void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, h, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseButton);
	glutMouseFunc(mouseButton);
	r = DefinitionDistance(x, y, xi, yi);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
