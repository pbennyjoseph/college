/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helper function to store value into diagonal matrix.
void store(int *x, int row, int col, int value)
{
    if (row != col && value != 0)
        return;
    else
    {
        x[row] = value;
    }
}

// Helper function to retrieve element form diagonal matrix.
int retrieve(int *x, int row, int col, int size)
{
    if (row >= size || col >= size || row < 0 || col < 0)
    {
        printf("Error\n");
        return 0;
    }
    if (row != col)
        return 0;
    return x[row];
}

int main()
{
    int n, i, temp, row, col;

    printf("Enter the size of matrix: ");
    scanf("%d", &n);

    printf("Enter %d Diagonal elements row col and value\n", n);

    int a[n];
    int *p = a;

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &row, &col, &temp);
        store(p, row, col, temp);
    }

    printf("Enter Diagonal Element row and col to retrieve: ");
    scanf("%d %d", &row, &col);

    temp = retrieve(a, row, col, n);

    printf("The element at row %d and col %d is %d\n", row, col, temp);
    return 0;
}