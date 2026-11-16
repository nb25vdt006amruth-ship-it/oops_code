/*
 * Lab Experiment: Week 8 - DIY 1
 * Problem: Abstract Account with Pure Virtual Function
 * Description: Abstract Account class with pure-virtual calculateInterest();
 *              derive Savings and Current accounts; process polymorphic Account* array.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Account {
protected:
    int accNo;
    double balance;

public:
    Account(int no, double bal) : accNo(no), balance(bal) {}
    virtual ~Account() {}

    // Pure virtual function
    virtual double calculateInterest() const = 0;

    virtual void display() const {
        cout << "Acc #" << accNo << " | Balance: $" << fixed << setprecision(2) << balance
             << " | Annual Interest: $" << calculateInterest() << "\n";
    }
};

class SavingsAccount : public Account {
private:
    double rate; // e.g., 4.5%

public:
    SavingsAccount(int no, double bal, double r = 4.5)
        : Account(no, bal), rate(r) {}

    double calculateInterest() const override {
        return balance * (rate / 100.0);
    }

    void display() const override {
        cout << "[Savings] ";
        Account::display();
    }
};

class CurrentAccount : public Account {
private:
    double rate; // e.g., 1.5%

public:
    CurrentAccount(int no, double bal, double r = 1.5)
        : Account(no, bal), rate(r) {}

    double calculateInterest() const override {
        return balance * (rate / 100.0);
    }

    void display() const override {
        cout << "[Current] ";
        Account::display();
    }
};

int main() {
    cout << "===== Week 8 DIY 1: Polymorphic Bank Accounts =====\n";
    vector<Account*> accounts = {
        new SavingsAccount(101, 15000.0, 5.0),
        new CurrentAccount(102, 50000.0, 1.5),
        new SavingsAccount(103, 8500.0, 4.0)
    };

    cout << "\nProcessing accounts polymorphically via base pointer:\n";
    for (Account *acc : accounts) {
        acc->display();
    }

    // Cleanup
    for (Account *acc : accounts) {
        delete acc;
    }
    return 0;
}
