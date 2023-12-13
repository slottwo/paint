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
    glClear(GL_COLOR_BUFFER_BIT);

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

    return 0;
}
