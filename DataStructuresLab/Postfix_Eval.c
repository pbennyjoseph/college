/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct stack
{
    int *s;
    int top;
} stack;

void push(stack *st, int data)
{
    st->s[++st->top] = data;
}

void pop(stack *st)
{
    --st->top;
}

int top(stack *st)
{
    if (st->top == -1)
    {
        printf("Empty stack\n");
        return -1;
    }
    return st->s[st->top];
}

void postfixEvaluation(char *expression, int size)
{
    stack MyStack;
    MyStack.top = -1;
    int i = 0, opr1, opr2, number = 0;
    MyStack.s = (int *)calloc(size, sizeof(char));
    for (i = 0; expression[i]; ++i)
    {
        if (expression[i] == ' ')
            continue;
        else if (isdigit(expression[i]))
        {
            push(&MyStack, expression[i] - '0');
        }
        else
        {
            opr1 = top(&MyStack);
            pop(&MyStack);
            opr2 = top(&MyStack);
            pop(&MyStack);
            switch (expression[i])
            {
            case '+':
                push(&MyStack, opr1 + opr2);
                break;
            case '-':
                push(&MyStack, opr1 - opr2);
                break;
            case '*':
                push(&MyStack, opr1 * opr2);
                break;
            case '/':
                push(&MyStack, opr1 / opr2);
                break;
            case '^':
                push(&MyStack, opr1 ^ opr2);
                break;
            default:
                break;
            }
        }
    }
    // Output the result
    printf("The expression evaluates to: %d", top(&MyStack));
    // free the space
    free(MyStack.s);
}

int main()
{
    char *expr = (char *)malloc(300 * sizeof(char));
    printf("Enter a postfix expression\n");
    scanf(" %[^\n]s ", expr);
    postfixEvaluation(expr, strlen(expr));
    free(expr);
    return 0;
}

// Enter a postfix expression
// 23+456+7***
// The expression evaluates to: 1540