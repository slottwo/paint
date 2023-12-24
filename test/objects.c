#include <stdio.h>
#include "../lib/render.h"

int main(int argc, char const *argv[])
{
    Polygon *poly = createPolygon();

    polygonPush(poly, createPointXY(1.0, 2.0));
    polygonPush(poly, createPointXY(2.0, 2.0));
    polygonPush(poly, createPointXY(1.0, 3.0));

    double *v = getV(poly->head->vertex);

    printf("- head: %.1f %.1f\n", v[0], v[1]);

    printf("- len: %d\n", polygonLength(poly));

    printf("- 1st 5 points:\n");

    Point *point;
    for (int i = 0; i < 5; i++)
    {
        point = polygonPop(poly);
        if (point)
        {
            v = getV(point);
            printf("\t%.1f %.1f\n", v[0], v[1]);
            freePoint(point);
        }
        else
        {
            printf("\tNo more points...\n");
        }
    }



    return 0;
}
