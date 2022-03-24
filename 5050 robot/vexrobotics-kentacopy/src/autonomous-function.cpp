#include "autonomous-functions.h"


// Set the time for the motors to perform their task until forced stop
  void SetMotorTimeout(int TimeSeconds){
    LeftDrive.setTimeout(TimeSeconds, sec);
    RightDrive.setTimeout(TimeSeconds, sec);
  }

// Drive Foward with a specified distance in Centimeters
  void Movefoward(float DistancecCM, int SpeedPct, int TimeoutSec){
    SetMotorTimeout(TimeoutSec);

    LeftDrive.rotateFor(forward, ( DistancecCM / g_wheelCircumference ) * g_driveTrainGearRatio , rev, false); 
    RightDrive.rotateFor(forward, ( DistancecCM / g_wheelCircumference ) * g_driveTrainGearRatio , rev);

    SetMotorTimeout(0);
  }

// Drive Reverse with a specified distance in Centimeters
  void MoveReverse(float DistancecCM, int SpeedPct, int TimeoutSec){
    SetMotorTimeout(TimeoutSec);

    LeftDrive.rotateFor(reverse, ( DistancecCM / g_wheelCircumference ) * g_driveTrainGearRatio , rev, false); 
    RightDrive.rotateFor(reverse, ( DistancecCM / g_wheelCircumference ) * g_driveTrainGearRatio , rev);

    SetMotorTimeout(0);

  }
//

//Rotate Robot clockwise a specified degree rotation in Degrees
  void PointTurnClockwise(float ThetaDegree, int SpeedPct, int TimeoutSec){
  SetMotorTimeout(TimeoutSec);

  LeftDrive.rotateFor(forward, ((g_robotRadius * (ThetaDegree * (M_PI/180) ) ) / g_wheelCircumference) * g_driveTrainGearRatio  , rev, false); 
  RightDrive.rotateFor(reverse, ((g_robotRadius * (ThetaDegree * (M_PI/180) ) ) / g_wheelCircumference) * g_driveTrainGearRatio   , rev);

  SetMotorTimeout(0);

  }
//

//Rotate Robot Counter clockwise a specified degree rotation in Degrees
  void PointTurnCounterClockwise(float ThetaDegree, int SpeedPct, int TimeoutSec){
  SetMotorTimeout(TimeoutSec);

  LeftDrive.rotateFor(reverse, ((g_robotRadius * (ThetaDegree * (M_PI/180) ) ) / g_wheelCircumference) * g_driveTrainGearRatio  , rev, false); 
  RightDrive.rotateFor(forward, ((g_robotRadius * (ThetaDegree * (M_PI/180) ) ) / g_wheelCircumference) * g_driveTrainGearRatio   , rev);

  SetMotorTimeout(0);
  }
//
 void intakeAuton(int intakeDegree, int intakeVelocity){
  IntakeMotorA.spinTo(intakeDegree, rotationUnits::deg , intakeVelocity, velocityUnits::pct, true);
  IntakeMotorB.spinTo(intakeDegree, rotationUnits::deg , intakeVelocity, velocityUnits::pct, true);
 }

 void clawFangAuton(int clawFangDegree, float clawFangVelocity){
    clawFangMotor.spinTo(clawFangDegree, rotationUnits::deg, clawFangVelocity, velocityUnits::pct, true);
 } 


//Stop all motors
void DriveStop(){
  LeftDrive.stop(hold);
  RightDrive.stop(hold);
}
