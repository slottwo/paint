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
 * @brief Create a Line object
 *
 * @param points Double matrix (2,2)
 * @return Line*
 */
Line *createLine(double **points)
{
    Line *line = (Line *)malloc(sizeof(Line));
    if (line == NULL)
    {
        printf("Error: malloc fail");
        exit(1);
    }

    for (int i = 0; i < 4; i++)
    {
        // 1 2 3 4
        // 0 0 1 1 (/2)
        // 0 1 0 1 (%2)
        *line[i / 2][i % 2] = points[i / 2][i % 2];
    }

    return line;
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
 * @param points Double matrix (n,2)
 * @param n Amount of vertexes
 * @return Polygon*
 */
Polygon *createFPolygon(double **points, int n)
{
    Polygon *polygon = createPolygon();

    for (int i = 0; i < n; i++)
    {
        pushPoint(polygon, createPoint(points[i][0], points[i][1]));
    }

    return polygon;
}

/**
 * @brief Create a Node of a Polygon object (Private Method)
 *
 * @param vertex Point (double[2]) of new node
 * @return Node*
 */
Node *createNode(Point *vertex)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Error: malloc fail");
        exit(1);
    }

    node->vertex = vertex;
    node->next = NULL;

    return node;
}

/**
 * @brief Append a new node on top (head) of polygon as a stack
 * 
 * @param polygon Polygon to receive the push
 * @param vertex Point to be pushed on polygon
 */
void pushPoint(Polygon *polygon, Point *vertex)
{
    if (polygon == NULL | vertex == NULL)
        exit(1);

    Node *new_node = createNode(vertex);
    new_node->next = polygon->head;
    polygon->head = new_node;
}

/**
 * @brief 
 * 
 * @param polygon 
 * @return Point* 
 */
Point *popPoint(Polygon *polygon)
{
    if (polygon == NULL)
        exit(1);

    if (polygon->head == NULL)
        return NULL;

    Node *poppedNode = polygon->head;
    polygon->head = polygon->head->next;

    Point *poppedPoint = poppedNode->vertex;

    free(poppedNode);

    return poppedPoint;
}

/**
 * @brief 
 * 
 * @param polygon 
 */
void freePolygon(Polygon *polygon)
{
    if (polygon == NULL)
        exit(1);
    
    Node *head;
    while (polygon->head)
    {
        head = polygon->head;
        polygon->head = polygon->head->next;
        free(head->vertex);
        free(head);
    }
    
    free(polygon);
    
    head = NULL;
    polygon = NULL;
}
