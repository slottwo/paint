#include <stdio.h>
#include "lib/matrix.c"

int main(int argc, char const *argv[])
{
    double A[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double B[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double R[9] = {0};

    for (int i = 0; i < 9; i++)
    {
        printf("%d\n", R[i]);
    }

    return 0;
}
