#include "language_support.h"
#include "english_messages.h"
#include "german_messages.h"

// Global language variable definition
int currentLanguage = 0;  // Default to English

void setLanguageToEnglish() {
    currentLanguage = 0;
}

void setLanguageToGerman() {
    currentLanguage = 1;
}

const char* getLocalizedTemperatureMessage(const char* condition) {
    return (currentLanguage == 1) ? getGermanTemperatureMessage(condition)
                                  : getEnglishTemperatureMessage(condition);
}

const char* getLocalizedPulseMessage(const char* condition) {
    return (currentLanguage == 1) ? getGermanPulseMessage(condition)
                                  : getEnglishPulseMessage(condition);
}

const char* getLocalizedSpO2Message(const char* condition) {
    return (currentLanguage == 1) ? getGermanSpO2Message(condition)
                                  : getEnglishSpO2Message(condition);
}
