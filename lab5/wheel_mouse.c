#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

static GLfloat spin = 0.0;
static GLfloat spin_speed = 1.0;
float spin_x = 1;
float spin_y = 1;
float spin_z = 1;
float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;
float xc = -30.0, yc = 0.0;
int r1 = 6;
int r2 = 2;

//------- custom functions starts -------
void setSpin(float x, float y, float z)
{
    spin_x = x;
    spin_y = y;
    spin_z = z;
}
void reset()
{
    spin_x = 0;
    spin_y = 1;
    spin_z = 0;
    translate_x = 0.0;
    translate_y = 0.0;
    translate_z = -30.0;
}
//------- custom functions ends -------
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0f, (GLfloat)w / (GLfloat)h, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
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
void bresenham_circle(int r)
{
    int x = 0, y = r;

    float pk = 3 - (2 * r);

    /* Plot the points */
    /* Plot the first point */

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

void draw_circle()

{
     glTranslatef(translate_x, translate_y, translate_z);
    glRotatef(spin, spin_x, spin_y, spin_z);
    // glClear(GL_COLOR_BUFFER_BIT);
    bresenham_circle(r1);
    bresenham_circle(r2);
    plot_lines();


    	// //Draw Circle
		// 	glBegin(GL_POLYGON);
		// 		//Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
		// 		//Note that anything above 24 will have little affect on the circles appearance
		// 		//Play with the numbers till you find the result you are looking for
		// 		//Value 1.5 - Draws Triangle
		// 		//Value 2 - Draws Square
		// 		//Value 3 - Draws Hexagon
		// 		//Value 4 - Draws Octagon
		// 		//Value 5 - Draws Decagon
		// 		//Notice the correlation between the value and the number of sides
		// 		//The number of sides is always twice the value given this range
		// 		for(double i = 0; i < 2 * 3.141; i += 3.141 / 6) //<-- Change this Value
 		// 			glVertex3f(cos(i) * radius, sin(i) * r1, 0.0);
		// 	glEnd();
		// 	//Draw Circle
}



void spinDisplay(void)
{
    spin = spin + spin_speed;
    if (spin > 360.0)
    {
        spin = spin - 360.0;
    }
    glutPostRedisplay();
}
void spinDisplayReverse(void)
{
    spin = spin - spin_speed;
    if (spin < 360.0)
    {
        spin = spin + 360.0;
    }
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
{
            printf("x : %d y: %d",x,y);
            xc =  (float)((float)x)/((float)70.0f); 
yc = (float)((float)y)/((float)70.0f);
// xc=x;
// yc=y;
            // glutIdleFunc(spinDisplay);
 
//               glFlush();
//                     glClearColor(0, 0, 0, 0);
//   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//     glLoadIdentity();

//     //******************************************//
//     //------- custom code starts -------

//     // drawFan();
//     draw_circle();
//     // drawFanStand();

//     //------- custom code ends -------
//     //******************************************//
//     glutSwapBuffers();
//     glutPostRedisplay();
        glutPostRedisplay();
}
        
        break;


    case GLUT_MIDDLE_BUTTON:
        if (state == GLUT_DOWN)
        {
            glutIdleFunc(NULL);
        }
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
exit(0);        break;
    default:
        break;
    }
}
void keyboard(unsigned char key, int x, int y)
{
    //-------- spin --------
    if (key == 'x')
    {
        setSpin(1.0, 0.0, 0.0);
        glutPostRedisplay();
    }
    else if (key == 'y')
    {
        setSpin(0.0, 1.0, 0.0);
        glutPostRedisplay();
    }
    else if (key == 'z')
    {
        setSpin(0.0, 0.0, 1.0);
        glutPostRedisplay();
    }
    else if (key == 'a')
    {
        setSpin(1.0, 1.0, 1.0);
        glutPostRedisplay();
    }
    //-------- spin --------
    //-------- zoom --------
    else if (key == 'i')
    {
        translate_z++;
        glutPostRedisplay();
    }
    else if (key == 'd')
    {
        translate_z--;
        glutPostRedisplay();
    }
    //-------- zoom --------
    //-------- reset -------
    else if (key == 'c')
    {
        glFlush();
    }
    //-------- reset -------
}

// assuming work-window width=50unit, height=25unit;
void init()
{
        glClearColor(0.0, 1.0, 1.0, 0);
    glColor3f(0.0, 0.0, 0.0);
    gluOrtho2D(-683, 683, -384, 384);
    // glClearColor(0, 0, 0, 0);
    // glShadeModel(GL_SMOOTH); // Enable Smooth Shading
    // glClearDepth(1.0f);      // Depth Buffer Setup
    // glEnable(GL_DEPTH_TEST); // Enables Depth Testing
}

void drawFan()
{
    glTranslatef(translate_x, translate_y, translate_z);

    glRotatef(spin, spin_x, spin_y, spin_z);

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(0, 0);
    glVertex2i(-2, 5);
    glVertex2i(2, 5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(0, 0);
    glVertex2i(5, 2);
    glVertex2i(5, -2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(0, 0);
    glVertex2i(-2, -5);
    glVertex2i(2, -5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(0, 0);
    glVertex2i(-5, 2);
    glVertex2i(-5, -2);
    glEnd();
}


void myDisplay()
{
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
// glPushMatrix();
    //******************************************//
    //------- custom code starts -------

    // drawFan();
    draw_circle();
    // drawFanStand();

    //------- custom code ends -------
    //******************************************//
    glutSwapBuffers();
    // glPopMatrix();

}

void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1366, 768);
    glutCreateWindow("Keyboard and Mouse Interaction");
       glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3.0);

    glutDisplayFunc(myDisplay);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}