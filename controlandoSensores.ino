// Autor: Allan Otárola Villalobos
// Fecha: 6/11/17
// Práctica dirigida 1 (controlandoSensores)
// Se utilizan el Microcontrolador CircuitPlayground


#include <Adafruit_CircuitPlayground.h>

void setup() {
  
Serial.begin(9600);// Instrucción que iniciliza el monitor serial

}

void loop() {

sensoresBotonesContacto();
Serial.println();

sensorInterruptor();
Serial.println();

sensorDeLuz();
Serial.println();

sensorDeSonido();
Serial.println();

sensorTemperatura();
Serial.println();

}

//A continuación procedimiento que reporta valores de los botones de la CircuitPlayground

void sensoresBotonesContacto() {

  int valorBotonDerecho = CircuitPlayground.rightButton();
  int valorBotonIzquierdo = CircuitPlayground.leftButton();

  Serial.print("Valor del botón drecho: ");
  delay(500);
  Serial.println(valorBotonDerecho);
  delay(500);

  Serial.print("Valor del botón Izquierdo: ");
  delay(500);
  Serial.println(valorBotonIzquierdo);
  delay(500);
  
}

//A continuación procedimiento que reporta el valor del interruptor de la CircuitPlayground

void sensorInterruptor(){

  int valorInterruptor = CircuitPlayground.slideSwitch();


  if (valorInterruptor == 1){
    
    Serial.print("Posición del interruptor: lado izquierdo");
    Serial.println();
    delay(500);
  }
  else{
    
    Serial.print("Posición del interruptor: lado derecho");
    Serial.println();
    delay(500); 
    
  }


}


//A continuación procedimiento que reporta el valor del sensor de luz de la CircuitPlayground

void sensorDeLuz(){

  int valorLuz = CircuitPlayground.lightSensor();

    Serial.print("Valor detectado de luz: ");
    Serial.println(valorLuz);
    delay(500); 

}


//A continuación procedimiento que reporta el valor del sensor de sonido de la CircuitPlayground

void sensorDeSonido(){

  int valorSonido = CircuitPlayground.soundSensor();

    Serial.print("Valor detectado de sonido: ");
    Serial.println(valorSonido);
    delay(500); 

}


//A continuación procedimiento que reporta el valor del sensor de temperatura de la CircuitPlayground

void sensorTemperatura(){

  int valorTemperatura = CircuitPlayground.temperature();

    Serial.print("Valor detectado de temperatura: ");
    Serial.println(valorTemperatura);
    delay(500); 

}
