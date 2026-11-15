/*
 * Lab Experiment: Week 1 - DIY 1
 * Problem: Vowel & Consonant Counter
 * Description: Read a sentence using getline(cin, s) and count how many vowels
 *              and consonants it contains.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void countVowelsAndConsonants(const string &s, int &vowels, int &consonants) {
    vowels = 0;
    consonants = 0;
    for (char ch : s) {
        if (isalpha(static_cast<unsigned char>(ch))) {
            char lower = tolower(static_cast<unsigned char>(ch));
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
}

int main() {
    cout << "===== Week 1 DIY 1: Vowel & Consonant Counter =====\n";
    cout << "Enter a sentence (or press enter for default test): ";
    string input;
    getline(cin, input);
    if (input.empty()) {
        input = "Object Oriented Programming in C++ Lab";
        cout << "Using test sentence: \"" << input << "\"\n";
    }

    int vowels = 0, consonants = 0;
    countVowelsAndConsonants(input, vowels, consonants);

    cout << "\nSentence: \"" << input << "\"\n";
    cout << "Total Vowels:     " << vowels << "\n";
    cout << "Total Consonants: " << consonants << "\n";

    return 0;
}
