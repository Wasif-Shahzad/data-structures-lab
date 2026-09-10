#include <iostream>

class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;
public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertAt(int pos, int new_val) {
        Node *newNode = new Node(new_val);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }
        int i = 1;
        Node *temp = head;
        while(temp != nullptr && i + 1 < pos) {
            temp = temp->next;
            i++;
        }
        if (temp != nullptr) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            std::cout << "Position out of bounds" << std::endl;
        }
    }

    void traverse() {
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << "->";
            temp = temp->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    void goRev(Node *cur) {
        if (cur == nullptr) {
            return;
        }
        goRev(cur->next);
        std::cout << cur->data << "->";
    }

    void traverseReverse() {
        Node *temp = head;
        goRev(temp);
        std::cout << "nullptr" << std::endl;
    }

    void deleteFront() {
        if (head == nullptr) {
            return;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void deleteEnd() {
        if (head == nullptr) {
            return;
        } else if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node *temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }
};

int main() {
    LinkedList list;
    list.insertAt(1, 10);
    list.insertAt(2, 20);
    list.insertAt(3, 30);
    list.insertAt(2, 25);
    list.traverse();
    list.traverseReverse();
}
