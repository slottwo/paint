#include "input.h"
#include <GL/glut.h>
#include <stdio.h>

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

// if necessary, create private functions for a specific key
void onMouseClick(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        printf("x:%d y:%d\n", x, y);
        printf("%d\n", 'a');
        printf("%d\n", KEYS['a']);
        if(KEYS['a'] == 1){
            double xis = x;
            double iplison = y;
            renderPoint(createPointXY(xis, iplison));
            //glutPostRedisplay();
        }
    }

}


