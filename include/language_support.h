#pragma once

// Language support for Extension 2
// Single responsibility: Manage language settings

// Global language variable: 0 = English, 1 = German
extern int currentLanguage;

// Language setting functions
void setLanguageToEnglish();
void setLanguageToGerman();

// Message translation functions
const char* getLocalizedTemperatureMessage(const char* condition);
const char* getLocalizedPulseMessage(const char* condition);
const char* getLocalizedSpO2Message(const char* condition);
