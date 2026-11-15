/*
 * Lab Experiment: Week 3 - DIY 1
 * Problem: Rectangle Class with Encapsulation & Validation
 * Description: Private length and width, public setters rejecting negative numbers,
 *              area() and perimeter() getters, and method chaining.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>

using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l = 1.0, double w = 1.0) {
        setLength(l);
        setWidth(w);
    }

    // Setters with validation and method chaining
    Rectangle& setLength(double l) {
        if (l >= 0.0) {
            length = l;
        } else {
            cout << "Warning: Negative length rejected! Setting to 0.0.\n";
            length = 0.0;
        }
        return *this;
    }

    Rectangle& setWidth(double w) {
        if (w >= 0.0) {
            width = w;
        } else {
            cout << "Warning: Negative width rejected! Setting to 0.0.\n";
            width = 0.0;
        }
        return *this;
    }

    // Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }

    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2.0 * (length + width);
    }

    void display() const {
        cout << "Rectangle [" << length << " x " << width << "] -> Area: "
             << area() << ", Perimeter: " << perimeter() << "\n";
    }
};

int main() {
    cout << "===== Week 3 DIY 1: Rectangle Class =====\n";
    Rectangle r1(10.0, 5.0);
    r1.display();

    cout << "\nTesting method chaining: r1.setLength(15.5).setWidth(4.0)\n";
    r1.setLength(15.5).setWidth(4.0);
    r1.display();

    cout << "\nTesting validation with negative dimension:\n";
    Rectangle r2;
    r2.setLength(-8.0);
    r2.display();

    return 0;
}
