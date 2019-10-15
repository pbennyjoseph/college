#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *stack, *visited, top = -1;
int adj[1000][1000], n;

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
    if(top == -1) return -1;
    return stack[top];
}

void dfs(int startVertex)
{
    int i;
    push(startVertex);
    while (get() != -1)
    {
        startVertex = get();
        pop();
        visited[startVertex] = 1;
        for (i = 1; i < n + 1; ++i)
        {
            if (!visited[i] && adj[startVertex][i] == 1)
            {
                visited[i] = 1;
                push(i);
            }
        }
    }
}

// Not recommended for huge graphs
void dfsRecursive(int j)
{
    int i;
    visited[j] = 1;
    for (i = 1; i < n + 1; ++i)
    {
        if (!visited[i] && adj[j][i] == 1)
        {
            dfs(i);
        }
    }
}

int main()
{
    int a, b, i, j, m, count = 0;
    scanf("%d %d", &n, &m);                 // Read total vertices and edges
    stack = (int *)malloc(sizeof(int) * n); // maximum depth is n

    // Initialize adjecency matrix to all zeroes
    // Requires string.h
    memset(adj, 0, sizeof(adj));
    // Vertices are from 1 to N inclusive
    // Initialize all to 0 (Not visited)
    visited = (int *)calloc(n + 1, sizeof(int));
    // Read edges
    for (i = 0; i < m; ++i)
    {
        scanf("%d %d", &a, &b);
        // connect a and b
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    // Go through every vertex and check if it visited.
    // if not visited dfs on that vertex.
    for (i = 1; i < n + 1; ++i)
    {
        if (visited[i] == 0)
        {
            ++count;
            dfs(i);
        }
    }

    printf("The Number of components in graph are %d\n", count);

    free(stack);
    free(visited);
    return 0;
}

// The Number of components in graph are 3