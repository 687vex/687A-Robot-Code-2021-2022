/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Miguel                                           */
/*    Created:      Thu Jul 29 2021                                           */
/*    Description:  V5 project                                                */
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


void displayStats(void) {
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.print("| port | part_type | part_name | part_value |");
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                               Driver-Based Control
//
/////////////////////////////////////////////////////////////////////////////////////////
void drivercontrol(void) {
  Brain.Screen.print("Hello World!\n");

  while (true) {
    // spin to win 
    frontLeft.spin(directionType::fwd,Controller1.Axis3.value(), velocityUnits::pct);
    backLeft.spin(directionType::fwd,Controller1.Axis3.value(), velocityUnits::pct);

    frontRight.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);
    backRight.spin(directionType::rev,Controller1.Axis2.value(), velocityUnits::pct);

    displayStats();
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
