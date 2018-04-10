#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define VIEWPORT_X 800
#define VIEWPORT_Y 600
#define ORTHO_X 400
#define ORTHO_Y 300

/****Defines****/

/****Angle and Legs Disposition****/
#define innerLegAngle (M_P1*45)/180
#define outterLegAngle (M_P1*60)/180

#define AbsRAD 4
#define CephRAD 3



/****Initial Point****/
#define CephCenterInitX VIEWPORT_X/2
#define CephCenterInitY VIEWPORT_Y/2

#define AbsCenterInitX (VIEWPORT_X/2)
#define AbsCenterInitY (VIEWPORT_Y)+(AbsRAD+CephRAD)

typedef struct Point{
	GLint x,y;
}Point;

typedef struct Leg{
	//first leg section.
	Point *p1,*p2;
	//Second leg section.
	Point *p3;

}Leg;
typedef struct LegPair{
	Leg *left, *right;
	
}LegPair;

typedef struct Body{
	Point *CephCenter, *AbsCenter;
	GLint CephRad, AbsRad;
}Body;

typedef struct Spider{
	Body *corpse;
	LegPair *Pair1,*Pair3;
	LegPair *Pair2,*Pair4;
}Spider;



/****Globals****/
Spider *spd;




#endif
