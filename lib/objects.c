#include <stdlib.h>
#include "lib/objects.h"

/**
 * @brief Create a Point object
 *
 * @param x Double x position
 * @param y Double y position
 * @return Point*
 */
Point *createPoint(double x, double y)
{
    Point *point = (Point *)malloc(sizeof(Point));
    if (point == NULL)
    {
        printf("Error: malloc fail");
        exit(1);
    }

    *point[0] = x;
    *point[1] = y;

    return point;
}

/**
 * @brief Create a empty Polygon object (dynamic linked list)
 *
 * @return Polygon*
 */
Polygon *createPolygon()
{
    Polygon *polygon = (Polygon *)malloc(sizeof(Polygon));
    if (polygon == NULL)
    {
        printf("Error: malloc fail");
        exit(1);
    }

    polygon->head = NULL;

    return polygon;
}

/**
 * @brief Create a n-gonal Polygon object (dynamic linked list)
 * 
 * @param coords Double matrix (n,2)
 * @param n Amount of vertexes
 * @return Polygon* 
 */
Polygon *createFPolygon(double **coords, int n)
{
    Polygon *polygon = createPolygon();

    for (int i = 0; i < n; i++)
    {
        appendPoint(polygon, createPoint(coords[i][0], coords[i][1]));
    }

    return polygon;
}

/**
 * @brief Create a Node of a Polygon object
 * 
 * @param point 
 * @return Node* 
 */
Node *createNode(Point *point)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Error: malloc fail");
        exit(1);
    }

    node->vertex = point;
    node->next = NULL;

    return node;
}

void appendPoint(Polygon *polygon, Point *point)
{
    if (polygon == NULL | point == NULL)
        exit(1);

    Node *finder = polygon->head;
    if (finder)
    {
        finder = createNode(point);
        return;
    }
    while (1)
    {
        if (finder->next == NULL)
            break;
    }

    finder->next = createNode(point);
}

void freePolygon(Polygon *polygon)
{
    if (polygon == NULL)
        exit(1);

    free(polygon);
    polygon = NULL;
}
