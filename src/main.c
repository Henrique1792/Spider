#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include "../include/scene.h"

int main (int argc, char *argv[])
{
    //GLUT Init
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    
    //Window
    glutInitWindowSize(WIDTH, HEIGHT); // Defines the size in pixels of the window
    glutCreateWindow("Spider"); // Defines the window title
    
    //Rendering
    glutDisplayFunc(drawLoop);
    glutReshapeFunc(reshape); 
    glutIdleFunc(drawLoop);

    //Events
    glutMouseFunc(on_mouseClick);

    glMatrixMode(GL_PROJECTION); // Load matrix mode
    glViewport(0, 0, WIDTH, HEIGHT); // Set viewport size
    glOrtho(-WIDTH/2, WIDTH/2, -HEIGHT/2, HEIGHT/2, -1, 1); // Defines the orthogonal plane to build the scene in

    glutMainLoop();

    return EXIT_SUCCESS;
}
