#include "helper.h"
void setup()
{
  Serial.begin(115200);

  initializeWifi();

  initializeReader();

}

void loop()
{
  handleUid();
}
