#include "helper.h"
#define RX 1 // ESP8266 RX PIN - Only PI 1 available.
#define TX 3 // ESP8266 TX PIN - Only PI 3 available.
#define UART 2 // ESP32 SERIAL PORT - DEFAULT 2 (RX - PIN 16; TX - PIN 17).
#define RESET 2 // RESET PIN - On ESP8266 module only PIN 2 available.

#ifdef ESP32
uFR reader(UART, RESET);
#endif
#ifdef ESP8266
uFR reader(RX, TX, RESET);
#endif

String Sn = "";
uint8_t control = 0;
bool s = true;
String tmp = "";

void initializeReader()
{
  reader.begin();
  delay(2000);
  reader.setGreenLightBlinking(false);
  reader.setUserInterfaceSignal(4, 1);
  getSerialNumber();
}

void getSerialNumber()
{
  uint8_t serialnum[4];
  reader.getReaderSerial(serialnum);
  for (uint8_t k = 0; k < 4; k++)
  {
    Sn += String(unsigned(serialnum[k]));
  }
}

void handleUid()
{
  uint8_t cardID[10];

  uint8_t length = 0;
  uint8_t code = reader.getCardID(cardID, &length);
  if (code == 0)
  {

    String buff = "";
    for (int i = 0; i < length; i++)
    {
      if (unsigned(cardID[i]) < 16)
      {
        buff += "0";
      }
      buff += String(unsigned(cardID[i]), HEX) + ":";
    }
    buff = buff.substring(0, buff.length() - 1);
    buff.toUpperCase();
    if (!buff.equals(tmp))
    {
      HTTPClient http;

      http.begin(HOST);
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");

      int httpCode = http.POST("UID=" + buff + "&SN=" + Sn + "&CTRLINFO=" + String(control++));
      if (httpCode == 200)
      {
        String payload = http.getString();
        uint8_t light = String(payload.charAt(0)).toInt();
        uint8_t beep = String(payload.charAt(2)).toInt();
        reader.setUserInterfaceSignal(light, beep);

        delay(10);
        tmp = buff;
        http.end();
      }
      else
      {
        reader.setUserInterfaceSignal(4, 4);
        delay(10);
        tmp = buff;
        http.end();
      }
    }
  }
  else
  {
    tmp = "";
  }

  delay(50);

}
