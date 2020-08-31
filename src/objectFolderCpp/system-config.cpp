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

#ifndef SYSCONFIG_H
#define SYSCONFIG_H
#include "objectLib/system-config.h"
#endif

//This is used to initialize motor objects for easier usage
int Driven = 3;//Driven gear
int Driver = 1;//Driver gear (or gear on the motor's side)
cMotor BackLeftElbowMotor(EBL, Driven, Driver);//Motor, Driven, Driver
cMotor BackLeftShoulderMotor(SBL, Driven, Driver);
cMotor BackRightElbowMotor(EBR, Driven, Driver);
cMotor BackRightShoulderMotor(SBR, Driven, Driver);
cMotor FrontRightShoulderMotor(SFR, Driven, Driver);
cMotor FrontRightElbowMotor(EFR, Driven, Driver);
cMotor FrontLeftShoulderMotor(SFL, Driven, Driver);
cMotor FrontLeftElbowMotor(EFL, Driven, Driver);
cMotor FrontLeftWheelMotor(WFL, Driven, Driver);
cMotor FrontRightWheelMotor(WFR, Driven, Driver);
cMotor BackLeftWheelMotor(WBL, Driven, Driver);
cMotor BackRightWheelMotor(WBR, Driven, Driver);

//This is used to initialize potentiometer objects for easier usage
cPot BackLeftElbowPot(PEBL, true, 0.857); //Pot, Reversed?
cPot BackLeftShoulderPot(PSBL, true, 1.02);
cPot BackRightElbowPot(PEBR, true, 0.857);
cPot BackRightShoulderPot(PSBR, true, 1.048);
cPot FrontLeftElbowPot(PEFL, true, 0.8);
cPot FrontLeftShoulderPot(PSFL, true, 0.857);
cPot FrontRightElbowPot(PEFR, true, 0.8);
cPot FrontRightShoulderPot(PSFR, true, 1.061);

//This is used to initialize systems which includes the motor objects and sensor objects for a more refined sensor system
double referenceFrequency = 0.05;
cSystem BackLeftElbow(BackLeftElbowMotor, BackLeftElbowPot, referenceFrequency);//Motor, Pot, Frequency(0.1 = every 10 time called, use pot as reference)
cSystem BackLeftShoulder(BackLeftShoulderMotor, BackLeftShoulderPot, referenceFrequency);
cSystem BackRightElbow(BackRightElbowMotor, BackRightElbowPot, referenceFrequency);
cSystem BackRightShoulder(BackRightShoulderMotor, BackRightShoulderPot, referenceFrequency);
cSystem FrontLeftElbow(FrontLeftElbowMotor, FrontLeftElbowPot, referenceFrequency);
cSystem FrontLeftShoulder(FrontLeftShoulderMotor, FrontLeftShoulderPot, referenceFrequency);
cSystem FrontRightElbow(FrontRightElbowMotor, FrontRightElbowPot, referenceFrequency);
cSystem FrontRightShoulder(FrontRightShoulderMotor, FrontRightShoulderPot, referenceFrequency);

void offset(){
  BackLeftElbow.setZero(56);
  BackLeftShoulder.setZero(130);
  BackRightElbow.setZero(59);
  BackRightShoulder.setZero(128);
  FrontRightElbow.setZero(70);
  FrontRightShoulder.setZero(126.3);
  FrontLeftElbow.setZero(63.5);
  FrontLeftShoulder.setZero(147.5);
}