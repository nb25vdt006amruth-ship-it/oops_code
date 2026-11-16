/*
 * Lab Experiment: Week 11 - DIY 2
 * Problem: Generic Queue Class Template
 * Description: Implement a class template Queue<T> with enqueue, dequeue, front,
 *              isEmpty, and size; test with string and int.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
private:
    vector<T> elements;

public:
    void enqueue(const T &item) {
        elements.push_back(item);
    }

    T dequeue() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        T item = elements.front();
        elements.erase(elements.begin());
        return item;
    }

    T front() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty!");
        }
        return elements.front();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    cout << "===== Week 11 DIY 2: Generic Queue Class Template =====\n";

    Queue<string> stringQueue;
    cout << "Enqueueing strings: Alpha, Beta, Gamma\n";
    stringQueue.enqueue("Alpha");
    stringQueue.enqueue("Beta");
    stringQueue.enqueue("Gamma");

    cout << "Front item: " << stringQueue.front() << "\n";
    cout << "Queue size: " << stringQueue.size() << "\n";

    cout << "Dequeuing all items: ";
    while (!stringQueue.isEmpty()) {
        cout << stringQueue.dequeue() << " ";
    }
    cout << "\n";

    return 0;
}
