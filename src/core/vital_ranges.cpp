#include "vital_ranges.h"

VitalStatus checkVitalStatus(float value, const VitalRange& range) {
    if (value < range.criticalLow) return VitalStatus::CRITICAL_LOW;
    if (value < range.warningLow) return VitalStatus::WARNING_LOW;
    if (value < range.normalLow) return VitalStatus::WARNING_LOW;
    if (value <= range.normalHigh) return VitalStatus::NORMAL;
    if (value < range.warningHigh) return VitalStatus::WARNING_HIGH;
    return VitalStatus::CRITICAL_HIGH;
}

// Pulse rate ranges by age groups
static const PulseRateRange PULSE_RANGES[] = {
    {0, 1, 100, 190},      // Infants
    {2, 5, 95, 140},       // Toddlers
    {6, 12, 80, 120},      // Children
    {13, 18, 70, 100},     // Adolescents
    {19, 60, 60, 100},     // Adults
    {61, 120, 50, 100}     // Elderly
};

const PulseRateRange* getPulseRanges() {
    return PULSE_RANGES;
}

int getPulseRangeCount() {
    return sizeof(PULSE_RANGES) / sizeof(PULSE_RANGES[0]);
}
