#ifndef ARMOBJECT_H
#define ARMOBJECT_H
#include "dogObject/armCalculator.h"
#endif

//motorObj Library Header Guard
#ifndef cArmVector_H
#define cArmVector_H

class cVector
{
  private:
    cArm& rArm;
    double desiredAngle = 0;
  public:
    cVector(cArm& vArm);

    void setHorizontalGravityDegree(double degrees);
    void setMagnitude(double length);
    void setAngle(double degrees);
    void step();
    void setEnabled(bool enabled);
    void setFrequency(double Frequency);

    double getCurrentMagnitude();
    double getCurrentAngle();
    
};

#endif