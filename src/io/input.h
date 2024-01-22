#ifndef INPUT_H
#define INPUT_H

#define KEY_ENTER 13
#define KEY_ESCAPE 27
#define KEY_DELETE 127

void keyPressed(unsigned char, int, int);
void keyReleased(unsigned char, int, int);

void keySpecialPressed(int, int, int);
void keySpecialReleased(int, int, int);

void onMouseClick(int, int, int, int);

#endif
