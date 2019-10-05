//A variable to hold the level of coolness
int pin = 7;

void setup() {

  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}

void loop() {

  //Send the value of coolFactor to the the Serial port.
  //So we can see it in the serial monitor window
  digitalWrite(pin  , HIGH);
  Serial.println(pin);
  delay(2000);
  digitalWrite(pin, LOW);
  delay(2000);
}
