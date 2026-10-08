#include <iostream>
using namespace std;

class Node {
public:
    int id;
    int severity;
    Node* prev;
    Node* next;
    Node(int id, int severity) {
        this->id = id;
        this->severity = severity;
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

    void insertAtTail(int id, int severity) {
        Node* newNode = new Node(id, severity);
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

    void shellSortBySeverity() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        if (count <= 1) {
            return;
        }

        Node* box[100];
        temp = head;
        for (int i = 0; i < count; i++) {
            box[i] = temp;
            temp = temp->next;
        }

        for (int gap = count / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < count; i++) {
                Node* key = box[i];
                int j = i;
                while (j >= gap && box[j - gap]->severity > key->severity) {
                    box[j] = box[j - gap];
                    j -= gap;
                }
                box[j] = key;
            }
        }

        head = box[0];
        for (int i = 0; i < count; i++) {
            box[i]->prev = (i > 0) ? box[i - 1] : nullptr;
            box[i]->next = (i < count - 1) ? box[i + 1] : nullptr;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "[ID:" << temp->id << ", Sev:" << temp->severity << "] ";
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
    cout << "Enter number of patients: ";
    cin >> n;

    DoublyLinkedList list;
    for (int i = 0; i < n; i++) {
        int id;
        int severity;
        cout << "Enter patient ID and severity score: ";
        cin >> id >> severity;
        list.insertAtTail(id, severity);
    }

    cout << "Original queue: ";
    list.display();

    list.shellSortBySeverity();
    cout << "Sorted queue: ";
    list.display();

    return 0;
}