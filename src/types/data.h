#ifndef DATA_H
#define DATA_H

#include "node.h"

struct data
{
    NodePoint *point_head;
    NodeLine *line_head;
    NodePoly *polygon_head;
    NodePoly *polyline_head;
};

extern struct data DATA;

struct current_node
{
    NodePoint *current_point;
    NodeLine *current_line;
    NodePoly *current_polygon;
    NodePoly *current_polyline;
};

extern struct current_node SELECTED;

int pointDataPush(Point *);
int pointDataRemove(NodePoint *);

int lineDataPush(Line *);
int lineDataRemove(NodeLine *);

int polygonDataPush(Poly *);
int polygonDataRemove(NodePoly *);

int polylineDataPush(Poly *);
int polylineDataRemove(NodePoly *);

#endif
