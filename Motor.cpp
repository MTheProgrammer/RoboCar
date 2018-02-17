#include "Motor.h"

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

namespace ls {

    void Motor::run(int speed)
    {
        uint8_t direction = HIGH;
        if (speed < 0) {
            speed = -speed;
            direction = LOW;
        }
        analogWrite(analogPin, speed);
        digitalWrite(digitalPin, direction);
    }

    void Motor::stop()
    {
        analogWrite(analogPin, 0);
    }

    void Motor::reset()
    {
        speed = 1023;
        pinMode(analogPin, OUTPUT);
        pinMode(digitalPin, OUTPUT);
    }
}