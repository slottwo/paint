#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../types/data.h"

#define MAX_LINE 1024
#define DELIMITER ','
int loadPoint(char *src)
{
    int type;
    double x, y;
    sscanf(src, "%d,%lf,%lf", &type, &x, &y);
    pointDataPush(createPointXY(x, y));
}

int loadLine(char *src)
{
    int type;
    double x1, y1, x2, y2;
    sscanf(src, "%d,%lf,%lf,%lf,%lf", &type, &x1, &y1, &x2, &y2);
    lineDataPush(createLineP(createPointXY(x1, y1), createPointXY(x2, y2)));

    return 1;
}

int loadPoly(char *src)
{
    int type, num_points;
    double x, y;

    sscanf(src, "%d,%d", &type, &num_points);

    Poly *poly = createPoly();

    for (int i = 0; i < num_points; i++)
    {
        if (sscanf(src, "%lf,%lf", &x, &y) != 1)
        {
            printf("Load File Error: Invalid type (%d)\n", type);
            return 0;
        }

        src = strchr(src, DELIMITER);

        if (src == NULL)
        {
            break;
        }
        src++;

        polyPush(poly, createPointXY(x, y));
    }

    polygonDataPush(poly);

    return 1;
}

int loadPainting(char *path)
{
    FILE *file;

    file = fopen(path != NULL ? path : "painting.txt", "r");

    if (file == NULL)
    {
        printf("Load File Error: fopen failed\n");
        exit(1);
        return 0;
    }

    char line[MAX_LINE];
    fgets(line, sizeof(line), file);

    int type;
    double x, y;

    while (line != NULL)
    {

        sscanf(line, "%d,", &type);
        switch (type)
        {
        case point_type:
            loadPoint(line);
            break;

        case line_type:
            loadLine(line);
            break;

        case polyline_type:
            /* code */
            break;

        case polygon_type:
            loadPoly(line);
            break;

        default:
            printf("Load File Error: Invalid type (%d)\n", type);
            return 0;
            break;
        }

        fgets(line, sizeof(line), file); // Skip "\n"
    }

    fclose(file);

    return 1;
}