/*
 * Lab Experiment: Week 4 - DIY 2
 * Problem: Dynamic Stack with Destructor
 * Description: An integer Stack backed by a dynamic array; push/pop plus
 *              destructor that releases dynamic buffer.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>

using namespace std;

class Stack {
private:
    int *arr;
    int capacity;
    int topIndex;

public:
    explicit Stack(int cap = 5) : capacity(cap), topIndex(-1) {
        arr = new int[capacity];
        cout << "[Stack] Allocated capacity " << capacity << "\n";
    }

    ~Stack() {
        delete[] arr;
        cout << "[Stack] Destructor released memory\n";
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << val << "\n";
            return;
        }
        arr[++topIndex] = val;
        cout << "Pushed: " << val << "\n";
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Stack is empty.\n";
            return -1;
        }
        int val = arr[topIndex--];
        return val;
    }

    int top() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return -1;
        }
        return arr[topIndex];
    }
};

int main() {
    cout << "===== Week 4 DIY 2: Dynamic Stack =====\n";
    {
        Stack s(4);
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50); // Overflow test

        cout << "Top element: " << s.top() << "\n";

        cout << "Popping elements:\n";
        while (!s.isEmpty()) {
            cout << "Popped: " << s.pop() << "\n";
        }
        s.pop(); // Underflow test
    }
    return 0;
}
