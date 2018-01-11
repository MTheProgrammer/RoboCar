#ifndef _MOTOR_CONTROLLER_H_
#define _MOTOR_CONTROLLER_H_

#include "Motor.h"

namespace ls {

    class MotorController
    {
        Motor* leftMotor;
        Motor* rightMotor;
    public:
        MotorController()
        {
            leftMotor = new Motor(4, 0);
            rightMotor = new Motor(5, 2);
        }

        ~MotorController()
        {
            if (leftMotor) {
                delete leftMotor;
            }
            if (rightMotor) {
                delete rightMotor;
            }
        }
        void run(float left, float right);
        void backward();
        void forward();
        void left();
        void right();
        void stop();
    private:
        float roundPower(float power);
    };
}
#endif