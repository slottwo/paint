#include <stdlib.h>
#include <stdio.h>
#include "polygon.h"

/**
 * @brief Create a Node object
 *
 * @param vertex A polygon vertex Point object
 * @return Node* | NULL
 */
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

/**
 * @brief Create a empty Polygon object
 *
 * @return Polygon* | NULL
 */
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

/**
 * @brief Create a filled Polygon object with n vertexes
 *
 * @param vertexes Array[n][2] of double values (..., (x, y), ...)
 * @param n Amount of vertexes
 * @return Polygon*
 */
Polygon *createFPolygon(double **vertexes, int n)
{
    if (vertexes == NULL)
    {
        printf("Polygon Creation Error: NULL vertexes vector received\n");
        exit(1);
        return NULL;
    }

    Polygon *polygon = createPolygon();

    for (int i = 0; i < n; i++)
    {
        if (!polygonPush(polygon, createPoint(vertexes[i])))
        {
            printf("Polygon Filling Error: polygonPush() fail\n");
            exit(1);
            freePolygon(polygon);
            return NULL;
        }
    }

    return polygon;
}

/**
 * @brief Push a new vertex on top of polygon
 *
 * @param polygon Polygon to receiving the push
 * @param vertex Point to be pushed
 * @return int
 */
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

    return 1;
}

/**
 * @brief Removed the last added vertex to the polygon
 *
 * @param polygon Polygon object
 * @return Point* removed vertex | NULL
 */
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

/**
 * @brief Returns true if polygon has vertexes
 *
 * @param polygon Polygon object
 * @return int
 */
int polygonIsEmpty(Polygon *polygon)
{
    if (polygon == NULL)
    {
        printf("Polygon Parsing Error: NULL polygon received\n");
        exit(1);
        return -1;
    }

    return polygon->head == NULL;
}

/**
 * @brief Get the amount of vertexes on the polygon
 *
 * @param polygon Polygon object
 * @return int
 */
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

/**
 * @brief
 *
 * @param polygon Polygon object
 */
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

/**
 * @brief Get the vertex coordinates of a Node object. Remind to free the return later
 *
 * @param node Node object corresponding to a polygon vertex
 * @return double* (x, y)
 */
double *getVertex(Node *node)
{
    double *coordinates = (double *)malloc(2 * sizeof(double));

    coordinates[0] = node->vertex->x;
    coordinates[1] = node->vertex->y;

    return coordinates;
}
