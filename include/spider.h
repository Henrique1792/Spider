#ifndef SPIDER_H
#define SPIDER_H

#include <math.h>
#include "../include/vector.h"
#define CEPH_RAD 30
#define ABS_RAD 40
#define LEG_SIZE 25

#define CEPH_CENTER_INIT_X 0
#define CEPH_CENTER_INIT_Y 0

#define ABS_CENTER_INIT_X (0)
#define ABS_CENTER_INIT_Y (0) + (ABS_RAD + CEPH_RAD)

#define get_cos(x) cos(x) * CEPH_RAD
#define get_sin(y) sin(y) * CEPH_RAD

#define PI 3.14159265359

#define dec_to_rad(x) (PI * x) / 180
#define inner_leg_angle (PI * 45) / 180
#define outter_leg_angle (PI * 60) / 180

typedef struct leg
{
	float x[3], y[3];
}LEG;

typedef struct pair
{
	LEG *left, *right;
}PAIR;

typedef struct body
{
	float ceph_center[2], abs_center[2], ceph_rad, abs_rad;
}BODY;

typedef struct spider
{
	vec2 pos, target;
	GLfloat rotation, scale;
	BODY *body;
	PAIR *first_pair, *second_pair, *third_pair, *fourth_pair;
}SPIDER;

void allocate_spider(SPIDER *spider);

SPIDER *init_spider();

void set_body(SPIDER *spider, GLfloat ceph_center_x, GLfloat ceph_center_y, GLfloat ceph_rad, GLfloat abs_center_x, GLfloat abs_center_y, GLfloat abs_rad);

void set_leg(LEG *leg, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, int side);

void free_pair(PAIR *pair);

void free_spider(SPIDER *parker);

SPIDER *spider;

#endif
