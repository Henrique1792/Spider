#ifndef SCENE_H
#define SCENE_H

#include "../include/spider.h"

#define WIDTH 800
#define HEIGHT 600

#define VIEWPORT_X 400
#define VIEWPORT_Y 300

#define PI 3.14159265359

void draw();
void initialize();
void reshape(int width, int height);

void draw_circle(GLfloat center_x, GLfloat center_y, GLfloat radius, int num_segments);
void draw_leg(LEG *leg);

#endif