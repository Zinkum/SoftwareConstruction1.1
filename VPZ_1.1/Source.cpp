#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>

void glDrawCircle(float cx, float cy, float r, GLenum mode)
{
	int numsegments = int(r * 100);
	glBegin(mode);
	for (int i = 0; i < numsegments; i++)
	{
		float theta = 2.0f * M_PI * i / numsegments;
		float x = r * cosf(theta);
		float y = r * sinf(theta);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}

void init()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

void display()
{
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
	glVertex2f(0.75, 0.5);
	glVertex2f(-0.75, 0.5);
	glVertex2f(-0.75, -0.5);
	glVertex2f(0.75, -0.5);
	glEnd();

	glColor3f(1, 0, 0);
	glDrawCircle(0, 0.5, 0.4, GL_POLYGON);

	glColor3f(0, 1, 0.5);
	glDrawCircle(0, 0.5, 0.4, GL_LINE_LOOP);

	glBegin(GL_TRIANGLES);
	glVertex2f(0, 0.4);
	glVertex2f(0.6, -0.6);
	glVertex2f(-0.6, -0.6);
	glEnd();

	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(250, 250);
	glutCreateWindow("Lab1");

	init();
	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}