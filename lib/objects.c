#include <stdlib.h>
#include "objects.h"

Point *createPoint(float x, float y)
{
    Point *point = (Point *)malloc(sizeof(Point));
    if (point == NULL)
    {
        printf("Erro: malloc falhou");
        exit(0);
    }
    point->x = x;
    point->y = y;
    return point;
}

Line *createLine(float v[2][2])
{
    Line *line = (Line *)malloc(sizeof(Line));
    if (line == NULL)
    {
        printf("Erro: malloc falhou");
        exit(0);
    }
    line->vertexes[0] = createPoint(v[0][0], v[0][1]);
    line->vertexes[1] = createPoint(v[1][0], v[1][1]);
    return line;
}

Polygon *createPolygon(float **, int)
{
    Polygon *line = (Polygon *)malloc(sizeof(Polygon));
    if (line == NULL)
    {
        printf("Erro: malloc falhou");
        exit(0);
    }
}
