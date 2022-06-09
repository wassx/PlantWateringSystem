#include <Arduino.h>
#include "WifiMgr.h"
#include "WebServer.h"

WifiMgr wifimgr;
WebServer websrv;

void setup()
{
  wifimgr.init();
  websrv.init();
  Serial.println("Init done.");
}

void loop()
{
  wifimgr.loop();

  int sensorValue = analogRead(A0);
  float normalization = sensorValue / 1023.0;
  float percentage = 100 -( normalization * 100);
  websrv.loop(percentage);
  Serial.println(percentage);
  delay(100); // delay in between reads for stability
}