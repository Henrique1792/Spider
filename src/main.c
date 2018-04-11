#include "../include/settings.h"
#include "../include/eventscene.h"
#include "../include/spider.h"





void init(){ 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(VIEWPORT_X, VIEWPORT_Y);
	glutInitWindowPosition((SCREEN_SIZEX-VIEWPORT_X)/2, (SCREEN_SIZEY-VIEWPORT_Y)/2);
	glutCreateWindow("Spider");

	glMatrixMode(GL_PROJECTION);
	glViewport(0,0,VIEWPORT_X,VIEWPORT_Y);
	glLoadIdentity();
	gluOrtho2D(0,VIEWPORT_X, 0,VIEWPORT_Y);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}




int main(int argc, char *argv[]){
	spd=initSpider();
	glutInit(&argc,argv);
	
	init();
	glutDisplayFunc(display);

	glutMainLoop();
}