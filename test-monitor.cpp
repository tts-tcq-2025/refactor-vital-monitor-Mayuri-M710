#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70, 30)); // adult, pulse high, spo2 low
  ASSERT_TRUE(vitalsOk(98.1, 70, 98, 30)); // adult, all normal
  ASSERT_TRUE(vitalsOk(98.1, 120, 98, 3)); // child, pulse normal for age
  ASSERT_FALSE(vitalsOk(98.1, 120, 98, 30)); // adult, pulse high
  ASSERT_TRUE(vitalsOk(98.1, 150, 98, 0)); // newborn, pulse normal
  ASSERT_FALSE(vitalsOk(98.1, 150, 98, 10)); // child, pulse high
}

TEST(Monitor, TemperatureCritical) {
  ASSERT_FALSE(vitalsOk(103, 80, 98, 30)); // high temp
  ASSERT_FALSE(vitalsOk(94, 80, 98, 30)); // low temp
  ASSERT_TRUE(vitalsOk(95, 80, 98, 30)); // lower bound
  ASSERT_TRUE(vitalsOk(102, 80, 98, 30)); // upper bound
}

TEST(Monitor, SpO2Critical) {
  ASSERT_FALSE(vitalsOk(98.1, 80, 89, 30)); // low SpO2
  ASSERT_TRUE(vitalsOk(98.1, 80, 90, 30)); // lower bound
  ASSERT_TRUE(vitalsOk(98.1, 80, 100, 30)); // upper bound
}

TEST(Monitor, AgeBasedPulseRate) {
  // Newborn
  ASSERT_TRUE(vitalsOk(98.1, 100, 98, 0)); // lower bound
  ASSERT_TRUE(vitalsOk(98.1, 160, 98, 0)); // upper bound
  ASSERT_FALSE(vitalsOk(98.1, 99, 98, 0)); // below lower
  ASSERT_FALSE(vitalsOk(98.1, 161, 98, 0)); // above upper
  // Infant/toddler
  ASSERT_TRUE(vitalsOk(98.1, 80, 98, 2)); // lower bound
  ASSERT_TRUE(vitalsOk(98.1, 140, 98, 2)); // upper bound
  ASSERT_FALSE(vitalsOk(98.1, 79, 98, 2)); // below lower
  ASSERT_FALSE(vitalsOk(98.1, 141, 98, 2)); // above upper
  // Child
  ASSERT_TRUE(vitalsOk(98.1, 70, 98, 8)); // lower bound
  ASSERT_TRUE(vitalsOk(98.1, 110, 98, 8)); // upper bound
  ASSERT_FALSE(vitalsOk(98.1, 69, 98, 8)); // below lower
  ASSERT_FALSE(vitalsOk(98.1, 111, 98, 8)); // above upper
  // Adolescent
  ASSERT_TRUE(vitalsOk(98.1, 60, 98, 13)); // lower bound
  ASSERT_TRUE(vitalsOk(98.1, 105, 98, 13)); // upper bound
  ASSERT_FALSE(vitalsOk(98.1, 59, 98, 13)); // below lower
  ASSERT_FALSE(vitalsOk(98.1, 106, 98, 13)); // above upper
  // Adult
  ASSERT_TRUE(vitalsOk(98.1, 60, 98, 30)); // lower bound
  ASSERT_TRUE(vitalsOk(98.1, 100, 98, 30)); // upper bound
  ASSERT_FALSE(vitalsOk(98.1, 59, 98, 30)); // below lower
  ASSERT_FALSE(vitalsOk(98.1, 101, 98, 30)); // above upper
}
