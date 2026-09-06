#include <iostream>
using namespace std;

int **tracker;

void addNewStudent(int *student, int& n) {
    int **new_tracker = new int*[n + 1];
    for (int i = 0; i < n; i++) {
        new_tracker[i] = tracker[i];
    }
    new_tracker[n] = student;
    tracker = new_tracker;
    n++;
}

int main() {
    int n;
    cin >> n;
    cout << "enter the number of students: ";
    cin >> n;
    tracker = new int*[n];
    for (int i = 0; i < n; i++) {
        tracker[i] = new int[3];
        for (int j = 0; j < 3; j++) {
            cout << "enter the grades for student " << i << " subject " << j << ": ";
            cin >> tracker[i][j];
        }
    }
    int *new_student = new int[3];
    for(int i = 0; i < 3; i++) {
        cout << "enter the grades for the new student subject " << i << ": ";
        cin >> new_student[i];
    }
    addNewStudent(new_student, n);
    for (int i = 0; i < n + 1; i++) {
        cout << "student " << i << ": ";
        for (int j = 0; j < 3; j++) {
            cout << tracker[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = n - 1; i >= 0; i--) {
        delete[] tracker[i];
    }
    delete[] tracker;
}
