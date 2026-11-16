/*
 * Lab Experiment: Week 10 - DIY 1
 * Problem: Number Statistics from File
 * Description: Read an unknown count of integers from nums.txt and print
 *              their count, sum, min, max, and average.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>

using namespace std;

void prepareSampleFile(const string &filename) {
    ofstream out(filename);
    if (out) {
        out << "42 17 89 5 23 99 12 67 34 8";
    }
}

int main() {
    cout << "===== Week 10 DIY 1: Number Statistics from File =====\n";
    const string filename = "nums.txt";

    // Ensure sample input file exists
    prepareSampleFile(filename);

    ifstream in(filename);
    if (!in) {
        cerr << "Error: Could not open " << filename << endl;
        return 1;
    }

    int num;
    int count = 0;
    long long sum = 0;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    while (in >> num) {
        count++;
        sum += num;
        minVal = min(minVal, num);
        maxVal = max(maxVal, num);
    }

    if (count > 0) {
        cout << "File: " << filename << "\n";
        cout << "Count:   " << count << "\n";
        cout << "Sum:     " << sum << "\n";
        cout << "Min:     " << minVal << "\n";
        cout << "Max:     " << maxVal << "\n";
        cout << "Average: " << (static_cast<double>(sum) / count) << "\n";
    } else {
        cout << "No numbers found in file.\n";
    }

    return 0;
}
