#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

int xc, yc, radius, tx, ty;

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
int x, y;
void bresenham_circle(int r)
{
  x = 0;
  y = r;
  float pk = 3 - 2.0 * r;
  plot_point(x, y);
  int k;
  glColor3f(0.0, 0.0, 0.0);
  while (x < y)
  {
    x = x + 1;
    if (pk < 0)
      pk = pk + 4 * x + 6;
    else
    {
      y = y - 1;
      pk = pk + 4 * (x - y) + 10;
    }
    plot_point(x, y);
  }
  glEnd();
  draw_translated_fig();
  glFlush();
}

void draw_translated_fig()
{
  x = 0;
  y = radius * tx;
  float pk = 3 - 2.0 * radius * tx;
  plot_point(x, y);
  int k;
  xc += tx;
  yc += tx;
  glColor3f(1.0, 0.0, 0.0);
  while (x < y)
  {
    x = x + 1;
    if (pk < 0)
      pk = pk + 4 * x + 6;
    else
    {
      y = y - 1;
      pk = pk + 4 * (x - y) + 10;
    }
    plot_point(x, y);
  }
  glEnd();
}

void Init()
{
  glClearColor(1.0, 1.0, 1.0, 0);
  glColor3f(0.0, 0.0, 0.0);
  gluOrtho2D(-683, 683, -384, 384);
}

void display(void)
{

  glClear(GL_COLOR_BUFFER_BIT);

  bresenham_circle(radius);
}

void main(int argc, char **argv)
{
  glutInit(&argc, argv);
  printf("enter the radius\n");
  scanf("%d", &radius);
  printf("enter the center\n");
  scanf("%d %d", &xc, &yc);
  printf("enter the scaling factor\n");
  scanf("%d", &tx);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(1366, 768);
  glutCreateWindow("bresenham_circle");
  Init();
  glutDisplayFunc(display);
  glutMainLoop();
}