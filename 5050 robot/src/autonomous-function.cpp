#include "autonomous-functions.h"


// Set the time for the motors to perform their task until forced stop
  void SetMotorTimeout(int TimeMilliseconds){
    LeftDrive.setTimeout(TimeMilliseconds, msec);
    RightDrive.setTimeout(TimeMilliseconds, msec);
  }

// Drive Foward with a specified distance in Centimeters
  void moveFoward(float DistancecCM, int SpeedPct, int TimeoutmSec){
    LeftDrive.setTimeout(TimeoutmSec, msec);
    RightDrive.setTimeout(TimeoutmSec, msec);
    
    LeftDrive.setVelocity(SpeedPct, pct);
    RightDrive.setVelocity(SpeedPct, pct);
    
    LeftDrive.rotateFor(forward, ( DistancecCM / g_wheelCircumference ) * g_driveTrainGearRatio , rev, false); 
    RightDrive.rotateFor(forward, ( DistancecCM / g_wheelCircumference ) * g_driveTrainGearRatio , rev, true);

    SetMotorTimeout(0);
  }

// Drive Reverse with a specified distance in Centimeters
  void moveReverse(float DistancecCM, int SpeedPct, int TimeoutmSec){
    LeftDrive.setTimeout(TimeoutmSec, msec);
    RightDrive.setTimeout(TimeoutmSec, msec);

    LeftDrive.setVelocity(SpeedPct, pct);
    RightDrive.setVelocity(SpeedPct, pct);

    LeftDrive.rotateFor(reverse, ( DistancecCM / g_wheelCircumference ) * g_driveTrainGearRatio , rev, false); 
    RightDrive.rotateFor(reverse, ( DistancecCM / g_wheelCircumference ) * g_driveTrainGearRatio , rev, true);

    SetMotorTimeout(0);

  }
//

//Rotate Robot clockwise a specified degree rotation in Degrees
  void rightTurn(float ThetaDegree, int SpeedPct, int TimeoutmSec){
    LeftDrive.setTimeout(TimeoutmSec, msec);
    RightDrive.setTimeout(TimeoutmSec, msec);

    LeftDrive.setVelocity(SpeedPct, pct);
    RightDrive.setVelocity(SpeedPct, pct);

  LeftDrive.rotateFor(forward, ((g_robotRadius * (ThetaDegree * (M_PI/180) ) ) / g_wheelCircumference) * g_driveTrainGearRatio  , rev, false); 
  RightDrive.rotateFor(reverse, ((g_robotRadius * (ThetaDegree * (M_PI/180) ) ) / g_wheelCircumference) * g_driveTrainGearRatio   , rev);

  SetMotorTimeout(0);

  }
//

//Rotate Robot Counter clockwise a specified degree rotation in Degrees
  void leftTurn(float ThetaDegree, int SpeedPct, int TimeoutmSec){
    LeftDrive.setTimeout(TimeoutmSec, msec);
    RightDrive.setTimeout(TimeoutmSec, msec);

    LeftDrive.setVelocity(SpeedPct, pct);
    RightDrive.setVelocity(SpeedPct, pct);

  LeftDrive.rotateFor(reverse, ((g_robotRadius * (ThetaDegree * (M_PI/180) ) ) / g_wheelCircumference) * g_driveTrainGearRatio  , rev, false); 
  RightDrive.rotateFor(forward, ((g_robotRadius * (ThetaDegree * (M_PI/180) ) ) / g_wheelCircumference) * g_driveTrainGearRatio   , rev);

  SetMotorTimeout(0);
  }

//Intake and OutTake using specified degree by gear teeth count
 void intakeAuton(int intakeDegree, int intakeVelocity, int TimeoutmSec){
  Lift.setTimeout(TimeoutmSec, msec);

  Lift.setVelocity(intakeVelocity, pct);

  Lift.rotateFor(intakeDegree, rotationUnits::deg, intakeVelocity, velocityUnits::pct, false);
  SetMotorTimeout(0);
 }

  void LowintakeAuton(int lowTakeDegree, int lowTakeVelocity, int TimeoutmSec){
    LowerLift.setTimeout(TimeoutmSec, msec);

    LowerLift.setVelocity(lowTakeVelocity, pct);

    LowerLift.rotateFor(lowTakeDegree * g_lowerteethGearRatio, rotationUnits::deg, lowTakeVelocity, velocityUnits::pct, true);
    SetMotorTimeout(0);
  }

  void outtakeAuton(int outtakeDegree, int outtakeVelocity, int TimeoutmSec){
  LowerTeethMotorA.setTimeout(TimeoutmSec, msec);
  LowerTeethMotorB.setTimeout(TimeoutmSec, msec);
  // OuttakeMotorA.setVelocity(outtakeVelocity, pct);
  // OuttakeMotorB.setVelocity(outtakeVelocity, pct);
  LowerTeethMotorA.setVelocity(outtakeVelocity, pct);
  LowerTeethMotorB.setVelocity(outtakeVelocity, pct);
  
  LowerTeethMotorA.spinFor(reverse, outtakeDegree ,deg,false);
  LowerTeethMotorB.spinFor(reverse, outtakeDegree ,deg,true);
  // OuttakeMotorA.spinFor(reverse, outtakeDegree ,deg,false); //outtakeDegree*g_outtakeGearRatio
  // OuttakeMotorB.spinFor(reverse, outtakeDegree ,deg,true); //outtakeDegree*g_outtakeGearRatio
  SetMotorTimeout(0);
 }
 
// OLD CLAWFANGAUTON WITH MOTOR
//  void clawFangAuton(int clawFangDegree, float clawFangVelocity, int TimeoutmSec){
//     SetMotorTimeout(TimeoutmSec);
//     clawFangMotor.setVelocity(clawFangVelocity, pct);

//     clawFangMotor.spinTo(clawFangDegree, rotationUnits::deg, clawFangVelocity, velocityUnits::pct, true);
//     SetMotorTimeout(0);
//  } 

 void clawFangAuton(bool grabItem){
    if (grabItem) {
      clawFangPiston.set(0);
    } else {
      clawFangPiston.set(1);
    }
 } 

//Stop all motors
void DriveStop(){
  LeftDrive.stop(hold);
  RightDrive.stop(hold);
}
