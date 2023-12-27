#ifndef INPUT_H
#define INPUT_H

extern int KEYS[256];
extern int keySpecialStates[256];

void keyPressed(unsigned char, int, int);
void keyReleased(unsigned char, int, int);
void keyOperations();
void keySpecial(int, int, int);
void keySpecialUp(int, int, int);
void keySpecialOperations(void);
void onMouseClick(int, int, int, int);

#endif
