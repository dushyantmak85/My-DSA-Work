#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int qfront;
    int rear;
    int size;
    bool isFullFlag; // Flag to indicate if the queue is full

public:
    // Constructor
    CircularQueue(int s) {
        size = s;
        arr = new int[size];
        qfront = -1;
        rear = -1;
        isFullFlag = false; // Initially, the queue is not full
    }

    // Destructor to free allocated memory
    ~CircularQueue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (qfront == -1 && rear == -1);
    }

    // Check if the queue is full
    bool isFull() {
        return isFullFlag;
    }

    // Enqueue an element
    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue is Full!!" << endl;
            return;
        }

        if (isEmpty()) {
            // Inserting the first element
            qfront = 0;
            rear = 0;
            arr[rear] = data;
        } else {
            // Move rear to the next position
            rear++;
            if (rear == size) {
                rear = 0; // Wrap around to the beginning
            }
            arr[rear] = data;
        }

        // If after enqueueing, the next position is qfront, set the queue as full
        if (rear == qfront) {
            isFullFlag = true;
        }
    }

    // Dequeue an element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!!" << endl;
            return;
        }

        // If the queue is full, we need to unset the full flag because we're removing an element
        isFullFlag = false;

        if (qfront == rear) {
            // Only one element was present, now queue will be empty
            qfront = -1;
            rear = -1;
        } else {
            // Move qfront to the next position
            qfront++;
            if (qfront == size) {
                qfront = 0; // Wrap around to the beginning
            }
        }
    }

    // Print the queue elements
    void print() {
        if (isEmpty()) {
            cout << "Queue is Empty!!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = qfront;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i++;
            if (i == size) {
                i = 0; // Wrap around to the beginning
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5); // Queue should be full here
    q1.print();
    q1.dequeue();
    q1.enqueue(6); // This should work now because of circular behavior
    q1.print();

    return 0;
}
