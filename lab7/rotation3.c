#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 

#define Z 0
#define Y 1
#define X 1

 
/* Global variables */
char title[] = "3D Shapes";
float tx, ty,tz, cx=0,cy=0,cz=0;
float angle =0;
int flag =0;
 
/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

void translate(float *x1, float *x2,float *x3, float tx, float ty, float tz){

      *x1 = *x1 + tx;
      *x2 = *x2 + ty;
      *x3 = *x3 + tz;
   }

void rotate(float x1, float x2,float x3, float angle){

   translate(&x1, &x2, &x3, +1.0f, 1.0f, -1.0f);

   x1 = (x1)*cos(angle) - (x2)*sin(angle);
   x2 = (x2)*cos(angle) + (x1)*sin(angle);
   x3 = x3;

   translate(&x1, &x2, &x3,-1.0f, -1.0f, 1.0f);

   glVertex3f( x1, x2,x3);

}


void rotatex(float x1, float x2,float x3, float angle){

   translate(&x1, &x2, &x3, +1.0f, 1.0f, -1.0f);

   x2 = (x2)*cos(angle) - (x3)*sin(angle);
   x3 = (x2)*cos(angle) + (x3)*sin(angle);
   x1 = x1;

   translate(&x1, &x2, &x3,-1.0f, -1.0f, 1.0f);

   glVertex3f( x1, x2,x3);

}


void rotatey(float x1, float x2,float x3, float angle){

   translate(&x1, &x2, &x3, +1.0f, 1.0f, -1.0f);

   x3 = (x3)*cos(angle) - (x1)*sin(angle);
   x1 = (x1)*cos(angle) + (x3)*sin(angle);
   x2 = x2;

   translate(&x1, &x2, &x3,-1.0f, -1.0f, 1.0f);

   glVertex3f( x1, x2,x3);

}




void drawPyramid(){
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
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
}


void drawPyramidwithRotation(){



   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      rotate( cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      rotate(cx-1.0f, cy-1.0f, cz+1.0f, angle);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      rotate(cx+1.0f, cy-1.0f, cz+1.0f, angle);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      rotate(cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      rotate(cx+1.0f, cy-1.0f, cz+1.0f, angle);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      rotate(cx+1.0f, cy-1.0f, cz-1.0f, angle);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      rotate(cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      rotate(cx+1.0f, cy-1.0f, cz-1.0f, angle);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      rotate(cx-1.0f, cy-1.0f, cz-1.0f, angle);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      rotate( cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      rotate(cx-1.0f,cy-1.0f,cz-1.0f, angle);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      rotate(cx-1.0f,cy-1.0f, cz+1.0f, angle);
   glEnd();   // Done drawing the pyramid
}

void drawPyramidwithRotationx(){



   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      rotatex( cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      rotatex(cx-1.0f, cy-1.0f, cz+1.0f, angle);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      rotatex(cx+1.0f, cy-1.0f, cz+1.0f, angle);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      rotatex(cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      rotatex(cx+1.0f, cy-1.0f, cz+1.0f, angle);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      rotatex(cx+1.0f, cy-1.0f, cz-1.0f, angle);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      rotatex(cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      rotatex(cx+1.0f, cy-1.0f, cz-1.0f, angle);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      rotatex(cx-1.0f, cy-1.0f, cz-1.0f, angle);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      rotatex( cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      rotatex(cx-1.0f,cy-1.0f,cz-1.0f, angle);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      rotatex(cx-1.0f,cy-1.0f, cz+1.0f, angle);
   glEnd();   // Done drawing the pyramid
}

void drawPyramidwithRotationy(){



   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      rotatey( cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      rotatey(cx-1.0f, cy-1.0f, cz+1.0f, angle);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      rotatey(cx+1.0f, cy-1.0f, cz+1.0f, angle);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      rotatey(cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      rotatey(cx+1.0f, cy-1.0f, cz+1.0f, angle);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      rotatey(cx+1.0f, cy-1.0f, cz-1.0f, angle);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      rotatey(cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      rotatey(cx+1.0f, cy-1.0f, cz-1.0f, angle);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      rotatey(cx-1.0f, cy-1.0f, cz-1.0f, angle);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      rotatey( cx+0.0f, cy+1.0f, cz+0.0f, angle);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      rotatey(cx-1.0f,cy-1.0f,cz-1.0f, angle);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      rotatey(cx-1.0f,cy-1.0f, cz+1.0f, angle);
   glEnd();   // Done drawing the pyramid
}
 
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {

   cx = 0;
   cy = 0;
   cz = 0;

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
 
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
     // Move right and into the screen


   // if(flag == Z){
   //    glTranslatef(-1.5f, 0.0f, -7.0f);
   //    drawCube();
   //    translate( &cx, &cy, &cz,tx, ty, tz);
   //    drawCube();
   // }
   // else{
   //    glTranslatef(-1.5f, 0.0f, -6.0f);
   //    drawPyramid();
   //    translate( &cx, &cy, &cz,tx, ty, tz);
   //    drawPyramid();
   // }


   glTranslatef(-1.5f, 0.0f, -6.0f);


   if(flag == Z){
      drawPyramid();


   drawPyramidwithRotation();
   }
   else if( flag ==Y){
      // drawPyramid();

      drawPyramidwithRotationy();

   // glRotatef(angle, 0 ,1, 0);

   // drawPyramid();
   }
   else if(flag == X){
      // drawPyramid();

   // glRotatef(angle, 1 ,0, 0);
   drawPyramidwithRotationx();
   // drawPyramid();
   }
   else{
      drawPyramid();
   }
   
   



   glutSwapBuffers(); 
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


   int op = 0;


   printf("Rotation: \n");
   printf("1. z-axis \n");
   printf("2. y-axis\n");
   printf("3. x-axis\n");
   printf("Enter option: ");
   scanf("%d", &op);

   switch(op){
      case 1: 
            flag = Z;
            break;
      case 2:
            flag = Y;
            break;
   case 3:
         flag = X;
         break;
            

   }

   printf("Rotation angle: ");
   scanf("%f ", &angle);


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