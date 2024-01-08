#ifndef LINE_H
#define LINE_H

#include "point.h"

typedef struct Line
{
    Point *start;
    Point *end;
} Line;

Line *createLineP(Point *, Point *);
Line *createLineV(double **);

int setLineStart(Line *, double, double);
int setLineEnd(Line *, double, double);

void freeLine(Line *);

#endif
