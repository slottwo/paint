#include "input.h"
#include "../settings.h"

#include <stdio.h>

int KEYS[256] = {0};

void keyPressed(unsigned char key, int x, int y)
{
    KEYS[key] = 1;

    // printf("%d, %d\n", x, y);

    y = W - y;
}

void keyReleased(unsigned char key, int x, int y)
{
    KEYS[key] = 0;

    y = W - y;
}

void keyOperations()
{
}

void keySpecialPressed(int key, int x, int y)
{
    y = W - y;
}

void keySpecialReleased(int key, int x, int y)
{
    y = W - y;
}

void keySpecialOperations()
{
}

void onMouseClick(int, int, int, int)
{
}
