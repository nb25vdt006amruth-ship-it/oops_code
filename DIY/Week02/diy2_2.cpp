/*
 * Lab Experiment: Week 2 - DIY 2
 * Problem: Default-Argument Calculator (power)
 * Description: Write power(int base, int exp = 2) so power(5) gives 25
 *              and power(2, 10) gives 1024.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>

using namespace std;

long long power(int base, int exp = 2) {
    long long result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    cout << "===== Week 2 DIY 2: Default-Argument Calculator =====\n";
    cout << "power(5)       = " << power(5) << " (uses default exp = 2)\n";
    cout << "power(2, 10)   = " << power(2, 10) << " (explicit exp = 10)\n";
    cout << "power(3, 4)    = " << power(3, 4) << "\n";
    cout << "power(7)       = " << power(7) << "\n";
    return 0;
}
