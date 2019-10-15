#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *p;
void insert();
void delete ();
void display();

int main()
{
    int m, n, i;
    //Node *p=(Node *)malloc(sizeof(Node));
    printf("Pls enter the num of elements->");
    scanf("%d", &m);
    printf("Pls enter the number of items u want to delete from the list->");
    scanf("%d", &n);
    for (i = 0; i < m; i++)
    {
        insert();
        display();
    }
    for (i = 0; i < n; i++)
    {
        delete ();
    }
    display();
    return 0;
}
void insert()
{
    int x, k, pos, i;
    Node *q;
    q = p;
    printf("pls enter ur choice:");
    scanf("%d", &x);

    switch (x)
    {
    case 1:
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        printf("Insertion at the beginning\n");
        printf("Pls enter a num:");
        scanf("%d", &k);
        if (p == NULL)
        {
            temp->data = k;
            temp->next = temp;
            p = temp;
        }

        else
        {
            temp->data = k;
            while (q->next != p)
            {
                q = q->next;
            }
            temp->next = p;
            p = temp;
            q->next = p;
        }
        break;
    }
    case 2:
    {
        Node *temp = (Node *)malloc(sizeof(Node));
        printf("Insertion at the end\n");
        printf("Pls enter a num:");
        scanf("%d", &k);
        if (p == NULL)
        {
            temp->data = k;
            temp->next = temp;
            p = temp;
        }
        else
        {
            temp->data = k;
            while (q->next != p)
            {
                q = q->next;
            }
            q->next = temp;
            temp->next = p;
        }
        break;
    }
    case 3:

    {
        Node *temp = (Node *)malloc(sizeof(Node));
        printf("Enter the position where u want to insert the element->\n");
        scanf("%d", &pos);
        printf("Pls enter a num:");
        scanf("%d", &k);
        temp->data = k;
        temp->next = NULL;
        for (i = 1; i < pos - 1; i++)
        {
            q = q->next;
        }
        temp->next = q->next;
        q->next = temp;
        break;
    }
    }
}
void delete ()
{
    Node *temp = (Node *)malloc(sizeof(Node));
    int d, i, pos;
    Node *q;
    q = p;
    printf("Pls enter ur choice->");
    scanf("%d", &d);
    switch (d)
    {
    case 1:
    {
        while (q->next != p)
        {
            q = q->next;
        }
        temp = p;
        p = p->next;
        q->next = p;
        free(temp);

        break;
    }
    case 2:
    {
        while (q->next->next != p)
        {
            q = q->next;
        }
        temp = q->next;
        q->next = p;
        free(temp);
        break;
    }
    case 3:
    {
        scanf("%d", &pos);
        for (i = 1; i < pos - 1; i++)
        {
            q = q->next;
        }
        temp = q->next;
        q->next = q->next->next;
        free(temp);
        break;
    }
    }
}
void display()
{
    Node *q;
    q = p;
    do
    {
        printf("%d ", q->data);
        q = q->next;
    } while (q != p);
}