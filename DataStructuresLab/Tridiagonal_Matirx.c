/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>

void create();  //create a tridiagonal matrix
void display(); //display tridiagonal matrix
int *a;         //Creating a 1-d array to efficiently store elements of tridiagonal matrix
int n;          //order of tri-diagonal matrix

int main()
{
    printf("Enter the order of Tridiagonal Square Matrix: ");
    scanf("%d", &n);
    a = (int *)malloc((3 * n - 2) * sizeof(int)); //dynamically allocating memory for 1-d array

    create();
    display();
}

void create()
{
    int i, j, ele;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            switch (i - j)
            {
            case 1: //Elements lying to the left of diagonal(lower elements)
                printf("Enter Element a[%d][%d]", i, j);
                scanf("%d", &ele);
                a[i - 1] = ele;
                break;
            case 0: //ELements lying in the diagonal
                printf("Enter Element a[%d][%d]", i, j);
                scanf("%d", &ele);
                a[i + n - 1] = ele;
                break;
            case -1: //Elements lying to the right of the diagonal(upper elements)
                printf("Enter Element a[%d][%d]", i, j);
                scanf("%d", &ele);
                a[2 * n + i - 1] = ele;
                break;
            default:
                break;
            }
        }
    }
}

void display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i - j == 1) //display  elements to the left of diagonal(lower elements)
                printf("%d ", a[i - 1]);
            else if (i == j)
                printf("%d ", a[n + i - 1]); //display diagonal elements
            else if (i - j == -1)
                printf("%d ", a[2 * n + i - 1]); //display elements to the right of diagonal(upper elements)
            else
                printf("0 ");
        }
        printf("\n");
    }
}
