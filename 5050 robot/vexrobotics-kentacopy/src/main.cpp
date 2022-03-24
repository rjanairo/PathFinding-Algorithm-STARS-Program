#include "vex.h"
#include "driver-control.h"
#include "routines.h"

using namespace vex;

void Usercontrol(){
  while(1){
    DriveArcade();
    IntakeControl();
    clawFangControl();

    //wait to save resources
    wait(10,msec);
  }
}

void Autonomous(){
  RoutineOne();
}

competition Competition;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
 
  Competition.drivercontrol(Usercontrol);
  Competition.autonomous(Autonomous);

}
