#include "selection.h"
#include <stdlib.h>

/**
 * @brief Checks whether a point is present in a tolerance area
 *
 * @param float px and py from point. float mx and my from mouse click and a integer t of tolerance range
 * @return int 1 for true and 0 for false
 */
int checkPoint(double px, double py, int mx, int my, int t){
    if(mx <= px + t && mx >= px - t){
        if(my <= py + t && my >= py - t){
            return 1;
        }
    }
    return 0;
}

/**
 * @brief Select an existing point
 *
 * @param int coords x and y from mouse click
 * @return memory address of existing point vector
 */
Point *selectPoint(int x, int y, int t){
    //GLOBAL VECTOR "all_points"
    int i;
    for(i = 0; i < 1000; i++){
        if(all_points[i] != NULL){
            if(checkPoint(all_points[i]->x, all_points[i]->y, x, y, t)){
                Point *aux = all_points[i];
                return aux;
            }
        }
    }
    return NULL;
}


/**
 * @brief Checks if a line was selected by mouse click.
 *
 * @param Line line with two vertex. Int mx and my, the coords of mouse click and int t the tolerance of mouse click.
 * @return 1 for true and 0 to false
 */
int checkLine(Line *line, int mx, int my, int t){
    //CASO TRIVIAL DE SELEÇÃO DE LINHA
    //PEGANDO OS VÉRTICES
    Point *begin_point = line->begin;
    Point *end_point = line->end;
    //SETANDO AS ESTRUTURAS DE COMPARAÇÃO UTILIZADAS
    int begin_point_Left = 0, begin_point_Right = 0, begin_point_Up = 0, begin_point_Down = 0;
    int end_point_Left = 0, end_point_Right = 0, end_point_Up = 0, end_point_Down =0;
    //FAZENDO AS ESTRUTURAS DOS VÉRTICES
    //BEGIN POINT
    if(begin_point->x < mx - t) begin_point_Left = 1;
    if(begin_point->x > mx + t) begin_point_Right = 1;
    if(begin_point->y < my - t) begin_point_Down = 1;
    if(begin_point->y > my + t) begin_point_Up = 1;
    //END POINT
    if(end_point->x < mx - t) end_point_Left = 1;
    if(end_point->x > mx + t) end_point_Right = 1;
    if(end_point->y < my - t) end_point_Down = 1;
    if(end_point->y > my + t) end_point_Up = 1;
    //CASO UM VÉRTICE TENHA 0000
    if(begin_point_Left == 0 && begin_point_Right == 0 && begin_point_Down == 0 && begin_point_Up == 0) return 1;
    if(end_point_Left == 0 && end_point_Right == 0 && end_point_Down == 0 && end_point_Up == 0) return 1;
    //ELIMINANDO SE ESTÃO TOTALMENTE EM UM ÚNICA DIREÇÃO
    if((begin_point_Left && end_point_Left) || (begin_point_Right && end_point_Right) || (begin_point_Down && end_point_Down) || (begin_point_Up && end_point_Up)) return 0;

    //CASOS NÃO TRIVIAIS
    return checkLineAfterNonTrivial(begin_point->x, begin_point->y, end_point->x, end_point->y, mx, my, t);


}

/**
 * @brief The non-trivial cases of selecting a line, checking whether it was selected.
 *
 * @param double begin_x and begin_y for the begin point. end_x and end_y for end point. mx and my coords of mouse click. t the tolerance.
 * @return 1 for true and 0 for false.
 */
int checkLineAfterNonTrivial(double begin_x, double begin_y, double end_x, double end_y, int mx, int my, int t){

    int xmin = mx - t, xmax = mx + t, ymin = my - t, ymax = my + t;
    int x0 = begin_x, y0 = begin_y, x1 = end_x, y1 = end_x;

    if(begin_x < xmin){//Está na esquerda
        x0 = xmin;
        y0 = y0 + ((xmin - x0)*(y1 - y0)/(x1 - x0));
    }
    else if(begin_x > xmax){//Está na direita
        x0 = xmax;
        y0 = y0 + ((xmax - x0)*(y1 - y0)/(x1 - x0));
    }
    else if(begin_y < ymin){//Está abaixo
        y0 = ymin;
        x0 = x0 + ((ymin - y0)*(x1 - x0)/(y1 - y0));
    }
    else if(begin_y > ymax){//Está acima
        y0 = ymax;
        x0 = x0 + ((ymax - y0)*(x1 - x0)/(y1 - y0));
    }

    int begin_point_Left = 0, begin_point_Right = 0, begin_point_Up = 0, begin_point_Down = 0;
    int end_point_Left = 0, end_point_Right = 0, end_point_Up = 0, end_point_Down =0;
    //BEGIN POINT
    if(x0 < xmin) begin_point_Left = 1;
    if(x0 > xmax) begin_point_Right = 1;
    if(y0 < ymin) begin_point_Down = 1;
    if(y0 > ymax) begin_point_Up = 1;
    //END POINT
    if(x1 < xmin) end_point_Left = 1;
    if(x1 > xmax) end_point_Right = 1;
    if(y1 < ymin) end_point_Down = 1;
    if(y1 > ymax) end_point_Up = 1;

    if(begin_point_Left == 0 && begin_point_Right == 0 && begin_point_Down == 0 && begin_point_Up == 0) return 1;
    if(end_point_Left == 0 && end_point_Right == 0 && end_point_Down == 0 && end_point_Up == 0) return 1;

    return 0;
}

/**
 * @brief Select an existing line
 *
 * @param int coords x and y from mouse click
 * @return memory address of existing line vector
 */
Line *selectLine(int x, int y, int t){
    //VETOR GLOBAL DE LINHAS "all_lines"
    int i;
    for(i = 0; i < 1000; i++){
        if(all_lines[i] != NULL){
            if(checkLine(all_lines[i], x, y, t)){
                Line *aux = all_lines[i];
                return aux;
            }
        }
    }
    return NULL;
}

int checkEdgePolygonNoNTrivialCases(Point *p1, Point *p2, int mx, int my){

    double xi = p1->x + ((my - p1->y)*(p2->x - p1->x)/(p2->y - p1->y));

    if(xi > mx) return 1;

    return 0;
}

int checkEdgePolygonSpecialCase(Point *p1, Point *p2, int mx, int my){

    /*CODE*/

    return 0;
}

int checkEdgePolygonCases(Point *p1, Point *p2, int mx, int my){

    //CASO ESPECIAL DO ALGORITMO DO TIRO
    //if(p1->y == p2->y)
    //TRIVIAL CASES
    if(p1->y > my && p2->y > my) return 0;
    if(p1->y < my && p2->y < my) return 0;
    if(p1->x < mx && p2->x < mx) return 0;
    if((p1->x > mx && p2->x > mx) && ((p1->y > my && p2->y < my) || (p1->y < my && p2->y > my))) return 1;

    //NONTRIVIAL CASES
    return checkEdgePolygonNoNTrivialCases(p1, p2, mx, my);
}

int checkPolygon(polygon *p, int mx, int my){
    int count = 0;
    //CASOS TRIVIAIS
    Node *aux = p->head;
    while(aux->next != NULL){
        count += checkEdgePolygonCases(aux->vertex, aux->next->vertex, mx, my);
        aux = aux->next;
    }
    count += checkEdgePolygonCases(aux->vertex, p->head->vertex, mx, my);

    if(count % 2 == 0) return 0;
    else return 1;
}
