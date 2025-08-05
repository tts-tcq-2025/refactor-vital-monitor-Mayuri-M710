#include "./alert_system.h"
#include <iostream>
#include <thread>
#include <chrono>

using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

void printAlert(const char* message) {
    cout << message << "\n";
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

int handleVitalAlert(bool isOk, const char* message) {
    if (!isOk) {
        printAlert(message);
        return 0;
    }
    return 1;
}
