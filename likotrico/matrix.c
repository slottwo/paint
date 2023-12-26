#include <stdlib.h>
#include <math.h>
#include "matrix.h"

/**
 * @brief Multiply two 3*3 square matrices
 *
 * @param A First double[9] vector
 * @param B Second double[9] vector
 * @return double* – Resulting vector
 */
double *generic_multiply(double *A, double *B)
{
    if ((A == NULL) | (B == NULL))
        exit(1);

    double *R = (double *)calloc(9, sizeof(double));

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                R[3 * i + j] += A[3 * i + k] * B[3 * k + j];

    return R;
}

// a b c   g h i   ag + bj | ah + bk | ai + bl
// d e f x j k l = dg + ej | dh + bk | di + el
// 0 0 1   0 0 1      0    |    0    |    1

/**
 * @brief Multiply transformation matrices optimally
 *
 * @param A First double[9] vector
 * @param B Second double[9] vector
 * @return double* – Resulting vector
 */
double *optimized_multiply(double *A, double *B)
{
    double *R = (double *)calloc(9, sizeof(double));

    R[0] = A[0] * B[0] + A[1] * B[3];
    R[1] = A[0] * B[1] + A[1] * B[4];
    R[2] = A[0] * B[2] + A[1] * B[5];
    R[3] = A[3] * B[0] + A[4] * B[3];
    R[4] = A[3] * B[1] + A[4] * B[4];
    R[5] = A[3] * B[2] + A[4] * B[5];

    return R;
}

/**
 * @brief Apply transformation T to point P
 *
 * @param P Point to be transformed (double[2])
 * @param T Transformation matrix (double[9])
 */
void transform(Point *P, double *T)
{
    if ((P == NULL) | (T == NULL)) exit(1);

    int x = P->x * T[0] + P->y * T[1] + T[2];
    int y = P->x * T[3] + P->y * T[4] + T[5];

    P->x = x;
    P->y = y;
}

double *get_rotate_matrix(double angle)
{
    double *R = (double *)calloc(9, sizeof(double));
    R[0] = cos(angle);
    R[1] = sin(angle);
    R[3] = -sin(angle);
    R[4] = cos(angle);
    R[8] = 1;
    return R;
}

double *get_scale_matrix(double x, double y)
{
    double *R = (double *)calloc(9, sizeof(double));
    R[0] = x;
    R[4] = y;
    R[8] = 1;
    return R;
}

double *get_translate_matrix(double x, double y)
{
    double *R = (double *)calloc(9, sizeof(double));
    R[2] = x;
    R[5] = y;
    R[8] = 1;
    return R;
}

