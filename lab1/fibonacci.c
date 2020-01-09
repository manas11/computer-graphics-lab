
// C program to demonstrate 
// drawing a circle using 
// OpenGL 
#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<GL/glut.h> 
#include<math.h> 
#define pi 3.142857 
  


// function to initialize 
void myInit (void) 
{ 
    // making background color black as first  
    // 3 arguments all are 0.0 
    glClearColor(0.0, 255.0, 255.0, 1.0); 
      
    // making picture color green (in RGB mode), as middle argument is 1.0 
    glColor3f(0.0, 0.0, 0.0); 
      
    // breadth of picture boundary is 1 pixel 
    glPointSize(1.0); 
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
      
    // setting window dimension in X- and Y- direction 
    gluOrtho2D(-20000, 20000, -10000, 10000); 
} 


void display (void)  
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glBegin(GL_POINTS); 
    float x, y, i; 
    int size =200;
    float z=1;
 float t1=1,t2=1,nextTerm;
float a[size];
int k;
     for (k = 1; k <= size; ++k) {
        a[k-1]=t1;
        printf("%f",a[k-1]);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
float x1=0,y1=0;
for(int j=0;j<size;j++){
//u=2,3,0,1
if(j!=0){
if(j%4==1){
        y1+=(a[j]-a[j-1]);
    }else if(j%4==2){
          x1-=(a[j]-a[j-1]);

    }else if(j%4==3){
  y1-=(a[j]-a[j-1]);
    }else{
          x1+=(a[j]-a[j-1]);

    }
}
    for ( i = ((j+2)%4)*(pi/2); i < (((j+2)%4)+1)*(pi/2); i += 0.001) 
    { 
        x = a[j] * cos(i); 
        y = a[j] * sin(i); 
        glVertex2f(x1+x,y1+y); 
    }
             // sleep(1);


}
    glEnd(); 
    glFlush(); 
} 
  
int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

    // giving window size in X- and Y- direction 
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0); 
      
    // Giving name to window 
    glutCreateWindow("Circle Drawing"); 
    myInit(); 
      
    glutDisplayFunc(display); 
    glutMainLoop(); 
} 
