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

    Poly *p = createPoly();
    polyPush(p, createPointXY(60, 60));
    polyPush(p, createPointXY(70, 70));
    polyPush(p, createPointXY(80, 80));
    polygonDataPush(p);

    lineDataPush(createLineP(createPointXY(50,50), createPointXY(100, 50)));


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
