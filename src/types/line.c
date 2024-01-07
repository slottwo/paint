#include "line.h"
#include <stdlib.h>

Line *createLine()
{
    Line *new_line = (Line *)malloc(sizeof(Line));
    if (new_line == NULL)
    {
        exit(1);
    }

    new_line->start = NULL;
    new_line->end = NULL;

    return new_line;
}

Line *createLineP(Point *start, Point*end)
{
    Line *new_line = createLine();

    new_line->start = start;
    new_line->end = end;

    return new_line;
}

Line *createLineV(double **coords)
{
    Line *new_line = createLine();

    new_line->start = createPointV(coords[0]);
    new_line->end = createPointV(coords[1]);

    return new_line;
}

int setLineStart(Line *line, double x, double y)
{
    if (line == NULL)
        return 0;

    if (line->start == NULL)
    {
        line->start = createPointXY(x, y);
        return 1;
    }

    line->start->x = x;
    line->start->y = y;

    return 1;
}

int setLineEnd(Line *line, double x, double y)
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

    if (line->start != NULL)
    {
        freePoint(line->start);
    }

    if (line->end != NULL)
    {
        freePoint(line->end);
    }

    free(line);
    line = NULL;
}
