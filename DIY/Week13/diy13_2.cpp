/*
 * Lab Experiment: Week 13 - DIY 2
 * Problem: Shape Factory Pattern v2 with unique_ptr
 * Description: Shape factory supporting Circle, Rectangle, and Triangle;
 *              returns unique_ptr<Shape> and stores in vector<unique_ptr<Shape>>.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <memory>
#include <vector>
#include <string>

using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual void draw() const = 0;
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing Circle (O)\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing Rectangle [---]\n";
    }
};

class Triangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing Triangle /\\ \n";
    }
};

// Factory function
unique_ptr<Shape> createShape(const string &type) {
    if (type == "circle") return make_unique<Circle>();
    if (type == "rectangle") return make_unique<Rectangle>();
    if (type == "triangle") return make_unique<Triangle>();
    return nullptr;
}

int main() {
    cout << "===== Week 13 DIY 2: Shape Factory v2 (unique_ptr) =====\n";
    vector<unique_ptr<Shape>> shapes;

    shapes.push_back(createShape("circle"));
    shapes.push_back(createShape("rectangle"));
    shapes.push_back(createShape("triangle"));

    cout << "\nRendering shapes from polymorphic vector<unique_ptr<Shape>>:\n";
    for (const auto &s : shapes) {
        if (s) s->draw();
    }

    return 0;
}
