// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "DecreaseShooterPower.h"

#define DECREASE 0.1
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DecreaseShooterPower::DecreaseShooterPower(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void DecreaseShooterPower::Initialize() {

	printf("Decrease shooter power (button 2) pressed");

	double nextPower = std::max(0.0, Robot::shooter->shootPower - DECREASE);
	Robot::shooter->shootPower = nextPower;

}

// Called repeatedly when this Command is scheduled to run
void DecreaseShooterPower::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DecreaseShooterPower::IsFinished() {
    return true;
}
// Called once after isFinished returns true
void DecreaseShooterPower::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DecreaseShooterPower::Interrupted() {

}
