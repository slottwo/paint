#ifndef SETTINGS_H
#define SETTINGS_H

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGH 768
#define W 800
#define H 600
#define ORTHO_SCALE 1
#define ORTHO_SIZE 0, (ORTHO_SCALE * W / H), 0, ORTHO_SCALE

// default colors

#define BG_COLOR 234.0 / 255, 226.0 / 255, 183.0 / 255, 0
#define POINT_COLOR 0, 48.0 / 255, 73.0 / 255
#define LINE_COLOR 214 / 255, 40 / 255, 40 / 255
#define POLYLINE_COLOR 252.0 / 255, 191.0 / 255, 73.0 / 255
#define POLYGON_COLOR 247.0 / 255, 127.0 / 255, 0

extern double TOL;
extern double CANVAS_SIZE[4];

#endif
