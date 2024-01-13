#include <stdio.h>
#include <string.h>

#include "data.h"

#define MAX_LINE 1024
#define DELIMITER ","

int loadArquive(char *file_name)
{
    FILE *file = fopen(file_name, "r");

    if(file == NULL)
    {
        printf("Fail to load the arquive");
        return 0;
    }

    char linha[MAX_LINE];
    char *campo;

    while(fgets(linha, MAX_LINE, file) != NULL)
    {

        campo = strtok(linha, DELIMITER);

        while(campo != NULL)
        {
            printf("%s\n", campo);
            //printf("linha:%s\n", linha);

            if(strcmp(linha, "point") == 0) loadPoint(campo);
            if(strcmp(linha, "line") == 0) loadLine(campo);
            if(strcmp(linha, "poly") == 0) loadPoly(campo);
            if(strcmp(linha, "polyline") == 0) loadPolyline(campo);

            campo = strtok(NULL, DELIMITER);
        }
    }

    return 1;
}

int loadPoint(char *campo)
{
    char *ptr;
    double x, y;

    campo = strtok(NULL, DELIMITER);
    printf("x: %s\t", campo);
    x = atoi(campo);


    campo = strtok(NULL, DELIMITER);
    printf("y: %s\n", campo);
    y = atoi(campo);

    pointDataPush(createPointXY(x, y));

    return 1;
}

int loadLine(char *campo)
{
    char *ptr;
    double x1, y1, x2, y2;

    campo = strtok(NULL, DELIMITER);
    printf("x1: %s\t", campo);
    x1 = atoi(campo);

    campo = strtok(NULL, DELIMITER);
    printf("y1: %s\n", campo);
    y1 = atoi(campo);

    campo = strtok(NULL, DELIMITER);
    printf("x2: %s\t", campo);
    x2 = atoi(campo);

    campo = strtok(NULL, DELIMITER);
    printf("y2: %s\n", campo);
    y2 = atoi(campo);

    lineDataPush(createLineP(createPointXY(x1, y1), createPointXY(x2, y2)));

    return 1;
}

int loadPoly(char *campo)
{
    campo = strtok(NULL, DELIMITER);
    int i, num_points = atoi(campo);
    double x, y;

    Poly *p = createPoly();

    for(i = 0; i < num_points; i++)
    {
        campo = strtok(NULL, DELIMITER);
        printf("x%d: %s\t", i+1, campo);
        x = atoi(campo);

        campo = strtok(NULL, DELIMITER);
        printf("y%d: %s\n", i+1, campo);
        y = atoi(campo);

        polyPush(p, createPointXY(x, y));

    }

    polygonDataPush(p);

    return 1;
}

int loadPolyline(char *campo)
{
    campo = strtok(NULL, DELIMITER);
    int i, num_points = atoi(campo);
    double x, y;

    Poly *p = createPoly();

    for(i = 0; i < num_points; i++)
    {
        campo = strtok(NULL, DELIMITER);
        printf("x%d: %s\t", i+1, campo);
        x = atoi(campo);

        campo = strtok(NULL, DELIMITER);
        printf("y%d: %s\n", i+1, campo);
        y = atoi(campo);

        polyPush(p, createPointXY(x, y));
    }

    polylineDataPush(p);

    return 1;
}
