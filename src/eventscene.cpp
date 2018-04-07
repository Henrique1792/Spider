#include "../include/eventscene.h"


/****Display****/
void cleanScreen(){ 
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
}

void display(){
	cleanScreen();
	glPushMatrix();
	/*Draw Boris the spider here!*/
	glPopMatrix();
	glutSwapBuffers();
}
void reshape(int w, int h){
	//prevent divide by 0
	if(h==0) h=1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	if(w<=h)
		gluOrtho2D (0.0f, ORTHO_X, 0.0f, ORTHO_Y*h/w);
	else
		gluOrtho2D (0.0f, ORTHO_X*w/h, 0.0f, ORTHO_Y);
} 
