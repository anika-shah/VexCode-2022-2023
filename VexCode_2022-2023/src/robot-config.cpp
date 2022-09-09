#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontR_DT = motor(PORT1, ratio18_1, false);
motor FrontL_DT = motor(PORT2, ratio18_1, false);
motor BackR_DT = motor(PORT3, ratio18_1, false);
motor BackL_DT = motor(PORT4, ratio18_1, false);
inertial Inertial = inertial(PORT5);
distance LiDAR = distance(PORT6);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}