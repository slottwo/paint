#ifndef POINT_H
#define POINT_H

typedef struct
{
    double x;
    double y;
    // int is_colored;
    // double colors[3];
} Point;

Point *createPointV(double *);
Point *createPointXY(double, double);

double *getV(Point *Point);

void freePoint(Point *);

#endif
