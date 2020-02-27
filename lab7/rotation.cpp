#include<iostream>
#include<math.h>
#include<GL/glut.h>
using namespace std;

typedef float Matrix4 [4][4];
int translatex,translatey,translatez;



Matrix4 cube;
static GLfloat input[8][3]=
{
    //{0,0,0},{50,0,0},{50,50,0},{0,50,0},{-30,-30,-50},{20,-30,-50},{20,20,-50},{-30,20,-50}
    {40,40,-50},{90,40,-50},{90,90,-50},{40,90,-50},
    {30,30,0},{80,30,0},{80,80,0},{30,80,0}
    // {0,0,-50},{50,0,-50},{50,50,-50},{0,50,-50},
    // {-10,-10,0},{40,-10,0},{40,40,0},{-10,40,0}
};

float output[8][3];
float tx,ty,tz;
float angle;

float sx,sy,sz;

int choice,choiceRot,choiceRfl;

void setIdentityM(Matrix4 m)
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            m[i][j]=(i==j);
        }
    }
}

void translate(int tx,int ty,int tz)
{
    for(int i=0;i<8;i++)
    {
        output[i][0]=input[i][0]+tx;
        output[i][1]=input[i][1]+ty;
        output[i][2]=input[i][2]+tz;
    }
}

void scale(int sx,int sy,int sz)
{
    cube[0][0] = sx;
    cube[1][1] = sy;
    cube[2][2] = sz;    
}

void RotateX(float angle)
{
    angle = angle*3.142/180;
    cube[1][1] = cos(angle);
    cube[1][2] = -sin(angle);
    cube[2][1] = sin(angle);
    cube[2][2] = cos(angle);
}

void RotateY(float angle) //parallel to y
{

 angle = angle*3.142/180;
 cube[0][0] = cos(angle);
 cube[0][2] = -sin(angle);
 cube[2][0] = sin(angle);
 cube[2][2] = cos(angle);

}
void RotateZ(float angle) //parallel to z
{

 angle = angle*3.142/180;
 cube[0][0] = cos(angle);
 cube[0][1] = sin(angle);
 cube[1][0] = -sin(angle);
 cube[1][1] = cos(angle);

}
void RflXY()
{
    for(int i=0;i<8;i++)
    {
    output[i][0]=input[i][0];
    output[i][1]=input[i][1];
    output[i][2]=-input[i][2];
    }
}
void RflYZ()
{
    for(int i=0;i<8;i++)
    {
    output[i][0]=-input[i][0];
    output[i][0]=input[i][0];
    output[i][1]=-input[i][1];
    output[i][2]=input[i][2];
    }
}
void RflXZ()
{
    for(int i=0;i<8;i++)
    {
    output[i][0]=input[i][0];
    output[i][1]=-input[i][1];
    output[i][2]=input[i][2];
    }
}
void multiplyM()
{
for(int i=0;i<8;i++)
 {
    for(int j=0;j<3;j++)
    {
        output[i][j]=0;
        for(int k=0;k<3;k++)
        {
            output[i][j]=output[i][j]+input[i][k]*cube[k][j];
        }
    }
}
}
void draw(float a[8][3])
{


glBegin(GL_QUADS);
      glColor3f(0.5f, 0.5f, 0.0f);    
glVertex3fv(a[0]);
glVertex3fv(a[1]);
glVertex3fv(a[2]);
glVertex3fv(a[3]);

      glColor3f(1.0f, 0.5f, 0.0f);     
glVertex3fv(a[0]);
glVertex3fv(a[1]);
glVertex3fv(a[5]);
glVertex3fv(a[4]);

      glColor3f(1.0f, 0.5f, 0.5f);  
glVertex3fv(a[0]);
// glColor3f(0,1.0,1.0);
glVertex3fv(a[4]);
// glColor3f(1.0,0,0);
glVertex3fv(a[7]);
// glColor3f(0,1.0,1.0);
glVertex3fv(a[3]);

      glColor3f(1.0f, 0.0f, 1.0f);     
glVertex3fv(a[1]);
// glColor3f(0,0,1.0);
glVertex3fv(a[2]);
// glColor3f(0,1.0,0);
glVertex3fv(a[6]);
// glColor3f(0,0,1.0);
glVertex3fv(a[5]);

      glColor3f(1.0f, 0.3f, 0.2f);   
glVertex3fv(a[2]);
// glColor3f(0,1.0,0);
glVertex3fv(a[3]);
// glColor3f(1.0,0,0);
glVertex3fv(a[7]);
// glColor3f(0,1.0,0);
glVertex3fv(a[6]);

      glColor3f(0.0f, 0.3f, 0.2f);     
glVertex3fv(a[4]);
// glColor3f(1.0f, 1.0f, 1.0f); 
glVertex3fv(a[5]);
// glColor3f(0.2f, 0.2f, 0.2f);
glVertex3fv(a[6]);
// glColor3f(1.0f, 1.0f, 1.0f); 
glVertex3fv(a[7]);

glEnd();
}

void init()
{
    glClearColor(0.0,0.0,0.0,1.0); //set backgrond color to white
    glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);
    // Set the no. of Co-ordinates along X & Y axes and their gappings
    glEnable(GL_DEPTH_TEST);
     // To Render the surfaces Properly according to their depths
      
//    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
//    glShadeModel(GL_SMOOTH);   // Enable smooth shading
//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corre
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

glColor3f(1.0,0.0,0.0);

draw(input);

setIdentityM(cube);

switch(choice)
{
case 1:
    translate(tx,ty,tz);
    break;
 case 2:
    scale(sx,sy,sz);
	multiplyM();
    break;
 case 3:
    switch (choiceRot) {
    case 1:
        RotateX(angle);
        break;
    case 2:
                RotateY(angle);
            break;
    case 3:
        RotateZ(angle);
        break;
    default:
        break;
    }
	multiplyM();
    break;
case 4:
    switch (choiceRfl) {
    case 1:
        RflXY();
        break;
    case 2: 
        RflYZ();
        break;
    case 3:
        RflXZ();
        break;
    default:
        break;
    }
    break;
}

draw(output);

glFlush();

}

int main(int argc, char** argv)
{
 
    choice =3;
    switch (choice) {
    case 3:
        cout<<" axis:\n1 x axis \n 2 y axis \n3 z axis";
        cin>>choiceRot;
        switch (choiceRot) {
        case 1:
            cout<<"\nENter  angle: ";
            cin>>angle;
            break;
        case 2:
            cout<<"\nENter  angle: ";
            cin>>angle;
            break;
        case 3:
            cout<<"\nENter angle  ";
            cin>>angle;
            break;
        default:
            break;
        }
        break;
    case 4:cout<<"Enter your choice for Reflection about:\n1. XY plane"
             <<"\n2. YZ plane\n3. XZ plane"
              <<"\n =>";
        cin>>choiceRfl;
        break;
    default:
        break;
    }

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(1362,750);
    glutInitWindowPosition(0,0);
    
    glutCreateWindow("3D TRANSFORMATIONS");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
return 0;
}