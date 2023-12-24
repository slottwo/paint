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
    // if (KEYS['a'])
    // {
    //     /* code */
    // }
}

// if necessary, create private functions for a specific key
