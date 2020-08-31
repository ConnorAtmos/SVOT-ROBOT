//VEX Header Guard
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

#ifndef SYSOBJECT_H
#define SYSOBJECT_H
#include "objectLib/sensorSystem.h"
#endif

#ifndef SYSOBJECT_H
#define SYSOBJECT_H
#include "objectLib/system-config.h"
#endif

#ifndef PIDOBJECT_H
#define PIDOBJECT_H
#include "objectLib/pidObject.h"
#endif

//motorObj Library Header Guard
#ifndef cArmObj_H
#define cArmObj_H

class cArm
{
  private:
    cSystem& shoulder;
    cSystem& elbow;
    cPID shoulderPID;
    cPID elbowPID;

    double weightMultiplier = 1;

    double inputtedMagnitude;
    double armLength;
    double maxMagnitude;
    double elbowWeight;
    double shoulderWeight;
  public:
    cArm(cSystem& Shoulder, double ShoulderWeight, double sKP, double sKI, double sKD, cSystem& Elbow, double ElbowWeight, double eKP, double eKI, double eKD, double ArmLength);

    void setMagnitude(double magnitude);
    void setShoulderPower(double percent);
    void setElbowPower(double percent);

    double getMagnitude();

    double getShoulderZeroingAngle();
    double getElbowZeroingAngle();

    double getCurrentMagnitude();

    double getShoulderPosition();
    double getElbowPosition();

    double getShoulderGravityPower();
    double getElbowGravityPower();

    void setShoulderTuning(double KP, double KI, double KD);
    void setElbowTuning(double KP, double KI, double KD);

    void setShoulderDesired(double degrees);
    void setElbowDesired(double degrees);

    void setShoulderEnabled(bool enabled);
    void setElbowEnabled(bool enabled);
    void setFrequency(double Frequency);

    double stepShoulder();
    double stepElbow();

    void setArmDegreeForGravity(double degrees);
};

#endif