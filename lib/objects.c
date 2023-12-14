#include <stdlib.h>
#include "objects.h"

Point *createPoint(float x, float y)
{
    Point *point = (Point *)malloc(sizeof(Point));
    if (point == NULL)
    {
        printf("Error: malloc fail");
        exit(1);
    }
    point[0] = x;
    point[0] = y;
    return point;
}

// Line *createLine(float v[2][2])
// {
//     Line *line = (Line *)malloc(sizeof(Line));
//     if (line == NULL)
//     {
//         printf("Error: malloc fail");
//         exit(1);
//     }
//     line->vertexes[0] = createPoint(v[0][0], v[0][1]);
//     line->vertexes[1] = createPoint(v[1][0], v[1][1]);
//     return line;
// }

Polygon *createPolygon(float **, int)
{
    Polygon *polygon = (Polygon *)malloc(sizeof(Polygon));
    if (polygon == NULL)
    {
        printf("Error: malloc fail");
        exit(1);
    }

    return polygon;
}

void appendPoint(Polygon *, Point *)
{
    if (polygon == NULL |
}

void freePolygon(Polygon *);
