#include "vex.h"

//HEADER GUARDS
#ifndef AUTONOMOUS_FUNCTIONS
#define AUTONOMOUS_FUNCTIONS

//LIST OF FUNCTIONS TO BE CALLED IN AUTONOMOUS PERIOD

  // Set the time for the motors to perform their task until forced stop
  void SetMotorTimeout(int TimeSeconds);

  // Drive Foward with a specified distance in Centimeters
  void Movefoward(float DistancecCM, int SpeedPct, int TimeoutSec); 

  // Drive Reverse with a specified distance in Centimeters
  void MoveReverse(float DistancecCM, int SpeedPct, int TimeoutSec);

  //Rotate Robot clockwise a specified degree rotation in Degrees
  void PointTurnClockwise(float ThetaDegree, int SpeedPct, int TimeoutSec);

  //Rotate Robot Counter clockwise a specified degree rotation in Degrees
  void PointTurnCounterClockwise(float ThetaDegree, int SpeedPct, int TimeoutSec);

  void intakeAuton(int intakeDegree, int intakeVelocity);

  void clawFangAuton(int clawFangDegree, float clawFangVelocity);

  //Stop all motors
  void DriveStop();
//

//END HEADER GUARDS
#endif
