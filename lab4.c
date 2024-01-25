#include <stdio.h>

#define MAX_SIZE 5

struct Queue
{
    int front, rear;
    int array[MAX_SIZE];
};

void enqueue(struct Queue *queue, int item)
{
    if (queue->rear == MAX_SIZE - 1)
    {
        printf("Queue is full. Cannot enqueue %d.\n", item);
        return;
    }

    if (queue->front == -1 && queue->rear == -1)
    {

        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear++;
    }

    queue->array[queue->rear] = item;
}

void dequeue(struct Queue *queue)
{
    if (queue->front == -1)
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    if (queue->front == queue->rear)
    {

        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
}

void printQueue(struct Queue *queue)
{
    if (queue->front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue myQueue;
    myQueue.front = -1;
    myQueue.rear = -1;

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printQueue(&myQueue);

    dequeue(&myQueue);

    printQueue(&myQueue);

    return 0;
}
