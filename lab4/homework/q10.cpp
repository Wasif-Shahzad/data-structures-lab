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

    void createLoop(int position) {
        Node* temp = head;
        Node* loopStart = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        for (int i = 1; i < position; i++) {
            loopStart = loopStart->next;
        }
        temp->next = loopStart;
    }

    Node* loopStartPoint() {
        Node* slow = head;
        Node* fast = head;
        bool loop = false;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                loop = true;
                break;
            }
        }

        if (!loop) {
            return nullptr;
        }

        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }

    void breakLoop() {
        Node* start = loopStartPoint();
        if (start == nullptr) {
            return;
        }
        Node* temp = start;
        while (temp->next != start) {
            temp = temp->next;
        }
        temp->next = nullptr;
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
    cout << "Enter number of stops: ";
    cin >> n;

    LinkedList list;
    cout << "Enter stop IDs: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        list.insertAtTail(data);
    }

    int position;
    cout << "Enter the stop position the last stop wrongly points back to: ";
    cin >> position;

    list.createLoop(position);
    Node* start = list.loopStartPoint();
    cout << "Loop starts at = [" << start->data << "]" << endl;

    list.breakLoop();
    cout << "Broken route: ";
    list.display();

    return 0;
}