//VEX Header Guard
#ifndef VEX_H
#define VEX_H
#include "vex.h"
#endif

//motorObj Library Header Guard
#ifndef motorObj_H
#define motorObj_H

class cMotor
{
  private:
    motor& vMotor;
    double driver;
    double driven;
  public:
    cMotor(motor& sMotor, int Driver, int Driven);

    void setRatio(int Driver, int Driven);
    void setPos(double degrees);
    void setSpeed(double percent);
    double getPos();
};

#endif