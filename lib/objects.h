typedef struct
{
    float x;
    float y;
} Point;

typedef struct
{
    Point *vertexes[2];
} Line;

typedef struct
{
    Point *center;
    Point **vertexes;
} Polygon;


Point *createPoint(float, float);
Line *createLine(float[2][2]);
Polygon *createPolygon(float**, int);
