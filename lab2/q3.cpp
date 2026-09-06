#include <iostream>
using namespace std;

int* arr = new int[3];
int n = 3;

void addElem(int i, int v) {
    if (v == n) {
        cout << "current size: " << n << endl;
        cout << "need addition at index: " << i << endl;
        cout << "resizing to " << n * 2 << endl;
        int* temp = new int[n * 2];
        for (int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        arr[n] = v;
        n *= 2;
    } else {
        arr[i] = v;
    }
}

int main() {
    int choice = -1;
    do {
        cout << "1. Add element\n2. Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                int i, v;
                cout << "Enter index and value: ";
                cin >> i >> v;
                addElem(i, v);
                break;
            case 2:
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 2);
}
