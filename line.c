#include "line.h"
#include <stdlib.h>

Line *createLine()
{
    Line *line = (Line *)malloc(sizeof(Line));
    if (line == NULL)
    {
        exit(1);
    }

    line->begin = NULL;
    line->end = NULL;

    return line;
}

Line *createFLine(double **coords)
{
    Line *line = createLine();

    line->begin = createPoint(coords[0]);
    line->end = createPoint(coords[1]);

    return line;
}

int setBeginLine(Line *line, double x, double y)
{
    if (line == NULL)
        return 0;

    if (line->begin == NULL)
    {
        line->begin = createPointXY(x, y);
        return 1;
    }

    line->begin->x = x;
    line->begin->y = y;

    return 1;
}

int setEndLine(Line *line, double x, double y)
{
    if (line == NULL)
        return 0;

    if (line->end == NULL)
    {
        line->end = createPointXY(x, y);
        return 1;
    }

    line->end->x = x;
    line->end->y = y;

    return 1;
}

void freeLine(Line *line)
{
    if (line == NULL)
        return;

    if (line->begin != NULL)
    {
        freePoint(line->begin);
    }

    if (line->end != NULL)
    {
        freePoint(line->end);
    }

    free(line);
    line = NULL;
}

