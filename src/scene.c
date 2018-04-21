#include <GL/gl.h>
#include <GL/glut.h>
#include "../include/scene.h"

void initialize() {
	glutInitWindowSize(WIDTH, HEIGHT); // Defines the size in pixels of the window
    glutCreateWindow("Spider"); // Defines the window title
    glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
    glViewport(0, 0, VIEWPORT_X, VIEWPORT_Y);
    glLoadIdentity();
	gluOrtho2D(-VIEWPORT_X, VIEWPORT_X, -VIEWPORT_Y, VIEWPORT_Y);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void reshape (int width, int height) 
{  
    // glViewport (0, 0, (GLsizei) width, (GLsizei) height);
    // glMatrixMode (GL_PROJECTION);
    // glLoadIdentity ();
    // gluOrtho2D (0.0, (GLdouble) width, 0.0, (GLdouble) height);

    if(height==0) height=1;

	glViewport (0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);

	if(width <= height)
		gluOrtho2D (-VIEWPORT_X, VIEWPORT_X, VIEWPORT_Y, VIEWPORT_Y * (height / width));
	else
        gluOrtho2D (-VIEWPORT_X, VIEWPORT_X * (height / width), VIEWPORT_Y, VIEWPORT_Y);
}

void draw() 
{    
    // Repaint screen
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPointSize(10);
    glBegin(GL_POINTS);            // These vertices form a closed polygon
        glColor3f(0.0f, 10.0f, 0.0f); // Yellow
        glVertex2f(4.0f, 2.0f);
    glEnd();
 
    glFlush();  // Render now
}

