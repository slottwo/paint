#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "input.h"
#include "events.h"
#include "../settings.h"
#include "../types/data.h"

double CANVAS_SIZE[4] = {ORTHO_SIZE};

void keyPressed(unsigned char key, int x, int y)
{
    switch (key)
    {
    case KEY_ENTER:
        switch (EVENT)
        {
        case EVENT_CREATE:
            createEvent(OP_DONE, 0, 0);
            break;

        default:
            break;
        }
        break;

    case KEY_ESCAPE:
        switch (EVENT)
        {
        case EVENT_SELECT:
            selectEvent(OP_ESC, 0, 0);
            break;

        case EVENT_CREATE:
            createEvent(OP_ESC, 0, 0);
            break;

        case EVENT_MOVE:
            moveEvent(OP_ESC, 0, 0);
            break;

        case EVENT_ROTATE:
            createEvent(OP_ESC, 0, 0);
            break;

        case EVENT_SCALE:
            createEvent(OP_ESC, 0, 0);
            break;

        default:
            break;
        }
        break;

    case 'p': // point creation tool
        if (EVENT == EVENT_SELECT)
        {
            SELECTED.type = point_type;
            createEvent(OP_INIT, 0, 0);
        }
        break;

    case 'l': // line creation tool
        if (EVENT == EVENT_SELECT)
        {
            SELECTED.type = line_type;
            createEvent(OP_INIT, 0, 0);
        }
        break;

    case 'o': // polygon creation tool / open file
        if (EVENT == EVENT_SELECT)
        {
            SELECTED.type = polygon_type;
            createEvent(OP_INIT, 0, 0);
        }
        break;

    case 'm': // move tool
        break;

    case 'r': // rotate tool
        break;

    case 's': // scale tool / save file
        break;

    case 'z': // redo
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
    switch (key)
    {
    case GLUT_KEY_DELETE:
        switch (EVENT)
        {
        case EVENT_SELECT:
            deleteEvent(OP_DONE);
            break;

        case EVENT_CREATE:
            createEvent(OP_ESC, 0, 0);
            break;

        default:
            break;
        }
    }
}

void keySpecialReleased(int key, int x, int y)
{
}

void onMouseClick(int button, int state, int x, int y)
{
    double ortho_x = CANVAS_SIZE[1] * x / W;
    double ortho_y = CANVAS_SIZE[3] * (H - y) / H;

    switch (EVENT)
    {
    case EVENT_SELECT:
        selectEvent(OP_CLICK, x, y);
        break;

    case EVENT_CREATE:
        createEvent(OP_CLICK, x, y);
        break;

    case EVENT_MOVE:
        moveEvent(OP_CLICK, x, y);
        break;

    case EVENT_ROTATE:
        rotateEvent(OP_CLICK, x, y);
        break;

    case EVENT_SCALE:
        scaleEvent(OP_CLICK, x, y);
        break;

    default:
        break;
    }
}
