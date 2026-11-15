/*
 * Lab Experiment: Week 6 - DIY 1
 * Problem: Money Arithmetic with Operator Overloading
 * Description: Money class (rupees, paise); overload + and - with correct carry
 *              and borrow of paise into rupees.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Money {
private:
    long long rupees;
    int paise;

    void normalize() {
        if (paise >= 100) {
            rupees += paise / 100;
            paise %= 100;
        } else if (paise < 0) {
            long long borrow = (-paise + 99) / 100;
            rupees -= borrow;
            paise += borrow * 100;
        }
    }

public:
    Money(long long r = 0, int p = 0) : rupees(r), paise(p) {
        normalize();
    }

    Money operator+(const Money &other) const {
        return Money(rupees + other.rupees, paise + other.paise);
    }

    Money operator-(const Money &other) const {
        return Money(rupees - other.rupees, paise - other.paise);
    }

    void display() const {
        cout << "Rs. " << rupees << "." << setfill('0') << setw(2) << paise;
    }
};

int main() {
    cout << "===== Week 6 DIY 1: Money Arithmetic (+ and -) =====\n";
    Money m1(150, 75);
    Money m2(49, 50);

    cout << "m1 = "; m1.display(); cout << "\n";
    cout << "m2 = "; m2.display(); cout << "\n";

    Money sum = m1 + m2;
    cout << "m1 + m2 = "; sum.display(); cout << " (with carry)\n";

    Money diff = m1 - m2;
    cout << "m1 - m2 = "; diff.display(); cout << " (with borrow)\n";

    return 0;
}
