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

void draw_circle(float center_x, float center_y, float radius, int num_segments);
void draw_leg(LEG *leg);

#endif