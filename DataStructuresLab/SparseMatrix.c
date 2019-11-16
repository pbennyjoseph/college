/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct term
{
    int row, col, val;
} TERM;

void ReadInto(TERM *);
TERM *AddSPM(TERM *, TERM *);
TERM *TransposeSPM(TERM *);
void PrintSPM(TERM *);

int main()
{
    int M, N, i, j;
    // printf("Enter Number of rows and columns: ");
    scanf("%d %d", &M, &N);

    TERM *arr = (TERM *)malloc(sizeof(TERM) * M * N);
    arr[0].row = M;
    arr[0].col = N;

    // Read matrix and store only non-zero values
    ReadInto(arr);
    TERM *atr = (TERM *)malloc(sizeof(TERM) * (arr[0].val + 1));

    printf("Original Matrix is \n");
    PrintSPM(arr);

    printf("Transpose Matrix is \n");
    TransposeSPM(arr);

    printf("Double of Matrix is \n");
    AddSPM(arr, arr);

    free(arr);
    return 0;
}

void ReadInto(TERM *x)
{
    int i, j, temp, nz = 1;
    printf("Enter %d rows and %d columns\n", x[0].row, x[0].col);
    for (i = 0; i < x[0].row; i++)
    {
        for (j = 0; j < x[0].col; j++)
        {
            scanf("%d", &temp);
            if (temp != 0)
            {
                x[nz].row = i;
                x[nz].col = j;
                x[nz].val = temp;
                nz++;
            }
        }
    }
    x[0].val = nz - 1;
}

// Adds two Matrices a,b and returns a new SparseMatrix
TERM *AddSPM(TERM *a, TERM *b)
{
    int i = 1, j = 1, k = 1;
    if (a[0].row != b[0].row || a[0].col != b[0].col)
    {
        printf("Cannot Add these Matrices\n");
        return NULL;
    }
    TERM *result = (TERM *)malloc(sizeof(TERM) * (a[0].val + b[0].val));

    result[0] = a[0];
    while (i <= a[0].val || j <= b[0].val)
    {
        if (i == a[0].val) // first matrix is empty.
        {
            while (j <= b[0].val) // Put all elements of second matrix into result.
                result[k++] = b[j++];
        }
        if (j == b[0].val) // Second matrix is empty.
        {
            while (i <= a[0].val) // Put all elements of second matrix into result.
                result[k++] = a[i++];
        }

        if (a[i].row < b[j].row)
            result[k++] = a[i++];
        else if (a[i].row == b[j].row)
        {
            if (a[i].col < b[j].col)
                result[k++] = a[i++];
            else if (a[i].col > b[j].col)
                result[k++] = b[j++];
            else
            {
                result[k] = a[i];
                result[k++].val = a[i++].val + b[j++].val;
            }
        }
        else
            result[k++] = b[j++];
    }
    result[0].val = k;

    PrintSPM(result);

    free(result);
    // return c; // optional. comment above line.
}

TERM *TransposeSPM(TERM *a)
{
    int nums = a[0].val, cols = a[0].col;
    int row_arr[cols], startpos[cols], i, k = 0;
    // TERM a_tr[nums + 1]; // taking as parameter
    // printf("%d %d %d\n",a[1].col,a[2].col,a[3].col);
    TERM *a_tr = (TERM *)malloc((nums + 1) * sizeof(TERM));

    a_tr[0].val = a[0].val;
    a_tr[0].row = a[0].col;
    a_tr[0].col = a[0].row;

    // printf("%d %d %d\n",a[1].col,a[2].col,a[3].col);

    for (i = 0; i < cols; i++)
    {
        row_arr[i] = 0;
    }
    for (i = 1; i <= nums; i++)
    {
        row_arr[a[i].col]++;
    }

    startpos[0] = 1;

    for (i = 1; i < cols; i++)
    {
        startpos[i] = startpos[i - 1] + row_arr[i - 1];
    }

    for (i = 1; i <= nums; i++)
    {
        a_tr[startpos[a[i].col]].val = a[i].val;
        a_tr[startpos[a[i].col]].row = a[i].col;
        a_tr[startpos[a[i].col]].col = a[i].row;
        startpos[a[i].col]++;
    }
    
    PrintSPM(a_tr);
    free(a_tr);
    //return a_tr; // Optional. comment above line
}

void PrintSPM(TERM *a)
{
    int i, j, k = 1;

    // Code to print the terms
    // for(i=1;i<=a[0].val;i++)
    //     printf("%d %d %d\n",a[i].row,a[i].col,a[i].val);

    for (i = 0; i < a[0].row; i++)
    {
        for (j = 0; j < a[0].col; j++)
        {
            if (a[k].row == i && a[k].col == j)
            {
                printf("%d ", a[k++].val);
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
    printf("\n\n");
}
