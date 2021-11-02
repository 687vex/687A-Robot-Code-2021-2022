// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontLeft            motor         1               
// backLeft             motor         11              
// frontRight           motor         10              
// backRight            motor         20              
// Inertial             inertial      15              
// ringIntake           motor         5               
// frontMogoIntake      motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX 687A                                                  */
/*    Created:      Thu Jul 29 2021                                           */
/*    Description:  Official robot code of VEX Robotics Team 687A             */
/*                  for the 2021-2022 Season                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/** Drive used: Standard Drivetrain/Skid-Steer-Drive
 *   Skid-Steer-Drive configuration:
 *     FL              FR 
 *    XXXX            XXXX
 *    XXXX            XXXX
 *    XXXX            XXXX
 *    XXXXXXXXXXXXXXXXXXXX
 *    XXXXXXXXXXXXXXXXXXXX
 *    XXXX            XXXX
 *    XXXX            XXXX
 *     BL              BR 
**/

#include "vex.h"
using namespace vex;

// Competition
competition Competition;

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                               Pre-Autonomous                                        //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton(void) {
}

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                               Autonomous                                            //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

void autonomous(void) {
  frontLeft.spinFor(vex::directionType::fwd, 2076.79, vex::rotationunits::deg, false);
  backLeft.spinFor(vex::directionType::fwd, 2076.79, vex::rotationunits::deg, false);
  frontRight.spinFor(vex::directionType::fwd, 2076.79, vex::rotationunits::deg, false);
  backRight.spinFor(vex::directionType::fwd, 2076.79, vex::rotationunits::deg, true);

  // code for picking up mogo
  frontLeftMogoIntake.spinFor(vex::directionType::fwd, 135, vex::rotationunits::deg, false);
  frontRightMogoIntake.spinFor(vex::directionType::fwd, 135, vex::rotationunits::deg, true);
  
  frontLeft.spinFor(vex::directionType::rev, 2076.79, vex::rotationunits::deg, false);
  backLeft.spinFor(vex::directionType::rev, 2076.79, vex::rotationunits::deg, false);
  frontRight.spinFor(vex::directionType::rev, 2076.79, vex::rotationunits::deg, false);
  backRight.spinFor(vex::directionType::rev, 2076.79, vex::rotationunits::deg, true);
}

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                               Driver-Based Control                                  //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

void drivercontrol(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.print("Hello World!\n");

  int ringIntakePercent = 100;

  while (true) {
    // spin to win 
    // Left Drive Control (Left Joystick)
    frontLeft.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    backLeft.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    
    // Left Drive Control (Right Joystick)
    frontRight.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
    backRight.spin(vex::directionType::rev, Controller1.Axis2.value(), vex::velocityUnits::pct);
    
    if (Controller1.ButtonA.pressing()) {
      // Ring Intake Control (ButtonUp and ButtonDown)
      ringIntake.spin(vex::directionType::fwd, ringIntakePercent, vex::velocityUnits::pct);
    }
    else if (Controller1.ButtonB.pressing()) { 
      // Ring Intake Control (ButtonUp and ButtonDown)
      ringIntake.spin(vex::directionType::rev, ringIntakePercent, vex::velocityUnits::pct);
    }

    if (Controller1.ButtonR1.pressing()) {
      // Ring Intake Control (ButtonUp and ButtonDown)
      frontMogoIntake.spin(vex::directionType::fwd, ringIntakePercent, vex::velocityUnits::pct);
    }
    else if (Controller1.ButtonR2.pressing()) { 
      // Ring Intake Control (ButtonUp and ButtonDown)
      frontMogoIntake.spin(vex::directionType::rev, ringIntakePercent, vex::velocityUnits::pct);
    }
    vex::task::sleep(20); // Sleep the task for a short amount of time (20 ms) to prevent wasted resources
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                               Main                                                  //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

// Set up  competition and callbacks
int main() {
  Brain.Screen.print("Hello World!\n");
  
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // Callbacks for autonomous and driver control
  // Run pre-autonomous function.
  pre_auton();
  Competition.autonomous(autonomous);
  Competition.drivercontrol(drivercontrol);
}
