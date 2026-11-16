/*
 * Lab Experiment: Week 13 - DIY 1
 * Problem: Raw Pointers to Smart Pointers (std::unique_ptr)
 * Description: Rewrite dynamic memory allocation with unique_ptr and make_unique
 *              so no explicit delete remains and memory leaks are prevented.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Resource {
private:
    string name;

public:
    explicit Resource(const string &n) : name(n) {
        cout << "  [+] Resource '" << name << "' acquired\n";
    }

    ~Resource() {
        cout << "  [-] Resource '" << name << "' released automatically\n";
    }

    void operate() const {
        cout << "      Operating on resource '" << name << "'\n";
    }
};

int main() {
    cout << "===== Week 13 DIY 1: Smart Pointers (unique_ptr) =====\n";

    cout << "\nEntering scope:\n";
    {
        // Modern C++: no raw pointer, no delete
        unique_ptr<Resource> res = make_unique<Resource>("HardwareDriver");
        res->operate();
        cout << "Exiting scope (unique_ptr will automatically clean up):\n";
    }

    cout << "Scope exited successfully.\n";
    return 0;
}
