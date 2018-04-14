#include "../include/settings.h"
#include "../include/spider.h"

//init point

Point  *initPoint(GLint x, GLint y){
	Point *tgt=(Point *)malloc(sizeof(Point));
	tgt->x=x;
	tgt->y=VIEWPORT_Y-y;
	return tgt;
}

//init leg
Leg *initLeg(){
	Leg *rt=(Leg *)malloc(sizeof(Leg));

	return rt;
}
//setLeg
void setLeg(Leg *tgt, GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3){
	tgt->p1=initPoint(x1,y1);
	tgt->p2=initPoint(x2,y2);
	tgt->p3=initPoint(x3,y3);
}
//init LegPair

LegPair *initLegPair(){

	LegPair *rt=(LegPair *)malloc(sizeof(LegPair));
	return rt;
}
//set Legpair

void setLegPair(LegPair *tgt,GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3,
			GLint X1, GLint Y1, GLint X2, GLint Y2, GLint X3, GLint Y3){
	 tgt->left=initLeg(x1, y1, x2, y2, x3, y3);
	 tgt->right=initLeg(X1, Y1, X2, Y2, X3, Y3);
}
//init Body

Body *initBody(){
	Body *rt=(Body *)malloc(sizeof(Body));
	return rt;
}
//set body

void setBody(Body *tgt,GLint CepCenterX, GLint CepCenterY, GLint CepRad, GLint AbsCenterX, GLint AbsCenterY, GLint AbsRad){

	tgt->CephCenter=initPoint(CepCenterX, CepCenterY);
	tgt->AbsCenter=initPoint(AbsCenterX, AbsCenterY);
	tgt->CephRad=CepRad;
	tgt->AbsRad=AbsRad;
}
//set LegPOS
void legPos(GLint *x, GLint *y, GLfloat theta){
	GLint tmpX=*x, tmpY=*y;

	tmpX=cos(theta)*(*x)-sin(theta)*(*y);
	tmpY=cos(theta)*(*x)+sin(theta)*(*y);
	
	*x+=tmpX-CephRAD, *y+=tmpY-CephRAD;

}
//init spider
Spider *initSpider(){
	Spider *boris=(Spider *)malloc(sizeof(Spider));

	boris->corpse=initBody();
	boris->Pair1=initLegPair();
	boris->Pair2=initLegPair();
	boris->Pair3=initLegPair();
	boris->Pair4=initLegPair();
	
	//Set values here!
	setBody(boris->corpse, CephCenterInitX, CephCenterInitY, CephRAD, AbsCenterInitX, AbsCenterInitY, AbsRAD );
	return boris;
}




//drawSpider
void drawSpider();
