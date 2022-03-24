using namespace vex;

extern brain Brain;

// Controller  Declarations
extern controller Controller1;

// VEXcode devices
extern drivetrain Drivetrain;
extern motor ClawMotor;
extern motor ArmMotor;

//drivetrain motors
extern motor leftMotorA;
extern motor leftMotorB;
extern motor leftMotorC;

extern motor rightMotorA;
extern motor rightMotorB;
extern motor rightMotorC;

extern motor liftA;
extern motor liftB;

//Long arm boi
extern motor IntakeMotorA; //Front Left arm
extern motor IntakeMotorB; //Front Left arm
extern motor IntakeMotorC; //Front Right arm
extern motor IntakeMotorD; //Front Right arm

//Back Grabber
extern motor OuttakeMotorA; //Back Left arm
extern motor OuttakeMotorB; //Back Right arm

//Lower teeth boi
extern motor LowerTeethMotorA; //Lower Left arm
extern motor LowerTeethMotorB; //Lower Right arm

//Motor Groups
extern motor_group LeftDrive;
extern motor_group RightDrive;
extern motor_group FullDrive;
extern motor_group Lift;
extern motor_group LowerLift;
extern motor_group BackLift;


//Pneumatics
extern digital_out clawFangPiston;
//Pneumatic 

//Bumper Switch
extern limit frontBumpSwitch;

//sensor declarations
extern gyro myGyro;

// Global Variables(begein with g_ prefix)

extern const float g_wheelBase; // [cm] Distance between axles of two wheels on the left or right side of base
extern const float g_trackWidth; // [cm] Distance between wheel centers of two adjacent wheels

extern const float g_robotRadius; // [cm] 
extern const float g_wheelDiameter; // [cm]
extern const float g_wheelCircumference; // [cm]
extern const float g_driveTrainGearRatio; // [Driven Gear Teeth Count/ Driving Gear Teeth Count]

extern const float g_intakeGearRatio; //intake arm lift Gear Teeth Count/ Driving Gear Teeth Count
extern const float g_outtakeGearRatio; //outtake Gear Teeth Count/ Driving Gear Teeth Count
extern const float g_lowerteethGearRatio; // lower teeth 

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
