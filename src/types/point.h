#ifndef POINT_H
#define POINT_H

typedef struct Point
{
    double x;
    double y;
    // int is_colored;
    // double colors[3];
} Point;

Point *createPointV(double *);
Point *createPointXY(double, double);

int pointCompare(Point *, double, double);

double *getV(Point *);

void freePoint(Point *);

#endif
