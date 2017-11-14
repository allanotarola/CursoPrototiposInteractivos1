#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

#include <OneWire.h> //Se importa la biblioteca que controla el sensor de temperatura sumergible.

int DS18S20_Pin = 2; //Definición de variable "DS18S20" que representa la señal del pin digital 2

//Chip de temperatura  entrada/salida

OneWire ds(DS18S20_Pin);  // Se crea un ejemplar "ds" de la clase OneWire conectado en el Pin 2 digital.

void setup(void) {

  CircuitPlayground.begin();
  Serial.begin(9600); //Se inicia el monitor serial

}

void loop(void) {
  
  float temperature = getTemp(); //Se guarda el valor que obtiene el sensor y se guarda en la variable "temperature" puede tardar 2 segundos en ejecutarse.
  
  Serial.print("Temperatura del agua: "); // Se imprime en el monitor serial el valor de la variable de temperatura.
  Serial.println(temperature); // Se imprime en el monitor serial el valor de la variable de temperatura.

  fuenteVentilacion(temperature);// procedimiento que verifica nivel de temperatura para eventualemente activar ventilador
  
  fuenteCalor (temperature);//procedimiento que verifica nivel de temperatura para eventualemente activar fuente de calor

  luzLed(temperature);// procedimiento que verifica niveles de luz y temperatura para eventualemente enceder luces led decorativas.
   
}

float getTemp(){ //Función que calcula la temperatura en grados centígrados
  
  byte data[12];
  byte addr[8];

  if ( !ds.search(addr)) {
      //no more sensors on chain, reset search
      ds.reset_search();
      return -1000;
  }
  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.println("CRC no es válido!");
      return -1000;
  }

  if ( addr[0] != 0x10 && addr[0] != 0x28) {
      Serial.print("El dispositivo no se reconoce");
      return -1000;
  }
  ds.reset();
  ds.select(addr);
  ds.write(0x44,1); // inicia la conversión
  
  delay(2000); // Espera para que la conversión de temperatura se complete

  byte present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE); //
  
  for (int i = 0; i < 9; i++) { 
    data[i] = ds.read();
  }
  
  ds.reset_search();
  byte MSB = data[1];
  byte LSB = data[0];

  float tempRead = ((MSB << 8) | LSB);
  float TemperatureSum = tempRead / 16;
  
  return TemperatureSum;// se retorna el valor de la temperatura en grados centígrados 
}


void fuenteCalor (float temperatura){

    if (temperatura < 25 ){
    
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
    
    Serial.println("La temperatura está a menos de 25 grados, se encendió la fuente de calor");
    
  }else{

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
void fuenteVentilacion(float temperatura){

    if (temperatura > 27 ){
    
      CircuitPlayground.playTone(100,1000);
      Serial.println("La temperatura está a más de 27 grados, se encendió el ventilador");
    
    }
}
void luzLed(float temperatura){

  int luz = CircuitPlayground.lightSensor();

  if (luz < 10 and temperatura < 27 and temperatura > 24){
  
    CircuitPlayground.setPixelColor(0,10,180,10);
    CircuitPlayground.setPixelColor(1,10,180,10);
    CircuitPlayground.setPixelColor(2,10,180,10);
    CircuitPlayground.setPixelColor(3,10,180,10);
    CircuitPlayground.setPixelColor(4,10,180,10);
    CircuitPlayground.setPixelColor(5,10,180,10);
    CircuitPlayground.setPixelColor(6,10,180,10);
    CircuitPlayground.setPixelColor(7,10,180,10);
    CircuitPlayground.setPixelColor(8,10,180,10);
    CircuitPlayground.setPixelColor(9,10,180,10);

    delay(500);

    CircuitPlayground.setPixelColor(0,5,5,190);
    CircuitPlayground.setPixelColor(1,5,5,190);
    CircuitPlayground.setPixelColor(2,5,5,190);
    CircuitPlayground.setPixelColor(3,5,5,190);
    CircuitPlayground.setPixelColor(4,5,5,190);
    CircuitPlayground.setPixelColor(5,5,5,190);
    CircuitPlayground.setPixelColor(6,5,5,190);
    CircuitPlayground.setPixelColor(7,5,5,190);
    CircuitPlayground.setPixelColor(8,5,5,190);
    CircuitPlayground.setPixelColor(9,5,5,190);
  }
}
