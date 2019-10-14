#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heapSort(int *, int);
void heapify(int *, int, int);
void displayArray(int *, int);
void sway(int *, int *);

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

    heapSort(arr, number_of_ele);

    printf("Elements after sorting\n");
    displayArray(arr, number_of_ele);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
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

void heapify(int *arr, int root, int endindex)
{
    int maximum = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < endindex && arr[left] > arr[maximum])
    {
        maximum = left;
    }

    if (right < endindex && arr[right] > arr[maximum])
    {
        maximum = right;
    }

    if (maximum != root)
    {
        swap(arr + maximum, arr + root);
        heapify(arr, maximum, endindex);
    }
}

void heapSort(int *arr, int n)
{
    int i, j;
    for (i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, i, n);
    }
    for (j = n - 1; j >= 0; --j)
    {
        swap(arr, arr + j);
        heapify(arr, 0, j);
    }
}