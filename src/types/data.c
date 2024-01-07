#include <stdlib.h>
#include "data.h"

struct data DATA = {NULL, NULL, NULL, NULL};

struct current_node SELECTED = {NULL, NULL, NULL, NULL};

int pointDataPush(Point *point)
{
    if (point == NULL)
    {
        /* code */
        return 0;
    }

    NodePoint *new_node = createNodePoint(point);
    if (new_node == NULL)
    {
        /* code */
        return 0;
    }

    if (DATA.point_head == NULL)
    {
        DATA.point_head = new_node;
        return 1;
    }

    
}

int pointDataRemove(NodePoint *);

int lineDataPush(Line *);
int lineDataRemove(NodeLine *);

int polygonDataPush(Poly *);
int polygonDataRemove(NodePoly *);

int polylineDataPush(Poly *);
int polylineDataRemove(NodePoly *);