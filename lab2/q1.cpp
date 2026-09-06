#include <iostream>
using namespace std;

const int SIZE = 6;

void display(int arr[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void compact(int arr[SIZE]) {
    int writeIndex = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] != 0) {
            arr[writeIndex] = arr[i];
            if (writeIndex != i) {
                arr[i] = 0;
            }
            writeIndex++;
        }
    }
}

int main() {
    int arr[SIZE];

    cout << "Enter " << SIZE << " product IDs (0 for empty spot): ";
    for (int i = 0; i < SIZE; i++) {
        cin >> arr[i];
    }

    cout << "Initial shelf: ";
    display(arr);

    int choice;
    do {
        cout << "Compact the shelf? (1 = yes, 0 = exit): ";
        cin >> choice;

        if (choice == 1) {
            cout << "Before: ";
            display(arr);
            compact(arr);
            cout << "After:  ";
            display(arr);
        }
    } while (choice != 0);

    return 0;
}