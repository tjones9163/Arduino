#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
unsigned int distance;
byte redLed = 8;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup()
{
   Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
   pinMode(redLed, OUTPUT);
}

void loop()
{
   delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
   distance = sonar.ping_cm();
   Serial.print("Ping: ");
   Serial.print(distance); // Send ping, get distance in cm and print result (0 = outside set distance range)
   Serial.println("cm");
   if (distance < 40 && distance != 0) // less than 40 and exclude 0 readings
   {
      digitalWrite(redLed, HIGH);
   }
   else
   {
      digitalWrite(redLed, LOW);
   }
}
