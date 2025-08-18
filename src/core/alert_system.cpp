#include "alert_system.h"
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

void printWarning(const char* message) {
    cout << "! " << message << "\n";
}

bool isCriticalStatus(VitalStatus status) {
    return status == VitalStatus::CRITICAL_LOW || status == VitalStatus::CRITICAL_HIGH;
}

bool isWarningStatus(VitalStatus status) {
    return status == VitalStatus::WARNING_LOW || status == VitalStatus::WARNING_HIGH;
}

int processVitalStatus(VitalStatus status, const char* criticalMsg, 
                      const char* warningMsg, OutputFunction output) {
    if (isCriticalStatus(status) && output && criticalMsg) {
        output(criticalMsg);
        return 0;
    }
    if (isWarningStatus(status) && output && warningMsg) {
        output(warningMsg);
    }
    return 1;
}

int handleVitalWithOutput(VitalStatus status, const char* criticalMsg, 
                         const char* warningMsg, OutputFunction output) {
    return processVitalStatus(status, criticalMsg, warningMsg, output);
}

int handleVitalAlert(bool isOk, const char* message) {
    if (!isOk) {
        printAlert(message);
        return 0;
    }
    return 1;
}
