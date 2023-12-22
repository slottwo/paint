#include <stdlib.h>
#include "point.h"

Point *createPoint(double *coords, double *colors)
{
    Point *point = (double *)malloc(sizeof(Point));
    if (point == NULL)
    {
        // printf("Point creation error: malloc fail\n");
        exit(1);
        return NULL;
    }

    point->x = coords[0];
    point->y = coords[1];

    if (colors == NULL)
    {
        point->is_colored = 0;
        point->colors[0] = 0;
        point->colors[1] = 0;
        point->colors[2] = 0;
    }
    else
    {
        point->is_colored = 1;
        point->colors[0] = colors[0];
        point->colors[1] = colors[1];
        point->colors[2] = colors[2];
    }

    return point;
}

void freePoint(Point *point)
{
    if (point == NULL)
    {
        // printf("Point deallocate error: NULL pointer received\n");
        exit(1);
    }

    free(point->colors);
    free(point);

    point = NULL;
}
