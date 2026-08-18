#include <iostream>
using namespace std;

class LogBuffer {
private:
    char* buffer;
    int length;
public:
    LogBuffer(int size) {
        length = size;
        buffer = new char[length]; // Allocation on the heap
    }
    // TODO: Implement the Destructor
    ~LogBuffer() {
        delete[] buffer;
    }
    // TODO: Implement the Copy Constructor (Deep Copy)
    LogBuffer(const LogBuffer& other) {
        length = other.length;
        buffer = new char[length];
        for(int i = 0; i < length; i++) {
            buffer[i] = other.buffer[i];
        }
    }
    // TODO: Implement the Copy Assignment Operator (Deep Copy)
    LogBuffer& operator=(const LogBuffer& other) {
        if(this != &other) {
            delete[] this->buffer;

            this->length = other.length;
            this->buffer = new char[length];
            for(int i = 0; i < length; i++) {
                this->buffer[i] = other.buffer[i];
            }
        }
        return *this;
    }
};