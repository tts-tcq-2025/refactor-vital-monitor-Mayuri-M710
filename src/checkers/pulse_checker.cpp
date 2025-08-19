#include "pulse_checker.h"
#include "vital_ranges.h"

bool isPulseRateOk(float pulseRate, int age) {
    const PulseRateRange* range = findPulseRangeForAge(age);
    if (!range) return false;
    return pulseRate >= range->minPulse && pulseRate <= range->maxPulse;
}

const PulseRateRange* findPulseRangeForAge(int age) {
    const PulseRateRange* ranges = getPulseRanges();
    int rangeCount = getPulseRangeCount();
    
    for (int i = 0; i < rangeCount; i++) {
        if (age >= ranges[i].minAge && age <= ranges[i].maxAge) {
            return &ranges[i];
        }
    }
    return nullptr;
}

VitalStatus getPulseStatus(float pulseRate, int age) {
    const PulseRateRange* range = findPulseRangeForAge(age);
    if (!range) return VitalStatus::CRITICAL_LOW;

    float tolerance = range->maxPulse * 0.015f;  // 1.5% tolerance
    VitalRange pulseRange = {
        0.0f,
        range->minPulse,
        range->minPulse + tolerance,
        range->maxPulse - tolerance,
        range->maxPulse,
        1000.0f
    };
    
    return checkVitalStatus(pulseRate, pulseRange);
}
