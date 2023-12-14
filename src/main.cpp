#include <Arduino.h>
#include <stepper.h>

stepper Joint1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Joint1.init(4, 2, 3, 1.8, 25);

}

void loop() {
  // put your main code here, to run repeatedly:
  Joint1.driveStepper(360);
  delay(5000);



  
  
  

}