#include <SPI.h>
#include <SD.h>

#define CS 8

int i = 0;
File logFile;

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

  // Files that are opened for writing will be
  // created automatically if they don't already
  // exist on the SD card
  logFile = SD.open("log.txt", FILE_WRITE);

  if (!logFile)
  {
    Serial.println("Could not open logfile!");
    while (1);
  }
}

void loop()
{
  // Replace the condition with a meaningful one
  // To indicate that writing to the file is done
  // and it can be closed.
  if (i++ < 10)
  {
    // Dummy Value, replace with real readout
    long sensorValue = random(0, 1023);

    // Write a few lines to the logfile
    logFile.print("[ERROR: ");
    logFile.print(millis());
    logFile.print("] ");
    logFile.println("Sensor A missing!");

    logFile.print("[INFO: ");
    logFile.print(millis());
    logFile.print("] ");
    logFile.print("Sensor B reading: ");

    logFile.println(sensorValue);
  }
  else
  {
    logFile.close();
    Serial.println("Writing finished!");
  }

  delay(500);
}
