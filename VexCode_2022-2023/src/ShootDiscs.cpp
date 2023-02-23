#include "vex.h"
#include "robot-config.h"

/*
This function shoots a number of discs by moving the puncher to shoot the disc into the flywheel.
This function assumes that flywheel is already running at the required speed.
*/
void ShootDiscs(int numberOfDiscs) {
  //Move the puncher forward to push the disc into the flywheel
  Indexer.setVelocity(100, percent);

  for (int i = 1; i <= numberOfDiscs; i++) {
    Indexer.spinFor(forward, 5, turns);
    //The puncher needs to rest for 1 seconds for the motor to recover to its original speed
    wait(2, seconds);
  }

}