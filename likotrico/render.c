#include <GL/freeglut.h>
#include "render.h"

/**
 * @brief
 *
 * @param polygon
 * @return int
 */
int renderPoint(Point *point)
{
    // if (point == NULL) { ... return 0; }

    glBegin(GL_POINT);

    glVertex2d(point->x, point->y);

    glEnd();

    return 1;
}

// int renderPoints(Point **points, int n)
// {
//     glBegin(GL_POINTS);
//     for (int i = 0; i < n; i++)
//     {
//         glVertex2d(points[i]->x, points[i]->y);
//     }
//     glEnd();
//     return 1;
// }

/**
 * @brief
 *
 * @param polygon
 * @return int
 */
int renderPoints(polygon *polygon)
{
    glBegin(GL_POINTS);

    Node *node = polygon->head;
    while (node->next != NULL)
    {
        double *vertex = getV(node->vertex);
        glVertex2dv(vertex);
        free(vertex);
        node = node->next;
    }

    glEnd();

    return 1;
}

// int renderLine(Line *);

/**
 * @brief
 *
 * @param polygon
 * @return int
 */
int renderLines(polygon *polygon)
{
    glBegin(GL_LINE_STRIP);

    Node *node = polygon->head;
    while (node->next != NULL)
    {
        double *vertex = getV(node->vertex);
        glVertex2dv(vertex);
        free(vertex);
        node = node->next;
    }

    glEnd();

    return 1;
}

int renderpolygon(polygon *polygon)
{
    // if (polygon == NULL) ... return 0;

    if (polygonIsEmpty(polygon))
        return 1;

    glBegin(GL_POLYGON);

    Node *node = polygon->head;
    while (node != NULL)
    {
        glVertex2dv(getV(node->vertex));
        node = node->next;
    }
    glVertex2dv(getV(polygon->head->vertex));

    glEnd();

    return 1;
}

