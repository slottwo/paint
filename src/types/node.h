#ifndef NODE_H
#define NODE_H

#include "line.h"
#include "point.h"
#include "poly.h"

typedef struct NodePoint
{
    // int id;
    Point *obj;
    struct NodePoint *prior;
    struct NodePoint *next;
} NodePoint;

typedef struct NodeLine
{
    // int id;
    Line *obj;
    struct NodeLine *prior;
    struct NodeLine *next;
} NodeLine;

typedef struct NodePoly
{
    // int id;
    Poly *obj;
    struct NodePoly *prior;
    struct NodePoly *next;
} NodePoly;

NodePoint *createNodePoint(Point *);
NodeLine *createNodeLine(Line *);
NodePoly *createNodePoly(Poly *);

#endif
