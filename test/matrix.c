#include <stdio.h>
#include "../lib/matrix.h"

int main(int argc, char const *argv[])
{
    double A[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double B[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double R[9] = {0};

    for (int i = 0; i < 9; i++)
    {
        printf("%.1f%s", A[i], (i%3 == 2) ? "\n" : " ");
    }

    // for (int i = 0; i < 9; i++)
    // {
    //     printf("%f\n", R[i]);
    // }

    return 0;
}
