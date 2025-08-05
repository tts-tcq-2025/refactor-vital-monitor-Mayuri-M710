#include "./monitor.h"

VitalChecks checkAllVitals(float temperature, float pulseRate, float spo2,
                           int age) {
    VitalChecks checks;
    checks.temperature = isTemperatureOk(temperature);
    checks.pulseRate = isPulseRateOk(pulseRate, age);
    checks.spo2 = isSpO2Ok(spo2);
    return checks;
}

int vitalsOk(float temperature, float pulseRate, float spo2, int age) {
    VitalChecks checks = checkAllVitals(temperature, pulseRate, spo2, age);

    int result = handleVitalAlert(checks.temperature,
                                  "Temperature is critical!");
    if (result == 0) return 0;

    result = handleVitalAlert(checks.pulseRate, "Pulse Rate is out of range!");
    if (result == 0) return 0;

    return handleVitalAlert(checks.spo2, "Oxygen Saturation out of range!");
}
