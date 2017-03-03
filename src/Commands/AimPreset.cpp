// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AimPreset.h"
#define PRESET 0.5
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AimPreset::AimPreset(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AimPreset::Initialize() {
	RobotMap::aimerAimerPID->SetSetpoint(PRESET);
	//RobotMap::aimerAimerPID->Enable();
}

// Called repeatedly when this Command is scheduled to run
void AimPreset::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AimPreset::IsFinished() {
    return RobotMap::aimerAimerPID->OnTarget();
}

// Called once after isFinished returns true
void AimPreset::End() {
	RobotMap::aimerAimerPID->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimPreset::Interrupted() {
	End();
}
