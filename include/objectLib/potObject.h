//VEX Header Guard
#ifndef VEX_H
#define VEX_H
#include "vex.h"
#endif

//motorObj Library Header Guard
#ifndef potObj_H
#define potObj_H

class cPot
{
  private:
    pot& vPot;
    bool isReversed;
    double accuracyCorrection = 1;
  public:
    cPot(pot& sPot, bool reversed, double multiplier);

    double getPos();
};

#endif