/*
  R3D3  Library.
  Created by J3Viton [Kiddybot], November, 2017.
*/
#ifndef R3D3_h
#define R3D3_h

#include "Arduino.h"

#define LED_RED   11
#define LED_GREEN 10

#define Motor_A   1
#define MotorB_IA 6    // analog OUT
#define MotorB_IB 7
#define Motor_B   2
#define MotorA_IB 4
#define MotorA_IA 5   // analog OUT

class R3D3
{
  public:
    R3D3(int pin);
    void test_bridgeH(int motor, int speed, int rotation);
    void moveForward(int speed);
    void moveBack(int speed);
    void turnRight(int angle, int speed);
    void turnLeft(int angle, int speed);
    void stop();

  private:
    int _pin;

};

#endif
