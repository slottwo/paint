#include "input.h"
#include <math.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "render.h"

//teste
#include "save.h"
#include "selection.h"

int KEYS[256] = {0};
int keySpecialStates[256] = {0};

void keyPressed(unsigned char key, int x, int y)
{
    KEYS[key] = 1;
}

void keyReleased(unsigned char key, int x, int y)
{
    KEYS[key] = 0;
}

void keyOperations()
{
    if (KEYS['a'])
    {
        printf("a pressionado!");
    }
    if (KEYS['s'])
    {
        printf("Option select!");
    }
}

void keySpecial (int key, int x, int y) {

}

void keySpecialUp (int key, int x, int y) {

}

void keySpecialOperations(void) {
    if (keySpecialStates[GLUT_KEY_LEFT]) {
        printf("Esquerda");
    }
}

void onMouseClick(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        printf("x:%d y:%d\n", x, y);
        printf("%d\n", 'a');
        printf("%d\n", KEYS['a']);
        if(KEYS['a'] == 1){
            //printf("ok");
            double xis = x;
            double iplison = 300 - y;
            pointDataPush(createPointXY(xis, iplison));
            saveArquive("arquive.txt");
            glutPostRedisplay();
            //glutPostOverlayRedisplay();


        }
        if(KEYS['s'] == 1)
        {
            //printf("s ok\n");
            double xis = x;
            double iplison = 300 - y;
            NodePoint *p_s = NULL;
            NodeLine *l_s = NULL;
            NodePoly *poly_s = NULL;
            NodePoly *polyline_s = NULL;

            //SELECTED.point = selectPoint(xis, iplison, 2.5);
            p_s = selectPoint(xis, iplison, 2.5);
            //SELECTED.line = selectLine(xis, iplison, 2.5);
            l_s = selectLine(xis, iplison, 2.5);
            //SELECTED.polygon = selectPolygon(xis, iplison);
            poly_s = selectPolygon(xis, iplison);
            //SELECTED.polyline = selectPolyline(xis, iplison, 2.5);
            polyline_s = selectPolyline(xis, iplison, 2.5);
            //printf("s_polyline ok\n");

            if(p_s != NULL)
            {
                printf("point selected!\n");
                printf("x: %.2f\t", p_s->obj->x);
                printf("y: %.2f\n", p_s->obj->y);
            }
            if(l_s != NULL)
            {
                printf("line selected!\n");
                printf("start point:\n");
                printf("x: %.2f\t", l_s->obj->start->x);
                printf("y: %.2f\n", l_s->obj->start->y);
                printf("end point:\n");
                printf("x: %.2f\t", l_s->obj->end->x);
                printf("y: %.2f\n", l_s->obj->end->y);
            }
            if(poly_s != NULL)
            {
                printf("poly selected!\n");
                printf("first point:\n");
                printf("x:%.2f\t", poly_s->obj->head->obj->x);
                printf("y:%.2f\n", poly_s->obj->head->obj->y);
            }
            if(polyline_s != NULL)
            {
                printf("polyline selected!\n");
                printf("first point:\n");
                printf("x:%.2f\t", polyline_s->obj->head->obj->x);
                printf("y:%.2f\n", polyline_s->obj->head->obj->y);
            }
        }
    }

}


