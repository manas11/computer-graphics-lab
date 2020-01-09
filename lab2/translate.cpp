#include <GL/glut.h>
 #include <stdio.h>
 #include<math.h>

 #define pi 3.142587

void myInit(){

   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
}

void display() {
   glClear(GL_COLOR_BUFFER_BIT);         
 
 //quadrilateral
   glBegin(GL_QUADS);  
         glColor3f(0.23f, 0.2f, 0.243f); 

      glVertex2f(-0.5f, -0.5f);   
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();

//circle
//    glBegin(GL_QUADS);           
//       glColor3f(1.0f, 0.0f, 0.0f); 
//       glVertex2f(-0.5f, -0.5f);   
//       glVertex2f( 0.5f, -0.5f);
//       glVertex2f( 0.5f,  0.5f);
//       glVertex2f(-0.5f,  0.5f);
//    glEnd();

//triangle
//    glBegin(GL_QUADS);           
//       glColor3f(1.0f, 0.0f, 0.0f); 
//       glVertex2f(-0.5f, -0.5f);   
//       glVertex2f( 0.5f, -0.5f);
//       glVertex2f( 0.5f,  0.5f);
//       glVertex2f(-0.5f,  0.5f);
//    glEnd();
 
   glFlush();  // Render now
}
 
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 
   glutInitWindowSize(1366, 768);   
   glutInitWindowPosition(0, 0); 
      glutCreateWindow("OpenGL Setup Test"); 
myInit();
   glutDisplayFunc(display); 
   glutMainLoop();           
   return 0;
}