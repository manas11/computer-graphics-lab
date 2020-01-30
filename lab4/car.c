
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// Center of the cicle = (320, 240)
int xc = -300, yc = 0;
int xc2 = 100, yc2 = 0;
int x = 0;
int r1 = 100;
int r2 = 30;
int r3 = 110;
float angle = 360.0;

// Plot eight points using circle's symmetrical property
void plot_point(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc - y, yc - x);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc - y, yc + x);
    glEnd();
}

void plot_point2(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc2 + x, yc2 + y);
    glVertex2i(xc2 + x, yc2 - y);
    glVertex2i(xc2 + y, yc2 + x);
    glVertex2i(xc2 + y, yc2 - x);
    glVertex2i(xc2 - x, yc2 - y);
    glVertex2i(xc2 - y, yc2 - x);
    glVertex2i(xc2 - x, yc2 + y);
    glVertex2i(xc2 - y, yc2 + x);
    glEnd();
}

void plot_point3(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    // glVertex2i(xc2 + x, yc2 - y);
    glVertex2i(xc + y, yc + x);
    // glVertex2i(xc2 + y, yc2 - x);
    // glVertex2i(xc2 - x, yc2 - y);
    // glVertex2i(xc2 - y, yc2 - x);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc - y, yc + x);
    glEnd();
}

void plot_point4(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc2 + x, yc2 + y);
    // glVertex2i(xc2 + x, yc2 - y);
    glVertex2i(xc2 + y, yc2 + x);
    // glVertex2i(xc2 + y, yc2 - x);
    // glVertex2i(xc2 - x, yc2 - y);
    // glVertex2i(xc2 - y, yc2 - x);
    glVertex2i(xc2 - x, yc2 + y);
    glVertex2i(xc2 - y, yc2 + x);
    glEnd();
}
void RotateTime(int n)
{
    x += 1;
    angle -= 1.0;
    if (angle >= 0)
        angle += 360;
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
    glutTimerFunc(25, RotateTime, 0);
}
void acute_bresenham(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1, dy = y2 - y1;
    float yi = 1;
    if (dy < 0)
    {
        yi = -1;
        dy = -dy;
    }
    float D = 2 * dy - dx;

    glBegin(GL_POINTS);
    float x, y = y1;
    for (x = x1; x < x2; x++)
    {
        glVertex2f(x, y);
        if (D > 0)
        {
            y = y + yi;
            D = D - 2 * dx;
        }
        D = D + 2 * dy;
        //		printf("%d, %d\n", x, y);
    }
    glEnd();
}

void obtuse_bresenham(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1, dy = y2 - y1;
    float xi = 1;
    if (dx < 0)
    {
        xi = -1;
        dx = -dx;
    }
    float D = 2 * dx - dy;

    glBegin(GL_POINTS);
    float y, x = x1;
    for (y = y1; y < y2; y++)
    {
        glVertex2f(x, y);
        if (D > 0)
        {
            x = x + xi;
            D = D - 2 * dy;
        }
        D = D + 2 * dx;
        //		printf("%d, %d\n", x, y);
    }
    glEnd();
}

void bresenham(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1, dy = y2 - y1;
    if (abs(dy) < abs(dx))
    {
        dx > 0 ? acute_bresenham(x1, y1, x2, y2) : acute_bresenham(x2, y2, x1, y1);
    }
    else
    {
        dy > 0 ? obtuse_bresenham(x1, y1, x2, y2) : obtuse_bresenham(x2, y2, x1, y1);
    }
}

void plot_lines()
{
    bresenham(xc, yc + r2, xc, yc + r1);
    bresenham(xc + r1, yc, xc + r2, yc);
    bresenham(xc, yc - r2, xc, yc - r1);
    bresenham(xc - r1, yc, xc - r2, yc);
    bresenham(xc + (r2 / sqrt(2)), yc + (r2 / sqrt(2)), xc + (r1 / sqrt(2)), yc + (r1 / sqrt(2)));
    bresenham(xc - (r2 / sqrt(2)), yc - (r2 / sqrt(2)), xc - (r1 / sqrt(2)), yc - (r1 / sqrt(2)));
    bresenham(xc + (r2 / sqrt(2)), yc - (r2 / sqrt(2)), xc + (r1 / sqrt(2)), yc - (r1 / sqrt(2)));
    bresenham(xc - (r2 / sqrt(2)), yc + (r2 / sqrt(2)), xc - (r1 / sqrt(2)), yc + (r1 / sqrt(2)));
}
void plot_lines2()
{
    bresenham(xc2, yc2 + r2, xc2, yc2 + r1);
    bresenham(xc2 + r1, yc2, xc2 + r2, yc2);
    bresenham(xc2, yc2 - r2, xc2, yc2 - r1);
    bresenham(xc2 - r1, yc2, xc2 - r2, yc2);
    bresenham(xc2 + (r2 / sqrt(2)), yc2 + (r2 / sqrt(2)), xc2 + (r1 / sqrt(2)), yc2 + (r1 / sqrt(2)));
    bresenham(xc2 - (r2 / sqrt(2)), yc2 - (r2 / sqrt(2)), xc2 - (r1 / sqrt(2)), yc2 - (r1 / sqrt(2)));
    bresenham(xc2 + (r2 / sqrt(2)), yc2 - (r2 / sqrt(2)), xc2 + (r1 / sqrt(2)), yc2 - (r1 / sqrt(2)));
    bresenham(xc2 - (r2 / sqrt(2)), yc2 + (r2 / sqrt(2)), xc2 - (r1 / sqrt(2)), yc2 + (r1 / sqrt(2)));
}

