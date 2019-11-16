/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Function to add element to the stack.
void push(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    // Check if memory is allocated
    if (!newNode)
    {
        printf("Memory Full\n");
        return;
    }

    newNode->data = data;

    // Check if head node is NULL
    if (!*head)
    {
        *head = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = *head;
        *head = newNode;
    }
}

// Function to remove element from the stack.
void pop(Node **head)
{
    if (!*head)
    {
        return;
    }
    Node *temp = *head;
    *head = temp->next;
    free(temp);
}

// Function to retrieve top element from the stack.
int top(Node *head)
{
    if (!head)
    {
        printf("Empty Stack\n");
        return -1;
    }
    return head->data;
}

int main()
{
    int queries, mode, n;
    Node *head = NULL;

    // Testing code
    scanf("%d", &queries);
    while (queries--)
    {
        // Mode 0 - PUSH
        // Mode 1 - POP
        // Mode 2 - TOP
        scanf("%d", &mode);
        if (mode == 0)
        {
            scanf("%d", &n);
            push(&head, n);
        }
        else if (mode == 1)
        {
            pop(&head);
        }
        else
        {
            printf("%d\n", top(head));
        }
    }
    return 0;
}