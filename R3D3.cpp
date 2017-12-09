/*
  R3D3
  Libreria para controlar el robot de Kiddybot R3D3
    Created by J3Viton [Kiddybot], November, 2017.


    Hardware:
        DC motor Driver:
        L911O h bridge  http://www.gie.com.my/UploadFiles/robotics/drivers/motor_waveform.jpg
*/

#include "Arduino.h"
#include "R3D3.h"

R3D3::R3D3(int pin)
{
  // Preparo los pines de salida
  pinMode(MotorA_IA, OUTPUT);
  pinMode(MotorA_IB, OUTPUT);

  pinMode(11, OUTPUT);
  _pin = pin;

    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
}

/*******************************************************************
test_bridgeH
Funcion para testeo y debugg del resto de la clase y sus metodos.
toDo:
  .- añadir el control PWM
  .- controlar motor + velocidad + sentido
  .- ajustar angulos de giro.


********************************************************************/
void R3D3::test_bridgeH(int motor, int speed, int rotation){


    // Turn Righ
        //digitalWrite(MotorA_IA, HIGH);
    analogWrite(MotorA_IA, speed);    //PWM
    digitalWrite(MotorA_IB, LOW);
    digitalWrite(LED_GREEN, HIGH);
    delay(300);
    // Stop
    digitalWrite(MotorA_IA, LOW);
    digitalWrite(MotorA_IB, LOW);
    digitalWrite(LED_GREEN, LOW);
    delay(1000);
    // Turn Left
        // digitalWrite(MotorA_IA, LOW);
    analogWrite(MotorA_IA, (255-speed));    //PWM
    digitalWrite(MotorA_IB, HIGH);
    digitalWrite(LED_RED, HIGH);
    delay(300);
    // Stop
    digitalWrite(MotorA_IA, LOW);
    digitalWrite(MotorA_IB, LOW);
    digitalWrite(LED_RED, LOW);
    delay(1000);


  }//test_bridgeH  FIN



void R3D3::dot()
{
  digitalWrite(_pin, HIGH);
  delay(250);
  digitalWrite(_pin, HIGH);
  delay(250);
}

void R3D3::dash()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);

 delay(250);
}
