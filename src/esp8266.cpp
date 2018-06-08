#ifdef ESP8266

#include "esp8266.h"


void initializeWifi()
{
  uint8_t set = 0;

  EEPROM.begin(512);
  EEPROM.get(0, set);



  if (!set)
  {
    setDefault();
    Serial.println("SET");
  }
  else
  {
    setAP();
    Serial.println("NO");
  }
  EEPROM.end();

  WiFi.mode(WIFI_AP_STA);

  WiFi.begin("Razvoj_AP_6", "dlogic-sigurno");
}

void setDefault()
{
  EEPROM.begin(512);
  EEPROM.put(0, 1);
  EEPROM.put(1, AP);
  EEPROM.put(1 + sizeof(AP), AP);
  char ok[2 + 1] = "OK";
  EEPROM.put(1 + sizeof(PASS) + sizeof(PASS), ok);

  EEPROM.commit();


  if (!strlen(PASS))
  {
    WiFi.softAP(AP);
  }
  else
  {
    WiFi.softAP(AP, PASS);
  }
}

void setAP()
{
  char ssid[32] = "";
  char pass[64] = "";

  EEPROM.begin(512);
  EEPROM.get(1, ssid);
  EEPROM.get(1 + sizeof(ssid), pass);
  char ok[2 + 1];
  EEPROM.get(1 + sizeof(ssid) + sizeof(pass), ok);

  if (String(ok) != String("OK")) {
    ssid[0] = 0;
    pass[0] = 0;

  }
  if (!strlen(pass))
  {
    WiFi.softAP(ssid);
  }
  else
  {
    WiFi.softAP(ssid, pass);
  }
#endif
