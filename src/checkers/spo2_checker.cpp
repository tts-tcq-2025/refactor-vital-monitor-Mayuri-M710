#include "spo2_checker.h"

bool isSpO2Ok(float spo2) {
    return spo2 >= 90;
}

VitalStatus getSpO2Status(float spo2) {
    return checkVitalStatus(spo2, SPO2_RANGE);
}
