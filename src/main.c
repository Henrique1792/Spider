#include <GL/gl.h>
#include <GL/glut.h>
#include "../include/scene.h"

int main (int argc, char *argv[])
{
    //GLUT Init
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    //Initialize
    initialize();

    //Rendering
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape); 
    
    glutMainLoop();

    return EXIT_SUCCESS;
}
