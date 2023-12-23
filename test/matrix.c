#include <stdio.h>
#include "../lib/matrix.h"

void printM(double *matrix)
{
    for (int i = 0; i < 9; i++)
    {
        printf("%.0f%s", matrix[i], (i % 3 == 2) ? "\n" : " ");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    double I[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    double t = 0;
    double R[9] = {cos(t), -sin(t), 0, cos(t), sin(t), 0, 0, 0, 1};
    double S[9] = {5, 0, 0, 0, 5, 0, 0, 0, 1};
    double T[9] = {1, 0, -5, 0, 1, 8, 0, 0, 1};
    double F[9] = {0};

    // printM(R);

    printM(I);
    printM(T);

    generic_multiply(I, T, F);

    printM(F);

    return 0;
}
