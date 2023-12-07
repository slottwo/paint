#include <GL/glut.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGH 768

void init()
{
    glClearColor(1, 1, 1, 0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 200, 0, 200);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

int main(int argc, char const *argv[])
{
    // GLUT Config
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition((SCREEN_WIDTH - 400) / 2, (SCREEN_HEIGH - 400) / 2);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Program");

    init();

    // Draw
    glutDisplayFunc(display);
    // Loop
    glutMainLoop();

    // End    
    return 0;
}
