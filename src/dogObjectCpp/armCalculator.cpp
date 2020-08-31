
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

#ifndef ARMCALCULATOR_H
#define ARMCALCULATOR_H
#include "dogObject/armCalculator.h"
#endif

#ifndef PIDOBJECT_H
#define PIDOBJECT_H
#include "objectLib/pidObject.h"
#endif

#include "connormath.h"

using namespace vex; 
using namespace std; 

cArm::cArm(cSystem& Shoulder, double ShoulderWeight, double sKP, double sKI, double sKD, cSystem& Elbow, double ElbowWeight, double eKP, double eKI, double eKD, double ArmLength) : shoulder(Shoulder),  elbow(Elbow), shoulderPID(Shoulder, sKP, sKI, sKD, false), elbowPID(Elbow, eKP, eKI, eKD, false), armLength(ArmLength)
, elbowWeight(ElbowWeight), shoulderWeight(ShoulderWeight){
  maxMagnitude = ArmLength*2;
  inputtedMagnitude = maxMagnitude/2;
}

//////////////////////////////////////////////////////////////////////////////
//Motor Functions
//////////////////////////////////////////////////////////////////////////////
double cArm::getShoulderPosition(){
  return shoulder.getPos();
}
double cArm::getElbowPosition(){
  return elbow.getPos();
}

void cArm::setShoulderPower(double percent){
  if (shoulderPID.isEnabled()) shoulder.setSpeed(percent);
  else shoulder.setSpeed(0);
}

void cArm::setElbowPower(double percent){
  if (elbowPID.isEnabled()) elbow.setSpeed(percent);
  else elbow.setSpeed(0);
}

void cArm::setFrequency(double Frequency){
  elbow.setFrequency(Frequency);
  shoulder.setFrequency(Frequency);
}

//////////////////////////////////////////////////////////////////////////////
//Inverse Trig Calculator and Sensing
//////////////////////////////////////////////////////////////////////////////
void cArm::setMagnitude(double mag){
  inputtedMagnitude = mag;
}

double cArm::getMagnitude(){
  return inputtedMagnitude;
}

double cArm::getCurrentMagnitude(){

  double elbowInnerAngle = (180 - elbow.getPos())/2;

  //calculated from sin(A)/a = sin(B)/b
  return sin(toRad(elbowInnerAngle)) * armLength * 2;
}

double cArm::getShoulderZeroingAngle(){
  //a^2 + b^2 = c^2
  double legWidth = sqrt(pow(armLength, 2) - pow(inputtedMagnitude/2, 2));

  //calculated from sin(A)/a = sin(B)/b
  return toDeg(asin(legWidth / armLength));
}

double cArm::getElbowZeroingAngle(){
  return 180 - (toDeg(asin(inputtedMagnitude / (armLength * 2))) * 2);
}

//////////////////////////////////////////////////////////////////////////////
//Gravity Compensation Calculator
//////////////////////////////////////////////////////////////////////////////

void cArm::setArmDegreeForGravity(double degrees){
  weightMultiplier = ((double)abs((int)(cos(degrees)*100000)))/100000.0;
}

double cArm::getShoulderGravityPower(){
  return -(sin(toRad(getShoulderPosition() - getElbowPosition()/2)) * shoulderWeight * weightMultiplier * (getCurrentMagnitude()/(armLength * 2)));
}

double cArm::getElbowGravityPower(){
  return -(sin(toRad(getElbowPosition() - getShoulderPosition())) * elbowWeight * weightMultiplier);
}

//////////////////////////////////////////////////////////////////////////////
//PID Calculator
//////////////////////////////////////////////////////////////////////////////
void cArm::setShoulderTuning(double KP, double KI, double KD){
  shoulderPID.setTuning(KP, KI, KD);
}

void cArm::setElbowTuning(double KP, double KI, double KD){
  elbowPID.setTuning(KP, KI, KD);
}

void cArm::setShoulderDesired(double degrees){
  shoulderPID.setDesired(degrees);
}

void cArm::setElbowDesired(double degrees){
  elbowPID.setDesired(degrees);
}

void cArm::setShoulderEnabled(bool enabled){
  shoulderPID.setEnabled(enabled);
}

void cArm::setElbowEnabled(bool enabled){
  elbowPID.setEnabled(enabled);
}

double cArm::stepShoulder(){
  return shoulderPID.step();
}

double cArm::stepElbow(){
  return elbowPID.step();
}