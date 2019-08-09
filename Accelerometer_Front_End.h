/*Joseph Picard, Brandeis University; Ashton-Graybiel Spatial Orientation Lab

  Purpose: General purpose accelerometer/gyroscope to tactor effect controller.

  Email: jcpicard32@gmail.com

  Rights: Copyright (C) 2019 Joseph Picard
          License is GPL-3.0, included in License.txt of this project.

Circuit:
MPU6000 sensor attached to pins  10 - 13:
CSB: pin 10
MOSI: pin 11
MISO: pin 12
SCK: pin 13 2019/08/09*/

//sets up the Accelerometer_Front_End Header file
#ifndef Accelerometer_Front_End_h
#define Accelerometer_Front_End_h

//this should work on all boards, so there is no preprocessor directive here

//includes the libraries of code necessary to make this one work
#include <Accelerometer_Front_End.h>
#include <Adafruit_DRV2605.h>
#include <SensorInterface.h>

class Accelerometer_Front_End{
  private:
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    Adafruit_DRV2605 drv;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    SensorInterface sensorinterface;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    const int chipSelectPin = 10;
    //Define a variable to determine the maximum expected acceleration value. This will be used to scale the outputs throughout the program.
    double min;
    double xmax = 20000;
    double ymax = 20000;
    double zmax = 1000000;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    double threshold;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    double xAccelerationGain;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int xAccelerationOffset;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    double yAccelerationGain;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int yAccelerationOffset;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    double zAccelerationGain;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int zAccelerationOffset;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    double xGyroGain;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int xGyroOffset;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    double yGyroGain;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int yGyroOffset;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    double zGyroGain;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int zGyroOffset;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    double xAccelerationValue;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    double yAccelerationValue;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    double zAccelerationValue;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int xGyroValue;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int yGyroValue;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    int zGyroValue;
    //TODO: EXPLAIN WHAT METHOD DOES
    void setWaveform(int waveform);
  public:
    //Creates a new Accelerometer_Front_End object
    Accelerometer_Front_End();
    //Initializes the class, can't always be done at same time as constructor
    void begin();
    //Determine min, xmax, ymax, and zmax values from user input
    void setCalibrationValues (double min_new, double xmax_new, double ymax_new, double zmax_new);
    // Uses the minimum and maximum values to calibrate by subtracting min from max. This allows values to more accurately fit as a function of the maximum.
    void initialize();
    //Allows the user to adjust the threshold for when effects begin playing.
    void setThreshold(double threshold_new);
    //TODO: EXPLAIN WHAT METHOD DOES
    void getAcceleration();
    //Takes the input values from the gyroscope sensor so they can be printed to the serial monitor.
    void getGyro();
    //Conditional statement tree to get make the tactor play different effects based on the direction a subject is heading
    void findEffect();
    //TODO: EXPLAIN WHAT METHOD DOES
    void print();
};
#endif
