/*
 * Lab Experiment: Week 2 - DIY 3
 * Problem: Inline Overloaded minVal
 * Description: Write an inline overloaded minVal returning the smaller of two ints,
 *              and via a second overload, the smallest of three ints.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>

using namespace std;

// Inline function for minimum of two ints
inline int minVal(int a, int b) {
    return (a < b) ? a : b;
}

// Inline overloaded function for minimum of three ints
inline int minVal(int a, int b, int c) {
    return minVal(minVal(a, b), c);
}

int main() {
    cout << "===== Week 2 DIY 3: Inline Overloaded minVal =====\n";
    int x = 25, y = 42, z = 17;

    cout << "Comparing " << x << " and " << y << ": minVal = "
         << minVal(x, y) << "\n";
    cout << "Comparing " << x << ", " << y << ", and " << z << ": minVal = "
         << minVal(x, y, z) << "\n";

    return 0;
}
