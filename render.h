#ifndef RENDER_H
#define RENDER_H

#include "polygon.h"
#include "line.h"

int renderPoint(Point *);
int renderLine(Line *);
int renderLines(polygon *);
int renderPolygon(polygon *);

void renderPointTransformation(Point *, double *);
int renderLineTransformation(Line *, double *);
int renderPolygonTransformation(polygon *, double *);
#endif
