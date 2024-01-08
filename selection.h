#ifndef SELECTION_H
#define SELECTION_H

#include "point.h"
#include "line.h"
#include "data.h"

int checkPoint(Point *, double, double, double);
NodePoint *selectPoint(double, double, double);

int checkLine(Line *, double, double, double);
int checkLineAfterNonTrivial(Line *, double, double, double);
NodeLine *selectLine(double, double, double);

int checkEdgePolygonNoNTrivialCases(Point *, Point *, double, double);
int checkEdgePolygonSpecialCase(Point *, Point *, double, double);
int checkEdgePolygonCases(Point *, Point *, double, double);
int checkPoly(Poly *, double, double);
Poly *selectPolygon(double, double);

#endif
