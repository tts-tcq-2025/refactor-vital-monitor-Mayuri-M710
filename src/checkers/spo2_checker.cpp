#include "spo2_checker.h"
#include "vital_ranges.h"

bool isSpO2Ok(float spo2) {
    return spo2 >= 90.0f && spo2 <= 100.0f;
}

VitalStatus getSpO2Status(float spo2) {
    return checkVitalStatus(spo2, SPO2_RANGE);
}
