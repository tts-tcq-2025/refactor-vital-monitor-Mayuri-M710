#pragma once
#include "vital_types.h"
#include "vital_ranges.h"
#include "alert_system.h"
#include "language_support.h"

// Enhanced vital monitoring with early warning system and language support
// Single responsibility: Coordinate vital checks with warnings and localization

struct EnhancedVitalChecks {
    VitalStatus temperature;
    VitalStatus pulseRate;
    VitalStatus spo2;
    OverallStatus overall;
};

// Enhanced monitoring functions
EnhancedVitalChecks checkAllVitalsEnhanced(float temperature, float pulseRate, 
                                          float spo2, int age);
int vitalsOkEnhanced(float temperature, float pulseRate, float spo2, int age);
int vitalsOkWithOutput(float temperature, float pulseRate, float spo2, int age,
                      OutputFunction output);

// Helper functions
OverallStatus determineOverallStatus(VitalStatus temp, VitalStatus pulse, VitalStatus spo2);
bool isCritical(VitalStatus status);
bool isWarning(VitalStatus status);
