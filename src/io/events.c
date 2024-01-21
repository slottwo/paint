#include <stdlib.h>
#include <stdio.h>

#include "events.h"
// #include "selection.h"
#include "../types/data.h"
#include "../types/point.h"

enum events EVENT = EVENT_SELECT;

int selectEvent(int OP, double x, double y)
{
}

int createEvent(int OP, double x, double y)
{
    switch (OP)
    {
    case OP_ESC:
        switch (SELECTED.type)
        {
        case point_type:
            /* code */
            break;

        case line_type:
            /* code */
            break;

        case polyline_type:
            /* code */
            break;

        case polygon_type:
            /* code */
            break;

        default:
            break;
        }
        break;

    case OP_INIT:
        EVENT = EVENT_CREATE;

        printf("Init creating tool. Type: %d\n", SELECTED.type);

        switch (SELECTED.type)
        {
        case point_type:
            break;

        case line_type:
            SELECTED.line = NULL;
            break;

        case polygon_type:
            polylineDataPush(createPoly());
            break;

        default:
            printf("Creation Tool Error: No object type selected\n");
            return 0;
            break;
        }

        break;

    case OP_CLICK:
        printf("Creation tool clicking. Type: %d\n", SELECTED.type);

        switch (SELECTED.type)
        {
        case point_type:
            if (pointDataPush(createPointXY(x, y)) == 0)
            {
                printf("Point Creation Tool Error: Point not pushed\n");
                return 0;
            }
            break;

        case line_type:
            if (SELECTED.line == NULL)
            {
                printf("Line start at (%.2f, %.2f)\n", x, y);

                if (pointDataPush(createPointXY(x, y)) == 0) // Line start preview
                {
                    printf("Line Creation Tool Error: Point line view not pushed on DATA\n");
                    return 0;
                }
                if (lineDataPush(createLine()) == 0)
                {
                    printf("Line Creation Tool Error: Line not pushed on DATA\n");
                    return 0;
                }
                else if (setLineStart(SELECTED.line->obj, x, y) == 0)
                {
                    printf("Line Creation Tool Error: Line start setting\n");
                    return 0;
                }
            }
            else
            {
                printf("Line end at (%.2f, %.2f)\n", x, y);

                if (pointCompare(SELECTED.line->obj->start, x, y))
                {
                    printf("Line Creation Tool Error: Line ends coincides\n");
                    return 1;
                }
                else
                {
                    if (setLineEnd(SELECTED.line->obj, x, y) == 0)
                    {
                        printf("Line Creation Tool Error: Line end setting\n");
                        return 0;
                    }

                    pointDataRemove(SELECTED.point); // Rm line start preview
                    SELECTED.type = line_type;
                    SELECTED.line = NULL;
                }
            }
            break;

        case polyline_type:

            polyPush(SELECTED.polygon->obj, createPointXY(x, y));
            break;

        default:
            printf("Creation Tool Error: No object type selected\n");
            return 0;
            break;
        }

    case OP_DONE:
        switch (SELECTED.type)
        {
        case point_type:
            SELECTED.type = none_type;
            SELECTED.point = NULL;
            break;

        case line_type:
            /* code */
            break;

        case polyline_type:
            /* code */
            break;

        case polygon_type:
            /* code */
            break;

        default:
            break;
        }
        break;

    case OP_REDO:
        switch (SELECTED.type)
        {
        case point_type:
            /* code */
            break;

        case line_type:
            /* code */
            break;

        case polyline_type:
            /* code */
            break;

        case polygon_type:
            /* code */
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }

    return 1;
}

int moveEvent(int OP, double x, double y)
{
}

int rotateEvent(int OP, double x, double y)
{
}

int scaleEvent(int OP, double x, double y)
{
}

int deleteEvent(int OP)
{
    if (OP == OP_DONE)
    {
        switch (SELECTED.type)
        {
        case none_type:
            return 0;
            break;

        case point_type:
            pointDataRemove(SELECTED.point);
            break;

        case line_type:
            pointDataRemove(SELECTED.point);
            break;

        case polyline_type:
            pointDataRemove(SELECTED.point);
            break;

        case polygon_type:
            pointDataRemove(SELECTED.point);
            break;

        default:
            break;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}
