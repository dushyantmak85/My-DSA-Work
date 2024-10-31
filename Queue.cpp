#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear;
    int size;

public:
    // Parameterized constructor
    Queue(int s) {
        size = s;
        arr = new int[size];
        qfront = -1;
        rear = -1;
    }

    // Destructor to free allocated memory
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        if (qfront == -1 && rear == -1) {
            return true;
        } 
        else {
            return false;
        }
    }

    // Check if the queue is full
    bool isFull() {
        if (rear == size-1) {
            return true;
        } else {
            return false;
        }
    }

    // Enqueue an element
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is full!!" << endl;
            return;
        }
        if (qfront == -1 && rear == -1) {
            qfront = 0;
            rear = 0;
            arr[rear] = data;
        } else {
            rear++;
            arr[rear] = data;
        }
    }

    // Dequeue an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!!" << endl;
            return;
        }
        if (qfront == rear) {
            qfront = -1;
            rear = -1;
        } else {
            qfront++;
        }
    }

    // Print the queue elements
    void print() {
        if (isEmpty()) {
            cout << "Queue is Empty!!" << endl;
            return;
        }
        for (int i = qfront; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.dequeue();
    q1.enqueue(6);
    q1.print();

    return 0;
}
