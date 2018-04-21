
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#endif
#include <stdio.h>
#include "../include/scene.h"
#include "../include/spider.h"

int main (int argc, char *argv[])
{
    spider = init_spider();

    //GLUT Init
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    //Initialize
    initialize();

    //Rendering
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape); 
    
    glutMainLoop();

    free_spider(spider);

    return EXIT_SUCCESS;
}
