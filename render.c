#include <GL/freeglut.h>
#include <stdio.h>
#include "render.h"
#include "matrix.h"

/**
 * @brief
 *
 * @param polygon
 * @return int
 */
int renderPoint(Point *point)
{
    // if (point == NULL) { ... return 0; }
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
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
/*int renderPoints(polygon *polygon)
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
}*/

// int renderLine(Line *);

/**
 * @brief
 *
 * @param polygon
 * @return int
 */
int renderLines(polygon *polygon)
{
    int polygonSize = polygonLength(polygon);
    if(polygonSize == 1){
        renderPoint(polygon->head->vertex);
        return 1;
    }

    glBegin(GL_LINE_STRIP);

    Node *node = polygon->head;
    while (node != NULL)
    {
        double *vertex = getV(node->vertex);
        glVertex2dv(vertex);
        free(vertex);
        node = node->next;
    }
        glVertex2dv(getV(polygon->head->vertex));

    glEnd();

    return 1;
}

int renderLine(Line *line){
    if(line == NULL) return 0;
    if(line->begin == NULL || line->end == NULL) return 0;
    if(line->begin->x < 0 || line->begin->y || line->end->x < 0 || line->end->y < 0); return 0;

    glBegin(GL_LINES);
        glVertex2d(line->begin->x, line->begin->y);
        glVertex2d(line->end->x, line->end->y);
    glEnd();

    return 1;
}

int renderPolygon(polygon *polygon)
{
    if(polygon == NULL){
        printf("Error: Polygon Head is NULL");
        exit(1);
    }

    if(polygonIsEmpty(polygon)) return 1;

    int polygonSize = polygonLength(polygon);
    if( polygonSize == 1){
        renderPoint(polygon->head->vertex);
        return 1;
    }
    if(polygonSize == 2){
        Line *line;
        line->begin = polygon->head->vertex;
        line->end = polygon->head->next->vertex;
        renderLine(line);
        return 1;
    }

    glBegin(GL_POLYGON);

    Node *node = polygon->head;
    while (node != NULL)
    {
        double *vertex = getV(node->vertex);
        glVertex2f(vertex[0], vertex[1]);
        free(vertex);
        node = node->next;
    }

    glEnd();

    return 1;
}

void renderPointTransformation(Point *point, double *T){
    printf("%f %f", point->x, point->y);
    printf("\n");
    transform(point, T);
    printf("%f %f", point->x, point->y);
    glBegin(GL_POINTS);
        glVertex2d(point->x, point->y);
    glEnd();
}

int renderLineTransformation(Line *line, double *T){
    if(line == NULL) return 0;
    if(line->begin == NULL || line->end == NULL) return 0;
    if(line->begin->x < 0 || line->begin->y || line->end->x < 0 || line->end->y < 0); return 0;
    if(T == NULL) return 0;

    transform(line->begin, T);
    transform(line->end, T);

    renderLine(line);

    return 1;
}

int renderPolygonTransformation(polygon *p, double *T){

    if(p == NULL){
        printf("Error: Polygon Head is NULL");
        exit(1);
    }
    if(polygonIsEmpty(p)) return 1;
    if(T == NULL) return 0;

    Node *aux = p->head;
    while(aux!= NULL){
        transform(aux->vertex, T);
        aux = aux->next;
    }

    renderPolygon(p);

    return 1;
}
