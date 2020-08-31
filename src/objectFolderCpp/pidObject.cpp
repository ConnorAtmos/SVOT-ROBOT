
#ifndef VEX_H
#define VEX_H
#include "vex.h"
#endif

#ifndef SYSOBJECT_H
#define SYSOBJECT_H
#include "objectLib/sensorSystem.h"
#endif

#ifndef PIDOBJECT_H
#define PIDOBJECT_H
#include "objectLib/pidObject.h"
#endif

//PID Object constructor
cPID::cPID(cSystem& vSystem, double KP, double KI, double KD, bool Enabled) : rSystem(vSystem), kP(KP), kI(KI), kD(KD), enabled(Enabled){};

//Say if to enable or disable pid
void cPID::setEnabled(bool Enabled){
  enabled = Enabled;
  if (!Enabled) totalError = 0;
}

//Say if to enable or disable pid
bool cPID::isEnabled(){
  return enabled;
}

//Change tuning values
void cPID::setTuning(double KP, double KI, double KD){
  kP = KP;
  kI = KI;
  kD = KD;
}

//Set desired angle
void cPID::setDesired(double degrees){
  desired = degrees;
}

//Step the pid
double cPID::step(){
  if(enabled){
    double error = desired - rSystem.getPos();
    totalError += error;
    double velocity = error - prevError;

    if((prevError < 0 && error > 0) || (prevError > 0 && error < 0)){
      totalError = 0;
    }
    
    prevError = error;

    return error * kP + totalError * kI + velocity * kD;
  }
  else{
    totalError = 0;
    return 0;
  }
}