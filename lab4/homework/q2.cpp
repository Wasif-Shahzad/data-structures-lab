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

    Node* findMiddle() {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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
    cout << "Enter number of students: ";
    cin >> n;

    LinkedList list;
    cout << "Enter roll numbers: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        list.insertAtTail(data);
    }

    cout << "Chain: ";
    list.display();

    Node* middle = list.findMiddle();
    cout << "Middle Box = [" << middle->data << "]" << endl;

    return 0;
}