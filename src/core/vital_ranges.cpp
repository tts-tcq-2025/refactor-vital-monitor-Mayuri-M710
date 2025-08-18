#include "vital_ranges.h"

VitalStatus checkVitalStatus(float value, const VitalRange& range) {
    if (value < range.criticalLow) return VitalStatus::CRITICAL_LOW;
    if (value < range.warningLow) return VitalStatus::WARNING_LOW;
    if (value < range.normalLow) return VitalStatus::WARNING_LOW;
    if (value <= range.normalHigh) return VitalStatus::NORMAL;
    if (value < range.warningHigh) return VitalStatus::WARNING_HIGH;
    return VitalStatus::CRITICAL_HIGH;
}
