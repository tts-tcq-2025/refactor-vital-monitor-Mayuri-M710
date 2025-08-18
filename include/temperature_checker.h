#pragma once
#include "vital_ranges.h"

// Temperature validation functionality

// Checks if temperature is within normal range (95°F - 102°F)
bool isTemperatureOk(float temperature);
VitalStatus getTemperatureStatus(float temperature);
