#include <iostream>
using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void adjacentSwapper(int arr[], int size) {
    int swaps = 0;
    int comparisons = 0;
    int passes = 0;
    bool swapped = true;

    for (int i = 0; i < size - 1 && swapped; i++) {
        swapped = false;
        passes++;
        for (int j = 0; j < size - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = true;
            }
        }
    }

    int worstCasePasses = size - 1;
    int passesSaved = worstCasePasses - passes;
    int theoretical = size * (size - 1) / 2;

    cout << "Sorted array: ";
    display(arr, size);
    cout << "Total swaps made: " << swaps << endl;
    cout << "Total comparisons made: " << comparisons << endl;
    cout << "Passes run: " << passes << endl;
    cout << "Passes saved compared to worst case (" << worstCasePasses << "): " << passesSaved << endl;
    cout << "Actual comparisons: " << comparisons << "   Theoretical worst-case N(N-1)/2: " << theoretical << endl;
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

    cout << "Task 1:" << endl;
    adjacentSwapper(arr, size);

    return 0;
}
