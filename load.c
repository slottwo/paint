#include <stdio.h>
#include <string.h>

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
    campo = strtok(NULL, DELIMITER);

    printf("x: %s\t", campo);
    campo = strtok(NULL, DELIMITER);
    printf("y: %s\n", campo);

    return 1;
}

int loadLine(char *campo)
{
    campo = strtok(NULL, DELIMITER);
    printf("x1: %s\t", campo);
    campo = strtok(NULL, DELIMITER);
    printf("y1: %s\n", campo);

    campo = strtok(NULL, DELIMITER);
    printf("x2: %s\t", campo);
    campo = strtok(NULL, DELIMITER);
    printf("y2: %s\n", campo);

    return 1;
}

int loadPoly(char *campo)
{
    campo = strtok(NULL, DELIMITER);
    int i, num_points = atoi(campo);

    for(i = 0; i < num_points; i++)
    {
        campo = strtok(NULL, DELIMITER);
        printf("x%d: %s\t", i+1, campo);
        campo = strtok(NULL, DELIMITER);
        printf("y%d: %s\n", i+1, campo);
    }

    return 1;
}

int loadPolyline(char *campo)
{
    campo = strtok(NULL, DELIMITER);
    int i, num_points = atoi(campo);

    for(i = 0; i < num_points; i++)
    {
        campo = strtok(NULL, DELIMITER);
        printf("x%d: %s\t", i+1, campo);
        campo = strtok(NULL, DELIMITER);
        printf("y%d: %s\n", i+1, campo);
    }

    return 1;
}
