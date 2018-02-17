#ifndef _MOTOR_CONTROLLER_H_
#define _MOTOR_CONTROLLER_H_

#include "Motor.h"

namespace ls {

    class MotorController
    {
        Motor* leftMotor;
        Motor* rightMotor;
        float powerLeft;
        float powerRight;
        bool isStopped;
        int updateStep = 500;
    public:
        MotorController();
        ~MotorController();

        void setLeft(float value);
        void setRight(float value);
        void update();
        void stop();
    private:
        float roundPower(float power);
    };
}
#endif