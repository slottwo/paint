#ifndef EVENTS_H
#define EVENTS_H

enum events
{
    EVENT_SELECT,
    EVENT_CREATE,
    EVENT_MOVE,
    EVENT_ROTATE,
    EVENT_SCALE
};

extern enum events CURRENT_EVENT;

enum operation
{
    OP_ESC,
    OP_INIT,
    OP_CLICK,
    OP_DONE,
    OP_REDO
};

int selectOperation(int, int);
int createOperation(enum operation, int, int);
int moveOperation(int, int);
int rotateOperation(int, int);
int scaleOperation(int, int);

#endif
