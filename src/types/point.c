#include <stdlib.h>
#include <stdio.h>
#include "point.h"

Point *createPointV(double *coords)
{
    if (coords == NULL)
    {
        printf("Point Creation Error: NULL coords received\n");
        exit(1);
        return NULL;
    }

    Point *new_point = (Point *)malloc(sizeof(Point));
    if (new_point == NULL)
    {
        printf("Point Creation Error: malloc fail\n");
        exit(1);
        return NULL;
    }

    new_point->x = coords[0];
    new_point->y = coords[1];

    return new_point;
}

Point *createPointXY(double x, double y) // , double *colors)
{

    Point *new_point = (Point *)malloc(sizeof(Point));
    if (new_point == NULL)
    {
        printf("Point creation error: malloc fail\n");
        exit(1);
        return NULL;
    }

    new_point->x = x;
    new_point->y = y;

    return new_point;
}

/**
 * @brief Get the Point coordinates
 *
 * @param point Point pointer
 * @return double* (x, y)
 */
double *getV(Point *point)
{
    double *coordinates = (double *)malloc(2 * sizeof(double));

    coordinates[0] = point->x;
    coordinates[1] = point->y;

    return coordinates;
}

/**
 * @brief Free memory allocation of a Point object
 *
 * @param point Point pointer
 */
void freePoint(Point *point)
{
    if (point == NULL)
    {
        printf("Point deallocate error: NULL pointer received\n");
        exit(1);
    }

    // free(Point->colors);
    free(point);

    point = NULL;
}