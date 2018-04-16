#include <GL/gl.h>
#include <GL/glut.h>
#include "../include/scene.h"

void initialize() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-WIDTH, WIDTH, -HEIGHT, HEIGHT);
	glViewport(0, 0, WIDTH, HEIGHT);
    glEnable(GL_POINT_SMOOTH);
}

void reshape (int width, int height) 
{  
    glViewport (0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0, (GLdouble) width, 0.0, (GLdouble) height);
}

void draw() 
{    
    // Repaint screen
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(10.0, 10.0, 0.0);
	glEnd();
    
    glFlush();

    // glutPostRedisplay();
}

