// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Drive.h"
#define DEADBAND 0.05// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Drive::Drive(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

double Drive::Deadband(double input){

	if (fabs(input) <= DEADBAND) return 0;
	else if (input > 0) return (input - DEADBAND) / (1 - DEADBAND);
	else if (input < 0) return (input + DEADBAND) / (1 - DEADBAND);

}

// Called just before this Command runs the first time
void Drive::Initialize() {
	RobotMap::driveTrainRobotDrive->TankDrive(0.0,0.0,false);
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	double leftStickY = Deadband(Robot::oi->getLeftStick()->GetY());
	double rightStickY = Deadband(Robot::oi->getRightStick()->GetY());
	RobotMap::driveTrainRobotDrive->TankDrive(leftStickY, rightStickY, false);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void Drive::End() {
	RobotMap::driveTrainRobotDrive->TankDrive(0.0,0.0,false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {
	End();
}
