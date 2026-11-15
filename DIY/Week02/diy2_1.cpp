/*
 * Lab Experiment: Week 2 - DIY 1
 * Problem: Overloaded volume function
 * Description: Write three overloads computing the volume of a cube (1 arg),
 *              cuboid (3 args), and cylinder (2 args: radius & height).
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Volume of a cube: side^3
double volume(double side) {
    return side * side * side;
}

// Volume of a cuboid: l * w * h
double volume(double length, double width, double height) {
    return length * width * height;
}

// Volume of a cylinder: pi * r^2 * h
double volume(double radius, double height) {
    const double PI = 3.14159265358979323846;
    return PI * radius * radius * height;
}

int main() {
    cout << "===== Week 2 DIY 1: Overloaded Volume Function =====\n";
    cout << fixed << setprecision(3);

    double cubeSide = 4.0;
    cout << "Cube (side = " << cubeSide << "): "
         << volume(cubeSide) << " cubic units\n";

    double l = 5.0, w = 3.0, h = 2.5;
    cout << "Cuboid (l=" << l << ", w=" << w << ", h=" << h << "): "
         << volume(l, w, h) << " cubic units\n";

    double r = 3.0, cylH = 7.0;
    cout << "Cylinder (r=" << r << ", h=" << cylH << "): "
         << volume(r, cylH) << " cubic units\n";

    return 0;
}
