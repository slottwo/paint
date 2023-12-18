#include <stdlib.h>
#include "lib/objects.h"

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
