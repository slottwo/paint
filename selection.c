#include <stdlib.h>

#include "selection.h"

/**
 * @brief Checks whether a point is present in a tolerance area
 *
 * @param float px and py from point. float mx and my from mouse click and a integer t of tolerance range
 * @return double 1 for true and 0 for false
 */
int checkPoint(Point *point, double mx, double my, double t)
{
    double px = point->x;
    double py = point->y;

    if (mx <= px + t && mx >= px - t)
    {
        if (my <= py + t && my >= py - t)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Select an existing point
 *
 * @param double coords x and y from mouse click
 * @return memory address of existing point vector
 */
NodePoint *selectPoint(double x, double y, double t)
{
    // GLOBAL "DATA"
    NodePoint *node_point = DATA.point_head;
    while (node_point != NULL)
    {
        if (checkPoint(node_point->obj, x, y, t))
            return node_point;
        node_point = node_point->next;
    }

    return NULL;
}

/**
 * @brief Checks if a line was selected by mouse click.
 *
 * @param Line line with two vertex. Int mx and my, the coords of mouse click and double t the tolerance of mouse click.
 * @return 1 for true and 0 to false
 */
int checkLine(Line *line, double mx, double my, double t)
{
    // CASO TRIVIAL DE SELEÇÃO DE LINHA
    // PEGANDO OS VÉRTICES
    Point *begin_point = line->start;
    Point *end_point = line->end;
    // SETANDO AS ESTRUTURAS DE COMPARAÇÃO UTILIZADAS
    double begin_point_Left = 0, begin_point_Right = 0, begin_point_Up = 0, begin_point_Down = 0;
    double end_point_Left = 0, end_point_Right = 0, end_point_Up = 0, end_point_Down = 0;
    /*printf("Start Point\n");
    printf("%.1f %.1f %.1f %.1f\n", begin_point_Left, begin_point_Right, begin_point_Down, begin_point_Up);
    printf("End Point\n");
    printf("%.1f %.1f %.1f %.1f\n", end_point_Left, end_point_Right, end_point_Down, end_point_Up);*/
    // FAZENDO AS ESTRUTURAS DOS VÉRTICES
    // START POINT
    if (begin_point->x < mx - t)
        begin_point_Left = 1;
    if (begin_point->x > mx + t) //aqui
        begin_point_Right = 1;
    if (begin_point->y < my - t)
        begin_point_Down = 1;
    if (begin_point->y > my + t)
        begin_point_Up = 1;
    // END POINT
    if (end_point->x < mx - t)
        end_point_Left = 1;
    if (end_point->x > mx + t)
        end_point_Right = 1;
    if (end_point->y < my - t)
        end_point_Down = 1;
    if (end_point->y > my + t) //aqui
        end_point_Up = 1;
    // CASO UM VÉRTICE TENHA 0000
    if (begin_point_Left == 0 && begin_point_Right == 0 && begin_point_Down == 0 && begin_point_Up == 0)
    {
        //printf("CASO 0000\n");
        return 1;
    }
    if (end_point_Left == 0 && end_point_Right == 0 && end_point_Down == 0 && end_point_Up == 0)
    {
        //printf("CASO 0000\n");
        return 1;
    }
    // ELIMINANDO SE ESTÃO TOTALMENTE EM UM ÚNICA DIREÇÃO
    if ((begin_point_Left && end_point_Left) || (begin_point_Right && end_point_Right) || (begin_point_Down && end_point_Down) || (begin_point_Up && end_point_Up))
    {
        //printf("AMBOS EM UMA DIRECAO\n");
        return 0;
    }
    /*printf("Start Point\n");
    printf("%.1f %.1f %.1f %.1f\n", begin_point_Left, begin_point_Right, begin_point_Down, begin_point_Up);
    printf("End Point\n");
    printf("%.1f %.1f %.1f %.1f\n", end_point_Left, end_point_Right, end_point_Down, end_point_Up);*/

    // CASOS NÃO TRIVIAIS
    return checkLineAfterNonTrivial(line, mx, my, t);
}

/**
 * @brief The non-trivial cases of selecting a line, checking whether it was selected.
 *
 * @param double begin_x and begin_y for the start point. end_x and end_y for end point. mx and my coords of mouse click. t the tolerance.
 * @return 1 for true and 0 for false.
 */
int checkLineAfterNonTrivial(Line *line, double mx, double my, double t)
{
    /*printf("CASO NAO TRIVIAL\n");
    printf("number: %.2f\n", line->start->x);*/
    double xmin = mx - t, xmax = mx + t, ymin = my - t, ymax = my + t;
    double x0 = line->start->x, y0 = line->start->y;
    double x1 = line->end->x, y1 = line->end->y;

    if (line->start->x < xmin)
    { // Est� na esquerda
        x0 = xmin;
        y0 = y0 + ((xmin - x0) * (y1 - y0) / (x1 - x0));
    }
    else if (line->start->x > xmax)
    { // Est� na direita
        x0 = xmax;
        y0 = y0 + ((xmax - x0) * (y1 - y0) / (x1 - x0));
    }
    else if (line->start->y < ymin)
    { // Est� abaixo
        y0 = ymin;
        x0 = x0 + ((ymin - y0) * (x1 - x0) / (y1 - y0));
    }
    else if (line->start->y > ymax)
    { // Est� acima
        y0 = ymax;
        x0 = x0 + ((ymax - y0) * (x1 - x0) / (y1 - y0));
    }

    double begin_point_Left = 0, begin_point_Right = 0, begin_point_Up = 0, begin_point_Down = 0;
    double end_point_Left = 0, end_point_Right = 0, end_point_Up = 0, end_point_Down = 0;
    // START POINT
    if (x0 < xmin)
        begin_point_Left = 1;
    if (x0 > xmax)
        begin_point_Right = 1;
    if (y0 < ymin)
        begin_point_Down = 1;
    if (y0 > ymax)
        begin_point_Up = 1;
    // END POINT
    if (x1 < xmin)
        end_point_Left = 1;
    if (x1 > xmax)
        end_point_Right = 1;
    if (y1 < ymin)
        end_point_Down = 1;
    if (y1 > ymax)
        end_point_Up = 1;

    /*printf("Start Point\n");
    printf("%.1f %.1f %.1f %.1f\n", begin_point_Left, begin_point_Right, begin_point_Down, begin_point_Up);
    printf("End Point\n");
    printf("%.1f %.1f %.1f %.1f\n", end_point_Left, end_point_Right, end_point_Down, end_point_Up);*/

    if (begin_point_Left == 0 && begin_point_Right == 0 && begin_point_Down == 0 && begin_point_Up == 0)
        return 1;
    if (end_point_Left == 0 && end_point_Right == 0 && end_point_Down == 0 && end_point_Up == 0)
        return 1;


    return 0;
}

/**
 * @brief Select an existing line
 *
 * @param double coords x and y from mouse click
 * @return memory address of existing line vector
 */
NodeLine *selectLine(double x, double y, double t)
{
    // GLOBAL "DATA"
    NodeLine *node_line = DATA.line_head;
    while (node_line != NULL)
    {
        if (checkLine(node_line->obj, x, y, t))
            return node_line;
        node_line = node_line->next;
    }

    return NULL;
}

/**
 * @brief Checks the non-trivial cases of the analyzed edge for the polygon selection algorithm.
 *
 * @param The two points that define the edge. The coords mx and my from mouse click.
 * @return 1 for count the edge and 0 for no count.
 */
int checkEdgePolygonNoNTrivialCases(Point *p1, Point *p2, double mx, double my)
{
    //printf("POLY: CASO NAO TRIVIAL\n");
    double xi = p1->x + ((my - p1->y) * (p2->x - p1->x) / (p2->y - p1->y));

    if (xi > mx)
        return 1;

    return 0;
}

/**
 * @brief Checks the special cases of the analyzed edge for the polygon selection algorithm.
 *
 * @param The points analized for special caso of shot algorithm.
 * @return 1 for count the edge and 0 for no count.
 */
int checkEdgePolygonSpecialCase(Point *atual, Point *ant, Point *next)
{
    //printf("POLY: CASO ESPECIAL\n");
    if((atual->y > ant->y && atual->y < next->y) || (atual->y < ant->y && atual->y > next->y)) return 1;

    return 0;
}

/**
 * @brief Checks the analyzed edge cases for the polygon selection algorithm.
 *
 * @param The two points that define the edge. The coords mx and my from mouse click.
 * @return 1 for count the edge and 0 for no count.
 */
int checkEdgePolygonCases(Point *p1, Point *p2, double mx, double my)
{
    // TRIVIAL CASES
    if (p1->y > my && p2->y > my)
    {
        //printf("Caso 1 trivial\n");
        return 0;
    }
    if (p1->y < my && p2->y < my)
    {
        //printf("Caso 2 trivial\n");
        return 0;
    }
    if (p1->x < mx && p2->x < mx)
    {
        //printf("Caso 3 trivial\n");
        return 0;
    }
    if ((p1->x > mx && p2->x > mx) && ((p1->y > my && p2->y < my) || (p1->y < my && p2->y > my)))
    {
        //printf("Caso 4 trivial\n");
        return 1;
    }

    // NONTRIVIAL CASES
    return checkEdgePolygonNoNTrivialCases(p1, p2, mx, my);
}

/**
 * @brief Check if the polygon was selected using the shot algorithm.
 *
 * @param The polygon p. The coords mx and my from mouse click.
 * @return 1 for true and 0 for false.
 */
int checkPoly(Poly *p, double mx, double my)
{
    int count = 0;
    NodePoint *aux = p->head;
    NodePoint *ant = NULL;
    while (aux->next != NULL)
    {
        if(ant != NULL)
        {
            if(aux->obj->y == my && aux->obj->x > mx) count += checkEdgePolygonSpecialCase(aux->obj, ant->obj, aux->next->obj);

            else count += checkEdgePolygonCases(aux->obj, aux->next->obj, mx, my);
        }

        ant = aux;
        aux = aux->next;
    }
    //ANALISANDO O PRIMEIRO PONTO
    if(p->head->obj->y == my && p->head->obj->x > mx) count += checkEdgePolygonSpecialCase(p->head->obj, aux->obj, p->head->next->obj);
    else count += checkEdgePolygonCases(p->head->obj, p->head->next->obj, mx, my);

    //ANALISANDO O ÚLTIMO PONTO
    if(aux->obj->y == my && aux->obj->x > mx) count += checkEdgePolygonSpecialCase(aux->obj, ant->obj, p->head->obj);
    else count += checkEdgePolygonCases(aux->obj, p->head->obj, mx, my);

    if (count % 2 == 0)
        return 0;
    else
        return 1;
}

/**
 * @brief Select an existing polygon.
 *
 * @param double coords x and y from mouse click.
 * @return memory address of existing polygon vector
 */
NodePoly *selectPolygon(double x, double y)
{
    // GLOBAL "DATA"
    NodePoly *node_poly = DATA.polygon_head;
    while (node_poly != NULL)
    {
        if (checkPoly(node_poly->obj, x, y))
            return node_poly;
        node_poly = node_poly->next;
    }

    return NULL;
}


int checkPolyline(NodePoly *poly, double mx, double my, double t)
{
    NodePoint *aux = poly->obj->head;
    Line *line;
    while(aux->next != NULL)
    {
        line = createLineP(aux->obj, aux->next->obj);
        if(checkLine(line, mx, my, t)) return 1;
        aux = aux->next;
    }
    line = createLineP(aux->obj, poly->obj->head->obj);
    if(checkLine(line, mx, my, t)) return 1;

    return 0;
}


NodePoly *selectPolyline(double mx, double my, double t)
{
    NodePoly *node_poly = DATA.polyline_head;
    while(node_poly != NULL)
    {
        if(checkPolyline(node_poly, mx, my, t)) return node_poly;
        node_poly = node_poly->next;
    }

    return NULL;
}

