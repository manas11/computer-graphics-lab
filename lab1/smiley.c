#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
#include<math.h>
void display()
{ 
 int i; float x,y;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,.6,0.0);
 glPointSize(2.0);
 for(i=0;i<=360;i++)
 {
 glBegin(GL_POINTS);
 x=(cos((2*i*3.14)/360)) * .6;
 y=(sin((2*i*3.14)/360)) * .6;
 glVertex2f(x,y);
 glEnd();
 }
 
 for(i=240;i<300;i++)
 {
 glBegin(GL_POINTS);
 x=cos((2*i*3.14)/360) * .3;
 y=sin((2*i*3.14)/360) * .3;
 glVertex2f(x,y);
 glEnd();
 }
 glPointSize(10.0);
 glBegin(GL_POINTS);
 glVertex2f(-.25,.2);
 glVertex2f(.25,.2);
 glEnd();
  
 glFlush();
}
 
int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitWindowSize(250,250);
 glutInitWindowPosition(100,100);
 glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
 glutCreateWindow("simple");
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}