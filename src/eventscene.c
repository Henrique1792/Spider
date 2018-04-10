#include "../include/settings.h"
#include "../include/eventscene.h"


void DrawCircle(float cx, float cy, float r, int num_segments){ 
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++){ 
		float theta = 2.0f * 3.1415926f * (float)ii / (float)num_segments;//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	} 
	glEnd(); 
}

/****Display****/
void cleanScreen(){ 
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	glPointSize(5);
}

void display(){
	cleanScreen();
	glPushMatrix();

	drawSpider();

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



void drawSpider(){
	//Draw corpse at first
	DrawCircle(spd->corpse->CephCenter->x,spd->corpse->CephCenter->y, CephRAD, 10);
	glutPostRedisplay();
	DrawCircle(spd->corpse->AbsCenter->x,spd->corpse->AbsCenter->y, AbsRAD, 10);
	
	
	glutPostRedisplay();
}
