
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert a node at the end
void insert(int value) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Display the circular linked list
void display() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;

    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "HEAD" << endl;
}

// Delete the first node
void deleteNode() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;

    if (head->next == head) {
        head = NULL;
        delete temp;
        return;
    }

    Node* last = head;

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;
    delete temp;
}

int main() {
    insert(10);
    insert(20);
    insert(30);

    cout << "Circular Linked List: ";
    display();

    deleteNode();

    cout << "After deletion: ";
    display();

    return 0;
}
