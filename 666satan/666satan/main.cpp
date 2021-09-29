#include <windows.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


void display(void)

{
	glColor3f(1, 0, 0); // рисуем треугольник
	glBegin(GL_TRIANGLES);
	glVertex2f(-2, 1);
	glVertex2f(-1, 3);
	glVertex2f(-0.8, 1);

	glEnd();

	glColor3f(1, 0, 0); // рисуем треугольник
	glBegin(GL_TRIANGLES);
	glVertex2f(-2, 1);
	glVertex2f(-3.5, -1.5);
	glVertex2f(0, 1);

	glEnd();

	glColor3f(1, 0, 0); // рисуем треугольник
	glBegin(GL_TRIANGLES);
	glVertex2f(-3, 1);
	glVertex2f(-0.8, 1);
	glVertex2f(-0.5, -1.5);

	glEnd();

	glColor4f(0.7, 0.7, 0.7, 0.5); // рисуем тень
	glBegin(GL_POLYGON);
	glVertex2f(3, 1);
	glVertex2f(4.2, 1);
	glVertex2f(4.28, 0.48);
	glVertex2f(3.24, -0.28);
	glVertex2f(2.63, 0.4);


	glEnd();

	glColor3f(1, 1, 0); // рисуем треугольник
	glBegin(GL_TRIANGLES);
	glVertex2f(4, 3);
	glVertex2f(4.2, 1);
	glVertex2f(3, 1);

	glEnd();

	glColor3f(1, 0, 0); // рисуем треугольник
	glBegin(GL_TRIANGLES);
	glVertex2f(3, 1);
	glVertex2f(1.5, -1.5);
	glVertex2f(5, 1);

	glEnd();

	glColor3f(0, 0, 1); // рисуем треугольник
	glBegin(GL_TRIANGLES);
	glVertex2f(2, 1);
	glVertex2f(4.2, 1);
	glVertex2f(4.5, -1.5);

	glEnd();










	glFlush();

}

void init(void)

{

	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_LIGHTING);

	glEnable(GL_LIGHT0);

	glEnable(GL_DEPTH_TEST);

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(-5.0, 5.0, -5.0, 5.0, 2.0, 12.0);

	gluLookAt(0, 0, 5, 0, 1, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char** argv)

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(50, 10);
	glViewport(0, 0, 700, 700);
	glutInitWindowSize(900, 700);

	glutCreateWindow("World of lines");

	init();

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;

}