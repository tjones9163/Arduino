#include <RF24.h>
#define led 12
RF24 radio(7,8);
const byte adresses[] [6] = {"00001", "00002"};
boolean buttonState = 0;
void setup() {
  pinMode(12,OUTPUT);
  radio.begin();
  radio.openWritingPipe(adresses[1]);
  radio.openReadingPipe(1,adresses[0]);
  radio.setPALevel(RF24_PA_MIN);
}
void loop() {
  delay(5);
  radio.stopListening();
  int potValue = analogRead(A0);
  int angleValue = map(potValue, 0, 1023, 0, 180);
  radio.write(&angleValue, sizeof(angleValue));
  delay(5);
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonState, sizeof(buttonState));
  if(buttonState==HIGH)
  {
    digitalWrite(led,HIGH);
  }
else {
  digitalWrite(led,LOW);
}
}
