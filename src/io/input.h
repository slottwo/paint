#ifndef INPUT_H
#define INPUT_H

#define CUSTOM_KEY_ESC 27

extern int KEYS[256];
extern int SP_KEYS[256];

void keyPressed(unsigned char, int, int);
void keyReleased(unsigned char, int, int);
void keyOperations();

void keySpecialPressed(int, int, int);
void keySpecialReleased(int, int, int);
void keySpecialOperations();

void onMouseClick(int, int, int, int);

#endif
