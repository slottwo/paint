#include <GL/glut.h>
#include <math.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGH 768
#define W 400
#define H 400

#define PI 3.141592653589793

void drawCircle(double r, double x, double y)
{

    glBegin(GL_POINTS);
    for (float i = 0; i < 2 * PI; i += 0.001)
    {
        glVertex2f(x + r * sin(i), y + r * cos(i));
    }
    glEnd();
}

void RGB(float r, float g, float b, float *color)
{
    color[0] = r / 255;
    color[1] = g / 255,
    color[2] = b / 255;
}

void onInitialization()
{
    glClearColor(0, 0, 0, 1);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1, 0, 1);
}

void onDisplay()
{
    float *color = (float *)malloc(3 * sizeof(float));

    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);

    RGB(107, 73, 132, color);
    glColor3fv(color);

    glVertex2d(0, 1);
    glVertex2d(1, 1);

    RGB(43, 47, 119, color);
    glColor3fv(color);

    glVertex2d(1, 0);
    glVertex2d(0, 0);

    glEnd();

    RGB(246, 241, 213, color);
    glColor3fv(color);
    drawCircle(0.4, 0.5, 0.5);

    
    // glColor3f(0,0,0);
    drawCircle(0.1, 0.5, 0.7);

    glBegin(GL_LINES);
    glVertex2d(0.5, 0.6);
    glVertex2d(0.4, 0.4);
    glVertex2d(0.3, 0.5);
    glVertex2d(0.4, 0.4);

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

    return 0;
}
