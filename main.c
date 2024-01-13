#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#include <windows.h>
#endif

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

#include "settings.h"
#include "render.h"
#include "input.h"
#include "data.h"

double TOL = 2.5;
double CANVAS_SIZE[4] = {ORTHO_SIZE};

void onInitialization()
{
    glClearColor(1, 1, 1, 0);
    glPointSize(TOL * 2);

    pointDataPush(createPointXY(CANVAS_SIZE[1] / 2, CANVAS_SIZE[3] / 2));

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(ORTHO_SIZE);
}

void onDisplay()
{
    // Perform configured tasks for each key
    keyOperations();
    keySpecialOperations();

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

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

    // Drawing settings
    onInitialization();

    // Draw
    glutDisplayFunc(onDisplay);
    glutMouseFunc(onMouseClick);

    // Input
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutSpecialFunc(keySpecialPressed);
    glutSpecialUpFunc(keySpecialReleased);

    // Loop
    glutMainLoop();

    return 0;
}
