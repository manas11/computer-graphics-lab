#include<stdio.h>
#include<GL/glut.h>

#define H 1366
#define W 768


int X_, Y_, Z_, X, Y, Z, rA, shape, tx, ty, tz, n;
int size = 80;

void display()
{
	glPointSize(1.0);
	glClear(GL_COLOR_BUFFER_BIT);	

	glPushMatrix();
		glRotatef(20, 1, 1, 1);
		glPushMatrix();
			glColor3f(0.5, 0.5, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0,  Z_ + 0);
				glVertex3i(X_ + 0, Y_ + size, Z_ + 0);
				glVertex3i(X_ + size, Y_ + size, Z_ + 0);
				glVertex3i(X_ + size, Y_ + 0, Z_ + 0);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.5, 1, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + size);
				glVertex3i(X_ + 0, Y_ + size, Z_ + size);
				glVertex3i(X_ + size, Y_ + size, Z_ + size);
				glVertex3i(X_ + size, Y_ + 0, Z_ + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 0, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + 0, Y_ + size, Z_ + 0);
				glVertex3i(X_ + 0, Y_ + size, Z_ + size);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + size, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + size, Y_ + size, Z_ + 0);
				glVertex3i(X_ + size, Y_ + size, Z_ + size);
				glVertex3i(X_ + size, Y_ + 0, Z_ + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 0, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + size, Y_ + 0, Z_ + 0);
				glVertex3i(X_ + size, Y_ + 0, Z_ + size);
				glVertex3i(X_ + 0, Y_ + 0, Z_ + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 1, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X_ + 0, Y_ + size, Z_ + 0);
				glVertex3i(X_ + size, Y_ + size, Z_ + 0);
				glVertex3i(X_ + size, Y_ + size, Z_ + size);
				glVertex3i(X_ + 0, Y_ + size, Z_ + size);
			glEnd();
		glPopMatrix();
	glPopMatrix();
	
   X = X_ +tx;
   Y = Y_ +ty;
   Z = Z_ +tz;
   
	glPushMatrix();
		glRotatef(20, 1, 1, 1);
		glPushMatrix();
			glColor3f(0.5, 0.5, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0,  Z + 0);
				glVertex3i(X + 0, Y + size, Z + 0);
				glVertex3i(X + size, Y + size, Z + 0);
				glVertex3i(X + size, Y + 0, Z + 0);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0.5, 1, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0, Z + size);
				glVertex3i(X + 0, Y + size, Z + size);
				glVertex3i(X + size, Y + size, Z + size);
				glVertex3i(X + size, Y + 0, Z + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 0, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0, Z + 0);
				glVertex3i(X + 0, Y + size, Z + 0);
				glVertex3i(X + 0, Y + size, Z + size);
				glVertex3i(X + 0, Y + 0, Z + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 0, 1);
			glBegin(GL_POLYGON);
				glVertex3i(X + size, Y + 0, Z + 0);
				glVertex3i(X + size, Y + size, Z + 0);
				glVertex3i(X + size, Y + size, Z + size);
				glVertex3i(X + size, Y + 0, Z + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(1, 0, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + 0, Z + 0);
				glVertex3i(X + size, Y + 0, Z + 0);
				glVertex3i(X + size, Y + 0, Z + size);
				glVertex3i(X + 0, Y + 0, Z + size);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glColor3f(0, 1, 0);
			glBegin(GL_POLYGON);
				glVertex3i(X + 0, Y + size, Z + 0);
				glVertex3i(X + size, Y + size, Z + 0);
				glVertex3i(X + size, Y + size, Z + size);
				glVertex3i(X + 0, Y + size, Z + size);
			glEnd();
		glPopMatrix();
	glPopMatrix();
	glFlush();
}

int main(int argc, char** argv)
{
   printf("\n enter size of cube side : ");
	scanf("%d", &size);
	printf("\ngive translation inputs :  ");
	scanf("%d %d %d", &tx, &ty, &tz);
	glutInit(&argc, argv);
	glutInitWindowSize(H, W);
	glutCreateWindow("3d transformation cube");

	glOrtho(-H/2, H/2, -W/2, W/2, -1000, 1000);
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);

	glutDisplayFunc(display);
	glutMainLoop();
}
