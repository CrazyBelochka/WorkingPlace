#include <windows.h>

#include <GL/gl.h>

#include <GL/glu.h>


#include <GL/glut.h>

void resize(int width, int height)

{

}

void display(void)

{
	glLineWidth(2); 

	glBegin(GL_LINES); //рисуем центральные линии

	//оконтовка
	glColor3d(1, 1, 1); // белый цвет
	glVertex3d(0, -4, 0); 
	glVertex3d(0, 8, 0);
	glVertex3d(-5, 1, 0);
	glVertex3d(6, 1, 0);

	glEnd();

	glLineWidth(0.3); //новая толщина

	glBegin(GL_LINES);
	glVertex3d(-2.5 , -4, 0); //левая полоска
	glVertex3d(-2.5, 8, 0);

	glVertex3d(2.5, -4, 0); //правая полоска
	glVertex3d(2.5, 8, 0);

	glVertex3d(-5, -1.5, 0); //нижняя полоска
	glVertex3d(6, -1.5, 0);

	glVertex3d(-5, 3.5, 0); //верхняя полоска 
	glVertex3d(6, 3.5, 0);


	glEnd();
	glLineWidth(0.3); //новая толщина

	glBegin(GL_LINES); //желтая линия верхний квадратик
	glColor3d(1, 1, 0);
	glVertex3d(-4.7, 3, 0);
	glVertex3d(-1, 6, 0);

	glEnd();
	glLineWidth(4); //новая толщина

	glBegin(GL_LINES); //зеленая жирная линия верний квадратик
	glColor3d(0, 1, 0);
	glVertex3d(-3.3, 2.4, 0);
	glVertex3d(-0.3, 4.9, 0);
	glEnd();

	glLineWidth(1);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_LINE_STIPPLE); // разрешаем рисовать прерывистую линию
	glLineStipple(1, 0x00FF); // устанавливаем маску
	glBegin(GL_LINE_LOOP);

	glColor3d(1, 0, 0); //красная штрихованная сверху слева
	glVertex3d(-4, 5.8, 0);
	glVertex3d(-0.3, 2, 0);
	glEnd();

	glDisable(GL_LINE_SMOOTH);
	glDisable(GL_LINE_STIPPLE);

	glLineWidth(0.4);
	glBegin(GL_LINES); //правый верхний квадрат
										//3 квадратика
	glColor3d(1, 1, 1);
	glVertex3d(0.3, 6, 0);
	glVertex3d(0.3, 2, 0);
	glVertex3d(1.3, 6, 0);
	glVertex3d(1.3, 2, 0);
	glVertex3d(0.3, 3, 0);
	glVertex3d(1.3, 3, 0);
	glVertex3d(0.3, 2, 0);
	glVertex3d(1.3, 2, 0);
	glVertex3d(0.3, 4, 0);
	glVertex3d(1.3, 4, 0);
	glVertex3d(0.3, 5, 0);
	glVertex3d(1.3, 5, 0);
	glEnd();

	glBegin(GL_POLYGON);//красный квадратик
	glColor3d(1, 0, 0);
	glVertex3d(0.3, 2, 0);
	glVertex3d(0.3, 3, 0);
	glVertex3d(1.3, 3, 0);
	glVertex3d(1.3, 2, 0);
	glEnd();

	//glEnable(GL_LINE_STIPPLE);
	//glEnable(GL_LINE_SMOOTH);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLE_FAN);//веер цветов
	glColor3d(1, 0, 0);
	glVertex3d(2.5, 3.5, 0);
	glVertex3d(3, 2.6, 0);
	glVertex3d(3.6, 2.75, 0);
	glColor3d(0, 1, 0);
	glVertex3d(3.9, 3.2, 0);
	glColor3d(0, 0, 1);
	glVertex3d(4, 3.5, 0);
	glColor3d(0, 1, 1);
	glVertex3d(3.7, 4.2, 0);//все еще веер
	glColor3d(1, 1, 0);
	glVertex3d(3.4, 4.8, 0);
	glColor3d(1, 0, 1);
	glVertex3d(3, 5.3, 0);
	glEnd();
	//glDisable(GL_LINE_SMOOTH);
	//glDisable(GL_LINE_STIPPLE);

	glPointSize(7);
	glEnable(GL_POINT_SMOOTH); //желтая точка снизу слева
	glBegin(GL_POINTS);
	glColor3d(1, 1, 0);
	glVertex3d(-4, 0.3, 0);
	glEnd();
	glDisable(GL_POINT_SMOOTH);

	glPointSize(15); //синяя точка снизу слева
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glColor3d(0, 0, 1);
	glVertex3d(-4, -3.5, 0);
	glEnd();
	glDisable(GL_POINT_SMOOTH);

	glPointSize(7); //красная точка снизу слева
	glBegin(GL_POINTS);
	glColor3d(1, 0, 0);
	glVertex3d(-1.25, -0.25, 0);
	glEnd();

	glPointSize(7); //зеленая точка снизу слева
	glBegin(GL_POINTS);
	glColor3d(0, 1, 0);
	glVertex3d(-1.25, -3.6, 0);
	glEnd();

	glLineWidth(3); // ширина 3
	glBegin(GL_LINE_STRIP); // см. ниже
	glColor3d(1, 1, 1);
	glVertex3d(0.5, 0, 0);
	glVertex3d(1, 0.5, 0);
	glVertex3d(1, -1, 0);
	glVertex3d(0.65, -0.4, 0);
	glVertex3d(1.75, 0.1, 0);
	glVertex3d(1.75, -0.7, 0);

	glEnd();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // см. выше
	glBegin(GL_TRIANGLES);
	glColor3d(0, 1, 0); // рисуем треугольник
	glVertex3d(3, 0, 0);
	glVertex3d(4, 0.8, 0);
	glVertex3d(4.2,-0.3 , 0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3d(1, 0.5, 0); // рисуем фигуру справа снизу
	glVertex3d(3, -2, 0);
	glVertex3d(1, -2.8, 0);
	glVertex3d(2.5, -3.4, 0);
	glVertex3d(3.5, -3, 0);
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

int main(int argc, char ** argv)

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(50, 10);

	glutInitWindowSize(1000, 1000);

	glutCreateWindow("Hello");

	glutReshapeFunc(resize);

	init();

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;

}