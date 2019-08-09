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

//this should work on all boards, so there is no preprocessor directive here

//includes the libraries of code necessary to make this one work
#include <Accelerometer_Front_End.h>

//Creates a new Accelerometer_Front_End object
Accelerometer_Front_End::Accelerometer_Front_End() {
}

//Initializes the class, can't always be done at same time as constructor
void Accelerometer_Front_End::begin() {
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    //Define a variable to determine the maximum expected acceleration value. This will be used to scale the outputs throughout the program.
    min = // = 1;
    //uble xmax = 20000
    ymax = // = 20000;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    threshold = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    xAccelerationGain = 1;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    xAccelerationOffset = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    yAccelerationGain = 1;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    yAccelerationOffset = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    zAccelerationGain = 1;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    zAccelerationOffset = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    xGyroGain = 1;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    xGyroOffset = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    yGyroGain = 1;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    yGyroOffset = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    zGyroGain = 1;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    zGyroOffset = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    xAccelerationValue = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    yAccelerationValue = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    zAccelerationValue = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    xGyroValue = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    yGyroValue = 0;
    //TODO: EXPLAIN WHAT VARIABLE IS FOR
    zGyroValue = 0;
    drv.begin();
    drv.selectLibrary(1);
    drv.setMode(DRV2605_MODE_INTTRIG);
    sensorinterface.begin();
}

//Determine min, xmax, ymax, and zmax values from user input
void Accelerometer_Front_End::setCalibrationValues (double min_new, double xmax_new, double ymax_new, double zmax_new) {
    min = min_new;
    xmax = xmax_new;
    ymax = ymax_new;
    zmax = zmax_new;

}

// Uses the minimum and maximum values to calibrate by subtracting min from max. This allows values to more accurately fit as a function of the maximum.
void Accelerometer_Front_End::initialize() {
    xmax = xmax - min;
    ymax = ymax - min;
    zmax = zmax - min;
    // delay(100);
    xAccelerationGain=1/xmax;
    yAccelerationGain=1/ymax;
    zAccelerationGain=1/zmax;

}

//Allows the user to adjust the threshold for when effects begin playing.
void Accelerometer_Front_End::setThreshold(double threshold_new) {
    threshold = threshold_new;

}

//TODO: EXPLAIN WHAT METHOD DOES
void Accelerometer_Front_End::getAcceleration() {
    xAccelerationValue = xAccelerationGain * sensorinterface.getXAccelerometerCounts()  +  xAccelerationOffset;
    yAccelerationValue = yAccelerationGain * sensorinterface.getYAccelerometerCounts()  +  yAccelerationOffset;
    zAccelerationValue = zAccelerationGain * sensorinterface.getZAccelerometerCounts()  +  zAccelerationOffset;

}

//Takes the input values from the gyroscope sensor so they can be printed to the serial monitor.
void Accelerometer_Front_End::getGyro() {
    xGyroValue = xGyroGain * sensorinterface.getXGyroCounts()  +  xGyroOffset;
    yGyroValue = yGyroGain * sensorinterface.getYGyroCounts()  +  yGyroOffset;
    zGyroValue = zGyroGain * sensorinterface.getZGyroCounts()  +  zGyroOffset;

}

//Conditional statement tree to get make the tactor play different effects based on the direction a subject is heading
void Accelerometer_Front_End::findEffect() {
    //Full list of effects can be found in adafruit_products_DRV_Waveforms.png
    //Acceleration must exceed a minimum value of 0.02 in a given direction to filter out noise
    if (xAccelerationValue >= threshold) {
      setWaveform(1);
    }
    else if (xAccelerationValue <= -threshold) {
      setWaveform(47);
    }
    else if (yAccelerationValue >= threshold) {
      setWaveform(82);
    }
    else if (yAccelerationValue <= -threshold) {
      setWaveform(52);
    }
    else if (zAccelerationValue >= threshold) {
      setWaveform(58);
    }
    else if (zAccelerationValue <= -threshold) {
      setWaveform(31);
    }
    else {
      Serial.println("NOT MOVING");
      delay(50);
    }

}

//TODO: EXPLAIN WHAT METHOD DOES
void Accelerometer_Front_End::print() {
    Serial.print(" AccelerationX = ");
    Serial.print(xAccelerationValue);
    Serial.print(" AccelerationY = ");
    Serial.print(yAccelerationValue);
    Serial.print(" AccelerationZ = ");
    Serial.print(zAccelerationValue);
    Serial.print(" GyroX = ");
    Serial.print(xGyroValue);
    Serial.print(" GyroY = ");
    Serial.print(yGyroValue);
    Serial.print(" GyroZ = ");
    Serial.println(zGyroValue);
    //Serial.print(" Temperature = ");
    //Serial.print(getTemperature());

}

//TODO: EXPLAIN WHAT METHOD DOES
void Accelerometer_Front_End::setWaveform(int waveform) {
    drv.setWaveform(0,waveform);
    drv.go();
    delay(50);

}
