#include "vex.h"
#include "driver-control.h"
#include "robot-config.h"

using namespace vex;

//defining functions from header files
void DriveArcade(){

  if(abs(Controller1.Axis3.value()) > 5 || abs(Controller1.Axis1.value()) > 5){
    LeftDrive.spin(forward, ( Controller1.Axis3.value() + Controller1.Axis1.value() )/2 , pct);
    RightDrive.spin(forward, ( Controller1.Axis3.value() - Controller1.Axis1.value() )/2 , pct);
  } 
  else{
    LeftDrive.stop();
    RightDrive.stop();
  }
}

void DriveTank(){
   if( abs( Controller1.Axis2.value() ) > 5 && abs( Controller1.Axis3.value() ) > 5 ){
     LeftDrive.spin(forward,Controller1.Axis3.value(), pct);
     RightDrive.spin(forward, Controller1.Axis2.value(),pct);
   } 
   else{
     LeftDrive.stop();
     RightDrive.stop();
   }

 }

void IntakeControl(){
  if(Controller1.ButtonL1.pressing()){
    IntakeMotorA.spin(forward, 70, pct);
    IntakeMotorB.spin(forward, 70, pct);
  }else if(Controller1.ButtonL2.pressing()){
    IntakeMotorA.spin(reverse, 70, pct);
    IntakeMotorB.spin(reverse, 70, pct);
  }
  else{
    IntakeMotorA.stop(hold);
    IntakeMotorB.stop(hold);
  }
} 

void clawFangControl(){
  if(Controller1.ButtonR1.pressing()){
    clawFangMotor.spin(forward);
  }
  else if(Controller1.ButtonR2.pressing())
    {
    clawFangMotor.spin(reverse);
  }
  else {
    clawFangMotor.stop(hold);    
  }
}

void DriveXDrive(){

  if(abs(Controller1.Axis1.value()) > 5 || abs(Controller1.Axis3.value()) > 5 || abs(Controller1.Axis4.value()) > 5){
    LeftDrive.spin(forward, (Controller1.Axis4.value() + Controller1.Axis1.value() + Controller1.Axis3.value())/3 , pct);
    LeftDrive.spin(forward, (Controller1.Axis4.value() + Controller1.Axis1.value() - Controller1.Axis3.value())/3 , pct);
    RightDrive.spin(forward, (Controller1.Axis4.value() - Controller1.Axis1.value() - Controller1.Axis3.value())/3 , pct);
    RightDrive.spin(forward, (Controller1.Axis4.value() - Controller1.Axis1.value() + Controller1.Axis3.value())/3 , pct);
  } else {
    LeftDrive.stop();
    LeftDrive.stop();

    RightDrive.stop();
    RightDrive.stop();
  }
}
