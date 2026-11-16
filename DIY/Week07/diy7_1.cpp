/*
 * Lab Experiment: Week 7 - DIY 1
 * Problem: Employee Hierarchy (Inheritance)
 * Description: Base Employee (name, id); derive Manager (adds team size)
 *              and Engineer (adds skill); print details of each.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string &n, int i) : name(n), id(i) {}

    virtual void display() const {
        cout << "Employee ID: " << id << ", Name: " << name;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(const string &n, int i, int ts)
        : Employee(n, i), teamSize(ts) {}

    void display() const override {
        Employee::display();
        cout << " | Role: Manager | Team Size: " << teamSize << "\n";
    }
};

class Engineer : public Employee {
private:
    string skill;

public:
    Engineer(const string &n, int i, const string &s)
        : Employee(n, i), skill(s) {}

    void display() const override {
        Employee::display();
        cout << " | Role: Engineer | Skill: " << skill << "\n";
    }
};

int main() {
    cout << "===== Week 7 DIY 1: Employee Hierarchy =====\n";
    Manager m("Alice Johnson", 1001, 8);
    Engineer e("Bob Smith", 1002, "C++ & VLSI Design");

    m.display();
    e.display();

    return 0;
}
