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

enum creation_events
{
    point,
    line,
    polygon,
    polyline
};

extern enum events CURRENT_EVENT;

#endif
