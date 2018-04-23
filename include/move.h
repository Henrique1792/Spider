#ifndef MOVE_H_
#define MOVE_H_


#include "spider.h"

void spider_setPosition(SPIDER* spider, GLfloat x, GLfloat y);
void spider_setRotation(SPIDER* spider, GLfloat rotation);
void spider_setScale(SPIDER* spider, GLfloat scale);
void spider_rotate(SPIDER* spider, GLfloat delta);
void spider_scale(SPIDER* spider, GLfloat delta);
void spider_setTarget(SPIDER* spider, float x, GLfloat y);
void spider_move(SPIDER* spider, float deltaTime);


#endif
