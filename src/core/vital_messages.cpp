#include "vital_messages.h"

const char* getTemperatureMessage(VitalStatus status) {
    switch (status) {
        case VitalStatus::CRITICAL_LOW:
            return getLocalizedTemperatureMessage("critical_hypothermia");
        case VitalStatus::WARNING_LOW:
            return getLocalizedTemperatureMessage("approaching_hypothermia");
        case VitalStatus::NORMAL:
            return nullptr;
        case VitalStatus::WARNING_HIGH:
            return getLocalizedTemperatureMessage("approaching_hyperthermia");
        case VitalStatus::CRITICAL_HIGH:
            return getLocalizedTemperatureMessage("critical_hyperthermia");
        default:
            return (currentLanguage == 1) ?
                "Unbekannter Temperaturstatus" : "Temperature unknown status";
    }
}

const char* getPulseMessage(VitalStatus status) {
    switch (status) {
        case VitalStatus::CRITICAL_LOW:
            return getLocalizedPulseMessage("pulse_low");
        case VitalStatus::WARNING_LOW:
            return getLocalizedPulseMessage("pulse_approaching_low");
        case VitalStatus::NORMAL:
            return nullptr;
        case VitalStatus::WARNING_HIGH:
            return getLocalizedPulseMessage("pulse_approaching_high");
        case VitalStatus::CRITICAL_HIGH:
            return getLocalizedPulseMessage("pulse_high");
        default:
            return (currentLanguage == 1) ? "Unbekannter Pulsstatus" : "Pulse unknown status";
    }
}

const char* getSpO2Message(VitalStatus status) {
    switch (status) {
        case VitalStatus::CRITICAL_LOW:
            return getLocalizedSpO2Message("spo2_critical");
        case VitalStatus::WARNING_LOW:
            return getLocalizedSpO2Message("spo2_warning");
        case VitalStatus::NORMAL:
            return nullptr;
        case VitalStatus::WARNING_HIGH:
            return nullptr;  // No upper warning for SpO2
        case VitalStatus::CRITICAL_HIGH:
            return nullptr;  // No upper critical for SpO2
        default:
            return (currentLanguage == 1) ? "Unbekannter SpO2-Status" : "SpO2 unknown status";
    }
}
