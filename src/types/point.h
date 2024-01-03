#ifndef POINT_H
#define POINT_H

typedef struct
{
    double x;
    double y;
} Point;

Point *createPoint(double *);
Point *createPointXY(double, double);
double *getV(Point *point);
void freePoint(Point *);

#endif
