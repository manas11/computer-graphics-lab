#include<GL/glut.h>
#include<iostream>
using namespace std;

void initGL(){
	glClearColor(0.0f,0.0f,0.0f,1.0f);
}
void display(){
	
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glColor3f(0.95f,0.4f,0.0f);
		glVertex2f(0.1f,0.3f);
		glVertex2f(0.5f,0.3f);
		glVertex2f(0.3f,0.7f);

		glColor3f(0.95f,0.4f,0.0f);
		glVertex2f(0.5f,0.3f);
		glVertex2f(0.9f,0.3f);
		glVertex2f(0.7f,0.7f);

		glColor3f(0.95f,0.4f,0.0f);
		glVertex2f(0.9f,0.3f);
		glVertex2f(1.3f,0.3f);
		glVertex2f(1.0f,0.7f);

		glColor3f(0.95f,0.4f,0.0f);
		glVertex2f(-0.1f,0.3f);
		glVertex2f(-0.5f,0.3f);
		glVertex2f(-0.3f,0.7f);

		glColor3f(0.95f,0.4f,0.0f);
		glVertex2f(-0.5f,0.3f);
		glVertex2f(-0.9f,0.3f);
		glVertex2f(-0.7f,0.7f);

		glColor3f(0.95f,0.4f,0.0f);
		glVertex2f(-0.9f,0.3f);
		glVertex2f(-1.3f,0.3f);
		glVertex2f(-1.0f,0.7f);

	glEnd();

	glBegin(GL_TRIANGLES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex2f(0.5f,0.0f);
		glVertex2f(-0.5f,0.0f);
		glVertex2f(0.0f,0.5f);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2f(0.5f,0.0f);
		glVertex2f(-0.5f,0.0f);
		glVertex2f(-0.5f,-0.5f);
		glVertex2f(0.5f,-0.5f);
	
		glColor3f(0.0f,0.5f,0.0f);
		glVertex2f(0.20f,-0.25f);
		glVertex2f(-0.20f,-0.25f);
		glVertex2f(-0.20f,-0.5f);
		glVertex2f(0.20f,-0.5f);

		glColor3f(0.0f,0.5f,0.0f);
		glVertex2f(0.3f,-0.05f);
		glVertex2f(0.15f,-0.05f);
		glVertex2f(0.15f,-0.15f);
		glVertex2f(0.3f,-0.15f);

		glColor3f(0.0f,0.5f,0.0f);
		glVertex2f(-0.15f,-0.05f);
		glVertex2f(-0.3f,-0.05f);
		glVertex2f(-0.3f,-0.15f);
		glVertex2f(-0.15f,-0.15f);
		
		glColor3f(0.99f,0.5f,0.0f);
		glVertex2f(0.40f,-0.5f);
		glVertex2f(-0.40f,-0.5f);
		glVertex2f(-0.40f,-0.7f);
		glVertex2f(0.40f,-0.7f);

		glColor3f(0.75f,0.5f,0.0f);
		glVertex2f(0.35f,-0.7f);
		glVertex2f(-0.35f,-0.7f);
		glVertex2f(-0.35f,-0.9f);
		glVertex2f(0.35f,-0.9f);

		glColor3f(0.55f,0.5f,0.0f);
		glVertex2f(0.30f,-0.9f);
		glVertex2f(-0.30f,-0.9f);
		glVertex2f(-0.30f,-0.95f);
		glVertex2f(0.30f,-0.95f);
	glEnd();

	glFlush();
}
int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutCreateWindow("Baisc shapes");
	glutInitWindowSize(400,400);
	glutInitWindowPosition(50,50);
	glutDisplayFunc(display);
	initGL();
	glutMainLoop();
	return 0;
}