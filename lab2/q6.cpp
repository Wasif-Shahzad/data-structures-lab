#include <iostream>
using namespace std;

class Reservation {
private:
    int **reservation;
public:
    Reservation() {
        reservation = new int*[3];
        for(int i = 0; i < 3; i++) {
            reservation[i] = new int[2 * (i + 1)];
        }
    }
    Reservation(const Reservation& other) {
        reservation = new int*[3];
        for(int i = 0; i < 3; i++) {
            reservation[i] = new int[2 * (i + 1)];
            for(int j = 0; j < 2 * (i + 1); j++) {
                reservation[i][j] = other.reservation[i][j];
            }
        }
    }

    void reserve(int i, int j) {
        if (i < 1 || i > 3) {
            cout << "Invalid class\n";
            return;
        }
        if (j < 0 || j >= 2 * i) {
            cout << "Invalid seat\n";
            return;
        }
        reservation[i - 1][j] = 1;
        cout << "Reserved seat " << j << " in class " << i << "\n";
    }

    void print() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 2 * (i + 1); j++) {
                cout << reservation[i][j] << " ";
            }
            cout << "\n";
        }
    }

    ~Reservation() {
        for(int i = 0; i < 3; i++) {
            delete[] reservation[i];
        }
        delete[] reservation;
    }
};
