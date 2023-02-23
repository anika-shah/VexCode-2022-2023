#include "vex.h"
#include "robot-config.h"

/*
Releases air in pneumatic air tank to trigger expansion
*/
void Expand() {
  //Stop the flywheel to start expansion (otherwise string may get stuck in the flywheel)
  Flywheel_1.stop();
  DigitalOutD.set(true);
}