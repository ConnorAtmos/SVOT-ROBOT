#ifndef SYSCONFIG_H
#define SYSCONFIG_H
#include "dogObject/calculator-config.h"
#endif

#ifndef ARMCALCULATOR_H
#define ARMCALCULATOR_H
#include "dogObject/armCalculator.h"
#endif

#ifndef ARMVECTOR_H
#define ARMVECTOR_H
#include "dogObject/armVector.h"
#endif

cVector FrontLeft(FrontLeftCalculator);
cVector FrontRight(FrontRightCalculator);
cVector BackLeft(BackLeftCalculator);
cVector BackRight(BackRightCalculator);