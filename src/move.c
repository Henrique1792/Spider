#include "../include/move.h"
#include "../include/vector.h"


void spider_setPosition(SPIDER* spider, GLfloat x, GLfloat y) {
	spider->pos.x = x;
	spider->pos.y = y;
}

void spider_setRotation(SPIDER* spider, GLfloat rotation) {
	if (rotation > 360.0f)
		rotation = 0.0f;
	else if (rotation < 0.0f)
		rotation = 360.0f;

	spider->rotation = rotation;
}

void spider_setScale(SPIDER* spider, GLfloat scale) {
	if (scale > 0.2f && scale < 5.0f)
		spider->scale = scale;
}



void spider_rotate(SPIDER* spider, GLfloat delta) {
	spider_setRotation(spider, spider->rotation + delta);
}

void spider_scale(SPIDER* spider, GLfloat delta) {
	spider_setScale(spider, spider->scale + delta);
}

void spider_setTarget(SPIDER* spider, float x, GLfloat y) {
	spider->target.x = x;
	spider->target.y = y;
}



void spider_move(SPIDER* spider, float deltaTime) {
	// andar para frente
	vec2 dir, speed;
	dir.x = cosf(spider->rotation * PI/180);
	dir.y = sinf(spider->rotation * PI/180);
	vector_mul(&speed, &dir, deltaTime);
	vector_add(&(spider->pos), &(spider->pos), &speed);
}
