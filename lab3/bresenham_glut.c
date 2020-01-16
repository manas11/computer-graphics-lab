#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

int x1, x2, y4, y2;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    int m_new = 2 * (y2 - y4);
    int slope_error_new = m_new - (x2 - x1);
    for (int x = x1, y = y4; x <= x2; x++)
    {

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();

        slope_error_new += m_new;
        if (slope_error_new >= 0)
        {
            y++;
            slope_error_new -= 2 * (x2 - x1);
        }
    }
    glFlush();
}

void myInit()
{

    glClearColor(0.0, 0.0, 0.0, 1.0);
    // glColor3f(0.0, 1.0, 0.0);

    // glPointSize(15.0);

    gluOrtho2D(-100, 100, -100, 100);
}

int main(int argc, char **argv)
{

    printf("\n enter x1 : ");
    scanf("%d", &x1);
    printf("\n enter y1 : ");
    scanf("%d", &y4);
    printf("\n enter x2 : ");
    scanf("%d", &x2);
    printf("\n enter y2 : ");
    scanf("%d", &y2);

    glutInit(&argc, argv);
    glutInitWindowSize(1366, 768);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("bresenham glut");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}