#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
    Node *front, *rear;

public:
    Queue() { front = rear = nullptr; }

    void enqueue(int x) {
        Node* temp = new Node(x);
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    void dequeue() {
        if (front == nullptr) return;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    int peek() {
        return (front != nullptr) ? front->data : -1;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    cout << "After one dequeue, front: " << q.peek() << endl;

    q.dequeue();
    q.dequeue();

    if (q.isEmpty()) {
        cout << "Queue is now empty" << endl;
    }

    return 0;
}