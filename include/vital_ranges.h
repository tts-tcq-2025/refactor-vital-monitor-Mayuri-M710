#pragma once

// Vital signs ranges and threshold definitions
// Single responsibility: Define vital sign thresholds

enum class VitalStatus {
    CRITICAL_LOW,
    WARNING_LOW,
    NORMAL,
    WARNING_HIGH,
    CRITICAL_HIGH
};

struct VitalRange {
    float criticalLow;
    float warningLow;
    float normalLow;
    float normalHigh;
    float warningHigh;
    float criticalHigh;
};

// Temperature thresholds (Fahrenheit)
const VitalRange TEMPERATURE_RANGE = {
    0.0f,      // critical low (hypothermia)
    95.0f,     // warning low
    96.53f,    // normal low (95 + 1.5% of 102)
    100.47f,   // normal high (102 - 1.5% of 102)
    102.0f,    // warning high
    200.0f     // critical high (hyperthermia)
};

// SpO2 thresholds (percentage)
const VitalRange SPO2_RANGE = {
    0.0f,      // critical low
    90.0f,     // warning low
    91.35f,    // normal low (90 + 1.5% of 90)
    100.0f,    // normal high
    100.0f,    // warning high (no upper warning for SpO2)
    100.0f     // critical high (no upper critical for SpO2)
};

// Function to check vital status against range
VitalStatus checkVitalStatus(float value, const VitalRange& range);
