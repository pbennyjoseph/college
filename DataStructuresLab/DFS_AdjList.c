#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int *visited, n;
int *stack, top = -1;

// Function to add element at the start of linked list.
void add(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    // Check if memory is allocated
    if (!newNode)
    {
        printf("Memory Full\n");
        return;
    }

    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to Delete all elements from a linked list.
void delete_all(Node **head)
{
    Node *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void push(int x)
{
    stack[++top] = x;
}

void pop()
{
    --top;
}

int get()
{
    if (top == -1)
        return -1;
    return stack[top];
}

void dfs(Node **v, int startVertex)
{
    int i;
    push(startVertex);
    while (get() != -1)
    {
        startVertex = get();
        pop();
        visited[startVertex] = 1;
        Node *headj = v[startVertex];
        while (headj)
        {
            i = headj->data;
            if (!visited[i])
            {
                visited[i] = 1;
                push(i);
            }
            headj = headj->next;
        }
    }
}

// Not recommended for huge graphs
void dfsRecursive(Node **v, int j)
{
    int i;
    visited[j] = 1;
    Node *headj = v[j];
    while (headj)
    {
        i = headj->data;
        if (!visited[i])
        {
            dfs(v, i);
        }
        headj = headj->next;
    }
}

int main()
{
    int a, b, i, j, m, count = 0;
    scanf("%d %d", &n, &m);                 // Read total vertices and edges
    stack = (int *)malloc(sizeof(int) * n); // maximum elements are n
    Node **graph = (Node **)malloc(sizeof(Node *) * (n + 1));

    visited = (int *)calloc(n + 1, sizeof(int));
    // Read edges
    for (i = 0; i < m; ++i)
    {
        scanf("%d %d", &a, &b);
        // connect a and b
        add(graph + a, b);
        add(graph + b, a);
    }

    // Go through every vertex and check if it visited.
    // if not visited dfs on that vertex.
    for (i = 1; i < n + 1; ++i)
    {
        if (visited[i] == 0)
        {
            ++count;
            dfs(graph, i);
        }
    }

    printf("The Number of components in graph are %d\n", count);

    // Delete All linked lists now that graph is used.
    for (i = 1; i < n + 1; ++i)
    {
        delete_all(graph + i);
    }

    free(graph);
    free(stack);
    free(visited);
    return 0;
}