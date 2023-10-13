#include <stdio.h>

#define MAX_SIZE 10
typedef struct 
{
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(Queue *q) {
    if(q->rear == MAX_SIZE - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(Queue *q) {
    return q->front == -1 || q->front > q->rear;
}

void insertion (Queue *q , int item){ 
    if(isFull(q) == 1){
        printf("Queue is full");
        return;
    }
    if(q-> rear == -1 || q-> front == -1){ 
        q->front = 0; 
        q->rear = 0;
    } else{ 
        q->rear++;
    }
    q->arr[q->rear] = item;
    return;
}


void deletion (Queue *q ) {
    if(isEmpty(q) == 1){
        printf("Queue is empty");
        return;
    }
    if(q->front == q->rear){ 
        q->front = -1;
        q->rear = -1;
    } else{ 
        q->front++;
    }
    return;
}

void displayQ(Queue *q) {
    if(isEmpty(q)){
        printf("Queue is empty");
        return;
    }
    for(int i = q->front; i <= q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
    return;
}

int main() {
    Queue q; 
    init(&q);
    insertion(&q, 1);
    insertion(&q, 2);
    insertion(&q, 3);
    insertion(&q, 4);

    printf("Queue after insertion: ");
    displayQ(&q);

    deletion(&q);
    printf("Queue after 1st deletion: ");
    displayQ(&q);

    deletion(&q);
    printf("Queue after 2nd deletion: ");

    displayQ(&q);
    printf("Queue after 3rd deletion: ");
    return 0;
}
