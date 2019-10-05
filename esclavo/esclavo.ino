/*
  Programarfacil https://programarfacil.com
  Autor: Luis del Valle @ldelvalleh
  Comunicación I2C entre dos Arduinos, esclavo
*/

#include <Wire.h>

void setup() {
  // Pines en modo salida
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
//  pinMode(6, OUTPUT);

  // Unimos este dispositivo al bus I2C con dirección 1
  Wire.begin(1);

  // Registramos el evento al recibir datos
  Wire.onReceive(receiveEvent);

  // Iniciamos el monitor serie para monitorear la comunicación
  Serial.begin(9600);
}

void loop() {
  delay(300);
}

// Función que se ejecuta siempre que se reciben datos del master
// siempre que en el master se ejecute la sentencia endTransmission
// recibirá toda la información que hayamos pasado a través de la sentencia Wire.write
void receiveEvent(int howMany) {

  int pinOut = 0;
  int estado = 0;

  // Si hay dos bytes disponibles
  if (Wire.available() == 2)
  {
    // Leemos el primero que será el pin
    pinOut = Wire.read();
    Serial.print("LED ");
    Serial.println(pinOut);
  }
  // Si hay un byte disponible
  if (Wire.available() == 1)
  {
    estado = Wire.read();
    Serial.print("Estado ");
    Serial.println(estado);
  }

  // Activamos/desactivamos salida
  digitalWrite(pinOut,estado);
}
