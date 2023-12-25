#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"

typedef struct node
{
    Point *vertex;
    struct node *next;
} Node;

typedef struct
{
    Node *head;
} Polygon;

Polygon *createPolygon();

Polygon *createFPolygon(double **, int);

int polygonPush(Polygon *, Point *);

Point *polygonPop(Polygon *);

int polygonIsEmpty(Polygon *);

int polygonLength(Polygon *);

void freePolygon(Polygon *);

void freeNode(Node *);

#endif