# AGSOL-Gyro-Tactor
ABOUT:

This is a prototype of a general purpose module to use gyroscope measurements for playing different vibration effects. The base system includes a MPU_6000 gyroscope/accelerometer, an Adafruit tactor controller, and an Arduino Uno. It reads and calibrates incoming acceleration values in order to provide tactile feedback to the user regarding acceleration. The ultimate goal is to collect additional data for motion experiments, and to see how the stimulus affects participants' ability to complete tasks.

HOW TO USE:
  1. The system currently uses maximum and minimum calibration values that are hardcoded in. Until a front end is made, this should be edited manually based on expected maximum and minimum acceleration values. This can be found on line 130.
  2. After doing this, upload the revised program to the board.
  3. If you open the serial monitor, the board should constantly print "NOT MOVING" until it is moved in any direction.
  4. Move the board around to make it play different effects. It will begin playing an effect when acceleration of magnitude 0.02 or larger is detected and continue to do this until the board is held still or detects acceleration in another direction.
  5. If different effects are desired, consider changing them. The full list can be found in the included file titled adafruit_products_DRV_Waveforms.png.
  6. To see acceleration values in any direction, find the commented out lines underneath the calculations beginning on line 208. Deleting the comment markers (//) from the left side will print a measurement to the serial monitor. This is useful for debugging or data collection purposes, but not needed for a simple demo.

KNOWN ISSUES:
  1. Acceleration in the Z direction seems to have larger magnitudes than on the other two axis. More testing is needed to determine why      this is.
  2. Currently the logic prioritizes movement in the X direction, then the Y, then the Z. This could be problematic for certain experiments, and would require switching the order of statements. Switch cases would be a potential solution to this problem.
   
TO DO:
  1. Consider how the minimum expected value fits into this model
  2. Values for max are hardcoded for now. Create a program that gets the maximum acceleration and updates automatically.
  3. Currently values are only calibrated for the acceleromter. This should be done for the gyroscope as well.
