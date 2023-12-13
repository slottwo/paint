#include <GL/glut.h>
#include <math.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGH 768
#define W 600
#define H 400

#define PI 3.141592653589793
#define PHI ((1 + sqrt(5)) / 2)
#define BIG_PHI (1 - PHI)

float *draw_star(float r, float x_center, float y_center)
{
    float x[10], y[10];

    int i, k;

    for (i = 0; i < 5; i++)
    {
        x[i * 2] = r * cos(i * 2 * PI / 5 + PI / 2);
        y[i * 2] = r * sin(i * 2 * PI / 5 + PI / 2);
    }

    for (i = 0; i < 5; i++)
    {
        k = ((i + 2) % 5) * 2 + 1;
        x[k] = r * (BIG_PHI / 2) * cos(i * 2 * PI / 5 + PI / 2);
        y[k] = r * (BIG_PHI / 2) * sin(i * 2 * PI / 5 + PI / 2);
    }

    // glBegin(GL_POINTS);

    // for (i = 9; i > -1; i--)
    // {
    //     glColor3f(i/10.0, i/10.0, i/10.0);
    //     glVertex2f(x[i] + x_center, y[i] + y_center);
    // }

    // glEnd();

    glBegin(GL_POLYGON);

    glColor3f(1, 1, 0);
    for (i = 9; i > -1; i--)
    {
        glVertex2f(x[i] + x_center, y[i] + y_center);
    }

    glEnd();
}

void onInitialization()
{
    glClearColor(238.0 / 255, 28.0 / 255, 37.0 / 255, 1); // Chinese Red

    glPointSize(6);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 3, 0, 2);
}

void onDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);

    draw_star(0.3, 0.5, 1.5);
    draw_star(0.1, 1, 1.8);
    draw_star(0.1, 1, 1.1);
    draw_star(0.1, 1.2, 1.6);
    draw_star(0.1, 1.2, 1.3);

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
    glutCreateWindow("Chinese Flag");

    // Drawing presets
    onInitialization();

    // Draw
    glutDisplayFunc(onDisplay);

    // Loop
    glutMainLoop();

    return 0;
}
