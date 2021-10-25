#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>

float objSize = 15; //размер квадрата
float objX = objSize; //координаты квадрата
float objY = 600 - objSize; //координаты квадрата

void motion(int x, int y)
{
	if (objX - objSize <= x && x <= objX + objSize
		&&
		objY - objSize <= y && y <= objY + objSize)
	{
		objX = x;
		objY = y;
		glutPostRedisplay();
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslated(objX, objY, 0.0f);
	glScalef(objSize, objSize, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
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
	glutMotionFunc(motion);

	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */
}
