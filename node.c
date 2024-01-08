#include <stdlib.h>
#include <stdio.h>

#include "node.h"

NodePoint *createNodePoint(Point *obj)
{
    if (obj == NULL)
    {
        printf("Node Point Creation Error: NULL point received\n");
        exit(1);
        return NULL;
    }

    NodePoint *node = (NodePoint *)malloc(sizeof(NodePoint));
    if (node == NULL)
    {
        printf("Node Point Creation Error: Allocation\n");
        exit(1);
        return NULL;
    }

    node->obj = obj;

    node->prior = NULL;
    node->next = NULL;

    return node;
}

NodeLine *createNodeLine(Line *obj)
{
    if (obj == NULL)
    {
        printf("Node Line Creation Error: NULL Line received\n");
        exit(1);
        return NULL;
    }

    NodeLine *node = (NodeLine *)malloc(sizeof(NodeLine));
    if (node == NULL)
    {
        printf("Node Line Creation Error: Allocation\n");
        exit(1);
        return NULL;
    }

    node->obj = obj;

    node->prior = NULL;
    node->next = NULL;

    return node;
}

NodePoly *createNodePoly(Poly *obj)
{
    if (obj == NULL)
    {
        printf("Node Poly-Object Creation Error: NULL poly-object received\n");
        exit(1);
        return NULL;
    }

    NodePoly *node = (NodePoly *)malloc(sizeof(NodePoly));
    if (node == NULL)
    {
        printf("Node Poly-Object Creation Error: Allocation\n");
        exit(1);
        return NULL;
    }

    node->obj = obj;

    node->prior = NULL;
    node->next = NULL;

    return node;
}