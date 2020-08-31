#ifndef VEX_H
#define VEX_H
#include "vex.h"
#endif

#ifndef MOTOROBJECT_H
#define MOTOROBJECT_H
#include "objectLib/motorObject.h"
#endif

#ifndef POTOBJECT_H
#define POTOBJECT_H
#include "objectLib/potObject.h"
#endif

//motorObj Library Header Guard
#ifndef sensorObj_H
#define sensorObj_H

class cSystem
{
  private:
    cMotor& rMotor;
    cPot& rPot;
    double frequency;
    double currentFreq = 0;
    double zeroOffset = 0;
    int differenceCount = 0;
  public:
    cSystem(cMotor& fMotor, cPot& fPot, double Frequency);
    void setFrequency(double Frequency);
    void setSpeed(double percent);
    void setZero(double degrees);
    double getPos();
};

#endif