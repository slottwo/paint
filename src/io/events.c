#include "events.h"
#include "selection.h"
#include "../types/data.h"
#include "../types/point.h"

#include <stdio.h>

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
        if (SELECTED.type == polygon_type)
        {
            polylineDataPush(createPoly());
        }
        else if (SELECTED.type == none_type || SELECTED.type > 4)
        {
            printf("Creation Tool Error: No object type selected\n");
            return 1;
        }
        break;

    case OP_CLICK:
        switch (SELECTED.type)
        {
        case point_type:
            pointDataPush(createPointXY(x, y));
            break;

        case line_type:
            if (SELECTED.line->obj->start)
            {
                if (pointCompare(SELECTED.line->obj->start, x, y))
                {
                    printf("Line Creation Tool Error: End point coincides with beginning\n");
                    break;
                }
                else
                {
                    setLineEnd(SELECTED.line->obj, x, y);
                    createEvent(OP_DONE, 0, 0); // remove rendered starter point
                }
            }
            else
            {
                setLineStart(SELECTED.line->obj, x, y);
                pointDataPush(createPointXY(x, y)); // render starter point :D
                SELECTED.type = line_type;
            }
            break;

        case polyline_type:

            polyPush(SELECTED.polygon->obj, createPointXY(x, y));
            break;

        default:
            printf("Creation Tool Error: No object type selected\n");
            return 1;
            break;
        }

    case OP_DONE:
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

    return 0;
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
