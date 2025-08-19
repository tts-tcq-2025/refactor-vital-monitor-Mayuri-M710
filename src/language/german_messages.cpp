#include "german_messages.h"
#include <cstring>

const char* getGermanTemperatureMessage(const char* condition) {
    if (!condition) return nullptr;

    if (strcmp(condition, "approaching_hypothermia") == 0) {
        return "Warnung: Hypothermie nähert sich";
    }
    if (strcmp(condition, "approaching_hyperthermia") == 0) {
        return "Warnung: Hyperthermie nähert sich";
    }
    if (strcmp(condition, "critical_hypothermia") == 0) {
        return "Kritisch: Hypothermie";
    }
    if (strcmp(condition, "critical_hyperthermia") == 0) {
        return "Kritisch: Hyperthermie";
    }
    return nullptr;
}

const char* getGermanPulseMessage(const char* condition) {
    if (!condition) return nullptr;

    if (strcmp(condition, "pulse_low") == 0) {
        return "Puls kritisch: Zu niedrig";
    }
    if (strcmp(condition, "pulse_high") == 0) {
        return "Puls kritisch: Zu hoch";
    }
    if (strcmp(condition, "pulse_approaching_low") == 0) {
        return "Warnung: Puls nähert sich niedrigem Grenzwert";
    }
    if (strcmp(condition, "pulse_approaching_high") == 0) {
        return "Warnung: Puls nähert sich hohem Grenzwert";
    }
    return nullptr;
}

const char* getGermanSpO2Message(const char* condition) {
    if (!condition) return nullptr;

    if (strcmp(condition, "spo2_critical") == 0) {
        return "SpO2 kritisch: Zu niedrig";
    }
    if (strcmp(condition, "spo2_warning") == 0) {
        return "Warnung: SpO2 nähert sich niedrigem Grenzwert";
    }
    return nullptr;
}
