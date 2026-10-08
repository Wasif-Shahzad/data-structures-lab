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

    int countTriplets(int x) {
        int matching = 0;
        cout << "All triplets checked:" << endl;

        Node* first = head;
        while (first != nullptr) {
            Node* second = first->next;
            while (second != nullptr) {
                Node* third = second->next;
                while (third != nullptr) {
                    int sum = first->data + second->data + third->data;
                    cout << "(" << first->data << "," << second->data << "," << third->data
                         << ") = " << sum << "  ";
                    if (sum == x) {
                        cout << "matched" << endl;
                        matching++;
                    } else {
                        cout << "not matched" << endl;
                    }
                    third = third->next;
                }
                second = second->next;
            }
            first = first->next;
        }

        return matching;
    }

    void display() {
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
};

int main() {
    int n;
    cout << "Enter number of transactions: ";
    cin >> n;

    DoublyLinkedList list;
    cout << "Enter transaction amounts: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        list.insertAtTail(data);
    }

    int x;
    cout << "Enter target sum x: ";
    cin >> x;

    list.display();
    int count = list.countTriplets(x);
    cout << "Matching: " << count << endl;

    return 0;
}