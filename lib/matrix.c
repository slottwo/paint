#include "stdlib.h"
#include "matrix.h"
#include "objects.h"

/**
 * @brief Multiplies 3*3 square matrices (R = A * B)
 *
 * @param A First double[9] vector
 * @param B Second double[9] vector
 * @param R Resulting double[9] vector
 */
void multiply(double *A, double *B, double *R)
{
    if (A == NULL | B == NULL)
        exit(1);

    if (R == NULL)
        R = (double *)calloc(9, sizeof(double));
    else
        for (int i = 0; i < 9; i++)
            R[i] = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                R[3 * i + j] += A[3 * i + k] * B[3 * k + j];
}

/**
 * @brief Apply transformation T to point P
 *
 * @param P Point to be transformed (double[2])
 * @param T Transformation matrix (double[9])
 */
void transform(Point *P, double *T)
{
    if (P == NULL | T == NULL)
        exit(1);

    *P[0] = *P[0] * T[0] + *P[1] * T[1] + T[2];
    *P[0] = *P[0] * T[3] + *P[1] * T[4] + T[5];
}
