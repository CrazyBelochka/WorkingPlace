#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLfloat vertices[][3] = { {-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},
{1.0,1.0,-1.0},{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},
{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0} };

void polygon(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
	glTexCoord2d(0, 1);
	glVertex3fv(vertices[a]);
	glTexCoord2d(1, 1);
	glVertex3fv(vertices[b]);
	glTexCoord2d(1, 0);
	glVertex3fv(vertices[c]);
	glTexCoord2d(0, 0);
	glVertex3fv(vertices[d]);
	glEnd();
}

void colorcube(unsigned int brickText)
{
	glEnable(GL_TEXTURE_2D);
	glColor3d(1, 1, 1);

	glBindTexture(GL_TEXTURE_2D, brickText);
	polygon(0, 3, 2, 1);
	polygon(2, 3, 7, 6);
	polygon(0, 4, 7, 3);
	polygon(1, 2, 6, 5);
	polygon(4, 5, 6, 7);
	polygon(0, 1, 5, 4);
}

void display(void) {
	unsigned int brickText;
	glGenTextures(1, &brickText);
	glBindTexture(GL_TEXTURE_2D, brickText);

	int width, height, nrChannels;
	unsigned char* data = stbi_load("real_pudge.jpg", &width, &height, &nrChannels, 0);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glBegin;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 7, 0, 0, 0, 0, 1, 0);
	glRotated(36, 1, 0, 0);
	glRotated(45, 0, 1, 0);
	colorcube(brickText);

	glEnd();
	glDisable(GL_TEXTURE_2D);
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
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(50, 10);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Lab5");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

