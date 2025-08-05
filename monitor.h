#pragma once

// Main interface for vital signs monitoring system
// This header includes all necessary components

#include "./vital_types.h"
#include "./temperature_checker.h"
#include "./pulse_checker.h"
#include "./spo2_checker.h"
#include "./alert_system.h"

// Main vital signs monitoring coordination functions

// Checks all vitals and returns a struct with individual results
VitalChecks checkAllVitals(float temperature, float pulseRate, float spo2, int age);

// Main function: returns 0 if any vital is out of range, 1 otherwise
int vitalsOk(float temperature, float pulseRate, float spo2, int age);
