#include "matrix.h"

void multiply(float *A, float *B, float *R)
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
