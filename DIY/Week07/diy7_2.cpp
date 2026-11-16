/*
 * Lab Experiment: Week 7 - DIY 2
 * Problem: Multilevel Inheritance Order of Constructors
 * Description: Shape -> Polygon -> Rectangle. Each level adds one field;
 *              demonstrate constructor and destructor call order.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <string>

using namespace std;

class Shape {
protected:
    string color;

public:
    Shape(const string &c = "Red") : color(c) {
        cout << "  [+] Shape constructor called (Color: " << color << ")\n";
    }
    virtual ~Shape() {
        cout << "  [-] Shape destructor called\n";
    }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon(const string &c, int s) : Shape(c), sides(s) {
        cout << "  [+] Polygon constructor called (Sides: " << sides << ")\n";
    }
    ~Polygon() override {
        cout << "  [-] Polygon destructor called\n";
    }
};

class Rectangle : public Polygon {
private:
    double length, width;

public:
    Rectangle(const string &c, double l, double w)
        : Polygon(c, 4), length(l), width(w) {
        cout << "  [+] Rectangle constructor called (" << length << "x" << width << ")\n";
    }
    ~Rectangle() override {
        cout << "  [-] Rectangle destructor called\n";
    }

    void display() const {
        cout << "Rectangle Properties -> Color: " << color
             << ", Sides: " << sides << ", Area: " << (length * width) << "\n";
    }
};

int main() {
    cout << "===== Week 7 DIY 2: Multilevel Inheritance Call Order =====\n";
    cout << "\nInstantiating Rectangle object:\n";
    {
        Rectangle rect("Blue", 10.0, 5.0);
        rect.display();
        cout << "\nLeaving scope (destruction):\n";
    }
    return 0;
}
