// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#define SCALED_SAFETY 0.8
#define DEADBAND 0.1
#include "RunWinch.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

RunWinch::RunWinch(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::winch.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void RunWinch::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void RunWinch::Execute() {

	double input = Robot::oi->getOpStick()->GetY();
	double output;
	if (fabs(input) <= DEADBAND) {
		RobotMap::winchWinchMotor->Set(0);
	}else if (input > 0) {
		output = SCALED_SAFETY * (input - DEADBAND) / (1 - DEADBAND);
	}else if (input < 0) {
		output = 0;
		//as to ensure that only forward values are provided to the winch.
	}

	RobotMap::winchWinchMotor->Set(-output);

}

// Make this return true when this Command no longer needs to run execute()
bool RunWinch::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void RunWinch::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunWinch::Interrupted() {

}
