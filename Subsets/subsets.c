#include <stdio.h>
#include <stdlib.h>
#include "subsets.h"


void PrintArr(int * arr, size_t size)
{
    size_t index = 0;
    printf("{");
    for(index = 0; index < size; index++)
    {
        printf("%d;", arr[index]);
    }
    printf("}\n");
}

int * AddVal(int * arr, size_t size, int val)
{
    size_t newSize = size + 1;
    arr = realloc(arr, newSize * sizeof(int));
    if(arr == NULL)
    {
        return NULL;
    }
    arr[size] = val;
    return arr;
}

int RemoveVal(int * arr, size_t size, int val)
{
    size_t index = 0;
    size_t newSize = size -1;
    for(index = 0; index < size; index++)
    {
        if(arr[index] == val)
        {
            for(; index < size; index++)
            {
                arr[index] = arr[index+1];
            }
            arr = realloc(arr, newSize * sizeof(int));
            if(arr == NULL)
            {
                return 1;
            }
            return 0;
        }
    }
    return 1;
}

void FindSubsets(int * origArr, size_t origSize,  int * newArr, size_t newSize)
{
    size_t index = 0;
    //size_t origArrSize = sizeof(origArr) / sizeof(int);
    //size_t newArrSize = sizeof (newArr)/sizeof (int);
    if(origSize == 0)
    {
        PrintArr(origArr, origSize);
        return;
    }
    for(index = 0; index < origSize; index++)
    {
        AddVal(newArr, newSize, origArr[index]);
        PrintArr(newArr, newSize);
        RemoveVal(origArr, origSize, origArr[index]);
        FindSubsets(origArr, origSize -1, newArr, newSize +1);
    }
    return;
}
