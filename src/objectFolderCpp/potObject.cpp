#ifndef VEX_H
#define VEX_H
#include "vex.h"
#endif

#include "objectLib/potObject.h"

using namespace vex; 
using namespace std; 

//Sets potentiometer and reversed
cPot::cPot(pot& sPot, bool reversed, double multiplier) : vPot(sPot), isReversed(reversed), accuracyCorrection(multiplier) {}

//Gets position
double cPot::getPos(){
  if (isReversed) return 250 - vPot.angle(rotationUnits::deg) * accuracyCorrection;
  return vPot.angle(rotationUnits::deg) * accuracyCorrection;
}
