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

#include "objectLib/sensorSystem.h"

#include "connormath.h"
#include <cmath>

//Sets motor (and ratio)
cSystem::cSystem(cMotor& fMotor, cPot& fPot, double Frequency) : rMotor(fMotor), rPot(fPot), frequency(Frequency){
  rMotor.setPos(rPot.getPos());
}

//Sets frequency of the system
void cSystem::setFrequency(double Frequency){
  frequency = Frequency;
}

//Sets speed of the system
void cSystem::setSpeed(double percent){
  rMotor.setSpeed(percent);
}

//Gets position of the system
void cSystem::setZero(double degrees){
  zeroOffset = degrees;
}

//Gets position of the system
double cSystem::getPos(){
  currentFreq--;
  if (currentFreq < 0) {
    currentFreq = 1/frequency;

    double difference = rPot.getPos() - rMotor.getPos();
    if(std::abs(difference) > 3) differenceCount+=5;
    else differenceCount--;

    if(std::abs(differenceCount) > 10){
      differenceCount = 0;
      rMotor.setPos(rPot.getPos());
    }
  }
  return rMotor.getPos() - zeroOffset;
}

