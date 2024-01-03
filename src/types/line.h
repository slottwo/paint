#ifndef LINE_H
#define LINE_H

#include "point.h"

typedef struct
{
    Point *begin;
    Point *end;
} Line;

Line *createLine();
Line *createFLine(double *);
int setBeginLine(double, double);
int setEndLine(double, double);
void freeLine(Line *);

#endif
