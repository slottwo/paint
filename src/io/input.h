#ifndef INPUT_H
#define INPUT_H

extern int KEYS[256];

void keyPressed(unsigned char, int, int);
void keyReleased(unsigned char, int, int);
void keyOperations();

#endif