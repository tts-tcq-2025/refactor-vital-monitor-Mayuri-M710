#include "temperature_checker.h"

bool isTemperatureOk(float temperature) {
    return temperature >= 95 && temperature <= 102;
}

VitalStatus getTemperatureStatus(float temperature) {
    return checkVitalStatus(temperature, TEMPERATURE_RANGE);
}
