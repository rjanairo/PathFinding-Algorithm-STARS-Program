#include "vex.h"

//Header Guards
#ifndef DRIVER_CONTROL_HEADER
#define DRIVER_CONTROL_HEADER

// Drive control for tank drive
// void DriveTank();

// Drive function for arcade drive
void DriveArcade();

// Drive Function for xDrive
// void DriveXDrive();

//Driver control function for moving motor [insert name]
void ClawControl();

void ArmControl();

void IntakeControl();

void LowerTeethControl(); 

void PneumaticsIntakeConrol(); //Button A

void OuttakeControl();

brakeType ToggleHold();

double ToggleSpeed();

#endif
