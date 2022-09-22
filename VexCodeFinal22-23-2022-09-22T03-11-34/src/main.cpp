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
// FrontR_DT            motor         8               
// FrontL_DT            motor         2               
// BackR_DT             motor         19              
// BackL_DT             motor         11              
// Controller1          controller                    
// Inertial             inertial      21              
// Distance             distance      3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
#include "MoveStraight.h"
#include "Turning.h"

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

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
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

  MoveStraight(500, forward);
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
  FrontL_DT.setVelocity(75, percent);
  FrontR_DT.setVelocity(75, percent);
  BackL_DT.setVelocity(75, percent);
  BackR_DT.setVelocity(75, percent);

  //tank drive

  while(true) {
    FrontL_DT.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct); //(Axis3+Axis4)/2
    BackL_DT.spin(directionType::fwd, Controller1.Axis3.value(), velocityUnits::pct); //(Axis3+Axis4)/2
    FrontR_DT.spin(directionType::fwd, Controller1.Axis2.value(), velocityUnits::pct); //(Axis3-Axis4)/2
    BackR_DT.spin(directionType::fwd, Controller1.Axis2.value(), velocityUnits::pct); //(Axis3-Axis4)/2
    /*
    if (Controller1.ButtonX.pressing()) {
      Forklift_L.spin(forward);
    }
    else if (Controller1.ButtonB.pressing()) {
      Forklift_L.spin(reverse);
    }
    else {
      Forklift_L.stop();
    }
    task::sleep(20);*/
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
