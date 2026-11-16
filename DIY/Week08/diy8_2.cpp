/*
 * Lab Experiment: Week 8 - DIY 2
 * Problem: Polymorphic Logger Interface
 * Description: Abstract Logger with write(string); derive ConsoleLogger and
 *              FileLogger; switch loggers at runtime via pointer.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <fstream>
#include <string>
#include <memory>

using namespace std;

class Logger {
public:
    virtual ~Logger() {}
    virtual void write(const string &msg) = 0;
};

class ConsoleLogger : public Logger {
public:
    void write(const string &msg) override {
        cout << "[CONSOLE LOG] " << msg << endl;
    }
};

class FileLogger : public Logger {
private:
    string filename;

public:
    explicit FileLogger(const string &fname) : filename(fname) {}

    void write(const string &msg) override {
        ofstream out(filename, ios::app);
        if (out) {
            out << "[FILE LOG] " << msg << "\n";
            cout << "[FileLogger] Message written to " << filename << endl;
        }
    }
};

int main() {
    cout << "===== Week 8 DIY 2: Polymorphic Logger =====\n";
    ConsoleLogger console;
    FileLogger file("system_log.txt");

    Logger *logger = &console;
    logger->write("System initialized successfully.");

    // Switching logger at runtime
    logger = &file;
    logger->write("File logging activated: User logged in.");

    logger = &console;
    logger->write("Task finished.");

    return 0;
}
