#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int binarySearch(int *arr, int size, int key)
{
    int lo = 0, hi = size - 1, mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2; // To avoid integer overflow.
        if (arr[mid] < key)
            lo = mid + 1;
        else if (arr[mid] > key)
            hi = mid - 1;
        else
            return mid;
    }
    return -1;
}

int recursiveBS(int *arr, int lo, int hi, int key)
{
    int mid = lo + (hi-lo)/2;

    if(lo > hi) return -1; // base case
    
    if(arr[mid] > key){
        return recursiveBS(arr,lo,mid-1,key);
    }
    else if(arr[mid] < key){
        return recursiveBS(arr,mid+1,hi,key);
    }
    else return mid;
}

int main()
{
    int n, key, result, *itr;

    printf("Enter number of elements\n");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));

    printf("Enter elements\n");
    for (itr = arr; itr < arr + n; ++itr)
    {
        scanf("%d", itr);
    }
    scanf("%d", &key);

    result = recursiveBS(arr, 0,n, key);

    if (result == -1)
    {
        printf("Element '%d' not found\n", key);
    }
    else
    {
        printf("Element '%d' found at index %d\n", key, result);
    }

    free(arr);
    return 0;
}
// Enter number of elements
// 15
// Enter elements
// 6 13 14 25 33 43 51 53 64 72 84 93 95 96 97
// 33
// Element '33' found at index 4

// Enter number of elements
// 15
// Enter elements
// 6 13 14 25 33 43 51 53 64 72 84 93 95 96 97
// 90
// Element '90' not found