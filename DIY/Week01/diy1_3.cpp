/*
 * Lab Experiment: Week 1 - DIY 3
 * Problem: Reverse the Words
 * Description: Read a sentence like "hello world cpp" and print "cpp world hello"
 *              (reverse word order, keeping character order within words).
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string reverseWordOrder(const string &sentence) {
    stringstream ss(sentence);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    string result;
    for (int i = static_cast<int>(words.size()) - 1; i >= 0; --i) {
        result += words[i];
        if (i > 0) result += " ";
    }
    return result;
}

int main() {
    cout << "===== Week 1 DIY 3: Reverse Words in Sentence =====\n";
    cout << "Enter a sentence (or press enter for default test): ";
    string input;
    getline(cin, input);
    if (input.empty()) {
        input = "hello world cpp";
        cout << "Using test sentence: \"" << input << "\"\n";
    }

    string reversed = reverseWordOrder(input);
    cout << "\nOriginal: \"" << input << "\"\n";
    cout << "Reversed: \"" << reversed << "\"\n";

    return 0;
}
