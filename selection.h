#ifndef SELECTION_H
#define SELECTION_H

#include "point.h"
#include "line.h"
#include "data.h"

int checkPoint(double, double, int, int, int);
Point *selectPoint(int, int, int);

int checkLine(Line *, int, int, int);
int checkLineAfterNonTrivial(double, double, double, double, int, int, int);
Line *selectLine(int, int, int);

int checkEdgePolygonNoNTrivialCases(Point *, Point *, int, int);
int checkEdgePolygonSpecialCase(Point *, Point *, int, int);
int checkEdgePolygonCases(Point *, Point *, int, int);
int checkPolygon(polygon *, int, int);
polygon *selectPolygon(int, int);

#endif
