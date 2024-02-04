#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isEmpty(struct circularQueue *q) {
    return (q->r == -1 && q->f == -1);
}

int isFull(struct circularQueue *q) {
    return ((q->r + 1) % q->size == q->f);
}

void enqueue(struct circularQueue *q, int val) {
    if (isFull(q)) {
        printf("This Queue is full\n");
    } else {
        if (isEmpty(q)) {
            q->f = 0;
            q->r = 0;
        } else {
            q->r = (q->r + 1) % q->size;
        }
        q->arr[q->r] = val;
        printf("Enqueued element: %d\n", val);
    }
}

int dequeue(struct circularQueue *q) {
    int a = -1;
    if (isEmpty(q)) {
        printf("This Queue is empty\n");
    } else {
        a = q->arr[q->f];
        if (q->f == q->r) {
            q->f = -1;
            q->r = -1;
        } else {
            q->f = (q->f + 1) % q->size;
        }
    }
    return a;
}

int main() {
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = -1;
    q.arr = (int*)malloc(q.size * sizeof(int));

    // Enqueue few elements
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    printf("Dequeuing element %d\n", dequeue(&q));
    enqueue(&q, 45);
    enqueue(&q, 45);
    enqueue(&q, 145);
    enqueue(&q, 453);
    enqueue(&q, 3);

    if (isEmpty(&q)) {
        printf("Queue is empty\n");
    }
    if (isFull(&q)) {
        printf("Queue is full\n");
    }

    return 0;
}
