#include<stdio.h>
#include<GL/glut.h>
typedef float point[3];
point v[] = {
             {0.0,0.0,1.0},{1.0,0.0,1.0},
             {0.5,0.866025,1.0}           
               };
int n;
void draw_triangle(point a,point b,point c)
{
  glBegin(GL_POLYGON);
      glColor3f(0.0,1.0,1.0);
  glVertex3fv(a);
  glVertex3fv(b);
  glVertex3fv(c);
  glEnd();
}

void midpoint(point save,point a,point b) {
  save[0]=(a[0]+b[0])/2;
  save[1]=(a[1]+b[1])/2;
  save[2]=(a[2]+b[2])/2;
}

void divide_tetrahedron(point a,point b,point c,int m)
{
  point ab,ac,bc;

  //repeat 'm' no of times as specified by user
  if(m>0) {
    midpoint(ab,a,b);
    midpoint(ac,a,c); 
    midpoint(bc,b,c);
  
    // consider midpoints as vertex and divide bigger triangle 
    // to 3 parts recursively
    divide_tetrahedron(a,ab,ac,m-1); 
    divide_tetrahedron(ab,b,bc,m-1);
    divide_tetrahedron(ac,bc,c,m-1);
    //note if u want the colors of phases to align just adjudt the above points
  }
  //draw the sub divided traingles
  else {
    glColor3f(1.0,0.0,0.0);
    draw_triangle(a,b,c);
  }
}

//this is called everytime the display is refreshed. Here it draw a tetrahedron.
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  divide_tetrahedron(v[0],v[1],v[2],n);
  glFlush();
}

// This function is executed when the wiindow size is changed. 
void myReshape(int w,int h)
{
  glViewport(0,0,w,h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  if(w<=h)
    glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);  //to get exact aspect ratio
  else
    glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
  glMatrixMode(GL_MODELVIEW);
  glutPostRedisplay();
}

int main(int argc,char **argv)
{
  printf("SIERPINSKI\nenter the number of divisions \n");
  scanf("%d",&n);
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
  glutInitWindowSize(1366,768);
  glutCreateWindow("SIERPINSKI TRIANGLE");
  glutReshapeFunc(myReshape);   
  glutDisplayFunc(display);
  glEnable(GL_DEPTH_TEST);
  glClearColor(1.0,1.0,1.0,1.0);
  glutMainLoop();
}