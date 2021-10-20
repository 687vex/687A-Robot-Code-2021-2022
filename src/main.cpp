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
// frontLeftMogoIntake  motor         6               
// frontRightMogoIntake motor         7 
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
  
}

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                               Driver-Based Control                                  //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

void drivercontrol(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.print("Hello World!\n");

  int ringIntakePercent = 50;
  int mogoIntakePercent = 100;

  while (true) {
    // spin to win 
    // Left Drive Control (Left Joystick)
    frontLeft.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    backLeft.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    
    // Left Drive Control (Right Joystick)
    frontRight.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
    backRight.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
    
    if (Controller1.ButtonA.pressing()) {
      // Ring Intake Control (ButtonUp and ButtonDown)
      ringIntake.spin(vex::directionType::fwd, ringIntakePercent, vex::velocityUnits::pct);
    }
    else if (Controller1.ButtonB.pressing()) { 
      // Ring Intake Control (ButtonUp and ButtonDown)
      ringIntake.spin(vex::directionType::rev, ringIntakePercent, vex::velocityUnits::pct);
    }
    else {
      ringIntake.stop(vex::brakeType::hold);
    }

    if (Controller1.ButtonR1.pressing()) {
      // Ring Intake Control (ButtonUp and ButtonDown)
      frontLeftMogoIntake.spin(vex::directionType::fwd, mogoIntakePercent, vex::velocityUnits::pct);
      frontRightMogoIntake.spin(vex::directionType::fwd, mogoIntakePercent, vex::velocityUnits::pct);
    }
    else if (Controller1.ButtonR2.pressing()) { 
      // Ring Intake Control (ButtonUp and ButtonDown)
      frontLeftMogoIntake.spin(vex::directionType::rev, mogoIntakePercent, vex::velocityUnits::pct);
      frontRightMogoIntake.spin(vex::directionType::rev, mogoIntakePercent, vex::velocityUnits::pct);
    }
    else {
      frontLeftMogoIntake.stop(vex::brakeType::hold);
      frontRightMogoIntake.stop(vex::brakeType::hold);
    }
    vex::task::sleep(10); // Sleep the task for a short amount of time (20 ms) to prevent wasted resources
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
