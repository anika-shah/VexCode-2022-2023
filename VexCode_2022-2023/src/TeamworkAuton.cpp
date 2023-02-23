#include "vex.h"
#include "robot-config.h"
#include "Moving.h"
#include "Turning.h"
#include "ShootDisc.h"
#include <stdio.h>

using namespace vex;

/*
This function reuses code from the 15-second teamwork auton to go from the second roller to the third roller
*/
void SetDriveVelocity(int targetPerct)
{
  FrontL_DT.setVelocity(targetPerct, percent);
  FrontR_DT.setVelocity(targetPerct, percent);
  BackL_DT.setVelocity(targetPerct, percent);
  BackR_DT.setVelocity(targetPerct, percent);
}

void TeamworkAuton(bool oneMinuteSkillRun) {

  int rollerDegreesToMove = 0;
  if (oneMinuteSkillRun) {
    rollerDegreesToMove = 150;
  } else {
    rollerDegreesToMove = 200;
  }
  
  SetDriveVelocity(15);
  Flywheel_1.setVelocity(2000, rpm);
  Indexer.setVelocity(100, percent);
  Intake.setVelocity(120, percent);
  
  // Robot should now be very close to the roller
  Intake.spinFor(reverse, rollerDegreesToMove, degrees, false);
  MoveStraight(50, forward);

  // Come back to go parallel to the diagonal autonomous line
  MoveStraight(150, reverse);

  TurnToTarget(40);

  SetDriveVelocity(15);

  //MoveStraight(700, reverse);
  MoveStraight(400, reverse);
  TurnToTarget(400);

  SetDriveVelocity(20);

  MoveStraight(500, reverse);
  MoveStraight(550, forward);

  TurnToTarget(77);
  SetDriveVelocity(30);
  MoveStraight(600, reverse);
  
  SetDriveVelocity(20);
  
  MoveStraight(400, forward);
  
  TurnToTarget(221);
  
  SetDriveVelocity(40);

  Intake.spinFor(forward, 5000, degrees, false);
  MoveStraight(2550, forward);

  wait(1, seconds);
  
  MoveStraight(380, forward);
  TurnToTarget(260);

  Intake.setVelocity(100, percent);

  SetDriveVelocity(15);

  Intake.spinFor(forward, 500, degrees, false);
  MoveStraight(100, forward);

  MoveStraight(100, reverse);
  wait(1, seconds);

  DigitalOutD.set(true);

}
