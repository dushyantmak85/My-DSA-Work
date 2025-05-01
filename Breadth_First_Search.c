#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front;
    int rear;
    int size;
    int* arr;
};

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

// Function to check if the queue is full
int isFull(struct Queue* q) {
    return q->rear == q->size - 1;
}

// Function to enqueue an element
void Enqueue(struct Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is Full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = data;
}

// Function to dequeue an element
int Dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!!\n");
        return -1;
    }
    q->front++;
    return q->arr[q->front];
}

int main() {
    struct Queue q;
    q.size = 100;
    q.front = q.rear = -1;
    q.arr = (int*)malloc(q.size * sizeof(int));

    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int adjacencyMatrix[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };

    int startNode = 1;
    printf("BFS Traversal: %d ", startNode);
    visited[startNode] = 1;
    Enqueue(&q, startNode);// For Exploration 

    while (!isEmpty(&q)) {
        int currentNode = Dequeue(&q);

        for (int i = 0; i < 7; i++) {
            if (adjacencyMatrix[currentNode][i] == 1 && visited[i] == 0) {
                printf("%d ", i);
                visited[i] = 1;
                Enqueue(&q, i);
            }
        }
    }

    free(q.arr); // Free allocated memory
    return 0;
}


