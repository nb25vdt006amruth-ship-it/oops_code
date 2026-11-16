/*
 * Lab Experiment: Week 11 - DIY 3
 * Problem: Word Frequency Counter using unordered_map
 * Description: Read words from input, use an unordered_map<string, int> to print
 *              each word with its count, and identify the most frequent word.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

int main() {
    cout << "===== Week 11 DIY 3: Frequency Counter (unordered_map) =====\n";
    string text = "cpp is powerful and cpp is fast and elegant cpp is modern";
    cout << "Input text:\n\"" << text << "\"\n\n";

    unordered_map<string, int> freq;
    stringstream ss(text);
    string word;

    while (ss >> word) {
        freq[word]++;
    }

    cout << "Word Frequencies:\n";
    string mostFrequent;
    int maxCount = 0;

    for (const auto &pair : freq) {
        cout << "  " << pair.first << ": " << pair.second << "\n";
        if (pair.second > maxCount) {
            maxCount = pair.second;
            mostFrequent = pair.first;
        }
    }

    cout << "\nMost frequent word: \"" << mostFrequent
         << "\" (occurred " << maxCount << " times)\n";

    return 0;
}
