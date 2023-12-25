#include <GL/glut.h>
#include <math.h>

#include "io/input.h"

#include "settings.h"

void onInitialization()
{
    glClearColor(0, 0, 0, 0);

    // Add here later the memory stacks initialization of the rendered objects

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1, 0, 1);
}

void onDisplay()
{
    keyOperations(); // Perform configured tasks for each key

    glClear(GL_COLOR_BUFFER_BIT);

    // Run render fuctions for each object

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

    // Loop
    glutMainLoop();

    return 0;
}
