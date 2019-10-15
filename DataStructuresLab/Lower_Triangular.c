#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sumnaturalN(int x)
{
    return x * (x + 1) / 2;
}

int toLinear(int i, int j, int n)
{
    return sumnaturalN(i) + j;
}

// Helper function to read LT matrix
void readLTMatrix(int *x, int order)
{
    int i, j, temp;
    for (i = 0; i < order; i++)
    {
        for (j = 0; j < order; j++)
        {
            scanf("%d", &temp);
            if (j <= i)
                x[toLinear(i, j, order)] = temp;
        }
    }
}

// Helper function to retieve element form LT matrix.
int retrieve(int *x, int order, int i, int j)
{
    if (i < 0 || i >= order || j < 0 || j >= order)
    {
        printf("\nError\n");
        return -1;
    }
    if (j <= i)
    {
        return x[toLinear(i, j, order)];
    }
    return 0;
}

int main()
{
    int n, i, j;
    printf("Enter the order of LT matrix: ");
    scanf("%d", &n);

    int *lw = (int *)malloc(sizeof(int) * sumnaturalN(n));

    printf("Enter the elements of %d x %d LT matrix: \n", n, n);

    readLTMatrix(lw, n);
    
    printf("Retrieved Matrix is\n");
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", retrieve(lw, n, i, j));
        }
        printf("\n");
    }
    
    return 0;
}