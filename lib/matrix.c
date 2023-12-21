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
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                R[3 * i + j] += A[3 * i + k] * B[3 * k + j];
            }
        }
    }
}

/**
 * @brief Apply transfomation T to point P
 * 
 * @param P 
 * @param T 
 */
void transform(Point *P, double *T)
{
    /* code */
}
