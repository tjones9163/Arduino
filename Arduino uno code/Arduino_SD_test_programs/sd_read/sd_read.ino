#include <SPI.h>
#include <SD.h>

#define CS 8

int i = 0;
File sensorFile;

boolean initCard()
{
  Serial.print("Connecting to SD card... ");

  // Initialize the SD card
  if (!SD.begin(CS))
  {
    // An error occurred
    Serial.println("\nError: Could not connect to SD card!");
    Serial.println("- Is a card inserted?");
    Serial.println("- Is the card formatted as FAT16/FAT32?");
    Serial.println("- Is the CS pin correctly set?");
    Serial.println("- Is the wiring correct?");

    return false;
  }
  else
    Serial.println("Done!");

  return true;
}

void setup()
{
  Serial.begin(9600);

  if (!initCard())
    while (1);
  
  // Files that are opened for reading have to
  // exist. They will not be created.
  sensorFile = SD.open("value.txt", FILE_WRITE);

  if (!sensorFile)
  {
    Serial.println("Could not open sensor file!");
    while (1);
  }
  else
  {
    // Move the cursor the the beginning of the file for reading
    sensorFile.seek(0);

    // Read the entire file and print
    // it to the serial console.
    while (sensorFile.available())
      Serial.write(sensorFile.read());
  }
}

void loop()
{
}