void plot_road()
{
    int xc3 = -300, yc3 = 0;

    bresenham(xc3 - 200, yc3 - r1, xc3 + 800, yc3 - r1);
}
void bresenham_circle3(int r)
{
    int x = 0, y = r;

    float pk = 3 - (2 * r);

    /* Plot the points */
    /* Plot the first point */
    int k;

    while (x <= y)
    {
        plot_point3(x, y);

        if (pk < 0)
            pk = pk + (4 * x) + 6;
        else
        {
            pk = pk + 4 * (x - y) + 10;
            y = y - 1;
        }
        x = x + 1;
    }
}
void bresenham_circle4(int r)
{
    int x = 0, y = r;

    float pk = 3 - (2 * r);

    /* Plot the points */
    /* Plot the first point */
    int k;

    while (x <= y)
    {
        plot_point4(x, y);

        if (pk < 0)
            pk = pk + (4 * x) + 6;
        else
        {
            pk = pk + 4 * (x - y) + 10;
            y = y - 1;
        }
        x = x + 1;
    }
}
void plot_car()
{

    bresenham(xc + r1 + 10, yc, xc2 - r1 - 10, yc2);
    bresenham_circle3(r3);
    bresenham_circle4(r3);
    bresenham(xc - r1 - 10, yc, xc - r1 - 100, yc);
    bresenham(xc2 + r1 + 10, yc, xc2 + r1 + 100, yc);
    bresenham(xc - r1 - 100, yc, xc - r1 - 100, yc + 150);
    bresenham(xc2 + r1 + 100, yc, xc2 + r1 + 100, yc + 150);
    bresenham(xc - r1 - 100, yc + 150, xc, yc + 150);
    bresenham(xc2 + r1 + 100, yc + 150, xc2, yc2 + 150);
    bresenham(xc, yc + 150, xc, yc + 250);
    bresenham(xc2, yc + 150, xc2, yc + 250);
    bresenham(xc, yc + 250, xc2, yc + 250);
}
// Function to draw a circle using bresenham's
// circle drawing algorithm
void bresenham_circle(int r)
{
    int x = 0, y = r;

    float pk = 3 - (2 * r);

    /* Plot the points */
    /* Plot the first point */
    int k;

    while (x <= y)
    {
        plot_point(x, y);

        if (pk < 0)
            pk = pk + (4 * x) + 6;
        else
        {
            pk = pk + 4 * (x - y) + 10;
            y = y - 1;
        }
        x = x + 1;
    }
}
void bresenham_circle2(int r)
{
    int x = 0, y = r;

    float pk = 3 - (2 * r);

    /* Plot the points */
    /* Plot the first point */
    int k;

    while (x <= y)
    {
        plot_point2(x, y);

        if (pk < 0)
            pk = pk + (4 * x) + 6;
        else
        {
            pk = pk + 4 * (x - y) + 10;
            y = y - 1;
        }
        x = x + 1;
    }
}

void draw_circle(void)

{
    glClear(GL_COLOR_BUFFER_BIT);
    bresenham_circle(r1);
    bresenham_circle(r2);
    plot_lines();
}
void draw_circle2(void)

{
    bresenham_circle2(r1);
    bresenham_circle2(r2);
    plot_lines2();
}
void display()
{
    glPushMatrix();
    glTranslatef(xc + x, yc, 0);
    glRotatef(angle, 0.0, 0.0, 1.0);

    glTranslatef(-xc, -yc, 0);
    draw_circle();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(xc2 + x, yc2, 0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-xc2, -yc2, 0);
    draw_circle2();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(xc + x, yc, 0);
    // glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-xc, -yc, 0);
    plot_car();

    glPopMatrix();

    plot_road();

    glFlush();
}

void Init()
{
    glClearColor(0.0, 1.0, 1.0, 0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(-683, 683, -384, 384);
}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1366, 768);
    glutCreateWindow("figure");
    Init();
    glutDisplayFunc(display);
    glutTimerFunc(25, RotateTime, 0);
    glutMainLoop();
}
