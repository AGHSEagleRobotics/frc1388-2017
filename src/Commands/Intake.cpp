// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Intake.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Intake::Intake(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::ballIntake.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Intake::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Intake::Execute() {

	float motorSpeed = 1.0;

	if (Robot::oi->getOpStick()->GetRawButton(6)){
		motorSpeed = motorSpeed * -1;
	}
	RobotMap::ballIntakeIntakeMotor->Set(motorSpeed);


}

// Make this return true when this Command no longer needs to run execute()
bool Intake::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void Intake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Intake::Interrupted() {

}
