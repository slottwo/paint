#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "save.h"
#include "../../types/data.h"

#define MAX 1024
#define DELIMITER ","

int savePoints(FILE *file)
{
    char string_point[7] = "point,";

    NodePoint *aux = DATA.point_head;

    while(aux != NULL)
    {
        char newline[MAX] = "";
        char x_string[50] = "";
        char y_string[50] = "";

        //strcpy(newline, strcat(string_point, DELIMITER));//point,
        strcpy(newline, string_point);

        sprintf(x_string, "%.2f", aux->obj->x);

        strcpy(newline, strcat(newline, x_string)); //point,x
        strcpy(newline, strcat(newline, DELIMITER));//point,x,

        sprintf(y_string, "%.2f", aux->obj->y);

        strcpy(newline, strcat(newline, y_string));//point,x,y
        strcpy(newline, strcat(newline, "\n"));//point,x,y\n

        fputs(newline, file);
        aux = aux->next;
    }

    return 1;
}

int saveLines(FILE *file)
{
    char string_line[6] = "line,";

    NodeLine *aux = DATA.line_head;

    while(aux != NULL)
    {
        char newline[MAX] = "";
        char x_start_string[50] = "";
        char y_start_string[50] = "";
        char x_end_string[50] = "";
        char y_end_string[50] = "";

        //strcpy(newline, strcat(string_line, DELIMITER));//line,
        strcpy(newline, string_line);

        sprintf(x_start_string, "%.2f", aux->obj->start->x);

        strcpy(newline, strcat(newline, x_start_string)); //line, x1
        strcpy(newline, strcat(newline, DELIMITER));//line,x1,

        sprintf(y_start_string, "%.2f", aux->obj->start->y);

        strcpy(newline, strcat(newline, y_start_string));//line,x1,y1
        strcpy(newline, strcat(newline, DELIMITER));//line,x1,y1,

        sprintf(x_end_string, "%.2f", aux->obj->end->x);

        strcpy(newline, strcat(newline, x_end_string));//line,x1,y1,x2
        strcpy(newline, strcat(newline, DELIMITER));//line,x1,y1,x2,

        sprintf(y_end_string, "%.2f", aux->obj->end->y);

        strcpy(newline, strcat(newline, y_end_string)); //line,x1,y1,x2,y2
        strcpy(newline, strcat(newline, "\n"));//line,x1,y1,x2,y2\n

        fputs(newline, file);
        aux = aux->next;
    }

    return 1;
}

int savePolygons(FILE *file)
{
    char string_poly[6] = "poly,";
    int i;

    NodePoly *aux = DATA.polygon_head;

    while(aux != NULL)
    {
        int num_points = polyLength(aux->obj);
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "%d", num_points);
        // char *string_num_points = itoa(num_points, buffer, 10);
        char newline[MAX] = "";
        //strcpy(newline, strcat(string_poly, DELIMITER)); //poly,
        strcpy(newline, string_poly);
        strcpy(newline, strcat(newline, buffer));//poly,num


        NodePoint *actual_point = aux->obj->head;
        while(actual_point != NULL)
        {

            strcpy(newline, strcat(newline, DELIMITER));//poly,num,

            char x_string[50] = "";
            char y_string[50] = "";

            sprintf(x_string, "%.2f", actual_point->obj->x);

            strcpy(newline, strcat(newline, x_string)); //poly,num,x1
            strcpy(newline, strcat(newline, DELIMITER));//poly,num,x1,

            sprintf(y_string, "%.2f", actual_point->obj->y);

            strcpy(newline, strcat(newline, y_string));//poly,num,x1,y1...

            actual_point = actual_point->next;
        }

        strcpy(newline, strcat(newline, "\n"));//poly,num,x1,y1,...,xn,yn\n

        fputs(newline, file);
        aux = aux->next;
    }

    return 1;
}

int savePolylines(FILE *file)
{
    char string_polyline[9] = "polyline,";
    int i;

    NodePoly *aux = DATA.polyline_head;

    while(aux != NULL)
    {
        int num_points = polyLength(aux->obj);
        char buffer[50];
        snprintf(buffer, sizeof(buffer), "%d", num_points);
        // char *string_num_points = itoa(num_points, buffer, 10);
        char newline[MAX] = "";
        strcpy(newline, string_polyline); //polyline,
        //printf("\n1:%s\n", newline);
        //strcpy(newline, strcat(newline, string_num_points));//polyline,num
        //printf("\n2:%s\n", newline);

        NodePoint *actual_point = aux->obj->head;
        while(actual_point != NULL)
        {
            strcpy(newline, strcat(newline, DELIMITER));//polyline,num,

            char x_string[50] = "";
            char y_string[50] = "";

            sprintf(x_string, "%.2f", actual_point->obj->x);

            strcpy(newline, strcat(newline, x_string)); //poly,num,x1
            strcpy(newline, strcat(newline, DELIMITER));//poly,num,x1,

            sprintf(y_string, "%.2f", actual_point->obj->y);

            strcpy(newline, strcat(newline, y_string));//poly,num,x1,y1...

            actual_point = actual_point->next;
        }

        strcpy(newline, strcat(newline, "\n"));//poly,num,x1,y1,...,xn,yn\n

        fputs(newline, file);
        aux = aux->next;
    }

    return 1;
}

int saveArquive(char *file_name)
{
    FILE *file = fopen(file_name, "w");
    //SALVAR OS PONTOS
    savePoints(file);
    //SALVAR AS LINHAS
    saveLines(file);
    //SALVAR OS POL�GONOS
    savePolygons(file);
    //SALVAR AS POLILINHAS
    savePolylines(file);

    return 1;
}




