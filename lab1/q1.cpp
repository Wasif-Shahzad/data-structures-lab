#include <iostream>
using namespace std;

class DataArchive {
public:
    int n;
    int *arr;

    DataArchive(int size) {
        n = size;
        arr = new int[size];
    }

    DataArchive(const DataArchive& other) {
        n = other.n;
        arr = new int[other.n];
        for(int i = 0; i < other.n; i++) {
            arr[i] = other.arr[i];
        }
    }

    DataArchive& operator=(const DataArchive& other) {
        if(this != &other) {
            delete[] this->arr;

            this->n = other.n;
            this->arr = new int[n];
            for(int i = 0; i < n; i++) {
                this->arr[i] = other.arr[i]; 
            }
        }
        return *this;
    }

    ~DataArchive() {
        delete[] arr;
    }
};