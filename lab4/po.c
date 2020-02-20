
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

// Center of the cicle = (320, 240)
int xc = 320, yc = 240;

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
  glFlush();
}

void draw_circle(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  int radius = 100;
  bresenham_circle(radius);
}

void Init()
{
  glClearColor(0.0, 1.0, 1.0, 0);
  glColor3f(0.0, 0.0, 0.0);
  gluOrtho2D(0, 640, 0, 480);
}

void main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(640, 480);
  glutCreateWindow("bresenham_circle");
  Init();
  glutDisplayFunc(draw_circle);
  glutMainLoop();
}
