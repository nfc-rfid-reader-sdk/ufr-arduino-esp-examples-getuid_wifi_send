#ifndef ESP8266_H
#define ESP8266_H
#include "constants.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <EEPROM.h>

void initializeWifi();

void setDefault();

void setAP();

#endif

