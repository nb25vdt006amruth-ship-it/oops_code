/*
 * Lab Experiment: Week 12 - DIY 3
 * Problem: Custom Aggregates with std::accumulate and Lambdas
 * Description: Use accumulate with lambdas to compute:
 *              1) Product of all elements
 *              2) Sum of only even elements
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    cout << "===== Week 12 DIY 3: Custom Aggregates with std::accumulate =====\n";
    vector<int> numbers = {1, 2, 3, 4, 5, 6};

    cout << "Numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << "\n\n";

    // 1. Product of all elements
    long long product = accumulate(numbers.begin(), numbers.end(), 1LL, [](long long acc, int val) {
        return acc * val;
    });
    cout << "Product of all elements: " << product << " (1*2*3*4*5*6)\n";

    // 2. Sum of only even elements
    int sumEven = accumulate(numbers.begin(), numbers.end(), 0, [](int acc, int val) {
        return (val % 2 == 0) ? (acc + val) : acc;
    });
    cout << "Sum of even elements:    " << sumEven << " (2+4+6)\n";

    return 0;
}
