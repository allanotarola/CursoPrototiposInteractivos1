// Autor: Allan Otárola Villalobos
// Fecha: 6/11/17
// Reto1 sensorAcelerometro (reto1)
// Se utilizan el Microcontrolador CircuitPlayground

#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

 float valorX;
 float valorY;
 float valorZ;


void setup() {

  CircuitPlayground.begin();
  Serial.begin(9600);


}

void loop() {

  valorX = CircuitPlayground.motionX();
  valorY = CircuitPlayground.motionY();
  valorZ = CircuitPlayground.motionZ();
  
  Serial.print(" Valor de x: ");
  Serial.print(valorX);
 

  Serial.print(" Valor de Y: ");
  Serial.print(valorY);
 

  Serial.print(" Valor de Z: ");
  Serial.println(valorZ);

  acelerometroXYZ();

}

void acelerometroXYZ(){


  if(valorX < -5){

  
    CircuitPlayground.setPixelColor(1,255,0,255);
    CircuitPlayground.setPixelColor(0,255,0,255);
    CircuitPlayground.setPixelColor(9,255,0,255);
    CircuitPlayground.setPixelColor(8,255,0,255);


  
  }
  else{
  
    CircuitPlayground.setPixelColor(1,0,0,0);
    CircuitPlayground.setPixelColor(0,0,0,0);
    CircuitPlayground.setPixelColor(9,0,0,0);
    CircuitPlayground.setPixelColor(8,0,0,0);
   
  }

  if(valorX > 5){


    CircuitPlayground.setPixelColor(3,255,0,255);
    CircuitPlayground.setPixelColor(4,255,0,255);
    CircuitPlayground.setPixelColor(5,255,0,255);
    CircuitPlayground.setPixelColor(6,255,0,255);
  
  }
  else{
  
    CircuitPlayground.setPixelColor(3,0,0,0);
    CircuitPlayground.setPixelColor(4,0,0,0);
    CircuitPlayground.setPixelColor(5,0,0,0);
    CircuitPlayground.setPixelColor(6,0,0,0);
   
  }

  if(valorY < -5){

    CircuitPlayground.setPixelColor(0,255,0,255);
    CircuitPlayground.setPixelColor(1,255,0,255);
    CircuitPlayground.setPixelColor(2,255,0,255);
    CircuitPlayground.setPixelColor(3,255,0,255);
    CircuitPlayground.setPixelColor(4,255,0,255);
  
  }
  else{
  
    CircuitPlayground.setPixelColor(0,0,0,0);
    CircuitPlayground.setPixelColor(1,0,0,0);
    CircuitPlayground.setPixelColor(2,0,0,0);
    CircuitPlayground.setPixelColor(3,0,0,0);
    CircuitPlayground.setPixelColor(4,0,0,0);
   
  }

  if(valorY > 5){

    CircuitPlayground.setPixelColor(5,255,0,255);
    CircuitPlayground.setPixelColor(6,255,0,255);
    CircuitPlayground.setPixelColor(7,255,0,255);
    CircuitPlayground.setPixelColor(8,255,0,255);
    CircuitPlayground.setPixelColor(9,255,0,255);
  
  }
  else{
  
    CircuitPlayground.setPixelColor(5,0,0,0);
    CircuitPlayground.setPixelColor(6,0,0,0);
    CircuitPlayground.setPixelColor(7,0,0,0);
    CircuitPlayground.setPixelColor(8,0,0,0);
    CircuitPlayground.setPixelColor(9,0,0,0);
   
  }

}
