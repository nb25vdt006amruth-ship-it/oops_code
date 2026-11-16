/*
 * Lab Experiment: Week 9 - DIY 3
 * Problem: Exception Catch Ordering Demonstration
 * Description: Base MathError and derived DivideByZero. Show how catching
 *              the derived class before base class ensures proper handling.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <exception>

using namespace std;

class MathError : public exception {
public:
    const char* what() const noexcept override {
        return "General MathError occurred";
    }
};

class DivideByZero : public MathError {
public:
    const char* what() const noexcept override {
        return "DivideByZero: Division by zero is undefined";
    }
};

double divide(double a, double b) {
    if (b == 0.0) {
        throw DivideByZero();
    }
    return a / b;
}

int main() {
    cout << "===== Week 9 DIY 3: Exception Catch Ordering =====\n";

    cout << "Demonstrating CORRECT handler order (derived caught before base):\n";
    try {
        divide(10.0, 0.0);
    } catch (const DivideByZero &ex) {
        cout << "Caught specific [DivideByZero]: " << ex.what() << "\n";
    } catch (const MathError &ex) {
        cout << "Caught generic [MathError]: " << ex.what() << "\n";
    }

    return 0;
}
