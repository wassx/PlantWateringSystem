#include <Arduino.h>
#include "WifiMgr.h"
#include "WebServer.h"

WifiMgr wifimgr;
WebServer websrv;

void setup() {
  wifimgr.init("", "");
  websrv.init();
  Serial.println("Init done.");
}

void loop() {
  wifimgr.loop();
  websrv.loop();

int sensorValue = analogRead(A0);
Serial.println(sensorValue);
delay(100); // delay in between reads for stability


}