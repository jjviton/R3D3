/*
  R3D3  Library.
  Created by J3Viton [Kiddybot], November, 2017.
*/
#ifndef R3D3_h
#define R3D3_h

#include "Arduino.h"

#define LED_RED   11
#define LED_GREEN 10

#define MotorB_IB 6
#define MotorB_IA 7
#define MotorA_IB 4
#define MotorA_IA 5

class R3D3
{
  public:
    R3D3(int pin);
    void test_bridgeH(int motor, int speed, int rotation);
    void moveForward();
    void moveback();
    void turnRight(int angle);
    void turnLeft(int angle);
    void stop();
    
    void dot();
    void dash();
  private:
    int _pin;
  //  int MotorA_IB=6;
  //  int MotorA_IA=7;
};

#endif
