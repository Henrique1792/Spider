#ifndef VECTOR_H_
#define VECTOR_H_

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#endif
#include <stdlib.h>
#include <stdio.h>

typedef struct vec2{
	GLfloat x, y;

}vec2;


void vector_add(vec2* vr, vec2* v1, vec2* v2);

void vector_sub(vec2* vr, vec2* v1, vec2* v2);

void vector_mul(vec2* vr, vec2* v, GLfloat scalar);

GLfloat vector_length(vec2* v);

void vector_unit(vec2* unit, vec2* v);

#endif
