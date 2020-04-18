int ledPin1=9;
int ledPin2=10;
int ledPin3=11;
void setup() 
{
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
}
void loop()
{
  digitalWrite(ledPin1,HIGH);
  delay(100);
  digitalWrite(ledPin2,HIGH);
  delay(100);
  digitalWrite(ledPin3,HIGH);
  delay(100);
  digitalWrite(ledPin1,LOW);
  delay(40);
  digitalWrite(ledPin2,LOW);
  delay(40);
  digitalWrite(ledPin3,LOW);
  delay(40);
}
