#include "vex.h"
#include "driver-control.h"
#include "robot-config.h"

using namespace vex;

//defining functions from header files

// void DriveTank(){
//   if( abs( Controller1.Axis2.value() ) > 5 && abs( Controller1.Axis3.value() ) > 5 ){
//     LeftDrive.spin(forward,Controller1.Axis3.value(), pct);
//     RightDrive.spin(forward, Controller1.Axis2.value(),pct);
// } 
// else{
//   LeftDrive.stop(coast);
//   RightDrive.stop(coast);
//   FullDrive.stop(ToggleHold());
//   }
// }

//Button PAUSE mode
bool doWheelHold = false;
bool buttonToggleHold = false; 

brakeType ToggleHold() { 
  if (Controller1.ButtonDown.pressing()) { 
    if(!buttonToggleHold){
      
      buttonToggleHold = true;
      doWheelHold = !doWheelHold;
    } 
  } else {
      buttonToggleHold = false;
    }
  
  if(!doWheelHold){
    //Controller1.rumble(".");
    return hold;
  } else {
    //Controller1.rumble("-");
    return coast;
  }
  wait(20, msec);
  
}

bool doSpeedToggle = false;
bool buttonToggleSpeed = false;
double ToggleSpeed() {
  if (Controller1.ButtonUp.pressing()) {
    if (!buttonToggleSpeed) {
      buttonToggleSpeed = true;
      doSpeedToggle = !doSpeedToggle;
    }
  } else {
    buttonToggleSpeed = false;
  }

  if (doSpeedToggle) {
    return 0.5;
  } else {
    return 1;
  }
}

void IntakeControl(){
  if(Controller1.ButtonR1.pressing()){
    Lift.spin(forward, 40, pct);
  }else if(Controller1.ButtonR2.pressing()){
    Lift.spin(reverse, 40, pct);
  }
  else{
    Lift.stop(hold);
  }
} 
void LowerTeethControl(){
  if(Controller1.ButtonL1.pressing()){
    LowerTeethMotorA.spin(forward, 70, pct);
    LowerTeethMotorB.spin(forward, 70, pct);
  } 
  else if(Controller1.ButtonL2.pressing()){

    LowerTeethMotorA.spin(reverse, 70, pct);
    LowerTeethMotorB.spin(reverse, 70, pct);
  
  }
  else{
    LowerTeethMotorA.stop(hold);
    LowerTeethMotorB.stop(hold);
  }

  wait(20, msec);
}

void PneumaticsIntakeConrol(){ //Pneumatics Claw Butoton A
if(Controller1.ButtonA.pressing()){
  clawFangPiston.set(0);
}
else if (Controller1.ButtonY.pressing()) {
  clawFangPiston.set(1);
} else {

}

/*
  if (Controller1.ButtonA.pressing()) { //isOpen &&
    if(!buttonToggleClaw){
    clawFangPiston.set(0);
    buttonToggleClaw = true;
    clawIsOpen = !clawIsOpen;
    } else {
      clawFangPiston.set(1);
    }
  }
  else{
    
    buttonToggleClaw = false;
  }
*/    
}

// void OuttakeControl(){
//   if(Controller1.ButtonX.pressing()){
//     OuttakeMotorA.spin(forward, 30, pct);
//     OuttakeMotorB.spin(forward, 30, pct);
//   }
//   else if (Controller1.ButtonB.pressing()) {
//     OuttakeMotorA.spin(reverse, 30, pct);
//     OuttakeMotorB.spin(reverse, 30, pct);
//   }
//   else{
//     OuttakeMotorA.stop(hold);
//     OuttakeMotorB.stop(hold);
//   }
// }

void DriveArcade(){
  double speedValue = ToggleSpeed();

  if(abs(Controller1.Axis3.value()) > 5 || abs(Controller1.Axis1.value()) > 5){
    LeftDrive.spin(forward, ( Controller1.Axis3.value() + Controller1.Axis1.value() ) * speedValue, pct);
    RightDrive.spin(forward, ( Controller1.Axis3.value() - Controller1.Axis1.value() ) * speedValue, pct);
  } 
  else {
    if (doWheelHold) {
      LeftDrive.stop(hold); //please fix me
      RightDrive.stop(hold); //please fix me
    } else {
      LeftDrive.stop(); //please fix me
      RightDrive.stop(); //please fix me
    }
      brakeType stopType = ToggleHold();
      LeftDrive.stop(stopType); //please fix me
      RightDrive.stop(stopType); //please fix me
      FullDrive.stop(ToggleHold());
  }
    
  }

//Claw Fang Pneumatics

/*
void DriveXDrive(){

  if(abs(Controller1.Axis1.value()) > 5 || abs(Controller1.Axis3.value()) > 5 || abs(Controller1.Axis4.value()) > 5){
    // LeftDrive.spin(forward, (Controller1.Axis4.value() + Controller1.Axis1.value() + Controller1.Axis3.value())/3 , pct);
    // LeftDrive.spin(forward, (Controller1.Axis4.value() + Controller1.Axis1.value() - Controller1.Axis3.value())/3 , pct);
        leftMotorC.spin(forward, (Controller1.Axis4.value() + Controller1.Axis1.value() + Controller1.Axis3.value())/3 , pct);
    RightDrive.spin(forward, (Controller1.Axis4.value() - Controller1.Axis1.value() - Controller1.Axis3.value())/3 , pct);
    RightDrive.spin(forward, (Controller1.Axis4.value() - Controller1.Axis1.value() + Controller1.Axis3.value())/3 , pct);
  } else {
    LeftDrive.stop();
    LeftDrive.stop();

    RightDrive.stop();
    RightDrive.stop();
  }
}
*/

