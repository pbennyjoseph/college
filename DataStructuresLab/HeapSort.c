#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heapSort(int *, int);
void heapify(int *, int, int);
void displayArray(int *, int);
void swap(int *, int *);

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

// fix heap property from root to all children till endindex.
void heapify(int *arr, int root, int endindex)
{
    int maximum = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    // check if left index is in range and
    // if leftchild is greater than root.
    if (left < endindex && arr[left] > arr[maximum])
    {
        maximum = left;
    }

    // check if right index is in range and
    // if rightchild is greater than root.
    if (right < endindex && arr[right] > arr[maximum])
    {
        maximum = right;
    }

    // fix heap property by replacing root with maximum
    // of the two children
    if (maximum != root)
    {
        swap(arr + maximum, arr + root);

        // Now fix heap property in the maximum subtree
        heapify(arr, maximum, endindex);
    }
}

void heapSort(int *arr, int n)
{
    int i, j;
    // Build a max-heap
    for (i = n / 2 - 1; i >= 0; --i)
    {
        heapify(arr, i, n);
    }

    // Extract top element and insert at the end.
    // Now that end element is inplace, --j.
    // fix heap property after removing the max element.
    for (j = n - 1; j >= 0; --j)
    {
        swap(arr, arr + j);

        // jth element is sorted.
        // fix heap property till j-1
        heapify(arr, 0, j);
    }
}