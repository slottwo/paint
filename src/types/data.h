#ifndef DATA_H
#define DATA_H

#include "node.h"

struct data
{
    NodePoint *point_head;
    NodeLine *line_head;
    NodePoly *polyline_head;
    NodePoly *polygon_head;
};

extern struct data DATA;

enum object_type
{
    none_type = 0,
    point_type,
    line_type,
    polyline_type,
    polygon_type
};

struct current_node
{
    int current_type;
    NodePoint *current_point;
    NodeLine *current_line;
    NodePoly *current_polyline;
    NodePoly *current_polygon;
};

extern struct current_node SELECTED;

int pointDataPush(Point *);
int pointDataRemove(NodePoint *);

int lineDataPush(Line *);
int lineDataRemove(NodeLine *);

int polylineDataPush(Poly *);
int polylineDataRemove(NodePoly *);

int polygonDataPush(Poly *);
int polygonDataRemove(NodePoly *);

int pointIsInDATA(NodePoint *);
int lineIsInDATA(NodeLine *);
int polylineIsInDATA(NodePoly *);
int polygonIsInDATA(NodePoly *);

#endif
