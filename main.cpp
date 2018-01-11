// include libraries
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "FS.h"
#include "MotorController.h"

// configure server
ESP8266WebServer server(80);
const char *form = "Please connect through <a href=\"index.html\">app</a>";
ls::MotorController* motorController;

void handleRequest()
{
    // only move if we submitted the form
    if (server.arg("stop")) {
        motorController->stop();
    }
    float left = 0;
    float right = 0;
    if (server.arg("left")) {
        left = server.arg("left").toFloat();
    }
    if (server.arg("right")) {
        right = server.arg("right").toFloat();
    }
    motorController->run(left, right);
    delay(100);
    server.send(200, "text/html", form);
}
void setup()
{
    Serial.begin(115200);
    Serial.println();
    SPIFFS.begin();
    pinMode(LED_BUILTIN, OUTPUT);
    WiFi.mode(WIFI_AP);
    WiFi.softAP("Car-mcu", "zaq12345");
    IPAddress myIP = WiFi.softAPIP();
    Serial.println("AP IP address: ");
    Serial.println(myIP.toString()); 
    motorController = new ls::MotorController();
    // set up the callback for http server
    server.on("/", []() { handleRequest(); });
    Dir dir = SPIFFS.openDir("/");
    Serial.println("Serving files:");
    while (dir.next()) {
        Serial.println(dir.fileName());
        server.serveStatic(dir.fileName().c_str(), SPIFFS, dir.fileName().c_str());
    }
    // start the webserver
    server.begin();
}
void loop()
{
    // check for client connections
    server.handleClient();
}

