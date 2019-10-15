#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sumnaturalN(int x)
{
    return x * (x + 1) / 2;
}

// Converts i,j to array
int toLinear(int i, int j, int n)
{
    return sumnaturalN(n) - sumnaturalN(n - i) + j - i;
}

// Helper function to read Upper Triangular matrix
void readUTMatrix(int *x, int order)
{
    int i, j, temp;
    for (i = 0; i < order; i++)
    {
        for (j = 0; j < order; j++)
        {
            scanf("%d", &temp);
            if (j >= i)
                x[toLinear(i, j, order)] = temp;
        }
    }
}

// Helper function to retrieve elements from UT matrix.
int retrieve(int *x, int order, int i, int j)
{
    if (i < 0 || i >= order || j < 0 || j >= order)
    {
        printf("\nError\n");
        return -1;
    }
    if (j >= i)
    {
        return x[toLinear(i, j, order)];
    }
    return 0;
}

int main()
{
    int n, i, j;
    printf("Enter the order of UT matrix: ");
    scanf("%d", &n);
    int *up = (int *)malloc(sizeof(int) * sumnaturalN(n));

    printf("Enter the elements of %d x %d UT matrix: \n", n, n);

    readUTMatrix(up, n);

    printf("Retrieved Matrix is\n");
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", retrieve(up, n, i, j));
        }
        printf("\n");
    }

    return 0;
}

// 0 1 2 3
// 0 4 5 6
// 0 0 7 8
// 0 0 0 9