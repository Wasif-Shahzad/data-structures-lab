#include <iostream>
using namespace std;

class SafeCommandCenter {
private:
    int* commands;

public:
    SafeCommandCenter() {
        commands = new int[5];
        for (int i = 0; i < 5; i++) {
            commands[i] = 0;
        }
    }

    SafeCommandCenter(const SafeCommandCenter& other) {
        commands = new int[5];
        for (int i = 0; i < 5; i++) {
            commands[i] = other.commands[i];
        }
    }

    ~SafeCommandCenter() {
        delete[] commands;
    }

    bool validIndex(int index) {
        return index >= 0 && index < 5;
    }

    bool validSpeed(int value) {
        return value >= 0 && value <= 100;
    }

    void safeWrite(int index, int value) {
        if (!validIndex(index) || !validSpeed(value)) {
            cout << "CRITICAL ERROR WARNING!" << endl;
            cout << "Rover Emergency Braking Triggered!" << endl;
            cout << "Command rejected and blocked." << endl;
            return;
        }
        commands[index] = value;
    }

    void display() {
        for (int i = 0; i < 5; i++) {
            cout << commands[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    SafeCommandCenter rover;

    int index, value;
    char choice;
    do {
        cout << "Enter index (0-4) and speed (0-100): ";
        cin >> index >> value;
        rover.safeWrite(index, value);
        rover.display();
        cout << "Continue? (y/n): ";
        cin >> choice;
    } while (choice == 'y');
}
