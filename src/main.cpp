// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontLeftDrive       motor         3               
// frontRightDrive      motor         15              
// backLeftDrive        motor         2               
// backRightDrive       motor         16              
// Pneumatics           digital_out   A               
// clampGear            motor         1               
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
  // code for picking up mogo
}

/////////////////////////////////////////////////////////////////////////////////////////
//                                                                                     //
//                               Driver-Based Control                                  //
//                                                                                     //
/////////////////////////////////////////////////////////////////////////////////////////

void drivercontrol(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.print("Hello World!\n");

  int mogoIntakePercent = 25;  
  bool clampHold = false; // two-choice toggle, so we use bool
  bool buttonPressed = false; // IGNORE, logic variable

  while (true) {

    // spin to win
    // Left Drive Control (Left Joystick)
    frontLeftDrive.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
    backLeftDrive.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);

    // Left Drive Control (Right Joystick)
    frontRightDrive.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
    backRightDrive.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);

    if (Controller1.ButtonR1.pressing()) {
      // Ring Intake Control (ButtonUp and ButtonDown)
      backRightDrive.spin(vex::directionType::fwd, mogoIntakePercent, vex::velocityUnits::pct);
    }
    else if (Controller1.ButtonR2.pressing()) {
      // Ring Intake Control (ButtonUp and ButtonDown)
      backRightDrive.spin(vex::directionType::rev, mogoIntakePercent, vex::velocityUnits::pct);
    }
    else {
      backRightDrive.stop(vex::brakeType::brake);
    }
    bool buttonX = Controller1.ButtonX.pressing();

    ////////////////////////////////////////////////////////////////////
    // Toggle Logic
    if (buttonX && !buttonPressed) {
      buttonPressed = true; 
      clampHold = !clampHold;
    }
    else if (!buttonX) {
      buttonPressed = false;
    }

    ////////////////////////////////////////////////////////////////////
    // Code For toggle Enabled or Disabled
    if(clampHold) {
      Pneumatics.set(true);
    }
    else {
      Pneumatics.set(false);
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