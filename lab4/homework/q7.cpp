#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void insertAtTail(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void removeDuplicates() {
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->data == temp->next->data) {
                Node* dup = temp->next;
                temp->next = dup->next;
                if (dup->next != nullptr) {
                    dup->next->prev = temp;
                }
                delete dup;
            } else {
                temp = temp->next;
            }
        }
    }

    void displayForward() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "[" << temp->data << "] ";
            if (temp->next != nullptr) {
                cout << "<-> ";
            }
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
            cout << "[" << temp->data << "] ";
            if (temp->prev != nullptr) {
                cout << "<-> ";
            }
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of patient records: ";
    cin >> n;

    DoublyLinkedList list;
    cout << "Enter patient IDs: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        list.insertAtTail(data);
    }

    cout << "Original sequence: ";
    list.displayForward();

    list.removeDuplicates();
    cout << "Cleaned sequence: ";
    list.displayForward();
    cout << "Backward links intact: ";
    list.displayBackward();

    return 0;
}