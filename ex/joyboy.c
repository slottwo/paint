#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGH 768
#define W 400
#define H 400

#define PI 3.141592653589793

void drawCircle(double r, double x, double y)
{
    glBegin(GL_POLYGON);
    for (float i = 0; i < 2 * PI; i += 0.001)
    {
        glVertex2f(x + r * sin(i), y + r * cos(i));
    }
    glEnd();
}

void readPoints()
{
    FILE *file;

    file = fopen("ex/joyboy", "r");

    if (file == NULL)
    {
        printf("Erro: fopen falho\n");
        exit(EXIT_FAILURE);
    }

    // char prefix[][10] = {
    //     "Move",
    //     "Line",
    //     "Close",
    //     "CubicBezier"};

    char format[][40] = {
        "Move {{%lf, %lf}, {%lf, %lf}}\n",
        "Line {{%lf, %lf" // }, {%lf, %lf}}\n",
        "Close {{%lf, %lf}, {%lf, %lf}}\n",
        "CubicBezier {{%lf, %lf}, {%lf, %lf}}\n"};

    int k = 0;
    double v[1000][2];

    char data[50];
    fgets(data, sizeof(data), file);
    while (data != NULL)
    {
        if (strcmp(data, "PASS\n") == 0)
        {
            do
            {
                fgets(data, sizeof(data), file);
            } while (strcmp(data, "\n") != 0);

            fgets(data, sizeof(data), file); // Skip "\n"
        }

        // glBegin(GL_LINES);

        // fgets(data, sizeof(data), file); // Skip "Move"

        while (strcmp(data, "\n") != 0)
        {

            // for (int i = 0; i < 4; i++)
            // {
            //     if (strncmp(data, prefix[i], strlen(prefix[i]) - 1) == 0)
            //         {
            //             sscanf(data, format[i], &v[k][0], &v[k][1], &v[k][2], &v[k][3]);
            //             k++;
            //             break;
            //         }
            // }
            // if (i == 4)
            // {
            //     printf("Error: bad formatting\n");
            //     exit(1);
            // }

            if (strncmp(data, "Line", 4) == 0) // Skip "Move" | "Close"
            {
                sscanf(data, format[1], &v[k][0], &v[k][1]);
                k++;
            }

            fgets(data, sizeof(data), file); // Next line

            // glVertex2fv(v[k]);
        }

        // glEnd();

        // fgets(data, sizeof(data), file); // Skip "Close"

        fgets(data, sizeof(data), file); // Skip "\n"
    }

    fclose(file);
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

    // Sky

    glBegin(GL_POLYGON);

    RGB(19, 24, 98, color);
    glColor3fv(color);

    glVertex2d(0, 1);
    glVertex2d(1, 1);

    RGB(46, 68, 130, color);
    glColor3fv(color);

    glVertex2d(1, 0);
    glVertex2d(0, 0);

    glEnd();

    // Moon

    RGB(245, 243, 206, color);
    glColor3fv(color);
    drawCircle(0.45, 0.5, 0.5);

    // Nika
    
    glColor3f(0, 0, 0);
    // drawJoyboy();

    // glBegin(GL_LINE_STRIP);

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
    glutCreateWindow("JOYBOY HAS RETURNED!");

    // readPoints();

    // Drawing presets
    onInitialization();

    // Draw
    glutDisplayFunc(onDisplay);

    // Loop
    glutMainLoop();

    return 0;
}
