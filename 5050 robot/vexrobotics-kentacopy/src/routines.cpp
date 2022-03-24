#include "routines.h"
#include "autonomous-functions.h"

void RoutineOne(){ // robot move forward, grab yellow goal, backward 
  intakeAuton(45, 100);
  wait(550, msec);
  Movefoward(100, 80, 1); //Need to change the value of value if robot is crash the goal 
  wait(2000, msec);
  clawFangAuton(90, 100);
  wait(550,msec);
  clawFangAuton(0, 85);
  wait(400,  msec);
  MoveReverse(100, 100, 1);
  wait(1500, msec);
  clawFangAuton(100, 100); //Drop the yellow goal
  PointTurnCounterClockwise(45, 80, 2); // change value for rotation towards the mid  yellow goal
  Movefoward(100, 100, 1);
  wait(2000, msec);
  clawFangAuton(0, 100);
  wait(550, msec);
  MoveReverse(100, 100, 1);
  clawFangAuton(100, 100); //Drop the Yellow Goal 
}

/*
void RoutineKenta() { // Bot starts backwards in front of circle thing
  MoveReverse(160, 100, 5); // move "forward" (quickly to get time to go on the scale properly)
}
*/
