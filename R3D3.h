/*
  R3D3  Library.
  Created by J3Viton [Kiddybot], November, 2017.
*/
#ifndef R3D3_h
#define R3D3_h

#include "Arduino.h"
#include "Servo.h"



#define Motor_A   1
#define MotorB_IA 6    // analog OUT
#define MotorB_IB 7
#define Motor_B   2
#define MotorA_IB 4
#define MotorA_IA 5   // analog OUT

#define HeadCenter 90
#define HeadRight   150
#define HeadLeft  30

#define pulsador_A 3  // pulsador
#define zumb  9


#define ON 1
#define OFF 0


class R3D3
{
  public:
    R3D3(int pin);          // Constructor
    void R3D3::Init(void);  // Inicializo todo

    void test_bridgeH(int motor, int speed, int rotation);
    void moveForward(int speed);
    void moveBack(int speed);
    void turnRight(int angle, int speed);
    void turnLeft(int angle, int speed);
    void stop();

    void testServo();
    void headPosition(int position);

    byte getPulsador(byte reference);  //Devuelve TRUE si pulsado
    void beep(byte duration, byte times);


  private:
    int _pin;
  //headServo.attach(12);


};

#endif
