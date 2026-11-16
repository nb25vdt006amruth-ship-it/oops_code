/*
 * Lab Experiment: Week 11 - DIY 1
 * Problem: Generic Utilities with Function Templates
 * Description: Write template functions swapVals(T&, T&) and findMax(T arr[], int n)
 *              and test with int, double, and string.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <string>

using namespace std;

template <typename T>
void swapVals(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T findMax(const T arr[], int n) {
    T maxVal = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    cout << "===== Week 11 DIY 1: Generic Utilities (Templates) =====\n";

    // Testing swapVals
    int x = 10, y = 20;
    cout << "Before swap: x=" << x << ", y=" << y << "\n";
    swapVals(x, y);
    cout << "After swap:  x=" << x << ", y=" << y << "\n\n";

    string s1 = "Apple", s2 = "Orange";
    cout << "Before swap: s1=" << s1 << ", s2=" << s2 << "\n";
    swapVals(s1, s2);
    cout << "After swap:  s1=" << s1 << ", s2=" << s2 << "\n\n";

    // Testing findMax
    int intArr[] = {5, 23, 89, 42, 12};
    cout << "Max int in array:    " << findMax(intArr, 5) << "\n";

    double dblArr[] = {3.14, 2.718, 9.81, 1.414};
    cout << "Max double in array: " << findMax(dblArr, 4) << "\n";

    return 0;
}
