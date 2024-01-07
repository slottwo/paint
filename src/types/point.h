#ifndef POINT_H
#define POINT_H

typedef struct Point
{
    double x;
    double y;
} Point;

Point *createPointV(double *);
Point *createPointXY(double, double);

double *getV(Point *Point);

void freePoint(Point *);

#endif
