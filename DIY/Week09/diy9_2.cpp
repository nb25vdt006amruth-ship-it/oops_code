/*
 * Lab Experiment: Week 9 - DIY 2
 * Problem: Stack Exception Handling (Overflow and Underflow)
 * Description: Give Stack custom Overflow and Underflow exceptions
 *              and handle them cleanly in main().
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class StackOverflowException : public runtime_error {
public:
    explicit StackOverflowException(const string &msg) : runtime_error(msg) {}
};

class StackUnderflowException : public runtime_error {
public:
    explicit StackUnderflowException(const string &msg) : runtime_error(msg) {}
};

class Stack {
private:
    int *data;
    int capacity;
    int topIndex;

public:
    explicit Stack(int cap = 3) : capacity(cap), topIndex(-1) {
        data = new int[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(int val) {
        if (topIndex == capacity - 1) {
            throw StackOverflowException("Stack Overflow: Exceeded capacity of " + to_string(capacity));
        }
        data[++topIndex] = val;
        cout << "Pushed: " << val << "\n";
    }

    int pop() {
        if (topIndex == -1) {
            throw StackUnderflowException("Stack Underflow: Attempted to pop from empty stack");
        }
        return data[topIndex--];
    }
};

int main() {
    cout << "===== Week 9 DIY 2: Stack Exceptions =====\n";
    Stack s(2);

    // Test Overflow
    try {
        s.push(10);
        s.push(20);
        s.push(30); // Triggers Overflow
    } catch (const StackOverflowException &e) {
        cout << "Caught: " << e.what() << "\n";
    }

    // Test Underflow
    try {
        cout << "Popped: " << s.pop() << "\n";
        cout << "Popped: " << s.pop() << "\n";
        cout << "Popped: " << s.pop() << "\n"; // Triggers Underflow
    } catch (const StackUnderflowException &e) {
        cout << "Caught: " << e.what() << "\n";
    }

    return 0;
}
