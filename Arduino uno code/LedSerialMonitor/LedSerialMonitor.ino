int ledPin= 13;
int delayPeriod = 500;
int ledState;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}
void loop()
{
if (ledState == LOW) {
     ledState = HIGH;
  }
  else {
    ledState  = LOW;
  }
  digitalWrite(ledPin,ledState);
  Serial.println(ledState);
  delay(delayPeriod);
 
  }
  
  
 
