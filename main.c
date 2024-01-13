#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>


#include "input.h"
#include "render.h"
#include "settings.h"
#include "load.h"
#include "poly.h"

void onInitialization()
{
    glClearColor(1, 1, 1, 0);

    loadArquive("arquive.txt");

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 300);
}

void onDisplay(void)
{


    // Perform configured tasks for each key
    keyOperations();
    keySpecialOperations();

    glClear(GL_COLOR_BUFFER_BIT);

    // Run render fuctions for each object
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(10);
    renderData();

    /*glBegin(GL_POLYGON);
        glVertex2i(60, 60);
        glVertex2i(70, 70);
        glVertex2i(80, 80);
    glEnd();*/

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    // GLUT Config
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(200, 0);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Paint");

    // Drawing settings
    onInitialization();

    // Draw
    glutDisplayFunc(onDisplay);
    glutMouseFunc(onMouseClick);

    // Input
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutSpecialFunc(keySpecial);
    glutSpecialUpFunc(keySpecialUp);

    // Loop
    glutMainLoop();

    return 0;
}
