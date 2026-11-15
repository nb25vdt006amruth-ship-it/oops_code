/*
 * Lab Experiment: Week 5 - DIY 3
 * Problem: Unique ID Factory with Static Member
 * Description: Every new Order object automatically receives the next unique ID
 *              (1001, 1002, ...) in its constructor.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <string>

using namespace std;

class Order {
private:
    static int nextId;
    int orderId;
    string item;
    double price;

public:
    Order(const string &itemName, double itemPrice)
        : orderId(nextId++), item(itemName), price(itemPrice) {}

    void display() const {
        cout << "Order ID: #" << orderId << " | Item: " << item
             << " | Price: $" << price << "\n";
    }

    static int getNextAssignedId() {
        return nextId;
    }
};

// Initial ID sequence starting at 1001
int Order::nextId = 1001;

int main() {
    cout << "===== Week 5 DIY 3: Unique ID Factory =====\n";
    Order o1("Laptop", 1200.0);
    Order o2("Wireless Mouse", 25.50);
    Order o3("Mechanical Keyboard", 85.0);

    o1.display();
    o2.display();
    o3.display();

    cout << "\nNext available order ID will be: #" << Order::getNextAssignedId() << "\n";
    return 0;
}
