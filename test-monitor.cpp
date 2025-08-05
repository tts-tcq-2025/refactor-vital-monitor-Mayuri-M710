#include <gtest/gtest.h>
#include "./monitor.h"

// Test pure logic functions without I/O
TEST(Monitor, TemperatureChecks) {
  ASSERT_TRUE(isTemperatureOk(98.6f));
  ASSERT_TRUE(isTemperatureOk(95.0f));  // lower bound
  ASSERT_TRUE(isTemperatureOk(102.0f));  // upper bound
  ASSERT_FALSE(isTemperatureOk(94.9f));  // below lower
  ASSERT_FALSE(isTemperatureOk(102.1f));  // above upper
}

TEST(Monitor, SpO2Checks) {
  ASSERT_TRUE(isSpO2Ok(95.0f));
  ASSERT_TRUE(isSpO2Ok(90.0f));  // lower bound
  ASSERT_TRUE(isSpO2Ok(100.0f));  // upper bound
  ASSERT_FALSE(isSpO2Ok(89.9f));  // below lower

  // Additional edge cases
  ASSERT_TRUE(isSpO2Ok(90.1f));  // just above threshold
  ASSERT_FALSE(isSpO2Ok(89.0f));  // clearly below threshold
  ASSERT_TRUE(isSpO2Ok(99.9f));  // high normal value
}

TEST(Monitor, PulseRateChecks) {
  // Newborn (age 0): range 100-160
  ASSERT_TRUE(isPulseRateOk(130.0f, 0));
  ASSERT_TRUE(isPulseRateOk(100.0f, 0));  // lower bound
  ASSERT_TRUE(isPulseRateOk(160.0f, 0));  // upper bound
  ASSERT_FALSE(isPulseRateOk(99.0f, 0));  // below
  ASSERT_FALSE(isPulseRateOk(161.0f, 0));  // above

  // Infant/Toddler (age 1-5): range 80-140
  ASSERT_TRUE(isPulseRateOk(110.0f, 3));
  ASSERT_TRUE(isPulseRateOk(80.0f, 5));   // lower bound
  ASSERT_TRUE(isPulseRateOk(140.0f, 1));  // upper bound
  ASSERT_FALSE(isPulseRateOk(79.0f, 2));  // below
  ASSERT_FALSE(isPulseRateOk(141.0f, 4));  // above

  // Adult (age 15+): range 60-100
  ASSERT_TRUE(isPulseRateOk(75.0f, 30));
  ASSERT_TRUE(isPulseRateOk(60.0f, 30));  // lower bound
  ASSERT_TRUE(isPulseRateOk(100.0f, 30));  // upper bound
  ASSERT_FALSE(isPulseRateOk(59.0f, 30));  // below
  ASSERT_FALSE(isPulseRateOk(101.0f, 30));  // above
}

TEST(Monitor, VitalChecksStruct) {
  // All vitals normal for adult
  VitalChecks checks = checkAllVitals(98.6f, 75.0f, 95.0f, 30);
  ASSERT_TRUE(checks.temperature);
  ASSERT_TRUE(checks.pulseRate);
  ASSERT_TRUE(checks.spo2);

  // All vitals out of range for adult
  checks = checkAllVitals(105.0f, 45.0f, 85.0f, 30);
  ASSERT_FALSE(checks.temperature);  // 105°F > 102°F
  ASSERT_FALSE(checks.pulseRate);    // 45 < 60 for adult
  ASSERT_FALSE(checks.spo2);         // 85% < 90%

  // Mixed case: temperature OK, pulse high, SpO2 OK for newborn
  checks = checkAllVitals(98.0f, 170.0f, 95.0f, 0);
  ASSERT_TRUE(checks.temperature);   // 98°F is OK
  ASSERT_FALSE(checks.pulseRate);    // 170 > 160 for newborn
  ASSERT_TRUE(checks.spo2);          // 95% is OK
}

// Test the main function for logic
TEST(Monitor, VitalsOkLogic) {
  // Test cases that should return 1 (OK) - these won't print alerts
  ASSERT_EQ(1, vitalsOk(98.6f, 75.0f, 95.0f, 30));  // all normal adult
  ASSERT_EQ(1, vitalsOk(98.1f, 130.0f, 98.0f, 0));  // normal newborn
  // Test cases that should return 0 (NOT OK) - these will print alerts
  // but we minimize them
  ASSERT_EQ(0, vitalsOk(105.0f, 75.0f, 95.0f, 30));  // temperature critical
  ASSERT_EQ(0, vitalsOk(98.6f, 45.0f, 95.0f, 30));  // only pulse critical
  ASSERT_EQ(0, vitalsOk(98.6f, 75.0f, 85.0f, 30));  // only SpO2 critical
}

// Test edge cases and boundary conditions
TEST(Monitor, EdgeCases) {
  // Test boundary values for temperature
  ASSERT_TRUE(isTemperatureOk(95.0f));   // exact lower bound
  ASSERT_TRUE(isTemperatureOk(102.0f));  // exact upper bound
  ASSERT_FALSE(isTemperatureOk(94.99f));  // just below lower
  ASSERT_FALSE(isTemperatureOk(102.01f));  // just above upper

  // Test different age groups for pulse rate
  ASSERT_TRUE(isPulseRateOk(120.0f, 0));  // newborn
  ASSERT_TRUE(isPulseRateOk(100.0f, 3));  // toddler
  ASSERT_TRUE(isPulseRateOk(85.0f, 8));   // child
  ASSERT_TRUE(isPulseRateOk(75.0f, 13));  // adolescent
  ASSERT_TRUE(isPulseRateOk(70.0f, 25));  // adult

  // Test SpO2 boundary
  ASSERT_TRUE(isSpO2Ok(90.0f));   // exact threshold
  ASSERT_FALSE(isSpO2Ok(89.99f));  // just below threshold
}
