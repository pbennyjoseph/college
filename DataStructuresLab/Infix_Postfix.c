/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SZ 200

typedef struct stack
{
    char *s;
    int top;
} stack;

void push(stack* st, char data)
{
    st->s[++st->top] = data;
}

void pop(stack* st)
{
    --st->top;
}

int prcd(char ch)
{
    if (ch == '*' || ch == '/')
        return 4;
    else if (ch == '+' || ch == '-')
        return 3;
    else if (ch == '^')
        return 2;
    else if (ch == '(')
        return 1;
    else
        return 0;
}

void InfixPostfix(char *infixString, int n)
{
    stack MyStack;
    MyStack.top = -1;
    int i;
    char currentCharacter;
    MyStack.s = (char *)calloc(MAX_SZ, sizeof(char));

    for (i = 0; i < n; ++i)
    {
        currentCharacter = infixString[i];
        if (currentCharacter >= 97 && currentCharacter <= 122)
        {
            printf("%c ", currentCharacter);
        }
        else if (currentCharacter == '(')
            push(&MyStack, currentCharacter);
        else if (currentCharacter == ')')
        {
            while (MyStack.top != -1 && MyStack.s[MyStack.top] != '(')
            {
                printf("%c ", MyStack.s[MyStack.top]);
                pop(&MyStack);
            }
            pop(&MyStack);
        }
        else
        {
            while (MyStack.top != -1 && prcd(currentCharacter) < prcd(MyStack.s[MyStack.top]))
            {
                printf("%c ", MyStack.s[MyStack.top]);
                pop(&MyStack);
            }
            push(&MyStack, currentCharacter);
        }
    }

    while(MyStack.top!=-1){
        printf("%c ",MyStack.s[MyStack.top]);
        pop(&MyStack);
    }

    free(MyStack.s);
}

int main()
{
    char DriverString[] = "(a+b)*c*(d+e)*f";
    InfixPostfix(DriverString, 15);
    // Outputs a b + c d e + f * * *
    return 0;
}