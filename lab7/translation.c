#include <stdio.h> 
#include <GL/glut.h> 
#include <math.h> 

#define CUBE 0
#define PYR 1

 
/* Global variables */
char title[] = "3D Shapes";
float tx, ty,tz, cx=0,cy=0,cz=0;
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

void drawCube(){
   
 
   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( cx + 1.0f, cy + 1.0f, cz-1.0f);
      glVertex3f(cx  -1.0f, cy + 1.0f, cz-1.0f);
      glVertex3f(cx -1.0f, cy +1.0f,  cz+1.0f);
      glVertex3f( cx + 1.0f, cy + 1.0f,  cz+1.0f);
 
      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( cx + 1.0f, cy-1.0f,  cz+1.0f);
      glVertex3f(cx-1.0f, cy-1.0f,  cz+1.0f);
      glVertex3f(cx-1.0f, cy-1.0f, cz-1.0f);
      glVertex3f(cx+1.0f, cy-1.0f, cz-1.0f);
 
      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( cx+1.0f,  cy+1.0f, cz+1.0f);
      glVertex3f(cx-1.0f,  cy+1.0f, cz+1.0f);
      glVertex3f(cx-1.0f, cy-1.0f, cz+1.0f);
      glVertex3f( cx+1.0f, cy-1.0f, cz+1.0f);
 
      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( cx+1.0f, cy-1.0f, cz-1.0f);
      glVertex3f(cx-1.0f, cy-1.0f, cz-1.0f);
      glVertex3f(cx-1.0f,  cy+1.0f, cz-1.0f);
      glVertex3f( cx+1.0f,  cy+1.0f, cz-1.0f);
 
      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(cx-1.0f,  cy+1.0f,  cz+1.0f);
      glVertex3f(cx-1.0f,  cy+1.0f, cz-1.0f);
      glVertex3f(cx-1.0f, cy-1.0f, cz-1.0f);
      glVertex3f(cx-1.0f, cy-1.0f,  cz+1.0f);
 
      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(cx+1.0f,  cy+1.0f, cz-1.0f);
      glVertex3f(cx+1.0f,  cy+1.0f,  cz+1.0f);
      glVertex3f(cx+1.0f, cy+-1.0f,  cz+1.0f);
      glVertex3f(cx+1.0f, cy-1.0f, cz-1.0f);
   glEnd();  // End of drawing color-cube

   

}


void drawPyramid(){
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( cx+0.0f, cy+1.0f, cz+0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(cx-1.0f, cy-1.0f, cz+1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(cx+1.0f, cy-1.0f, cz+1.0f);
 
      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(cx+0.0f, cy+1.0f, cz+0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(cx+1.0f, cy-1.0f, cz+1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(cx+1.0f, cy-1.0f, cz-1.0f);
 
      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(cx+0.0f, cy+1.0f, cz+0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(cx+1.0f, cy-1.0f, cz-1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(cx-1.0f, cy-1.0f, cz-1.0f);
 
      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( cx+0.0f, cy+1.0f, cz+0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(cx-1.0f,cy-1.0f,cz-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(cx-1.0f,cy-1.0f, cz+1.0f);
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


   if(flag == CUBE){
      glTranslatef(-1.5f, 0.0f, -7.0f);
      drawCube();
      translate( &cx, &cy, &cz,tx, ty, tz);
      drawCube();
   }
   else{
      glTranslatef(-1.5f, 0.0f, -6.0f);
      drawPyramid();
      translate( &cx, &cy, &cz,tx, ty, tz);
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


   printf("Translation: \n");
   printf("1. cube \n");
   printf("2. pyramid\n");
   printf("Enter option: ");
   scanf("%d", &op);

   switch(op){
      case 1: /*printf("Enter center of the cube ");
            scanf("%d %d %d", &cx, &cy, &cz);*/
            flag = CUBE;
            break;
      case 2:/* printf("No of points: ");
            scanf("%d", &n);

            printf("Enter the points: ");
            for( int i =0; i < n; i++){
               for( int j =0; j < 2; j++){
                  scanf("%d", &points[i][j]);   
               }
            }
            */
            flag = PYR;
            break;
      // case 3: printf("Enter the center, radius: ");
      //       scanf("%d %d %d", &xa, &ya, &r);
      //       flag = CIRCLE;
      //       break;
            

   }

   printf("translation vector(x,y): ");
   scanf("%f %f %f",&tx, &ty,&tz );


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