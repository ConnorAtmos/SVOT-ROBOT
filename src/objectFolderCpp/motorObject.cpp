#ifndef VEX_H
#define VEX_H
#include "vex.h"
#endif

#include "objectLib/motorObject.h"

using namespace vex; 
using namespace std; 

//Sets motor (and ratio)
cMotor::cMotor(motor& sMotor, int Driven, int Driver) : vMotor(sMotor) {
  setRatio(Driver, Driven);
}

//Sets ratio
void cMotor::setRatio(int Driven, int Driver){
  driver = abs(Driver);
  driven = abs(Driven);
}

//Sets position
void cMotor::setPos(double degrees){
  vMotor.setPosition(degrees / (driven / driver), rotationUnits::deg);
}

//Gets position
double cMotor::getPos(){
  return vMotor.position(rotationUnits::deg) * (driven / driver);
}

//Sets motor speed
void cMotor::setSpeed(double Amt){
  vMotor.spin(directionType::fwd, Amt * 0.12,voltageUnits::volt);
}