typedef double *Point;
typedef Point *Line;

typedef struct
{
    Point *vertex;
    Node *next;
} Node;

typedef struct
{
    Node *head;
} Polygon;

Point *createPoint(double, double);
Line *createLine(double **);
Polygon *createPolygon();
Polygon *createFPolygon(double **, int);
void pushPoint(Polygon *, Point *);
Point *popPoint(Polygon *);
void freePolygon(Polygon *);
