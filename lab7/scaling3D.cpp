
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <stdio.h>
/* Global variables */
char title[] = "3D Shapes";
 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */


void draw_pyramid(float Tx, float Ty, float Tz) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(-1.5f, 0.0f, -7.0f);  // Move left and into the screen
 
   glBegin(GL_LINE_STRIP);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
 
   glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-1.5f, 0.0f, -7.0f);
 glBegin(GL_LINE_STRIP);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 0.0f * Tx, 1.0f * Ty, 0.0f * Tz);
      glColor3f(1.0f, 1.0f, 1.0f);     // Green
      glVertex3f(-1.0f * Tx, -1.0f * Ty, 1.0f * Tz);
      glColor3f(1.0f, 1.0f, 1.0f);     // Blue
      glVertex3f(1.0f * Tx, -1.0f * Ty, 1.0f * Tz);
 
      // Right
      glColor3f(1.0f, 1.0f, 1.0f);     // Red
      glVertex3f(0.0f * Tx, 1.0f * Ty, 0.0f * Tz);
      glColor3f(1.0f , 1.0f , 1.0f );     // Blue
      glVertex3f(1.0f * Tx, -1.0f * Ty, 1.0f * Tz);
      glColor3f(1.0f , 1.0f , 1.0f );     // Green
      glVertex3f(1.0f * Tx, -1.0f * Ty, -1.0f * Tz);
 
      // Back
      glColor3f(1.0f , 1.0f , 1.0f );     // Red
      glVertex3f(0.0f * Tx, 1.0f * Ty, 0.0f * Tz);
      glColor3f(1.0f , 1.0f , 1.0f);     // Green
      glVertex3f(1.0f * Tx, -1.0f * Ty, -1.0f * Tz);
      glColor3f(1.0f , 1.0f , 1.0f );     // Blue
      glVertex3f(-1.0f * Tx, -1.0f * Ty, -1.0f * Tz);
 
      // Left
      glColor3f(1.0f ,1.0f ,1.0f );       // Red
      glVertex3f( 0.0f * Tx, 1.0f * Ty, 0.0f * Tz);
      glColor3f(1.0f ,1.0f ,1.0f );       // Blue
      glVertex3f(-1.0f * Tx,-1.0f ,-1.0f );
      glColor3f(1.0f ,1.0f,1.0f );       // Green
      glVertex3f(-1.0f * Tx,-1.0f * Ty, 1.0f * Tz);
   glEnd();   // Done drawing the pyramid   // Done drawing the pyramid
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void draw_cube(float Tx, float Ty, float Tz) {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(-1.5f, 0.0f, -7.0f);  // Move right and into the screen
 
   glBegin(GL_LINE_STRIP);
      glColor3f(1.0f, 1.0f, 1.0f);     //front
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glVertex3f(0.0f, 1.0f, 1.0f);
      glVertex3f(0.0f, 0.0f,  1.0f);
      glVertex3f( 1.0f, 0.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glEnd();

      glBegin(GL_LINE_STRIP); //right
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glVertex3f(1.0f, 1.0f, 0.0f);
      glVertex3f(1.0f, 0.0f,  0.0f);
      glVertex3f( 1.0f, 0.0f, 1.0f);
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glEnd();

      glBegin(GL_LINE_STRIP); //top
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glVertex3f(1.0f, 1.0f, 0.0f);
      glVertex3f(0.0f, 1.0f,  0.0f);
      glVertex3f( 0.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f, 1.0f, 1.0f);
      glEnd();

      glBegin(GL_LINE_STRIP); //left
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 0.0f, 1.0f, 1.0f);
      glVertex3f(0.0f, 0.0f, 1.0f);
      glVertex3f(0.0f, 0.0f,  0.0f);
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glVertex3f( 0.0f, 1.0f, 1.0f);
      glEnd();

            glBegin(GL_LINE_STRIP); //bottom
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f, 0.0f, 1.0f);
      glVertex3f(0.0f, 0.0f, 1.0f);
      glVertex3f(0.0f, 0.0f,  0.0f);
      glVertex3f( 1.0f, 0.0f, 0.0f);
      glVertex3f( 1.0f, 0.0f, 1.0f);
      glEnd();

 
   glLoadIdentity();                  // Reset the model-view matrix
    glTranslatef(-1.5f, 0.0f, -7.0f);
   glBegin(GL_LINE_STRIP);
      glColor3f(1.0f, 1.0f , 1.0);     //front
      glVertex3f( 1.0f * Tx, 1.0f * Ty, 1.0f * Tz);
      glVertex3f(0.0f * Tx, 1.0f * Ty, 1.0f * Tz);
      glVertex3f(0.0f * Tx, 0.0f * Ty,  1.0f * Tz);
      glVertex3f( 1.0f * Tx, 0.0f * Ty,  1.0f * Tz);
      glVertex3f( 1.0f * Tx, 1.0f * Ty, 1.0f * Tz);
      glEnd();

      glBegin(GL_LINE_STRIP); //right
      glColor3f(1.0f, 1.0f, 1.0f);
      glVertex3f( 1.0f * Tx, 1.0f * Ty, 1.0f * Tz);
      glVertex3f(1.0f * Tx, 1.0f * Ty, 0.0f * Tz);
      glVertex3f(1.0f * Tx, 0.0f * Ty,  0.0f * Tz);
      glVertex3f( 1.0f * Tx, 0.0f * Ty, 1.0f * Tz);
      glVertex3f( 1.0f * Tx, 1.0f * Ty, 1.0f * Tz);
      glEnd();

      glBegin(GL_LINE_STRIP); //top
      glColor3f(1.0f , 1.0f , 1.0f );
      glVertex3f( 1.0f * Tx, 1.0f * Ty, 1.0f * Tz);
      glVertex3f(1.0f * Tx, 1.0f * Ty, 0.0f * Tz);
      glVertex3f(0.0f * Tx, 1.0f * Ty,  0.0f * Tz);
      glVertex3f( 0.0f * Tx, 1.0f * Ty, 1.0f * Tz);
      glVertex3f( 1.0f * Tx, 1.0f * Ty, 1.0f * Tz);
      glEnd();

      glBegin(GL_LINE_STRIP); //left
      glColor3f(1.0f , 1.0f , 1.0f);
      glVertex3f( 0.0f * Tx, 1.0f * Ty, 1.0f * Tz);
      glVertex3f(0.0f * Tx, 0.0f * Ty, 1.0f * Tz);
      glVertex3f(0.0f * Tx, 0.0f * Ty,  0.0f * Tz);
      glVertex3f( 0.0f * Tx, 1.0f * Ty, 0.0f * Tz);
      glVertex3f( 0.0f * Tx, 1.0f * Ty, 1.0f * Tz);
      glEnd();

            glBegin(GL_LINE_STRIP); //bottom
      glColor3f(1.0f , 1.0f, 1.0f);
      glVertex3f( 1.0f * Tx, 0.0f * Ty, 1.0f * Tz);
      glVertex3f(0.0f * Tx, 0.0f * Ty, 1.0f * Tz);
      glVertex3f(0.0f * Tx, 0.0f * Ty,  0.0f * Tz);
      glVertex3f( 1.0f * Tx, 0.0f * Ty, 0.0f * Tz);
      glVertex3f( 1.0f * Tx, 0.0f * Ty, 1.0f * Tz);
      glEnd();
 
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void display() {
  int ch;
  float Tx, Ty, Tz;
  printf("Enter your choice\n1. Cube\n2.Pyramid\n");
  scanf("%d",&ch);
  if(ch==1) {
    printf("Enter the scaling factor (Tx,Ty,Tz)\n");
    scanf("%f%f%f",&Tx,&Ty,&Tz);
    draw_cube(Tx,Ty,Tz);       
  }
  if(ch==2) {
    printf("Enter the scaling factor (Tx,Ty,Tz)\n");
    scanf("%f%f%f",&Tx,&Ty,&Tz);
    draw_pyramid(Tx,Ty,Tz); 
  }
   
}
 
/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}
 
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}