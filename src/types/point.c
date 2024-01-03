#include <stdlib.h>
#include <stdio.h>
#include "point.h"

Point *createPoint(double *coords) // , double *colors)
{
    if (coords == NULL)
    {
        printf("Point Creation Error: NULL coords received\n");
        exit(1);
        return NULL;
    }

    Point *point = (Point *)malloc(sizeof(Point));
    if (point == NULL)
    {
        printf("Point creation error: malloc fail\n");
        exit(1);
        return NULL;
    }

    point->x = coords[0];
    point->y = coords[1];

    return point;
}

Point *createPointXY(double x, double y) // , double *colors)
{

    Point *point = (Point *)malloc(sizeof(Point));
    if (point == NULL)
    {
        printf("Point creation error: malloc fail\n");
        exit(1);
        return NULL;
    }

    point->x = x;
    point->y = y;

    return point;
}

/**
 * @brief Get the point coordinates
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

    // free(point->colors);
    free(point);

    point = NULL;
}