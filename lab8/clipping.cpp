#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<iostream>

#define H 1366
#define W 768

int n;
float xd1[50],yd1[50], xd2[50], yd2[50];
using namespace std;

float xmin,ymin,xmax,ymax;

int bitcode(float x,float y)
{
    int c=0;
    if(y>ymax)c=8;
    if(y<ymin)c=4;
    if(x>xmax)c=c|2;
    if(x<xmin)c=c|1;
    return c;
}

void clip_points(float x1,float y1,float x2,float y2, int i)
{
    int c1=bitcode(x1,y1);
    int c2=bitcode(x2,y2);
    float m=(y2-y1)/(x2-x1);
    while((c1|c2)>0)
    {
        if((c1 & c2)>0)
        {
            xd1[i]=0;
            xd2[i]=0;
            yd1[i]=0;
            yd2[i]=0;
            return;
        }
    float xi=x1;
    float yi=y1;
    int c=c1;
    if(c==0)
    {
         c=c2;
         xi=x2;
         yi=y2;
    }
    float x,y;
    if((c & 8)>0)
    {
       y=ymax;
       x=xi+ 1.0/m*(ymax-yi);
    }
    else
      if((c & 4)>0)
      {
          y=ymin;
          x=xi+1.0/m*(ymin-yi);
      }
      else
       if((c & 2)>0)
       {
           x=xmax;
           y=yi+m*(xmax-xi);
       }
       else
       if((c & 1)>0)
       {
           x=xmin;
           y=yi+m*(xmin-xi);
       }

       if(c==c1)
       {
           xd1[i]=x;
           yd1[i]=y;
           c1=bitcode(xd1[i],yd1[i]);
       }

       if(c==c2)
       {
           xd2[i]=x;
           yd2[i]=y;
           c2=bitcode(xd2[i],yd2[i]);
       }
}
}


void myInit(void)
{
    glClearColor(1,1,1,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-H/2,H/2,-W/2,W/2);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);

   glBegin(GL_LINE_LOOP);
   glVertex2i(xmin,ymin);
   glVertex2i(xmin,ymax);
   glVertex2i(xmax,ymax);
   glVertex2i(xmax,ymin);
   glEnd();

for(int i=0;i<n;i++){
    clip_points(xd1[i],yd1[i],xd2[i],yd2[i],i);
   glColor3f(0.0,0.0,1.0);
   glBegin(GL_LINES);
   glVertex2i(xd1[i],yd1[i]);
   glVertex2i(xd2[i],yd2[i]);
   glEnd();
}
        glFlush();
}


int main(int argc,char** argv)
{
    
        printf("enter numebr of lines (n) : ");
            cin>>n;
      for(int i=0;i<n;i++){
    printf("enter coordinates off the line %d (x1 y1, x2 y2) :", i);
    cin>>xd1[i]>>yd1[i]>>xd2[i]>>yd2[i];
    }
    
    printf("enter the rectangle coordintes (xmin, ymin, xmax, ymax): ");
    cin>>xmin>>ymin>>xmax>>ymax;

    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("cohen sutherland algo");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
    return 0;
}

