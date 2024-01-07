#include <stdlib.h>
#include "data.h"

struct data DATA = {NULL, NULL, NULL, NULL};

struct current_node SELECTED = {none_type, NULL, NULL, NULL, NULL};

int pointDataPush(Point *point)
{
    if (point == NULL)
    {
        /* code */
        return 0;
    }

    NodePoint *new_node = createNodePoint(point);
    if (new_node == NULL)
    {
        /* code */
        return 0;
    }

    new_node->next = DATA.point_head;
    DATA.point_head = new_node;

    SELECTED.current_type = point_type;
    SELECTED.current_point = new_node;

    return 1;
}

int pointDataRemove(NodePoint *node)
{
    if (node == NULL)
    {
        /* code */
        return 0;
    }

    if (node->prior == NULL)
    {
        DATA.point_head = node->next;
    }
    else
    {
        node->prior->next = node->next;
    }

    freePoint(node->obj);
    free(node);
    node = NULL;

    SELECTED.current_type = 0;
    SELECTED.current_point = NULL;

    return 1;
}

int lineDataPush(Line *line)
{
    if (line == NULL)
    {
        /* code */
        return 0;
    }

    NodeLine *new_node = createNodeLine(line);
    if (new_node == NULL)
    {
        /* code */
        return 0;
    }

    new_node->next = DATA.line_head;
    DATA.line_head = new_node;

    SELECTED.current_type = line_type;
    SELECTED.current_line = new_node;

    return 1;
}

int lineDataRemove(NodeLine *node)
{
    if (node == NULL)
    {
        /* code */
        return 0;
    }

    if (node->prior == NULL)
    {
        DATA.line_head = node->next;
    }
    else
    {
        node->prior->next = node->next;
    }

    freeLine(node->obj);
    free(node);
    node = NULL;

    SELECTED.current_type = 0;
    SELECTED.current_line = NULL;

    return 1;
}

int polylineDataPush(Poly *poly)
{
    if (poly == NULL)
    {
        /* code */
        return 0;
    }

    NodePoly *new_node = createNodePoly(poly);
    if (new_node == NULL)
    {
        /* code */
        return 0;
    }

    new_node->next = DATA.polyline_head;
    DATA.polyline_head = new_node;

    SELECTED.current_type = polyline_type;
    SELECTED.current_polyline = new_node;

    return 1;
}

int polylineDataRemove(NodePoly *node)
{
    if (node == NULL)
    {
        /* code */
        return 0;
    }

    if (node->prior == NULL)
    {
        DATA.polyline_head = node->next;
    }
    else
    {
        node->prior->next = node->next;
    }

    freePoly(node->obj);
    free(node);
    node = NULL;

    SELECTED.current_type = 0;
    SELECTED.current_polyline = NULL;

    return 1;
}

int polygonDataPush(Poly *poly)
{
    if (poly == NULL)
    {
        /* code */
        return 0;
    }

    NodePoly *new_node = createNodePoly(poly);
    if (new_node == NULL)
    {
        /* code */
        return 0;
    }

    new_node->next = DATA.polygon_head;
    DATA.polygon_head = new_node;

    SELECTED.current_type = polygon_type;
    SELECTED.current_polygon = new_node;

    return 1;
}

int polygonDataRemove(NodePoly *node)
{
    if (node == NULL)
    {
        /* code */
        return 0;
    }

    if (node->prior == NULL)
    {
        // Devo verificar se node está em data?
        DATA.polygon_head = node->next;
    }
    else
    {
        node->prior->next = node->next;
    }

    freePoly(node->obj);
    free(node);
    node = NULL;

    SELECTED.current_type = 0;
    SELECTED.current_polygon = NULL;

    return 1;
}

int pointIsInDATA(NodePoint *node)
{
    NodePoint *parse = DATA.point_head;
    while (parse != NULL)
    {
        if (parse == node)
            return 1;

        parse = parse->next;
    }
    return 0;
}

int lineIsInDATA(NodeLine *node)
{
    NodeLine *parse = DATA.line_head;
    while (parse != NULL)
    {
        if (parse == node)
            return 1;

        parse = parse->next;
    }
    return 0;
}

int polylineIsInDATA(NodePoly *node)
{
    NodePoly *parse = DATA.polyline_head;
    while (parse != NULL)
    {
        if (parse == node)
            return 1;

        parse = parse->next;
    }
    return 0;
}

int polygonIsInDATA(NodePoly *node)
{
    NodePoly *parse = DATA.polygon_head;
    while (parse != NULL)
    {
        if (parse == node)
            return 1;

        parse = parse->next;
    }
    return 0;
}
