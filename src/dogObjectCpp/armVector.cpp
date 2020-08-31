#ifndef ARMCALCULATOR_H
#define ARMCALCULATOR_H
#include "dogObject/armCalculator.h"
#endif

#ifndef ARMVECTOR_H
#define ARMVECTOR_H
#include "dogObject/armVector.h"
#endif

//Trig function

cVector::cVector(cArm& vArm) : rArm(vArm){}

void cVector::setHorizontalGravityDegree(double degrees){
  rArm.setArmDegreeForGravity(degrees);
}

void cVector::setMagnitude(double length){
  rArm.setMagnitude(length);
}

void cVector::setAngle(double degrees){
  desiredAngle = degrees;
}

void cVector::step(){
  double wantedElbowAngle = rArm.getElbowZeroingAngle();
  double wantedShoulderAngle = rArm.getShoulderZeroingAngle();
  //PID functions
  rArm.setElbowDesired(wantedElbowAngle);
  rArm.setShoulderDesired(wantedShoulderAngle + desiredAngle);
  double ElbowPIDPowerResultant = rArm.stepElbow();
  double ShoulderPIDPowerResultant = rArm.stepShoulder();
  //Gravity Compensation functions
  double ShoulderWeightNegationResultant = rArm.getShoulderGravityPower();
  double ElbowWeightNegationResultant = rArm.getElbowGravityPower();
  //Arm Motor Power
  rArm.setElbowPower(ElbowPIDPowerResultant + ElbowWeightNegationResultant);
  rArm.setShoulderPower(ShoulderPIDPowerResultant + ShoulderWeightNegationResultant);
}

void cVector::setEnabled(bool enabled){
  rArm.setShoulderEnabled(enabled);
  rArm.setElbowEnabled(enabled);
}

void cVector::setFrequency(double Frequency){
  rArm.setFrequency(Frequency);
}

double cVector::getCurrentMagnitude(){
  return rArm.getCurrentMagnitude();
}

double cVector::getCurrentAngle(){
  return rArm.getShoulderPosition() - rArm.getShoulderZeroingAngle();
}