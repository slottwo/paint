#include <stdlib.h>
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
        polygonPush(polygon, createPoint(vertexes[i]));

    return polygon;
}

int polygonPush(Polygon *polygon, Point *vertex)
{
    if (polygon == NULL)
    {
        printf("Polygon Popping Error: NULL polygon received\n");
        exit(1);
        return 0;
    }

    if (vertex == NULL)
    {
        printf("Polygon Popping Error: NULL vertex received\n");
        exit(1);
        return 0;
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

    free(poppedNode); // Don't use `freeNode()`!

    return poppedPoint;
}

int polygonIsEmpty(Polygon *polygon)
{
    if (polygon == NULL)
    {
        printf("Polygon Parsing Error: NULL polygon received\n");
        exit(1);
        return -1; // -1 ou zero?
    }

    return polygon->head == NULL;
}

int polygonLength(Polygon *polygon)
{
    if (polygon == NULL)
    {
        printf("Polygon Parsing Error: NULL polygon received\n");
        exit(1);
        return -1;
    }
    int length = 0;
    Node *node = polygon->head;

    while (node != NULL)
    {
        length++;
        node = node->next;
    }
    
    return length;
}


void freePolygon(Polygon *polygon)
{
    if (polygon == NULL)
    {
        printf("Polygon Clearance Error: NULL polygon received\n");
        exit(1);
        return;
    }

    Point *point;
    while (!polygonIsEmpty(polygon))
    {
        point = polygonPop(polygon);
        freePoint(point);
    }

    free(polygon);
    polygon = NULL;
}

// Inútil
void freeNode(Node *node)
{
    if (node == NULL)
    {
        printf("Node Clearance Error: NULL node received\n");
        exit(1);
        return;
    }

    freePoint(node->vertex);
    free(node);
    node = NULL;
}

double *getVertex(Node *node)
{
    double coords[] = {node->vertex->x, node->vertex->x};

    return coords;
}
