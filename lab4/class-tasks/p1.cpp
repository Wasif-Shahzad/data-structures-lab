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
    void insert(int data) {
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

    void merge(LinkedList& other) {
        if (head == nullptr) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = other.head;
        }
    }

    void insertAtFront(int data) {
        if (head == nullptr) {
            head = new Node(data);
        } else {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        }
    }

    void traverse() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    LinkedList even, odd;
    for(int i = 0; i < n; i++) {
        int data;
        cout << "Enter element " << i + 1 << ": ";
        cin >> data;
        if (data % 2 == 0) {
            even.insert(data);
        } else {
            odd.insert(data);
        }
    }
    even.merge(odd);
    even.traverse();
}
