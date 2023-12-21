typedef double *Point;
typedef Point *Line;

typedef struct node
{
    Point *vertex;
    struct node *next;
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
