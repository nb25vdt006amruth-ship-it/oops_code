/*
 * Lab Experiment: Week 8 - DIY 3
 * Problem: Virtual Destructors in Polymorphism
 * Description: Build a Base/Derived pair where Derived allocates memory;
 *              demonstrate how a virtual destructor ensures complete cleanup.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>

using namespace std;

class Base {
public:
    Base() { cout << "  Base constructor\n"; }
    // Virtual destructor guarantees Derived destructor is called
    virtual ~Base() { cout << "  Base destructor\n"; }
};

class Derived : public Base {
private:
    int *buffer;
    int size;

public:
    Derived(int sz = 100) : size(sz) {
        buffer = new int[size];
        cout << "  Derived constructor (allocated buffer of size " << size << ")\n";
    }

    ~Derived() override {
        delete[] buffer;
        cout << "  Derived destructor (buffer safely deallocated)\n";
    }
};

int main() {
    cout << "===== Week 8 DIY 3: Virtual Destructor Verification =====\n";
    cout << "Deleting Derived object through Base pointer with virtual destructor:\n";
    Base *ptr = new Derived(50);
    delete ptr; // Calls ~Derived() followed by ~Base()
    cout << "Cleanup successful without memory leaks.\n";
    return 0;
}
