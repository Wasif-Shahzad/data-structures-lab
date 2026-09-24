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

class MyQueue {
private:
    Stack inStack;
    Stack outStack;

public:
    void enqueue(string data) {
        inStack.push(data);
    }

    string dequeue() {
        if (outStack.isEmpty()) {
            while (!inStack.isEmpty()) {
                outStack.push(inStack.pop());
            }
        }
        return outStack.pop();
    }
};

int main() {
    MyQueue q;
    
    q.enqueue("A");
    q.enqueue("B");
    cout << q.dequeue() << endl;
    
    q.enqueue("C");
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}