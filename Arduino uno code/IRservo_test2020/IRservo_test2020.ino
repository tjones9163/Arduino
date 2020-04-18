
#include <Servo.h>
#include <IRremote.h>

Servo myservo;  // create servo object to control a servo
                // twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

const int RECV_PIN = 4;

IRrecv irrecv(RECV_PIN);
decode_results results;


void setup(){
  Serial.begin(9600);


myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
  irrecv.enableIRIn();
  

}


void loop(){
    if (irrecv.decode(&results)){

        switch(results.value){
          case 0x20df40bf: 
     
 Serial.println(results.value);
 delay(1);
         for (pos = 0; pos <= 180; pos += 1) {       // goes from 0 degrees to 180 degrees
                                                     // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) {           // goes from 180 degrees to 0 degrees
    myservo.write(pos);                           // tell servo to go to position in variable 'pos'
    delay(15);                                    //
        
    }
    irrecv.resume(); 
  }

}}
