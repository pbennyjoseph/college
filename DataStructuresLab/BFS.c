#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *circularQueue, *visited, start = -1, rear = -1;
int adj[1000][1000], n;

// Enqueue element into Queue;
void enQueue(int x)
{
    if ((rear + 1) % n != start)
    {
        rear = (rear + 1) % n;
        circularQueue[rear] = x;
    }
}

// Remove Element form queue.
void deQueue()
{
    if (start != rear)
    {
        start = (start + 1) % n;
        return;
    }
    start = -1;
}

// Function to get the front element
int front()
{
    if (start == rear)
        return -1;
    return circularQueue[(start + 1) % n];
}

void bfs(int j)
{
    int i;
    enQueue(j);
    while ((j = front()) != -1)
    {
        deQueue();
        for (i = 1; i < n + 1; ++i)
        {
            if (!visited[i] && adj[j][i] == 1)
            {
                visited[i] = 1;
                enQueue(i);
            }
        }
    }
}

int main()
{
    int a, b, i, j, m, count = 0;
    scanf("%d %d", &n, &m);                         // Read total vertices and edges
    circularQueue = (int *)malloc(sizeof(int) * n); // maximum elements are n

    // Initialize adjecency matrix to all zeroes
    // Requires string.h
    memset(adj, 0, sizeof(adj));

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
            bfs(i);
        }
    }

    printf("The Number of components in graph are %d\n", count);

    free(circularQueue);
    free(visited);
    return 0;
}