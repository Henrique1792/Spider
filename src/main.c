#include <GL/gl.h>
#include <GL/glut.h>
#include "../include/scene.h"

int main (int argc, char *argv[])
{
    //GLUT Init
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    //Window
    glutInitWindowSize(WIDTH, HEIGHT); // Defines the size in pixels of the window
    glutCreateWindow("Spider"); // Defines the window title
    
    //Rendering
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape); 

    //Initialize
    initialize();
    
    glutMainLoop();

    return EXIT_SUCCESS;
}
