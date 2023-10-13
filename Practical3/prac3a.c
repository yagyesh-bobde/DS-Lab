#include <stdio.h>

#define MAX_SIZE 10
typedef struct
{
    char arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *q)
{
    q->front = 1;
    q->rear = 5;
}

int isFull(Queue *q)
{
    if (q->rear == MAX_SIZE - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q)
{
    return q->front == -1 || q->front > q->rear;
}

void enqueue(Queue *q, int item)
{
    if (isFull(q) == 1)
    {
        printf("Queue is full");
        return;
    }
    if (q->rear == -1 || q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    q->arr[q->rear] = item;
    return;
}

void dequeue(Queue *q)
{
    if (isEmpty(q) == 1)
    {
        printf("Queue is empty");
        return;
    }
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front++;
    }
    return;
}

void displayQ(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty");
        return;
    }

    printf("Queue after operations: ");
    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
    return;
}

int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 'F');
    displayQ(&q);
    dequeue(&q);
    displayQ(&q);
    dequeue(&q);
    displayQ(&q);
    enqueue(&q, 'G');
    displayQ(&q);
    enqueue(&q, 'H');
    displayQ(&q);
    dequeue(&q);
    displayQ(&q);
    dequeue(&q);
    displayQ(&q);
    dequeue(&q);
    displayQ(&q);
    dequeue(&q);
    displayQ(&q);
    enqueue(&q, 'I');
    displayQ(&q);

    return 0;
}
