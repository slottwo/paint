#include <GL/glut.h>
#include <math.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGH 768
#define W 150
#define H 100
#define SIZE_RATIO 4

void init()
{
    glClearColor(0, 0, 0, 0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, W, 0, H);
}

void display()
{
    int h = 25 * sqrt(3); // 15 + 50 * sin(pi/3)

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    glColor3f(1, 0, 0);
    glVertex2f(25, (H - h) / 2);
    glColor3f(0, 1, 0);
    glVertex2f(75, (H - h) / 2);
    glColor3f(0, 0, 1);
    glVertex2f(50, (H + h) / 2);

    glEnd();

    glFlush();
}

int main(int argc, char const *argv[])
{

    // GLUT Config
    glutInit(&argc, (char **)argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(
        (SCREEN_WIDTH - W * SIZE_RATIO) / 2,
        (SCREEN_HEIGH - H * SIZE_RATIO) / 2);
    glutInitWindowSize(W * SIZE_RATIO, H * SIZE_RATIO);
    glutCreateWindow("Program");

    // Drawing presets
    init();

    // Draw
    glutDisplayFunc(display);
    // Loop
    glutMainLoop();

    // End
    return 0;
}
