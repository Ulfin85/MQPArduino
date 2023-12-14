#include <Arduino.h>

class stepper
{
protected:
 int ENApin;
 int DIRpin;
 int PULpin;
 float stepAngle;
 float gearRatio;
    
    
public:
 int steps;
 void init(int ENA, int DIR, int PUL, float stepAngle, float gearRatio = 1.00);
 void driveStepper(float deg, int speed = 4000);

    
};