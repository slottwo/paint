#include <math.h>
#include <stdlib.h>

#include "geometry.h"

/**
 * @brief The distance between two points.
 *
 * @param The coords of point 1 and point 2.
 * @return The distance between point 1 and 2.
 */
double distanceBetweenTwoPoints(double x1, double y1, double x2, double y2)
{
    double num1 = x1 - x2;
    double num2 = y1 - y1;
    return sqrt(pow(num1, 2) + pow(num2, 2));
}

/**
 * @brief Calculates the center point of the polygon.
 *
 * @param The Poly object.
 * @return Array of legth two. First, the x coord. After, the y coord.
 */
double *centerPolygon(Poly *poly)
{
    double acum_x = 0, acum_y = 0, count_points = 0;

    NodePoint *aux = poly->head;
    while(aux != NULL)
    {
        count_points++;
        acum_x += aux->obj->x;
        acum_y += aux->obj->y;
        aux = aux->next;
    }

    double *result;
    result = (double*)malloc(sizeof(double)*2);

    result[0] = acum_x/count_points;
    result[1] = acum_y/count_points;

    return result;
}

/**
 * @brief Angle between two points relative to the center of a Poly object.
 *
 * @param The coords of point 1, point 2 and the Poly object.
 * @return The angle in radian.
 */
double anglePoly(double x1, double y1, double x2, double y2, Poly *poly)
{
    double *center_point;
    center_point = (double*)malloc(sizeof(double)*2);
    center_point = centerPolygon(poly);

    double distance_p1_p2, distance_p1_c, distance_p2_c;
    distance_p1_p2 = distanceBetweenTwoPoints(x1, y1, x2, y2);
    distance_p1_c = distanceBetweenTwoPoints(x1, y1, center_point[0], center_point[1]);
    distance_p2_c = distanceBetweenTwoPoints(x2, y2, center_point[0], center_point[1]);

    double num = pow(distance_p1_p2, 2) - pow(distance_p1_c, 2) - pow(distance_p2_c, 2) + 2*distance_p1_c*distance_p2_c;

    return acos(num);
}

/**
 * @brief Calculates the center point of the line.
 *
 * @param The Line object.
 * @return Array of legth two. First, the x coord. After, the y coord.
 */
double *centerLine(Line *line)
{
    double *result;
    result = (double*)malloc(sizeof(double)*2);

    result[0] = (line->start->x + line->end->x)/2;
    result[1] = (line->start->y + line->end->y)/2;

    return result;
}

/**
 * @brief Calculates the center point of the line.
 *
 * @param The Line object.
 * @return Array of legth two. First, the x coord. After, the y coord.
 */
double *angleLine(double x1, double y1, double x2, double y2, Line *line)
{
    double *center_point;
    center_point = (double*)malloc(sizeof(double)*2);
    center_point = centerLine(line);

    double distance_p1_p2, distance_p1_c, distance_p2_c;
    distance_p1_p2 = distanceBetweenTwoPoints(x1, y1, x2, y2);
    distance_p1_c = distanceBetweenTwoPoints(x1, y1, center_point[0], center_point[1]);
    distance_p2_c = distanceBetweenTwoPoints(x2, y2, center_point[0], center_point[1]);

    double num = pow(distance_p1_p2, 2) - pow(distance_p1_c, 2) - pow(distance_p2_c, 2) + 2*distance_p1_c*distance_p2_c;

    double *result;
    result = (double*)malloc(sizeof(double));
    result[0] = acos(num);

    return result;
}
