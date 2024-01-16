#include "input.h"
#include "../settings.h"

enum events CURRENT_EVENT = EVENT_SELECT;

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
}

void keySpecialPressed(int key, int x, int y)
{
}

void keySpecialReleased(int key, int x, int y)
{
}

void keySpecialOperations()
{
}

void onMouseClick(int button, int state, int x, int y)
{
}
