#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "render.h"
#include "../settings.h"
#include "../types/data.h"

/**
 * @brief
 *
 * @param point
 * @return int
 */
int renderPoint(Point *point)
{
    if (point == NULL)
    {
        return 0;
    }

    glBegin(GL_POINT);

    glVertex2d(point->x, point->y);
    printf("Point (%.2f, %.2f) rendered\n", point->x, point->y);

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
    if (node == NULL)
    {
        return 0;
    }

    glBegin(GL_POINTS);

    while (node != NULL)
    {
        if (node->obj == NULL)
        {
            return 0;
        }

        printf("(%.2f, %.2f) ", node->obj->x, node->obj->y);
        glVertex2d(node->obj->x, node->obj->y);

        node = node->next;
    }

    glEnd();

    return 1;
}

/**
 * @brief
 *
 * @param line
 * @return int
 */
int renderLine(Line *line)
{
    if (line == NULL)
    {
        return 0;
    }

    if (line->start == NULL || line->end == NULL)
    {
        printf("Render Line Error: Incomplete line received\n");
        return 0;
    }

    glBegin(GL_LINES);

    glVertex2d(line->start->x, line->start->y);
    glVertex2d(line->end->x, line->end->y);

    glEnd();

    return 1;
}

/**
 * @brief
 *
 * @param node
 * @return int
 */
int renderLines(NodeLine *node)
{
    if (node == NULL)
    {
        return 0;
    }

    Line *line;

    glBegin(GL_LINES);

    while (node != NULL)
    {
        line = node->obj;

        if (line == NULL)
        {
            exit(1);
            return 1;
        }

        if (line->start == NULL || line->end == NULL)
        {
            printf("[skip incomplete line] ");
            node = node->next;
            continue;
        }

        glVertex2d(line->start->x, line->start->y);
        glVertex2d(line->end->x, line->end->y);

        node = node->next;
    }

    glEnd();

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

/**
 * @brief
 *
 * @param poly
 * @return int
 */
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
    while (node != NULL)
    {
        glVertex2d(node->obj->x, node->obj->y);
        node = node->next;
    }

    glEnd();

    return 1;
}

/**
 * @brief
 *
 * @return int
 */
int renderData()
{
    int out = 1;

    // Render Points

    glColor3d(POINT_COLOR);

    if (DATA.point_head)
    {
        printf("Point rendering: ");
        out &= renderPoints(DATA.point_head);
        printf("\n");
    }

    // Render Lines

    glColor3d(LINE_COLOR);

    if (DATA.line_head)
    {
        printf("Lines rendering: ");
        out &= renderLines(DATA.line_head);
        printf("\n");
    }

    NodePoly *node;

    // Render Polylines

    glColor3d(POLYLINE_COLOR);

    node = DATA.polyline_head;
    while (node != NULL)
    {
        out &= renderPolyline(node->obj);
        node = node->next;
    }

    // Render Polygons

    glColor3d(POLYGON_COLOR);

    node = DATA.polygon_head;
    while (node != NULL)
    {
        out &= renderPolygon(node->obj);
        node = node->next;
    }

    return out;
}
