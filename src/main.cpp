/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Connor                                           */
/*    Created:      Mon Jul 27 2020                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// WBL                  motor         20              
// EBL                  motor         19              
// SBL                  motor         18              
// PEBL                 pot           E               
// PSBL                 pot           F               
// WBR                  motor         10              
// EBR                  motor         9               
// SBR                  motor         8               
// PEBR                 pot           G               
// PSBR                 pot           H               
// WFL                  motor         11              
// EFL                  motor         12              
// SFL                  motor         13              
// PEFL                 pot           D               
// PSFL                 pot           C               
// WFR                  motor         1               
// EFR                  motor         2               
// SFR                  motor         3               
// PEFR                 pot           B               
// PSFR                 pot           A               
// ---- END VEXCODE CONFIGURED DEVICES ----

//VEX Header Guard
#ifndef VEX_H
#define VEX_H
#include "vex.h"
#endif

#include <cmath>
#include <algorithm>
#include "objectLib/motorObject.h"
#include "objectLib/potObject.h"
#include "objectLib/sensorSystem.h"
#include "objectLib/system-config.h"
#include "dogObject/armCalculator.h"
#include "dogObject/calculator-config.h"
#include "dogObject/armVector.h"
#include "dogObject/vector-config.h"
#include "connormath.h"

using namespace std;

//BackRight.getCurrentMagnitude(); //Gets the current magnitude calculated
//void setArmDegreeForGravity(double degrees); //Is to be applied based upon the angle the arm is horizontally if a horizontal axis is made
//An arm calculator requires a an elbow system and a shoulder system.
//A system requires a pot object and a motor object.
//A pot object requires a pot
//A motor object requires a motor
//A PID object requires a system (Note: A calculator automatically creates and assigns PID objects upon its initialization)

int stepper(){
  while(1==1){
    BackRight.step();
    BackLeft.step();
    FrontRight.step();
    FrontLeft.step();
    vex::task::sleep(10);
  }
  return 1;
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  offset();
  vex::task Stepp(stepper);

  BackRight.setAngle(0);
  BackLeft.setAngle(0);
  FrontRight.setAngle(0);
  FrontLeft.setAngle(0);

  vex::task::sleep(5000);
  BackRight.setEnabled(true);
  BackLeft.setEnabled(true);
  FrontRight.setEnabled(true);
  FrontLeft.setEnabled(true);

  bool buttonPressed = false;
  double height = (BackRight.getCurrentMagnitude() + BackLeft.getCurrentMagnitude() + FrontRight.getCurrentMagnitude() + FrontLeft.getCurrentMagnitude())/4;
  double desiredHeight = height;
  BackRight.setMagnitude(height);
  BackLeft.setMagnitude(height);
  FrontRight.setMagnitude(height);
  FrontLeft.setMagnitude(height);

  double heightChangeSpeed = 0.02;

  while(true){

    double leMag = BackRightCalculator.getCurrentMagnitude();
    double ElbowAngle = BackRightCalculator.getElbowPosition();
    double wantedElbowAngle = BackRightCalculator.getElbowZeroingAngle();
    double shoulderAngle = BackRightCalculator.getShoulderPosition();
    double wantedShoulderAngle = BackRightCalculator.getShoulderZeroingAngle();

    if (desiredHeight > height) height += heightChangeSpeed;
    else if (desiredHeight < height) height -= heightChangeSpeed;
  

    BackRight.setMagnitude(height);
    BackLeft.setMagnitude(height);
    FrontRight.setMagnitude(height);
    FrontLeft.setMagnitude(height);

    if(Controller1.installed()){
      if(Controller1.ButtonA.pressing() && buttonPressed == false){
        buttonPressed = true;
        desiredHeight+=0.5;
        if (desiredHeight > 12.5) desiredHeight = 12.5;
      }
      else if(Controller1.ButtonB.pressing() && buttonPressed == false){
        buttonPressed = true;
        desiredHeight-=0.5;
        if (desiredHeight < 6.5) desiredHeight = 6.5;
      }
      else if(!Controller1.ButtonA.pressing() && !Controller1.ButtonB.pressing()) buttonPressed = false;

      BackRightWheelMotor.setSpeed(Controller1.Axis3.value() - Controller1.Axis1.value());
      FrontRightWheelMotor.setSpeed(Controller1.Axis3.value() - Controller1.Axis1.value());
      BackLeftWheelMotor.setSpeed(Controller1.Axis3.value() + Controller1.Axis1.value());
      FrontLeftWheelMotor.setSpeed(Controller1.Axis3.value() + Controller1.Axis1.value());
    }
    else{
      BackRightWheelMotor.setSpeed(0);
      FrontRightWheelMotor.setSpeed(0);
      BackLeftWheelMotor.setSpeed(0);
      FrontLeftWheelMotor.setSpeed(0);
    }

    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(ElbowAngle);
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print(wantedElbowAngle);
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print(shoulderAngle);
    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print(wantedShoulderAngle);
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print(leMag);
    vex::task::sleep(10);
  }
  
}
