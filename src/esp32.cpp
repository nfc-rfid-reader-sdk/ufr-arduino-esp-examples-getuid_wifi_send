#ifdef ESP32
#include "esp32.h"
Preferences preferences;


void initializeWifi()
{

  preferences.begin("data", false);

  bool set = preferences.getBool("set", false);


  if (!set)
  {

    Serial.println("SET");
  }
  else
  {
    setAP();
    Serial.println("NO");
  }
  preferences.end();

  WiFi.mode(WIFI_AP_STA);

  WiFi.begin("Razvoj_AP_6", "dlogic-sigurno");
}

void setDefault()
{
  preferences.putString("ssid", AP);
  preferences.putString("pass", PASS);
  preferences.putBool("set", true);

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
  String ssid = preferences.getString("ssid");
  String pass = preferences.getString("pass");

  if (!pass.length())
  {
    WiFi.softAP(ssid.c_str());
  }
  else
  {
    WiFi.softAP(ssid.c_str(), pass.c_str());
  }
}

#endif

