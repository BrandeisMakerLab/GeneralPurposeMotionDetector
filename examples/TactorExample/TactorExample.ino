/* Prints distance to screen
   Created from example program and turned into class by Jacob Smith
*/
//includes the libraries of code necessary to make this one work
int time=500;
int pin=2;
//runs once
void setup() {

  //sets up the class with minimum and maximum values
  Serial.begin(9600);
  pinMode(2, OUTPUT);

}

//runs many times
void loop() {
  Serial.println("Tactor On");
  digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time);
  Serial.println("Tactor Off");
  digitalWrite(pin, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(time);
}
