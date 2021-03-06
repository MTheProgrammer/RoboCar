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
    if (server.arg("stop")) {
        motorController->stop();
    } 
    if (server.arg("left")) {
        float left = server.arg("left").toFloat();
        motorController->setLeft(left);
    }
    if (server.arg("right")) {
        float right = server.arg("right").toFloat();
        motorController->setRight(right);
    }
    motorController->update();    
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
    server.handleClient();
}

