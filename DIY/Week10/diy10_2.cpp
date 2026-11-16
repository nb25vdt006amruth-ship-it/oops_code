/*
 * Lab Experiment: Week 10 - DIY 2
 * Problem: Line-Numbered File Copy
 * Description: Read in.txt and write out.txt with each line prefixed by its line number.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void prepareSampleInput(const string &filename) {
    ofstream out(filename);
    if (out) {
        out << "Object-Oriented Programming in C++\n"
            << "Nitte Meenakshi Institute of Technology\n"
            << "Department of VLSI Design & Technology\n"
            << "Standard Template Library and File Handling\n";
    }
}

int main() {
    cout << "===== Week 10 DIY 2: Line-Numbered File Copy =====\n";
    const string inFile = "in.txt";
    const string outFile = "out.txt";

    prepareSampleInput(inFile);

    ifstream in(inFile);
    ofstream out(outFile);

    if (!in || !out) {
        cerr << "File open error!\n";
        return 1;
    }

    string line;
    int lineNum = 1;
    while (getline(in, line)) {
        out << lineNum << ": " << line << "\n";
        cout << lineNum << ": " << line << "\n";
        lineNum++;
    }

    cout << "\nCopied " << (lineNum - 1) << " lines to " << outFile << " successfully.\n";
    return 0;
}
