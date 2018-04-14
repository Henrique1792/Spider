#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include "../include/scene.h"

float mouse_x = 0;
float mouse_y = 0;

float dis_x = 0;
float dis_y = 0;

float pos_x = WIDTH / 2;
float pos_y = HEIGHT / 2;

float speed = 10;
float radian = 0;
float rotation = 0;

void reshape (int width, int height) 
{  
    glViewport (0, 0, width, height);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluOrtho2D (0.0, (GLdouble) width, 0.0, (GLdouble) height);
}

void on_mouseClick(int button, int click_state, int x_mouse_position, int y_mouse_position)
{
    mouse_x = x_mouse_position - (WIDTH / 2);
    mouse_y = - y_mouse_position + (HEIGHT / 2);
}

void move()
{
    dis_x = mouse_x - pos_x;
    dis_y = mouse_y - pos_y;
     
    if(sqrt(pow(dis_y, 2) + pow(dis_x, 2)) < speed)
    {
        pos_x = mouse_x;
        pos_y = mouse_y;                    
    }
    else
    {
        radian = atan2(dis_y, dis_x);
        pos_x += cos(radian) * speed;
        pos_y += sin(radian) * speed;
        rotation = radian * 100 / 3.14;     
    }
}

void drawScene()
{    
    // Refresh matrix for new object
    glLoadIdentity();

    // Teapot
    glColor3f(1,0,0);
    glTranslated(pos_x, pos_y, 0);
    glRotatef(rotation, 0, 0, 1);
    glutSolidTeapot(10);
    
    glFlush();
}

void drawLoop() 
{    
    // Background color
    glClearColor(1, 1, 1, 1);

    // Repaint screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw scene
    drawScene();

    //Update object position
    move();
}

