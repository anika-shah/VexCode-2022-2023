/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\shaha                                            */
/*    Created:      Fri Sep 02 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontR_DT            motor         18              
// FrontL_DT            motor         2               
// BackR_DT             motor         7               
// BackL_DT             motor         12              
// IntakeRoller         motor         3               
// Inertial             inertial      17              
// Controller1          controller                    
// Indexer              motor         13              
// Flywheel_1           motor         5               
// DigitalOutD          digital_out   D               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  IntakeRoller.spinFor(forward, 3000, degrees);
}
