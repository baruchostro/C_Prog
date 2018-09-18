#include <stdio.h>
#include <stdlib.h>
#include "subsets.h"


void PrintArr(int * arr, size_t size)
{
    size_t index = 0;
    printf("{");
    for(index = 0; index < size; index++)
    {
        if(index != 0)
        {
            printf(";");
        }
        printf("%d", arr[index]);
    }
    printf("}\n");
}

int AddVal(int * arr, size_t size, int val)
{
    size_t newSize = size + 1;
    arr = realloc(arr, newSize * sizeof(int));
    if(arr == NULL)
    {
        return 1;
    }
    arr[size] = val;
    return 0;
}

void FindSubsetsRec(int * origArr, size_t origSize,  int * newArr, size_t newSize, size_t index)
{
    //size_t newArrSize = sizeof (newArr)/sizeof (int);
    if(newSize == 0)
    {
        PrintArr(newArr, newSize);
    }
    for(; index < origSize; index++)
    {
        AddVal(newArr, newSize, origArr[index]);
        PrintArr(newArr, newSize +1);
        FindSubsetsRec(origArr, origSize, newArr, newSize +1, index +1);
    }
    return;
}

void FindSubsets(int * origArr, size_t origSize)
{
    int * newArr = malloc(sizeof(int));
    size_t newSize = 0;
    size_t index = 0;
    FindSubsetsRec(origArr, origSize, newArr, newSize, index);
    free(newArr);
}
