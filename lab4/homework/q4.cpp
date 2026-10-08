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

class SortedList {
public:
    Node* head;
    SortedList() {
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

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "[" << temp->data << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

Node* mergeSortedLists(Node* headA, Node* headB) {
    if (headA == nullptr) return headB;
    if (headB == nullptr) return headA;

    Node* merged = nullptr;
    if (headA->data <= headB->data) {
        merged = headA;
        headA = headA->next;
    } else {
        merged = headB;
        headB = headB->next;
    }

    Node* tail = merged;
    while (headA != nullptr && headB != nullptr) {
        if (headA->data <= headB->data) {
            tail->next = headA;
            headA = headA->next;
        } else {
            tail->next = headB;
            headB = headB->next;
        }
        tail = tail->next;
    }

    if (headA != nullptr) {
        tail->next = headA;
    } else {
        tail->next = headB;
    }

    return merged;
}

int main() {
    int n;
    cout << "Enter number of employees in chain A: ";
    cin >> n;
    SortedList listA;
    cout << "Enter employee IDs of chain A: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        listA.insertAtTail(data);
    }

    int m;
    cout << "Enter number of employees in chain B: ";
    cin >> m;
    SortedList listB;
    cout << "Enter employee IDs of chain B: ";
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;
        listB.insertAtTail(data);
    }

    cout << "Chain A: ";
    listA.display();
    cout << "Chain B: ";
    listB.display();

    SortedList result;
    result.head = mergeSortedLists(listA.head, listB.head);
    cout << "Merged chain: ";
    result.display();

    return 0;
}