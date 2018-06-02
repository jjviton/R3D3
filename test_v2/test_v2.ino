#include <R3D3.h>

// Creamos un objeto de la clase r3d3.
R3D3 myR3D3(11);

// define los números de los pins
const int trigPin_1 = 12 ; 
const int echoPin_1 = 13 ; 
int microfono = 8;

// define variables
float duracion ;
float distancia;
float distancia1 ;
float distancia2 ;
float distancia3 ;
byte distancia10 ;
byte distancia20 ;
byte distancia30 ;
float distanciaMedia ;
int valorMic;
int empezar = 0;

///////////////////////////////////////////////////////////////// Funcion de preparacion de modulos
void setup ( ) { 
  pinMode( trigPin_1 , OUTPUT ) ;   // Establece el trigPin como salida
  pinMode( echoPin_1 , INPUT ) ;  // Establece el echoPin como entrada
  pinMode( microfono , INPUT) ; //Establece el microfono como entrada
  valorMic = 0;

//  headServo.attach(12);
myR3D3.Init();
  Serial.begin( 9600 ) ;    // Inicia la comunicación serial para debug

  while (!myR3D3.getPulsador(pulsador_A));  // Espera a que se pulse
}

/////////////////////////////////////////////////////// FUNCION PRINCIPAL /////////////////////////////////////////////////////////////

void loop ( ) { 
        
        //myR3D3.beep((byte)2);
        //while(1);
         
        // myR3D3.testServo();
        /*myR3D3.headPosition(HeadLeft);*/

        // myR3D3.stop(); while(1);
        // muevo es robot hacia delante
        //myR3D3.moveForward(100);
        //delay(100);

    valorMic = digitalRead(microfono); //Dar a valorMic el valor del microfono
    while ((valorMic != 1)&&(empezar<=0)){ //Establecer empezar como 1 si se detecta una palmada
      valorMic = digitalRead(microfono); //Dar a valorMic el valor del microfono
      myR3D3.stop();
    }
    if (empezar<=0){
       empezar=4;
    }
// Juego de cabeza mirando 
// 1. Colocar la cabeza mirando al frente y avanzar
        myR3D3.headPosition(112);
        myR3D3.headPosition(90);
        delay(400);

        myR3D3.moveForward(100);

// 2. Mirar si hay objeto delante. Si lo hay, giro 
        distanciaMedia = ultrasonido_medio();
        if(distanciaMedia < 50){
          myR3D3.moveBack(100);
          myR3D3.beep(100,2);
          delay(1000);
          myR3D3.turnRight(180, 100);
          myR3D3.moveForward(100);
          empezar--;
        }

// 3. Colocar la cabeza mirando a la izquierda y mirar si hay objeto
        myR3D3.headPosition(72);
        myR3D3.headPosition(45);
        delay(400);

        distanciaMedia = ultrasonido_medio();
        if(distanciaMedia < 50){
          myR3D3.moveBack(100);
          myR3D3.beep(100,2);
          delay(1000);
          myR3D3.turnRight(180, 100);
          myR3D3.moveForward(100);
           empezar--;
        }
// 3.1. Colocar la cabeza mirando al frente y mirar
        myR3D3.headPosition(72);
        myR3D3.headPosition(90);
        delay(400);
        distanciaMedia = ultrasonido_medio();
        if(distanciaMedia < 50){
          myR3D3.moveBack(100);
          myR3D3.beep(100,2);
          delay(1000);
          myR3D3.turnRight(180, 100);
          myR3D3.moveForward(100);
           empezar--;
        }

// 4. Colocar la cabeza mirando a la izquierda y repetir      
        myR3D3.headPosition(112);
        myR3D3.headPosition(135);
        delay(400);
        distanciaMedia = ultrasonido_medio();
        if(distanciaMedia < 50){
          myR3D3.moveBack(100);
          myR3D3.beep(100,2);
          delay(1000);
          myR3D3.turnRight(180, 100);
          myR3D3.moveForward(100);
           empezar--;
        }
       // if ( pulsador == ON)  myR3D3.stop();
}//loop

/////////////////////////////////////////// Función para calcular distancia desde un sensor de ultraSonido

float  ultrasonicDistance( byte sensorNum) {

  float dist=0;

        // Borra el trigPin
        digitalWrite ( trigPin_1 , LOW ) ;
        delayMicroseconds ( 20 ) ;
        // Establece el trigPin en estado ALTO durante 10 micro segundos
        // 1.- Lanzamos el pulso de sonido
        digitalWrite( trigPin_1 , HIGH ) ;
        delayMicroseconds( 10 ) ;
        digitalWrite ( trigPin_1 , LOW ) ;
        // 2.- Lee el echoPin, devuelve el tiempo de viaje de la onda de sonido en uSg
        duracion = pulseIn( echoPin_1 , HIGH ) ;
        // 3.- Calculando la distancia en centimetros ??
        dist = duracion * 0.034 / 2 ;

        /*
        // DEBUG:: Imprime la distancia en el monitor serie     
        Serial.print ( "Distancia:" ) ;
        Serial.println ( dist ) ;
        */
        
        return (dist);
}// fin ultasonicDistance

//////////////////////////////////////////// Función para calcular la muestra de la mitad de 3 muestras

float  ultrasonido_medio(){

  //Reiniciar los valores
  distancia10 =1;
  distancia20 =1;
  distancia30 =1;

  //Tomar 3 muestras
  distancia1 = ultrasonicDistance(1);
  delayMicroseconds(50);
  distancia2 = ultrasonicDistance(1);
  delayMicroseconds(50);
  distancia3 = ultrasonicDistance(1);

  //Hallar el más alto
  if ((distancia1 > distancia2) && (distancia1 > distancia3)){
    distancia10 = 0;
  }
  if ((distancia2 > distancia1) && (distancia2 > distancia3)){
    distancia20 = 0;
  }
  if ((distancia3 > distancia1)&&(distancia3 > distancia2)){
    distancia30 = 0;
  }

  //Hallar el más bajo
  if ((distancia1 < distancia2) && (distancia1 < distancia3)){
    distancia10 = 0;
  }
  if ((distancia2 < distancia1) && (distancia2 < distancia3)){
    distancia20 = 0;
  }
  if ((distancia3 < distancia1)&&(distancia3 < distancia2)){
    distancia30 = 0;
  }

/*
  //DEBUG
  Serial.print ("Distancia1: ");
  Serial.print (distancia1);
  Serial.print (" ");
  Serial.println (distancia10);
  Serial.print ("Distancia2: ");
  Serial.print (distancia2);
  Serial.print (" ");
  Serial.println (distancia20);
  Serial.print ("Distancia3: ");
  Serial.print (distancia3);
  Serial.print (" ");
  Serial.println (distancia30);
*/ 

  //Devolver el valor medio
  if (distancia10 != 0){
    return(distancia1);
  }
  if (distancia20 != 0){
    return(distancia2);
  }
  if (distancia30 != 0){
    return(distancia3);
  }
}//fin ultrasonidos_medio

