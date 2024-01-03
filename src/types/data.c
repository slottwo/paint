#include "data.h"
#include "stdlib.h"

Point *CURRENT_POINT = NULL;
Line *CURRENT_LINE = NULL;
Polygon *CURRENT_POLYGON = NULL;

Point *POINTS[1000] = {NULL};
Line *LINES[1000] = {NULL};
Polygon *POLYGONS[1000] = {NULL};
Polygon *LINE_STRIPS[1000] = {NULL};
