/* this code is written by geobruce
for more info check my site http://xprobe.net
*/
#include <Servo.h> 
Servo horizontal; 
int servoh = 90; 
Servo vertical; 
int servov = 90; 
int ldrlt = 0; 
int ldrrt = 1; 
int ldrld = 2; 
int ldrrd = 3; 
void setup()
{
  Serial.begin(9600);
  horizontal.attach(9); 
  vertical.attach(10);
}
void loop() 
{
  int lt = analogRead(ldrlt); 
  int rt = analogRead(ldrrt); 
  int ld = analogRead(ldrld); 
  int rd = analogRead(ldrrd); 
int dtime = analogRead(4)/20; 
int tol = analogRead(5)/4;
int avt = (lt + rt) / 2; 
int avd = (ld + rd) / 2; 
int avl = (lt + ld) / 2; 
int avr = (rt + rd) / 2; 
int dvert = avt - avd; 
int dhoriz = avl - avr;
if (-1*tol > dvert || dvert > tol) 
{
if (avt > avd)
{
servov = ++servov;
if (servov > 180)
{
servov = 180;
}
}
else if (avt < avd)
{
servov= --servov;
if (servov < 0)
{
servov = 0;
}
}
vertical.write(servov);
}

if (-1*tol > dhoriz || dhoriz > tol) 
{
if (avl > avr)
{
servoh = --servoh;
if (servoh < 0)
{
servoh = 0;
}
}
else if (avl < avr)
{
servoh = ++servoh;
if (servoh > 180)
{
servoh = 180;
}
}
else if (avl == avr)
{
// nothing
}
horizontal.write(servoh);
}
delay(dtime);
} 
