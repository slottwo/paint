#include <stdlib.h>
#include <stdio.h>

#include "events.h"
#include "../types/data.h"
#include "../types/point.h"
#include "../math/selection.h"

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
        case line_type:
            if (SELECTED.line != NULL)
            {
                pointDataRemove(SELECTED.point); // Rm line start preview
                lineDataRemove(SELECTED.line);   // Rm incomplete line
            }
            break;

        case polyline_type:
            if (SELECTED.polyline != NULL)
            {
                polylineDataRemove(SELECTED.polyline, 0);
            }
            break;

        default:
            break;
        }

        SELECTED.type = none_type;
        SELECTED.point = NULL;
        SELECTED.line = NULL;
        SELECTED.polyline = NULL;
        SELECTED.polygon = NULL;

        EVENT = EVENT_SELECT;

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
            printf("Adding a new point to poly (%.2f, %.2f)\n", x, y);
            if (polyPush(SELECTED.polyline->obj, createPointXY(x, y)) == 0)
            {
                printf("Polygon Creation Tool Error: Returned 0\n");
            }
            break;

        default:
            printf("Creation Tool Error: No object type selected\n");
            return 0;
            break;
        }

        break;

    case OP_DONE:

        if (SELECTED.type == polyline_type && SELECTED.polyline != NULL)
        {
            if (polyLength(SELECTED.polyline->obj) < 3)
            {
                printf("Polygon Creation Tool Error: Polygons needs to have at least\n");
                return 1;
            }

            // Turn polyline in a polygon
            if (polygonDataPush(SELECTED.polyline->obj) == 0)
            {
                printf("Polygon Creation Tool Error: Polygon not pushed to DATA\n");
                return 0;
            }

            if (polylineDataRemove(SELECTED.polyline, 1) == 0)
            {
                printf("Polygon Creation Tool Error: Polyline not removed from DATA\n");
                return 0;
            }

            // Setup to create another polygon
            SELECTED.type = polygon_type;
            createEvent(OP_INIT, 0, 0);
        }
        else
        {
            createEvent(OP_ESC, 0, 0);
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
