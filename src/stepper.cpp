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
    if(steps == 0){
        digitalWrite(DIRpin, HIGH);
        int numStep = round(deg/stepAngle*gearRatio);
        Serial.println(numStep);
        for(int x = 0; x < numStep; x++){
            digitalWrite(PULpin, HIGH);
            delayMicroseconds(speed);
            digitalWrite(PULpin, LOW);
            delayMicroseconds(speed);
            
        }
        steps = numStep;
        delay(200);
        
    }
    if(steps != 0){
        float currDeg = steps*stepAngle;
        if(deg<currDeg){
            float travDeg = currDeg-deg;
            int numStep = round(travDeg/stepAngle*gearRatio);
            digitalWrite(DIRpin, LOW);
            for(int x = 0; x < numStep; x++){
                digitalWrite(PULpin, HIGH);
                delayMicroseconds(speed);
                digitalWrite(PULpin,LOW);
                delayMicroseconds(speed);
                steps--;
            }
            delay(200);
        }

        if(deg>currDeg){
            float travDeg = currDeg+deg;
            int numStep = round(travDeg/stepAngle*gearRatio);
            digitalWrite(DIRpin, HIGH);
            for(int x = 0; x < numStep; x++){
                digitalWrite(PULpin, HIGH);
                delayMicroseconds(speed);
                digitalWrite(PULpin,LOW);
                delayMicroseconds(speed);
                steps++;
            }
            
            delay(200);
        }

    }
}




