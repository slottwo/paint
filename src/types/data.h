#ifndef DATA_H
#define DATA_H

#include "line.h"
#include "polygon.h"

extern Point *CURRENT_POINT;
extern Line *CURRENT_LINE;
extern Polygon *CURRENT_POLYGON;

extern Point *POINTS[1000];
extern Line *LINES[1000];
extern Polygon *POLYGONS[1000];
extern Polygon *LINE_STRIPS[1000];

#endif
