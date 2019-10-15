#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SZ 200

int *Queue, size, front = -1, rear = -1;

void enQueue(int val)
{
    if (rear == -1)
    {
        front = rear = 0;
        Queue[rear] = val;
    }
    else
    {
        if (rear == MAX_SZ)
        {
            printf("Queue Full\n");
            return;
        }
        Queue[++rear] = val;
    }
}

void deQueue()
{
    if (front == -1)
        return;
    ++front;
}

int getFront()
{
    if (front == -1 || front > rear)
    {
        printf("Empty Queue\n");
        return -1;
    }
    return Queue[front];
}

int main()
{
    int queries, mode, val;
    Queue = (int *)malloc(sizeof(int) * MAX_SZ);
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
            enQueue(val);
        }
        else if (mode == 1)
        {
            deQueue();
        }
        else
        {
            printf("%d\n", getFront());
        }
    }
    return 0;
}