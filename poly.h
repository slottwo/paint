#ifndef POLY_H
#define POLY_H

#include "point.h"
#include "node.h"

typedef struct Poly
{
    NodePoint *head;
} Poly;

Poly *createPoly();
Poly *createFPoly(double **, int);

int polyPush(Poly *, Point *);
Point *polygonPop(Poly *);

int polyIsEmpty(Poly *);
int polyLength(Poly *);

void freePoly(Poly *);

#endif
