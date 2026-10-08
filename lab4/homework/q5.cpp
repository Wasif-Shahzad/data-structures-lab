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

class Chain {
public:
    Node* head;
    Chain() {
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

int listLength(Node* temp) {
    int length = 0;
    while (temp != nullptr) {
        length++;
        temp = temp->next;
    }
    return length;
}

Node* intersectionPoint(Node* headA, Node* headB) {
    int lenA = listLength(headA);
    int lenB = listLength(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    while (headA != nullptr && headB != nullptr) {
        if (headA == headB) {
            return headA;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return nullptr;
}

int main() {
    int commonCount;
    cout << "Enter number of common road stops: ";
    cin >> commonCount;
    Chain common;
    cout << "Enter common road stop values (" << commonCount << "): ";
    for (int i = 0; i < commonCount; i++) {
        int data;
        cin >> data;
        common.insertAtTail(data);
    }
    Node* commonHead = common.head;

    int n;
    cout << "Enter number of stops in chain A before merge: ";
    cin >> n;
    Chain chainA;
    cout << "Enter chain A values: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        chainA.insertAtTail(data);
    }

    int m;
    cout << "Enter number of stops in chain B before merge: ";
    cin >> m;
    Chain chainB;
    cout << "Enter chain B values: ";
    for (int i = 0; i < m; i++) {
        int data;
        cin >> data;
        chainB.insertAtTail(data);
    }

    Node* tailA = chainA.head;
    while (tailA->next != nullptr) {
        tailA = tailA->next;
    }
    tailA->next = commonHead;

    Node* tailB = chainB.head;
    while (tailB->next != nullptr) {
        tailB = tailB->next;
    }
    tailB->next = commonHead;

    cout << "Chain A: ";
    chainA.display();
    cout << "Chain B: ";
    chainB.display();

    Node* meeting = intersectionPoint(chainA.head, chainB.head);
    if (meeting == nullptr) {
        cout << "No intersection" << endl;
    } else {
        cout << "Intersection point = [" << meeting->data << "]" << endl;
    }

    return 0;
}