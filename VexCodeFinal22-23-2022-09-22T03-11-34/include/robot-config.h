using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FrontR_DT;
extern motor FrontL_DT;
extern motor BackR_DT;
extern motor BackL_DT;
extern controller Controller1;
extern inertial Inertial;
extern distance Distance;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );