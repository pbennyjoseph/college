#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayArray(int *, int);
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

int partition(int * arr, int lo,int hi){
	int i = lo;
	int j = hi+1;
	int v = arr[lo];
	while(1){
		while(arr[++i] < v)
			if(i==hi) break;
		while(v < arr[--j])
			if(j==lo) break;
		if(i>=j) break;
		swap(arr+i,arr+j);
	}
	swap(arr+lo,arr+j);
	return j;
}

// QuickSort algorithm implementation.
void recursiveQS(int *arr, int left, int right)
{
    int i, j;
	if(right <= left) return;
	i = partition(arr,left,right);
	recursiveQS(arr, left, i-1);
	recursiveQS(arr, i+1, right);
}