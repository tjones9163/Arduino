 #include <Servo.h>;
 const int buttonPin = 8;
 const int servoPin = 3;
 Servo servo;
 
int counter = 0;
void setup()
{
  servo.attach (servoPin);
  
  pinMode(buttonPin, INPUT);
}

void loop()
{
  int buttonState;  
  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) // light the LED
  {
    counter++;
    delay(150);
  }
if(counter == 0)
    servo.write (20);  // zero degrees
  else if(counter == 1)
    servo.write(90);
  else if(counter == 2)
    servo.write (150); 
  else if(counter == 3)  
    servo.write (180);
  
  else
   counter = 0;
} 
