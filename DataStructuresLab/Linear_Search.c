/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int i, key = 40;
    for (int i = 0; i < 5; ++i)
    {
        if (arr[i] == key)
        {
            printf("Key Found at index %d\n", i);
            break;
        }
    }
    return 0;
}