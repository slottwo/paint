#include "data.h"
#include "stdlib.h"

Point *all_points[1000] = {NULL};
Line *all_lines[1000] = {NULL};
Polygon *all_polygons[1000] = {NULL};
Polygon *all_line_strips[1000] = {NULL};
Point *selected_point = NULL;
Line *selected_point = NULL;
Polygon *selected_point = NULL;