/*
 * Lab Experiment: Week 10 - DIY 3
 * Problem: Records into Objects
 * Description: Store name and marks pairs in a file, read them back into an array
 *              of Student objects, and print the topper.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
    string name;
    float marks;

public:
    Student(const string &n = "", float m = 0.0f) : name(n), marks(m) {}

    string getName() const { return name; }
    float getMarks() const { return marks; }

    void display() const {
        cout << "Name: " << name << ", Marks: " << marks << "\n";
    }
};

void prepareRecordsFile(const string &filename) {
    ofstream out(filename);
    if (out) {
        out << "Aarav 88.5\n"
            << "Diya 94.0\n"
            << "Rohan 76.5\n"
            << "Meera 91.0\n"
            << "Kabir 82.5\n";
    }
}

int main() {
    cout << "===== Week 10 DIY 3: Records into Objects & Find Topper =====\n";
    const string filename = "students.txt";

    prepareRecordsFile(filename);

    ifstream in(filename);
    if (!in) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    vector<Student> students;
    string name;
    float marks;
    while (in >> name >> marks) {
        students.push_back(Student(name, marks));
    }

    cout << "Loaded " << students.size() << " student records:\n";
    const Student *topper = nullptr;
    for (const auto &s : students) {
        s.display();
        if (topper == nullptr || s.getMarks() > topper->getMarks()) {
            topper = &s;
        }
    }

    if (topper) {
        cout << "\n>>> TOPPER: " << topper->getName()
             << " with " << topper->getMarks() << " marks <<<\n";
    }

    return 0;
}
