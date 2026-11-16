/*
 * Lab Experiment: Week 9 - DIY 1
 * Problem: Safe Withdrawal with Custom Exception
 * Description: Extend BankAccount to throw a custom InsufficientFundsException
 *              when withdrawal amount exceeds available balance.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class InsufficientFundsException : public exception {
private:
    string msg;

public:
    InsufficientFundsException(double balance, double amount) {
        msg = "Insufficient Funds! Balance: $" + to_string(balance) +
              ", Requested: $" + to_string(amount);
    }

    const char* what() const noexcept override {
        return msg.c_str();
    }
};

class BankAccount {
private:
    int accNum;
    double balance;

public:
    BankAccount(int acc, double initBal) : accNum(acc), balance(initBal) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            throw InsufficientFundsException(balance, amount);
        }
        balance -= amount;
        cout << "Successfully withdrew $" << amount << ". New Balance: $" << balance << "\n";
    }

    double getBalance() const { return balance; }
};

int main() {
    cout << "===== Week 9 DIY 1: Safe Withdrawal Exception =====\n";
    BankAccount acc(1001, 500.0);

    try {
        cout << "Attempting to withdraw $200...\n";
        acc.withdraw(200.0);

        cout << "\nAttempting to withdraw $400...\n";
        acc.withdraw(400.0); // Should throw InsufficientFundsException
    } catch (const InsufficientFundsException &ex) {
        cout << "Caught Exception: " << ex.what() << "\n";
    }

    cout << "\nFinal Account Balance: $" << acc.getBalance() << "\n";
    return 0;
}
