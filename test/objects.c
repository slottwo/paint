#include <stdio.h>
#include "../lib/render.h"

int main(int argc, char const *argv[])
{
    Polygon *p = createPolygon();
    polygonPush(p, createPointXY(1.0,2.0));
    double *v = getVertex(p->head);
    printf("%.1f %.1f\n", v[0], v[1]);
    return 0;
}
