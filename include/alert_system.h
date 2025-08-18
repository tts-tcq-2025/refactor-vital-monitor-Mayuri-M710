#pragma once
#include "vital_ranges.h"

// Alert system for vital signs monitoring

// Function pointer type for output dependency injection
typedef void (*OutputFunction)(const char*);

// Prints alert message with visual indicators
void printAlert(const char* message);
void printWarning(const char* message);

// Handles vital alert logic with dependency injection
int handleVitalWithOutput(VitalStatus status, const char* criticalMsg, 
                         const char* warningMsg, OutputFunction output);

// Helper functions
int processVitalStatus(VitalStatus status, const char* criticalMsg, 
                      const char* warningMsg, OutputFunction output);
bool isCriticalStatus(VitalStatus status);
bool isWarningStatus(VitalStatus status);

// Original function for backward compatibility
int handleVitalAlert(bool isOk, const char* message);
