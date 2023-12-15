#include <Arduino.h>
#include <stepper.h>

stepper Joint1;
stepper Joint2;
stepper Joint3;
stepper Joint4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Joint1.init(4, 2, 3, 1.8, 4);
  Joint2.init(4, 5, 7, 1.8, 25);
  Joint3.init(4, 8, 9, 1.8, 4);
  Joint4.init(4, 10, 11, 0.9);


}

void loop() 
{
  // put your main code here, to run repeatedly:
  delay(15000);
  for(int x = 0; x < 50; x++){
    
  }
  


}