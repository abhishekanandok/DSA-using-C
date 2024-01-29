#include <stdio.h>
#include <stdlib.h>
//queue implementation using linklist

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *front;
    struct Node *rear;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Queue *initializeQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (queue == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

int isEmpty(struct Queue *queue)
{
    return (queue->front == NULL);
}

void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = createNode(data);

    if (isEmpty(queue))
    {
        // If the queue is empty, set both front and rear to the new node
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        // Otherwise, add the new node to the rear and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }

    struct Node *temp = queue->front;
    int dequeuedValue = temp->data; // ye data ouput screen pe show karenge,esko delete kar diye hai

    // Update the front pointer
    queue->front = temp->next;

    // If the queue becomes empty, update the rear pointer to NULL
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);
    return dequeuedValue;
}

void displayQueue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    struct Node *current = queue->front;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(struct Queue *queue)
{
    while (!isEmpty(queue))
    {
        dequeue(queue);
    }
    free(queue);
}

int main()
{
    struct Queue *anand = initializeQueue();

    enqueue(anand, 10);
    enqueue(anand, 20);
    enqueue(anand, 30);

    displayQueue(anand);

    int dequeuedValue = dequeue(anand);
    printf("Dequeued element: %d\n", dequeuedValue);

    displayQueue(anand);

    freeQueue(anand);

    return 0;
}
