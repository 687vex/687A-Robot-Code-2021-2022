#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor frontLeft = motor(PORT1, ratio18_1, false);
motor backLeft = motor(PORT11, ratio18_1, false);
motor frontRight = motor(PORT10, ratio18_1, true);
motor backRight = motor(PORT20, ratio18_1, true);
inertial Inertial = inertial(PORT15);
motor ringIntake = motor(PORT5, ratio18_1, false);
motor frontLeftMogoIntake = motor(PORT6, ratio36_1, true);
motor frontRightMogoIntake = motor(PORT7, ratio36_1, false);

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