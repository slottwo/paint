#ifndef RENDER_H
#define RENDER_H

#include "../types/point.h"
#include "../types/line.h"
#include "../types/poly.h"

int renderPoint(Point *);
int renderLine(Line *);
int renderLines(Poly *);
int renderPolygon(Poly *);

#endif
