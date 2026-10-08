#include <iostream>
using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionArmSorter(int arr[], int size) {
    int totalShift = 0;

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        int shifts = 0;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        arr[j + 1] = key;
        totalShift += shifts;

        cout << "Key " << key << " placed at index " << j + 1 << ": ";
        if (shifts == 0) {
            cout << "No shift required" << endl;
        } else {
            cout << "shifted " << shifts << " positions" << endl;
        }
        cout << "Array state: ";
        display(arr, size);
    }

    cout << "Total shift distance: " << totalShift << endl;
}

int main() {
    int size;
    cout << "Enter number of items: ";
    cin >> size;

    int arr[100];
    cout << "Enter tracking IDs: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Task 2:" << endl;
    insertionArmSorter(arr, size);

    return 0;
}
