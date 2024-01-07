#include "input.h"

int KEYS[256] = {0};

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
}

void keySpecialPressed(int key_code, int x, int y)
{
}

void keySpecialReleased(int key_code, int x, int y)
{
}

void keySpecialOperations()
{
}

void onMouseClick(int, int, int, int)
{
}
