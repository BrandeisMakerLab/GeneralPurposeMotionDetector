/* Prints distance to screen
   Created from example program and turned into class by Jacob Smith
*/
//includes the libraries of code necessary to make this one work
#include <SensorInterface.h>
//runs the haptic motor library
#include <Wire.h>
#include "Adafruit_DRV2605.h"
//The object used to interfact with the class
SensorInterface sensorinterface;
Adafruit_DRV2605 drv;

//includes the libraries of code necessary to make this one work
int time=500;
int pin=2;
uint8_t effect = 1;
//runs once
void setup() {

  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  //sets up the class
  sensorinterface.begin();
  Serial.println("xAccel\tyAccel\tzAccel\txGyro\tyGyro\tzGyro\tTemp");
   drv.begin();
  
  drv.selectLibrary(1);
  
  // I2C trigger by sending 'go' command 
  // default, internal trigger when sending GO command
  drv.setMode(DRV2605_MODE_INTTRIG); 

}

//runs many times
void loop() {
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time);
  //Prints raw values from the sensor to the monitor.
  //NOTE: In it's current state, temperature is not set up to work properly. More work must be done for that data to be useable.
  Serial.print(sensorinterface.getXAccelerometerCounts());
  Serial.print("\t");
  Serial.print(sensorinterface.getYAccelerometerCounts());
  Serial.print("\t");
  Serial.print(sensorinterface.getZAccelerometerCounts());
  Serial.print("\t");
  Serial.print(sensorinterface.getXGyroCounts());
  Serial.print("\t");
  Serial.print(sensorinterface.getYGyroCounts());
  Serial.print("\t");
  Serial.print(sensorinterface.getZGyroCounts());
  Serial.print("\t");
  Serial.println(sensorinterface.getTemperature());
  digitalWrite(pin, LOW);   // turn the LED on (HIGH is the voltage level)
  drv.setWaveform(0, effect);  // play effect 
  drv.setWaveform(1, 0);       // end waveform

  // play the effect!
  drv.go();

  // wait a bit
  delay(time);

  effect++;
  if (effect > 117) effect = 1;
}
