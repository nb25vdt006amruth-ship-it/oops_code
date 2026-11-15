/*
 * Lab Experiment: Week 6 - DIY 2
 * Problem: Fraction I/O and Auto-Simplification
 * Description: Fraction class; overload << and >> operators and auto-simplify
 *              by dividing by GCD on construction.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <numeric>

using namespace std;

class Fraction {
private:
    int num;
    int den;

    void simplify() {
        if (den < 0) {
            num = -num;
            den = -den;
        }
        if (den == 0) {
            cout << "Warning: denominator cannot be zero. Resetting to 1.\n";
            den = 1;
        }
        int g = std::gcd(abs(num), abs(den));
        if (g != 0) {
            num /= g;
            den /= g;
        }
    }

public:
    Fraction(int n = 0, int d = 1) : num(n), den(d) {
        simplify();
    }

    friend ostream& operator<<(ostream &os, const Fraction &f) {
        if (f.den == 1) os << f.num;
        else os << f.num << "/" << f.den;
        return os;
    }

    friend istream& operator>>(istream &is, Fraction &f) {
        char slash;
        if (is >> f.num >> slash >> f.den) {
            f.simplify();
        }
        return is;
    }
};

int main() {
    cout << "===== Week 6 DIY 2: Fraction I/O and Auto-Simplify =====\n";
    Fraction f1(12, 18);
    cout << "Fraction(12, 18) auto-simplified: " << f1 << "\n";

    Fraction f2(-14, 28);
    cout << "Fraction(-14, 28) auto-simplified: " << f2 << "\n";

    Fraction f3(9, 3);
    cout << "Fraction(9, 3) auto-simplified: " << f3 << "\n";

    return 0;
}
