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

// insert element at the tail
// if tail is empty set head and tail to the new element
void enQueue(Node **head, Node **tail, int x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;

    if (*tail)
        (*tail)->next = newNode;
    else
    {
        *tail = newNode;
        *head = newNode;
    }
    *tail = newNode;
}

// Remove element from the head
void deQueue(Node **head, Node **tail)
{
    if (*head)
    {
        Node *temp = *head;
        *head = temp->next;
        free(temp);
        if (!*head)
            *tail = NULL;
    }
}

int front(Node *head)
{
    if (head)
    {
        return head->data;
    }
    printf("Empty Queue\n");
    return -1;
}

int main()
{
    Node *head = NULL, *tail = NULL;
    int queries, mode, val;
    scanf("%d", &queries);
    while (queries--)
    {
        // Mode 0 - enQueue
        // Mode 1 - deQueue
        // Mode 2 - front
        scanf("%d", &mode);
        if (mode == 0)
        {
            scanf("%d", &val);
            enQueue(&head, &tail, val);
        }
        else if (mode == 1)
        {
            deQueue(&head, &tail);
        }
        else
        {
            printf("%d\n", front(head));
        }
    }
    return 0;
}