#include <GL/freeglut.h>
#include "render.h"

int renderPoint(Point *point)
{
    // if (point == NULL) { ... }

    glBegin(GL_POINT);
    glVertex2d(point->x, point->y);
    glEnd();
}

// int renderPoints(Point **points)
// {
//     /* code */
// }

int renderPoints(Polygon *polygon)
{
    glBegin(GL_POINTS);
    // ...
    glEnd();
}

// int renderLine(Line *);

int renderLines(Polygon *polygon)
{
    glBegin(GL_LINE_STRIP);

    Node *node = polygon->head;
    while (node->next != NULL)
    {
        double *vertex = getVertex(node);
        glVertex2dv(vertex);
        free(vertex);
        node = node->next;
    }

    glEnd();
}

int renderPolygon(Polygon *polygon)
{
    glBegin(GL_POLYGON);

    Node *node = polygon->head;
    while (node != NULL)
    {
        glVertex2dv(getVertex(node));
        node = node->next;
    }
    glVertex2dv(getVertex(polygon->head));

    glEnd();
}
