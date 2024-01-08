#ifndef RENDER_H
#define RENDER_H

#include "point.h"
#include "line.h"
#include "poly.h"

int renderPoint(Point *);
int renderLine(Line *);
int renderPolyline(Poly *);
int renderPolygon(Poly *);

// int renderPoints(NodePoint *);
// int renderLines(NodeLine *);
// int renderPolylines(NodePoly *);
// int renderPolygons(NodePoly *);

int renderData();

#endif
