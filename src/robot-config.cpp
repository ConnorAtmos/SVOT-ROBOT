#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor WBL = motor(PORT20, ratio18_1, false);
motor EBL = motor(PORT19, ratio36_1, true);
motor SBL = motor(PORT18, ratio36_1, false);
pot PEBL = pot(Brain.ThreeWirePort.E);
pot PSBL = pot(Brain.ThreeWirePort.F);
motor WBR = motor(PORT10, ratio18_1, true);
motor EBR = motor(PORT9, ratio36_1, false);
motor SBR = motor(PORT8, ratio36_1, true);
pot PEBR = pot(Brain.ThreeWirePort.G);
pot PSBR = pot(Brain.ThreeWirePort.H);
motor WFL = motor(PORT11, ratio18_1, false);
motor EFL = motor(PORT12, ratio36_1, false);
motor SFL = motor(PORT13, ratio36_1, true);
pot PEFL = pot(Brain.ThreeWirePort.D);
pot PSFL = pot(Brain.ThreeWirePort.C);
motor WFR = motor(PORT1, ratio18_1, true);
motor EFR = motor(PORT2, ratio36_1, true);
motor SFR = motor(PORT3, ratio36_1, false);
pot PEFR = pot(Brain.ThreeWirePort.B);
pot PSFR = pot(Brain.ThreeWirePort.A);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}