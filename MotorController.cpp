#include "MotorController.h"
#include <cmath>

namespace ls {

    MotorController::MotorController():
        powerLeft(0),
        powerRight(0),
        isStopped(true)
    {
        leftMotor = new Motor(4, 0);
        rightMotor = new Motor(5, 2);
    }

    MotorController::~MotorController()
    {
        if (leftMotor) {
            delete leftMotor;
        }
        if (rightMotor) {
            delete rightMotor;
        }
    }

    void MotorController::setLeft(float value)
    {
        powerLeft = value;
        isStopped = false;
    }

    void MotorController::setRight(float value)
    {
        powerRight = value;
        isStopped = false;
    }

    void MotorController::update()
    {
        if (!isStopped) {
            leftMotor->run(roundPower(powerLeft));
            rightMotor->run(roundPower(powerRight));
        }
    }
    
    void MotorController::stop()
    {
        if (!isStopped) {
            isStopped = true;
            leftMotor->stop();
            rightMotor->stop();
        }
    }

    float MotorController::roundPower(float power)
    {
        float bias = 10;
        float minPower = 250;
        float absPower = fabs(power);
        if (absPower > bias) {
            if (absPower < minPower) {
                return power > 0 ? minPower : -minPower; 
            }
        }
        return power;
    }
}