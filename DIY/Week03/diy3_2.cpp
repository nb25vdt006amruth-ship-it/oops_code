/*
 * Lab Experiment: Week 3 - DIY 2
 * Problem: Counter Array
 * Description: A Counter class with increment(), reset(), and get();
 *              create an array of 3 counters and exercise them.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>

using namespace std;

class Counter {
private:
    int count;

public:
    Counter(int initial = 0) : count(initial) {}

    void increment() {
        count++;
    }

    void reset() {
        count = 0;
    }

    int get() const {
        return count;
    }
};

int main() {
    cout << "===== Week 3 DIY 2: Counter Array =====\n";
    const int NUM_COUNTERS = 3;
    Counter counters[NUM_COUNTERS];

    // Exercising the counters
    cout << "Exercising counters...\n";
    for (int i = 0; i < 5; ++i) counters[0].increment(); // counter 0: 5
    for (int i = 0; i < 12; ++i) counters[1].increment(); // counter 1: 12
    for (int i = 0; i < 3; ++i) counters[2].increment(); // counter 2: 3

    for (int i = 0; i < NUM_COUNTERS; ++i) {
        cout << "Counter [" << i << "] value: " << counters[i].get() << "\n";
    }

    cout << "\nResetting counter 1...\n";
    counters[1].reset();
    cout << "Counter [1] after reset: " << counters[1].get() << "\n";

    return 0;
}
