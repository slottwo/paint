#include "render.h"

#include "../types/data.h"

#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief
 *
 * @param point
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

/**
 * @brief
 *
 * @param poly
 * @return int
 */
int renderPoints(NodePoint *node)
{
    // if (node == NULL) { ... return 0; }

    glBegin(GL_POINTS);

    while (node->next != NULL)
    {
        glVertex2d(node->obj->x, node->obj->y);
        node = node->next;
    }

    glEnd();

    return 1;
}

int renderLine(Line *line)
{
    // if (line == NULL) { ... return 0; }

    glBegin(GL_LINE);

    glVertex2d(line->start->x, line->start->y);
    glVertex2d(line->end->x, line->end->y);

    glEnd();

    return 1;
}

int renderLines(NodeLine *node)
{
    // if (node == NULL) { ... return 0; }

    Line *line;
    while (node->next != NULL)
    {
        line = node->obj;

        renderLine(line);

        node = node->next;
    }

    return 1;
}

/**
 * @brief
 *
 * @param poly
 * @return int
 */
int renderPolyline(Poly *poly)
{
    if (poly == NULL)
    {
        printf("Render Polyline Error: NULL poly received\n");
        exit(1);
        return 0;
    }

    if (polyLength(poly) < 2)
        return 0;

    glBegin(GL_LINE_STRIP);

    NodePoint *node = poly->head;
    while (node->next != NULL)
    {
        glVertex2d(node->obj->x, node->obj->y);
        node = node->next;
    }

    glEnd();

    return 1;
}

int renderPolygon(Poly *poly)
{
    if (poly == NULL)
    {
        printf("Render Polygon Error: NULL poly received\n");
        exit(1);
        return 0;
    }

    // switch (polyLength(poly))
    // {
    // case 0:
    //     return 1;
    //     break;

    // case 1:
    //     renderPoint(poly->head->obj);
    //     return 1;
    //     break;

    // case 2:
    //     renderPolyline(poly);
    //     return 1;
    //     break;

    // default:
    //     break;
    // }

    if (polyLength(poly) < 3)
        return 0;

    glBegin(GL_POLYGON);

    NodePoint *node = poly->head;
    while (node->next != NULL)
    {
        glVertex2d(node->obj->x, node->obj->y);
        node = node->next;
    }

    glEnd();

    return 1;
}

int renderData()
{
    // Render Points
    renderPoints(DATA.point_head);

    // Render Lines
    renderLines(DATA.line_head);

    NodePoly *node;

    // Render Polylines
    node = DATA.polyline_head;
    while (node->next != NULL)
    {
        renderPolyline(node->obj);
        node = node->next;
    }

    // Render Polygons
    node = DATA.polygon_head;
    while (node->next != NULL)
    {
        renderPolygon(node->obj);
        node = node->next;
    }

    return 1;
}
