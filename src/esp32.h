#ifndef ESP32_H
#define ESP32_H
#include "constants.h"
#include <WiFi.h>
#include <Preferences.h>
#include <HTTPClient.h>

void initializeWifi();

void setDefault();

void setAP();

#endif
