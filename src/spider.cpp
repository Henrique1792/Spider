#include "../include/spider.h"

//init point

Point  *initPoint(GLint x, GLint y){
	Point *tgt=(Point *)malloc(sizeof(Point));
	tgt->x=x;
	tgt->y=y;
	return tgt;
}

//init leg
Leg *initLeg(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3){
	Leg *rt=(Leg *)malloc(sizeof(Leg));
	rt->p1=initPoint(x1,y1);
	rt->p2=initPoint(x2,y2);
	rt->p3=initPoint(x3,y3);

	return rt;
}

//init LegPair

LegPair *initLegPair(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3,
			GLint X1, GLint Y1, GLint X2, GLint Y2, GLint X3, GLint Y3){

	LegPair *rt=(LegPair *)malloc(sizeof(LegPair));
	rt->left=initLeg(x1, y1, x2, y2, x3, y3);
	rt->right=initLeg(X1, Y1, X2, Y2, X3, Y3);
	return rt;
}

//init Body

Body *initBody(GLint CepCenterX, GLint CepCenterY, GLint CepRad, GLint AbsCenterX, GLint AbsCenterY, GLint AbsRad){
	Body *rt=(Body *)malloc(sizeof(Body));
	rt->CephCenter=initPoint(CepCenterX, CepCenterY);
	rt->AbsCenter=initPoint(AbsCenterX, AbsCenterY);
	rt->CephRad=CepRad;
	rt->AbsRad=AbsRad;
	return rt;
}

//init spider
Spider *initSpider(){
	Spider *boris=(Spider *)malloc(sizeof(Spider));
	boris->Body=initBody();
	boris->Pair1=initLegPair();
	boris->Pair2=initLegPair();
	boris->Pair3=initLegPair();
	boris->Pair4=initLegPair();
	return boris;
}




//drawSpider
void drawSpider();
