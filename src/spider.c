#include "../include/settings.h"
#include "../include/spider.h"

//init point
Point  *initPoint(){
	Point *tgt=(Point *)malloc(sizeof(Point));
	return tgt;
}

//set point
void setPoint(Point *tgt, GLint x, GLint y){
	tgt->x=x;
	tgt->y=VIEWPORT_Y-y;
}

//init leg
Leg *initLeg(){
	Leg *rt=(Leg *)malloc(sizeof(Leg));
	rt->p1=initPoint();
	rt->p2=initPoint();
	rt->p3=initPoint();
	return rt;
}
//setLeg
void setLeg(Leg *tgt, GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3){
	
	setPoint(tgt->p1,x1,y1);
	setPoint(tgt->p2,x2,y2);
	setPoint(tgt->p3,x3,y3);
}

//init LegPair
LegPair *initLegPair(){

	LegPair *rt=(LegPair *)malloc(sizeof(LegPair));
	rt->left=initLeg();
	rt->right=initLeg();
	return rt;
}

//set Legpair
void setLegPair(LegPair *tgt,GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3,
			GLint X1, GLint Y1, GLint X2, GLint Y2, GLint X3, GLint Y3){
	
	 setLeg(tgt->left, x1, y1, x2, y2, x3, y3);
	 setLeg(tgt->right, X1, Y1, X2, Y2, X3, Y3);
}

//init Body
Body *initBody(){
	Body *rt=(Body *)malloc(sizeof(Body));
	rt->CephCenter=initPoint();
	rt->AbsCenter=initPoint();
	return rt;
}

//set body
void setBody(Body *tgt,GLint CepCenterX, GLint CepCenterY, GLint CepRad, GLint AbsCenterX, GLint AbsCenterY, GLint AbsRad){

	setPoint(tgt->CephCenter, CepCenterX, CepCenterY);
	setPoint(tgt->AbsCenter, AbsCenterX, AbsCenterY);
	tgt->CephRad=CepRad;
	tgt->AbsRad=AbsRad;
}


//init spider
Spider *initSpider(){
	Spider *boris=(Spider *)malloc(sizeof(Spider));
	GLint tmpX=CephCenterInitX-CephRAD, tmpY=CephCenterInitY-CephRAD;
	
	glPushMatrix();
		glRotatef(outterLegAngle,tmpX, tmpY,1.0);
	glPopMatrix();

	boris->corpse=initBody();
	boris->Pair1=initLegPair();
	boris->Pair2=initLegPair();
	boris->Pair3=initLegPair();
	boris->Pair4=initLegPair();
	
	//Set values here!
	setBody(boris->corpse, CephCenterInitX, CephCenterInitY, CephRAD, AbsCenterInitX, AbsCenterInitY, AbsRAD );
	setLeg(boris->Pair1->left, tmpX, tmpY,tmpX-LegSize, tmpY-LegSize, tmpX+LegSize, tmpY-(2*LegSize));
	return boris;
}




//drawSpider
void drawSpider();
