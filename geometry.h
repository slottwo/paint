#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "poly.h"

double distanceBetweenTwoPoints(double, double, double, double);

double *centerPolygon(Poly *);
double anglePoly(double, double, double, double, Poly *);

double *centerLine(Line *);

#endif
