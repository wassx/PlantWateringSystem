#include "WebServer.h"

ESP8266WebServer server(80);

float hydration = 0.0;

void WebServer::handle_Root()
{
    server.send(200, "text/html", MAIN_page); // Send web page
}

void WebServer::handle_NotFound()
{
    server.send(404, "text/plain", "Page not found");
}

void WebServer::formatValue(SafeString &result, double value)
{
    result.clear();
    result.print(value, 3, 7, true);
}

// send snapshot of the current data
void WebServer::handle_Snapshot()
{
    cSF(sfResult, 45);
    cSF(sfData, 100); // data to send

    formatValue(sfResult, hydration);
    sfData.print(sfResult);
    sfData.print(',');
    formatValue(sfResult, 21);
    sfData.print(sfResult);
    sfData.print(',');
    formatValue(sfResult, 123);
    sfData.print(sfResult);
    sfData.print(',');
    formatValue(sfResult, 321);
    sfData.print(sfResult);
    sfData.print(',');
    formatValue(sfResult, 45);
    sfData.print(sfResult);
    sfData.print(',');
    // formatValue(sfResult, currentModel[SENORS][AIR_HUMIDITY]);
    // sfData.print(sfResult);
    sfData.print(',');
    formatValue(sfResult, 1);
    sfData.print(sfResult);
    // Serial.println(sfData);
    server.send(200, "text/plane", sfData.c_str());
}

void WebServer::init()
{
    server.on("/", handle_Root);                    //--> This is to display web page.
    server.on("/getSnapshotData", handle_Snapshot); //--> handle the call procedure getSnapshotData
    server.begin();                                 //--> Start server
    Serial.println("HTTP server started");
}

void WebServer::loop(float hydro)
{
    hydration = hydro;
    server.handleClient();
}