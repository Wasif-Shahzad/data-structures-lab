#include <iostream>
using namespace std;

struct Node{
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

struct CircularLinkedList{
    Node *tail;
public:
    CircularLinkedList() {
        tail = nullptr;
    }

    void insertAtFront(int data) {
        Node *newNode = new Node(data);
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
    }
};

int main() {

}
