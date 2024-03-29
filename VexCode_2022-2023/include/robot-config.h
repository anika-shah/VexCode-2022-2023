using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FrontR_DT;
extern motor FrontL_DT;
extern motor BackR_DT;
extern motor BackL_DT;
extern inertial Inertial;
extern motor Intake;
extern motor Indexer;
extern motor Flywheel_1;
extern digital_out DigitalOutD;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );