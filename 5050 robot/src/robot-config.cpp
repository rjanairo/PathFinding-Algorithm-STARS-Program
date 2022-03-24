#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 Brain screen
  brain Brain;
//

// VEXcode device constructors
  controller Controller1 = controller();
//

//drivetrain motors
motor leftMotorA = motor(PORT9, ratio18_1, false);
motor leftMotorB = motor(PORT10, ratio18_1, false);
motor leftMotorC = motor(PORT1, ratio18_1, false);

motor rightMotorA = motor(PORT4, ratio18_1, true);
motor rightMotorB = motor(PORT3, ratio18_1, true);
motor rightMotorC = motor(PORT2, ratio18_1, true);
//

//Motor Groups
  motor_group LeftDrive = motor_group(leftMotorA, leftMotorB, leftMotorC);
  motor_group RightDrive = motor_group(rightMotorA, rightMotorB,rightMotorC);
  motor_group FullDrive = motor_group(leftMotorA, leftMotorB, leftMotorC, rightMotorA, rightMotorB,rightMotorC);
  motor_group Lift = motor_group(IntakeMotorA, IntakeMotorB, IntakeMotorC, IntakeMotorD);
  motor_group LowerLift = motor_group(LowerTeethMotorA, LowerTeethMotorB);
  motor_group BackLift = motor_group(OuttakeMotorA,OuttakeMotorB);
//

//Drivetrain 
  drivetrain Drivetrain = drivetrain(LeftDrive, RightDrive,319.19, 320, 130, mm, 1);
//

//Left IntakeMotor
 motor IntakeMotorA = motor(PORT18, ratio36_1, false); //used to be port 11 2/11/2022
 motor IntakeMotorB = motor(PORT12, ratio36_1, false);

//Right IntakeMotor
 motor IntakeMotorC = motor(PORT16, ratio36_1, true);
 motor IntakeMotorD = motor(PORT17, ratio36_1, true);



//OuttakeMotor
 motor OuttakeMotorA = motor(PORT14, ratio36_1, true);
 motor OuttakeMotorB = motor(PORT13, ratio36_1, false);

//LowerTeethIntake
 motor LowerTeethMotorA = motor(PORT8, ratio36_1, true);
 motor LowerTeethMotorB = motor(PORT19, ratio36_1, false);


//Claw Fang Pneumatics
digital_out clawFangPiston = digital_out(Brain.ThreeWirePort.B);

// Global Variables(begein with g_ prefix)
  const float g_wheelBase = 33; // [cm] Distance between axles of two wheels on the left or right side of base
  const float g_trackWidth = 28.2; // [cm] Distance between wheel centers of two adjacent wheels
  const float g_robotRadius = sqrtf( powf( (g_trackWidth/2), 2) + powf( (g_wheelBase/2), 2) ); // [cm] 
  const float g_wheelDiameter = 10.16; // [cm]
  const float g_wheelCircumference = g_wheelDiameter * M_PI; // [cm]
  const float g_driveTrainGearRatio = 1;  // originally 1/1 [Driven Gear Teeth Count/ Driving Gear Teeth Count][unit-less]

  const float g_intakeGearRatio = 1/2; //intake arm gear teeth
  const float g_outtakeGearRatio = 3/5; //outtake arm gear teeth 
  const float g_lowerteethGearRatio = 3/5;
//Bumper Switch
limit frontBumpSwitch = limit(Brain.ThreeWirePort.A);

// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // reset the screen now that the calibration is complete
  Brain.Screen.clearScreen();
  wait(50, msec);
  Brain.Screen.drawRectangle(0, 0, 200, 200);
  Brain.Screen.setFillColor(green);
}
