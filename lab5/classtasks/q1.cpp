#include <iostream>
using namespace std;
#define error 404

class Stack {
private:
    int *arr;
    int n, i = 0;
public:
    Stack() = default;
    Stack(int n) {
        this-> n = n;
        arr = new int[n];
    }

    int pop() {
        if (i == 0) {
            cout << "no more undo\n";
            return error;
        }
        return arr[--i];
    }

    void push(int x) {
        if (i == n) {
            return error;
        }
        arr[i++] = x;
    }

    int peek() {
        if (i == 0) {
            cout << "NO elems\n";
            return error;
        }
        return arr[i - 1];
    }
};

int main() {
    int n = 8;
    Stack stack(n);
    stack.push(12);
    cout << "Top: " << stack.peek() << endl;
    stack.push(25);
    cout << "Top: " << stack.peek() << endl;
    stack.push(17);
    cout << "Top: " << stack.peek() << endl;
    stack.push(31);
    cout << "Top: " << stack.peek() << endl;
    stack.push(44);
    cout << "Top: " << stack.peek() << endl;
    stack.push(19);
    cout << "Top: " << stack.peek() << endl;

    // Press Undo 3 times
    stack.pop();
    cout << "Top: " << stack.peek() << endl;
    stack.pop();
    cout << "Top: " << stack.peek() << endl;
    stack.pop();
    cout << "Top: " << stack.peek() << endl;

    // Perform new operation 52
    stack.push(52);
    cout << "Top: " << stack.peek() << endl;

    // Press Undo 2 times
    stack.pop();
    cout << "Top: " << stack.peek() << endl;
    stack.pop();
    cout << "Top: " << stack.peek() << endl;

    cout << "Remaining operations (Top to Bottom):" << endl;
    while (true) {
        int val = stack.pop();
        if (val == error) break;
        cout << val << endl;
    }
}
