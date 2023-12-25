#ifndef polygon_H
#define polygon_H

#include "point.h"

typedef struct node
{
    Point *vertex;
    struct node *next;
} Node;

typedef struct
{
    Node *head;
} polygon;

polygon *createPolygon();

polygon *createFPolygon(double **, int);

int polygonPush(polygon *, Point *);

Point *polygonPop(polygon *);

int polygonIsEmpty(polygon *);

int polygonLength(polygon *);

void freepolygon(polygon *);

void freeNode(Node *);

#endif
