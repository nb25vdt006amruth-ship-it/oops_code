/*
 * Lab Experiment: Week 7 - DIY 3
 * Problem: Resolving Diamond Problem with Virtual Base Class
 * Description: Build Person -> Student, Person -> Employee, then TA inheriting both.
 *              Use virtual inheritance so Person appears exactly once without ambiguity.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <string>

using namespace std;

// Base class
class Person {
protected:
    string name;

public:
    Person(const string &n) : name(n) {
        cout << "Person constructor called for: " << name << "\n";
    }
    virtual ~Person() {}

    void printName() const {
        cout << "Name: " << name << "\n";
    }
};

// Virtual inheritance avoids duplicate Person subobjects
class Student : virtual public Person {
protected:
    int studentId;

public:
    Student(const string &n, int sid) : Person(n), studentId(sid) {
        cout << "Student constructor called (ID: " << studentId << ")\n";
    }
};

class Employee : virtual public Person {
protected:
    int empId;

public:
    Employee(const string &n, int eid) : Person(n), empId(eid) {
        cout << "Employee constructor called (EmpID: " << empId << ")\n";
    }
};

// Teaching Assistant inherits from both Student and Employee
class TA : public Student, public Employee {
private:
    string course;

public:
    TA(const string &n, int sid, int eid, const string &c)
        : Person(n), Student(n, sid), Employee(n, eid), course(c) {
        cout << "TA constructor called (Course: " << course << ")\n";
    }

    void displayTA() const {
        cout << "\n--- Teaching Assistant Details ---\n";
        printName(); // Unambiguous call thanks to virtual inheritance!
        cout << "Student ID: " << studentId << "\n";
        cout << "Employee ID: " << empId << "\n";
        cout << "Course:      " << course << "\n";
    }
};

int main() {
    cout << "===== Week 7 DIY 3: Diamond Problem Resolution =====\n";
    TA ta("Amruth RM", 2026101, 905, "Object-Oriented Programming");
    ta.displayTA();
    return 0;
}
