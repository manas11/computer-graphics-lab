 
// C program to demonstrate
// drawing a circle using
// OpenGL
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#define pi 3.142857
 
// function to initialize
float angle = 30.0f;
void update(int value)
 
{
   angle += 2.0f;
 
   if (angle > 360.f)
 
   {
       angle -= 360;
   }
   glutPostRedisplay();
   glutTimerFunc(25, update, 0);
}
 
void myInit(void)
{
   // making background color black as first
   // 3 arguments all are 0.0
   glClearColor(0.0, 0.0, 0.0, 1.0);
 
   // making picture color green (in RGB mode), as middle argument is 1.0
   glColor3f(0.0, 1.0, 0.0);
 
   // breadth of picture boundary is 1 pixel
   glPointSize(1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
 
   // setting window dimension in X- and Y- direction
   gluOrtho2D(-780, 780, -420, 420);
}

 
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);      // To operate on Model-View matrix
   glLoadIdentity(); 
   
   glPushMatrix();
   //move the center point around whose axis the object rotates
    glTranslatef(-0.3f,0.25f,0.0f);
    //rotate (x-axis,y axis,z axis)
    glRotatef(angle,0.0f,0.0f,1.0f);
    //bring back the center point to the origin
    glTranslatef(0.3f,-0.25f,0.0f);
    glBegin(GL_TRIANGLES);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(-0.5f,0.0f);
        glVertex2f(-0.1f,0.0f);
        glVertex2f(-0.3f,0.5f);
    glEnd();
 
    glBegin(GL_POINTS);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex2f(-0.3f,0.25f);
   glEnd();
   glPopMatrix();
 
   glPushMatrix();
   glTranslatef(0.2f,0.28f,0.0f);
    glRotatef(angle,0.0f,1.0f,0.0f);
    glTranslatef(-0.2f,-0.28f,0.0f);
    glBegin(GL_POLYGON);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(0.1f,0.0f);
        glVertex2f(0.3f,0.0f);
        glVertex2f(0.3f,0.2f);
        glVertex2f(0.2f,0.4f);
        glVertex2f(0.1f,0.2f);
    glEnd();
 
    glBegin(GL_POINTS);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex2f(0.2f,0.28f);
   glEnd();
   glPopMatrix();
 
    glPushMatrix();
   glTranslatef(0.0f,-0.5f,0.0f);
    glRotatef(angle,1.0f,0.0f,0.0f);
    glTranslatef(-0.0f,0.5f,0.0f);
    glBegin(GL_QUADS);
        glColor3f(1.0f,1.0f,1.0f);
        glVertex2f(-0.1f,-0.2f);
        glVertex2f(-0.2f,-0.6f);
        glVertex2f(0.2f,-0.6f);
        glVertex2f(0.1f,-0.2f);
    glEnd();
    glBegin(GL_POINTS);
       glColor3f(1.0f,0.0f,0.0f);
       glVertex2f(0.0f,-0.5f);
   glEnd();
    glPopMatrix();
    
    glFlush();
}
 
int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 
   // giving window size in X- and Y- direction
   glutInitWindowSize(649, 480);
   glutInitWindowPosition(0, 0);
 
   // Giving name to window
   glutCreateWindow("Circle Drawing");
   myInit();
 
   glutDisplayFunc(display);
   glutTimerFunc(25, update, 0);
   glutMainLoop();
}
 

