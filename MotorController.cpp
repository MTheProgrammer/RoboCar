#include "MotorController.h"
#include <cmath>

namespace ls {

    float MotorController::roundPower(float power)
    {
        return fabs(power) > 150 ? power : 0;
    }

    void MotorController::run(float left, float right)
    {
        leftMotor->run(roundPower(left));
        rightMotor->run(roundPower(right));
    }

    void MotorController::backward()
    {
        leftMotor->backward();
        rightMotor->backward();
    }

    void MotorController::forward()
    {
        leftMotor->forward();
        rightMotor->forward();
    }

    void MotorController::left()
    {
        leftMotor->backward();
        rightMotor->forward();
    }

    void MotorController::right()
    {
        leftMotor->forward();
        rightMotor->backward();
    }
    
    void MotorController::stop()
    {
        leftMotor->stop();
        rightMotor->stop();  
    }
}