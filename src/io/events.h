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

extern enum events EVENT;

enum operation
{
    OP_ESC,
    OP_INIT,
    OP_CLICK,
    OP_DONE,
    OP_REDO
};

// struct eventLog
// {
// };

// struct eventLog LAST_Event;

int selectEvent(int, double, double);
int createEvent(int, double, double);
int moveEvent(int, double, double);
int rotateEvent(int, double, double);
int scaleEvent(int, double, double);
int deleteEvent(int);

#endif
