#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "../include/spider.h"
#include "../include/scene.h"

void set_body(SPIDER *spider, GLfloat ceph_center_x, GLfloat ceph_center_y, GLfloat ceph_rad, GLfloat abs_center_x, GLfloat abs_center_y, GLfloat abs_rad)
{
    spider->body->ceph_center[0] = ceph_center_x;
    spider->body->ceph_center[1] = ceph_center_y;
    spider->body->ceph_rad = ceph_rad;
    spider->body->abs_center[0] = abs_center_x;
    spider->body->abs_center[1] = abs_center_y;
    spider->body->abs_rad = abs_rad;
}

void set_leg(LEG *leg, GLfloat rad, GLfloat x, GLfloat y)
{
    GLfloat angle, new_x, new_y, dir_x, dir_y;
    
    angle = dec_to_rad(rad);
	new_x = x + get_cos(angle);
    new_y = y + get_sin(angle);
	dir_x = get_cos(angle);
    dir_y = get_sin(angle);
	leg->x[0] = new_x;
    leg->y[0] = new_y;
    leg->x[1] = new_x + (dir_x * LEG_SIZE);
    leg->y[1] = new_y + (dir_y * LEG_SIZE);
    leg->x[2] = new_x + (dir_x * LEG_SIZE);
    leg->y[2] = new_y + (dir_y * LEG_SIZE);
}

void allocate_spider(SPIDER *spider)
{
    spider->body = (BODY *) malloc (sizeof(BODY));
    
    spider->first_pair = (PAIR *) malloc (sizeof(PAIR));
    spider->second_pair = (PAIR *) malloc (sizeof(PAIR));
    spider->third_pair = (PAIR *) malloc (sizeof(PAIR));
    spider->fourth_pair = (PAIR *) malloc (sizeof(PAIR));
    
    spider->first_pair->left = (LEG *) malloc (sizeof(LEG));
    spider->first_pair->right = (LEG *) malloc (sizeof(LEG));

    spider->second_pair->left = (LEG *) malloc (sizeof(LEG));
    spider->second_pair->right = (LEG *) malloc (sizeof(LEG));

    spider->third_pair->left = (LEG *) malloc (sizeof(LEG));
    spider->third_pair->right = (LEG *) malloc (sizeof(LEG));

    spider->fourth_pair->left = (LEG *) malloc (sizeof(LEG));
    spider->fourth_pair->right = (LEG *) malloc (sizeof(LEG));
}

SPIDER *init_spider()
{
    SPIDER *spider = (SPIDER *) malloc (sizeof(SPIDER));

    allocate_spider(spider);

    //Body
    set_body(spider, CEPH_CENTER_INIT_X, CEPH_CENTER_INIT_Y, CEPH_RAD, ABS_CENTER_INIT_X, ABS_CENTER_INIT_Y, ABS_RAD);

	//Legs
    set_leg(spider->first_pair->left, 45, CEPH_CENTER_INIT_X, CEPH_CENTER_INIT_Y);
    set_leg(spider->first_pair->right, 135, CEPH_CENTER_INIT_X, CEPH_CENTER_INIT_Y);
    
    set_leg(spider->second_pair->left, 10, CEPH_CENTER_INIT_X, CEPH_CENTER_INIT_Y);
    set_leg(spider->second_pair->right, 170, CEPH_CENTER_INIT_X, CEPH_CENTER_INIT_Y);

    set_leg(spider->third_pair->left, 345, CEPH_CENTER_INIT_X, CEPH_CENTER_INIT_Y);
    set_leg(spider->third_pair->right, 195, CEPH_CENTER_INIT_X, CEPH_CENTER_INIT_Y);
	
    set_leg(spider->fourth_pair->left, 330, CEPH_CENTER_INIT_X, CEPH_CENTER_INIT_Y);
    set_leg(spider->fourth_pair->right, 210, CEPH_CENTER_INIT_X, CEPH_CENTER_INIT_Y);

	return spider;
}

void free_pair(PAIR *pair)
{
	free(pair->left);
	free(pair->right);
	free(pair);
}

void free_spider(SPIDER *parker)
{
    free(parker->body);
    free(parker->first_pair);
    free(parker->second_pair);
    free(parker->third_pair);
    free(parker->fourth_pair);
    free(parker);
}