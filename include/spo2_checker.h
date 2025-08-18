#pragma once
#include "vital_ranges.h"

// SpO2 (Oxygen Saturation) validation functionality

// Checks if SpO2 is within normal range (>= 90%)
bool isSpO2Ok(float spo2);
VitalStatus getSpO2Status(float spo2);
