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
public:
    Node* head;
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

    void groupOddPassengers() {
        Node* oddHead = nullptr;
        Node* oddTail = nullptr;
        Node* evenHead = nullptr;
        Node* evenTail = nullptr;

        Node* curr = head;
        while (curr != nullptr) {
            Node* nxt = curr->next;
            curr->next = nullptr;

            if (curr->data % 2 == 1) {
                if (oddHead == nullptr) {
                    oddHead = curr;
                    oddTail = curr;
                } else {
                    oddTail->next = curr;
                    oddTail = curr;
                }
            } else {
                if (evenHead == nullptr) {
                    evenHead = curr;
                    evenTail = curr;
                } else {
                    evenTail->next = curr;
                    evenTail = curr;
                }
            }
            curr = nxt;
        }

        if (oddHead == nullptr) {
            head = evenHead;
        } else {
            oddTail->next = evenHead;
            head = oddHead;
        }
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
    cout << "Enter number of passengers: ";
    cin >> n;

    LinkedList list;
    cout << "Enter passenger IDs: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        list.insertAtTail(data);
    }

    cout << "Original chain: ";
    list.display();

    list.groupOddPassengers();
    cout << "Grouped chain: ";
    list.display();

    return 0;
}