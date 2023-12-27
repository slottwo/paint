#ifndef DATA_H
#define DATA_H

#include "line.h"
#include "polygon.h"

extern Point *selected_point;
extern Line *selected_line;
extern polygon *selected_polygon;

extern Point *all_points[1000];
extern Line *all_lines[1000];
extern polygon *all_polygons[1000];
extern polygon *all_line_strips[1000];

#endif
