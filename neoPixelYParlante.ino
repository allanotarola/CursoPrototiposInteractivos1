// Autor: Allan Otárola Villalobos
// Fecha: 19/10/17
// Práctica dirigida 1 (NeoPixelYParlante)
// Se utilizan el Microcontrolador CircuitPlayground

//Se importa la biblioteca que controla la CircuitPlayground
#include <Adafruit_CircuitPlayground.h>



void setup() { //Procedimiento de configuración del programa 


  CircuitPlayground.begin();// Instrucción que inicializa la tarjeta CircuitPlayground
  Serial.begin(9600);// Instrucción que iniciliza el monitor serial

}

void loop() { //Procedimiento cíclico del programa 

  CircuitPlayground.setPixelColor(0,255,0,255); //Método setPixelColor del objeto CircuitPlayground que recibe 4 parámetros: Número del NeoPixel, Valor del RED, Valor del Green, Valor del Blue
  CircuitPlayground.playTone(100,1000); //Método playTone del objeto CircuitPlayground que recibe los parámetros del valor de frecuencia y tiempo 
  delay(1000); // precedimiento que realiza una pausa de 1 segundo.
  

}
