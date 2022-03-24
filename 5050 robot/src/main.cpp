#include "vex.h"
#include "driver-control.h"
#include "routines.h"

using namespace vex;

void Usercontrol(){
  while(1){
    DriveArcade();
    // DriveTank();
    IntakeControl();
    LowerTeethControl();
    PneumaticsIntakeConrol();
    // OuttakeControl();
    
    //wait to save resources
    wait(10,msec);
  }
}

void Autonomous(){
  //RoutineCenterGrab(); //main auton
  // JohnLennonDeservedtobeShot();
  BackupSuggestion(); //auton for center goal (USC)
  //TestRoutine();
  // RoutineKenta();
  // RoutineAutoSkills();
}

competition Competition;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
 
  Competition.drivercontrol(Usercontrol);
  Competition.autonomous(Autonomous);
}
