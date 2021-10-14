/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX 687A                                                  */
/*    Created:      Thu Jul 29 2021                                           */
/*    Description:  Official robot code of VEX Robotics Team 687A             */
/*                  for the 2021-2022 Season                                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// frontLeft            motor         1               
// backLeft             motor         11              
// frontRight           motor         10              
// backRight            motor         20              
// Inertial             inertial      15             
// ---- END VEXCODE CONFIGURED DEVICES ----

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
*/

#include "vex.h"
using namespace vex;

// Competition
competition Competition;

/////////////////////////////////////////////////////////////////////////////////////////
//
//                               Pre-Autonomous
//
/////////////////////////////////////////////////////////////////////////////////////////
void pre_auton(void) {
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                               Autonomous
//
/////////////////////////////////////////////////////////////////////////////////////////
void autonomous(void) {
  while (true) // While true is true, repeat the commands in the next {}
  {
    while (!Brain.Screen.pressing()) {} // while the screen is not being pressed, do nothing
    Brain.Screen.printAt(Brain.Screen.xPosition(), Brain.Screen.yPosition(), "Ouch"); // print 'Ouch' where the screen was pressed
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                               Driver-Based Control
//
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

    vex::task::sleep(20); // Sleep the task for a short amount of time to prevent wasted resources
  }
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                               Main
//
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
