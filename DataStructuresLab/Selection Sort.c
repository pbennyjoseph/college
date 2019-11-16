/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void selectionSort(int* ,int );
void displayArray(int *, int );

int main(){
	int number_of_ele,*itr;
	
	scanf("%d",&number_of_ele);
	int * arr = (int *) calloc(number_of_ele,sizeof(int));
	// read elements as input
	for(itr = arr;itr < arr+number_of_ele ; ++itr){
		scanf("%d",itr);
	}

	printf("Elements before sorting\n");
	displayArray(arr,number_of_ele);
	
	selectionSort(arr,number_of_ele);
	
	printf("Elements after sorting\n");
	displayArray(arr,number_of_ele);
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

void selectionSort(int *arr,int n){
	int i=0,j=0,minind,temp;
	for(i = 0; i < n - 1; ++i){
		minind = i;
		for(j = i+1; j < n; ++j){
			if (arr[j] < arr[minind]){
				minind = j;
			}
		}
		if (minind != i){
			temp = arr[minind];
			arr[minind] = arr[i];
			arr[i] = temp;
		}
	}
}