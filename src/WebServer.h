#ifndef WEB_SERVER_H
#define WEB_SERVER_H

#include <ESP8266WebServer.h>
#include <ArduinoJson.h>
#include "PageIndex.h"
#include "SafeString.h"

class WebServer
{
public:
    void init();
    void loop(float hydro);

private:
    static void handle_Root();
    static void handle_NotFound();
    static void formatValue(SafeString &result, double value);
    static void handle_Snapshot();

};
#endif