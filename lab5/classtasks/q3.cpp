#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) : data(d), next(nullptr) {}
};

class Stack {
private:
    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    void push(string data) {
        Node* newNode = new Node(data);
        newNode->next = topNode;
        topNode = newNode;
    }

    string pop() {
        if (isEmpty()) return "";
        Node* temp = topNode;
        string popped = temp->data;
        topNode = topNode->next;
        delete temp;
        return popped;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

class Queue {
private:
    Node* frontNode;
    Node* rearNode;
    int size;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

    void enqueue(string data) {
        Node* newNode = new Node(data);
        if (rearNode == nullptr) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        size++;
    }

    string dequeue() {
        if (isEmpty()) return "";
        Node* temp = frontNode;
        string dequeued = temp->data;
        frontNode = frontNode->next;
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
        delete temp;
        size--;
        return dequeued;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    int getSize() {
        return size;
    }

    void print() {
        Node* current = frontNode;
        bool first = true;
        while (current != nullptr) {
            if (!first) cout << ", ";
            cout << current->data;
            first = false;
            current = current->next;
        }
        cout << endl;
    }
};

void reverseFirstK(Queue& q, int k) {
    if (q.isEmpty() || k <= 1 || k > q.getSize()) {
        return;
    }

    Stack s;

    for (int i = 0; i < k; i++) {
        s.push(q.dequeue());
    }

    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }

    int remaining = q.getSize() - k;
    for (int i = 0; i < remaining; i++) {
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q;
    
    q.enqueue("J1");
    q.enqueue("J2");
    q.enqueue("J3");
    q.enqueue("J4");
    q.enqueue("J5");
    q.enqueue("J6");
    q.enqueue("J7");

    q.print();

    reverseFirstK(q, 3);

    q.print();

    return 0;
}