/*
 * Lab Experiment: Week 3 - DIY 3
 * Problem: Complex Number Class
 * Description: Store real and imag parts, provide setData() and display(),
 *              and print a small array of complex numbers.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    void setData(double r, double i) {
        real = r;
        imag = i;
    }

    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }
};

int main() {
    cout << "===== Week 3 DIY 3: Complex Number Class =====\n";
    Complex arr[4] = {
        Complex(3.0, 4.5),
        Complex(2.0, -1.5),
        Complex(0.0, 5.0),
        Complex(-4.2, 0.0)
    };

    cout << "Array of Complex Numbers:\n";
    for (int i = 0; i < 4; ++i) {
        cout << "C[" << i << "] = ";
        arr[i].display();
        cout << "\n";
    }

    return 0;
}
