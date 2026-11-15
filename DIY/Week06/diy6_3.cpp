/*
 * Lab Experiment: Week 6 - DIY 3
 * Problem: Safe Array with operator[]
 * Description: Dynamic array class wrapper; overload operator[] to throw an error
 *              or report bounds violations instead of memory corruption.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <stdexcept>

using namespace std;

class SafeArray {
private:
    int *data;
    int size;

public:
    explicit SafeArray(int sz) : size(sz) {
        data = new int[size]();
    }

    ~SafeArray() {
        delete[] data;
    }

    int getSize() const { return size; }

    // Overloaded subscript operator with bounds checking
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index " + to_string(index) +
                               " out of range [0, " + to_string(size - 1) + "]");
        }
        return data[index];
    }

    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index " + to_string(index) +
                               " out of range [0, " + to_string(size - 1) + "]");
        }
        return data[index];
    }
};

int main() {
    cout << "===== Week 6 DIY 3: Safe Array operator[] =====\n";
    SafeArray arr(5);

    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i] = (i + 1) * 10;
    }

    cout << "Array elements: ";
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    cout << "\nTesting out-of-bounds access:\n";
    try {
        cout << "Accessing arr[10]: ";
        cout << arr[10] << endl;
    } catch (const out_of_range &ex) {
        cout << "Caught Exception: " << ex.what() << "\n";
    }

    try {
        cout << "Accessing arr[-1]: ";
        cout << arr[-1] << endl;
    } catch (const out_of_range &ex) {
        cout << "Caught Exception: " << ex.what() << "\n";
    }

    return 0;
}
