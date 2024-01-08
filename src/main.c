#if defined(__WIN32__) || defined(_WIN32) || defined(__CYGWIN__) || defined(__MINGW32__) || defined(__BORLANDC__)
#include <windows.h>
#endif

#include <GL/freeglut.h>
#include <GL/glut.h>

#include "settings.h"
#include "render.h"
#include "input.h"

void onInitialization()
{
    glClearColor(1, 1, 1, 0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1, 0, 1);
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
    glutKeyboardFunc(keyPressed);
    glutKeyboardUpFunc(keyReleased);
    glutSpecialFunc(keySpecialPressed);
    glutSpecialFunc(keySpecialReleased);

    // Loop
    glutMainLoop();

    return 0;
}
