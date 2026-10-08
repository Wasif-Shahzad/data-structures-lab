#include <iostream>
#include <cmath>
using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool isSorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int midpointSplitSearch(int arr[], int size, int targetID) {
    if (!isSorted(arr, size)) {
        cout << "Error: Conveyor is unsorted. Search aborted." << endl;
        return -1;
    }

    int low = 0;
    int high = size - 1;
    int steps = 0;
    int maxSteps = floor(log2(size)) + 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        steps++;

        cout << "Step " << steps << ": low = " << low << ", mid = " << mid << ", high = " << high << endl;
        cout << "Remaining search space: " << ((high - low + 1) * 100.0) / size << "%" << endl;
        cout << "Steps taken so far vs theoretical max: " << steps << " / " << maxSteps << endl;

        if (arr[mid] == targetID) {
            cout << "Target found at index " << mid << endl;
            return mid;
        } else if (arr[mid] < targetID) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << "Target not found in the list" << endl;
    return -1;
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

    int targetID;
    cout << "Enter tracking ID to search: ";
    cin >> targetID;

    cout << "Task 5:" << endl;
    cout << "Array: ";
    display(arr, size);
    midpointSplitSearch(arr, size, targetID);

    sortArray(arr, size);
    cout << "Sorted array: ";
    display(arr, size);
    midpointSplitSearch(arr, size, targetID);

    return 0;
}
