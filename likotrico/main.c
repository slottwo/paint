#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>

#include "settings.h"
#include "render.h"
#include "input.h"

void onInitialization()
{
    glClearColor(1, 1, 1, 0);

    // Add here later the memory stacks initialization of the rendered objects

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 200, 0, 150);
}

void onDisplay(void)
{
    //keyOperations(); // Perform configured tasks for each key
    glClear(GL_COLOR_BUFFER_BIT);
    // Run render fuctions for each object
    glColor3f(1.0, 0.0, 0.0);

    polygon *p = createpolygon();
    polygonPush(p, createPointXY(50, 50));
    polygonPush(p, createPointXY(200, 50));
    polygonPush(p, createPointXY(200, 10));

    printf("%d\n", polygonLength(p));
    renderLines(p);
    //renderpolygon(p);
    //renderPoint(createPointXY(100, 100));
    //glFlush();
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

    // Drawing presets
    onInitialization();

    // Draw
    glutDisplayFunc(onDisplay);

    // Input
    //glutKeyboardFunc(keyPressed);
    //glutKeyboardUpFunc(keyReleased);

    // Loop
    glutMainLoop();

    return 0;
}
