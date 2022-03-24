#include "routines.h"
#include "autonomous-functions.h"


void RoutineCenterGrab(){ //mark misael
  /*----
  grab side goal
  -----*/
  moveFoward(120, 100, 5500); // 100 speed
  clawFangPiston.set(1);
  wait(500, msec);
  moveReverse(50, 40, 5500);
  leftTurn(30, 40, 5000);
  moveReverse(40, 40, 4000);
  // intakeAuton(550, 70, 5000); //newly added
  wait(500, msec);
  
  /*----
  align for platform goal
  -----*/
  leftTurn(38, 50, 5500);
  moveFoward(20, 70, 3000);
  outtakeAuton(370, 70, 3000);
  wait(500, msec);
  
  /*----
  grab platform goal
  -----*/
  moveReverse(48, 35, 6000);
  wait(500, msec);
  outtakeAuton(-80, 70, 5000);


  moveFoward(25, 35, 5500);
  rightTurn(65, 50, 5000);
  outtakeAuton(-250, 70, 5000);
  moveFoward(20, 35, 5500);
  leftTurn(20, 55, 3000);
 }

void BackupSuggestion() {
  /*----
  grab center goal
  -----*/
  moveFoward(140, 100, 5500); 
  clawFangPiston.set(1);
  outtakeAuton(370, 70, 3000);
  wait(300, msec);
  leftTurn(73, 50, 5500); // turn to the next goal or enemy donuts
  //wait(500, msec);
  

  /*----
  align for other side goal
  -----*/
  moveReverse(30, 70, 5000);
  
  wait(200, msec);
  
  /*----
  Misael suggested not to focus the other neutral goal 
  -----*/
  // rightTurn(20, 50, 50000);
  // moveReverse(48, 35, 6000);
  // outtakeAuton(-240, 70, 5000);
  
  // /*----
  // move center goal to corner and drop
  // -----*/
  // leftTurn(70, 50, 5500);
  // moveFoward(15, 35, 5500);
  // clawFangPiston.set(0);
}
// void BackupSuggestion(){
//   outtakeAuton(370, 70, 5000);
//   moveReverse(123, 100, 5500);
//   outtakeAuton(-360, 75, 5000);
//   moveFoward(120, 70, 5000);
//   leftTurn(75, 100, 5000);
//   moveFoward(20, 65, 5000);
//   wait(500, msec);
//   clawFangPiston.set(1);
//   moveReverse(40, 65, 5000);
  


// }

void TestRoutine(){
  clawFangPiston.set(1);
  intakeAuton(550, 70, 5000);
  
  
  
  
  //leftTurn(21, 75, 5); //90 degrees = 360 degrees, 21 degrees = 45 degrees

}


void JohnLennonDeservedtobeShot(){
  outtakeAuton(360, 100, 5000); //back grabber down
  moveReverse(130, 100, 5500); // move forward to center goal
  outtakeAuton(-300, 100, 5000); // grab center goal
  leftTurn(73, 50, 5500); // turn to the next goal or enemy donuts
  moveFoward(20, 100, 5500);
  clawFangPiston.set(1);
  
  //moveFoward(120, 100, 5000);

}

void RoutineAutoSkills(){
  /*----
  grab platform goal
  -----*/
  moveFoward(45, 60, 3000);
  wait(500, msec);
  clawFangPiston.set(1); 
  moveReverse(30, 80, 5000);

  // adjust to allign and not get stuck
  leftTurn(24, 70, 5000);
  wait(500, msec);
  moveFoward(20, 70, 2000);
  wait(500, msec);
  leftTurn(54, 70, 5000);
  wait(500, msec);
  moveFoward(50, 70, 2000);
  wait(500, msec);
  leftTurn(167, 70, 5000);
  // outtakeAuton(360, 60, 4000);
 

  /*----
  push side goal and put alliance goal on platform
  -----*/
  moveReverse(140, 70, 6000);
  leftTurn(30, 60, 5000);
  moveReverse(30, 70, 4000);
  leftTurn(20, 60, 2000);
  moveReverse(20, 70, 4000);
  rightTurn(50, 60, 5000);
  moveFoward(20, 50, 3000);
  leftTurn(95, 50, 5000);
  moveFoward(100, 70, 5000);
  intakeAuton(500, 70, 5000); // rise goal
  wait(800, msec);
  leftTurn(83, 30, 6000); // Turn left facing the ramp
  wait(800, msec);
  moveFoward(40, 30, 5000);
  clawFangPiston.set(0); //Drop
  wait(1000, msec);
  moveReverse(15, 80, 2000);
  wait(300, msec);
  leftTurn(75, 70, 5000); // Turn left
  wait(300, msec);
  intakeAuton(-500, 70 ,3000); //arm falls neutral


  /*----
  get red alliance goal
  -----*/
  moveFoward(130, 50, 5000); // go red goal
  wait(300, msec);
  clawFangPiston.set(1); //grab red goal
  rightTurn(20, 70, 3000);
  // moveReverse(110, 80, 5000);

  /*----
  push and score high again
  -----*/
  moveReverse(125, 70, 4000);
  rightTurn(30, 60, 5000);
  moveReverse(95, 50, 6000); //until reach the other side of the map while colliding the yellow goal
  leftTurn(45, 80, 4000);
  moveFoward(40, 70, 5000);
  intakeAuton(500, 70, 5000); // rise goal
  // moveFoward(30, 40, 4000);
  leftTurn(90, 70, 5000); // Turn left facing the ramp
  wait(800, msec);
  moveFoward(60, 30, 5000);
  clawFangPiston.set(0); //Drop
}


