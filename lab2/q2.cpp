#include <iostream>
using namespace std;

int main() {
    int count;
    cout << "Enter number of passengers: ";
    cin >> count;
    string* passengers = new string[count];
    cin.ignore();
    for (int i = 0; i < count; i++) {
        cout << "Enter name of passenger " << i + 1 << ": ";
        getline(cin, passengers[i]);
    }
    cout << "Boarding sequence (reverse check-in order):" << endl;
    for (int i = count - 1; i >= 0; i--) {
        cout << passengers[i] << endl;
    }
    delete[] passengers;
}
