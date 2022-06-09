#ifndef WIFI_MGR_H
#define WIFI_MGR_H

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266mDNS.h>

class WifiMgr
{
public:
    void init(String ssid, String pwd);
    void loop();

private:
};
#endif
