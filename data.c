#include "data.h"
#include "stdlib.h"

Point *selected_point = NULL;
Line *selected_line = NULL;
polygon *selected_polygon = NULL;

Point *all_points[1000] = {NULL};
Line *all_lines[1000] = {NULL};
polygon *all_polygons[1000] = {NULL};
polygon *all_line_strips[1000] = {NULL};

