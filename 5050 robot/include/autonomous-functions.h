#include "vex.h"

//HEADER GUARDS
#ifndef AUTONOMOUS_FUNCTIONS
#define AUTONOMOUS_FUNCTIONS

//LIST OF FUNCTIONS TO BE CALLED IN AUTONOMOUS PERIOD

  // Set the time for the motors to perform their task until forced stop
  // void setMotorTimeout(int TimeMilliseconds);

  // Drive Foward with a specified distance in Centimeters
  void moveFoward(float DistancecCM, int SpeedPct, int TimeoutmSec); 

  // Drive Reverse with a specified distance in Centimeters
  void moveReverse(float DistancecCM, int SpeedPct, int TimeoutmSec);

  //Rotate Robot clockwise a specified degree rotation in Degrees
  void leftTurn(float ThetaDegree, int SpeedPct, int TimeoutmSec);

  //Rotate Robot Counter clockwise a specified degree rotation in Degrees
  void rightTurn(float ThetaDegree, int SpeedPct, int TimeoutmSec);

  void intakeAuton(int intakeDegree, int intakeVelocity, int TimeoutmSec);

  void LowintakeAuton(int lowTakeDegree, int lowTakeVelocity, int TimeoutmSec);
  // void clawFangAuton(int clawFangDegree, float clawFangVelocity, int TimeoutmSec);
 // void clawFangAuton(bool grabItem);
  void outtakeAuton(int outtakeDegree, int outtakeVelocity, int TimeoutmSec);


  //Stop all motors
  void DriveStop();
//

//END HEADER GUARDS
#endif
