#include "vex.h"

void MoveStraight(int numberOfDegrees, vex::directionType dir) {

  FrontL_DT.spinFor(dir, numberOfDegrees, degrees, false);
  FrontR_DT.spinFor(dir, numberOfDegrees, degrees, false);
  BackL_DT.spinFor(dir, numberOfDegrees, degrees, false);
  BackR_DT.spinFor(dir, numberOfDegrees, degrees);
 
}