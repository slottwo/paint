#include "selection.h"
#include <stdlib.h>

/**
 * @brief Checks whether a point is present in a tolerance area
 *
 * @param float px and py from point. float mx and my from mouse click and a integer t of tolerance range
 * @return int 1 for true and 0 for false
 */
int checkPoint(float px, float py, float mx, float my, int t){
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
