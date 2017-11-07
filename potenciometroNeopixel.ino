//Se importan las librerías de la tarjeta
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

int contador=0;//Se declara una variable de tipo entero

void setup() {

  pinMode(A9,INPUT);//Se configura el PIN 9 análogo de entrada
  CircuitPlayground.begin();//Se inicializa la tarjeta
  Serial.begin(9600);

}

void loop() {


  int val=map(analogRead(A9),0,1023,0,255);// La función map convierte el dato que nos ofrece el pin 9 a través del potenciómentro en un valor  entre 0 y 255 y se guarda en la variable val

 
  contador=(contador+1)%10;// se genera cada loop un valor entre 0 y 9 para encender el neoPixel correspondiente.
  
  CircuitPlayground.setPixelColor(contador,CircuitPlayground.colorWheel(val)); //Enciende ek neoPixel correspondiente en el color segun se defina con la variable val

}
