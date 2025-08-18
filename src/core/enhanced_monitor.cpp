#include "enhanced_monitor.h"
#include "temperature_checker.h"
#include "pulse_checker.h"
#include "spo2_checker.h"
#include "vital_messages.h"

bool isCritical(VitalStatus status) {
    return status == VitalStatus::CRITICAL_LOW || status == VitalStatus::CRITICAL_HIGH;
}

bool isWarning(VitalStatus status) {
    return status == VitalStatus::WARNING_LOW || status == VitalStatus::WARNING_HIGH;
}

OverallStatus determineOverallStatus(VitalStatus temp, VitalStatus pulse, VitalStatus spo2) {
    if (isCritical(temp) || isCritical(pulse) || isCritical(spo2)) {
        return OverallStatus::HAS_CRITICAL;
    }
    if (isWarning(temp) || isWarning(pulse) || isWarning(spo2)) {
        return OverallStatus::HAS_WARNINGS;
    }
    return OverallStatus::ALL_NORMAL;
}

EnhancedVitalChecks checkAllVitalsEnhanced(float temperature, float pulseRate, 
                                          float spo2, int age) {
    EnhancedVitalChecks checks;
    checks.temperature = getTemperatureStatus(temperature);
    checks.pulseRate = getPulseStatus(pulseRate, age);
    checks.spo2 = getSpO2Status(spo2);
    checks.overall = determineOverallStatus(checks.temperature, checks.pulseRate, checks.spo2);
    return checks;
}

int vitalsOkWithOutput(float temperature, float pulseRate, float spo2, int age,
                      OutputFunction output) {
    EnhancedVitalChecks checks = checkAllVitalsEnhanced(temperature, pulseRate, spo2, age);
    
    int result = handleVitalWithOutput(checks.temperature,
                                      getTemperatureMessage(checks.temperature),
                                      getTemperatureMessage(checks.temperature), output);
    if (result == 0) return 0;
    
    result = handleVitalWithOutput(checks.pulseRate, getPulseMessage(checks.pulseRate),
                                  getPulseMessage(checks.pulseRate), output);
    if (result == 0) return 0;
    
    return handleVitalWithOutput(checks.spo2, getSpO2Message(checks.spo2),
                                getSpO2Message(checks.spo2), output);
}

int vitalsOkEnhanced(float temperature, float pulseRate, float spo2, int age) {
    return vitalsOkWithOutput(temperature, pulseRate, spo2, age, printWarning);
}
