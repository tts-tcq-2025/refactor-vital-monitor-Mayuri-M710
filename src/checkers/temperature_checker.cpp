#include "temperature_checker.h"
#include "vital_ranges.h"

bool isTemperatureOk(float temperature) {
    return temperature >= 95.0f && temperature <= 102.0f;
}

VitalStatus getTemperatureStatus(float temperature) {
    return checkVitalStatus(temperature, TEMPERATURE_RANGE);
}
