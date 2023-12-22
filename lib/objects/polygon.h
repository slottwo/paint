#include "point.h"

typedef struct node
{
    Point *vertex;
    struct node *next;
} Node;

typedef struct polygon
{
    Node *head;
} Polygon;

Point *createPoint(double, double);

Polygon *createFPolygon(double **, int);

int polygonPush(Polygon *, Point *);

Point *polygonPop(Polygon *);

int polygonIsEmpty(Polygon *);

void freePolygon(Polygon *);

