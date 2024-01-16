#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "input.h"
#include "events.h"
#include "../settings.h"
#include "../types/data.h"

void keyPressed(unsigned char key, int x, int y)
{
    switch (key)
    {
    case KEY_ENTER:
        if (CURRENT_EVENT == EVENT_CREATE)
        {
            createOperation(0,0);
        }
        
        break;

    default:
        break;
    }
}

void keyReleased(unsigned char key, int x, int y)
{
}

void keySpecialPressed(int key, int x, int y)
{
}

void keySpecialReleased(int key, int x, int y)
{
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
        createOperation(OP_CLICK, x, y);
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
