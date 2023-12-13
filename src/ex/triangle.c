#include <GL/glut.h>
#include <math.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGH 768
#define W 400
#define H 400

void onInitialization()
{
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1, 0, 1);
}

void onDisplay()
{
    float h = sqrt(3) / 4;

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(1, 0, 0);
    glVertex2f(0.25, (1 - h) / 2);
    glColor3f(0, 1, 0);
    glVertex2f(0.75, (1 - h) / 2);
    glColor3f(0, 0, 1);
    glVertex2f(0.5, (1 + h) / 2);

    glEnd();

    glFlush();
}

int main(int argc, char const *argv[])
{

    // GLUT Config
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(
        (SCREEN_WIDTH - W) / 2,
        (SCREEN_HEIGH - H) / 2);
    glutInitWindowSize(W, H);
    glutCreateWindow("Triangle");

    // Drawing presets
    onInitialization();

    // Draw
    glutDisplayFunc(onDisplay);
    // Loop
    glutMainLoop();

    // End
    return 0;
}
