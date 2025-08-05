#include "./temperature_checker.h"

bool isTemperatureOk(float temperature) {
    return temperature >= 95 && temperature <= 102;
}
