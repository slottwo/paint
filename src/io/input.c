#include <GL/glut.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "input.h"
#include "events.h"
#include "render.h"
#include "file/load.h"
#include "file/save.h"
#include "../settings.h"
#include "../types/data.h"

void keyPressed(unsigned char key, int x, int y)
{
    switch (key)
    {
    case KEY_BACKSPACE: // Redo
        switch (EVENT)
        {
        case EVENT_SELECT:
            selectEvent(OP_ESC, 0, 0);
            break;

        case EVENT_CREATE:
            switch (SELECTED.type)
            {
            case point_type:
                SELECTED.point = DATA.point_head;
                deleteEvent(OP_DONE);
                SELECTED.type = point_type;
                createEvent(OP_INIT, 0, 0);
                break;

            case polyline_type:
                if (SELECTED.polyline != NULL)
                {
                    Point *point = polyPop(SELECTED.polyline->obj);
                    if (point)
                    {
                        freePoint(point);
                    }
                }
                break;

            default:
                break;
            }
        default:
            break;
        }
        break;

    case KEY_ENTER:
        switch (EVENT)
        {
        case EVENT_CREATE:
            printf("Creation Tool. OP: DONE. Type: %d\n", SELECTED.type);
            if (createEvent(OP_DONE, 0, 0) == 0)
            {
                printf("Creation Tool Error: Returned 0\n");
                exit(1);
            }
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
            rotateEvent(OP_ESC, 0, 0);
            break;

        case EVENT_SCALE:
            scaleEvent(OP_ESC, 0, 0);
            break;

        default:
            break;
        }
        break;

    case KEY_DELETE:
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
        break;

    case 'p': // Point Creation Tool
        if (EVENT == EVENT_SELECT || EVENT == EVENT_CREATE)
        {
            printf("Point Creation Tool pre-setup\n");

            if (EVENT == EVENT_CREATE)
            {
                printf("Quit previous Creation Tool\n");
                createEvent(OP_ESC, 0, 0);
            }

            SELECTED.type = point_type;

            if (createEvent(OP_INIT, 0, 0) == 0)
            {
                printf("Point Creation Tool Error: Returned 0\n");
                exit(1);
            }
        }
        break;

    case 'l': // Line Creation Tool
        if (EVENT == EVENT_SELECT || EVENT == EVENT_CREATE)
        {
            printf("Line Creation Tool pre-setup\n");

            if (EVENT == EVENT_CREATE)
            {
                printf("Quit previous Creation Tool\n");
                createEvent(OP_ESC, 0, 0);
            }

            SELECTED.type = line_type;

            if (createEvent(OP_INIT, 0, 0) == 0)
            {
                printf("Line Creation Tool Error: Returned 0\n");
                exit(1);
            }
        }
        break;

    case 'o': // polygon Creation Tool
        if (EVENT == EVENT_SELECT || EVENT == EVENT_CREATE)
        {
            printf("Polygon Creation Tool pre-setup\n");

            if (EVENT == EVENT_CREATE)
            {
                printf("Quit previous Creation Tool\n");
                createEvent(OP_ESC, 0, 0);
            }

            SELECTED.type = polygon_type;
            if (createEvent(OP_INIT, 0, 0) == 0)
            {
                printf("Polygon Creation Tool Error: Returned 0\n");
                exit(1);
            }
        }
        break;

    case 'm': // Move Tool
        break;

    case 'r': // Rotate Tool
        break;

    case 'a': // Load Tool
        if (EVENT == EVENT_SELECT)
        {
            loadPainting(NULL);
            EVENT = EVENT_SELECT;
            selectEvent(OP_ESC, 0, 0);
        }
        break;

    case 's': // Scale Tool
        break;

    default:
        break;
    }

    glutPostRedisplay();
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
    double ortho_x = CANVAS_SIZE[1] * x / W;
    double ortho_y = CANVAS_SIZE[3] * (H - y) / H;

    if (state == GLUT_DOWN)
    {
        printf("Click (%.2f, %.2f). Event: %d\n", ortho_x, ortho_y, EVENT);

        switch (EVENT)
        {
        case EVENT_SELECT:
            selectEvent(OP_CLICK, ortho_x, ortho_y);
            break;

        case EVENT_CREATE:
            createEvent(OP_CLICK, ortho_x, ortho_y);
            break;

        case EVENT_MOVE:
            moveEvent(OP_CLICK, ortho_x, ortho_y);
            break;

        case EVENT_ROTATE:
            rotateEvent(OP_CLICK, ortho_x, ortho_y);
            break;

        case EVENT_SCALE:
            scaleEvent(OP_CLICK, ortho_x, ortho_y);
            break;

        default:
            break;
        }

        glutPostRedisplay();
    } /*
    else if (EVENT == EVENT_CREATE)
    {
        createEvent(OP_CLICK, ortho_x, ortho_y);
        glutPostRedisplay();
    } */
}
