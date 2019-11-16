/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct stack
{
    int *s;
    int top;
} stack;

// Function to add element to the stack.
void push(stack *x, int data)
{
    x->s[++x->top] = data;
}

// Function to remove element from the stack.
void pop(stack *x)
{
    --x->top;
}

// Function to retrieve top element from the stack.
int top(stack *x)
{
    if (x->top == -1)
    {
        printf("Empty stack\n");
        return -1;
    }
    return x->s[x->top];
}

int main()
{
    int queries, mode, n;
    stack mystack;
    mystack.top = -1;

    // Testing code
    scanf("%d", &queries);
    mystack.s = (int *) malloc(sizeof(int) * queries);
    while (queries--)
    {
        // Mode 0 - PUSH
        // Mode 1 - POP
        // Mode 2 - TOP
        scanf("%d", &mode);
        if (mode == 0)
        {
            scanf("%d", &n);
            push(&mystack, n);
        }
        else if (mode == 1)
        {
            pop(&mystack);
        }
        else
        {
            printf("%d\n", top(&mystack));
        }
    }
    free(mystack.s);
    return 0;
}