/*
 * Lab Experiment: Week 4 - DIY 3
 * Problem: Lifetime Logger with Dynamic Allocation
 * Description: Extend Program 4.1 so Tracer objects are created dynamically
 *              with new inside a loop and explicitly deleted to demonstrate proper cleanup.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>

using namespace std;

class Tracer {
private:
    int id;

public:
    explicit Tracer(int i) : id(i) {
        cout << "  [+] Tracer " << id << " created at " << this << "\n";
    }

    ~Tracer() {
        cout << "  [-] Tracer " << id << " destroyed from " << this << "\n";
    }

    void doWork() const {
        cout << "      Tracer " << id << " performing operation.\n";
    }
};

int main() {
    cout << "===== Week 4 DIY 3: Lifetime Logger (Dynamic Allocation) =====\n";

    cout << "\nCreating and properly deleting dynamic Tracer objects in loop:\n";
    for (int i = 1; i <= 3; ++i) {
        Tracer *t = new Tracer(i);
        t->doWork();
        delete t; // Explicit cleanup avoids memory leak
        t = nullptr;
    }

    cout << "\nAll objects properly managed and released.\n";
    return 0;
}
