#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

struct PulseRateRange {
    int minAge;
    int maxAge;
    float minPulse;
    float maxPulse;
};

static const PulseRateRange pulseRateRanges[] = {
    {0, 0, 100, 160},    // newborn
    {1, 5, 80, 140},     // infant/toddler
    {6, 10, 70, 110},    // child
    {11, 14, 60, 105},   // adolescent
    {15, 200, 60, 100}   // adult (assuming max age 200)
};

bool isTemperatureOk(float temperature) {
    return temperature >= 95 && temperature <= 102;
}

bool isPulseRateOk(float pulseRate, int age) {
    for (const auto& range : pulseRateRanges) {
        if (age >= range.minAge && age <= range.maxAge) {
            return pulseRate >= range.minPulse && pulseRate <= range.maxPulse;
        }
    }
    return false; // age not found
}

bool isSpO2Ok(float spo2) {
    return spo2 >= 90;
}

void printAlert(const char* message) {
    cout << message << "\n";
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
}

int vitalsOk(float temperature, float pulseRate, float spo2, int age) {
    if (!isTemperatureOk(temperature)) {
        printAlert("Temperature is critical!");
        return 0;
    }
    if (!isPulseRateOk(pulseRate, age)) {
        printAlert("Pulse Rate is out of range!");
        return 0;
    }
    if (!isSpO2Ok(spo2)) {
        printAlert("Oxygen Saturation out of range!");
        return 0;
    }
    return 1;
}
