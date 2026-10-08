#include <iostream>
using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void minimalSwapCrane(int arr[], int size) {
    int swaps = 0;
    int skipped = 0;
    int comparisons = 0;

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex == i) {
            skipped++;
            cout << "Smallest item already in right spot, skipped swap at index " << i << endl;
            continue;
        }

        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        swaps++;
        cout << "Swapped index " << i << " with index " << minIndex << endl;
    }

    double ratio = 0;
    if (comparisons > 0) {
        ratio = (swaps * 100.0) / comparisons;
    }

    cout << "Sorted array: ";
    display(arr, size);
    cout << "Total actual swaps: " << swaps << endl;
    cout << "Number of skipped swaps: " << skipped << endl;
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Swap-to-Comparison Ratio: " << ratio << "%" << endl;
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

    cout << "Task 3:" << endl;
    minimalSwapCrane(arr, size);

    return 0;
}
