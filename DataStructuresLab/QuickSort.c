#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayArray(int *, int);
// void quickSort(int *arr, );
void swap(int *, int *);

void recursiveQS(int *, int, int);

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

    recursiveQS(arr, 0, number_of_ele - 1);

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

// QuickSort algorithm implementation.
void recursiveQS(int *arr, int left, int right)
{
    int i, j, pivot = arr[left];
    if (left < right)
    {
        i = left + 1;
        j = right;
        do
        {
            while (i<=j && arr[i] < pivot )
                ++i;
            while (i <= j && arr[j] > pivot )
                --j;
            if (i < j)
            {
                swap(arr + i, arr + j);
            }
        } while (i < j);

        swap(arr + left, arr + j);

        recursiveQS(arr, left, i-1);
        recursiveQS(arr, i+1, right);
    }
}