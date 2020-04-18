#include <Servo.h>
const int servo1=11;
const int servo2=10;
const int joyH=3;
const int joyV=4;
int servoVal;
Servo myservo1;
Servo myservo2;

void setup()
{
  myservo1.attach(servo1);
  myservo2.attach(servo2);
  Serial.begin(9600);
}
void loop(){
  outputJoystick();
  servoVal= analogRead(joyH);
  servoVal= map(servoVal,0, 1023, 0, 180);
  myservo2.write(servoVal);
  servoVal=analogRead(joyV);
  servoVal=map(servoVal,0, 1023, 70, 180);
  myservo1.write(servoVal);
  delay(15);
}
void outputJoystick(){
  Serial.print(analogRead(joyH));
  Serial.print("----");
  Serial.print(analogRead(joyV));
  Serial.println ("------------");
}
