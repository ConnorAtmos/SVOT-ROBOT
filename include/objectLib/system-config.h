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

extern cMotor BackLeftElbowMotor;
extern cMotor BackLeftShoulderMotor;
extern cMotor BackRightElbowMotor;
extern cMotor BackRightShoulderMotor;
extern cMotor FrontRightShoulderMotor;
extern cMotor FrontRightElbowMotor;
extern cMotor FrontLeftShoulderMotor;
extern cMotor FrontLeftElbowMotor;
extern cMotor FrontLeftWheelMotor;
extern cMotor FrontRightWheelMotor;
extern cMotor BackLeftWheelMotor;
extern cMotor BackRightWheelMotor;

extern cPot BackLeftElbowPot;
extern cPot BackLeftShoulderPot;
extern cPot BackRightElbowPot;
extern cPot BackRightShoulderPot;
extern cPot FrontLeftElbowPot;
extern cPot FrontLeftShoulderPot;
extern cPot FrontRightElbowPot;
extern cPot FrontRightShoulderPot;

extern cSystem BackLeftElbow;
extern cSystem BackLeftShoulder;
extern cSystem BackRightElbow;
extern cSystem BackRightShoulder;
extern cSystem FrontLeftElbow;
extern cSystem FrontLeftShoulder;
extern cSystem FrontRightElbow;
extern cSystem FrontRightShoulder;

void offset();