typedef double *Point;

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

Point *createPoint(double, double);
Polygon *createPolygon();
void appendPoint(Polygon *, Point *);
void freePolygon(Polygon *);

// typedef Point[2] Line;

// typedef struct
// {
//     // Node_Line *head;
// } Line_Strip;

// Line *createLine(float[2][2]);
