typedef double[2] Point;

typedef struct
{
    Point *vertex;
    Node *next;
} Node;

typedef struct
{
    // Point *center;
    Node *head;
} Polygon;

Point *createPoint(float, float);
Polygon *createPolygon(float**, int);
void appendPoint(Polygon *, Point *);
void freePolygon(Polygon *);

// typedef Point[2] Line;

// typedef struct
// {
//     // Node_Line *head;
// } Line_Strip;

// Line *createLine(float[2][2]);
