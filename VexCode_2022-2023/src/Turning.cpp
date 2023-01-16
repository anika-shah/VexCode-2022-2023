#include "vex.h"

/*
This function turns the robot by the provided amount of degrees in the provided direction
*/
void TurnUsingGyro(int numOfDegrees, vex::turnType dir) {

  FrontL_DT.setVelocity(15, percent);
  FrontR_DT.setVelocity(15, percent);
  BackL_DT.setVelocity(15, percent);
  BackR_DT.setVelocity(15, percent);

  if (dir == right) {
    FrontL_DT.spinFor(forward, 2000, degrees, false);
    FrontR_DT.spinFor(reverse, 2000, degrees, false);
    BackL_DT.spinFor(forward, 2000, degrees, false);
    BackR_DT.spinFor(reverse, 2000, degrees, false);

    float target = Inertial.heading(degrees) + numOfDegrees;
    if(target >= 360)
    {
      target = target-360;
    }

    while (true)
    {
      //wait(0.01, seconds);
      if (Inertial.heading(degrees) > target-1 && Inertial.heading(degrees) < target+1)
      {
          break;
      }
    }
  }
  else if (dir == left) {
    FrontL_DT.spinFor(reverse, 2000, degrees, false);
    FrontR_DT.spinFor(forward, 2000, degrees, false);
    BackL_DT.spinFor(reverse, 2000, degrees, false);
    BackR_DT.spinFor(forward, 2000, degrees, false);

    wait(0.1, seconds);

    //Setting the target
    float target = Inertial.heading(degrees) - numOfDegrees;
    if (target < 0)
    {
      target = target + 360;
    }

    while (true)
    {
      //wait(0.01, seconds);
      if (Inertial.heading(degrees) > target-1 && Inertial.heading(degrees) < target+1)
      {
          break;
      }
    }
  }

  FrontL_DT.stop();
  FrontR_DT.stop();
  BackL_DT.stop();
  BackR_DT.stop();

  FrontL_DT.setVelocity(85, percent);
  FrontR_DT.setVelocity(85, percent);
  BackL_DT.setVelocity(85, percent);
  BackR_DT.setVelocity(85, percent);
}

void TurnToTarget(float target) {
  float current = Inertial.heading(degrees);
  float x = target-current;
  Brain.Screen.print(Inertial.heading(degrees));

  if (x > 0) {
    if (x <= 180) {
      TurnUsingGyro(x, right);
    }
    else if (x > 180) {
      TurnUsingGyro(360 - x, left);
    }
  }
  else if (x < 0) {
    if (x < -180) {
      TurnUsingGyro(360 + x, right);
    }
    else if (x > -180) {
      TurnUsingGyro(-x, left);
    }
  }
  Brain.Screen.print(Inertial.heading(degrees));
}