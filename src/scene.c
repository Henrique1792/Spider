#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

#include "../include/scene.h"
#include "../include/spider.h"

void initialize()
{
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

void reshape(int width, int height) 
{  
    if(height==0) 
	{
		height=1;
	}

	glViewport (0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);

	if(width <= height)
	{
		gluOrtho2D (-VIEWPORT_X, VIEWPORT_X, VIEWPORT_Y, VIEWPORT_Y * (height / width));
	}
	else
	{
    	gluOrtho2D (-VIEWPORT_X, VIEWPORT_X * (height / width), VIEWPORT_Y, VIEWPORT_Y);
	}
}

void draw_circle(float center_x, float center_y, float radius, int num_segments)
{ 
	glBegin(GL_LINE_LOOP); 
	for(int i = 0; i < num_segments; i++)
    { 	
        float theta = 2.0f * PI * (float)i / (float)num_segments; //get the current angle 
		
        float x = radius * cosf(theta); //calculate the x component 
		float y = radius * sinf(theta); //calculate the y component 

		glVertex2f(x + center_x, y + center_y); //output vertex
	} 
	glEnd(); 
}

void draw_leg(LEG *leg)
{
	glBegin(GL_LINE_STRIP);
		glVertex2f(leg->x[0], leg->y[0]);
		glVertex2f(leg->x[1], leg->y[1]);
		glVertex2f(leg->x[2], leg->y[2]);
	glEnd();
}

void draw() 
{    
    // // Repaint screen
    // glClear(GL_COLOR_BUFFER_BIT);
    
    // glPointSize(10);
    // glBegin(GL_POINTS);            // These vertices form a closed polygon
    //     glColor3f(0.0f, 10.0f, 0.0f); // Yellow
    //     glVertex2f(4.0f, 2.0f);
    // glEnd();
 
    // glFlush();  // Render now


    glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
    glPointSize(10);

    glPushMatrix();

    //Body
	glBegin(GL_POINTS);
		glVertex2f(spider->body->ceph_center[0], spider->body->ceph_center[1]);
		glVertex2f(spider->body->abs_center[0], spider->body->abs_center[1]);
	glEnd();

	//Cephalotorax
	draw_circle(spider->body->ceph_center[0], spider->body->ceph_center[1], CEPH_RAD, 1000);
	
    //Abdomen
	draw_circle(spider->body->abs_center[0], spider->body->abs_center[1], ABS_RAD, 1000);
	
    //Legs
	glColor3f(1.0,0.0,0.0);
	draw_leg(spider->first_pair->left);
	draw_leg(spider->first_pair->right);

	glColor3f(0.0,1.0,0.0);
	draw_leg(spider->second_pair->left);
	draw_leg(spider->second_pair->right);

	glColor3f(0.0,0.0,1.0);
	draw_leg(spider->third_pair->left);
	draw_leg(spider->third_pair->right);

	draw_leg(spider->fourth_pair->left);
	draw_leg(spider->fourth_pair->right);

    glutPostRedisplay();

    glLoadIdentity();

	glPopMatrix();
    glutSwapBuffers();
}

