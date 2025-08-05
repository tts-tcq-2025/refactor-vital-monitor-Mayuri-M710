#pragma once
#include "./vital_types.h"

// Pulse rate validation functionality (age-based)

// Checks if pulse rate is within normal range for the given age
bool isPulseRateOk(float pulseRate, int age);

// Helper functions
const PulseRateRange* findPulseRangeForAge(int age);
bool ageInRange(int age, const PulseRateRange& range);
