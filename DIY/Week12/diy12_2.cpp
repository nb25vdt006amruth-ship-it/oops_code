/*
 * Lab Experiment: Week 12 - DIY 2
 * Problem: Top-3 Largest Numbers using priority_queue (Heap)
 * Description: Read N numbers and print the three largest using a priority_queue
 *              without sorting the entire array.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    cout << "===== Week 12 DIY 2: Top-3 with Heap (priority_queue) =====\n";
    vector<int> numbers = {45, 12, 89, 7, 63, 91, 34, 99, 23, 78};

    cout << "Input numbers: ";
    for (int n : numbers) cout << n << " ";
    cout << "\n\n";

    // Min-heap to maintain top 3 elements in O(N log K) time
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int n : numbers) {
        minHeap.push(n);
        if (minHeap.size() > 3) {
            minHeap.pop(); // Remove smallest among top elements
        }
    }

    vector<int> top3;
    while (!minHeap.empty()) {
        top3.push_back(minHeap.top());
        minHeap.pop();
    }

    cout << "Top 3 largest numbers: ";
    for (int i = static_cast<int>(top3.size()) - 1; i >= 0; --i) {
        cout << top3[i] << " ";
    }
    cout << "\n";

    return 0;
}
