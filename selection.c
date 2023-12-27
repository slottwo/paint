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
Point *selectPoint(int x, int y){
    //GLOBAL VECTOR "all_points"
    int i;
    for(i = 0; i < 1000; i++){
        if(all_points[i] != NULL){
            if(checkPoint(all_points[i]->x, all_points[i]->y, x, y, 10)){
                Point *aux = all_points[i];
                return aux;
            }
        }
    }
    return NULL;
}



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
}
