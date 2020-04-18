#include <Servo.h>
Servo myservo;
int val;
byte LDRL = 0;
byte LDRR = 1;

void setup()
{
  myservo.attach(12);
}
void loop()
{
   if(analogRead(LDRL) > analogRead(LDRR) ) {
      myservo.write(0); // move to angel 80 degrees or what ever you want
}
else {
     myservo.write(180); // move to angel 100 degrees or what ever you want
  }
} 
