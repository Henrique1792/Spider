#include "../include/vector.h"
#include <math.h>



/*
 * vector.c
 *
 *  Created on: 15 de abr de 2018
 *  Author: Guilherme Vicentin
 */



void vector_add(vec2* vr, vec2* v1, vec2* v2) {
	vr->x = v1->x + v2->x;
	vr->y = v1->y + v2->y;
}

void vector_sub(vec2* vr, vec2* v1, vec2* v2) {
	vr->x = v1->x - v2->x;
	vr->y = v1->y - v2->y;
}

void vector_mul(vec2* vr, vec2* v, GLfloat scalar) {
	vr->x = v->x * scalar;
	vr->y = v->y * scalar;
}

GLfloat vector_length(vec2* v) {
	return sqrtf(v->x * v->x + v->y * v->y);
}

void vector_unit(vec2* unit, vec2* v) {
	GLfloat length = vector_length(v);

	if (length > 0) {
		unit->x = v->x / length;
		unit->y = v->y / length;
	}
}
