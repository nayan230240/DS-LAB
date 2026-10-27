
#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Insert an element
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue is full" << endl;
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = value;

    cout << value << " inserted" << endl;
}

// Delete an element
void dequeue() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << queue[front] << " deleted" << endl;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

// Display the queue
void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }

    int i = front;

    cout << "Circular Queue: ";

    while (true) {
        cout << queue[i] << " ";
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();

    dequeue();

    display();

    return 0;
}
