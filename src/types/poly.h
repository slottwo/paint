#ifndef POLYGON_H
#define POLYGON_H

#include "node.h"

typedef struct
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
