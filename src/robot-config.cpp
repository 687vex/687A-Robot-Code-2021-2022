#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor frontLeftDrive = motor(PORT1, ratio18_1, false);
motor frontRightDrive = motor(PORT5, ratio18_1, true);
motor backLeftDrive = motor(PORT11, ratio18_1, false);
motor backRightDrive = motor(PORT15, ratio18_1, true);
digital_out Pneumatics = digital_out(Brain.ThreeWirePort.A);
motor clampGear = motor(PORT4, ratio18_1, false);

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