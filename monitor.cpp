#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

// Pure functions
bool isTemperatureOk(float temperature) {
    return temperature >= 95 && temperature <= 102;
}

// Age-based pulse rate ranges (adults, children, infants)
bool isPulseRateOk(float pulseRate, int age) {
    if (age < 1) return pulseRate >= 100 && pulseRate <= 160; // newborn
    if (age < 6) return pulseRate >= 80 && pulseRate <= 140;  // infant/toddler
    if (age < 11) return pulseRate >= 70 && pulseRate <= 110; // child
    if (age < 15) return pulseRate >= 60 && pulseRate <= 105; // adolescent
    return pulseRate >= 60 && pulseRate <= 100; // adult
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
