#include "./pulse_checker.h"
#include <algorithm>

static const PulseRateRange pulseRateRanges[] = {
    {0, 0, 100, 160},    // newborn
    {1, 5, 80, 140},     // infant/toddler
    {6, 10, 70, 110},    // child
    {11, 14, 60, 105},   // adolescent
    {15, 200, 60, 100}   // adult (assuming max age 200)
};

bool ageInRange(int age, const PulseRateRange& range) {
    return age >= range.minAge && age <= range.maxAge;
}

const PulseRateRange* findPulseRangeForAge(int age) {
    const auto* end = pulseRateRanges +
                      sizeof(pulseRateRanges) / sizeof(pulseRateRanges[0]);
    const auto* result = std::find_if(pulseRateRanges, end,
                                      [age](const PulseRateRange& range) {
                                          return ageInRange(age, range);
                                      });
    return result != end ? result : nullptr;
}

bool isPulseRateOk(float pulseRate, int age) {
    const PulseRateRange* range = findPulseRangeForAge(age);
    return range && pulseRate >= range->minPulse &&
           pulseRate <= range->maxPulse;
}
