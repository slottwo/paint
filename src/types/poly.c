#include <stdlib.h>
#include <stdio.h>

#include "poly.h"

/**
 * @brief Create a empty Poly object (double linked list)
 *
 * @return Poly* | NULL
 */
Poly *createPoly()
{
    Poly *new_poly = (Poly *)malloc(sizeof(Poly));
    if (new_poly == NULL)
    {
        printf("Poly Creation Error: Allocation\n");
        exit(1);
        return NULL;
    }

    new_poly->head = NULL;

    return new_poly;
}

/**
 * @brief Create a filled Poly object with n vertexes
 *
 * @param vertexes Array[n][2] of double values (..., (x, y), ...)
 * @param n Amount of vertexes
 * @return Poly*
 */
Poly *createFPoly(double **vertexes, int n)
{
    if (vertexes == NULL)
    {
        printf("Poly Creation Error: NULL vertexes vector received\n");
        exit(1);
        return NULL;
    }

    Poly *new_poly = createPoly();

    for (int i = 0; i < n; i++)
    {
        if (!polyPush(new_poly, createPointV(vertexes[i])))
        {
            printf("Poly Filling Error: polyPush() fail\n");
            exit(1);
            freePoly(new_poly);
            return NULL;
        }
    }

    return new_poly;
}

/**
 * @brief Push a new vertex on top of Poly
 *
 * @param poly Poly to receiving the push
 * @param vertex Point to be pushed
 * @return int
 */
int polyPush(Poly *poly, Point *vertex)
{
    if (poly == NULL)
    {
        printf("Poly Popping Error: NULL poly received\n");
        exit(1);
        return 0;
    }

    if (vertex == NULL)
    {
        printf("Poly Popping Error: NULL vertex received\n");
        exit(1);
        return 0;
    }

    NodePoint *new_node = createNodePoint(vertex);

    if (polyIsEmpty(poly))
    {
        poly->head = new_node;
        return 1;
    }

    new_node->next = poly->head;
    poly->head->prior = new_node;
    poly->head = new_node;

    return 1;
}

/**
 * @brief Removed the last added vertex to the Poly
 *
 * @param poly Poly object
 * @return Point* removed vertex | NULL
 */
Point *polyPop(Poly *poly)
{
    if (poly == NULL)
    {
        printf("Poly Popping Error: NULL poly received\n");
        exit(1);
        return NULL;
    }

    if (polyIsEmpty(poly))
    {
        printf("Poly Popping Error: Empty poly received\n");
        return NULL;
    }

    NodePoint *last_added_node = poly->head;

    poly->head = last_added_node->next;

    if (poly->head != NULL) // if it wasn't the last
    {
        poly->head->prior = NULL;
    }

    Point *popped_point = last_added_node->obj;

    free(last_added_node);
    return popped_point;
}

/**
 * @brief Returns true if Poly has vertexes
 *
 * @param poly Poly object
 * @return int
 */
int polyIsEmpty(Poly *poly)
{
    if (poly == NULL)
    {
        printf("Poly Parsing Error: NULL poly received\n");
        exit(1);
        return -1;
    }

    return poly->head == NULL;
}

/**
 * @brief Get the amount of vertexes on the Poly
 *
 * @param poly Poly object
 * @return int
 */
int polyLength(Poly *poly)
{
    if (poly == NULL)
    {
        printf("Poly Parsing Error: NULL poly received\n");
        exit(1);
        return -1;
    }

    int length = 0;
    NodePoint *node = poly->head;

    while (node != NULL)
    {
        length += 1;
        node = node->next;
    }

    return length;
}

/**
 * @brief
 *
 * @param poly Poly object
 */
void freePoly(Poly *poly)
{
    if (poly == NULL)
    {
        printf("Poly Clearance Error: NULL poly received\n");
        exit(1);
        return;
    }

    Point *point;

    while (polyIsEmpty(poly) == 0)
    {
        point = polyPop(poly);
        freePoint(point);
    }

    free(poly);

    poly = NULL;
}
