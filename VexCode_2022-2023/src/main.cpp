/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontR_DT            motor         18              
// FrontL_DT            motor         2               
// BackR_DT             motor         21              
// BackL_DT             motor         12              
// Inertial             inertial      17              
// Intake               motor         3               
// Indexer              motor         13              
// Flywheel_1           motor         5               
// DigitalOutD          digital_out   D               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Moving.h"
#include "Turning.h"
#include "Expand.h"
#include "ShootDisc.h"
#include "robot-config.h"
#include "Teamwork.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  //The flywheel needs to run at the required speed to shoot
  Inertial.calibrate(0);
  Flywheel_1.setVelocity(3000, rpm);
  
  //Set all drive train motors to 15 percent
  SetDriveVelocity(15);

  //Move straight to be parallel to the first roller
  MoveStraight(475, forward);

  //Turn 90 degrees right to face the first roller
  TurnToTarget(83);

  SetDriveVelocity(15);

  //Spin the rollers and move forward to spin the first roller to red
  Intake.spinFor(forward, 250, degrees, false);
  MoveStraight(130, forward);

  //Wait 0.75 seconds to cool down the motors
  wait(0.75, seconds);

  //Move reverse to be parallel to the second roller
  MoveStraight(510, reverse);

  //Turn 90 degrees left to face the second roller
  TurnToTarget(10);

  SetDriveVelocity(15);

  MoveStraight(420, forward);
  Intake.spinFor(reverse, 150, degrees, false);
  MoveStraight(50, forward);

  MoveStraight(200, reverse);
  TurnToTarget(35);
  DigitalOutD.set(true);

  //TeamworkAuton(true);

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
