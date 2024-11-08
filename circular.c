
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Queue structure
typedef struct {
    int data[MAX_QUEUE_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Function to create a new queue
void createQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

// Function to check if the queue is empty
int queueIsEmpty(Queue* q) {
    return (q->size == 0);
}

// Function to check if the queue is full
int queueIsFull(Queue* q) {
    return (q->size == MAX_QUEUE_SIZE);
}

// Function to enqueue an element
void enqueue(Queue* q, int value) {
    if (queueIsFull(q)) {
        printf("Error: Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = value;
    q->size++;
}

// Function to dequeue an element
int dequeue(Queue* q) {
    if (queueIsEmpty(q)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    q->size--;
    return value;
}

// Function to display the queue
void displayQueue(Queue* q) {
    if (queueIsEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    for (int j = 0; j < q->size; j++) {
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    }
    printf("\n");
}

// Function to get the size of the queue
int sizeOfQueue(Queue* q) {
    return q->size;
}

// Function to get the value at the head of the queue
int headOfQueue(Queue* q) {
    if (queueIsEmpty(q)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    return q->data[q->front];
}

// Function to get the value at the end of the queue
int endOfQueue(Queue* q) {
    if (queueIsEmpty(q)) {
        printf("Error: Queue is empty\n");
        return -1;
    }
    return q->data[q->rear];
}

int main() {
    Queue q;
    createQueue(&q);

    // Example usage
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    displayQueue(&q);  // Output: Queue: 10 20 30
    printf("Size of queue: %d\n", sizeOfQueue(&q));  // Output: Size of queue: 3
    printf("Head of queue: %d\n", headOfQueue(&q));  // Output: Head of queue: 10
    printf("End of queue: %d\n", endOfQueue(&q));  // Output: End of queue: 30
    printf("Dequeued: %d\n", dequeue(&q));  // Output: Dequeued: 10
    displayQueue(&q);  // Output: Queue: 20 30

    return 0;
}
