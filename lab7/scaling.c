#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 

char title[] = "3D Shapes";
float sx, sy,sz, tx, ty, tz;
int flag =0;
 
void initGL() {
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}


void scale(float *x1, float *x2,float *x3, float tx, float ty, float tz){

      *x1 = *x1 + tx;
      *x2 = *x2 + ty;
      *x3 = *x3 + tz;
   }

void drawCube(){
   
   glBegin(GL_QUADS);             
      glColor3f(0.5f, 0.5f, 0.0f);    
      glVertex3f( sx * 1.0f, sy * 1.0f, sz*-1.0f);
      glVertex3f(sx  *-1.0f, sy * 1.0f, sz*-1.0f);
      glVertex3f(sx *-1.0f, sy *1.0f,  sz*1.0f);
      glVertex3f( sx * 1.0f, sy * 1.0f,  sz*1.0f);
 
      glColor3f(1.0f, 0.5f, 0.0f);     
      glVertex3f( sx * 1.0f, sy*-1.0f,  sz*1.0f);
      glVertex3f(sx*-1.0f, sy*-1.0f,  sz*1.0f);
      glVertex3f(sx*-1.0f, sy*-1.0f, sz*-1.0f);
      glVertex3f(sx*1.0f, sy*-1.0f, sz*-1.0f);
 
      glColor3f(1.0f, 0.5f, 0.5f);  
      glVertex3f( sx*1.0f,  sy*1.0f, sz*1.0f);
      glVertex3f(sx*-1.0f,  sy*1.0f, sz*1.0f);
      glVertex3f(sx*-1.0f, sy*-1.0f, sz*1.0f);
      glVertex3f( sx*1.0f, sy*-1.0f, sz*1.0f);
 
      glColor3f(1.0f, 0.0f, 1.0f);     
      glVertex3f( sx*1.0f, sy*-1.0f, sz*-1.0f);
      glVertex3f(sx*-1.0f, sy*-1.0f, sz*-1.0f);
      glVertex3f(sx*-1.0f,  sy*1.0f, sz*-1.0f);
      glVertex3f( sx*1.0f,  sy*1.0f, sz*-1.0f);
 
      glColor3f(1.0f, 0.3f, 0.2f);   
      glVertex3f(sx*-1.0f,  sy*1.0f,  sz*1.0f);
      glVertex3f(sx*-1.0f,  sy*1.0f, sz*-1.0f);
      glVertex3f(sx*-1.0f, sy*-1.0f, sz*-1.0f);
      glVertex3f(sx*-1.0f, sy*-1.0f,  sz*1.0f);
 
      glColor3f(0.0f, 0.3f, 0.2f);     
      glVertex3f(sx*1.0f,  sy*1.0f, sz*-1.0f);
      glVertex3f(sx*1.0f,  sy*1.0f,  sz*1.0f);
      glVertex3f(sx*1.0f, sy*-1.0f,  sz*1.0f);
      glVertex3f(sx*1.0f, sy*-1.0f, sz*-1.0f);
   glEnd(); 


}



void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glMatrixMode(GL_MODELVIEW);     
   glLoadIdentity();                
   glTranslatef(-1.8f, 0.0f, -8.0f);
      sx = 1;
      sy = 1;
      sz = 1;
      drawCube();
      sx = tx;
      sy = ty;
      sz = tz;
      drawCube();
   glutSwapBuffers(); 
}
 

void reshape(GLsizei width, GLsizei height) {  
   if (height == 0) height = 1;                
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   glViewport(0, 0, width, height);
 
   glMatrixMode(GL_PROJECTION);  
   glLoadIdentity();            
   gluPerspective(60.0f, aspect, 0.1f, 80.0f);
}
 
int main(int argc, char** argv) {
   int op = 0;
   printf("enter scaling inputs :");
   scanf("%f %f %f",&tx, &ty,&tz );

   glutInit(&argc, argv);            
   glutInitDisplayMode(GLUT_DOUBLE); 
   glutInitWindowSize(1366, 768);  
   glutInitWindowPosition(50, 50); 
   glutCreateWindow(title);       
   glutDisplayFunc(display);       
   glutReshapeFunc(reshape);       
   initGL();                       
   glutMainLoop();                 
   return 0;
}