#include <stdio.h>
#include "polygon.h"

Node *createNode(Point *vertex)
{
    if (vertex == NULL)
    {
        printf("Node Creation Error: NULL vertex received\n");
        exit(1);
        return NULL;
    }

    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Node Creation Error: Allocation\n");
        exit(1);
        return NULL;
    }

    node->vertex = vertex;
    node->next = NULL;

    return node;
}

Polygon *createPolygon()
{
    Polygon *polygon = (Polygon *)malloc(sizeof(Polygon));
    if (polygon == NULL)
    {
        printf("Polygon Creation Error: Allocation\n");
        exit(1);
        return NULL;
    }

    polygon->head = NULL;

    return polygon;
}

Polygon *createFPolygon(double **vertexes, int n)
{
    if (vertexes == NULL)
    {
        printf("Node Creation Error: NULL vertexes vector received\n");
        exit(1);
        return NULL;
    }

    Polygon *polygon = createPolygon();

    for (int i = 0; i < n; i++)
        pushPoint(polygon, createPoint(vertexes[i]));

    return polygon;
}

int polygonPush(Polygon *polygon, Point *vertex)
{
    if (polygon == NULL)
    {
        printf("Polygon Popping Error: NULL polygon received\n");
        exit(1);
        return NULL;
    }

    if (vertex == NULL)
    {
        printf("Polygon Popping Error: NULL vertex received\n");
        exit(1);
        return NULL;
    }

    Node *new_node = createNode(vertex);
    new_node->next = polygon->head;
    polygon->head = new_node;
}

Point *polygonPop(Polygon *polygon)
{
    if (polygon == NULL)
    {
        printf("Polygon Popping Error: NULL polygon received\n");
        exit(1);
        return NULL;
    }

    if (polygonIsEmpty(polygon))
    {
        printf("Polygon Popping Error: Empty polygon received\n");
        return NULL;
    }

    Node *poppedNode = polygon->head;
    polygon->head = polygon->head->next;

    Point *poppedPoint = poppedNode->vertex;

    free(poppedNode);

    return poppedPoint;
}

int polygonIsEmpty(Polygon *polygon)
{
    return polygon->head == NULL;
}

void freePolygon(Polygon *polygon)
{
    if (polygon == NULL)
    {
        printf("Polygon Clearance Error: NULL polygon received\n");
        exit(1);
        return NULL;
    }

    /* code */
}
