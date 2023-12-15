#include <Arduino.h>
#include <stepper.h>

void stepper::init(int ENA, int DIR, int PUL, float sAngle, float ratio)
{
    ENApin = ENA;
    pinMode(ENApin, OUTPUT);
    DIRpin = DIR;
    pinMode(DIRpin, OUTPUT);
    PULpin = PUL;
    pinMode(PULpin, OUTPUT);
    stepAngle = sAngle;
    gearRatio = ratio;
    digitalWrite(ENApin, LOW);
    steps = 0;
}

void stepper::driveStepper(float deg, int speed)
{
    if(deg < 0)
    {
        if(steps<0)
        {

            if(deg<steps*stepAngle)
            {
                digitalWrite(DIRpin, LOW);
                int numStep = round(deg/stepAngle*gearRatio);
                int travStep = abs(numStep)-abs(steps);
                for(int x = 0; x < travStep; x++)
                {
                digitalWrite(PULpin, HIGH);
                delayMicroseconds(speed);
                digitalWrite(PULpin, LOW);
                delayMicroseconds(speed);
                steps--;
                }
                delay(200);

            }
            if(deg>steps*stepAngle)
            {
                digitalWrite(DIRpin, HIGH);
                int numStep = round(deg/stepAngle*gearRatio);
                int travStep = abs(numStep)-steps;
                for(int x = 0; x < travStep; x++)
                {
                digitalWrite(PULpin, HIGH);
                delayMicroseconds(speed);
                digitalWrite(PULpin, LOW);
                delayMicroseconds(speed);
                steps++;
                }
            
                delay(200);

            }
        }
        else{
            digitalWrite(DIRpin, LOW);
            int numStep = round(deg/stepAngle*gearRatio);
            int travStep = abs(numStep)+abs(steps);
            for(int x = 0; x < travStep; x++)
            {
            digitalWrite(PULpin, HIGH);
            delayMicroseconds(speed);
            digitalWrite(PULpin, LOW);
            delayMicroseconds(speed);
            steps--;
            }
            delay(200);
        }

    }

    else
    {
        if(steps>0){

            if(deg<steps*stepAngle)
            {
                digitalWrite(DIRpin, LOW);
                int numStep = round(deg/stepAngle*gearRatio);
                int travStep = abs(steps)-abs(numStep);
                for(int x = 0; x < travStep; x++)
                {
                digitalWrite(PULpin, HIGH);
                delayMicroseconds(speed);
                digitalWrite(PULpin, LOW);
                delayMicroseconds(speed);
                steps--;
                }
                delay(200);

                }
            if(deg>steps*stepAngle)
            {
                digitalWrite(DIRpin, HIGH);
                int numStep = round(deg/stepAngle*gearRatio);
                int travStep = abs(numStep)-steps;
                for(int x = 0; x < travStep; x++)
                {
                digitalWrite(PULpin, HIGH);
                delayMicroseconds(speed);
                digitalWrite(PULpin, LOW);
                delayMicroseconds(speed);
                steps++;
                }
            
                delay(200);

            }
        }
        else
        {
            digitalWrite(DIRpin, HIGH);
            int numStep = round(deg/stepAngle*gearRatio);
            int travStep = abs(numStep)+steps;
            for(int x = 0; x < travStep; x++)
            {
            digitalWrite(PULpin, HIGH);
            delayMicroseconds(speed);
            digitalWrite(PULpin, LOW);
            delayMicroseconds(speed);
            steps++;
            }
            
            delay(200);
        }
    }
    
}




