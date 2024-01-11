#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>


#include "input.h"
#include "render.h"
#include "settings.h"
#include "load.h"

void onInitialization()
{
    glClearColor(1, 1, 1, 0);

    // Add here later the memory stacks initialization of the rendered objects

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 300);
}

void onDisplay(void)
{
    loadArquive("arquive.txt");
    double matrix[9];
    matrix[0] = 433.0/500.0;
    matrix[1] = -1.0/2.0;
    matrix[2] = 253.0/125.0;
    matrix[3] = 1.0/2.0;
    matrix[4] = 433.0/500.0;
    matrix[5] = -133.0/150.0;
    matrix[6] = 0.0;
    matrix[7] = 0.0;
    matrix[8] = 1.0;


    keyOperations(); // Perform configured tasks for each key
    keySpecialOperations();
    glClear(GL_COLOR_BUFFER_BIT);

    // Run render fuctions for each object
    glColor3f(1.0, 0.0, 0.0);
    /*glColor3f(1.0, 0.0, 0.0);

    polygon *p = createPolygon();
    polygonPush(p, createPointXY(50, 50));
    polygonPush(p, createPointXY(200, 50));
    polygonPush(p, createPointXY(200, 10));

    printf("%d\n", polygonLength(p));
    renderLines(p);*/
    glPointSize(10);
    Point *p = createPointXY(50,50);
    //renderPoint(p);
    //renderPointTransformation(p, matrix);
    glBegin(GL_POINTS);
        glVertex2i(50, 50);
    glEnd();

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