//void RoutineOuttakeDummy(){
//  moveFoward(100, 100, 10);
//  wait(42069, msec);
//  outtakeAuton(45, 100);
//  outtakeAuton(15, 50);
//  wait(42069,msec);
//  MoveReverse(100, 100, 10);



void RoutineKenta() { // Bot starts backwards in front of circle thing
    /*----
  grab side goal
  -----*/
  moveFoward(120, 100, 5500); // 100 speed
  clawFangPiston.set(1);
  wait(500, msec);
  leftTurn(140, 80, 4000);
  // intakeAuton(550, 70, 5000); //newly added
  wait(500, msec);
  
  /*----
  align for platform goal
  -----*/
  leftTurn(68, 50, 5500);
  moveFoward(20, 70, 3000);
  outtakeAuton(370, 70, 3000);
  wait(500, msec);
  
  /*----
  grab platform goal
  -----*/
  moveReverse(28, 35, 6000);
  wait(500, msec);
  outtakeAuton(-80, 70, 5000);


  moveFoward(25, 35, 5500);
  rightTurn(65, 50, 5000);
  outtakeAuton(-250, 70, 5000);
  moveFoward(20, 35, 5500);
  leftTurn(20, 55, 3000);
}


// void RoutinePlatformGrab() {
//   moveFoward(78, 70, 5);
//   clawFangPiston.set(1); // grab side goal
//   intakeAuton(2, 100, 3);
//   moveFoward(3, 100, 2); 
//   PointTurnCounterClockwise(10, 100, 2);
//   // wait(550, msec);
//   moveReverse(70, 45, 8);
//   clawFangAuton(100, 100, 3); //drop the goal
//   moveReverse(10, 45, 8); // position to goal near platform
//   PointTurnClockwise(105, 100, 5); // facing to the new goal
//   moveFoward(10, 80, 3);
//   clawFangAuton(5, 100, 2); // grab goal
//   intakeAuton(2, 100, 2);
//   moveFoward(3, 100, 2); 
//   intakeAuton(20, 100, 3); // grabbed
//   moveReverse(22, 45, 8); // move goal back
//   clawFangAuton(100, 100, 3); //drop the goal
// }


//void AutonomousSkills(){
  //intakeAuton(350, 100, 5);
  //outtakeAuton(150, 90, 5);
  //moveReverse(100, 100, 5050);
//}


//  void RoutineSkillsTemp(){ // robot move forward, grab yellow goal, backward 
//   /*----
//   grab side goal
//   -----*/
//   moveFoward(110, 100, 5500); // 100 speed
//   clawFangPiston.set(1);
//   wait(5000, msec);
//   moveReverse(100, 40, 5500);
//   // intakeAuton(550, 70, 5000); //newly added
//   wait(500, msec);
  
//   /*----
//   align for platform goal
//   -----*/
//   leftTurn(68, 50, 5500);
//   moveFoward(10, 70, 3000);
//   outtakeAuton(370, 70, 3000);
//   wait(500, msec);
  
//   /*----
//   grab platform goal
//   -----*/
//   moveReverse(28, 35, 6000);
//   wait(500, msec);
//   outtakeAuton(-80, 70, 5000);


//   moveFoward(25, 35, 5500);
//   rightTurn(65, 50, 5000);
//   outtakeAuton(-250, 70, 5000);
//   moveFoward(20, 35, 5500);
//   leftTurn(20, 55, 3000);
//   moveFoward(210, 35, 5500);
//   // clawFangPiston.set(0);
//  }