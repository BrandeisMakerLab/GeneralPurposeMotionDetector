# AGSOL-Gyro-Tactor
ABOUT:

This is a prototype of a general purpose module to use gyroscope measurements for playing different vibration effects. The base system includes a MPU_6000 gyroscope/accelerometer, an Adafruit tactor controller, and an Arduino Uno. It reads and calibrates incoming acceleration values in order to provide tactile feedback to the user regarding acceleration. The ultimate goal is to collect additional data for motion experiments, and to see how the stimulus affects participants' ability to complete tasks.

HOW TO USE:
  1. Open the Accelerometer_Front_End Example file from the examples folder.
  2. The system currently uses maximum and minimum calibration values that are entered into the calibration function.
  3. After doing this, upload the revised program to the board.
  4. If you open the serial monitor, the board should constantly print "NOT MOVING" until it is moved in any direction.
  5. Move the board around to make it play different effects. It will begin playing an effect when acceleration of magnitude 0.02 or larger is detected and continue to do this until the board is held still or detects acceleration in another direction.
  6. If different effects are desired, consider changing them. The full list can be found in the included file titled adafruit_products_DRV_Waveforms.png. This will require editing the variable inputs to the waveform function, which can be found in the ___
  
KNOWN ISSUES:
  1. Acceleration in the Z direction seems to have larger magnitudes than on the other two axis. More testing is needed to determine why      this is.
  2. Currently the logic prioritizes movement in the X direction, then the Y, then the Z. This could be problematic for certain experiments, and would require switching the order of statements. Switch cases would be a potential solution to this problem.
   
TO DO:
  1. Consider how the minimum expected value fits into this model
  2. Currently values are only calibrated for the acceleromter. This should be done for the gyroscope as well.
