/*
 * Lab Experiment: Week 1 - DIY 2
 * Problem: Anagram Test
 * Description: Read two words and decide whether one is an anagram of the other
 *              using character frequencies.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

bool areAnagrams(const string &s1, const string &s2) {
    vector<int> freq(256, 0);
    int len1 = 0, len2 = 0;

    for (char c : s1) {
        if (!isspace(static_cast<unsigned char>(c))) {
            freq[tolower(static_cast<unsigned char>(c))]++;
            len1++;
        }
    }
    for (char c : s2) {
        if (!isspace(static_cast<unsigned char>(c))) {
            freq[tolower(static_cast<unsigned char>(c))]--;
            len2++;
        }
    }

    if (len1 != len2) return false;

    for (int count : freq) {
        if (count != 0) return false;
    }
    return true;
}

int main() {
    cout << "===== Week 1 DIY 2: Anagram Test =====\n";
    string w1, w2;
    cout << "Enter first word (or enter for 'listen'): ";
    getline(cin, w1);
    if (w1.empty()) w1 = "listen";

    cout << "Enter second word (or enter for 'silent'): ";
    getline(cin, w2);
    if (w2.empty()) w2 = "silent";

    cout << "\nTesting: \"" << w1 << "\" and \"" << w2 << "\"\n";
    if (areAnagrams(w1, w2)) {
        cout << "Result: They ARE anagrams of each other.\n";
    } else {
        cout << "Result: They are NOT anagrams.\n";
    }

    return 0;
}
