typedef struct point
{
    double x;
    double y;
    // int is_colored;
    // double colors[3];
} Point;

Point *createPoint(double *);        // , double *);
Point *createPointv(double, double); // , double *);
void freePoint(Point *);
