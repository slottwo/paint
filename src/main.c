#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#include <windows.h>
#endif

#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "settings.h"
#include "types/data.h"
#include "io/render.h"
#include "io/input.h"
#include "io/file/load.h"

void onInitialization()
{
    glClearColor(BG_COLOR);
    glPointSize(5);

    loadArquive(file);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(ORTHO_SIZE);
}

void onDisplay()
{
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

    // glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF);

    // Loop
    glutMainLoop();

    return 0;
}
