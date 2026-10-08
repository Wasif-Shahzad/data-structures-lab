#include <iostream>
using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void diminishingDistanceScanner(int arr[], int size) {
    int gap = size / 2;
    int phase = 1;

    while (gap > 0) {
        int comparisons = 0;
        int swaps = 0;

        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap) {
                comparisons++;
                if (arr[j - gap] > temp) {
                    arr[j] = arr[j - gap];
                    swaps++;
                    j -= gap;
                } else {
                    break;
                }
            }
            arr[j] = temp;
        }

        double percentage = (gap * 100.0) / size;
        cout << "Phase " << phase << " - Gap size: " << gap << endl;
        cout << "Gap percentage of array size: " << percentage << "%" << endl;
        cout << "Comparisons made in this phase: " << comparisons << endl;
        cout << "Swaps made in this phase: " << swaps << endl;
        cout << "Array state: ";
        display(arr, size);

        gap /= 2;
        phase++;
    }

    cout << "Sorted array: ";
    display(arr, size);
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

    cout << "Task 4:" << endl;
    diminishingDistanceScanner(arr, size);

    return 0;
}
