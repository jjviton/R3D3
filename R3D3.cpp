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
  pinMode(MotorB_IA, OUTPUT);
  pinMode(MotorB_IB, OUTPUT);

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


    if(motor == Motor_A){
        // Turn Righ
        analogWrite(MotorA_IA, speed);    //PWM
        digitalWrite(MotorA_IB, LOW);
        digitalWrite(LED_GREEN, HIGH);
        delay(2000);
        // Stop
        digitalWrite(MotorA_IA, LOW);
        digitalWrite(MotorA_IB, LOW);
        digitalWrite(LED_GREEN, LOW);
        delay(1000);
        // Turn Left
        analogWrite(MotorA_IA, (255-speed));    //PWM
        digitalWrite(MotorA_IB, HIGH);
        digitalWrite(LED_RED, HIGH);
        delay(2000);
        // Stop
        digitalWrite(MotorA_IA, LOW);
        digitalWrite(MotorA_IB, LOW);
        digitalWrite(LED_RED, LOW);
        delay(1000);
      }
      else if(motor=Motor_B){
        // Turn Righ
        analogWrite(MotorB_IA, speed);    //PWM
        digitalWrite(MotorB_IB, LOW);
        digitalWrite(LED_GREEN, HIGH);
        delay(2000);
        // Stop
        digitalWrite(MotorB_IA, LOW);
        digitalWrite(MotorB_IB, LOW);
        digitalWrite(LED_GREEN, LOW);
        delay(1000);
        // Turn Left

        analogWrite(MotorB_IA, (255-speed));    //PWM
        digitalWrite(MotorB_IB, HIGH);
        digitalWrite(LED_RED, HIGH);
        delay(2000);
        // Stop
        digitalWrite(MotorB_IA, LOW);
        digitalWrite(MotorB_IB, LOW);
        digitalWrite(LED_RED, LOW);
        delay(1000);
      }

  }//test_bridgeH  FIN

void R3D3::moveForward(int speed){
  analogWrite(MotorA_IA, speed);    //PWM
  digitalWrite(MotorA_IB, LOW);
  analogWrite(MotorB_IA, speed);    //PWM
  digitalWrite(MotorB_IB, LOW);
}//moveForward

void R3D3::moveBack(int speed){
  analogWrite(MotorA_IA, 255-speed);    //PWM
  digitalWrite(MotorA_IB, HIGH);
  analogWrite(MotorB_IA, 255-speed);    //PWM
  digitalWrite(MotorB_IB, HIGH);
}//moveForward

// Metodo para parar los motores
void R3D3::stop(void){

  digitalWrite(MotorA_IA, LOW);
  digitalWrite(MotorA_IB, LOW);
  digitalWrite(MotorB_IA, LOW);
  digitalWrite(MotorB_IB, LOW);
}//stop

void R3D3::turnRight(int angle, int speed){
  // Turn Righ,Pivotando.
  analogWrite(MotorA_IA, speed);    //PWM
  digitalWrite(MotorA_IB, LOW);
  analogWrite(MotorB_IA, 255-speed);    //PWM
  digitalWrite(MotorB_IB, HIGH);
  delay(angle * 3,3);  // tiempo de giro
  stop();               // Paramos motores
}//turnRight
