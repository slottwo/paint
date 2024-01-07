#ifndef NODE_H
#define NODE_H

#include "point.h"
#include "line.h"

typedef struct Poly Poly; // Forward declaration

typedef struct NodePoint
{
    Point *obj;
    struct NodePoint *prior;
    struct NodePoint *next;
} NodePoint;

typedef struct NodeLine
{
    Line *obj;
    struct NodeLine *prior;
    struct NodeLine *next;
} NodeLine;

typedef struct NodePoly
{
    Poly *obj;
    struct NodePoly *prior;
    struct NodePoly *next;
} NodePoly;

NodePoint *createNodePoint(Point *);
NodeLine *createNodeLine(Line *);
NodePoly *createNodePoly(Poly *);

#include "poly.h"

#endif
