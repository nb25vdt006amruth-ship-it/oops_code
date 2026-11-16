/*
 * Lab Experiment: Week 12 - DIY 1
 * Problem: Sort Pairs by Second Field using Lambda
 * Description: Given a vector<pair<string, int>>, sort by the integer (second)
 *              field ascending using std::sort with a lambda expression.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cout << "===== Week 12 DIY 1: Sort Pairs with Lambda =====\n";
    vector<pair<string, int>> students = {
        {"Rohan", 78},
        {"Diya", 92},
        {"Aarav", 85},
        {"Meera", 88},
        {"Kabir", 67}
    };

    cout << "Before sorting:\n";
    for (const auto &p : students) {
        cout << "  " << p.first << ": " << p.second << "\n";
    }

    // Sort by second field (marks) ascending using lambda
    sort(students.begin(), students.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second < b.second;
    });

    cout << "\nAfter sorting ascending by score:\n";
    for (const auto &p : students) {
        cout << "  " << p.first << ": " << p.second << "\n";
    }

    return 0;
}
