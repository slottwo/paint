#ifndef EVENTS_H
#define EVENTS_H

enum events
{
    select,
    create,
    move,
    rotate,
    scale
};

extern enum events CURRENT_EVENT;

int selectOperation();
int createOperation();
int moveOperation();
int rotateOperation();
int scaleOperation();

#endif
