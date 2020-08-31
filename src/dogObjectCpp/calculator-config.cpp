#ifndef SYSOBJECT_H
#define SYSOBJECT_H
#include "objectLib/sensorSystem.h"
#endif

#ifndef ARMCALCULATOR_H
#define ARMCALCULATOR_H
#include "dogObject/armCalculator.h"
#endif

#ifndef SYSCONFIG_H
#define SYSCONFIG_H
#include "objectLib/system-config.h"
#endif

double shoulderkP = 40;
double shoulderkI = 0.05;
double shoulderkD = 15;
double ShoulderWeight = 15;

double elbowkP = 40;
double elbowkI = 0.05;
double elbowkD = 15;
double ElbowWeight = 3;

double armLength = 6.5;

cArm FrontLeftCalculator(FrontLeftShoulder, ShoulderWeight, shoulderkP, shoulderkI, shoulderkD, FrontLeftElbow, ElbowWeight, elbowkP, elbowkI, elbowkD, armLength);
cArm FrontRightCalculator(FrontRightShoulder, ShoulderWeight, shoulderkP, shoulderkI, shoulderkD, FrontRightElbow, ElbowWeight, elbowkP, elbowkI, elbowkD, armLength);
cArm BackLeftCalculator(BackLeftShoulder, ShoulderWeight, shoulderkP, shoulderkI, shoulderkD, BackLeftElbow, ElbowWeight, elbowkP, elbowkI, elbowkD, armLength);
cArm BackRightCalculator(BackRightShoulder, ShoulderWeight, shoulderkP, shoulderkI, shoulderkD, BackRightElbow, ElbowWeight, elbowkP, elbowkI, elbowkD, armLength);