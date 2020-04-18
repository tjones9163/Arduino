int ledPin = 13;
int delayPeriod = 1000;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  if (Serial.available() == 0)
  {
    Serial.println("LED: On");
    // Serial.println(ledPin, DEC);
    digitalWrite(ledPin, HIGH);
    delay(delayPeriod);
    //-------------------------
    Serial.println("LED: Off");
    digitalWrite(ledPin, LOW);
    delay(delayPeriod);
  }
}
