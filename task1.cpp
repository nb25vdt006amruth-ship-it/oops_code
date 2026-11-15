/*
 * Course: Object-Oriented Programming in C++ Lab (ECE121)
 * Task 1: Student Management System using OOP in C++ (Weeks 1-6 Concepts)
 * Author: Amruth RM (USN/ID: nb25vdt006)
 *
 * Concepts Demonstrated:
 *  - Classes and Encapsulation
 *  - Parameterized Constructor with Initializer List
 *  - Destructor for Resource/Count Management
 *  - Dynamic Memory Management (new and delete)
 *  - Static Data Member and Static Member Function
 *  - Function Overloading (display)
 *  - Friend Function (showDetails)
 *  - Operator Overloading (operator>)
 *  - const Correctness
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;
    static int count; // Shared student counter

public:
    // Parameterized constructor
    Student(int r, const string &n, float m) : rollNo(r), name(n), marks(m) {
        count++;
    }

    // Destructor
    ~Student() {
        count--;
    }

    // Getters
    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    float getMarks() const { return marks; }

    // Validating setter
    void setMarks(float m) {
        if (m >= 0.0f && m <= 100.0f) {
            marks = m;
        } else {
            cout << "Invalid marks! Must be between 0 and 100." << endl;
        }
    }

    // Static member function to retrieve count
    static int getCount() {
        return count;
    }

    // Overloaded display functions
    void display() const {
        cout << "Roll No: " << rollNo << ", Name: " << name << endl;
    }

    void display(bool showMarks) const {
        if (showMarks) {
            cout << "Roll No: " << rollNo << ", Name: " << name
                 << ", Marks: " << fixed << setprecision(2) << marks << endl;
        } else {
            display();
        }
    }

    // Overloaded > operator comparing marks
    bool operator>(const Student &other) const {
        return this->marks > other.marks;
    }

    // Friend function declaration
    friend void showDetails(const Student &s);
};

// Definition of static data member
int Student::count = 0;

// Friend function definition
void showDetails(const Student &s) {
    cout << "[Friend] " << s.name << " (Roll " << s.rollNo << ") scored "
         << fixed << setprecision(2) << s.marks << " marks." << endl;
}

int main() {
    cout << "Student Management using OOP in C++\n";
    
    // Creating static Student objects
    Student s1(101, "Aarav", 85.50f);
    Student s2(102, "Diya", 92.00f);
    Student s3(103, "Rohan", 78.25f);

    cout << "Total students created: " << Student::getCount() << "\n\n";

    cout << "--- Student Details (overloaded display) ---\n";
    s1.display(false); // Overload 1: basic display
    s2.display(true);  // Overload 2: detailed display with marks
    s3.display(true);

    cout << "\n--- Friend Function ---\n";
    showDetails(s1);
    showDetails(s2);
    showDetails(s3);

    cout << "\n--- Comparison using overloaded > operator ---\n";
    if (s2 > s1) {
        cout << s2.getName() << " has higher marks than " << s1.getName() << endl;
    } else {
        cout << s1.getName() << " has higher marks than " << s2.getName() << endl;
    }

    if (s1 > s3) {
        cout << s1.getName() << " has higher marks than " << s3.getName() << endl;
    } else {
        cout << s3.getName() << " has higher marks than " << s1.getName() << endl;
    }

    cout << "\n--- Dynamic object creation ---\n";
    Student *s4 = new Student(104, "Meera", 88.00f);
    s4->display(true);
    cout << "Total students now: " << Student::getCount() << endl;

    delete s4;
    s4 = nullptr;
    cout << "After deleting Meera, total students: " << Student::getCount() << endl;

    return 0;
}
