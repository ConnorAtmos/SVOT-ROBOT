using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor WBL;
extern motor EBL;
extern motor SBL;
extern pot PEBL;
extern pot PSBL;
extern motor WBR;
extern motor EBR;
extern motor SBR;
extern pot PEBR;
extern pot PSBR;
extern motor WFL;
extern motor EFL;
extern motor SFL;
extern pot PEFL;
extern pot PSFL;
extern motor WFR;
extern motor EFR;
extern motor SFR;
extern pot PEFR;
extern pot PSFR;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );