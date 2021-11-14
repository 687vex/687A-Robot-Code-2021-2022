/**
 * definitions.cpp
 *
 * This file contains various declarations and definitions for
 * motors, sensors, controls, constants, and settings, so that
 * things that might need to be changed are all in one place.
 */
#include "main.h" // gives access to definition.hpp and other dependencies

namespace def
{
/* ----------------------------------------------------------- */
/*                           Devices                           */
/* ----------------------------------------------------------- */

/* -------------------------- Motors ------------------------- */
/* -------------------- Drivetrain Motors -------------------- */
okapi::Motor::Motor mtr_dt_front_left(20);
okapi::Motor::Motor mtr_dt_front_right(-11);
okapi::Motor::Motor mtr_dt_back_left(10);
okapi::Motor::Motor mtr_dt_back_right(-1);

/* ----------------- Front Mogo Intake Motors ---------------- */
okapi::Motor::Motor mtr_mg_it_front_left(12);
okapi::Motor::Motor mtr_mg_it_front_right(-19);

/* ------------------------- Sensors ------------------------- */
pros::Imu imu_center(15);

/* ----------------------------------------------------------- */
/*                           Controls                          */
/* ----------------------------------------------------------- */
Controller controller = Controller();

/* ------------------------ Drivetrain ----------------------- */
/* -------------- Drivetrain Toggle Balacing PID ------------- */
ControllerButton btn_dt_tglBalancingPID = ControllerDigital::B;

/* ----------------------- Mogo Control ---------------------- */
ControllerButton btn_mg_it_front_fwd = ControllerDigital::R1;
ControllerButton btn_mg_it_front_bkd = ControllerDigital::R2;

/* ----------------------------------------------------------- */
/*                          Constructs                         */
/* ----------------------------------------------------------- */
// @TODO: Add CustomOdometry.cpp and CustomOdometry.hpp
CustomOdometry customOdom = CustomOdometry(); // object that calculates robot position
// @TODO: Add Drivetrain.cpp and Drivetrain.hpp
Drivetrain drivetrain = Drivetrain(); // used by DrivetrainStateMachine for drivetrain control

} // end namespace def
