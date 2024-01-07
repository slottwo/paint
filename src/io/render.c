#include <GL/freeglut.h>
#include "render.h"

/**
 * @brief
 *
 * @param Poly
 * @return int
 */
int renderPoint(Point *Point)
{
    // if (Point == NULL) { ... return 0; }

    glBegin(GL_POINT);

    glVertex2d(Point->x, Point->y);

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
 * @param Poly
 * @return int
 */
int renderPoints(Poly *Poly)
{
    glBegin(GL_POINTS);

    Node *node = Poly->head;
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
 * @param Poly
 * @return int
 */
int renderLines(Poly *Poly)
{
    glBegin(GL_LINE_STRIP);

    Node *node = Poly->head;
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

int renderPolygon(Poly *Poly)
{
    // if (Poly == NULL) ... return 0;

    if (polyIsEmpty(Poly))
        return 1;

    glBegin(GL_POLYGON);

    Node *node = Poly->head;
    while (node != NULL)
    {
        glVertex2dv(getV(node->vertex));
        node = node->next;
    }
    glVertex2dv(getV(Poly->head->vertex));

    glEnd();

    return 1;
}
