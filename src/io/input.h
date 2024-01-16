#ifndef INPUT_H
#define INPUT_H

enum events
{
    EVENT_SELECT,
    EVENT_CREATE,
    EVENT_MOVE,
    EVENT_ROTATE,
    EVENT_SCALE
};

extern enum events CURRENT_EVENT;

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
