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

int selectOperation(int, int);
int createOperation(int, int);
int moveOperation(int, int);
int rotateOperation(int, int);
int scaleOperation(int, int);

#endif
