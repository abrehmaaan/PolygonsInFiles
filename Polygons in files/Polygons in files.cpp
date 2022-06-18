#include <GL/glut.h>
#include<iostream>
#include<fstream>
using namespace std;
void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 150, 0, 150);
}
void drawPolyLineFile(const char* filename) {
	fstream inStream;
	inStream.open(filename, ios::in);
	if (inStream.fail()) return;
	glClear(GL_COLOR_BUFFER_BIT);
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;
	for (int i = 0; i < numpolys; i++) {
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);
		for (int j = 0; j < numLines;j++) {
			inStream >> x >> y;
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}
void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawPolyLineFile("house.txt");
	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Home Sweet Home");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}