#ifndef DATA_H
#define DATA_H

#include "line.h"
#include "polygon.h"

extern Point *all_points[1000];
extern Line *all_lines[1000];
extern Polygon *all_polygons[1000];
extern Polygon *all_line_strips[1000];
extern Point *selected_point;
extern Line *selected_point;
extern Polygon *selected_point;

#endif
