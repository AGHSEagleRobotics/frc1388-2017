// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "IncreaseShooterPower.h"
#define INCREASE 0.1
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

IncreaseShooterPower::IncreaseShooterPower(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void IncreaseShooterPower::Initialize() {

	printf("Increase shooter power (button 4) pressed");

	if (!RobotMap::shooterShooterPID->IsEnabled()){
		RobotMap::shooterShooterPID->Enable();
	}
	double nextPower = std::min(1.0, Robot::shooter->shootPower + INCREASE);
	Robot::shooter->shootPower = nextPower;
}

// Called repeatedly when this Command is scheduled to run
void IncreaseShooterPower::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool IncreaseShooterPower::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void IncreaseShooterPower::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IncreaseShooterPower::Interrupted() {

}
