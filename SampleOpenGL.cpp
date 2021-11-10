#include <iostream>
#include <gl/glut.h>

void setPixel(int xPos, int yPos)					// set pixel at integer point (x,y)
{
	glBegin(GL_POINTS);
	glVertex2i((GLint)xPos, (GLint)yPos);			// set pixel
	glEnd();
}

void drawLine(int xStart, int yStart, int xEnd, int yEnd)		// draw a line from integer
{									// point (xStart, yStart) to
	glBegin(GL_LINES);						// (xEnd, yEnd)
	glVertex2i((GLint)xStart, (GLint)yStart);			// line start point
	glVertex2i((GLint)xEnd, (GLint)yEnd);			// line end point				
	glEnd();
}

void lineBreak(int xa, int ya, int xb, int yb) 
{
	int dx = abs(xa - xb), dy = abs(ya - yb);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy - dx, twoDyDx = 2 * (dy - dx);
	int x, y, xend;

	if (xa > xb) 
	{
		x = xb;
		y = yb;
		xend = xa;
	}
	else 
	{
		x = xa; 
		y = ya;
		xend = xb;
	}
	setPixel(x, y);
	while (x < xend) 
	{
		x = x + 1;
		if (p < 0) 
		{
			p = p + twoDy;
		}
		else
		{
			setPixel(x, y);
		}
	}
}

void myDisplayFunction(void)						 // this is your function
{
	glClear(GL_COLOR_BUFFER_BIT);					// clear the screen
	
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(50, 75);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(75, 125);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(100, 75);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(125, 75);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(125,125);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(175, 125);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2i(175, 75);
	glEnd();

	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(200, 75);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(225, 75);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(250, 150);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(225, 175);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(200, 200);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(185, 150);
	glEnd();

	


	/*
	glBegin(GL_LINES);	
	glColor3d(0.0, 0.0, 1.0);					// set blue drawing color
	glVertex2i(100, 50);
	glVertex2i(100, 100);
	glColor3d(0.0, 1.0, 0.0);					// set blue drawing color
	glVertex2i(100, 100);
	glVertex2i(150, 100);
	glColor3d(1.0, 0.0, 0.0);					// set blue drawing color
	glVertex2i(150, 100);
	glVertex2i(150, 50);
	glColor3d(0.0, 1.0, 1.0);					// set blue drawing color
	glVertex2i(150, 50);
	glVertex2i(100, 50);
	glEnd();							

	glBegin(GL_POINTS);
	glColor3d(0.0, 0.0, 1.0);
	glVertex2i(125, 125);
	glEnd();

	glColor3d(0.0, 0.0, 0.0);					// set black drawing color
	*/

	glFlush();							// send all output to display
}

void main(int argc, char** argv)					// start of main program
{

	glutInit(&argc, argv);						// initialize the GLUT library
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);		        // set the display mode
	glutInitWindowSize(512, 512);						// set window screen size
	glutInitWindowPosition(100, 100);					// set window position on screen
	glutCreateWindow("Isaiah White-Booth");				// open the screen window with title


	glutDisplayFunc(myDisplayFunction);					// register the callback function

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// set white background color
	glColor3d(0.0, 0.0, 0.0);							// set black drawing color
	gluOrtho2D(0.0, 511.0, 0.0, 511.0);					// specify screen coordinates
									  // bottom left = (0,0)
									  // top right = (511, 511)

	glutMainLoop();							// go into a perpetual loop

}