/*
 * Lab Experiment: Week 5 - DIY 2
 * Problem: Friend Comparison of Time
 * Description: Time class (hh:mm) and a friend function laterOf(Time, Time)
 *              returning the later of two times.
 * Author: Amruth RM (nb25vdt006)
 */

#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {}

    void display() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes;
    }

    // Friend function declaration
    friend Time laterOf(const Time &t1, const Time &t2);
};

// Friend function definition
Time laterOf(const Time &t1, const Time &t2) {
    int totalMin1 = t1.hours * 60 + t1.minutes;
    int totalMin2 = t2.hours * 60 + t2.minutes;
    return (totalMin1 >= totalMin2) ? t1 : t2;
}

int main() {
    cout << "===== Week 5 DIY 2: Friend Function Comparison =====\n";
    Time t1(14, 45);
    Time t2(16, 15);
    Time t3(9, 30);

    cout << "Time 1: "; t1.display(); cout << "\n";
    cout << "Time 2: "; t2.display(); cout << "\n";

    Time later = laterOf(t1, t2);
    cout << "Later of Time 1 and Time 2: "; later.display(); cout << "\n";

    Time later2 = laterOf(t1, t3);
    cout << "Later of Time 1 and Time 3: "; later2.display(); cout << "\n";

    return 0;
}
