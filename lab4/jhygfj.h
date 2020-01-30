#include <GL/glut.h>
#include <stdio.h>
 
int x, y, r;
 
void myInit()
{
 
   glClearColor(1.0, 1.0, 1.0, 1.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(0.0, 0.0, 0.0);
   gluOrtho2D(0, 500, 0, 500);
}
 
float angle = 360.0;
void StepRot(int n)
{
  angle-=1.0;
  if(angle>=0)
      angle+=360;
  glClear(GL_COLOR_BUFFER_BIT);
  glutPostRedisplay();
  glutTimerFunc(25,StepRot,0);
}
 
 
void draw_pixel(int x, int y)
{
   glBegin(GL_POINTS);
   glVertex2i(x, y);
   glEnd();
}
void circle_points(int x, int y, int p, int q)
{
   draw_pixel(x + p, y + q);
   draw_pixel(x + p, y - q);
   draw_pixel(x + q, y + p);
   draw_pixel(x + q, y - p);
   draw_pixel(x - p, y + q);
   draw_pixel(x - p, y - q);
   draw_pixel(x - q, y + p);
   draw_pixel(x - q, y - p);
}
void draw_circle(int x, int y, int r)
{
   int d = 3 - 2 * r;
   int p = 0;
   int q = r;
   draw_pixel(x + r, y);
   draw_pixel(x, y + r);
   draw_pixel(x - r, y);
   draw_pixel(x, y + r);
   while (p < q)
   {
       p++;
       if (d <= 0)
           d = d + 4 * p + 6;
       else
       {
           q--;
           d = d + 4 * (p - q) + 10;
       }
       circle_points(x, y, p, q);
   }
}
void draw_line(int x1, int x2, int y1, int y2)
{
   int dx, dy, i, e;
   int incx, incy, inc1, inc2;
   int x, y;
 
   dx = x2 - x1;
   dy = y2 - y1;
 
   if (dx < 0)
       dx = -dx;
   if (dy < 0)
       dy = -dy;
   incx = 1;
   if (x2 < x1)
       incx = -1;
   incy = 1;
   if (y2 < y1)
       incy = -1;
   x = x1;
   y = y1;
   if (dx > dy)
   {
       draw_pixel(x, y);
       e = 2 * dy - dx;
       inc1 = 2 * (dy - dx);
       inc2 = 2 * dy;
       for (i = 0; i < dx; i++)
       {
           if (e >= 0)
           {
               y += incy;
               e += inc1;
           }
           else
               e += inc2;
           x += incx;
           draw_pixel(x, y);
       }
   }
   else
   {
       draw_pixel(x, y);
       e = 2 * dx - dy;
       inc1 = 2 * (dx - dy);
       inc2 = 2 * dx;
       for (i = 0; i < dy; i++)
       {
           if (e >= 0)
           {
               x += incx;
               e += inc1;
           }
           else
               e += inc2;
           y += incy;
           draw_pixel(x, y);
       }
   }
}
void myDisplay()
{
 
    glPushMatrix();
      glTranslatef(250,250,0);
      glRotatef(angle,0.0,0.0,1.0);
      glTranslatef(-250,-250,0);
 
   draw_circle(250, 250, 150);
   draw_circle(250, 250, 30);
   draw_line(250, 250, 280, 400); //line up
   draw_line(271, 356, 271, 356); //line up right
   draw_line(280, 400, 250, 250); //line right
   draw_line(271, 356, 229, 144); //line right down
   draw_line(250, 250, 220, 100); //line up
   draw_line(229, 144, 229, 144); //line down left
   draw_line(220, 100, 250, 250); //line left
   draw_line(229, 144, 271, 356); //line left up
   glPopMatrix();
    glPopMatrix();

   draw_line(0, 500, 100, 100);   //base
   glFlush();
}
 
int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(0, 0);
   glutCreateWindow("Bresenham's Circle Drawing");
   myInit();
   glutDisplayFunc(myDisplay);
   glutTimerFunc(25,StepRot,0);
   glutMainLoop();
   return 0;
}
 


