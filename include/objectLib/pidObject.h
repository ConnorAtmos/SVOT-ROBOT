#ifndef VEX_H
#define VEX_H
#include "vex.h"
#endif

#ifndef SYSOBJECT_H
#define SYSOBJECT_H
#include "objectLib/sensorSystem.h"
#endif

//motorObj Library Header Guard
#ifndef pidObj_H
#define pidObj_H

class cPID
{
  private:
    cSystem& rSystem;
    double kP;
    double kI;
    double kD;
    bool enabled;
    double prevError = 0;
    double totalError = 0;
    double desired = 0;
  public:
    cPID(cSystem& vSystem, double KP, double KI, double KD, bool Enabled);
    void setEnabled(bool Enabled);
    void setTuning(double KP, double KI, double KD);
    void setDesired(double degrees);
    bool isEnabled();
    
    double step();
};

#endif