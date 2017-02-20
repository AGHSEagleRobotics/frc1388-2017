// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RunShooter.h"
#define TO_RPM_CONVERSION 4500
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

RunShooter::RunShooter(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void RunShooter::Initialize() {
	//Nothing, probably
	printf("Initializing Run Shooter");
	RobotMap::shooterShooterPID->SetSetpoint(Robot::shooter->shootPower * TO_RPM_CONVERSION);
	RobotMap::shooterShooterPID->Reset();
	RobotMap::shooterShooterPID->Enable();
	//RobotMap::shooterShooterMotor->Set(0.0);
}

// Called repeatedly when this Command is scheduled to run
void RunShooter::Execute() {
	//RobotMap::shooterShooterMotor->Set(Robot::shooter->shootPower);
}

// Make this return true when this Command no longer needs to run execute()
bool RunShooter::IsFinished() {
    return true;
    //return false
}

// Called once after isFinished returns true
void RunShooter::End() {
	//RobotMap::shooterShooterPID->Disable();

	//RobotMap::shooterShooterMotor->Set(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunShooter::Interrupted() {
	End();
}
