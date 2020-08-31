
#include <cmath>
#include "connormath.h"
#include <algorithm>

using namespace std;

//Degrees -> Radians
double toRad(double degrees){
  return  ( degrees * M_PI ) / 180 ;
}

//Radians -> Degrees
double toDeg(double radians){
  return ( radians * 180 ) / M_PI ;
}

//Clamp
double clamp(double n, double lower, double upper) {
  return max(lower, min(n, upper));
}