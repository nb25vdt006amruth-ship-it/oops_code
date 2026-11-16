/*
 * Course: Object-Oriented Programming in C++ Lab (ECE121)
 * Task 2: Student Result Management System (Weeks 7-13 Concepts)
 * Author: Amruth RM (USN/ID: nb25vdt006)
 *
 * Concepts Demonstrated:
 *  - Inheritance (Base: Student -> Derived: Result)
 *  - Virtual Functions and Runtime Polymorphism
 *  - Virtual Destructor
 *  - STL vector container
 *  - Exception Handling (Custom InvalidMarksException & range check)
 *  - File Handling (saveToFile & loadFromFile with ifstream/ofstream)
 *  - Function Template (validateRange)
 *  - STL Algorithms (copy_if, count_if, sort) and Lambda Expressions
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

using namespace std;

// Custom exception for invalid marks
class InvalidMarksException : public runtime_error {
public:
    explicit InvalidMarksException(const string &msg) : runtime_error(msg) {}
};

// Function template: validates that a value lies in [lo, hi]
template <typename T>
void validateRange(T value, T lo, T hi, const string &label) {
    if (value < lo || value > hi) {
        throw InvalidMarksException("Invalid marks for " + label + ": " +
            to_string(value) + " (allowed " + to_string(lo) + "-" + to_string(hi) + ")");
    }
}

// Base class
class Student {
protected:
    int id;
    string name;

public:
    Student(int i = 0, string n = "") : id(i), name(n) {}
    virtual ~Student() {}

    int getId() const { return id; }
    string getName() const { return name; }

    // Virtual functions for runtime polymorphism
    virtual void display() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    virtual void displayMarks() const {
        cout << "No marks available for a plain Student." << endl;
    }
};

// Derived class
class Result : public Student {
private:
    static const int SUBJECTS = 3;
    int marks[SUBJECTS];

public:
    Result(int i, string n, int m1, int m2, int m3) : Student(i, n) {
        validateRange(m1, 0, 100, "Maths");
        validateRange(m2, 0, 100, "Physics");
        validateRange(m3, 0, 100, "C++");
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    int getTotal() const { return marks[0] + marks[1] + marks[2]; }
    double getPercentage() const { return getTotal() / 3.0; }
    int getMark(int k) const { return marks[k]; }

    bool isPass() const {
        for (int k = 0; k < SUBJECTS; k++) {
            if (marks[k] < 40) return false;
        }
        return true;
    }

    void display() const override {
        Student::display();
    }

    void displayMarks() const override {
        cout << "\tMaths: " << marks[0] << ", Physics: " << marks[1]
             << ", C++: " << marks[2] << " | Total: " << getTotal()
             << "/300 | " << fixed << setprecision(2) << getPercentage()
             << "% | " << (isPass() ? "PASS" : "FAIL") << endl;
    }

    // Serialized format used by file handling
    string toRecord() const {
        return to_string(id) + " " + name + " " + to_string(marks[0]) + " " +
               to_string(marks[1]) + " " + to_string(marks[2]);
    }
};

// File handling: Save records to file
void saveToFile(const vector<Result> &v, const string &fname) {
    ofstream out(fname);
    if (!out) throw runtime_error("Cannot open file for writing: " + fname);
    for (const Result &r : v) {
        out << r.toRecord() << "\n";
    }
}

// File handling: Load records from file
vector<Result> loadFromFile(const string &fname) {
    ifstream in(fname);
    if (!in) throw runtime_error("Cannot open file for reading: " + fname);
    vector<Result> v;
    int id, a, b, c;
    string name;
    while (in >> id >> name >> a >> b >> c) {
        v.push_back(Result(id, name, a, b, c));
    }
    return v;
}

void showAll(const vector<Result> &v) {
    for (const Result &r : v) {
        r.display();
        r.displayMarks();
    }
}

int main() {
    vector<Result> records;

    cout << "===== Student Result Management System =====\n\n";
    cout << "--- Adding students (with mark validation) ---\n";

    struct Entry { int id; string name; int m1, m2, m3; };
    vector<Entry> input = {
        {101, "Aarav", 85, 78, 92},
        {102, "Diya", 91, 88, 95},
        {103, "Rohan", 35, 60, 72},
        {104, "Meera", 105, 80, 70}, // Deliberately invalid: 105 > 100
        {105, "Kabir", 67, 74, 58}
    };

    for (const Entry &e : input) {
        try {
            records.push_back(Result(e.id, e.name, e.m1, e.m2, e.m3));
            cout << "Added: " << e.name << endl;
        } catch (const InvalidMarksException &ex) {
            cout << "Skipped " << e.name << " - " << ex.what() << endl;
        }
    }

    cout << "\n--- Records stored in vector ---\n";
    showAll(records);

    cout << "\n--- Runtime polymorphism (base class reference) ---\n";
    const Student &polyRef = records[0];
    polyRef.display();
    polyRef.displayMarks();

    cout << "\n--- File handling ---\n";
    saveToFile(records, "records.txt");
    cout << records.size() << " records saved to records.txt\n";

    vector<Result> loaded = loadFromFile("records.txt");
    cout << loaded.size() << " records loaded from records.txt:\n";
    showAll(loaded);

    cout << "\n--- Students scoring above 200 total marks (lambda + STL) ---\n";
    vector<Result> toppers;
    copy_if(loaded.begin(), loaded.end(), back_inserter(toppers), [](const Result &r) {
        return r.getTotal() > 200;
    });
    for (const auto &r : toppers) {
        cout << r.getName() << " - " << r.getTotal() << endl;
    }

    int passed = count_if(loaded.begin(), loaded.end(), [](const Result &r) {
        return r.isPass();
    });
    int failed = static_cast<int>(loaded.size()) - passed;
    cout << "\nTotal students: " << loaded.size() << ", Passed: " << passed << ", Failed: " << failed << "\n";

    cout << "\n--- Ranking by total marks (sort with lambda) ---\n";
    sort(loaded.begin(), loaded.end(), [](const Result &a, const Result &b) {
        return a.getTotal() > b.getTotal();
    });
    for (size_t i = 0; i < loaded.size(); ++i) {
        cout << (i + 1) << ". " << loaded[i].getName() << " (" << loaded[i].getTotal() << ")\n";
    }

    return 0;
}
