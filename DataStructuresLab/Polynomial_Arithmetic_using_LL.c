/*
Name: P Benny Joseph
Date: 2 Nov 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct term
{
    int exp;
    double coeff;
} term;

typedef struct Node
{
    term t;
    struct Node *next;
} Node;

// insert element at the tail
// if tail is empty set head and tail to the new element
void enQueue(Node **head, Node **tail, term x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->t = x;
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

term front(Node *head)
{
    term None;
    if (head)
    {
        return head->t;
    }
    printf("Empty Queue\n");
    return None;
}

void sum(Node * head1,Node *head2,Node * tail1,Node * tail2){

}

int main()
{
    int n,m,exp;
    double coeff;
    term t;
    Node *head1 = NULL, *head2 = NULL;
    Node *tail1 = NULL, *tail2 = NULL;
    scanf("%d %d",n,m);
    
    return 0;
}