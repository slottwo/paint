#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "input.h"
#include "events.h"
#include "../settings.h"
#include "../types/data.h"

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
    if (KEYS['p']) // _P_OINT
    {
        if (CURRENT_EVENT != EVENT_CREATE)
        {
            CURRENT_EVENT = EVENT_CREATE;
            
            SELECTED.type = point_type;
        }
    }
    else if (KEYS['l']) // _L_INE
    {
        if (CURRENT_EVENT != EVENT_CREATE)
        {
            CURRENT_EVENT = EVENT_CREATE;
            
            SELECTED.type = point_type;
        }
    }
    else if (KEYS['o']) // P_O_LYGON
    {
        /* code */
    }
    if (KEYS[13]) // Enter
    {
        printf("Enter\n");
    }
}

void keySpecialPressed(int key, int x, int y)
{
    SP_KEYS[key] = 1;
}

void keySpecialReleased(int key, int x, int y)
{
    SP_KEYS[key] = 0;
}
 
void keySpecialOperations()
{
    if (SP_KEYS[CUSTOM_KEY_ESC])
    {
        if (CURRENT_EVENT != EVENT_SELECT)
        {

        }
    }
}

void onMouseClick(int button, int state, int x, int y)
{
    y = W - y;

    switch (CURRENT_EVENT)
    {
    case EVENT_SELECT:
        selectOperation(x, y);
        break;

    case EVENT_CREATE:
        createOperation(x, y);
        break;

    case EVENT_MOVE:
        moveOperation(x, y);
        break;

    case EVENT_ROTATE:
        rotateOperation(x, y);
        break;

    case EVENT_SCALE:
        scaleOperation(x, y);
        break;

    default:
        break;
    }
}
