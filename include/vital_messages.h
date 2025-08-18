#pragma once
#include "vital_ranges.h"
#include "language_support.h"

// Message generation for vital status
// Single responsibility: Convert status to messages with language support

const char* getTemperatureMessage(VitalStatus status);
const char* getPulseMessage(VitalStatus status);
const char* getSpO2Message(VitalStatus status);
