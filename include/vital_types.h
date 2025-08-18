#pragma once

// Common data structures for vital signs monitoring

struct PulseRateRange {
    int minAge;
    int maxAge;
    float minPulse;
    float maxPulse;
};

struct VitalChecks {
    bool temperature;
    bool pulseRate;
    bool spo2;
};

enum class OverallStatus {
    ALL_NORMAL,
    HAS_WARNINGS,
    HAS_CRITICAL
};
