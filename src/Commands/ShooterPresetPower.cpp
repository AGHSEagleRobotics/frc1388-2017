// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "ShooterPresetPower.h"
#define PRESET 0.5
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

ShooterPresetPower::ShooterPresetPower(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void ShooterPresetPower::Initialize() {
	if (!RobotMap::shooterShooterPID->IsEnabled()){
			RobotMap::shooterShooterPID->Enable();
	}
	Robot::shooter->shootPower = PRESET;
	RobotMap::shooterShooterPID->SetSetpoint(3200 * Robot::shooter->shootPower);
}

// Called repeatedly when this Command is scheduled to run
void ShooterPresetPower::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterPresetPower::IsFinished() {
    return true;
}

// Called once after isFinished returns true
void ShooterPresetPower::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterPresetPower::Interrupted() {

}
