#include <stdlib.h>
#include <Wire.h>

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
  Wire.begin();
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}


void loop() {
  // print the string when a newline arrives:
  if (stringComplete) {
    //Serial.println(inputString);
    // clear the string:
    char s[1];
    s[0]= (char) inputString[0];
    int led = atoi(s);
    s[0]= (char) inputString[2];
   int level = atoi(s);
//   Serial.println("led");
//    Serial.println(led);
//    Serial.println("level");
//    Serial.println(level);
    inputString = "";
    stringComplete = false;
  
 // Comenzamos la transmisión al dispositivo 1
    Wire.beginTransmission(1);

    // Enviamos un byte, será el pin a encender
    Wire.write(led);

    // Enviamos un byte, L pondrá en estado bajo y H en estado alto
    Wire.write(level);

    // Paramos la transmisión
    Wire.endTransmission();

    // Esperamos 1 segundo
    delay(1000);
}
}
/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
