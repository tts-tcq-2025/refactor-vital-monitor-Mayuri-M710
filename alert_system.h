#pragma once

// Alert system for vital signs monitoring

// Prints alert message with visual indicators
void printAlert(const char* message);

// Handles vital alert logic - prints alert if not OK, returns status
int handleVitalAlert(bool isOk, const char* message);
