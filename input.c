#include "input.h"
#include <math.h>
#include <GL/freeglut.h>
#include <stdio.h>
#include "render.h"

//teste
#include "save.h"

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
            printf("ok");
            double xis = x;
            double iplison = 300 - y;
            pointDataPush(createPointXY(xis, iplison));
            saveArquive("arquive.txt");
            glutPostRedisplay();
            //glutPostOverlayRedisplay();


        }
    }

}


