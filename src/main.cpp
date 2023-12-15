#include <Arduino.h>
#include <stepper.h>

stepper Joint1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Joint1.init(4, 2, 3, 1.8, 1);

}

void loop() {
  // put your main code here, to run repeatedly:
  Joint1.driveStepper(90);
  delay(2000);
  Joint1.getDeg();
  Joint1.driveStepper(0);
  delay(2000);
  Joint1.getDeg();
  Joint1.driveStepper(-90);
  delay(2000);
  Joint1.getDeg();
  Joint1.driveStepper(-30);
  delay(2000);
  Joint1.getDeg();
  Joint1.driveStepper(80);
  delay(2000);
  Joint1.getDeg();
  Joint1.driveStepper(-20);
  delay(2000);
  Joint1.getDeg();
  



  
  
  

}