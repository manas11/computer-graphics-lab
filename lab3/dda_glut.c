#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

float x1, x2, y4, y2;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float x, y, x_inc, y_inc;
    float dx = 0, dy = 0;
    float steps = 0;
    dx = x2 - x1;
    dy = y2 - y4;

    if (abs(dx) > abs(dy))
        steps = dx;
    else
        steps = dy;

    x_inc = dx / (float)steps;
    y_inc = dy / (float)steps;

    x = x1;
    y = y4;

    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (int i = 0; i < steps; i++)
    {
        x += x_inc;
        y += y_inc;

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }

    glFlush();
}

void myInit()
{

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.0, 1.0, 0.0);

    glPointSize(1.0);

    gluOrtho2D(-100, 100, -100, 100);
}
int main(int argc, char **argv)
{
    printf("\n enter x1 : ");
    scanf("%f", &x1);
    printf("\n enter y1 : ");
    scanf("%f", &y4);
    printf("\n enter x2 : ");
    scanf("%f", &x2);
    printf("\n enter y2 : ");
    scanf("%f", &y2);

    glutInit(&argc, argv);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("dda glut");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}