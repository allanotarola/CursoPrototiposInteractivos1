/*
Autor: Allan Otárola Villalobos
Reto2: Encender neoPixeles con un boton.
Fecha: 7/11/17
*/

#include <Adafruit_CircuitPlayground.h> /// prueba
#include <Adafruit_Circuit_Playground.h>


const int buttonPin = 10;     // Número del pin 


int estadoBoton = 0;         // variable que almacena el estado del botón

void setup() {

  //Se iniciliza el pin 10 como INPUT y se inicializa la circuitPlayGround

  CircuitPlayground.begin();
  pinMode(buttonPin, INPUT);

}

void loop() {
  
  // lectura del estado del botón
  estadoBoton = digitalRead(buttonPin);

  

  // condicional que verifica si el botón está encendido o apagado
  if (estadoBoton == HIGH) {
    
    // enciende los neoPixeles de la circuitPlayGround
    CircuitPlayground.setPixelColor(0,255,255,255);
    CircuitPlayground.setPixelColor(1,255,255,255);
    CircuitPlayground.setPixelColor(2,255,255,255);
    CircuitPlayground.setPixelColor(3,255,255,255);
    CircuitPlayground.setPixelColor(4,255,255,255);
    CircuitPlayground.setPixelColor(5,255,255,255);
    CircuitPlayground.setPixelColor(6,255,255,255);
    CircuitPlayground.setPixelColor(7,255,255,255);
    CircuitPlayground.setPixelColor(8,255,255,255);
    CircuitPlayground.setPixelColor(9,255,255,255);
    
    
  } else {
    // apaga los neoPixeles de la circuitPlayGround
    CircuitPlayground.setPixelColor(0,0,0,0);
    CircuitPlayground.setPixelColor(1,0,0,0);
    CircuitPlayground.setPixelColor(2,0,0,0);
    CircuitPlayground.setPixelColor(3,0,0,0);
    CircuitPlayground.setPixelColor(4,0,0,0);
    CircuitPlayground.setPixelColor(5,0,0,0);
    CircuitPlayground.setPixelColor(6,0,0,0);
    CircuitPlayground.setPixelColor(7,0,0,0);
    CircuitPlayground.setPixelColor(8,0,0,0);
    CircuitPlayground.setPixelColor(9,0,0,0);
  }
}
