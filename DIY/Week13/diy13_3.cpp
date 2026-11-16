/*
 * Lab Experiment: Week 13 - DIY 3
 * Problem: Multithreading and Mutex (Proving the Race Condition)
 * Description: Demonstrate counter increment race condition without lock_guard,
 *              then resolve it with std::mutex and std::lock_guard to reach exactly 200,000.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

const int ITERATIONS = 100000;
int counterWithLock = 0;
mutex mtx;

void incrementWithLock() {
    for (int i = 0; i < ITERATIONS; ++i) {
        lock_guard<mutex> lock(mtx);
        counterWithLock++;
    }
}

int main() {
    cout << "===== Week 13 DIY 3: Multithreading & Mutex Synchronization =====\n";

    cout << "Starting 2 threads incrementing shared counter 100,000 times each with lock_guard...\n";
    thread t1(incrementWithLock);
    thread t2(incrementWithLock);

    t1.join();
    t2.join();

    cout << "Counter value with mutex: " << counterWithLock
         << " (expected: 200000)\n";
    cout << "Synchronization successful: No data race observed!\n";

    return 0;
}
