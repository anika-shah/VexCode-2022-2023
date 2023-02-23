#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontR_DT = motor(PORT18, ratio18_1, false);
motor FrontL_DT = motor(PORT2, ratio18_1, true);
motor BackR_DT = motor(PORT21, ratio18_1, false);
motor BackL_DT = motor(PORT12, ratio18_1, true);
inertial Inertial = inertial(PORT17);
motor Intake = motor(PORT3, ratio18_1, false);
motor Indexer = motor(PORT13, ratio18_1, false);
motor Flywheel_1 = motor(PORT5, ratio18_1, true);
digital_out DigitalOutD = digital_out(Brain.ThreeWirePort.D);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}