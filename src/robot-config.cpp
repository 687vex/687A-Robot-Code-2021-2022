#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor frontLeftDrive = motor(PORT12, ratio18_1, false);
motor backLeftDrive = motor(PORT10, ratio18_1, false);
motor frontRightDrive = motor(PORT11, ratio18_1, true);
motor backRightDrive = motor(PORT1, ratio18_1, true);
inertial Inertial = inertial(PORT15);
motor frontLeftMogoIntake = motor(PORT20, ratio36_1, false);
motor frontRightMogoIntake = motor(PORT19, ratio36_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void)
{
  // nothing to initialize
}