#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
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
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;

            cout << "curr = [" << curr->data << "]";
            if (prev == nullptr) {
                cout << " now points to NULL" << endl;
            } else {
                cout << " now points to [" << prev->data << "]" << endl;
            }

            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "[" << temp->data << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of songs: ";
    cin >> n;

    LinkedList list;
    cout << "Enter song IDs: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        list.insertAtTail(data);
    }

    cout << "Original chain: ";
    list.display();

    cout << "Reversing chain in-place (no new boxes):" << endl;
    list.reverse();

    cout << "Reversed chain: ";
    list.display();

    return 0;
}