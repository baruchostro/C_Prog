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

int * CopyArray(int * orig, size_t size)
{
    size_t index = 0;
    int * newArr = malloc(size * sizeof(int));
    if(newArr == NULL)
    {
        return NULL;
    }
    for(index = 0; index < size; index++)
    {
        newArr[index] = orig[index];
    }
    return newArr;
}


int * RemoveVal(int * arr, size_t size, int val)
{
    size_t index = 0;
    size_t newSize = size -1;
    int * newArr = CopyArray(arr, size);
    for(index = 0; index < size; index++)
    {
        if(arr[index] == val)
        {
            for(; index < size; index++)
            {
                newArr[index] = newArr[index+1];
            }
            newArr = realloc(newArr, newSize * sizeof(int));
            if(newArr == NULL)
            {
                return NULL;
            }
            return newArr;
        }
    }
    return NULL;
}


void FindSubsetsRec(int * origArr, size_t origSize,  int * newArr, size_t newSize)
{
    size_t index = 0;
    //size_t newArrSize = sizeof (newArr)/sizeof (int);
    if(origSize == 0)
    {
        return;
    }
    for(index = 0; index < origSize; index++)
    {
        AddVal(newArr, newSize, origArr[index]);
        PrintArr(newArr, newSize +1);
        FindSubsetsRec(RemoveVal(origArr, origSize, origArr[index]), origSize -1, newArr, newSize +1);
    }
    free(origArr);
    return;
}

void FindSubsets(int * origArr, size_t origSize)
{
    int * newArr = malloc(sizeof(int));
    size_t newSize = 0;
    PrintArr(newArr, newSize);
    FindSubsetsRec(origArr, origSize, newArr, newSize);
    free(newArr);
}
