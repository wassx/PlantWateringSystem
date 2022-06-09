#include "WifiMgr.h"

ESP8266WiFiMulti wifiMulti;

void WifiMgr::init(String ssid, String pwd)
{
    wifiMulti.addAP(ssid.c_str(), pwd.c_str());
    // WiFi.config(staticIP, gateway, subnet, dns);
    // WiFi.begin(ssid, pwd);
    Serial.print("Connecting network .");

    int i = 0;
    while (wifiMulti.run() != WL_CONNECTED)
    { // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
        delay(1000);
        Serial.print(++i);
        Serial.print('.');
    }
    Serial.println('\n');
    Serial.print("Connected to ");
    Serial.println(WiFi.SSID()); // Tell us what network we're connected to
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP()); // Send the IP address of the ESP8266 to the computer

    if (!MDNS.begin("webserv"))
    { // Start the mDNS responder for esp8266.local
        Serial.println("Error setting up MDNS responder!");
    }
    Serial.println("mDNS responder started");
}

void WifiMgr::loop() {
    MDNS.update();
}
