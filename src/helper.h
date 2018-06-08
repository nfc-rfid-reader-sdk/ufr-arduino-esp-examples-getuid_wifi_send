#ifndef HELPER_H
#define HELPER_H
#include <Arduino.h>
#include "uFR.h"
#ifdef ESP32
#include "esp32.h"
#endif
#ifdef ESP8266
#include "esp8266.h"
#endif

void getSerialNumber();

void handleUid();

void initializeReader();

#endif
