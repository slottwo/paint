#include <GL/glut.h>
#include <stdio.h>

#include "input.h"
#include "render.h"

int KEYS[256] = {0};
int SP_KEYS[256] = {0};

void keyPressed(unsigned char key, int x, int y)
{
    KEYS[key] = 1;
}

void keyReleased(unsigned char key, int x, int y)
{
    KEYS[key] = 0;
}

void keyOperations()
{
    if (KEYS['a'])
    {
        printf("a pressionado!");
    }
}

void keySpecialPressed(int key, int x, int y)
{
}

void keySpecialReleased(int key, int x, int y)
{
}

void keySpecialOperations(void)
{
}

void onMouseClick(int button, int state, int x, int y)
{
}
