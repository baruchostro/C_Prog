#include <stdio.h>
#include <stdlib.h>
#include "subsets.h"
#define N 3

int main()
{
    int * arr = malloc(sizeof(int) * N);
    arr[0] = 1;
    arr[1] = 3;
    arr[2] = 5;
    int * newArr = NULL;
    FindSubsets(arr, N, newArr, 0);
    return 0;
}