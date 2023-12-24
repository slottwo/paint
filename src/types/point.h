#ifndef POINT_H
#define POINT_H

typedef struct
{
    double x;
    double y;
    // int is_colored;
    // double colors[3];
} Point;

Point *createPoint(double *);         // , double *);
Point *createPointXY(double, double); // , double *);
double *getV(Point *point);
void freePoint(Point *);

#endif
