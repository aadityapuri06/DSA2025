#include <iostream>
using namespace std;

#define MAX_SIZE 5
int cqueue[MAX_SIZE];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX_SIZE;
    cqueue[rear] = value;
    cout << value << " enqueued to circular queue." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << cqueue[front] << " dequeued from circular queue." << endl;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Front element is: " << cqueue[front] << endl;
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Circular Queue elements: ";
    int i;
    for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
        cout << cqueue[i] << " ";
    }
    cout << cqueue[i] << endl;
}

int main() {
    int choice, value;
    do {
        cout << "\n--- CIRCULAR QUEUE MENU ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. IsEmpty" << endl;
        cout << "4. IsFull" << endl;
        cout << "5. Display" << endl;
        cout << "6. Peek" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << (isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 4:
                cout << (isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 5:
                display();
                break;
            case 6:
                peek();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 7);

    return 0;
}
