/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayArray(int *, int);
void swap(int *, int *);
void insertionSort(int *, int);

int main()
{
    int number_of_ele, *itr;

    scanf("%d", &number_of_ele);
    int *arr = (int *)calloc(number_of_ele, sizeof(int));
    // read elements as input
    for (itr = arr; itr < arr + number_of_ele; ++itr)
    {
        scanf("%d", itr);
    }

    printf("Elements before sorting\n");
    displayArray(arr, number_of_ele);

    insertionSort(arr, number_of_ele);

    printf("Elements after sorting\n");
    displayArray(arr, number_of_ele);
    return 0;
    return 0;
}

void displayArray(int *arr, int n)
{
    int *itr;
    for (itr = arr; itr < arr + n; ++itr)
    {
        printf("%d ", *itr);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementation of Insertion sort.
void insertionSort(int *arr, int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; ++i)
    {
        k = i;
        j = i + 1;
        while (k >= 0 && arr[j] < arr[k])
        {
            swap(arr + j, arr + k);
            --k;
            --j;
        }
    }
}