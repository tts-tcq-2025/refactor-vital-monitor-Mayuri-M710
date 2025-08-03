#pragma once

// Returns 0 if any vital is out of range, 1 otherwise
int vitalsOk(float temperature, float pulseRate, float spo2, int age);

// Pure function to check each vital
bool isTemperatureOk(float temperature);
bool isPulseRateOk(float pulseRate, int age);
bool isSpO2Ok(float spo2);

// Alert function for I/O
void printAlert(const char* message);
