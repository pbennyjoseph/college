#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void merge(int *, int , int , int );
void mergeSort(int *, int , int );
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

    mergeSort(arr, 0, number_of_ele);

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

void mergeSort(int *a, int l, int h)
{
    /*The function mergeSort takes 3 parameters
    a[]- The array to be sorted
    l-Starting index of the list
    h-Ending index of the list*/
    if (l < h)
    {
        int mid = (l + h) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, h);
        merge(a, l, mid, h);
    }
}

void merge(int *a, int l, int m, int h)
{
    /*
    The function merge take 4 parameters 
    a-integr array 
    l- is the starting of list 1
    m- is the ending index of list1
        and j+1 is the satring index of list 2
    h- is the ending of list 2
    and the return void
*/
    int b[100];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (j <= h)
    {
        b[k++] = a[j++];
    }
    while (i <= m)
    {
        b[k++] = a[i++];
    }
    for (i = l, j = 0; i <= h; i++, j++)
    {
        a[i] = b[j];
    }
}