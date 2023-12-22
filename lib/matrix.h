#include "objects.h"

void generic_multiply(double *, double *, double *);
void optimized_multiply(double *, double *, double *);
void transform(Point *, double *);
double *get_rotate_matrix(double);
double *get_scale_matrix(double, double);
double *get_translate_matrix(double, double);
