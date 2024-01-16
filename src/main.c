#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#include <windows.h>
#endif

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "settings.h"
#include "types/data.h"
#include "io/render.h"
#include "io/input.h"

double TOL = 2.5;
double CANVAS_SIZE[4] = {ORTHO_SIZE};

void onInitialization()
{
    glClearColor(1, 1, 1, 0);
    glPointSize(TOL * 2);

    pointDataPush(createPointXY(0.5, 0.5));

    lineDataPush(createLineP(createPointXY(0.25, 0.5), createPointXY(0.5, 0.75)));

    Poly *p = createPoly();
    polyPush(p, createPointXY(0.5, 0.5));
    polyPush(p, createPointXY(0.25, 0.5));
    polyPush(p, createPointXY(0.25, 0.25));

    polygonDataPush(p);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(ORTHO_SIZE);
}

void onDisplay()
{
    // Perform configured tasks for each key
    keyOperations();
    keySpecialOperations();

    glClear(GL_COLOR_BUFFER_BIT);

    // Render each object in DATA

    if (renderData() == 0)
    {
        printf("Render DATA Error\n");
        exit(1);
    }

    glutSwapBuffers();
}

int main(int argc, char const *argv[])
{
    // GLUT Config
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(
        (SCREEN_WIDTH - W) / 2,
        (SCREEN_HEIGH - H) / 2);
    glutInitWindowSize(W, H);
    glutCreateWindow("Paint");

    // Drawing presets
    onInitialization();

    // Draw
    glutDisplayFunc(onDisplay);

    // Input
    glutMouseFunc(onMouseClick);
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutSpecialFunc(keySpecialPressed);
    glutSpecialFunc(keySpecialReleased);

    // Loop
    glutMainLoop();

    return 0;
}
