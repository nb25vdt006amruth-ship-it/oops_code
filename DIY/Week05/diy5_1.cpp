/*
 * Lab Experiment: Week 5 - DIY 1
 * Problem: Object Counter with Static Members
 * Description: Add static members to Counter class reporting total objects created
 *              and currently alive instances.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>

using namespace std;

class Counter {
private:
    int id;
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter(int i = 0) : id(i) {
        totalCreated++;
        currentlyAlive++;
        cout << "Counter " << id << " created.\n";
    }

    ~Counter() {
        currentlyAlive--;
        cout << "Counter " << id << " destroyed.\n";
    }

    static void printStats() {
        cout << "[STATS] Total Ever Created: " << totalCreated
             << ", Currently Alive: " << currentlyAlive << "\n";
    }
};

int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    cout << "===== Week 5 DIY 1: Object Counter =====\n";
    Counter::printStats();

    Counter c1(1);
    Counter c2(2);
    Counter::printStats();

    {
        cout << "\nEntering nested block:\n";
        Counter c3(3);
        Counter c4(4);
        Counter::printStats();
        cout << "Exiting nested block:\n";
    }

    cout << "\nAfter nested block:\n";
    Counter::printStats();

    return 0;
}
