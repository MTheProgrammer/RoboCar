#ifndef _MOTOR_H_
#define _MOTOR_H_

namespace ls {

    class Motor
    {
        int analogPin;
        int digitalPin;
        int speed;
    public:
        Motor(int analogPin, int digitalPin) :
            analogPin(analogPin),
            digitalPin(digitalPin)
        {
            reset();
        };
        void setSpeed(int speed) { this->speed = speed; }  
        void run(int speed);
        void forward();
        void backward();
        void stop();
        void reset();
    };
}
#endif