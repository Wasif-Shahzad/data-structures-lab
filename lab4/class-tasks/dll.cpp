#include <iostream>

class Node {
public:
    int data;
    Node *prev, *next;
    Node(int data) {
        this->data = data;
        prev = next = nullptr;
    }
};

class DLL {
    Node *head;
public:
    DLL () {
        head = nullptr;
    }

    void insertAtFront(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteAtPos(int pos) {
        if (head == nullptr) {
            std::cout << "emtpy\n";
            return;
        }
        Node *temp = head;
        int i = 1;
        while(temp != nullptr && i < pos) {
            temp = temp->next;
        }
        if (i < pos) {
            std::cout << "emtpy\n";
            return;
        }
        if (temp == head) {
            head = temp->next;
            delete temp;
            return;
        }
        if (temp->next == nullptr) {
            temp->prev->next = nullptr;
            delete temp;
            return;
        }
        Node *after = temp->next, *before = temp->prev;
        before->next = after;
        after->prev = before;
        delete temp;
    }
}
