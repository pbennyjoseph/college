/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void merge(int *, int, int, int);
void mergeSort(int *, int, int);
void displayArray(int *, int);

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

    mergeSort(arr, 0, number_of_ele - 1);

    printf("Elements after sorting\n");
    displayArray(arr, number_of_ele);
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

void mergeSort(int *arr, int left, int right)
{

    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int *arr, int left, int middle, int right)
{
    int auxilliary[20];
    int i = left, j = middle + 1, k = 0;
    while (i <= middle && j <= right)
    {
        if (arr[i] < arr[j])
        {
            auxilliary[k++] = arr[i++];
        }
        else
        {
            auxilliary[k++] = arr[j++];
        }
    }

    while (j <= right)
    {
        auxilliary[k++] = arr[j++];
    }
    while (i <= middle)
    {
        auxilliary[k++] = arr[i++];
    }

    for (i = left, j = 0; i <= right; i++, j++)
    {
        arr[i] = auxilliary[j];
    }
}