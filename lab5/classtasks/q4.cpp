#include <iostream>

using namespace std;

class CircularQueue {
private:
    int* arr;
    int capacity;
    int front;
    int rear;

public:
    CircularQueue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(int val) {
        if ((rear + 1) % capacity == front) {
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = val;
    }

    int dequeue() {
        if (front == -1) {
            return -1;
        }
        int val = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        return val;
    }

    void print() {
        if (front == -1) {
            return;
        }
        
        int i = front;
        bool first = true;
        while (true) {
            if (!first) cout << " ";
            cout << arr[i];
            first = false;
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
        cout << front << endl;
        cout << rear << endl;
    }
};

int main() {
    CircularQueue q(6);

    q.enqueue(101);
    q.enqueue(102);
    q.enqueue(103);
    q.enqueue(104);
    q.enqueue(105);
    q.enqueue(106);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(107);
    q.enqueue(108);
    q.enqueue(109);

    q.dequeue();
    q.dequeue();

    q.enqueue(110);

    q.dequeue();

    q.enqueue(111);
    q.enqueue(112);

    q.print();

    return 0;
}